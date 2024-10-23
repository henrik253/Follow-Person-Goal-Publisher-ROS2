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
    
    # TODO refactor
        # from ament_index_python.packages import get_package_share_directory
        # get_package_share_directory(directory) returns path to directory  
    # Maybe use LaunchDescription and LaunchConfiguration  
        # from launch import LaunchDescription
        # 

    # look in tb3_simulation_launch.py urdf = os.path.join(sim_dir, 'urdf', 'turtlebot3_waffle.urdf')

    # robot state publisher neccessary for urdf file and publishs state to tf tree

    return LaunchDescription([
        Node(
            package='slam_toolbox',
            executable='sync_slam_toolbox_node', #online_sync_launch? 
            name='slam_toolbox',
            output='screen',
            parameters=[
                '/home/student/Desktop/workspace/src/navigation/config/slam_params.yaml',
                {'use_sim_time': False,  'debug_logging': True}],
            remappings=slam_remappings,
        ),
        # Transform from map to odom
        Node(
            package='tf2_ros',
            namespace='map_to_odom',
            executable='static_transform_publisher',
            arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "map", "odom"]
        ),

        # Transform from odom to base_footprint
        Node(
            package='tf2_ros',
            namespace='odom_to_base_footprint',
            executable='static_transform_publisher',
            arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "odom", "base_footprint"]
        ),
        # Transform from base_footprint to base_link
        Node(
            package='tf2_ros',
            namespace='base_footprint_to_base_link',
            executable='static_transform_publisher',
            arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "base_footprint", "base_link"]
        ),

        # Transform from base_link to os_lidar
        Node(
            package='tf2_ros',
            namespace='base_link_to_os_lidar',
            executable='static_transform_publisher',
            arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "base_link", "os_lidar"]
        ),

        Node(
            package='tf2_ros',
            namespace='base_link_to_os_lidar',
            executable='static_transform_publisher',
            arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "base_link", "base_scan"]
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