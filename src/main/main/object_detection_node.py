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
import os

logging.getLogger('ultralytics').setLevel(logging.WARNING)

# pip install torchreid!

# REID Parameter
min_similarity = 0.65

max_queue_size = 2

max_fixed_tracked_person_size = 30

min_summed_similarity_treshold = 0.8 # similarity between values in fixed are coming close to this value

#YOLO Parameter
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
        self.last_tracked_persons = {}  # Custom ID -> feature vector
        self.fixed_tracked_persons = {} # Custom ID -> feature vector

        self.disappeared_persons = {}  # Custom ID -> feature vector
        self.yolo_to_custom_id = {}  # YOLO ID -> Custom ID
        self.person_id_counter = 0  # Counter for new IDs


        self.body_part_names = ["nose", "left_eye", "right_eye", "left_ear", "right_ear",
                                "left_shoulder", "right_shoulder", "left_elbow", "right_elbow",
                                "left_wrist", "right_wrist", "left_hip", "right_hip",
                                "left_knee", "right_knee", "left_ankle", "right_ankle"]
    
        self.store_image_counter = 0

        self.image_storage_dir = "/home/student/Desktop/images"
        os.makedirs(self.image_storage_dir, exist_ok=True)  

        self.cropped_person1 = None

    def save_cropped_person_image(self,type, custom_id, image = None):
        """
        Saves the cropped person image into a folder named after the custom ID.
        """
        image = self.cropped_person1
       
        # Create a directory for the custom ID if it doesn't exist
        person_dir = os.path.join(self.image_storage_dir, f"person_{custom_id}")
        os.makedirs(person_dir, exist_ok=True)

        # Save the image with a unique name
        image_count = len(os.listdir(person_dir))
        image_path = os.path.join(person_dir, f"image_{custom_id}_{type}.jpg")
        cv2.imwrite(image_path, image)
        #self.get_logger().info(f"Saved cropped image for person {custom_id} at {image_path}")


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
        if custom_id not in self.last_tracked_persons and custom_id not in self.fixed_tracked_persons: # new candidate will be created with fixed and current features
            self.last_tracked_persons[custom_id] = deque(maxlen=max_queue_size) 
            self.fixed_tracked_persons[custom_id] = []
        
        last_feature = None 
        
        if len(self.last_tracked_persons[custom_id]) >= max_queue_size: # max_queue size is m 
            last_feature = self.last_tracked_persons[custom_id].popleft() # remove the oldest feature map when max_size is reached | this is m+1 
            
        self.last_tracked_persons[custom_id].append(feature)
        #self.save_cropped_person_image(f'current_{self.last_tracked_persons[custom_id].index(feature.item())}',custom_id)
        if last_feature != None: 
            # last_tracked_persons is a queue and fixed_tracked_persons ins a list
            if len(self.fixed_tracked_persons[custom_id]) < max_fixed_tracked_person_size :
                self.fixed_tracked_persons[custom_id].append(last_feature)
                self.save_cropped_person_image(f'fixed_{len(self.fixed_tracked_persons[custom_id]) - 1}',custom_id)
               # self.save_cropped_person_image(f'fixed_{self.fixed_tracked_persons[custom_id].index(last_feature.item())}',custom_id)
            else:
                most_similar_feature, index, summed_similarity_all_neighbours = self.get_max_summed_similar_feature_of_neighbours(custom_id)
                feature_summed_similarity = self.get_summed_similarity(custom_id,feature)

                n = float(len(self.fixed_tracked_persons[custom_id]))
                normalized_summed_similarity_all_neighbours = summed_similarity_all_neighbours / (n - 1.0) # n - 1, because its a feature and is compared to all its n - 1 neighbours
                normalized_feature_summed_similarity = feature_summed_similarity / (n)

                if normalized_feature_summed_similarity < normalized_summed_similarity_all_neighbours and normalized_feature_summed_similarity >= min_summed_similarity_treshold:
                    self.fixed_tracked_persons[custom_id][index] = feature
                    self.save_cropped_person_image(f'fixed_{index}',custom_id)
                    #print(f'replacing the feature {summed_similarity_all_neighbours} and in norm {normalized_summed_similarity_all_neighbours}')
                    #print(f'with the new feature of person {custom_id} detected, with in sum {feature_summed_similarity} and in norm {normalized_feature_summed_similarity}')
                else: 
                    pass

    def get_max_summed_similar_feature_of_neighbours(self,custom_id): # need to be divied by count - 1
        most_similar_feature = None
        max_summed_feature_similarity = 0.0
        most_similar_feature_index = 0
        for i in range(len(self.fixed_tracked_persons[custom_id])):
            similarity_sum = float(0.0) # lowest possible value
            for j in range(len(self.fixed_tracked_persons[custom_id])): 
                if i != j:
                    similarity_sum += cosine_similarity(self.fixed_tracked_persons[custom_id][i].unsqueeze(0),self.fixed_tracked_persons[custom_id][j].unsqueeze(0)).item()

            if similarity_sum >= max_summed_feature_similarity:
                max_summed_feature_similarity = similarity_sum
                most_similar_feature = self.fixed_tracked_persons[custom_id][i]
                most_similar_feature_index = i

        return [most_similar_feature, most_similar_feature_index, max_summed_feature_similarity] # return the feature, with his index and its summed similarity to all neighbours
    

    def get_summed_similarity(self,custom_id,feature): # need to be divied by count 
        similarity_sum = 0.0
        for i in range(len(self.fixed_tracked_persons[custom_id])):
            similarity_sum += cosine_similarity(feature.unsqueeze(0),self.fixed_tracked_persons[custom_id][i].unsqueeze(0)).item()
        return similarity_sum
        
    # it can happen that there are multiple canditates that are the same person 
    # when does this happen: 
    # 1. a person reenters the frame and the calculated sim is lower than min_similarity -> means the stored candidates do not offer a good variety 
    # 2. or multiple boundingboxes of a same person occure  -
    # the problem is that now multiple candidates to match exist, and so the reid will give in the whole progress multiple id's
    # to the same person when reid is neccessary
    # for avoiding this the candidates will be deleted when they are simillar to each other and the one with lowest 
    # id will always stay!
    
    def update_untracked_persons(self):
        similarity_threshold = 0.05  # Threshold for considering two disappeared persons as the same
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
                    max_similarity = max(similarities)
                    print(f"Similarity between ID {id1} and ID {id2}: {max_similarity}")

                    # If similarity is above the threshold, consider them the same person
                    if max_similarity > 1 - similarity_threshold:
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
                self.cropped_person1 = cropped_person
                person_feature = self.extract_features(cropped_person)
                
                yolo_id = int(track_id) if track_id is not None else None
                
                best_similarity = 0.0 # Debugging!
                if yolo_id is not None:
                    # Check if YOLO ID is already mapped to a custom ID
                    if yolo_id in self.yolo_to_custom_id:
                        custom_id = self.yolo_to_custom_id[yolo_id]
                    else:
                        print('Person entered the frame!')
                        # Attempt to match with disappeared persons
                        best_match_id = None
                        best_similarity = 0.0
                        
                        #self.update_untracked_persons()  # Ensure no candidate is multiple in disappeared_persons
                        disapperead_persons = list(self.disappeared_persons.items())
                        for disappeared_id, disappeared_features in disapperead_persons:
                            print(f'\n Comparing entered candidate with disappeared ID: {disappeared_id}')
                            print(f'available ids to take: {list(self.disappeared_persons.keys())}')
                            
                            similarities = []

                            # Calculate similarities between disappeared_features and person_feature

                            for disappeared_feature in disappeared_features:
                                sim = cosine_similarity(disappeared_feature.unsqueeze(0), person_feature.unsqueeze(0)).item()
                                print(f"    Similarity with disappeared feature: {sim}")  # Debug each similarity
                                similarities.append(sim)
                        
                            similarity = max(similarities) if similarities else 0.0
                            print(f'Best similarity: {similarity}')

                            if float(similarity) >= float(min_similarity) and float(similarity) > float(best_similarity): # float neccessary?
                                best_match_id = disappeared_id
                                best_similarity = similarity
                                custom_id = best_match_id
                                print(f'removing {custom_id}')
                                del self.disappeared_persons[custom_id]
                                print(f'removed: {self.disappeared_persons.keys()}')
                                print(f'Match found for {best_match_id}')
                          
                        if best_match_id is None:
                            # Assign a new custom ID                
                            self.person_id_counter += 1
                            print("---------------------------")
                            print(f'new id {self.person_id_counter}')
                            print("---------------------------")
                            custom_id = self.person_id_counter
                            
                        self.yolo_to_custom_id[yolo_id] = custom_id
                        
                
                self.update_tracked_persons(custom_id, person_feature) # every detected person will be handled in these function but no untracked as the name suggests
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
            raise e
            pass
        
        # Handle disappeared persons
        disappeared_ids = set(self.last_tracked_persons.keys()) - active_ids
        for disappeared_id in disappeared_ids:
            self.disappeared_persons[disappeared_id] = self.fixed_tracked_persons[disappeared_id] # + list(self.last_tracked_persons[disappeared_id]) 

        # Remove old YOLO to custom ID mappings for disappeared YOLO IDs
        self.yolo_to_custom_id = {
            yolo_id: custom_id
            for yolo_id, custom_id in self.yolo_to_custom_id.items()
            if custom_id in self.last_tracked_persons
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