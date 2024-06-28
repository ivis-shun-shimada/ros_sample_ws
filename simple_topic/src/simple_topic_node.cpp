#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include "can_msgs/msg/frame.hpp"

class SimpleTopicNode : public rclcpp::Node
{
public:
  SimpleTopicNode()
  : Node("simple_topic_node")
  {
    pub_ = this->create_publisher<std_msgs::msg::String>("str_topic", 10);
    timer_ = this->create_wall_timer(
      std::chrono::seconds(1), std::bind(&SimpleTopicNode::timer_function, this)
      );    
  }

  ~SimpleTopicNode()
  {
  }

private:
  void timer_function()
  {
    auto message = std_msgs::msg::String();
    message.data = "hello";
    RCLCPP_INFO(this->get_logger(), "test publish");
    pub_->publish(message);
  }
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;

};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleTopicNode>());
  rclcpp::shutdown();
  return 0;
}
