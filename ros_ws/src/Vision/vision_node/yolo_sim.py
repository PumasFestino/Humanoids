#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from ultralytics import YOLO
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from socket import socket, AF_INET, SOCK_DGRAM
from warnings import filterwarnings

filterwarnings("ignore")
UDP_PORT = 5000

class YoloSim(Node):
    def __init__(self):
        super().__init__('yolo_sim')
        
        # Declare parameters
        self.declare_parameter('yolo_model_path', '')
        self.declare_parameter('ip_server', '127.0.0.1')
        
        # Get parameters
        model_path = self.get_parameter('yolo_model_path').value
        self.udp_ip = self.get_parameter('ip_server').value
        
        # Initialize YOLOv8 model
        self.model = YOLO(model_path)
        self.get_logger().info(f"Loaded YOLOv8 model from: {model_path}")
        
        # Initialize UDP socket
        self.udp_server = socket(AF_INET, SOCK_DGRAM)
        
        # Initialize CV bridge
        self.bridge = CvBridge()
        
        # Create publisher and subscriber
        self.class_image_pub = self.create_publisher(Image, "/vision/yolo/image", 5)
        self.subscription = self.create_subscription(
            Image,
            "/hardware/camera/image",
            self.yolo_callback,
            10)
        
        self.get_logger().info("YOLOv8 Simulator node initialized")

    def yolo_callback(self, msg):
        try:
            # Convert ROS image to OpenCV
            img = self.bridge.imgmsg_to_cv2(msg, "rgb8")
            
            # Run YOLOv8 inference
            results = self.model(img)
            
            # Process results
            for result in results:
                # Log detections
                self.get_logger().debug(f"Detection results: {result.boxes}", throttle_duration_sec=1)
                
                # Visualize results
                annotated_img = result.plot()
                
                # Send detections via UDP
                for box in result.boxes:
                    cls_id = int(box.cls)
                    conf = float(box.conf)
                    xyxy = box.xyxy[0].tolist()
                    
                    vis_str = "{}@({:d},{:d},{:d},{:d}){:.2f}".format(
                        result.names[cls_id],
                        int(xyxy[0]),
                        int(xyxy[1]),
                        int(xyxy[2]),
                        int(xyxy[3]),
                        conf)
                    
                    self.get_logger().info(f"Detection: {vis_str}", throttle_duration_sec=1)
                    self.udp_server.sendto(vis_str.encode('utf-8'), (self.udp_ip, UDP_PORT))
            
            # Publish annotated image
            img_msg = self.bridge.cv2_to_imgmsg(annotated_img, "rgb8")
            self.class_image_pub.publish(img_msg)
            
        except Exception as e:
            self.get_logger().error(f"Error in YOLO callback: {str(e)}")

def main(args=None):
    rclpy.init(args=args)
    
    yolo_sim = YoloSim()
    
    try:
        rclpy.spin(yolo_sim)
    except KeyboardInterrupt:
        pass
    finally:
        yolo_sim.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
