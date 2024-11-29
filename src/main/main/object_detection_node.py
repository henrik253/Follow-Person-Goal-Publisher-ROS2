import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
import numpy as np
import logging
from object_tracking_messages.msg import DetectedPersons, DetectedPerson, BoundingBox, PersonKeyPoint

import torch
from torchreid.reid.utils import FeatureExtractor
from torch.nn.functional import cosine_similarity
from collections import deque 

import statistics

logging.getLogger('ultralytics').setLevel(logging.WARNING)

# pip install torchreid!
min_similarity = 0.65
max_images_per_person = 100


min_confidence_score = 0.7
class ObjectTracker(Node): 
    def __init__(self): 
        super().__init__('yolo_tracking')

        self.create_subscription(
            Image,
            '/zed/zed_node/left/image_rect_color',
            self.image_callback,
            1  # Low queue-size for low latency
        )

        self.detected_persons_publisher = self.create_publisher(
            DetectedPersons,
            'detected_persons',
            1
        )

        self.image_publisher = self.create_publisher(
            Image,
            'tracked_image',
            1
        )
        
        # Create CvBridge to convert ROS Image messages to OpenCV images
        self.bridge = CvBridge()
        self.model = YOLO('yolov8n-pose.pt')

        # REID 

        self.extractor = FeatureExtractor(
            model_name='osnet_x1_0',
            device='cuda' if torch.cuda.is_available() else 'cpu'
        )
        # ID manager
        self.tracked_persons = {}  # Custom ID -> feature vector
        self.disappeared_persons = {}  # Custom ID -> feature vector
        self.yolo_to_custom_id = {}  # YOLO ID -> Custom ID
        self.person_id_counter = 0  # Counter for new IDs


        self.body_part_names = ["nose", "left_eye", "right_eye", "left_ear", "right_ear",
                                "left_shoulder", "right_shoulder", "left_elbow", "right_elbow",
                                "left_wrist", "right_wrist", "left_hip", "right_hip",
                                "left_knee", "right_knee", "left_ankle", "right_ankle"]
    
        self.store_image_counter = 0

    def store_image(self,image,type):
        self.store_image_counter += 1
        cv2.imwrite(f'images/temp{self.store_image_counter}_{type}.jpg', self.preprocess_image(image))
       
    # RE-ID
    def preprocess_image(self,image):
        resized_image = cv2.resize(image, (256, 512))
        rgb_image = cv2.cvtColor(resized_image, cv2.COLOR_BGR2RGB)
       # cv2.imwrite('temp.jpg', rgb_image)
       # return 'temp.jpg'
        return rgb_image  

    def extract_features(self,image):
        features = self.extractor(self.preprocess_image(image))[0]
        return features


    def update_tracked_persons(self, custom_id, feature):
        if custom_id not in self.tracked_persons:
            self.tracked_persons[custom_id] = deque(maxlen=max_images_per_person) # create new candidate
        self.tracked_persons[custom_id].append(feature)
            
    # it can happen that there are multiple canditates that are the same person 
    # when does this happen: 
    # 1. a person reenters the frame and the calculated sim is lower than min_similarity 
    # 2. or multiple boundingboxes of a same person occure 
    # the problem is that now multiple candidates to match exist, and so the reid will give in the whole progress multiple id's
    # to the same person 
    # for avoiding this the candidates will be deleted when they are simillar to each other and the one with lowest 
    # id will always stay!
    # 
    def update_untracked_persons(self):
        similarity_threshold = 0.20  # Threshold for considering two disappeared persons as the same
        ids_to_remove = set()  # Keep track of IDs to remove

        disappeared_ids = list(self.disappeared_persons.keys())  # Get list of disappeared IDs

        # Compare every pair of disappeared persons
        for i, id1 in enumerate(disappeared_ids):
            if id1 in ids_to_remove:
                continue 

            features1 = self.disappeared_persons[id1]

            for id2 in disappeared_ids[i + 1:]:
                if id2 in ids_to_remove:
                    continue  

                features2 = self.disappeared_persons[id2]

                # Calculate median similarity of two candidates
                similarities = []
                for feature1 in features1:
                    for feature2 in features2:
                        sim = cosine_similarity(
                            feature1.unsqueeze(0), feature2.unsqueeze(0)
                        ).item()
                        similarities.append(sim)

                if similarities:
                    median_similarity = statistics.median(similarities)
                    print(f"Similarity between ID {id1} and ID {id2}: {median_similarity}")

                    # If similarity is above the threshold, consider them the same person
                    if median_similarity > 1 - similarity_threshold:
                        # Remove the person with the higher ID
                        higher_id = max(id1, id2)
                        ids_to_remove.add(higher_id)

        # Remove the marked IDs from disappeared_persons
        for id_to_remove in ids_to_remove:
            print(f"Removing disappeared person with ID {id_to_remove}")
            del self.disappeared_persons[id_to_remove]
           

    def image_callback(self, msg):
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        trackedResults = self.model.track(cv_image, persist=True)
        detectedPersonsMsg = DetectedPersons()
        persons = []
        
        active_ids = set()

        try:
            track_ids = trackedResults[0].boxes.id.int().cpu().tolist()
            class_ids = trackedResults[0].boxes.cls.int().cpu().tolist()
            confidences = trackedResults[0].boxes.conf.float().cpu().tolist()
            keypoints_data = trackedResults[0].keypoints  # Get keypoints object for pose data
        except Exception:
            track_ids, class_ids, confidences, keypoints_data = [], [], [], []
     
        try:
            for bbox, track_id, class_id, confidence, kp in zip(trackedResults[0].boxes, track_ids, class_ids, confidences, keypoints_data):
                if(not bbox or not track_id or not confidence or not kp ):
                    continue
                
                if confidence < min_confidence_score:
                    continue 

                x1, y1, x2, y2 = map(int, bbox.xyxy[0])
                detectedPerson = DetectedPerson()
                boundingBox = BoundingBox()
                
                cropped_person = cv_image[y1:y2, x1:x2] 
                person_feature = self.extract_features(cropped_person)
                
                yolo_id = int(track_id) if track_id is not None else None
                
                best_similarity = 0.0 # Debugging!
                if yolo_id is not None:
                    # Check if YOLO ID is already mapped to a custom ID
                    if yolo_id in self.yolo_to_custom_id:
                        custom_id = self.yolo_to_custom_id[yolo_id]
                    else:
                        # Attempt to match with disappeared persons
                        best_match_id = None
                        best_similarity = 0.0
                        self.update_untracked_persons()  # Ensure no candidate is multiple in disappeared_persons

                        for disappeared_id, disappeared_features in self.disappeared_persons.items():
                            print(f'Comparing candidate with disappeared ID: {disappeared_id}')
                            similarities = []

                            # Calculate similarities between disappeared_features and person_feature
                            for disappeared_feature in disappeared_features:
                                sim = cosine_similarity(disappeared_feature.unsqueeze(0), person_feature.unsqueeze(0)).item()
                                print(f"    Similarity with disappeared feature: {sim}")  # Debug each similarity
                                similarities.append(sim)
                            print('f')
                            # Process disappeared_features with a sliding window for the first half
                            half_size = len(disappeared_features) // 2
                            print('disapperead_features')
                            first_half_features = list(disappeared_features)[:half_size]
                            print('disapperead_features')
                            first_half_similarities = similarities[:half_size]  # Use already calculated similarities
                            if len(disappeared_features) == max_images_per_person:
                                # Sliding window size
                                sliding_window_size = 5
                                filtered_features = []
                                filtered_similarities = []

                                # Process in disjoint windows (jumping by the window size)
                                for i in range(0, len(first_half_features), sliding_window_size):
                                    # Extract the current window of features and similarities

                                    window_features = first_half_features[i:i + sliding_window_size]
                                    window_similarities = first_half_similarities[i:i + sliding_window_size]

                                    if len(window_features) == sliding_window_size:
                                        # Pair similarities with their indices within the window

                                        indexed_similarities = list(enumerate(window_similarities))
                                        # Sort the similarities along with their indices
                                        indexed_similarities.sort(key=lambda x: x[1])

                                        # Find the median position
                                        median_pos = len(indexed_similarities) // 2
                                        # Get the index of the median similarity in the window
                                        median_index_in_window = indexed_similarities[median_pos][0]

                                        # Get the feature corresponding to the median similarity
                                        median_feature = window_features[median_index_in_window]
                                        # Append the median feature and similarity to the filtered lists
                                        filtered_features.append(median_feature)
                                        filtered_similarities.append(window_similarities[median_index_in_window])

                                        #print(f"Sliding window similarities: {window_similarities}")
                                        #print(f"Median similarity: {window_similarities[median_index_in_window]}")
                                    else:
                                        pass
                                        # Skip incomplete windows in this implementation
                                        #print(f"Skipping incomplete window: {window_features}")
                    
                                # Add the second half of features and similarities unchanged
                                filtered_features.extend(list(disappeared_features)[:half_size])
                                print('f6')
                                filtered_similarities.extend(similarities[half_size:])
                                print('f7')
                                # Update disappeared_features and similarities with the filtered results
                                disappeared_features = filtered_features
                                similarities = filtered_similarities

                            # Now compute the maximum similarity from the updated similarities
                            similarity = max(similarities) if similarities else 0.0
                            print(f'Best similarity after filtering: {similarity}')
                            print(f'Best similarity among all candidates: {best_similarity}')
                            print('After filtering similarities:')
                            print(similarities)

                            # Matching logic
                            if float(similarity) >= float(min_similarity) and float(similarity) > float(best_similarity):
                                best_match_id = disappeared_id
                                best_similarity = similarity
                                print('Match found')

                        if best_match_id is not None:
                            # Reassign the old ID
                            custom_id = best_match_id
                            del self.disappeared_persons[custom_id]
                        else:
                            # Assign a new custom ID
                            print('new id')
                            self.person_id_counter += 1
                            custom_id = self.person_id_counter
                        self.yolo_to_custom_id[yolo_id] = custom_id

                
                self.update_tracked_persons(custom_id, person_feature)
                active_ids.add(custom_id)   
                # self.store_image(cropped_person,f'id: {id}')
                # end reid part

                detectedPerson.id = custom_id
                detectedPerson.confidence = confidence

                # Access keypoint coordinates and confidence
                kp_xy = kp.xy.cpu().numpy()[0]  # Convert to numpy array for easier manipulation
                kp_conf = kp.conf.cpu().numpy()[0]
                
                # Prepare keypoints and body parts for publishing
                detectedPerson.body_parts = self.body_part_names
                detectedPerson.person_key_point = [
                    PersonKeyPoint(x=float(x), y=float(y), confidence=float(c)) for (x, y), c in zip(kp_xy, kp_conf)
                ]

                detectedPerson.label = f"{self.model.names[class_id]}"
                boundingBox.x_min = x1
                boundingBox.x_max = x2
                boundingBox.y_min = y1
                boundingBox.y_max = y2
                detectedPerson.bbox = boundingBox
                persons.append(detectedPerson)
        except Exception as e: 
            self.get_logger().error(f"Error processing detection: {e}")
            pass
        
         # Handle disappeared persons
        disappeared_ids = set(self.tracked_persons.keys()) - active_ids
        for disappeared_id in disappeared_ids:
            self.disappeared_persons[disappeared_id] = self.tracked_persons.pop(disappeared_id)

        # Remove old YOLO to custom ID mappings for disappeared YOLO IDs
        self.yolo_to_custom_id = {
            yolo_id: custom_id
            for yolo_id, custom_id in self.yolo_to_custom_id.items()
            if custom_id in self.tracked_persons
        }

        detectedPersonsMsg.persons = persons
        self.detected_persons_publisher.publish(detectedPersonsMsg)
        tracked_image = self.bridge.cv2_to_imgmsg(cv_image, encoding='bgr8')
        self.image_publisher.publish(tracked_image)


def main(args=None):
    rclpy.init(args=args)
    object_tracker = ObjectTracker()
    rclpy.spin(object_tracker)
    object_tracker.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

# REID: 
# Erstelle Map für aktive ID's (Personen) Custom ID -> Feature
# Erstelle Map für verschwundene ID's (Personen) Custom ID -> Feature
# Erstelle Map für YOLO-IDs zu Custom IDs
# Zähler für neue Custom IDs

# Definiere Konstante min_similarity

# Berechne Tracking für momentanes Image mit YOLO

# Für jedes Objekt (Bounding Box und ID) in den Ergebnissen:
    # Wenn das erkannte Objekt eine Person ist, dann weiter, anonsten überspringe

    # Schneide den Bereich der Person aus und extrahiere Merkmale

    # Wenn die YOLO-ID bereits aktiv ist (also yolo_id in yolo_to_custom):
        # Nutze die existierende Custom ID
    # Wenn die YOLO-ID nicht enthalten ist (bedeutet: Neue Person erkannt!):
        # Berechne die Ähnlichkeit zu allen verschwundenen Personen
        # Bestimme die höchste Ähnlichkeit
        # Ist die höchste Ähnlichkeit über dem Schwellwert min_similarity?
            # Ja: Weise der Person ihre alte Custom ID zu
            # Nein: Vergib der Person eine neue Custom ID

    # Mappe die YOLO-ID auf die Custom ID
    # Aktualisiere aktive Personen

# Aktualisiere verschwundene Personen -> alle bisher getracketen IDs ohne aktiven IDs
# Aktualisiere Mapping von YOLO-IDs auf Custom IDs (nur für aktive IDs)