#include <iostream>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Rate rate(100);

    auto dataStr = std_msgs::msg::String();

    auto node = rclcpp::Node::make_shared("data_publisher");

    auto publisher = node->create_publisher<std_msgs::msg::String>("data/publisher", 1);

    dataStr.data = "data";

    while(rclcpp::ok()){

        publisher->publish(dataStr);

        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
