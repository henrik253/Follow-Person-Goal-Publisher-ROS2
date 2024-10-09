import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from object_tracking_messages.msg import DetectedPersons, PersonDistance
from cv_bridge import CvBridge
import cv2

import logging

logging.getLogger('ultralytics').setLevel(logging.WARNING)

class VisualizationNode(Node):
    def __init__(self):
        super().__init__('person_visualizer')

        # Create subscriptions
        self.create_subscription(
            Image,
            '/zed/zed_node/left/image_rect_color',
            self.image_callback,
            10
        )

        self.create_subscription(
            PersonDistance,
            'estimated_person_positions',
            self.positions_callback,
            10
        )

        # Create CvBridge to convert ROS Image messages to OpenCV images
        self.bridge = CvBridge()

        self.cv_image = None
        self.detected_positions = []

    def image_callback(self, msg):
        # Convert ROS Image message to OpenCV image
        self.cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

    def positions_callback(self, msg):
        self.get_logger.info(f'positions_callback msg: {msg}')
        # Clear the detected positions list
        self.detected_positions = []
 
        # Store detected positions along with ID, distance, and confidence
        for i, person in enumerate(msg.detected_persons.persons):
            x_center = int(person.bbox.x_min + (person.bbox.x_max - person.bbox.x_min) / 2)
            y_center = int(person.bbox.y_min + (person.bbox.y_max - person.bbox.y_min) / 2)

            # Get the distance for this person
            distance = msg.distances[i] if i < len(msg.distances) else None

            # Assuming confidence is stored in person.confidence
            confidence = getattr(person, 'confidence', None)  # Adjust if named differently

            self.detected_positions.append({
                'id': person.id,
                'distance': distance,
                'confidence': confidence,
                'position': (x_center, y_center)
            })

        # Visualize detected persons
        if self.cv_image is not None:
            self.visualize()

    def visualize(self):
        # Draw bounding boxes and center points based on detected positions
        for detected in self.detected_positions:
            x_center, y_center = detected['position']
            box_size = 20  # Size of the box
            x1 = x_center - box_size
            y1 = y_center - box_size
            x2 = x_center + box_size
            y2 = y_center + box_size

            # Draw bounding box and center point
            cv2.rectangle(self.cv_image, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.circle(self.cv_image, (x_center, y_center), 5, (0, 0, 255), -1)  # Red circle at center

            # Add text for ID, distance, and confidence
            text = f"ID: {detected['id']}, D: {detected['distance']}m, C: {detected['confidence']}"
            cv2.putText(self.cv_image, text, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)

        # Display the image
        cv2.imshow('Person Visualization', self.cv_image)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    visualization_node = VisualizationNode()
    rclpy.spin(visualization_node)
    visualization_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
