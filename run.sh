
#gnome-terminal -- bash -c "source /opt/ros/humble/setup.bash ;source /home/student/Desktop/workspace/install/local_setup.bash; ros2 launch ouster_ros driver.launch.py ; exec bash"


CURRENT_DIR=$(pwd)

# Open a new terminal for the first command
xterm -e "sleep 3; cd '$CURRENT_DIR'; source install/setup.bash; source install/local_setup.bash; ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2i; exec bash" & 

# Open a new terminal for the second command
xterm -e "sleep 3; cd '$CURRENT_DIR'; source install/setup.bash; source install/local_setup.bash; ros2 run yolo_tracking object_detection_node; exec bash" &