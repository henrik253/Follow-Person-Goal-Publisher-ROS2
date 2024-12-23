import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from PIL import Image as PIL_Image
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
from torchvision import transforms
from collections import deque 
import statistics
import os
import shutil
from main.utils.id_mapper import idMapper


logging.basicConfig(
    level=logging.INFO, 
    format='%(message)s' 
)

logging.getLogger("ultralytics").setLevel(logging.ERROR)  # Suppress messages from 'ultralytics'

# Disable other unnecessary loggers if required
logging.getLogger("rclpy").setLevel(logging.ERROR)  # Suppress logging from rclpy if needed
logging.getLogger("sensor_msgs").setLevel(logging.ERROR)  # Suppress logging from sensor_msgs if needed

# REID Parameter
MAX_QUEUE_SIZE_LAST_FEATURES = 15
MAX_LIST_SIZE_FIXED_FEATURES = 10
MIN_SIMILARITY_FOR_MATCHING = 0.6
MIN_AVG_SIMILARITY_TRESHOLD = 0.8 # average similarity between features inside a candidate are coming close to this value
MIN_REMOVE_CANDIDATE_TRESHOLD = 0.8
FILL_FIXED_FEATURES_WITH_FILTERING = True 

USE_MARGIN = False
MARGIN_LEFT_RIGHT_PERCENTAGE = 0.1 

# REID Debugging
SAVE_CROPPED_PERSON = True
ENABLE_CACHING = True
#YOLO Parameter
YOLO_MIN_CONF_SCORE = 0.8
MIN_KEY_POINTS = 10 

class ObjectTracker(Node): 
    def __init__(self): 
        super().__init__('yolo_tracking')

        self.create_subscription(
            Image,
            '/zed/zed_node/left/image_rect_color',
            self.image_callback,
            4  # Low queue-size for low latency
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
        self.extractor = FeatureExtractor( # 
            model_name='osnet_x1_0',   # 1. perfect run: 
            device='cuda' if torch.cuda.is_available() else 'cpu'
        )

        self.transform =  transforms.Compose([
            transforms.Resize((256, 128)),  
            transforms.ToTensor(),
            transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])  
        ])

        # ID manager
        self.last_tracked_persons = {}  # Custom ID -> feature vector
        self.fixed_tracked_persons = {} # Custom ID -> feature vector

        self.disappeared_ids = set() # disapperead ids
        self.disappeared_yolo_ids = set()
        self.yolo_to_custom_id = idMapper()  # YOLO ID -> Custom ID
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
        self.counter_map = {}

    def get_image_counter(self, custom_id = None):
        self.image_counter+=1
        return self.image_counter

    def save_cropped_person_image(self,type, custom_id, image = None):
        if(not SAVE_CROPPED_PERSON):
            return 
        
        image = self.current_cropped_person
        person_dir = os.path.join(self.image_storage_dir, f"person_{custom_id}")
        os.makedirs(person_dir, exist_ok=True)
        resized_image = cv2.resize(image, (256, 512))
        rgb_image = cv2.cvtColor(resized_image, cv2.COLOR_RGB2RGBA)
        image_count = len(os.listdir(person_dir))
        image_path = os.path.join(person_dir, f"image_{custom_id}_{type}.jpg")
        cv2.imwrite(image_path, rgb_image)


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
        pil_image = PIL_Image.fromarray(image)
        return self.transform(pil_image)

    def extract_features(self,image):
        features = self.extractor(self.preprocess_image(image))[0]
        return features
    
    def update_tracked_person(self, custom_id, feature):
        if custom_id not in self.last_tracked_persons and custom_id not in self.fixed_tracked_persons: # new candidate will be created with fixed and current features
            self.last_tracked_persons[custom_id] = deque(maxlen=MAX_QUEUE_SIZE_LAST_FEATURES) 
            self.fixed_tracked_persons[custom_id] = []
        
        last_feature = None 
        
        if len(self.last_tracked_persons[custom_id]) >= MAX_QUEUE_SIZE_LAST_FEATURES: # max_queue size is m 
                last_feature = self.last_tracked_persons[custom_id].popleft() # remove the oldest feature map when max_size is reached | this is m+1 
        
        self.last_tracked_persons[custom_id].append(feature) # fill fixed_frames up with last_frames without checking 

        if last_feature != None: 
            n = float(len(self.fixed_tracked_persons[custom_id]))

            if len(self.fixed_tracked_persons[custom_id]) < MAX_LIST_SIZE_FIXED_FEATURES :                
                if FILL_FIXED_FEATURES_WITH_FILTERING and n > 0:
                    avg_similarity_of_feature_to_fixed_features = self.get_summed_similarity_of_feature(custom_id,feature) / n
                    if(avg_similarity_of_feature_to_fixed_features >= MIN_AVG_SIMILARITY_TRESHOLD):
                        self.fixed_tracked_persons[custom_id].append(last_feature)
                        self.save_cropped_person_image(f'first_fixed_{len(self.fixed_tracked_persons[custom_id]) - 1}',custom_id)
                        if(custom_id == 1):    
                            print(f'fill: {avg_similarity_of_feature_to_fixed_features}')
                else:
                    self.fixed_tracked_persons[custom_id].append(last_feature)
                    self.save_cropped_person_image(f'first_fixed_{len(self.fixed_tracked_persons[custom_id]) - 1}',custom_id)
            else:
                most_similar_feature, index, summed_similarity_all_neighbours = self.get_summed_similarity_of_fixed_features(custom_id)
                feature_summed_similarity = self.get_summed_similarity_of_feature(custom_id,feature)
                normalized_summed_similarity_all_neighbours = summed_similarity_all_neighbours / (n - 1.0) # n - 1, because its a feature and is compared to all its n - 1 neighbours
          
                normalized_feature_summed_similarity = feature_summed_similarity / (n)
                
                if normalized_feature_summed_similarity < normalized_summed_similarity_all_neighbours and normalized_feature_summed_similarity >= MIN_AVG_SIMILARITY_TRESHOLD:
                    if(custom_id == 1):
                        print(f'id: {custom_id} : {normalized_summed_similarity_all_neighbours}')
                    self.fixed_tracked_persons[custom_id][index] = feature
                    self.save_cropped_person_image(f'replace_{index}',custom_id)
                else: 
                    pass

    def get_summed_similarity_of_fixed_features(self,custom_id): 
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
    

    def get_summed_similarity_of_feature(self,custom_id,feature):
        similarity_sum = 0.0
        for i in range(len(self.fixed_tracked_persons[custom_id])):
            similarity_sum += self.get_similarity(feature,self.fixed_tracked_persons[custom_id][i])
        return similarity_sum
        
    def update_candidates(self):
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

                similarities_from_id1_and_id2 = []
                for feature1 in features1:
                    for feature2 in features2:
                        sim = self.get_similarity(
                            feature1, feature2
                        )
                        similarities_from_id1_and_id2.append(sim)

                if similarities_from_id1_and_id2:   
                    mean_similarity = statistics.mean(similarities_from_id1_and_id2)

                    if mean_similarity >= MIN_REMOVE_CANDIDATE_TRESHOLD:   # If similarity is above the threshold, we consider them as the same person or as an inconsistency! 
                        ids_to_remove[id1] = id2

        # Remove the marked IDs from all appereances!
        for base_id, incosistent_id in ids_to_remove.items():
            self.merge_candidates(incosistent_id,base_id)
            #print(f"Merging candidate {incosistent_id} in {base_id}")
            self.remove_cropped_person_folder(incosistent_id)
        
    # just fill up IMPORTANT TO SAY WHY 
    def merge_candidates(self,inconsistent_id, id_to_merge_in):  
        try:
            while len(self.fixed_tracked_persons[id_to_merge_in]) < MAX_LIST_SIZE_FIXED_FEATURES and len(self.fixed_tracked_persons[inconsistent_id]) > 0: 
                self.fixed_tracked_persons[id_to_merge_in].append(self.fixed_tracked_persons[inconsistent_id].pop()) 
            
            del self.fixed_tracked_persons[inconsistent_id]
            del self.last_tracked_persons[inconsistent_id]
            yolo_id = self.yolo_to_custom_id.get_key_from_value(inconsistent_id)
            
            if(yolo_id):
                self.disappeared_yolo_ids.remove(yolo_id)
        except KeyError:
            pass

    def get_cosine_similarity(self, feature1, feature2):
        # Create a unique key for the pair
        if ENABLE_CACHING:
            pair_key = (id(feature1), id(feature2))
            if pair_key in self.similarity_cache:
                return self.similarity_cache[pair_key]
        
        similarity = cosine_similarity(feature1.unsqueeze(0), feature2.unsqueeze(0)).item()
        self.similarity_cache[pair_key] = similarity
        return similarity
    
    def get_similarity(self, feature1, feature2, w1=0.9, w2=0.1, max_distance=30.0, min_distance=5.0):
        if ENABLE_CACHING:
            pair_key = (id(feature1), id(feature2))
            if pair_key in self.similarity_cache:
                return self.similarity_cache[pair_key]

        cosine_sim = cosine_similarity(feature1.unsqueeze(0), feature2.unsqueeze(0)).item()
        distance = torch.dist(feature1, feature2, p=2).item()
        
        if distance <= min_distance:
            normalized_distance = 1.0
        elif distance >= max_distance:
            normalized_distance = 0.0
        else:
            normalized_distance = (max_distance - distance) / (max_distance - min_distance)
        
        combined_score = w1 * cosine_sim + w2 * normalized_distance
        combined_score = max(0.0, min(1.0, cosine_sim))

        if ENABLE_CACHING:
            self.similarity_cache[pair_key] = combined_score
        
        return combined_score


    
    def determine_best_similarity(self,similarities):
        if similarities:
             top_n_candidates = int((MAX_LIST_SIZE_FIXED_FEATURES + MAX_QUEUE_SIZE_LAST_FEATURES) / 4)
             highest_values = sorted(similarities, reverse=True)[:top_n_candidates]
             return statistics.median(highest_values)
        else: 
            return 0.0
        

    def calculate_similarities(self, disappeared_id, current_person_feature):
        cosine_similarities = []
        euclidian_sims = []

        for disappeared_feature in self.fixed_tracked_persons[disappeared_id]:
            sim = self.get_similarity(disappeared_feature, current_person_feature)
            cosine_similarities.append(sim)

        for disappeared_feature in self.last_tracked_persons[disappeared_id]:
            sim = self.get_similarity(disappeared_feature, current_person_feature)
            cosine_similarities.append(sim)

        euclidian_sims = [sim.item() if isinstance(sim, torch.Tensor) else float(sim) for sim in euclidian_sims] # for experimenting, try it yourself 
        cosine_similarities = [sim.item() if isinstance(sim, torch.Tensor) else float(sim) for sim in cosine_similarities]

        return cosine_similarities
    
    def image_callback(self, msg):
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        trackedResults = self.model.track(cv_image, persist=True, iou=0.8)
        detectedPersonsMsg = DetectedPersons()
        persons = []
        
        active_ids = set()
        active_yolo_ids = set() 

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
                valid_keypoints = [(x, y) for (x, y), c in zip(kp.xy.cpu().numpy()[0], kp.conf.cpu().numpy()[0]) if c > 0.5]  # Confidence threshold
               
                if len(valid_keypoints)  <= MIN_KEY_POINTS:
                    continue
            
                detectedPerson = DetectedPerson()
                boundingBox = BoundingBox()

                x1, y1, x2, y2 = map(int, bbox.xyxy[0])
                if USE_MARGIN:
                    margin_x = int((x2 - x1) * MARGIN_LEFT_RIGHT_PERCENTAGE)
                    x1_adjusted = max(x1 + margin_x, 0) 
                    x2_adjusted = min(x2 - margin_x, cv_image.shape[1])  

                    # Crop the person with the adjusted bounding box
                    cropped_person = cv_image[y1:y2, x1_adjusted:x2_adjusted]
                else:
                    # Use the full bounding box if no margin is applied
                    cropped_person = cv_image[y1:y2, x1:x2]

                self.current_cropped_person = cropped_person
                current_person_feature = self.extract_features(cropped_person)
                yolo_id = int(track_id)

                # Check if YOLO ID is already mapped to a custom ID
                if yolo_id in self.yolo_to_custom_id.keys() and yolo_id not in self.disappeared_yolo_ids:
                    custom_id = self.yolo_to_custom_id.get(yolo_id)
                else:
                    #print('\n \n \n')
                    #print(f'Person entered the frame! avaible {self.disappeared_ids}')
                    #self.update_candidates()  # Ensure no candidate is multiple in disappeared_persons      !!!!! BUGFIXING !!!!!! <----  
                
                    # Attempt to match with disappeared persons
                    best_match_id = None
                    best_similarity = 0.0
                    # Compare entered person with disappeared featrues 
                    for disappeared_id in self.disappeared_ids:
                        #print(f'comparing to {disappeared_id}')
                        similarities = self.calculate_similarities(disappeared_id,current_person_feature)
                        similarity = self.determine_best_similarity(similarities)
                       
                        if float(similarity) >= float(MIN_SIMILARITY_FOR_MATCHING) and float(similarity) > float(best_similarity): # float neccessary?
                            best_match_id = disappeared_id
                            best_similarity = similarity
                            custom_id = best_match_id
                       

                    if best_match_id is not None:
                        self.disappeared_ids.remove(best_match_id)
                        self.save_cropped_person_image(f"matching_{self.get_image_counter()}",custom_id,cropped_person)
                    else:      
                        self.person_id_counter += 1
                        custom_id = self.person_id_counter
                        self.save_cropped_person_image(f"new_id_{self.get_image_counter()}",custom_id,cropped_person)
                        
                    self.yolo_to_custom_id.put(yolo_id,custom_id)
                  
                self.update_tracked_person(custom_id, current_person_feature) 
                active_ids.add(custom_id)   
                active_yolo_ids.add(yolo_id)

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
        self.disappeared_ids = set(self.fixed_tracked_persons.keys()) - set(active_ids)
        self.disappeared_yolo_ids = set(self.yolo_to_custom_id.keys()) - active_yolo_ids
     
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
