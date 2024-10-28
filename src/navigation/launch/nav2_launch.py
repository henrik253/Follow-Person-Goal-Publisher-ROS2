from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from nav2_common.launch import RewrittenYaml
from launch_ros.descriptions import ParameterFile
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
import os

def generate_launch_description():
    slam_remappings = [
        ('/scan', '/scan'),
        ('/points', '/filtered_points')
    ]

    # SLAM Toolbox Node
    slam_toolbox_node = Node(
        package='slam_toolbox',
        executable='async_slam_toolbox_node',
        name='slam_toolbox',
        output='screen',
        parameters=[
            '/home/student/Desktop/workspace/src/navigation/config/slam_params.yaml',
            {'use_sim_time': LaunchConfiguration('use_sim_time', default='false'), 'debug_logging': True}
        ],
        remappings=slam_remappings,
    )

    # Parameters for Navigation
    params_file = '/home/student/Desktop/workspace/src/navigation/config/nav2_params.yaml'
    namespace = ''#LaunchConfiguration('namespace', default='/')  # Use LaunchConfiguration
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    autostart = True  # Boolean directly

    param_substitutions = {
        'use_sim_time': str(use_sim_time),
        'autostart': str(autostart)
    }

    log_level = 'Debug'
    remappings = [('/tf', 'tf'), ('/tf_static', 'tf_static')]

    configured_params = ParameterFile(
        RewrittenYaml(
            source_file=params_file,
            root_key=namespace,
            param_rewrites=param_substitutions,
            convert_types=True),
        allow_substs=True
    )

    #Include Navigation Launch
    navigation_launch_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(['/home/student/Desktop/workspace/src/navigation/launch/navigation_launch.py']),
    )

    simulation_launch_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(['/home/student/Desktop/workspace/src/navigation/launch/SimulationLaunch.py']),
    )


    # Load Robot Description from URDF
    urdfPath = '/opt/ros/humble/share/nav2_bringup/urdf/turtlebot3_waffle.urdf'
    with open(urdfPath, 'r') as infp:
        robot_description = infp.read()

    # Robot State Publisher
    start_robot_state_publisher_cmd = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        namespace=namespace,
        output='screen',
        parameters=[{'use_sim_time': use_sim_time, 'robot_description': robot_description}],
        remappings=remappings
    )

    # Navigation Container
    nav2_container_cmd = Node(
        name='nav2_container',
        package='rclcpp_components',
        executable='component_container_isolated',
        parameters=[configured_params, {'autostart': autostart}],
        arguments=['--ros-args', '--log-level', log_level],
        remappings=remappings,
        output='screen'
    )

    # Static Transform Nodes
    def create_static_transform_node(frame_id, child_frame_id):
        return Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", frame_id, child_frame_id]
        )

    transform_nodes = [
        create_static_transform_node("map", "odom"),
        create_static_transform_node("odom", "base_footprint"),
        create_static_transform_node("base_footprint", "base_link"),
        create_static_transform_node("base_link", "os_lidar"),
        create_static_transform_node("base_link", "base_scan")
    ]

    # Create the launch description
    ld = LaunchDescription()

    # Add nodes to the launch description
    ld.add_action(slam_toolbox_node)
    ld.add_action(nav2_container_cmd)
    ld.add_action(start_robot_state_publisher_cmd)
    ld.add_action(navigation_launch_cmd)
    
   # ld.add_action(simulation_launch_cmd)

    for transform_node in transform_nodes:
        ld.add_action(transform_node)

    return ld
