import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
import numpy as np
import math
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
            1 # Low queue-size for low latency! 
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
        self.model = YOLO('yolov8n.pt')
        # Human class index in YOLO
        self.human_class_id = 0
        self.width_depth = 0
        self.depth_image = None
        self.depth = None
        self.distance_formatted = ""
    
    def image_callback(self, msg):
       
        # Convert ROS Image message to OpenCV image
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        
        # YOLOv8 detection
        results = self.model.track(cv_image, persist=True)
        positions = Float32MultiArray()
        positions.data = []
        
        boxes = results[0].boxes
        
        if boxes.data.shape[0] == 0:
            self.get_logger().debug('No detection found')
            return
       
        try:
            track_ids = results[0].boxes.id.int().cpu().tolist()
            class_ids = boxes.cls.int().cpu().tolist()  # when no object is detected an excption is thrown where cls attribute cant be found
            confidences = boxes.conf.float().cpu().tolist()
            detectedPersonsMsg = DetectedPersons()
            persons = []

            for bbox, track_id, class_id, confidence in zip(boxes,track_ids, class_ids,confidences): 
                if class_id == self.human_class_id:
                    x1, y1, x2, y2 = map(int, bbox.xyxy[0])
                    detectedPerson = DetectedPerson()
                    boundingBox = BoundingBox()
                    
                    detectedPerson.id = track_id
                    detectedPerson.confidence = confidence
                    boundingBox.x_min = x1
                    boundingBox.x_max = x2
                    boundingBox.y_min = y1
                    boundingBox.y_max = y2
                    detectedPerson.bbox = boundingBox
                    persons.append(detectedPerson)
        except Exception as e: 
            print(e)

      
        detectedPersonsMsg.persons = persons
        self.detected_persons_publisher.publish(detectedPersonsMsg)
        
        # Publish image where detection was used on to avoid delay from image and detection time! 
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
