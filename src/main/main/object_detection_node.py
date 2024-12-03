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
import shutil


logging.getLogger().setLevel(logging.INFO)
logging.getLogger("ultralytics").setLevel(logging.ERROR)  
# pip install torchreid!
logging.basicConfig(
format='%(message)s'  # Custom format to show only the message
)
# REID Parameter
MIN_SIMILARITY_FOR_MATCHING = 0.68
MAX_QUEUE_SIZE_LAST_FEATURES = 2
MAX_LIST_SIZE_FIXED_FEATURES = 100
MIN_AVG_SIMILARITY_TRESHOLD = 0.6 # similarity between values in fixed are coming close to this value
MIN_REMOVE_CANDIDATE_TRESHOLD = 0.9
# REID Debugging
SAVE_CROPPED_PERSON = True
ENABLE_CACHING = True
#YOLO Parameter
YOLO_MIN_CONF_SCORE = 0.8
MIN_KEY_POINTS = 10 # Important for quality!!!!

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

        # Improvements
        self.similarity_cache = {} 

        self.body_part_names = ["nose", "left_eye", "right_eye", "left_ear", "right_ear",
                                "left_shoulder", "right_shoulder", "left_elbow", "right_elbow",
                                "left_wrist", "right_wrist", "left_hip", "right_hip",
                                "left_knee", "right_knee", "left_ankle", "right_ankle"]
        
        self.image_storage_dir = "/home/student/Desktop/images"
        self.log_storage_dir = "/home/student/Desktop/logs"
        if os.path.exists(self.image_storage_dir):
            shutil.rmtree(self.image_storage_dir)
        if os.path.exists(self.log_storage_dir):
            shutil.rmtree(self.log_storage_dir)

        os.makedirs(self.image_storage_dir, exist_ok=True)  
        os.makedirs(self.log_storage_dir, exist_ok=True)  
        self.current_cropped_person = None

        self.image_counter = -1

    def get_image_counter(self):
        self.image_counter+=1
        return self.image_counter

    def save_cropped_person_image(self,type, custom_id, image = None):
        if(not SAVE_CROPPED_PERSON):
            return 
        
        image = self.current_cropped_person
       
        # Create a directory for the custom ID if it doesn't exist
        person_dir = os.path.join(self.image_storage_dir, f"person_{custom_id}")
        os.makedirs(person_dir, exist_ok=True)

        # Save the image with a unique name
        image_count = len(os.listdir(person_dir))
        image_path = os.path.join(person_dir, f"image_{custom_id}_{type}.jpg")
        cv2.imwrite(image_path, image)
        #self.get_logger().info(f"Saved cropped image for person {custom_id} at {image_path}")

    def remove_cropped_person_folder(self, custom_id): 
        if(not SAVE_CROPPED_PERSON):
            return 
        
        if os.path.exists(self.image_storage_dir):
            try:
                os.rename(os.path.join(self.image_storage_dir, f"person_{custom_id}"), os.path.join(self.image_storage_dir, f"person_{custom_id}_REMOVED"))
            except:
                pass

    # RE-ID
    def preprocess_image(self,image):
        resized_image = cv2.resize(image, (256, 512))
        rgb_image = cv2.cvtColor(resized_image, cv2.COLOR_BGR2RGB)
        return rgb_image  

    def extract_features(self,image):
        features = self.extractor(self.preprocess_image(image))[0]
        return features

    
    def update_tracked_persons(self, custom_id, feature):
        if custom_id not in self.last_tracked_persons and custom_id not in self.fixed_tracked_persons: # new candidate will be created with fixed and current features
            self.last_tracked_persons[custom_id] = deque(maxlen=MAX_QUEUE_SIZE_LAST_FEATURES) 
            self.fixed_tracked_persons[custom_id] = []
        
        last_feature = None 
        
        if len(self.last_tracked_persons[custom_id]) >= MAX_QUEUE_SIZE_LAST_FEATURES: # max_queue size is m 
            last_feature = self.last_tracked_persons[custom_id].popleft() # remove the oldest feature map when max_size is reached | this is m+1 
            
        self.last_tracked_persons[custom_id].append(feature)
        #self.save_cropped_person_image(f'current_{self.last_tracked_persons[custom_id].index(feature.item())}',custom_id)
        if last_feature != None: 
            # last_tracked_persons is a queue and fixed_tracked_persons ins a list
            if len(self.fixed_tracked_persons[custom_id]) < MAX_LIST_SIZE_FIXED_FEATURES :
                self.fixed_tracked_persons[custom_id].append(last_feature)
                self.save_cropped_person_image(f'fixed_{len(self.fixed_tracked_persons[custom_id]) - 1}',custom_id)
            else:
                most_similar_feature, index, summed_similarity_all_neighbours = self.get_max_summed_similar_feature_of_neighbours(custom_id)
                feature_summed_similarity = self.get_summed_similarity(custom_id,feature)
                n = float(len(self.fixed_tracked_persons[custom_id]))
                normalized_summed_similarity_all_neighbours = summed_similarity_all_neighbours / (n - 1.0) # n - 1, because its a feature and is compared to all its n - 1 neighbours
                normalized_feature_summed_similarity = feature_summed_similarity / (n)

                if normalized_feature_summed_similarity < normalized_summed_similarity_all_neighbours and normalized_feature_summed_similarity >= MIN_AVG_SIMILARITY_TRESHOLD:
                    self.fixed_tracked_persons[custom_id][index] = feature
                    self.save_cropped_person_image(f'fixed_{index}',custom_id)
                    #self.get_logger().info(f'replace avg sim {normalized_summed_similarity_all_neighbours} with compared avg sim {normalized_feature_summed_similarity}')
                else: 
                    pass

    def get_max_summed_similar_feature_of_neighbours(self,custom_id): 
        most_similar_feature = None
        max_summed_feature_similarity = 0.0
        most_similar_feature_index = 0
        for i in range(len(self.fixed_tracked_persons[custom_id])):
            similarity_sum = float(0.0) # lowest possible value
            for j in range(len(self.fixed_tracked_persons[custom_id])): 
                if i != j:  
                    similarity_sum += self.get_similarity(self.fixed_tracked_persons[custom_id][i],self.fixed_tracked_persons[custom_id][j])

            if similarity_sum >= max_summed_feature_similarity:
                max_summed_feature_similarity = similarity_sum
                most_similar_feature = self.fixed_tracked_persons[custom_id][i]
                most_similar_feature_index = i

        return [most_similar_feature, most_similar_feature_index, max_summed_feature_similarity] 
    

    def get_summed_similarity(self,custom_id,feature):
        similarity_sum = 0.0
        for i in range(len(self.fixed_tracked_persons[custom_id])):
            similarity_sum += self.get_similarity(feature,self.fixed_tracked_persons[custom_id][i])
        return similarity_sum
        
    # it can happen that there are multiple canditates that are the same person 
    # when does this happen: 
    # 1. a person reenters the frame and the calculated sim is lower than min_similarity -> means the stored candidates do not offer a good variety 
    # 2. or multiple boundingboxes of a same person occure  -
    # the problem is that now multiple candidates to match exist, and so the reid will give in the whole progress multiple id's
    # to the same person when reid is neccessary
    # for avoiding this the candidates will be deleted when they are simillar to each other and the one with lowest 
    # id will always stay!
    def update_candidates(self):
        # Update candidates for all appereances but based on the id's that are missing! 

        ids_to_remove = {} # Keep track of IDs to remove
        candidate_ids = list(self.fixed_tracked_persons.keys())  # Get list of disappeared IDs
        # Compare every pair of disappeared persons
        for i, id1 in enumerate(candidate_ids):
            if id1 in ids_to_remove.values():
                continue 

            features1 = self.fixed_tracked_persons[id1]

            for id2 in candidate_ids[i + 1:]:
                if id2 in ids_to_remove.values():
                    continue  

                features2 = self.fixed_tracked_persons[id2]

                similarities = []
                for feature1 in features1:
                    for feature2 in features2:
                        sim = self.get_similarity(
                            feature1, feature2
                        )
                        similarities.append(sim)

                if similarities:
                    max_similarity = max(similarities)
                    self.get_logger().info(f"Similarity between ID {id1} and ID {id2}: {max_similarity}")
                  
                    if max_similarity >= MIN_REMOVE_CANDIDATE_TRESHOLD:   # If similarity is above the threshold, we consider them as the same person or as an inconsistency! 
                        ids_to_remove[id1] = id2

        # Remove the marked IDs from all appereances!
        for base_id, incosistent_id in ids_to_remove.items():
            self.merge_candidates(incosistent_id,base_id)
            self.get_logger().info(f"Merging candidate {incosistent_id} in {base_id}")
            self.remove_cropped_person_folder(incosistent_id)
        
    # just fill up IMPORTANT TO SAY WHY 
    def merge_candidates(self,inconsistent_id, id_to_merge_in):  
         
        while len(self.fixed_tracked_persons[id_to_merge_in]) < MAX_LIST_SIZE_FIXED_FEATURES:
            self.fixed_tracked_persons[id_to_merge_in].append(self.fixed_tracked_persons[inconsistent_id].pop()) 
        
        del self.fixed_tracked_persons[inconsistent_id]
        del self.last_tracked_persons[inconsistent_id]
        try:
            del self.disappeared_persons[inconsistent_id] 
        except KeyError as e:
            pass
        
    def get_similarity(self, feature1, feature2):
        # Create a unique key for the pair
        if ENABLE_CACHING:
            pair_key = (id(feature1), id(feature2))
            if pair_key in self.similarity_cache:
                return self.similarity_cache[pair_key]
        
        # Calculate similarity and cache it
        similarity = cosine_similarity(feature1.unsqueeze(0), feature2.unsqueeze(0)).item()
        self.similarity_cache[pair_key] = similarity
        return similarity

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
                
                if confidence < YOLO_MIN_CONF_SCORE:
                    continue 
                #print(len(kp.xy.cpu().numpy()[0]))

                
                valid_keypoints = [(x, y) for (x, y), c in zip(kp.xy.cpu().numpy()[0], kp.conf.cpu().numpy()[0]) if c > 0.5]  # Confidence threshold
               
                if len(valid_keypoints)  <= MIN_KEY_POINTS:
                    continue
                

                detectedPerson = DetectedPerson()
                boundingBox = BoundingBox()

                x1, y1, x2, y2 = map(int, bbox.xyxy[0])
                cropped_person = cv_image[y1:y2, x1:x2] 
                self.current_cropped_person = cropped_person
                person_feature = self.extract_features(cropped_person)
                yolo_id = int(track_id)
                
                best_similarity = 0.0 # Debugging!

                # Check if YOLO ID is already mapped to a custom ID
                if yolo_id in self.yolo_to_custom_id.keys():
                    custom_id = self.yolo_to_custom_id[yolo_id]
                   
                else:
                    self.get_logger().info('\n \n \n')
                    self.get_logger().info('Person entered the frame!')
                    # Attempt to match with disappeared persons
                    best_match_id = None
                    best_similarity = 0.0
                    
                   
                    cloned_disapperead_persons = list(self.disappeared_persons.items())
                    print(f'------ DISAPPEARED KEYS: {self.disappeared_persons.keys()}--------')
                    for disappeared_id, disappeared_features in cloned_disapperead_persons:
                        self.get_logger().info(f'   Comparing entered candidate with disappeared ID: {disappeared_id}')
                        self.get_logger().info(f'   available ids to take: {list(self.disappeared_persons.keys())}')
                        similarities = []

                        # Calculate similarities between disappeared_features and person_feature
                        for disappeared_feature in disappeared_features:
                            sim = self.get_similarity(disappeared_feature, person_feature)
                            torch.cuda.synchronize() 
                            similarities.append(sim)
                            self.get_logger().info(f"       Similarity with disappeared feature: {sim}")  # Debug each similarity
                        

                        if similarities:
                            highest_values = sorted(similarities, reverse=True)[:5] # insteaf of max we take n best values
                            similarity = np.mean(highest_values)
                        else: 
                            similarity = 0.0
                        # similarity = max(similarities) if similarities else 0.0
                        self.get_logger().info(f'       Best similarity: {similarity}')

                        if float(similarity) >= float(MIN_SIMILARITY_FOR_MATCHING) and float(similarity) > float(best_similarity): # float neccessary?
                            best_match_id = disappeared_id
                            best_similarity = similarity
                            custom_id = best_match_id
                       

                    if best_match_id is not None:
                        del self.disappeared_persons[custom_id]
                        self.get_logger().info(f'   MATCH FOUND FOR {best_match_id}')
                        self.save_cropped_person_image(f"matching_{self.get_image_counter()}",custom_id,cropped_person)
                    else:
                        # Assign a new custom ID                
                        self.person_id_counter += 1
                        self.get_logger().info(f'    new id {self.person_id_counter}')
                        custom_id = self.person_id_counter
                        self.save_cropped_person_image(f"new_id_{self.get_image_counter()}",custom_id,cropped_person)
                        
                    self.yolo_to_custom_id[yolo_id] = custom_id
                    self.update_candidates()  # Ensure no candidate is multiple in disappeared_persons      !!!!! BUGFIXING !!!!!! <----  
                
                self.update_tracked_persons(custom_id, person_feature) # every detected person will be handled in these function but no untracked as the name suggests
                active_ids.add(custom_id)   

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
        disappeared_ids = set(self.fixed_tracked_persons.keys()) - set(active_ids)
        self.disappeared_persons = {}
        for disappeared_id in disappeared_ids:
            self.disappeared_persons[disappeared_id] = self.fixed_tracked_persons[disappeared_id] # + list(self.last_tracked_persons[disappeared_id]) # only using fixed frames
    
        # Remove old YOLO to custom ID mappings for disappeared YOLO IDs
        self.yolo_to_custom_id = {
            yolo_id: custom_id
            for yolo_id, custom_id in self.yolo_to_custom_id.items()
            if custom_id in self.fixed_tracked_persons
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