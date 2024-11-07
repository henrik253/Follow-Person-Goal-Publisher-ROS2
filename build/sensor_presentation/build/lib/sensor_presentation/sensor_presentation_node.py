import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from object_tracking_messages.msg import DetectedPersons, PersonDistance
from cv_bridge import CvBridge
import cv2
import logging
from launch.launch_description_sources import PythonLaunchDescriptionSource
logging.getLogger('ultralytics').setLevel(logging.WARNING)

class VisualizationNode(Node):
    def __init__(self):
        super().__init__('person_visualizer')

        # Create subscriptions
        self.create_subscription(
            Image,
            'tracked_image',
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
        self.get_logger().debug(f'positions_callback msg: {msg}')
        self.detected_positions = []
 
        # Store detected positions along with ID, distance, and confidence
        for i, person in enumerate(msg.detected_persons.persons):
            x1 = person.bbox.x_min
            y1 = person.bbox.y_min
            x2 = person.bbox.x_max
            y2 = person.bbox.y_max

            # Get the distance, real-world coordinates, and confidence score for this person
            distance = msg.distances[i] if i < len(msg.distances) else None
            confidence = getattr(person, 'confidence', None)  # Adjust if named differently
            # Get real-world coordinates (assuming it's a flat list)
            if msg.real_world_coordinates and i < len(msg.real_world_coordinates) // 3:
                x_real = msg.real_world_coordinates[i * 3]   # X coordinate
                y_real = msg.real_world_coordinates[i * 3 + 1]  # Y coordinate
                z_real = msg.real_world_coordinates[i * 3 + 2]  # Z coordinate
            else:
                x_real, y_real, z_real = None, None, None

            self.detected_positions.append({
                'id': person.id,
                'distance': distance,
                'confidence': confidence,
                'real_coords': (x_real, y_real, z_real),  
                'bbox': (x1, y1, x2, y2)  ,
                'label': person.label
            })

        # Visualize detected persons
        if self.cv_image is not None:
            self.visualize()

    def visualize(self):
        try: 
            for detected in self.detected_positions:
                x1, y1, x2, y2 = detected['bbox']
                x_center = int((x1 + x2) / 2)
                y_center = int((y1 + y2) / 2)

                # Circle and Bounding Box
                cv2.rectangle(self.cv_image, (x1, y1), (x2, y2), (0, 255, 0), 2)
                cv2.circle(self.cv_image, (x_center, y_center), 5, (0, 0, 255), -1)  # Red circle

                real_coords_str = ""

                #TODO avoid try catch block if not neccessary
                # Format text 
                distance_str = f"{detected['distance']:.2f}" if detected['distance'] is not None else "N/A"
                try:
                    real_coords_str = f"R:({detected['real_coords'][0]:.2f}, {detected['real_coords'][1]:.2f}, {detected['real_coords'][2]:.2f})" 
                except Exception as e:
                    self.get_logger().warning(f'e')

                text = f"{detected['label']},ID: {detected['id']}, D: {distance_str}m, C: {detected['confidence']:.2f}, {real_coords_str}"
                text_x = x1
                text_y = y1 - 10
                cv2.putText(self.cv_image, text, (text_x, text_y), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2)
        except Exception as e:
            print(e)
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
