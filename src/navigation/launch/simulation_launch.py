#!/usr/bin/env python3
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node

def generate_launch_description():
    TURTLEBOT3_MODEL = os.environ['TURTLEBOT3_MODEL']
    LDS_MODEL = os.environ['LDS_MODEL']
    
    usb_port = LaunchConfiguration('usb_port', default='/dev/ttyACM0')

    tb3_param_dir = LaunchConfiguration(
        'tb3_param_dir',
        default=os.path.join(
            get_package_share_directory('turtlebot3_bringup'),
            'param',
            TURTLEBOT3_MODEL + '.yaml'))

    if LDS_MODEL == 'LDS-01':
        lidar_pkg_dir = os.path.join(get_package_share_directory('hls_lfcd_lds_driver'), 'launch')
        LDS_LAUNCH_FILE = 'hlds_laser.launch.py'
    elif LDS_MODEL == 'LDS-02':
        lidar_pkg_dir = os.path.join(get_package_share_directory('ld08_driver'), 'launch')
        LDS_LAUNCH_FILE = 'ld08.launch.py'
    else:
        lidar_pkg_dir = os.path.join(get_package_share_directory('hls_lfcd_lds_driver'), 'launch')
        LDS_LAUNCH_FILE = 'hlds_laser.launch.py'

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    bringup_dir = get_package_share_directory('nav2_bringup')
    world_model = LaunchConfiguration('world', default=os.path.join(bringup_dir, 'worlds', 'world_only.model'))  # Ensure this is a valid world file
    use_simulator = LaunchConfiguration('use_simulator', default='true')  # Ensure to declare this
    headless = LaunchConfiguration('headless', default='true')  # Ensure to declare this

    return LaunchDescription([
        #DeclareLaunchArgument('use_sim_time', default_value=use_sim_time, description='Use simulation (Gazebo) clock if true'),
        #DeclareLaunchArgument('usb_port', default_value=usb_port, description='Connected USB port with OpenCR'),
        #DeclareLaunchArgument('tb3_param_dir', default_value=tb3_param_dir, description='Full path to turtlebot3 parameter file to load'),
        DeclareLaunchArgument('world', default_value=world_model, description='Full path to world model file to load'),

        # IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource(os.path.join(get_package_share_directory('turtlebot3_bringup'), 'launch', 'turtlebot3_state_publisher.launch.py')),
        #     launch_arguments={'use_sim_time': use_sim_time}.items(),
        # ),

        # IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource(os.path.join(lidar_pkg_dir, LDS_LAUNCH_FILE)),
        #     launch_arguments={'port': '/dev/ttyUSB0', 'frame_id': 'base_scan'}.items(),
        # ),

        # Start Gazebo server with different parameters
        ExecuteProcess(
            cmd=['gzserver', '-s', 'libgazebo_ros_init.so',
                 '-s', 'libgazebo_ros_factory.so', world_model,
                 '--verbose'],  # Added verbosity for debugging
            cwd=[bringup_dir], output='screen'),

        # Start Gazebo client conditionally based on headless mode
        ExecuteProcess(
            cmd=['gzclient'],
            cwd=[bringup_dir], output='screen'),

        Node(
            package='turtlebot3_node',
            executable='turtlebot3_ros',
            parameters=[tb3_param_dir],
            arguments=['-i', usb_port],
            output='screen'),
    ])
