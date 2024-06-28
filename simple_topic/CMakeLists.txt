cmake_minimum_required(VERSION 3.8)
project(simple_topic)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(can_msgs REQUIRED)

add_executable(simple_topic_node src/simple_topic_node.cpp)
ament_target_dependencies(simple_topic_node
  rclcpp
  std_msgs
  can_msgs
)
install(TARGETS
  simple_topic_node
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
