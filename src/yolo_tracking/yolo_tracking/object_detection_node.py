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

logging.getLogger('ultralytics').setLevel(logging.WARNING)

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
            10
        )

        self.image_publisher = self.create_publisher(
            Image,
            'tracked_image',
            10
        )
        
        # Create CvBridge to convert ROS Image messages to OpenCV images
        self.bridge = CvBridge()
        self.model = YOLO('yolov8n-pose.pt')
    
    def image_callback(self, msg):
        # Convert ROS Image message to OpenCV image
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        
        # YOLOv8 detection
        results = self.model.track(cv_image, persist=True)
        
        if results[0].boxes.data.shape[0] == 0:
            self.get_logger().debug('No detection found')
            return
       
        detectedPersonsMsg = DetectedPersons()
        persons = []
        
        try:
            track_ids = results[0].boxes.id.int().cpu().tolist()
            class_ids = results[0].boxes.cls.int().cpu().tolist()
            confidences = results[0].boxes.conf.float().cpu().tolist()
            keypoints_data = results[0].keypoints  # Get keypoints object for pose data

            for bbox, track_id, class_id, confidence, kp in zip(
                results[0].boxes, track_ids, class_ids, confidences, keypoints_data
            ):
                x1, y1, x2, y2 = map(int, bbox.xyxy[0])
                detectedPerson = DetectedPerson()
                boundingBox = BoundingBox()

                detectedPerson.id = track_id
                detectedPerson.confidence = confidence

                # Access keypoint coordinates and confidence
                kp_xy = kp.xy.cpu().numpy()[0]  # Convert to numpy array for easier manipulation
                kp_conf = kp.conf.cpu().numpy()[0]
                print(kp_xy)
                # Prepare keypoints and body parts for publishing
                body_part_names = ["nose", "left_eye", "right_eye", "left_ear", "right_ear",
                                "left_shoulder", "right_shoulder", "left_elbow", "right_elbow",
                                "left_wrist", "right_wrist", "left_hip", "right_hip",
                                "left_knee", "right_knee", "left_ankle", "right_ankle"]

                detectedPerson.body_parts = body_part_names
                detectedPerson.person_key_point = [
                    PersonKeyPoint(x=float(x), y=float(y), confidence=float(c)) for (x, y), c in zip(kp_xy, kp_conf)
                ]

                # Populate additional data
                detectedPerson.label = f"{self.model.names[class_id]}"
                boundingBox.x_min = x1
                boundingBox.x_max = x2
                boundingBox.y_min = y1
                boundingBox.y_max = y2
                detectedPerson.bbox = boundingBox
                persons.append(detectedPerson)
        except Exception as e: 
            self.get_logger().error(f"Error processing detection: {e}")
            persons = []


        detectedPersonsMsg.persons = persons
        self.detected_persons_publisher.publish(detectedPersonsMsg)
        
        # Publish image with detections
        tracked_image = self.bridge.cv2_to_imgmsg(cv_image, encoding='bgr8')
        self.image_publisher.publish(tracked_image)

    def classify_pose(self, kp):
        # Define indices for relevant joints
        left_wrist_index = 9
        right_wrist_index = 10

        # Ensure required keypoints are available
        if len(kp) > max(left_wrist_index, right_wrist_index):
            left_wrist = np.array(kp[left_wrist_index][:2])  # (x, y) of left wrist
            right_wrist = np.array(kp[right_wrist_index][:2])  # (x, y) of right wrist

            # Calculate the distance between the wrists
            wrist_distance = np.linalg.norm(left_wrist - right_wrist)

            # Threshold for determining if hands are folded
            if wrist_distance < 50:  # Adjust threshold as needed
                return "hands folded"

        return "normal"


def main(args=None):
    rclpy.init(args=args)
    object_tracker = ObjectTracker()
    rclpy.spin(object_tracker)
    object_tracker.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
