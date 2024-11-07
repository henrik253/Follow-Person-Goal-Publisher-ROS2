import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, TransformStamped
from object_tracking_messages.msg import DetectedPersons  # Replace with your actual package name
import tf2_ros
import tf2_geometry_msgs  # For transforming geometry_msgs types
from tf2_ros import TransformBroadcaster

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
        self.timer = self.create_timer(1.0, self.publish_goal)  # Publish every second

        # TF2 setup
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        self.tf_broadcaster = TransformBroadcaster(self)

    # STATES: Look for Person 
    # If State.LookForPerson && found_person.size>0:
    #   SAVE THE ID of nearest person
    #   State = State.FollowPerson 
    # If State.FollowPerson: 
    #   look for id in person_position_callback
    #   If(Id found in person_position_callback):
    #       last_spot_person_found_transformed =  translated_position
    #   else if(ID not found in person_position_callback):
    #       State.LookForPerson 

    def publish_goal(self):
        goal_msg = PoseStamped()
        goal_msg.header.stamp = self.get_clock().now().to_msg()
        goal_msg.header.frame_id = 'map'  # Use the appropriate frame
        goal_msg.pose.position.x = 0.0  # Set your desired x position
        goal_msg.pose.position.y = 0.0  # Set your desired y position
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

                # # Create a PoseStamped for transformation
                # person_pose = PoseStamped()
                # person_pose.header.frame_id = "camera_frame"  # Replace with your camera frame ID
                # person_pose.header.stamp = self.get_clock().now().to_msg()
                # person_pose.pose.position.x = x
                # person_pose.pose.position.y = y
                # person_pose.pose.position.z = z
                # person_pose.pose.orientation.w = 1.0  # No rotation

                # Transform to the robot base frame
                # try:
                #     transform = self.tf_buffer.lookup_transform('base_frame',  # Replace with your base frame ID
                #                                                 person_pose.header.frame_id,
                #                                                 rclpy.time.Time())
                #     transformed_person_pose = tf2_geometry_msgs.do_transform_pose(person_pose, transform)
                #     self.get_logger().info(
                #         f'Detected person {i}: Distance: {distance}, Transformed Coordinates: ({transformed_person_pose.pose.position.x}, {transformed_person_pose.pose.position.y}, {transformed_person_pose.pose.position.z})'
                #     )
                # except Exception as e:
                #     self.get_logger().warn(f'Transform error for person {i}: {e}')
        

def main(args=None):
    rclpy.init(args=args)
    goal_publisher_node = GoalPublisher()
    rclpy.spin(goal_publisher_node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
