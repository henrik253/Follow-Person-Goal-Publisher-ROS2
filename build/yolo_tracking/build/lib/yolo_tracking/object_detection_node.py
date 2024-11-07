import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
import numpy as np
import logging
from object_tracking_messages.msg import DetectedPersons, DetectedPerson, BoundingBox

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
            keypoints = results[0].keypoints  # Get keypoints for pose data

            for bbox, track_id, class_id, confidence, kp in zip(
                results[0].boxes, track_ids, class_ids, confidences, keypoints
            ):
                x1, y1, x2, y2 = map(int, bbox.xyxy[0])
                detectedPerson = DetectedPerson()
                boundingBox = BoundingBox()
     
                detectedPerson.id = track_id
                detectedPerson.confidence = confidence

                # Pose classification based on keypoints
                pose_description = self.classify_pose(kp.data[0].cpu().tolist())
                print(pose_description)
                # Populate detected person data
               # pose_keypoints = " ".join([f"({int(x)}, {int(y)})" for x, y, _ in kp])
                pose_keypoints = 'no keypoints'
                detectedPerson.label = f"{self.model.names[class_id]} Pose: {pose_keypoints} - {pose_description}"
                boundingBox.x_min = x1
                boundingBox.x_max = x2
                boundingBox.y_min = y1
                boundingBox.y_max = y2
                detectedPerson.bbox = boundingBox
                persons.append(detectedPerson)
        except Exception as e: 
          #  self.get_logger().error(f"Error processing detection: {e}")
            persons = []

        detectedPersonsMsg.persons = persons
        self.detected_persons_publisher.publish(detectedPersonsMsg)
        
        # Publish image with detections
        tracked_image = self.bridge.cv2_to_imgmsg(cv_image, encoding='bgr8')
        self.image_publisher.publish(tracked_image)
# 2D feld fuer alle keypoints in einem 3D feld fue
    def classify_pose(self, kp):
        # Define indices for relevant joints
        hip_index = 11
        knee_index = 13
        ankle_index = 15
        left_wrist_index = 9
        right_wrist_index = 10

        # Ensure required keypoints are available
        if len(kp) > max(hip_index, knee_index, ankle_index, left_wrist_index, right_wrist_index):
        
            hip = np.array(kp[hip_index][:2])
            print(hip)
            knee = np.array(kp[knee_index][:2])
            print(knee)
            ankle = np.array(kp[ankle_index][:2])
            print(ankle)
            left_wrist = np.array(kp[left_wrist_index][:2])
            print(left_wrist)
            right_wrist = np.array(kp[right_wrist_index][:2])
            print(right_wrist)
            # Calculate vectors for thigh and calf
            thigh = knee - hip
            calf = ankle - knee
            thigh_length = np.linalg.norm(thigh)
            calf_length = np.linalg.norm(calf)

            # Check if person is sitting based on thigh and calf angles
            if thigh_length > 0 and calf_length > 0:
                cosine_angle = np.dot(thigh, calf) / (thigh_length * calf_length)
                angle = np.degrees(np.arccos(cosine_angle))
                if angle < 160:
                    return "sitting"

            # Check if arms are stretched based on wrist positions
            shoulder_width = abs(left_wrist[0] - right_wrist[0])
            if shoulder_width > thigh_length * 1.5:  # Adjust threshold as necessary
                return "stretching arms"

        return "default"
    

def main(args=None):
    rclpy.init(args=args)
    object_tracker = ObjectTracker()
    rclpy.spin(object_tracker)
    object_tracker.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
