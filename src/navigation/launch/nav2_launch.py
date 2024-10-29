from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from nav2_common.launch import RewrittenYaml
from launch_ros.descriptions import ParameterFile
from launch.actions import IncludeLaunchDescription,DeclareLaunchArgument,ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
import os

def generate_launch_description():

    # The part that is missing for now is the robot launch! 
    # this launch can be run in combination with robot.launch.py | more descirption on nav2-exa... branch
    # in the robot.launch.py robot state publisher is called and lidar_pkg_dir and turtlebot3_node
    # and robot state publisher is actually only creating a node containing robot_state_publisher
    # and the robot_desc!   
    
  
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
    )

    #Include Navigation Launch
    navigation_launch_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(['/home/student/Desktop/workspace/src/navigation/launch/navigation_launch.py']),
    )

    rviz_launch_cmd = IncludeLaunchDescription(PythonLaunchDescriptionSource(['/home/student/Desktop/workspace/src/navigation/launch/rviz_launch.py']))
    
    bringup_dir = get_package_share_directory('nav2_bringup')
    declare_world_cmd = DeclareLaunchArgument(
        'world',
        default_value=os.path.join(bringup_dir, 'worlds', 'world_only.model'),
        description='Full path to world model file to load'
    )

    start_gazebo_server_cmd = ExecuteProcess(
        cmd=['gzserver', '-s', 'libgazebo_ros_init.so', '-s', 'libgazebo_ros_factory.so', LaunchConfiguration('world')],
        output='screen'
    )
    start_gazebo_client_cmd = ExecuteProcess(
        cmd=['gzclient'],
        output='screen'
    )
   
  

    # Static Transform Nodes
    # def create_static_transform_node(frame_id, child_frame_id):
    #     return Node(
    #         package='tf2_ros',
    #         executable='static_transform_publisher',
    #         arguments=["0.0", "0.0", "0.0", "0.0", "0.0", "0.0", frame_id, child_frame_id]
    #     )

    # transform_nodes = [
    #     create_static_transform_node("map", "odom"),
    #     create_static_transform_node("odom", "base_footprint"),
    #     create_static_transform_node("base_footprint", "base_link"),
    #     create_static_transform_node("base_link", "os_lidar"),
    #     create_static_transform_node("base_link", "base_scan")
    # ]

    # Create the launch description
    ld = LaunchDescription()

    ld.add_action(declare_world_cmd)
    ld.add_action(start_gazebo_server_cmd)
    ld.add_action(start_gazebo_client_cmd)

    # Add nodes to the launch description
    ld.add_action(slam_toolbox_node)
    ld.add_action(navigation_launch_cmd)
    ld.add_action(rviz_launch_cmd)
    

    # for transform_node in transform_nodes:
    #     ld.add_action(transform_node)

    return ld
