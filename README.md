# ROS2 Workspace: workspace

## Project Overview

This project focuses on **object tracking** using the **YOLO (You Only Look Once)** algorithm in conjunction with the **ZED 2i camera**. The camera is utilized for detecting and measuring the distance to recognized persons. Once a person is detected, a mobile platform (GO1) follows them, enabling dynamic tracking in real-world environments. For path planning and navigation, the **Nav2** stack is employed.

### Bachelor Thesis

This project is part of a bachelor thesis at **Hochschule Trier** and is currently in the development phase. 

  
## Run this Project

To build and run the project, follow these steps:

1. Build the workspace:
   ```bash
   colcon build --symlink-install
   ```
   
2. To launch the main application, run:
   ```bash
   ros2 launch main main_launch.py
   ```

## For More Information and Debugging

1. Build the workspace:
   ```bash
   colcon build --symlink-install
   ```
To launch the main application, run: 
   ```bash
   source launch/run.sh
   ```


### Possible names for this project
- ATMOS
- NavTrack
- FollowMe
