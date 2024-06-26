#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv){

    ros::init(argc, argv, "practice_publisher_1");

    ros::NodeHandle nh;
    int count = 0;

    ros::Publisher pub = nh.advertise<std_msgs::String>("practice_topic_1", 1000);

    while(ros::ok()){
        
        std_msgs::String msg;

        std::stringstream ss;
        ss << "Hello World " << count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());
        pub.publish(msg);

        count++;
        usleep(100000);
    }

    return 0;
}