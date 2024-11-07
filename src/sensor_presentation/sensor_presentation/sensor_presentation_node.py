import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from object_tracking_messages.msg import DetectedPersons, PersonDistance
from cv_bridge import CvBridge
import cv2
import logging
from launch.launch_description_sources import PythonLaunchDescriptionSource
import numpy as np

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
            confidence = getattr(person, 'confidence', None)
            if msg.real_world_coordinates and i < len(msg.real_world_coordinates) // 3:
                x_real = msg.real_world_coordinates[i * 3]
                y_real = msg.real_world_coordinates[i * 3 + 1]
                z_real = msg.real_world_coordinates[i * 3 + 2]
            else:
                x_real, y_real, z_real = None, None, None

            # Classify pose based on real-world keypoints
            pose_description = self.classify_pose(person, (x_real, y_real, z_real), x1, y1, x2, y2)

            # Append the pose description to the label
            label_with_pose = f"{person.label} - Pose: {pose_description}"

            self.detected_positions.append({
                'id': person.id,
                'distance': distance,
                'confidence': confidence,
                'real_coords': (x_real, y_real, z_real),  
                'bbox': (x1, y1, x2, y2),
                'label': label_with_pose,
                'body_parts': person.body_parts,
                'keypoints': person.person_key_point
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

                # Draw the bounding box and center point
                cv2.rectangle(self.cv_image, (x1, y1), (x2, y2), (0, 255, 0), 2)
                cv2.circle(self.cv_image, (x_center, y_center), 5, (0, 0, 255), -1)

                # Format additional text for distance and real-world coordinates
                distance_str = f"{detected['distance']:.2f}" if detected['distance'] is not None else "N/A"
                real_coords_str = ""
                try:
                    real_coords_str = f"R:({detected['real_coords'][0]:.2f}, {detected['real_coords'][1]:.2f}, {detected['real_coords'][2]:.2f})"
                except Exception as e:
                    self.get_logger().warning(f'Error formatting real-world coordinates: {e}')

                text = f"{detected['label']}, ID: {detected['id']}, D: {distance_str}m, C: {detected['confidence']:.2f}, {real_coords_str}"
                cv2.putText(self.cv_image, text, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2)

                # Draw keypoints with body part names
                for part, keypoint in zip(detected['body_parts'], detected['keypoints']):
                    kp_x, kp_y, kp_conf = int(keypoint.x), int(keypoint.y), keypoint.confidence
                    cv2.circle(self.cv_image, (kp_x, kp_y), 3, (0, 255, 255), -1)  # Yellow for keypoints
                    cv2.putText(self.cv_image, part, (kp_x, kp_y - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 255), 1)
        except Exception as e:
            self.get_logger().error(f"Visualization error: {e}")

        # Display the image
        cv2.imshow('Person Visualization', self.cv_image)
        cv2.waitKey(1)

    def classify_pose(self, person, real_world_coords, x1, y1, x2, y2):
        left_wrist_index = 9
        right_wrist_index = 10

        # Get the real-world position of the person’s torso (assumed to be the center of the bounding box)
        if real_world_coords is None or len(person.person_key_point) < max(left_wrist_index, right_wrist_index):
            return "unknown"

        torso_x, torso_y, torso_z = real_world_coords

        # Calculate the offsets for left and right wrists relative to the torso
        bbox_width = x2 - x1
        bbox_height = y2 - y1

        if bbox_width == 0 or bbox_height == 0:
            self.get_logger().warning("Bounding box has zero width or height, skipping pose classification.")
            return "unknown"

        left_wrist_offset_x = (person.person_key_point[left_wrist_index].x - x1) / bbox_width
        left_wrist_offset_y = (person.person_key_point[left_wrist_index].y - y1) / bbox_height
        right_wrist_offset_x = (person.person_key_point[right_wrist_index].x - x1) / bbox_width
        right_wrist_offset_y = (person.person_key_point[right_wrist_index].y - y1) / bbox_height

        # Assume wrists are at a similar depth as the torso
        scaling_factor = 0.001  # Adjust this factor as needed
        try:
            left_wrist_real_x = torso_x + (left_wrist_offset_x - 0.5) * bbox_width * scaling_factor
            left_wrist_real_y = torso_y + (left_wrist_offset_y - 0.5) * bbox_height * scaling_factor
            left_wrist_real_z = torso_z

            right_wrist_real_x = torso_x + (right_wrist_offset_x - 0.5) * bbox_width * scaling_factor
            right_wrist_real_y = torso_y + (right_wrist_offset_y - 0.5) * bbox_height * scaling_factor
            right_wrist_real_z = torso_z
        except Exception as e:
            return "normal"
        # Calculate the real-world distance between wrists
        wrist_distance = np.linalg.norm([
            left_wrist_real_x - right_wrist_real_x,
            left_wrist_real_y - right_wrist_real_y,
            left_wrist_real_z - right_wrist_real_z
        ])

        # Determine pose based on wrist distance
        if wrist_distance < 0.3:  # 30 cm in meters
            return "hands folded"
        
        return "normal"

def main(args=None):
    rclpy.init(args=args)
    visualization_node = VisualizationNode()
    rclpy.spin(visualization_node)
    visualization_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
