
gnome-terminal -- bash -c "source /opt/ros/humble/setup.bash ;source /home/student/Desktop/workspace/install/local_setup.bash; ros2 launch ouster_ros driver.launch.py ; exec bash"


# is not working for now, Wrong bash setup?
xterm -e "sleep 3;source /opt/ros/humble/setup.bash ;source /home/student/Desktop/workspace/install/local_setup.bash; ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2i; exec bash"

xterm -e "sleep 3;source /opt/ros/humble/setup.bash ;source /home/student/Desktop/workspace/install/setup.bash; ros2 run yolo_tracking object_detection_node; exec bash"
