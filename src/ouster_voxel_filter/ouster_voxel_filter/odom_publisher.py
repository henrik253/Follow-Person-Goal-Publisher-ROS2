import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
import open3d as o3d
import numpy as np
from rclpy.qos import QoSProfile, QoSReliabilityPolicy
from scipy.spatial.transform import Rotation as R

class OdomPublisher(Node):
    def __init__(self):
        super().__init__('ouster_voxel_filter')

        # Define the QoS profile
        qos_profile = QoSProfile(depth=1)
        qos_profile.reliability = QoSReliabilityPolicy.BEST_EFFORT

        # Subscription to LaserScan
        self.laser_scan_subscription = self.create_subscription(
            LaserScan,
            '/ouster/scan',
            self.laser_scan_callback,
            qos_profile,
        )

        # Publisher for odometry
        self.odometry_publisher = self.create_publisher(Odometry, '/odom', 10)

        # Publisher for laser scan
        self.scan_publisher = self.create_publisher(LaserScan, '/scan', 10)

        # Timer for publishing odometry and laser scan
        self.timer = self.create_timer(0.1, self.timer_callback)  # Adjust the period as needed

        self.previous_points = None
        self.last_translation = None
        self.last_rotation = None
        self.last_laser_scan = None
        self.new_odometry_available = False

    def laser_scan_callback(self, msg):
        # Convert LaserScan to 3D points
        points = self.laser_scan_to_points(msg)

        # If we have previous points, compute odometry
        if self.previous_points is not None:
            self.last_translation, self.last_rotation = self.align_point_clouds(self.previous_points, points)
            self.new_odometry_available = True  # Mark that new odometry is available

        # Store the current laser scan message and points
        self.last_laser_scan = msg
        self.previous_points = points

    def timer_callback(self):
        current_time = self.get_clock().now().to_msg()

        # Publish odometry if available
        if self.last_translation is not None and self.last_rotation is not None:
            self.publish_odometry(self.last_translation, self.last_rotation, current_time)

        # Publish laser scan only if new odometry was received since the last scan
        if self.new_odometry_available and self.last_laser_scan is not None:
            self.publish_laser_scan(self.last_laser_scan, current_time)
            self.new_odometry_available = False  # Reset after publishing

    def laser_scan_to_points(self, msg):
        points = []
        for i, r in enumerate(msg.ranges):
            if r < msg.range_min or r > msg.range_max:
                continue  # Skip invalid ranges

            angle = msg.angle_min + i * msg.angle_increment
            x = r * np.cos(angle)
            y = r * np.sin(angle)
            points.append((x, y, 0))  # Assuming z = 0 for 2D points

        return np.array(points)

    def align_point_clouds(self, pc1_xyz, pc2_xyz):
    # Create Open3D point clouds from the provided XYZ coordinates
        pc1 = o3d.geometry.PointCloud()
        pc1.points = o3d.utility.Vector3dVector(pc1_xyz)

        pc2 = o3d.geometry.PointCloud()
        pc2.points = o3d.utility.Vector3dVector(pc2_xyz)

        # Perform ICP alignment
        max_correspondence_distance = 0.1  # Adjust threshold as needed
        reg_icp = o3d.pipelines.registration.registration_icp(
            pc2, pc1, max_correspondence_distance,
        )

        # Extract translation and rotation from the transformation matrix
        transformation_matrix = reg_icp.transformation
        translation = transformation_matrix[:3, 3]  # Extract translation
        rotation_matrix = transformation_matrix[:3, :3]  # Extract rotation matrix

        # Create a writable copy of the rotation matrix
        rotation_matrix_copy = np.array(rotation_matrix, copy=True)
        # Convert rotation matrix to quaternion
        rotation = R.from_matrix(rotation_matrix_copy).as_quat()  # [x, y, z, w]

        return translation, rotation
    def publish_odometry(self, translation, rotation, current_time):
        odometry_msg = Odometry()
        odometry_msg.header.stamp = current_time

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

    def publish_laser_scan(self, laser_scan_msg, current_time):
        laser_scan_msg.header.stamp = current_time
        self.scan_publisher.publish(laser_scan_msg)

def main(args=None):
    rclpy.init(args=args)
    node = OdomPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
