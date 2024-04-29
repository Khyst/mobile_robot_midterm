#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv){
    
        ros::init(argc, argv, "practice_subscriber_1");
    
        ros::NodeHandle nh;
        ros::Subscriber sub = nh.subscribe("practice_topic_1", 100000, chatterCallback);
    
        ros::spin();
    
        return 0;
}