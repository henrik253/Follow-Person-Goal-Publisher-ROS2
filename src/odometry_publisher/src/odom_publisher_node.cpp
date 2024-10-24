#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2/LinearMath/Quaternion.h"

class OdomPublisher : public rclcpp::Node
{
public:
    OdomPublisher()
        : Node("odom_publisher"), x_(0.1), y_(0.1), yaw_(0.0)
    {
        odom_publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("/odom", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(50), std::bind(&OdomPublisher::publish_odom, this));
    }

private:
    int _counter = 0; 
    void publish_odom()
    {
        auto odom_msg = nav_msgs::msg::Odometry();
        odom_msg.header.stamp = this->now();
        odom_msg.header.frame_id = "odom";
        odom_msg.child_frame_id = "base_link";

        odom_msg.pose.pose.position.x = x_;
        odom_msg.pose.pose.position.y = y_;
        odom_msg.pose.pose.position.z = 0.0; // z position is 0

        // Convert yaw to quaternion
        tf2::Quaternion q;
        q.setRPY(0.0, 0.0, yaw_);
        odom_msg.pose.pose.orientation.x = q.x();
        odom_msg.pose.pose.orientation.y = q.y();
        odom_msg.pose.pose.orientation.z = q.z();
        odom_msg.pose.pose.orientation.w = q.w();
  
        if(_counter == 10){
            _counter = 0; 
            x_ -= 0.1;
            y_ += 0.0;
            std::cout << "x_: " <<  x_ << "\n" ; 
        }
        _counter++; 
        odom_publisher_->publish(odom_msg);
    }

    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    double x_, y_, yaw_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OdomPublisher>());
    rclcpp::shutdown();
    return 0;
}
