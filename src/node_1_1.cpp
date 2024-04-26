#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include "std_msgs/String.h"
#include <sstream>
#include <pthread.h>

void velFeedback2Callback(const std_msgs::Int16::ConstPtr& msg){
    ROS_INFO("vel_feedback2: [%d]", msg->data);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "node_1_1");
    ros::NodeHandle n;

    ros::Publisher sensor_1_pub;
    sensor_1_pub = n.advertise<std_msgs::Int16>("sensor_1", 1000);
    
    ros::Subscriber vel_feedback_2_sub;
    vel_feedback_2_sub = n.subscribe("vel_feedback2", 1000, velFeedback2Callback);

    std_msgs::String msg;

    std::stringstream ss;
    ss << "node_1_1 data: " << 10;
    msg.data = ss.str();

    sensor_1_pub.publish(msg.data.c_str());

    ros::spin();

    return 0;
}