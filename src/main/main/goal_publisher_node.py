import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
from object_tracking_messages.msg import DetectedPersons
from tf2_ros import TransformBroadcaster, TransformListener, Buffer
import tf2_geometry_msgs
from main.utils.goal_state_machine import GoalStateMachine
from main.utils.goal_state import GoalState
import main.utils.config as Config
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
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.tf_broadcaster = TransformBroadcaster(self)

        # GoalStateMachine setup
        self.goal_state_machine = GoalStateMachine()
        self.current_position = None

    def odom_callback(self, msg):
        # Update robot's current position
        self.current_position = msg.pose.pose.position
        self.get_logger().info(f'Current position - x: {self.current_position.x}, y: {self.current_position.y}, z: {self.current_position.z}')

    def publish_goal(self):
        # Check the state of the GoalStateMachine before publishing
        if self.goal_state_machine.get_state() == GoalState.FOLLOW_PERSON:
            goal_msg = PoseStamped()
            goal_msg.header.stamp = self.get_clock().now().to_msg()
            goal_msg.header.frame_id = 'map'

            # Set your desired goal position
            goal_msg.pose.position.x = 0.0
            goal_msg.pose.position.y = 0.0
            goal_msg.pose.position.z = 0.0

            # Set orientation
            goal_msg.pose.orientation.x = 0.0
            goal_msg.pose.orientation.y = 0.0
            goal_msg.pose.orientation.z = 0.0
            goal_msg.pose.orientation.w = 1.0

            self.get_logger().info(f'Publishing goal: x: {goal_msg.pose.position.x}, y: {goal_msg.pose.position.y}')
            self.goal_publisher.publish(goal_msg)

    def person_positions_callback(self, msg):
        # Process detected persons data and update state machine
        for i, person in enumerate(msg.detected_persons.persons):
            keypointToRealWorld = {
                person.body_parts[j]: (
                    getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3],
                    getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3 + 1],
                    getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3 + 2]
                ) for j in range(len(person.person_key_point))
            }
            self.goal_state_machine.update_state_based_on_pose(keypointToRealWorld)

def main(args=None):
    rclpy.init(args=args)
    goal_publisher_node = GoalPublisher()
    rclpy.spin(goal_publisher_node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
