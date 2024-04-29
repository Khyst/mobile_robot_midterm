#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

void chatterCallback2(const std_msgs::Int16::ConstPtr& msg){
    ROS_INFO("I heard: [%d]", msg->data);
}

void chatterCallback3(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv){
    
    ros::init(argc, argv, "practice_multi_subscriber");
    
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("practice_topic_lidar", 100000, chatterCallback);
    ros::Subscriber sub_2 = nh.subscribe("practice_topic_safety", 100000, chatterCallback2);
    ros::Subscriber sub_3 = nh.subscribe("practice_topic_imu", 100000, chatterCallback3);
    
    ros::spin();
    
    return 0;
}