import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import PointCloud2
from sensor_msgs.msg import Image
import sensor_msgs_py.point_cloud2 as pc2
import heapq
from object_tracking_messages.msg import DetectedPersons, DetectedPerson, BoundingBox, PersonDistance
import numpy as np
from cv_bridge import CvBridge
import logging


logging.getLogger('ultralytics').setLevel(logging.WARNING)

'''
# TODO try to use LiDAR insteaf of ZED depth image! 
class Person:
    def __init__(self, person_id, x, y, z=float('nan')):
        self.person_id = person_id
        self.position = {'x': x, 'y': y, 'z': z}

class PersonPool:
    def __init__(self, capacity):
        self.capacity = capacity
        self.pool = {}
        self.max_heap = []
    
    def add_person(self, person):
        if person.person_id in self.pool:
            self._remove_person(person.person_id)
        
        if len(self.pool) >= self.capacity:
            self._remove_farthest_person()

        self.pool[person.person_id] = person
        heapq.heappush(self.max_heap, (-person.position['z'], person.person_id))
    
    def _remove_person(self, person_id):
        if person_id in self.pool:
            del self.pool[person_id]
            # Remove outdated entries in max heap
            self.max_heap = [entry for entry in self.max_heap if entry[1] != person_id]
            heapq.heapify(self.max_heap) # Reheapify to maintain heap priority
    
    def _remove_farthest_person(self):
        while self.max_heap:
            _, person_id = heapq.heappop(self.max_heap)
            if person_id in self.pool:
                self._remove_person(person_id)
                break
    
    def get_closest_person(self):
        if not self.pool:
            return None
        return min(self.pool.values(), key=lambda p: p.position['z'])
    
    def __repr__(self):
        return f"PersonPool({list(self.pool.values())})"

MAX_POOL_MEMBERS = 5
'''
class PositionEstimationNode(Node):
    
    def __init__(self):
        super().__init__('position_estimation_node')
        
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

        # Create publisher for detected object positions
        self.positions_publisher = self.create_publisher(
            PersonDistance,
            'estimated_person_positions',
            10
        )

       # self.detected_person_pool = PersonPool(capacity=MAX_POOL_MEMBERS)
        self.bridge = CvBridge()
        self.width_depth = 0
        self.depth_image = None
        self.depth = None
        self.distance_formatted = ""

    def detections_callback(self, msg):
        persons = msg.persons
        
        personDistanceMessage = PersonDistance() 
        personDistanceMessage.detected_persons.persons = persons 
        distances = []
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
                    distance = round(self.depth[y_center, x_center],2)
                    distances.append(float(distance))
            
            self.get_logger().info(f'id: {id} and distance: {distance}m')                
        
        
        personDistanceMessage.distances = distances
        self.positions_publisher.publish(personDistanceMessage)

        self.get_logger().info(f'distances: {distances}')
        self.get_logger().info(f"personDistanceMessage: {personDistanceMessage}")   

    def depth_callback(self, msg):
    # Convert ROS Image message to OpenCV image
        width = msg.width
        height = msg.height
        self.depthmap = msg.data; 
        
        #  int centerIdx = u + msg->width * v;
        u = int(width /2)
        v = int(height/2)
        centerIndex = u + width * v
        self.last_center_index = centerIndex

        #print(f'depth value at:::: {self.depthmap[centerIndex]}')

    
          # Convert ROS Image message to OpenCV image
        depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='32FC1')
        width = msg.width
        height = msg.height

        # Convert depth data to numpy array
        depthmap = np.frombuffer(msg.data, dtype=np.float32).reshape((height, width))
        
        self.width_depth = width
        self.depth = depthmap

        # Calculate center pixel index and print depth value
        u = width // 2
        v = height // 2
        if 0 <= u < width and 0 <= v < height:
            center_distance = depthmap[v, u]
            #self.get_logger().info(f'Depth value at center: {center_distance}')

def main(args=None):
    rclpy.init(args=args)
    node = PositionEstimationNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()