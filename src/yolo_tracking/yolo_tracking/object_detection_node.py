import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
from cv_bridge import CvBridge
import cv2 
from ultralytics import YOLO
import numpy as np

class ObjectTracker(Node): 
    def __init__(self): 
        super().__init__('yolo_tracking')

        # Create a subscription to the image topic (from camera or other sources)
        self.subscription = self.create_subscription(
            Image,
            '/zed/zed_node/left/image_rect_color',
            self.image_callback,
            10)

        # Create a publisher for detected person's position 
        self.positions_publisher = self.create_publisher(
            Float32MultiArray,
            'detected_object_positions',
            10
        )
        
        self.publish = True

        # Create a CvBridge to convert ROS Image messages to OpenCV images
        self.bridge = CvBridge()

        # Load the YOLOv8 model (we are using the pretrained one here)
        self.model = YOLO('yolov8n.pt')  # You can choose 'yolov8m.pt', 'yolov8l.pt', or a custom model

        # Human class index in YOLO (usually 'person' is class 0)
        self.human_class_id = 0

    def image_callback(self, msg):
        # Convert ROS Image message to OpenCV image
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        # Perform YOLOv8 detection
        results = self.model(cv_image)
        positions = Float32MultiArray()
        positions.data = []
        # Publish detected Objects on topic
    
             # Extract detections
        for result in results:
            for bbox in result.boxes:
                if bbox.cls == self.human_class_id:  # Check if detection is a person (class 0)
                    positions.data = []
                    x1, y1, x2, y2 = map(int, bbox.xyxy[0])  # Bounding box coordinates
                    cv2.rectangle(cv_image, (x1, y1), (x2, y2), (0, 255, 0), 2)
                    cv2.putText(cv_image, 'Person', (x1, y1-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (36, 255, 12), 2)
                    
                    x_center = (x1 + x2) / 2 
                    y_center = (y1 + y2) / 2

                    x_center = x_center * cv_image.shape[1]
                    y_center = y_center * cv_image.shape[0]
                    # Append to positions
                    positions.data.append(x_center)
                    positions.data.append(y_center)
        # Display the image (or you could publish the processed image as well)

        if(self.publish):
            self.positions_publisher.publish(positions)
            cv2.imshow('Human Tracker', cv_image)
            cv2.waitKey(1)
        else:
            cv2.imshow('Human Tracker', cv_image)
            cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    object_tracker = ObjectTracker()
    rclpy.spin(object_tracker)
    object_tracker.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()