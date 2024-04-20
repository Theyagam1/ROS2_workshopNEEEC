#include <string>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

auto message = std_msgs::msg::String();

void subsCallback(const std_msgs::msg::String::SharedPtr msg){
    message.data = msg->data;
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Rate rate(100);

    auto node = rclcpp::Node::make_shared("pub_string");

    auto publisher = node->create_publisher<std_msgs::msg::String>("topic/subs", 1);

    auto subscriber = node->create_subscription<std_msgs::msg::String>("topic/set", 1, subsCallback);

    message.data = "You subscribed correctly";

    while(rclcpp::ok()){

        publisher->publish(message);

        rclcpp::spin_some(node);
        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
