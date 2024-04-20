# ROS2_workshopNEEEC
In this repo, you have all the files needed in the ROS2 workshop

------

1. [Introduction](#Introduction)
2. [ROS2 Essential Commands](#ROS2-Essential-Commands)
3. [Trutlesim](#Turtlesim)
4. [Install Colon and Create Workspace](#Install-Colcon/Create-Workspace)
5. [Package.xml and CMakeLists.txt Changes](#Package.xml-and-CMakeLists.txt-Changes)

------

## Introduction:

Here you can find all the necessary commands to do well in this  workshop!

------

## ROS2 Essential Commands:

Source ROS2:
```
source /opt/ros/humble/setup.bash
```

Run a node:
```
ros2 run <package_name> <executable_name>
```

Check node list:
```
ros2 node list
```

Check node info:
```
ros2 node info <node_name>
```

Check topic list:
```
ros2 topic list
```

Subscribe topic:
```
ros2 topic echo <topic_name>
```
Note: With this command all variables published in the topic will be printed in the terminal.

Publish on topic:
```
ros2 topic pub <topic_name> <msg_type> '<args>'
```

Check node info:
```
ros2 topic info <topic_name>
```

Check service list:
```
ros2 service list
```

Call service:
```
ros2 service call <service_name> <service_type> <arguments>
```

Service type info:
```
ros2 service type <service_name>
```

------

## Turtlesim:
To use turtlesim:
    Open 2 terminals:
    Source ROS2 in both of them using:
    ```
    source /opt/ros/humble/setup.bash
    ```
    Note: "source" is the same as "." so you can use either of them in the command.
    Run turtlesim node in one terminal:
    ```
    ros2 run turtlesim turtlesim_node
    ```
    Run teleop node in the other terminal:
    ```
    ros2 run turtlesim turtle_teleop_key
    ```
    Now play with the previous commands to see the nodes, topics and services running

------

## Install Colcon/Create Workspace

Install colcon:
```
sudo apt install python3-colcon-common-extensions
```

Create Workspace:
```
mkdir -p ~/workspace/src
```
Note: This command create a folder called "workspace" and inside a folder called "src".

Build ROS2 Workspace:
```
cd workspace
colcon build
```

Source ROS2 Workspace:
```
source install/setup.bash
```
Note: You have to be in the folder where u created your workspace for exemple: User@User:~/<YOURWORKSPACE>$

------

## Package.xml and CMakeLists.txt Changes

In the Package.xml:
```
  <depend>rclcpp</depend>
  <depend>std_msgs</depend>
```

In the CMakeLists.txt:
```
Find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(data_publisher src/dataPublisher.cpp)
ament_target_dependencies(data_publisher rclcpp std_msgs)

add_executable(data_subscriber src/dataSubscriber.cpp)
ament_target_dependencies(data_subscriber rclcpp std_msgs)
```

------
