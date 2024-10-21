import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2
import open3d as o3d
import numpy as np
from rclpy.qos import QoSProfile, QoSReliabilityPolicy
from .point_cloud_2 import read_points
from sensor_msgs import point_cloud2

class VoxelFilterNode(Node):
    def __init__(self):
        super().__init__('ouster_voxel_filter')

        # Define the QoS profile
        qos_profile = QoSProfile(depth=10)
        qos_profile.reliability = QoSReliabilityPolicy.BEST_EFFORT

        self.subscription = self.create_subscription(
            PointCloud2,
            '/ouster/points',
            self.point_cloud_callback,
            qos_profile,
        )

        self.publisher = self.create_publisher(PointCloud2, 'filtered_points', 10)

    def point_cloud_callback(self, msg):
        # Convert ROS PointCloud2 to numpy array
        points, _ = self.pointCloud2_to_XYZ(msg)

        # Create an Open3D point cloud
        pcd = o3d.geometry.PointCloud()
        pcd.points = o3d.utility.Vector3dVector(points)

        # Apply voxel grid filter
        voxel_size = 0.1  # Adjust leaf size
        pcd_downsampled = pcd.voxel_down_sample(voxel_size)

        # Convert back to ROS PointCloud2
        filtered_cloud = np.asarray(pcd_downsampled.points, dtype=np.float64)
        filtered_msg = self.array_to_pointcloud2(filtered_cloud, msg.header)
        self.publisher.publish(filtered_msg)

    def pointCloud2_to_XYZ(self, msg):
        pcd_as_numpy_array = np.array(list(read_points(msg)))
        sol = []
        for arr in pcd_as_numpy_array:
            x, y, z, _, _, _, _, _, _ = arr  # Ignore other values
            vector = [x, y, z]
            sol.append(vector)
        return sol, []

   
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
            point_cloud2.PointField(name='x', offset=0, datatype=point_cloud2.PointField.FLOAT32, count=1),
            point_cloud2.PointField(name='y', offset=4, datatype=point_cloud2.PointField.FLOAT32, count=1),
            point_cloud2.PointField(name='z', offset=8, datatype=point_cloud2.PointField.FLOAT32, count=1)
        ]

        msg.data = points.astype(np.float32).tobytes()  # Convert to float32
        
        return msg


def main(args=None):
    rclpy.init(args=args)
    node = VoxelFilterNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
