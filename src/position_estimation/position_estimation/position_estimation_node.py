import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import PointCloud2
import sensor_msgs_py.point_cloud2 as pc2
import heapq



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

class PositionEstimationNode(Node):
    
    def __init__(self):
        super().__init__('position_estimation_node')
        
        # Create a subscription to the object detection topic
        self.object_subscription = self.create_subscription(
            Float32MultiArray,
            'detected_object_positions',
            self.object_callback,
            10
        )
        
        # Create a subscription to the sensor data topic
        self.sensor_subscription = self.create_subscription(
            PointCloud2,
            '/zed/zed_node/point_cloud/cloud_registered',
            self.zed_pointcloud_callback,
            10
        )

        self.detected_persons = PersonPool(capacity=MAX_POOL_MEMBERS)
        self.last_detected_person = None
        self.last_point_cloud = []

    def object_callback(self, msg):
        positions = msg.data
        num_persons = len(positions) // 2  # Each person has 2 coordinates
        self.get_logger().info(f'Received positions for {num_persons} detected persons.')
        for i in range(num_persons):
            x = positions[2*i]
            y = positions[2*i + 1]
            self.get_logger().info(f'Person {i+1}: x={x}, y={y}')
      
            if len(self.last_point_cloud) == 0:
                self.get_logger().info('last_point_cloud is 0')
                return  
            
            z_world = self.get_z_coordinate(x, y)

            if z_world is None:
                self.get_logger().info(f'No z found for x={x} and y={y}')
            else:
                self.get_logger().info(f'The z-coordinate for x={x} and y={y} is {z_world}')
            person = Person(person_id=i+1, x=x, y=y, z=z_world)
            self.last_detected_person = person

            #self.detected_persons.add_person(person)
        
    def zed_pointcloud_callback(self, msg):
        # Convert PointCloud2 message to a list of points
        point_cloud = pc2.read_points(msg, field_names=("x", "y", "z"), skip_nans=True)
        # Print the number of points and some sample data
        self.last_point_cloud = list(point_cloud)
        # Uncomment if needed
        #self.get_logger().info(f'Received point cloud with {len(self.last_point_cloud)} points.')
    
    def get_z_coordinate(self, x_image, y_image): 
        print("Ximage: ", x_image)
        print( "yimage:", y_image)
        for point in self.last_point_cloud: 
            x, y, z = point

            if abs(x - x_image) < 100.0 and abs(y - y_image) < 100.0:
                return z
        return None

def main(args=None):
    rclpy.init(args=args)
    node = PositionEstimationNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()