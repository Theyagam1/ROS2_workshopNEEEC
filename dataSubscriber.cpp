#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

void dataCallback(const std_msgs::msg::Int32::SharedPtr msg){
    std::cout << "Data: " << msg->data << std::endl;
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Rate rate(100);

    auto node = rclcpp::Node::make_shared("data_subscriber");

    auto subscriber = node->create_subscription<std_msgs::msg::Int32>("data/subscriber", 1, dataCallback);

    while(rclcpp::ok()){

        rclcpp::spin_some(node);
        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
