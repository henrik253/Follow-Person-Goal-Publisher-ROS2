import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
import numpy as np
import math

class ObjectTracker(Node): 
    def __init__(self): 
        super().__init__('yolo_tracking')

        # QoS profile for depth image subscription
        qos_profile = rclpy.qos.QoSProfile(
            depth=10,
            reliability=rclpy.qos.ReliabilityPolicy.BEST_EFFORT,
            durability=rclpy.qos.DurabilityPolicy.VOLATILE
        )

        # Create subscriptions
        self.create_subscription(
            Image,
            '/zed/zed_node/left/image_rect_color',
            self.image_callback,
            10
        )
        
        self.depth_subscription = self.create_subscription(
            Image,
            '/zed/zed_node/depth/depth_registered',
            self.depth_callback,
            qos_profile
        )

        # Create publisher for detected object positions
        self.positions_publisher = self.create_publisher(
            Float32MultiArray,
            'detected_object_positions',
            10
        )
        
        # Create CvBridge to convert ROS Image messages to OpenCV images
        self.bridge = CvBridge()

        # Load YOLOv8 model
        self.model = YOLO('yolov8n.pt')

        # Human class index in YOLO
        self.human_class_id = 0

        self.width_depth = 0
        self.depth_image = None
        self.depth = None
        self.distance_formatted = ""
    
    def image_callback(self, msg):
        # Convert ROS Image message to OpenCV image
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        
        # Perform YOLOv8 detection
        results = self.model.track(cv_image, persist=True)
        positions = Float32MultiArray()
        positions.data = []
        
        # Extract detections

        
        
        
        boxes = results[0].boxes
        
        if boxes.data.shape[0] == 0:
            print("No detections found.")
            return
        ## For seperating into mulitple nodes
        ## This Node should publish the bounding box of the detected object, including the detected id 
        
        try:
            track_ids = results[0].boxes.id.int().cpu().tolist()
            class_ids = boxes.cls.int().cpu().tolist()  # when no object is detected an excption is thrown where cls attribute cant be found
            confidences = boxes.conf.float().cpu().tolist()
            
            for bbox, track_id, class_id, confidence in zip(boxes,track_ids, class_ids,confidences): 
                
                if class_id == self.human_class_id:
                    x1, y1, x2, y2 = map(int, bbox.xyxy[0])
                    cv2.rectangle(cv_image, (x1, y1), (x2, y2), (0, 255, 0), 2)
                    
                    

                    x_center = (x1 + x2) // 2
                    y_center = (y1 + y2) // 2
                    
                    distance = None
                    if self.depth is not None:
                        # Ensure x_center and y_center are within bounds
                        if 0 <= x_center < self.width_depth and 0 <= y_center < self.depth.shape[0]:
                            distance = round(self.depth[y_center, x_center],2)
                    
                

                    # if distance is nan or inf we dont update the distance for better representation
                    if distance is not None and not math.isinf(distance) and not math.isnan(distance):
                        self.distance_formatted = f"{distance:.2f}"

                    cv2.putText(cv_image, f'ID: {track_id} Conf: {confidence:.2f} dis:{self.distance_formatted}', (x1, y1-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (36, 255, 12), 2)
                    print(distance)
                    # Append to positions

                    
                    positions.data.append(float(x_center))
                    positions.data.append(float(y_center))

        except Exception as e: 
            print(e)
        
        # Publish detected object positions
        self.positions_publisher.publish(positions)
        cv2.imshow('Human Tracker', cv_image)
        cv2.waitKey(1)

        # Display the depth image if available
        if self.depth_image is not None:
            depth_colored = cv2.applyColorMap(self.depth_image, cv2.COLORMAP_JET)
            cv2.imshow('Depth Map', depth_colored)
            cv2.waitKey(1)

    def depth_callback(self, msg):
        # Convert ROS Image message to OpenCV image
        depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='32FC1')
        width = msg.width
        height = msg.height

        # Convert depth data to numpy array
        depthmap = np.frombuffer(msg.data, dtype=np.float32).reshape((height, width))
        
        self.width_depth = width
        self.depth = depthmap

        # Calculate center pixel index and print depth value
        u = width // 2
        v = height // 2
        if 0 <= u < width and 0 <= v < height:
            center_distance = depthmap[v, u]
            self.get_logger().info(f'Depth value at center: {center_distance}')

        # Normalize depth image for display
        #depth_image_normalized = cv2.normalize(depth_image, None, 0, 255, cv2.NORM_MINMAX)
        #self.depth_image = np.uint8(depth_image_normalized)

def main(args=None):
    rclpy.init(args=args)
    object_tracker = ObjectTracker()
    rclpy.spin(object_tracker)
    object_tracker.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
