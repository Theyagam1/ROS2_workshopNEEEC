#include <iostream>
#include <string>

// Inclui a biblioteca do ROS 2
// #include "..."

// Inclui o tipo de mensagem String



void subsCallback(const std_msgs::msg::String::SharedPtr msg){
    // Escreve a função que vai ser chamada quando receber uma mensagem
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Rate rate(100);

    // Cria um nó e dá-lhe o nome sub_string


    // Cria um subscriber que subscreve na tópico topic/subs



    while(rclcpp::ok()){

        rclcpp::spin_some(node);

        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
