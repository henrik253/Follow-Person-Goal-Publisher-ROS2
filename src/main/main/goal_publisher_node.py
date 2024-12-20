import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
from object_tracking_messages.msg import PersonDistance, FollowPersonState
from tf2_ros import TransformBroadcaster, TransformListener, Buffer
import tf2_geometry_msgs
import main.utils.person_pose as Pose
from main.utils.person_pose_classifier import classify_pose
from visualization_msgs.msg import Marker
from enum import Enum 
import logging
from collections import defaultdict

logging.getLogger().setLevel(logging.INFO)

PUBLISH_GOAL_RATE = 0.25 # in seconds
MIN_POSE_COUNT = 3

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

        self.state_publisher = self.create_publisher(FollowPersonState, 'follow_person_state', 10)
        
        self.create_subscription(
            PersonDistance,
            'estimated_person_positions',
            self.person_positions_callback,
            10
        )
        

        self.timer = self.create_timer(PUBLISH_GOAL_RATE, self.publish_goal)  # Publish a goal to configured rate

        # TF2 setup
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.tf_broadcaster = TransformBroadcaster(self)

        # GoalStateMachine setup
        self.current_state = State.STARTED
        
        self.pose_counter = defaultdict(int)

        # Tracked target person 
        self.target_person = None

        # Position from camera
        self.target_person_camera_position = None
        # Position transformed to map 
        self.target_person_map_position = None
        # Flag if transform to map succeded 
        self.last_target_position_success = False

        self.distance = 0.5 # minimum distance to person  

    def change_state(self, new_state):
        self.get_logger().info(f'State changed from {self.current_state.name} to {new_state.name}')
        self.current_state = new_state
        self.publish_state()

    def publish_state(self): 
        follow_person_state_message = FollowPersonState()
        follow_person_state_message.state = self.current_state.name

        if self.current_state == State.FOLLOW_PERSON or self.current_state == State.FOUND_PERSON_TO_FOLLOW:
            follow_person_state_message.id = self.target_person
        else:
            follow_person_state_message.id = -1
        self.state_publisher.publish(follow_person_state_message)
        

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

        # Orientation (no rotation here)
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = 0.0
        marker.pose.orientation.w = 1.0

        # Set the scale of the marker (1x1x1 means 1 meter in each dimension)
        marker.scale.x = 0.3
        marker.scale.y = 0.3
        marker.scale.z = 0.5

        # Set the color (RGBA)
        marker.color.r = 1.0
        marker.color.g = 0.0  
        marker.color.b = 0.0  
        marker.color.a = 1.0 

        # Publish the marker
        self.marker_publisher.publish(marker)

    def publish_goal(self):
        # Check the state of the GoalStateMachine before publishing        
        if self.current_state == State.FOLLOW_PERSON:
            if self.last_target_position_success:
                    goal_msg = PoseStamped()
                    goal_msg.header.stamp = self.get_clock().now().to_msg()
                    goal_msg.header.frame_id = 'map'
                    goal_msg.pose = self.target_person_map_position
                    self.publish_marker()
  
                    self.goal_publisher.publish(goal_msg)
                    print(goal_msg)

    def person_positions_callback(self, msg):
        # Process (detected persons, keypoints) data and update state machine
        persons_to_real_world, person_keypoints = self.proccess_position_estimation_message(msg)

        if self.current_state == State.STARTED:
            self.started_state()
        elif self.current_state == State.LOOK_FOR_PERSON_TO_FOLLOW:
            self.look_for_person_to_follow_state(persons_to_real_world, person_keypoints)
        elif self.current_state == State.FOUND_PERSON_TO_FOLLOW:
            self.found_person_to_follow_state()
        elif self.current_state == State.FOLLOW_PERSON:
            self.follow_person_state(persons_to_real_world, person_keypoints)
        elif self.current_state == State.STOP_FOLLOW_PERSON:
            self.stop_follow_person_state()
    
    def started_state(self):
        self.change_state(State.LOOK_FOR_PERSON_TO_FOLLOW)



    def look_for_person_to_follow_state(self, person_real_world, person_keypoints):
        persons_with_right_hand_up = []
        for person_id, keypoints in person_keypoints.items():
            pose = classify_pose(keypoints)
            
            # Calculate distances of all person with pose
            if pose == Pose.RIGHT_HAND_UP:
                self.pose_counter[(person_id,Pose.RIGHT_HAND_UP)] += 1 

            if self.pose_counter[(person_id,Pose.RIGHT_HAND_UP)] >= MIN_POSE_COUNT: 
                distance = sum(coord ** 2 for coord in person_real_world[person_id]) ** 0.5
                persons_with_right_hand_up.append((distance, person_id))
                self.pose_counter[(self.target_person, Pose.LEFT_HAND_UP)] = 0 

        if persons_with_right_hand_up:
            # taret person with pose that has the closet distance 
            closest_person = min(persons_with_right_hand_up, key=lambda x: x[0])
            self.target_person = closest_person[1]
            self.get_logger().info(f'Target person ID: {self.target_person}')
            self.change_state(State.FOUND_PERSON_TO_FOLLOW)

    def found_person_to_follow_state(self):
        self.get_logger().info(f'Person found with ID: {self.target_person}')  # Log the ID of the person found
        self.change_state(State.FOLLOW_PERSON)

    def follow_person_state(self, persons_to_real_world, persons_to_keypoints):
        if self.target_person in persons_to_real_world:
            if classify_pose(persons_to_keypoints[self.target_person]) == Pose.LEFT_HAND_UP:
                self.pose_counter[(self.target_person, Pose.LEFT_HAND_UP)] += 1
            if self.pose_counter[(self.target_person, Pose.LEFT_HAND_UP)]  >= MIN_POSE_COUNT:
                self.change_state(State.STOP_FOLLOW_PERSON)
                self.pose_counter[(self.target_person, Pose.RIGHT_HAND_UP)] = 0
            else:
                pass
            try:
                person_rwc = persons_to_real_world[self.target_person]
                if(person_rwc[0] and person_rwc[1] and person_rwc[2]): 
                  
                    depth_value = max(person_rwc[2] - self.distance, 0)
                    flipped_person_rwc = (-person_rwc[0],depth_value,-person_rwc[1]) #Pose Estimation: x = person_rwc[0] (left or right from camera: positive means more right) : z = person_rwc[2] the distance from the person (the higher the more away)
                    self.target_person_map_position = self.transform_to_map(flipped_person_rwc)
                    self.target_person_camera_position = flipped_person_rwc
                    self.last_target_position_success = True 
                else:
                    self.get_logger().warn('Unable to calculate persons position')
                    self.last_target_position_success = False
                    return 
            except Exception as e:
                print(e)
                self.last_target_position_success = False
        else:
            pass

    def stop_follow_person_state(self): 
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

    # in ros2 
    def transform_to_map(self, camera_coords):
        camera_pose = PoseStamped()
        camera_pose.header.frame_id = 'camera_frame'
        camera_pose.header.stamp = self.get_clock().now().to_msg()

        camera_pose.pose.position.x = camera_coords[1]  # 
        camera_pose.pose.position.y = camera_coords[0]  # mapping x coordinate from camera to y on map. (x in camera means left or right) 
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
