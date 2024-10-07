
#gnome-terminal -- bash -c "source /opt/ros/humble/setup.bash ;source /home/student/Desktop/workspace/install/local_setup.bash; ros2 launch ouster_ros driver.launch.py ; exec bash"

# For running this script: 
# 0. navigate into workspace folder
# 1. chmod +x run.sh
# 2. source run.sh 

# cleanup function to kill terminals for each ros2 node!
cleanup() {
    kill $(jobs -p) 2>/dev/null
}

# Trap SIGINT and SIGTERM signals to call cleanup
trap cleanup SIGINT EXIT # catch SIGINT and EXIT command to call cleanup. 

CURRENT_DIR=$(pwd)
xterm -e "sleep 3; cd '$CURRENT_DIR'; source install/setup.bash; ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2i; exec bash" & 
xterm -e "sleep 3; cd '$CURRENT_DIR'; source install/setup.bash; ros2 run yolo_tracking object_detection_node; exec bash" &
xterm -e "sleep 3; cd '$CURRENT_DIR'; source install/setup.bash; ros2 run position_estimation position_estimation_node; exec bash" &

wait 




