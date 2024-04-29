#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv){

    ros::init(argc, argv, "practice_node_1");

    while(ros::ok()){
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello World ";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
        usleep(1000);
    }

    return 0;
}