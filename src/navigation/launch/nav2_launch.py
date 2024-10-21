from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    model = os.environ.get('TURTLEBOT3_MODEL', 'burger')

    return LaunchDescription([
        Node(
            package='slam_toolbox',
            executable='sync_slam_toolbox_node',
            name='slam_toolbox',
            output='screen',
            parameters=[{'use_sim_time': False, 'queue_size': 10}],
            remappings=[('/scan','/ouster/scan'),('/points','/filtered_points')],
        ),
          Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='static_os_lidar_transform',
            output='screen',
            parameters=[],
            arguments=['0', '0', '0', '0', '0', '0', 'os_lidar', 'os_sensor']  # Adjust this as needed
        ),
        ])



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