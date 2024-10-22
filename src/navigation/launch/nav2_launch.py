from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    model = os.environ.get('TURTLEBOT3_MODEL', 'burger')

    slam_remappings = [
        ('/scan','/filtered_scan'),
        ('/points','/filtered_points')
        ]
    
    # DEBUG NAV2 
    # 900 Points per message from LiDAR scan 
    # 324 points per message from turtlebot example 

    return LaunchDescription([
        Node(
            package='slam_toolbox',
            executable='sync_slam_toolbox_node',
            name='slam_toolbox',
            output='screen',
            parameters=[
                '/home/student/Desktop/workspace/src/navigation/config/slam_params.yaml',
                {'use_sim_time': False,  'debug_logging': True}],
            remappings=slam_remappings,
        ),
         Node(
            package='tf2_ros',
            namespace = 'os_lidar_to_base_footprint',
            executable='static_transform_publisher',
            arguments= ["0.5", "0", "0", "0", "0", "0",  "os_lidar","base_footprint"]
        ),
          Node(
            package='tf2_ros',
            namespace = 'scan_to_map',
            executable='static_transform_publisher',
            arguments= ["0.0", "0", "0", "0", "0", "0",  "os_lidar","odom"]
        ),
           Node(
            package='tf2_ros',
            namespace = 'odom_to_baselink',
            executable='static_transform_publisher',
            arguments= ["0.0", "0", "0", "0", "0", "0",  "base_link","odom"] # maybe change these
        ),
        ])


# base link -> odom 

# base_link ->  os_lidar

# --- Open RVIZ select map, odom, ...
# select ouster scan (dont forget best effort)
# TODO write seperate node for tf2 tree and lookup for tutorial! 

    # Start RViz for visualization
'''
        Node(
            package='rviz2',
            executable='rviz2',
            output='screen',
            parameters=[rviz_params]
        ),
        # Start the robot state publisher
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            output='screen',
            parameters=[robot_state_publisher_params]
        ),
        # Start your navigation stack
        Node(
            package='navigation',
            executable='nav2_launch',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),
        # Add your custom node for detecting and publishing targets here
        '''