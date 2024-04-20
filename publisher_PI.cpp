#include <iostream>

#include "rclcpp/rclcpp.hpp"
// Aqui inclui o tipo de mensagem Int32
// #include "..."

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Rate rate(100);

    // Declara a variável que será publicada

    // Cria um nó e dá-lhe o nome pub_pi

    // Cria um publisher que publica na tópico topic/pub

    // Define o valor da variável a ser publicada


    while(rclcpp::ok()){

        // Publica a variável

        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}