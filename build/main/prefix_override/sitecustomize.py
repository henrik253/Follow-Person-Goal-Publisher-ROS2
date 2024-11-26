import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/student/Desktop/Follow-Person-Goal-Publisher-ROS2/install/main'
