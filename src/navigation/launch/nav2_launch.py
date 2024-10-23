from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    slam_remappings = [
        ('/scan','/ouster/scan'),
        ('/points','/filtered_points')
        ]

    slam_toolbox_node = Node(
        package='slam_toolbox',
        executable='sync_slam_toolbox_node', 
        name='slam_toolbox',
        output='screen',
        parameters=[
            '/home/student/Desktop/workspace/src/navigation/config/slam_params.yaml',
            {'use_sim_time': False, 'debug_logging': True}
        ],
        arguments=['--ros-args', '--log-level', 'Debug'],
        remappings=slam_remappings,
    )

    # Add namespaces to nodes! and alos 
    start_map_saver_server_cmd = Node(
        package='nav2_map_server',
        executable='map_saver_server',
        output='screen',
        #respawn=use_respawn,
        #respawn_delay=2.0,
       # arguments=['--ros-args', '--log-level', log_level],
      #  parameters=[configured_params])
    )

    map_to_odom_transform_node = Node(
        package='tf2_ros',
        namespace='map_to_odom',
        executable='static_transform_publisher',
        arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "map", "odom"]
    )

    odom_to_base_footprint_transform_node = Node(
        package='tf2_ros',
        namespace='odom_to_base_footprint',
        executable='static_transform_publisher',
        arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "odom", "base_footprint"]
    )

    base_footprint_to_base_link_transform_node = Node(
        package='tf2_ros',
        namespace='base_footprint_to_base_link',
        executable='static_transform_publisher',
        arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "base_footprint", "base_link"]
    )

    base_link_to_os_lidar_transform_node = Node(
        package='tf2_ros',
        namespace='base_link_to_os_lidar',
        executable='static_transform_publisher',
        arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "base_link", "os_lidar"]
    )

    base_link_to_base_scan_transform_node = Node(
        package='tf2_ros',
        namespace='base_link_to_base_scan',
        executable='static_transform_publisher',
        arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", "base_link", "base_scan"]
    )
    
    # Create the launch description
    ld = LaunchDescription()

    # Add nodes to the launch description
    ld.add_action(slam_toolbox_node)
    ld.add_action(start_map_saver_server_cmd)

    ld.add_action(map_to_odom_transform_node)
    ld.add_action(odom_to_base_footprint_transform_node)
    ld.add_action(base_footprint_to_base_link_transform_node)
    ld.add_action(base_link_to_os_lidar_transform_node)
    ld.add_action(base_link_to_base_scan_transform_node)
    return ld


    
# TODO refactor
    # from ament_index_python.packages import get_package_share_directory
    # get_package_share_directory(directory) returns path to directory  
# Maybe use LaunchDescription and LaunchConfiguration  
    # from launch import LaunchDescription
    # 

# look in tb3_simulation_launch.py urdf = os.path.join(sim_dir, 'urdf', 'turtlebot3_waffle.urdf')

# robot state publisher neccessary for urdf file and publishs state to tf tree

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


'''
    start_robot_state_publisher_cmd = Node(
    package='robot_state_publisher',
    executable='robot_state_publisher',
    name='robot_state_publisher',
    output='screen',
    parameters=[{'use_sim_time': use_sim_time,
                    'robot_description': robot_description}],
    remappings=remappings)
'''