from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    model = os.environ.get('TURTLEBOT3_MODEL', 'burger')

    # ZED Camera Node
    zed_params = {
        'use_sim_time': True
    }

    # SLAM Toolbox Node
    slam_params = {
        'use_sim_time': True
    }

    # RViz Node
    rviz_params = {
        'use_sim_time': True
    }

    # Robot State Publisher Node
    robot_state_publisher_params = {
        'use_sim_time': True
    }

    return LaunchDescription([
        # Start SLAM using slam_toolbox
        Node(
            package='slam_toolbox',
            executable='sync_slam_toolbox_node',
            output='screen',
            parameters=[slam_params]
        ),
        # Start RViz for visualization
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
    ])
