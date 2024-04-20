#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

void messageCallback(const std_msgs::msg::Int32::SharedPtr msg){
    if(msg->data == 31416)
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "I received a PI number");
    else
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "I didn't receive the PI: %d", msg->data);
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Rate rate(100);

    auto node = rclcpp::Node::make_shared("sub_pi");

    auto subscriber = node->create_subscription<std_msgs::msg::Int32>("topic/pub", 1, messageCallback);

    while(rclcpp::ok()){

        rclcpp::spin_some(node);
        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}

