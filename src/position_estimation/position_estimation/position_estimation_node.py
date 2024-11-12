import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from object_tracking_messages.msg import DetectedPersons, PersonDistance
import numpy as np
from cv_bridge import CvBridge
import logging

logging.getLogger('ultralytics').setLevel(logging.WARNING)

class PositionEstimationNode(Node):
    
    def __init__(self):
        super().__init__('position_estimation_node')
        
        # Camera node and subscriptions
        self.zed_node_name = '/zed/zed_node'
        
        self.create_subscription(
            DetectedPersons,
            'detected_persons',
            self.detections_callback,
            10
        )

        qos_profile = rclpy.qos.QoSProfile(
            depth=10,
            reliability=rclpy.qos.ReliabilityPolicy.BEST_EFFORT,
            durability=rclpy.qos.DurabilityPolicy.VOLATILE
        )

        self.depth_subscription = self.create_subscription(
            Image,
            '/zed/zed_node/depth/depth_registered',
            self.depth_callback,
            qos_profile
        )

        self.camera_info_subscription = self.create_subscription(
            CameraInfo,
            '/zed/zed_node/rgb/camera_info',
            self.camera_info_callback,
            10
        )

        self.positions_publisher = self.create_publisher(
            PersonDistance,
            'estimated_person_positions',
            10
        )
        
        self.bridge = CvBridge()
        self.depth = None
        
        # Camera intrinsic parameters
        self.focal_length_x = None
        self.focal_length_y = None
        self.principal_point_x = None
        self.principal_point_y = None
        self.proccess_camera_info = True

    def camera_info_callback(self, msg):
        if self.proccess_camera_info:
            self.focal_length_x = msg.k[0]
            self.focal_length_y = msg.k[4]
            self.principal_point_x = msg.k[2]
            self.principal_point_y = msg.k[5]
            self.proccess_camera_info = False

    def detections_callback(self, msg):
        persons = msg.persons
        personDistanceMessage = PersonDistance() 
        personDistanceMessage.detected_persons.persons = persons 
        
        distances = []
        real_world_coordinates = []  
        body_part_coords = {
            "nose": [],
            "left_eye": [],
            "right_eye": [],
            "left_ear": [],
            "right_ear": [],
            "left_shoulder": [],
            "right_shoulder": [],
            "left_elbow": [],
            "right_elbow": [],
            "left_wrist": [],
            "right_wrist": [],
            "left_hip": [],
            "right_hip": [],
            "left_knee": [],
            "right_knee": [],
            "left_ankle": [],
            "right_ankle": []
        }

        for person in persons: 
            boundingBox = person.bbox
            x1, x2, y1, y2 = boundingBox.x_min, boundingBox.x_max, boundingBox.y_min, boundingBox.y_max
            x_center, y_center = (x1 + x2) // 2, (y1 + y2) // 2

            distance = None
            if self.depth is not None and 0 <= x_center < self.depth.shape[1] and 0 <= y_center < self.depth.shape[0]:
                distance = round(self.depth[y_center, x_center], 2)
                distances.append(float(distance))

                if distance > 0:
                    x_normalized = (x_center - self.principal_point_x) / self.focal_length_x
                    y_normalized = (y_center - self.principal_point_y) / self.focal_length_y
                    x_real, y_real, z_real = distance * x_normalized, distance * y_normalized, distance

                    real_world_coordinates.extend([float(x_real),float( y_real),float(z_real)])

                    # Calculate real-world coordinates for each body part keypoint
                    for body_part_name, keypoint in zip(person.body_parts, person.person_key_point):
                        kp_x, kp_y = int(keypoint.x), int(keypoint.y)
                        if 0 <= kp_x < self.depth.shape[1] and 0 <= kp_y < self.depth.shape[0]:
                            kp_distance = self.depth[kp_y, kp_x]
                            if kp_distance > 0:
                                kp_x_normalized = (kp_x - self.principal_point_x) / self.focal_length_x
                                kp_y_normalized = (kp_y - self.principal_point_y) / self.focal_length_y
                                kp_x_real = kp_distance * kp_x_normalized
                                kp_y_real = kp_distance * kp_y_normalized
                                kp_z_real = kp_distance
                                
                                body_part_coords[body_part_name].extend([float(kp_x_real), float(kp_y_real), float(kp_z_real)])

        personDistanceMessage.distances = distances
        personDistanceMessage.real_world_coordinates = real_world_coordinates
        personDistanceMessage.nose_real_world_coordinates = body_part_coords["nose"]
        personDistanceMessage.left_eye_real_world_coordinates = body_part_coords["left_eye"]
        personDistanceMessage.right_eye_real_world_coordinates = body_part_coords["right_eye"]
        personDistanceMessage.left_ear_real_world_coordinates = body_part_coords["left_ear"]
        personDistanceMessage.right_ear_real_world_coordinates = body_part_coords["right_ear"]
        personDistanceMessage.left_shoulder_real_world_coordinates = body_part_coords["left_shoulder"]
        personDistanceMessage.right_shoulder_real_world_coordinates = body_part_coords["right_shoulder"]
        personDistanceMessage.left_elbow_real_world_coordinates = body_part_coords["left_elbow"]
        personDistanceMessage.right_elbow_real_world_coordinates = body_part_coords["right_elbow"]
        personDistanceMessage.left_wrist_real_world_coordinates = body_part_coords["left_wrist"]
        personDistanceMessage.right_wrist_real_world_coordinates = body_part_coords["right_wrist"]
        personDistanceMessage.left_hip_real_world_coordinates = body_part_coords["left_hip"]
        personDistanceMessage.right_hip_real_world_coordinates = body_part_coords["right_hip"]
        personDistanceMessage.left_knee_real_world_coordinates = body_part_coords["left_knee"]
        personDistanceMessage.right_knee_real_world_coordinates = body_part_coords["right_knee"]
        personDistanceMessage.left_ankle_real_world_coordinates = body_part_coords["left_ankle"]
        personDistanceMessage.right_ankle_real_world_coordinates = body_part_coords["right_ankle"]

        self.positions_publisher.publish(personDistanceMessage)

    def depth_callback(self, msg):
        self.depth = np.frombuffer(msg.data, dtype=np.float32).reshape((msg.height, msg.width))

def main(args=None):
    rclpy.init(args=args)
    node = PositionEstimationNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
