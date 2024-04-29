#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include <sstream>

int main(int argc, char **argv){
    ros::init(argc, argv, "practice_multi_publisher_1");

    ros::NodeHandle nh_1;
    ros::Publisher pub_1 = nh_1.advertise<std_msgs::String>("practice_topic_lidar", 1000);

    ros::NodeHandle nh_2;
    ros::Publisher pub_2 = nh_2.advertise<std_msgs::Int16>("practice_topic_safety", 1000);

    int count = 0;
    int16_t true_false_test = 0;

    while(ros::ok()){
        std_msgs::String msg_lidar;
        std_msgs::Int16 msg_safety;

        std::stringstream ss;

        ss << "Lidar data: " << count;
        msg_lidar.data = ss.str();
        msg_safety.data = true_false_test;

        ROS_INFO("%s", msg_lidar.data.c_str());
        ROS_INFO("%d", msg_safety.data);

        pub_1.publish(msg_lidar);
        pub_2.publish(msg_safety);

        count++;
        true_false_test = !true_false_test;
        usleep(100000);
    }
}