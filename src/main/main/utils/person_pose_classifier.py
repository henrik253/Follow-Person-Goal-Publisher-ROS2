import main.utils.person_pose as Pose

def classify_pose(keypointToRealWorld):        
    nose_coords = keypointToRealWorld.get('nose')
    right_wrist_coords = keypointToRealWorld.get('right_wrist')
    left_wrist_coords = keypointToRealWorld.get('left_wrist')
    
    if not (nose_coords and right_wrist_coords and left_wrist_coords):
        return Pose.DEFAULT_POSE

    if len(nose_coords) < 2 or len(right_wrist_coords) < 2 or len(left_wrist_coords) < 2:
        return Pose.DEFAULT_POSE
    
    # Coordinate system is flipped
    if nose_coords[1] > right_wrist_coords[1] and nose_coords[1] > left_wrist_coords[1]:
        return Pose.BOTH_HANDS_UP
    elif nose_coords[1] > right_wrist_coords[1]:
        return Pose.RIGHT_HAND_UP
    elif nose_coords[1] > left_wrist_coords[1]:
        return Pose.LEFT_HAND_UP
    elif nose_coords[1] < right_wrist_coords[1] and nose_coords[1] < left_wrist_coords[1]:
        return Pose.NO_HAND_UP
    
    return Pose.DEFAULT_POSE




