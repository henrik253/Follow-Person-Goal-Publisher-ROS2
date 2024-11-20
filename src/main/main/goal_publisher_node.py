import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
from object_tracking_messages.msg import DetectedPersons
from tf2_ros import TransformBroadcaster, TransformListener, Buffer, TransformException
import tf2_geometry_msgs
from enum import Enum 
import main.utils.person_pose as Pose



class State(Enum): 
    STARTED = 0
    LOOK_FOR_PERSON_TO_FOLLOW = 1
    FOUND_PERSON_TO_FOLLOW = 2
    FOLLOW_PERSON = 3
    STOP_FOLLOW_PERSON = 4

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
        self.current_state = State.STARTED
        self.target_person_map_position = None
        self.target_person = None

        self.current_robot_position = None

    def odom_callback(self, msg):
        # Update robot's current position
        self.current_robot_position = msg.pose.pose.position
        self.get_logger().info(f'Current position - x: {self.current_robot_position.x}, y: {self.current_robot_position.y}, z: {self.current_robot_position.z}')
        

    def publish_goal(self):
        # Check the state of the GoalStateMachine before publishing
        if False: # For debugging false
            goal_msg = PoseStamped()
            goal_msg.header.stamp = self.get_clock().now().to_msg()
            goal_msg.header.frame_id = 'map'

            goal_msg.pose.position.x = 0.0
            goal_msg.pose.position.y = 0.0
            goal_msg.pose.position.z = 0.0

            goal_msg.pose.orientation.x = 0.0
            goal_msg.pose.orientation.y = 0.0
            goal_msg.pose.orientation.z = 0.0
            goal_msg.pose.orientation.w = 1.0

           
            self.get_logger().info(f'Publishing goal: x: {goal_msg.pose.position.x}, y: {goal_msg.pose.position.y}')
            #self.goal_publisher.publish(goal_msg)

    def person_positions_callback(self, msg):
          # Process (detected persons, keypoints) data and update state machine

        print(self.current_state)
        person_real_world, person_keypoints = self.proccess_position_estimation_message(msg)

        #print(person_real_world)
        #print(person_keypoints)

        if self.current_state == State.STARTED:
            self.started()
        elif self.current_state == State.LOOK_FOR_PERSON_TO_FOLLOW:
            self.look_for_person_to_follow(person_real_world, person_keypoints)
        elif self.current_state == State.FOLLOW_PERSON:
            self.follow_person(person_real_world)
        elif self.current_state == State.STOP_FOLLOW_PERSON:
            self.stop_follow_person()
          
    
    def started(self):
        self.current_state = State.LOOK_FOR_PERSON_TO_FOLLOW

    def look_for_person_to_follow(self,person_real_world, person_keypoints):
        persons_with_both_hands_up = []
        for person_id, keypoints in person_keypoints.items():
            pose = Pose.classify_pose(keypoints)
            if pose == Pose.BOTH_HANDS_UP:
                distance = sum(coord ** 2 for coord in person_real_world[person_id]) ** 0.5
                persons_with_both_hands_up.append((distance, person_id))

        if persons_with_both_hands_up:
            closest_person = min(persons_with_both_hands_up, key=lambda x: x[0])
            self.target_person = closest_person[1]
            self.get_logger().info(f'Target person ID: {self.target_person}')
            self.current_state = State.FOUND_PERSON_TO_FOLLOW
    
    def found_person_to_follow(self):
        self.current_state = State.FOLLOW_PERSON

    def follow_person(self,person_real_world):
        if self.target_person in person_real_world:
            try:
                self.target_person_map_position = self.transform_to_map(person_real_world[self.target_person])
            except TransformException as e:
                self.get_logger().error(f'Transformation error: {e}')
        else:
            self.get_logger().warn('Target person lost, transitioning to STOP_FOLLOW_PERSON')
            self.current_state = State.STOP_FOLLOW_PERSON
    
    def stop_follow_person(self): 
        self.get_logger().info('State transitioned to LOOK_FOR_PERSON_TO_FOLLOW')
        self.current_state = State.LOOK_FOR_PERSON_TO_FOLLOW

    def proccess_position_estimation_message(msg):
        person_to_key_point_to_real_world = {}
        person_to_real_world = {}
        for i, person in enumerate(msg.detected_persons.persons):
            # map bodypart to real_world coordinate!
            keypointToRealWorld = {
                person.body_parts[j]: (
                    getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3],
                    getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3 + 1],
                    getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3 + 2]
                ) for j in range(len(person.person_key_point))
            }

            xyz = person.real_world_coordinates
            person_to_key_point_to_real_world[person] = keypointToRealWorld
            person_to_real_world[person] = (xyz[i * 3], xyz[i * 3 + 1], xyz[i * 3 + 1])

        return [person_to_real_world, person_to_key_point_to_real_world]

    def transform_to_map(self, camera_coords):
        camera_pose = PoseStamped()
        camera_pose.header.frame_id = 'camera_frame'
        camera_pose.header.stamp = self.get_clock().now().to_msg()
        camera_pose.pose.position.x = camera_coords[0]
        camera_pose.pose.position.y = camera_coords[1]
        camera_pose.pose.position.z = camera_coords[2]
        camera_pose.pose.orientation.w = 1.0

        try:
            # Perform the transformation from the left camera frame to the map frame
            transform = self.tf_buffer.lookup_transform('map', 'zed_left_camera_frame', rclpy.time.Time())
            map_pose = tf2_geometry_msgs.do_transform_pose(camera_pose, transform)
            return (
                map_pose.pose.position.x,
                map_pose.pose.position.y,
                map_pose.pose.position.z
            )
        except TransformException as e:
            self.get_logger().error(f'Transformation error: {e}')
            raise e
        
def main(args=None):
    rclpy.init(args=args)
    goal_publisher_node = GoalPublisher()
    rclpy.spin(goal_publisher_node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
