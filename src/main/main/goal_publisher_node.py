import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
from object_tracking_messages.msg import PersonDistance
from tf2_ros import TransformBroadcaster, TransformListener, Buffer
import tf2_geometry_msgs
from enum import Enum 
import main.utils.person_pose as Pose
from main.utils.person_pose_classifier import classify_pose
from visualization_msgs.msg import Marker

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
        
        # Debugging!
        self.marker_publisher = self.create_publisher(Marker, 'visualization_marker', 10)

        self.create_subscription(
            PersonDistance,
            'estimated_person_positions',
            self.person_positions_callback,
            10
        )
      
        self.create_subscription(
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
        self.target_person = None

        self.target_person_camera_position = None
        self.target_person_map_position = None
        self.current_robot_position = None # ?

        self.last_target_position = False

        # distance
        self.distance = 1.0 # 1m min distance to person 

    def change_state(self, new_state):
        """Helper function to log state changes."""
        self.get_logger().info(f'State changed from {self.current_state.name} to {new_state.name}')
        self.current_state = new_state

    def odom_callback(self, msg):
        # Update robot's current position
        self.current_robot_position = msg.pose.pose.position
      #  self.get_logger().info(f'Current position - x: {self.current_robot_position.x}, y: {self.current_robot_position.y}, z: {self.current_robot_position.z}')
    # DEBUGGING

    def publish_marker(self):
        marker = Marker()
        marker.header.frame_id = "map"  # Replace with your desired frame
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "example_marker"
        marker.id = 0
        marker.type = Marker.SPHERE  
        marker.action = Marker.ADD

        if(not self.target_person_map_position):
            return 
        
        marker.pose.position.x = self.target_person_map_position.position.x
        marker.pose.position.y = self.target_person_map_position.position.y
        marker.pose.position.z = self.target_person_map_position.position.z

        print(f"Marker Position: x={marker.pose.position.x}, y={marker.pose.position.y}, z={marker.pose.position.z}")
        print(f"Target Person Map Position: x={self.target_person_map_position.position.x}, y={self.target_person_map_position.position.y}, z={self.target_person_map_position.position.z}")
    
        # Orientation (no rotation here)
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = 0.0
        marker.pose.orientation.w = 1.0

        # Set the scale of the marker (1x1x1 means 1 meter in each dimension)
        marker.scale.x = 0.1
        marker.scale.y = 0.1
        marker.scale.z = 0.5

        # Set the color (RGBA)
        marker.color.r = 1.0  # Red
        marker.color.g = 0.0  # Green
        marker.color.b = 0.0  # Blue
        marker.color.a = 1.0  # Alpha (transparency)

        # Publish the marker
        self.marker_publisher.publish(marker)

    def publish_goal(self):
        # Check the state of the GoalStateMachine before publishing
        print(f'map_pos: {self.target_person_map_position}')
        print(f'camera_pos {self.target_person_camera_position}')
        

        if self.current_state == State.FOLLOW_PERSON:
            if self.last_target_position:
                    goal_msg = PoseStamped()
                    goal_msg.header.stamp = self.get_clock().now().to_msg()
                    goal_msg.header.frame_id = 'map'
                    goal_msg.pose = self.target_person_map_position
                    self.publish_marker()
                    if False:
                        self.goal_publisher.publish(goal_msg)

    def person_positions_callback(self, msg):
        # Process (detected persons, keypoints) data and update state machine
        person_real_world, person_keypoints = self.proccess_position_estimation_message(msg)

        if self.current_state == State.STARTED:
            self.started_state()
        elif self.current_state == State.LOOK_FOR_PERSON_TO_FOLLOW:
            self.look_for_person_to_follow_state(person_real_world, person_keypoints)
        elif self.current_state == State.FOUND_PERSON_TO_FOLLOW:
            self.found_person_to_follow_state()
        elif self.current_state == State.FOLLOW_PERSON:
            self.follow_person_state(person_real_world, person_keypoints)
        elif self.current_state == State.STOP_FOLLOW_PERSON:
            self.stop_follow_person_state()
    
    def started_state(self):
        self.change_state(State.LOOK_FOR_PERSON_TO_FOLLOW)

    def look_for_person_to_follow_state(self, person_real_world, person_keypoints):
        persons_with_right_hand_up = []
        for person_id, keypoints in person_keypoints.items():
            pose = classify_pose(keypoints)
            if pose == Pose.RIGHT_HAND_UP:
                # Correctly reference the person's real-world position using their ID
                distance = sum(coord ** 2 for coord in person_real_world[person_id]) ** 0.5
                persons_with_right_hand_up.append((distance, person_id))

        if persons_with_right_hand_up:
            closest_person = min(persons_with_right_hand_up, key=lambda x: x[0])
            self.target_person = closest_person[1]
            self.get_logger().info(f'Target person ID: {self.target_person}')
            self.change_state(State.FOUND_PERSON_TO_FOLLOW)

    def found_person_to_follow_state(self):
        self.get_logger().info(f'Person found with ID: {self.target_person}')  # Log the ID of the person found
        self.change_state(State.FOLLOW_PERSON)

    def follow_person_state(self, person_real_world, person_keypoints):
        if self.target_person in person_real_world:
            if classify_pose(person_keypoints[self.target_person]) == Pose.LEFT_HAND_UP:
                self.change_state(State.STOP_FOLLOW_PERSON)
            try:
                person_rwc = person_real_world[self.target_person]
                if(person_rwc[0] and person_rwc[1] and person_rwc[2]): 
                    # x -> x, z -> y , y -> z 
                    depth_value = max(person_rwc[2] - self.distance, 0)
                    flipped_person_rwc = (-person_rwc[0],depth_value,-person_rwc[1]) # x/person_rwc[0] (left or right from camera: positive means more right) : z/person_rwc[2] the distance from the person (the higher the more away)
                    self.target_person_map_position = self.transform_to_map(flipped_person_rwc)
                    self.target_person_camera_position = flipped_person_rwc
                    self.last_target_position = True 
                else:
                    self.get_logger().warn('Unable to calculate persons position')
                    print(person_rwc)
                    self.last_target_position = False
                    return 
            except Exception as e:
                print(e)
                self.last_target_position = False
        else:
            self.get_logger().warn('Target person lost, transitioning to STOP_FOLLOW_PERSON')
            self.change_state(State.STOP_FOLLOW_PERSON)

    def stop_follow_person_state(self): # maybe wait a second 
        self.change_state(State.LOOK_FOR_PERSON_TO_FOLLOW)

    def proccess_position_estimation_message(self, msg):
        person_to_key_point_to_real_world = {}
        person_to_real_world = {}
        for i, person in enumerate(msg.detected_persons.persons):
            # Map bodypart to real-world coordinate
            keypointToRealWorld = {}
            for j in range(len(person.person_key_point)):
                try:
                    kp_real_x = getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3]
                    kp_real_y = getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3 + 1]
                    kp_real_z = getattr(msg, f'{person.body_parts[j]}_real_world_coordinates', [])[i * 3 + 2]
                    keypointToRealWorld[person.body_parts[j]] = (kp_real_x, kp_real_y, kp_real_z)
                except Exception as e:
                    kp_real_x = 0
                    kp_real_y = 0
                    kp_real_z = 0

            # Get main real-world coordinates (center of bbox)
            if msg.real_world_coordinates and i < len(msg.real_world_coordinates) // 3:
                x_real = msg.real_world_coordinates[i * 3]
                y_real = msg.real_world_coordinates[i * 3 + 1]
                z_real = msg.real_world_coordinates[i * 3 + 2]
            else:
                x_real, y_real, z_real = None, None, None

            person_to_key_point_to_real_world[person.id] = keypointToRealWorld
            person_to_real_world[person.id] = (x_real, y_real, z_real)

        return [person_to_real_world, person_to_key_point_to_real_world]

    def transform_to_map(self, camera_coords):
        camera_pose = PoseStamped()
        camera_pose.header.frame_id = 'camera_frame'
        camera_pose.header.stamp = self.get_clock().now().to_msg()

        camera_pose.pose.position.x = camera_coords[1]  # Left/right from the camera (flipped in follow_person), descibes the depth of the camera
        camera_pose.pose.position.y = camera_coords[0]  # Distance from the camera is actually the x value from the camera
        camera_pose.pose.position.z = camera_coords[2] 
        camera_pose.pose.orientation.w = 1.0
        
        pose = camera_pose.pose

        try:
          # Perform the transformation from the left camera frame to the map frame
            transform = self.tf_buffer.lookup_transform('map', 'zed_left_camera_frame', rclpy.time.Time())
            map_pose = tf2_geometry_msgs.do_transform_pose(pose, transform)
            return map_pose
        except Exception as e:
            self.get_logger().error(f'Transformation error: {e}')
            raise e

def main(args=None):
    rclpy.init(args=args)
    goal_publisher_node = GoalPublisher()
    rclpy.spin(goal_publisher_node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
