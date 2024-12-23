from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(['/home/student/Desktop/workspace/src/zed-ros2-wrapper/zed_wrapper/launch/zed_camera.launch.py']),
            launch_arguments={'camera_model': 'zed2i'}.items(),
        ),
        #   IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource(['/home/student/Desktop/workspace/src/ouster-ros/ouster-ros/launch/driver.launch.py']),
        # ),
        # IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource(['/home/student/Desktop/workspace/src/navigation/launch/nav2_launch.py']),
        # ),  
        Node(
            package='main',
            executable='object_detection_node',
            name='object_detection_node',
            output='screen'
        ),
        Node(
            package='main',
            executable='position_estimation_node',
            name='position_estimation_node',
            output='screen'
        ),
        Node(
            package='main',
            executable='sensor_presentation_node',
            name='sensor_presentation_node',
            output='screen'
        ),
    ])