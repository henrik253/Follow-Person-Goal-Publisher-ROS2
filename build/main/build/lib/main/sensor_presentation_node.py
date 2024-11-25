import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from object_tracking_messages.msg import DetectedPersons, PersonDistance, FollowPersonState
from cv_bridge import CvBridge
import cv2
import logging
import numpy as np
from main.utils.person_pose_classifier import classify_pose
#from main.utils.follow_person_state import State
from enum import Enum 

logging.getLogger('ultralytics').setLevel(logging.WARNING)

class State(Enum): 
    STARTED = 0
    LOOK_FOR_PERSON_TO_FOLLOW = 1
    FOUND_PERSON_TO_FOLLOW = 2
    FOLLOW_PERSON = 3
    STOP_FOLLOW_PERSON = 4

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

        self.create_subscription(
            FollowPersonState,
            'follow_person_state',
            self.follow_person_state_callback,
            10
        )

        # Create CvBridge to convert ROS Image messages to OpenCV images
        self.bridge = CvBridge()
        self.cv_image = None
        self.detected_positions = []
        self.last_detected_pose = "default"
        
        self.current_follow_person_target = State.STARTED
        self.current_follow_person_state = None

    def image_callback(self, msg):
        self.cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        self.visualize_state()

    def follow_person_state_callback(self, msg):
        self.current_follow_person_target = msg.target_person
        self.current_follow_person_state = msg.state


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
                    real_coords_str = f"(x: {detected['real_coords'][0]:.1f},y: {detected['real_coords'][1]:.1f},z: {detected['real_coords'][2]:.1f})"
                except Exception as e:
                    self.get_logger().warning(f'Error formatting real-world coordinates: {e}')

                text_up = f"{detected['label']}"
                #text_down = f"ID: {detected['id']}, {real_coords_str}"
                text_down = f"ID: {detected['id']}"
                #cv2.putText(self.cv_image, text_up, (x1, y1 - 30), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2)
                cv2.putText(self.cv_image, text_down + " : " + text_up, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2)

                for part, keypoint in zip(detected['body_parts'], detected['keypoints']):
                    if(part == 'right_wrist' or part == 'left_wrist' or part =='nose'):
                        kp_x, kp_y, kp_conf = int(keypoint.x), int(keypoint.y), keypoint.confidence
                        cv2.circle(self.cv_image, (kp_x, kp_y), 3, (0, 255, 255), -1)  # Yellow for keypoints

              #  self.visualize_state()

        except Exception as e:
            self.get_logger().error(f"Visualization error: {e}")

        # Display the image
        cv2.imshow('Person Visualization', self.cv_image)
        cv2.waitKey(1)


    def visualize_state(self):
        text_state = f"Follow Person State: {self.current_follow_person_state}"
        text_target_follow_person = f"Target Person: {self.current_follow_person_target.id if self.current_follow_person_state else None}"

        cv2.putText(self.cv_image,text_state , (0, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2)
        cv2.putText(self.cv_image,text_target_follow_person , (0, 100), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2)

def main(args=None):
    rclpy.init(args=args)
    visualization_node = VisualizationNode()
    rclpy.spin(visualization_node)
    visualization_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
