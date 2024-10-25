import numpy as np
import open3d as o3d
from scipy.spatial.transform import Rotation as R

def align_point_clouds(pc1_xyz, pc2_xyz):
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

# Example usage:
# translation, rotation = align_point_clouds(pc1_xyz, pc2_xyz)
