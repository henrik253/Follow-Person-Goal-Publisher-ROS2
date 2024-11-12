import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, TransformStamped
from object_tracking_messages.msg import DetectedPersons  # Replace with your actual package name
import tf2_ros
import tf2_geometry_msgs  # For transforming geometry_msgs types
from tf2_ros import TransformBroadcaster



'''pose:
  pose:
    position:
      x: -0.2860250767164436
      y: -0.5418394793158074
      z: 0.008734361356016903
    orientation:
      x: 4.7614411998054286e-05
      y: -0.0007509439160244883
      z: -0.08371571238624209
      w: -0.9964893944823332
  covariance:
  - 1.0e-05
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 1.0e-05
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 1000000000000.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 1000000000000.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 1000000000000.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.001
twist:
  twist:
    linear:
      x: -0.0003126695377348355
      y: -0.00018245790501396055
      z: 0.0
    angular:
      x: 0.0
      y: 0.0
      z: 0.0034838754620495935
  covariance:
  - 1.0e-05
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 1.0e-05
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 1000000000000.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 1000000000000.0
  - 0.0
  - 0.0
'''
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
from tf2_ros import TransformBroadcaster
import tf2_ros

class GoalPublisher(Node):

    def __init__(self):
        super().__init__('goal_publisher')
        self.goal_publisher = self.create_publisher(PoseStamped, '/goal_pose', 10)
        self.person_subscriber = self.create_subscription(
            DetectedPersons,
            'estimated_person_positions',
            self.person_positions_callback,
            10
        )
        self.odom_subscriber = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10
        )
        self.timer = self.create_timer(1.0, self.publish_goal)  # Publish every second

        # TF2 setup
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        self.tf_broadcaster = TransformBroadcaster(self)

        # Initialize variables to store the robot's current position
        self.current_position = None

    

    def odom_callback(self, msg):
        # Extract the robot's current position from the odometry message
        self.current_position = msg.pose.pose.position
        self.get_logger().info(f'Current position - x: {self.current_position.x}, y: {self.current_position.y}, z: {self.current_position.z}')

    def publish_goal(self):
        goal_msg = PoseStamped()
        goal_msg.header.stamp = self.get_clock().now().to_msg()
        goal_msg.header.frame_id = 'map'  # Use the appropriate frame

        # Set your desired goal position
        goal_msg.pose.position.x = 0.0
        goal_msg.pose.position.y = 0.0
        goal_msg.pose.position.z = 0.0  # Usually 0 for 2D navigation

        # Set orientation (facing along the x-axis)
        goal_msg.pose.orientation.x = 0.0
        goal_msg.pose.orientation.y = 0.0
        goal_msg.pose.orientation.z = 0.0  # No rotation
        goal_msg.pose.orientation.w = 1.0  # No rotation

        self.get_logger().info(f'Publishing goal: x: {goal_msg.pose.position.x}, y: {goal_msg.pose.position.y}')
        self.goal_publisher.publish(goal_msg)

    def person_positions_callback(self, msg):
        # Process the received detected persons data
        distances = msg.distances
        real_world_coordinates = msg.real_world_coordinates

        # Transform each person's coordinates from the camera frame to the robot's base frame
        for i, distance in enumerate(distances):
            if len(real_world_coordinates) >= (i + 1) * 3:  # Check if coordinates exist
                x = real_world_coordinates[i * 3]
                y = real_world_coordinates[i * 3 + 1]
                z = real_world_coordinates[i * 3 + 2]

                # Create a PoseStamped for transformation
                person_pose = PoseStamped()
                person_pose.header.frame_id = "camera_frame"  # Replace with your camera frame ID
                person_pose.header.stamp = self.get_clock().now().to_msg()
                person_pose.pose.position.x = x
                person_pose.pose.position.y = y
                person_pose.pose.position.z = z
                person_pose.pose.orientation.w = 1.0  # No rotation

                # Transform to the robot base frame
                try:
                    transform = self.tf_buffer.lookup_transform('base_frame',  # Replace with your base frame ID
                                                                person_pose.header.frame_id,
                                                                rclpy.time.Time())
                    transformed_person_pose = tf2_geometry_msgs.do_transform_pose(person_pose, transform)
                    self.get_logger().info(
                        f'Detected person {i}: Distance: {distance}, Transformed Coordinates: ({transformed_person_pose.pose.position.x}, {transformed_person_pose.pose.position.y}, {transformed_person_pose.pose.position.z})'
                    )
                except Exception as e:
                    self.get_logger().warn(f'Transform error for person {i}: {e}')

def main(args=None):
    rclpy.init(args=args)
    goal_publisher_node = GoalPublisher()
    rclpy.spin(goal_publisher_node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
