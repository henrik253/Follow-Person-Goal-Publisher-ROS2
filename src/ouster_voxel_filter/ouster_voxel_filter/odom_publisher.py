import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2, LaserScan
from nav_msgs.msg import Odometry

import open3d as o3d
import numpy as np
from rclpy.qos import QoSProfile, QoSReliabilityPolicy
from .point_cloud_2_utils import read_points
from sensor_msgs.msg._point_field import PointField
from scipy.spatial.transform import Rotation as R

class OdomPublisher(Node):
    def __init__(self):
        super().__init__('ouster_voxel_filter')

        # Define the QoS profile
        qos_profile = QoSProfile(depth=5)
        qos_profile.reliability = QoSReliabilityPolicy.BEST_EFFORT

        # Subscription to LaserScan
        self.laser_scan_subscription = self.create_subscription(
            LaserScan,
            '/ouster/scan',
            self.laser_scan_callback,
            qos_profile,
        )

        # Publisher for filtered PointCloud2
        self.publisher = self.create_publisher(PointCloud2, 'filtered_points', 10)
        self.laser_scan_publisher = self.create_publisher(LaserScan, 'filtered_scan', 10)
        self.odometry_publisher = self.create_publisher(Odometry, '/odometry', 10)

        self.latest_filtered_msg = None
        self.latest_filtered_scan = None
        self.previous_points = None
        self.current_points = None
        self.count = 0

    def point_cloud_callback(self, msg):
        # Convert ROS PointCloud2 to numpy array
        points, _ = self.pointCloud2_to_XYZ(msg)

        # Store the current points for odometry calculation
        self.previous_points = self.current_points
        self.current_points = points

        # Create an Open3D point cloud
        pcd = o3d.geometry.PointCloud()
        pcd.points = o3d.utility.Vector3dVector(points)

        # Apply voxel grid filter
        voxel_size = 0.1  # Adjust leaf size
        pcd_downsampled = pcd.voxel_down_sample(voxel_size)

        # Convert back to ROS PointCloud2
        filtered_cloud = np.asarray(pcd_downsampled.points, dtype=np.float64)
        self.latest_filtered_msg = self.array_to_pointcloud2(filtered_cloud, msg.header)

        # If we have both previous and current points, compute odometry
        if self.previous_points is not None and self.current_points is not None:
            translation, rotation = self.align_point_clouds(self.previous_points, self.current_points)
            self.publish_odometry(translation, rotation, msg.header)

    def laser_scan_callback(self, msg):
        # Create a downsampled laser scan
        ranges = np.array(msg.ranges)
        voxel_size = 0.1  # Adjust as needed
        downsampled_ranges = ranges[::int(1/voxel_size)]  # Simplistic downsampling logic

        # Create a new LaserScan message
        filtered_scan = LaserScan()
        filtered_scan.header = msg.header
        filtered_scan.header.stamp = self.get_clock().now().to_msg()
        filtered_scan.angle_min = msg.angle_min
        filtered_scan.angle_max = msg.angle_max
        filtered_scan.angle_increment = msg.angle_increment * int(1/voxel_size)
        filtered_scan.time_increment = msg.time_increment
        filtered_scan.scan_time = msg.scan_time
        filtered_scan.range_min = msg.range_min
        filtered_scan.range_max = msg.range_max
        filtered_scan.ranges = downsampled_ranges.tolist()  # Convert to list

        self.latest_filtered_scan = filtered_scan
        print(f'publishing scan with header: {msg.header}')
        if self.count == 3:
            filtered_scan.header.stamp = self.get_clock().now().to_msg()
            self.laser_scan_publisher.publish(self.latest_filtered_scan)
            self.count = 0
        self.count += 1

    def pointCloud2_to_XYZ(self, msg):
        pcd_as_numpy_array = np.array(list(read_points(msg)))
        sol = []
        for arr in pcd_as_numpy_array:
            x, y, z, _, _, _, _, _, _ = arr  # Ignore other values
            vector = [x, y, z]
            sol.append(vector)
        return np.array(sol), []

    def array_to_pointcloud2(self, points, header):
        # Create PointCloud2 message from numpy array
        msg = PointCloud2()
        msg.header = header
        msg.height = 1
        msg.width = points.shape[0]
        msg.is_dense = True
        msg.is_bigendian = False
        msg.point_step = 12  # 3 floats (x, y, z) * 4 bytes each
        msg.row_step = msg.point_step * msg.width

        # Set fields for the PointCloud2 message
        msg.fields = [
            PointField(name='x', offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name='y', offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name='z', offset=8, datatype=PointField.FLOAT32, count=1)
        ]

        msg.data = points.astype(np.float32).tobytes()  # Convert to float32
        
        return msg

    def align_point_clouds(self, pc1_xyz, pc2_xyz):
        # Create Open3D point clouds from the provided XYZ coordinates
        pc1 = o3d.geometry.PointCloud()
        pc1.points = o3d.utility.Vector3dVector(pc1_xyz)

        pc2 = o3d.geometry.PointCloud()
        pc2.points = o3d.utility.Vector3dVector(pc2_xyz)

        # Perform ICP alignment
        threshold = 0.02  # Distance threshold for point matching
        trans_init = np.eye(4)  # Initial transformation (identity matrix)

        reg_icp = o3d.pipelines.registration.registration_icp(
            pc2, pc1, threshold, trans_init,
            o3d.pipelines.registration.TransformationEstimationPointToPoint()
        )

        # Extract translation and rotation from the transformation matrix
        transformation_matrix = reg_icp.transformation
        translation = transformation_matrix[:3, 3]  # Extract translation
        rotation_matrix = transformation_matrix[:3, :3]  # Extract rotation matrix

        # Convert rotation matrix to quaternion
        rotation = R.from_matrix(rotation_matrix).as_quat()  # [x, y, z, w]

        return translation, rotation

    def publish_odometry(self, translation, rotation, header):
        odometry_msg = Odometry()
        odometry_msg.header = header
        odometry_msg.header.stamp = self.get_clock().now().to_msg()

        # Populate translation
        odometry_msg.pose.pose.position.x = translation[0]
        odometry_msg.pose.pose.position.y = translation[1]
        odometry_msg.pose.pose.position.z = translation[2]

        # Populate rotation (as quaternion)
        odometry_msg.pose.pose.orientation.x = rotation[0]
        odometry_msg.pose.pose.orientation.y = rotation[1]
        odometry_msg.pose.pose.orientation.z = rotation[2]
        odometry_msg.pose.pose.orientation.w = rotation[3]

        self.odometry_publisher.publish(odometry_msg)

def main(args=None):
    rclpy.init(args=args)
    node = OdomPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
