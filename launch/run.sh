# cleanup function to kill terminals for each ros2 node!
cleanup() {
    kill $(jobs -p) 2>/dev/null
}

# Trap SIGINT and SIGTERM signals to call cleanup
trap cleanup SIGINT EXIT

CURRENT_DIR=$(pwd)

# Get the screen width and height using xrandr
SCREEN_RESOLUTION=$(xrandr | grep '*+' | awk '{print $1}')
SCREEN_WIDTH=$(echo $SCREEN_RESOLUTION | cut -d 'x' -f 1)
SCREEN_HEIGHT=$(echo $SCREEN_RESOLUTION | cut -d 'x' -f 2)

# Calculate the number of terminals and their dimensions
NUM_TERMINALS=5
TERMINAL_WIDTH=130
TERMINAL_HEIGHT=20

# Calculate positions
X_OFFSET=$((SCREEN_WIDTH / NUM_TERMINALS))
Y_OFFSET=0  # You can change this to position them vertically if needed


xterm -geometry $TERMINAL_WIDTH"x"$TERMINAL_HEIGHT"+"$((0 * X_OFFSET))"+"$Y_OFFSET \
-e "cd '$CURRENT_DIR';cd ..; source install/setup.bash; ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2i; exec bash" & #use_sim_time:=true

xterm -geometry $TERMINAL_WIDTH"x"$TERMINAL_HEIGHT"+"$((1 * X_OFFSET))"+"$Y_OFFSET \
-e "cd '$CURRENT_DIR';cd ..; source install/setup.bash; ros2 run main object_detection_node; exec bash" &

xterm -geometry $TERMINAL_WIDTH"x"$TERMINAL_HEIGHT"+"$((2 * X_OFFSET))"+"$Y_OFFSET \
-e "cd '$CURRENT_DIR';cd ..; source install/setup.bash; ros2 run main position_estimation_node; exec bash" &

xterm -geometry $TERMINAL_WIDTH"x"$TERMINAL_HEIGHT"+"$((3 * X_OFFSET))"+"$Y_OFFSET \
-e "cd '$CURRENT_DIR';cd ..; source install/setup.bash; ros2 run main sensor_presentation_node; exec bash" &

xterm -geometry $TERMINAL_WIDTH"x"$TERMINAL_HEIGHT"+"$((4 * X_OFFSET))"+"$Y_OFFSET \
-e "cd '$CURRENT_DIR';cd ..; source install/setup.bash; ros2 run main goal_publisher_node; exec bash" &

wait