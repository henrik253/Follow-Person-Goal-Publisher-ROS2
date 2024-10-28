from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os

def generate_launch_description():
    robot_sdf = '/opt/ros/humble/share/nav2_bringup/worlds/world_only.model'
    robot_name = 'turtlebot3_waffle'
    pose = {
        'x': '-2.00',
        'y': '-0.50',
        'z': '0.01',
        'R': '0.00',
        'P': '0.00',
        'Y': '0.00'
    }
    
    # Command to spawn the robot
    start_gazebo_spawner_cmd = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        output='screen',
        arguments=[
            '-entity', robot_name,
            '-file', robot_sdf,
            '-x', pose['x'], '-y', pose['y'], '-z', pose['z'],
            '-R', pose['R'], '-P', pose['P'], '-Y', pose['Y']
        ]
    )

    # Command to launch RViz
    rviz_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource('/home/student/Desktop/workspace/src/navigation/launch/rviz_launch.py'),
        launch_arguments={'rviz_config': '/opt/ros/humble/share/nav2_bringup/rviz/nav2_default_view.rviz'}.items()
    )

    # Create the launch description
    ld = LaunchDescription()

    # Add actions to the launch description
    ld.add_action(start_gazebo_spawner_cmd)
    ld.add_action(rviz_cmd)

    return ld
