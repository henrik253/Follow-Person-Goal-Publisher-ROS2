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


logging.getLogger('ultralytics').setLevel(logging.WARNING)

# pip install torchreid!
min_similarity = 0.55

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
        resized_image = cv2.resize(image, (128, 256))
        rgb_image = cv2.cvtColor(resized_image, cv2.COLOR_BGR2RGB)
        if(type == 'mapped'):
            cv2.imwrite(f'images/temp_{type}.jpg', rgb_image)
        else:
            self.store_image_counter += 1
            cv2.imwrite(f'images/temp{self.store_image_counter}_{type}.jpg', rgb_image)
       

    # RE-ID
    def preprocess_image(self,image):
        resized_image = cv2.resize(image, (128, 256))
        rgb_image = cv2.cvtColor(resized_image, cv2.COLOR_BGR2RGB)
       # cv2.imwrite('temp.jpg', rgb_image)
       # return 'temp.jpg'
        return rgb_image  

    def extract_features(self,image):
        """Extract features of the person."""
        #image_path = self.preprocess_image(image)
        #features = self.extractor([image_path])[0]
        features = self.extractor(self.preprocess_image(image))[0]
        return features

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
                
                x1, y1, x2, y2 = map(int, bbox.xyxy[0])
                detectedPerson = DetectedPerson()
                boundingBox = BoundingBox()
                
                # reid part
              
                cropped_person = cv_image[y1:y2, x1:x2] 
                person_feature = self.extract_features(cropped_person)
                
                yolo_id = int(track_id) if track_id is not None else None
                
                best_similarity = 0.0 # Debugging!
                
                if yolo_id is not None:
                # Check if YOLO ID is already mapped to a custom ID
                    if yolo_id in self.yolo_to_custom_id:
                        custom_id = self.yolo_to_custom_id[yolo_id]
                        self.store_image(cropped_person,'mapped')
                    else:
                        # Attempt to match with disappeared persons
                        best_match_id = None
                        best_similarity = 0.0
                        for disappeared_id, disappeared_feature in self.disappeared_persons.items():
                            similarity = cosine_similarity(
                                disappeared_feature.unsqueeze(0), person_feature.unsqueeze(0)
                            ).item()
                            self.store_image(cropped_person,'rematch')
                            print(f'disappeared id: {disappeared_id}')
                            if similarity > min_similarity and similarity > best_similarity:
                                best_match_id = disappeared_id
                                best_similarity = similarity

                        if best_match_id is not None:
                            # Reassign the old ID
                            custom_id = best_match_id
                            self.tracked_persons[custom_id] = person_feature
                            del self.disappeared_persons[custom_id]
                        else:
                            # Assign a new custom ID
                            self.person_id_counter += 1
                            custom_id = self.person_id_counter
                        self.yolo_to_custom_id[yolo_id] = custom_id

                
                self.tracked_persons[custom_id] = person_feature
                active_ids.add(custom_id)   

                # end reid part

                detectedPerson.id = custom_id
                detectedPerson.confidence = best_similarity

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