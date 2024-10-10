import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import PointCloud2, Image, CameraInfo
import sensor_msgs_py.point_cloud2 as pc2
import heapq
from object_tracking_messages.msg import DetectedPersons, PersonDistance
import numpy as np
from cv_bridge import CvBridge
import logging

logging.getLogger('ultralytics').setLevel(logging.WARNING)

class PositionEstimationNode(Node):
    
    def __init__(self):
        super().__init__('position_estimation_node')
          
        self.zed_node_name = '/zed/zed_node'  # Adjust as needed
        
        # Create a subscription to the object detection topic
        self.object_subscription = self.create_subscription(
            DetectedPersons,
            'detected_persons',
            self.detections_callback,
            10
        )

        # QoS profile for depth image subscription
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

        # Subscribe to camera_info to get intrinsic parameters
        self.camera_info_subscription = self.create_subscription(
            CameraInfo,
            '/zed/zed_node/rgb/camera_info',  # Adjust this topic as necessary
            self.camera_info_callback,
            10
        )

        # Create publisher for detected object positions
        self.positions_publisher = self.create_publisher(
            PersonDistance,
            'estimated_person_positions',
            10
        )


        self.bridge = CvBridge()
        self.width_depth = 0
        self.depth_image = None
        self.depth = None
        self.distance_formatted = ""
        
        # Intrinsic parameters of ZED camera
        self.focal_length_x = None
        self.focal_length_y = None
        self.principal_point_x = None
        self.principal_point_y = None
        
        self.proccess_camera_info = True
  

    def camera_info_callback(self, msg):
        # intrinsic paramets dont change so only one call is needed 
        # subscription.unregister does not exist for now! 
        if self.proccess_camera_info:
            # Get intrinsic parameters from CameraInfo
            self.focal_length_x = msg.k[0]
            self.focal_length_y = msg.k[4]
            self.principal_point_x = msg.k[2]
            self.principal_point_y = msg.k[5]

            self.get_logger().info(f'Focal Length X: {self.focal_length_x}')
            self.get_logger().info(f'Focal Length Y: {self.focal_length_y}')
            self.get_logger().info(f'Principal Point X: {self.principal_point_x}')
            self.get_logger().info(f'Principal Point Y: {self.principal_point_y}')

            self.proccess_camera_info = False
     
        
    
    def detections_callback(self, msg):
        persons = msg.persons
        
        personDistanceMessage = PersonDistance() 
        personDistanceMessage.detected_persons.persons = persons 
        distances = []
        real_world_coordinates = []  # List to hold real-world coordinates

        for person in persons: 
            boundingBox = person.bbox
            id = person.id
            x1 = boundingBox.x_min
            x2 = boundingBox.x_max
            y1 = boundingBox.y_min
            y2 = boundingBox.y_max

            x_center = (x1 + x2) // 2
            y_center = (y1 + y2) // 2
            
            distance = None
            if self.depth is not None:
                # Ensure x_center and y_center are within bounds
                if 0 <= x_center < self.width_depth and 0 <= y_center < self.depth.shape[0]:
                    distance = round(self.depth[y_center, x_center], 2)
                    distances.append(float(distance))
                    
                    # Calculate real-world coordinates
                    if distance > 0:  # Ensure distance is valid
                        # Convert pixel coordinates to normalized coordinates
                        x_normalized = (x_center - self.principal_point_x) / self.focal_length_x
                        y_normalized = (y_center - self.principal_point_y) / self.focal_length_y

                        # Scale by depth to get real-world coordinates
                        x_real = distance * x_normalized
                        y_real = distance * y_normalized
                        z_real = distance  # Depth value

                        real_world_coordinates.append(float(x_real))
                        real_world_coordinates.append(float(y_real))
                        real_world_coordinates.append(float(z_real))
            
            self.get_logger().info(f'id: {id} and distance: {distance}m')                
        
        personDistanceMessage.distances = distances
        personDistanceMessage.real_world_coordinates = real_world_coordinates  

        self.positions_publisher.publish(personDistanceMessage)

        self.get_logger().info(f'distances: {distances}')
        self.get_logger().info(f'real_world_coordinates: {real_world_coordinates}')
        self.get_logger().info(f"personDistanceMessage: {personDistanceMessage}")   


    def depth_callback(self, msg):
        # Convert ROS Image message to OpenCV image
        depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='32FC1')
        width = msg.width
        height = msg.height

        # Convert depth data to numpy array
        depthmap = np.frombuffer(msg.data, dtype=np.float32).reshape((height, width))
        
        self.width_depth = width
        self.depth = depthmap

def main(args=None):
    rclpy.init(args=args)
    node = PositionEstimationNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
