#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include "std_msgs/String.h"
#include <sstream>
#include <pthread.h>


int main(int argc, char **argv){
    ros::init(argc, argv, "node_1_2");
    
    ros::NodeHandle n;

    ros::Publisher sensor_2_pub;
    sensor_2_pub = n.advertise<std_msgs::Int16>("sensor_1", 10);
    
    int count = 0;
    std_msgs::String msg;

    std::stringstream ss;
    ss << "node_1_2 data: " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    sensor_2_pub.publish(msg);

    count += 2;

    ros::spin();

    return 0;
}