import numpy as np


def classify_pose(self, kp):
    # Define indices for relevant joints
    left_wrist_index = 9
    right_wrist_index = 10

    # Ensure required keypoints are available
    if len(kp) > max(left_wrist_index, right_wrist_index):
        left_wrist = np.array(kp[left_wrist_index][:2])  # (x, y) of left wrist
        right_wrist = np.array(kp[right_wrist_index][:2])  # (x, y) of right wrist

        # Calculate the distance between the wrists
        wrist_distance = np.linalg.norm(left_wrist - right_wrist)

        # Threshold for determining if hands are folded
        if wrist_distance < 50:  # Adjust threshold as needed
            return "hands folded"

    return "normal"