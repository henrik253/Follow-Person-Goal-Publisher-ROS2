ROS2 Workspace: workspace
Project Overview

This project focuses on object tracking using the YOLO (You Only Look Once) algorithm in conjunction with the ZED 2i camera. The camera is utilized for detecting and measuring the distance to recognized persons. Once a person is detected, a mobile platform (GO1) follows them, enabling dynamic tracking in real-world environments. For path planning and navigation, the Nav2 stack is employed.
Bachelor Thesis

This project is part of a bachelor thesis at Hochschule Trier and is currently in the development phase.

    ATMOS
    NavTrack
    FollowMe

Run this Project

To build and run the project, follow these steps:

    Build the workspace:

    bash

colcon build --symlink-install

Launch the main application:

bash

    ros2 launch main main_launch.py

For More Information and Debugging

To gather more information and for debugging purposes, execute the following commands:

    Build the workspace again:

    bash

colcon build --symlink-install

Source the environment:

bash

    source launch/run.sh

Feel free to modify any parts or add more details as needed!
