import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from object_tracking_messages.msg import DetectedPersons, PersonDistance
from cv_bridge import CvBridge
import cv2
import logging
import numpy as np
from main.utils.person_pose_classifier import classify_pose
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
        self.last_detected_pose = "default"

    def image_callback(self, msg):
        self.cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

    def positions_callback(self, msg):
        self.detected_positions = []

        for i, person in enumerate(msg.detected_persons.persons):
            x1, y1, x2, y2 = person.bbox.x_min, person.bbox.y_min, person.bbox.x_max, person.bbox.y_max
            distance = msg.distances[i] if i < len(msg.distances) else None
            confidence = getattr(person, 'confidence', None)

            # Get main real-world coordinates (center of bbox)
            if msg.real_world_coordinates and i < len(msg.real_world_coordinates) // 3:
                x_real = msg.real_world_coordinates[i * 3]
                y_real = msg.real_world_coordinates[i * 3 + 1]
                z_real = msg.real_world_coordinates[i * 3 + 2]
            else:
                x_real, y_real, z_real = None, None, None

            keypoints_real_coords = []
            keypointToRealWorld = {}
            for j in range(len(person.person_key_point)):
                try:
                    kp_real_x = getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3]
                    kp_real_y = getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3 + 1]
                    kp_real_z = getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3 + 2]
                    keypointToRealWorld[person.body_parts[j]] = (kp_real_x,kp_real_y,kp_real_z)
                except Exception as e:
                    kp_real_x=0
                    kp_real_y=0
                    kp_real_z=0
                    
                keypoints_real_coords.append((kp_real_x, kp_real_y, kp_real_z))
            
            pose_description = classify_pose(keypointToRealWorld)
            self.last_detected_pose = pose_description 
            label_with_pose = f"{self.last_detected_pose}"

            self.detected_positions.append({
                'id': person.id,
                'distance': distance,
                'confidence': confidence,
                'real_coords': (x_real, y_real, z_real),
                'bbox': (x1, y1, x2, y2),
                'label': label_with_pose,
                'body_parts': person.body_parts,
                'keypoints': person.person_key_point,
                'keypoints_real_coords': keypoints_real_coords
            })

        if self.cv_image is not None:
            self.visualize()

    def visualize(self):
        try: 
            for detected in self.detected_positions:
                x1, y1, x2, y2 = detected['bbox']
                x_center = int((x1 + x2) / 2)
                y_center = int((y1 + y2) / 2)

                # Draw the bounding box and center point of detected person 
                cv2.rectangle(self.cv_image, (x1, y1), (x2, y2), (0, 255, 0), 2)
                cv2.circle(self.cv_image, (x_center, y_center), 5, (0, 0, 255), -1)

                distance_str = f"{detected['distance']:.2f}" if detected['distance'] is not None else "N/A"
                real_coords_str = ""
                try:
                    real_coords_str = f"(x: {detected['real_coords'][0]:.2f},y: {detected['real_coords'][1]:.2f},z: {detected['real_coords'][2]:.2f})"
                except Exception as e:
                    self.get_logger().warning(f'Error formatting real-world coordinates: {e}')

                text = f"{detected['label']}, ID: {detected['id']}, {real_coords_str}"
                cv2.putText(self.cv_image, text, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2)

                # Draw keypoints with their real-world coordinates
                for part, keypoint, real_coords in zip(detected['body_parts'], detected['keypoints'], detected['keypoints_real_coords']):
                    kp_x, kp_y, kp_conf = int(keypoint.x), int(keypoint.y), keypoint.confidence
                    cv2.circle(self.cv_image, (kp_x, kp_y), 3, (0, 255, 255), -1)  # Yellow for keypoints
                   # cv2.putText(self.cv_image, part, (kp_x, kp_y - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 255), 1)

                    # Add real-world coordinates text next to each keypoint
                    if real_coords[0] is not None:
                        real_coords_text = f"({real_coords[0]:.2f}, {real_coords[1]:.2f}, {real_coords[2]:.2f})"
                        cv2.putText(self.cv_image, real_coords_text, (kp_x + 10, kp_y + 10), cv2.FONT_HERSHEY_SIMPLEX, 0.4, (0, 255, 0), 1)

        except Exception as e:
            self.get_logger().error(f"Visualization error: {e}")

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
