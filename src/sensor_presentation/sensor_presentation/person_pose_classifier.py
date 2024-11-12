
def classify_pose(keypointToRealWorld):        
    nose_coords = keypointToRealWorld.get('nose')
    right_wrist_coords = keypointToRealWorld.get('right_wrist')
    left_wrist_coords = keypointToRealWorld.get('left_wrist')
    
    if not (nose_coords and right_wrist_coords and left_wrist_coords):
        return "Default"  

    if len(nose_coords) < 2 or len(right_wrist_coords) < 2 or len(left_wrist_coords) < 2:
        return "Default"  
    
    # Coordinate system is flipped
    if nose_coords[1] > right_wrist_coords[1] and nose_coords[1] > left_wrist_coords[1]:
        return 'Both Hands Up'
    elif nose_coords[1] > right_wrist_coords[1]:
        return 'Right Hand Up'
    elif nose_coords[1] > left_wrist_coords[1]:
        return 'Left Hand Up'
    elif nose_coords[1] < right_wrist_coords[1] and nose_coords[1] < left_wrist_coords[1]:
        return 'No Hand Up'
    
    return "Default"