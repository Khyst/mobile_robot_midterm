#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv){
    ros::init(argc, argv, "practice_multi_publisher_2");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("practice_topic_imu", 1000);

    int count = 0;

    while(ros::ok()){
        std_msgs::String msg;
        std::stringstream ss;

        ss << "IMU data: " << count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());
        pub.publish(msg);
        
        count++;
        usleep(100000);
    }
}