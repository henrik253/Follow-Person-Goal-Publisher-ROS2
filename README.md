# Follow Person Implementation in ROS2 Humble

This project is part of a bachelor thesis at **Hochschule Trier** and is currently in the development phase. 

### Key-Features

- **Person Detection & Tracking**: Detects and tracks people in real-time using **YOLOv8-N Pose Model** and the **ZED 2i camera**.
- **Depth & Coordinate Estimation**: Estimates depth and real-world **3D coordinates** (X, Y, Z) for each detected person.
- **Pose Analysis**: Detects when a person raises their **right arm** and saves their **ID** for targeting their location.
- **Goal Pose Publisher**: Publishes the target person's position (on the map) to the **goal_pose** topic.
- **Visualization**: Includes a node for visualizing tracked persons and their positions in real-time.
- **Modular**: Each task is separated into individual nodes, each publishing on custom messages.


## Project Overview: Object Tracking with YOLO and ZED 2i Camera

This project focuses on **object tracking** using the **YOLO (You Only Look Once)** algorithm in combination with the **ZED 2i camera**. The camera is utilized to measure the distance to persons recognized by YOLO, leveraging the **YOLOv8n-pose** model.

When a person raises their right arm:
- Their **ID** is saved.
- Their position will be published to the `/goal_pose` topic at a configurable frequency until the ID disappears or the person raises their left arm.

### Key-Features

- **Person Detection & Tracking**: Detects and tracks people in real-time using **YOLOv8-N Pose Model** and the **ZED 2i camera**.
- **Depth & Coordinate Estimation**: Estimates depth and real-world **3D coordinates** (X, Y, Z) for each detected person.
- **Pose Analysis**: Detects when a person raises their **right arm** and saves their **ID** for targeting their location.
- **Goal Pose Publisher**: Publishes the target person's position (on the map) to the **goal_pose** topic.
- **Visualization**: Includes a node for visualizing tracked persons and their positions in real-time.
- **Modular**: Each task is separated into individual nodes, each publishing on custom messages

## Project Requirements

1. A fully functional robot with:
   - A working **Nav2 stack**.
   - A properly configured **TF2 tree**.

2. TF2 setup:
   - The **ZED 2i camera** must be defined relative to the robot's `base` frame in the TF2 tree.
   - A transformation to the `/map` frame must be provided. 
     - This ensures that the detected person's position in real-world coordinates can be translated to map coordinates.
     - The map coordinates are then published to the `/goal_pose` topic.

## Installation
Make sure you are using ROS2 Humble.

1. Clone the Repository and Its Submodules
```bash
   git clone --recursive https://github.com/henrik253/workspace
```
  
## Run this Project

To build and run the project, follow these steps:

1. Build & source the workspace:
   ```bash
   colcon build --symlink-install
   . install/setup.bash
   ```
   
2. To launch the main application, run:
   ```bash
   ros2 launch main main_launch.py
   ```

For More Information and Debugging

1. Build the workspace:
   ```bash
   colcon build --symlink-install
   ```
2. To launch the main application, run: 
   ```bash
   . launch/run.sh
   ```



