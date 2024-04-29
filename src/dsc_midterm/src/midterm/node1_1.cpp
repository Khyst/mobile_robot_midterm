#include "ros/ros.h"
#include "std_msgs/Int32.h"

int feedback_value = 0;

void feedbackCallback(const std_msgs::Int32::ConstPtr& msg) {

    feedback_value = msg->data; 
    ROS_INFO("I heared: [vel_feedback2: %d]", feedback_value);

}

int main(int argc, char **argv) {

    ros::init(argc, argv, "node1_1");
    
    ros::NodeHandle nh;

    ros::Publisher sensor1_pub = nh.advertise<std_msgs::Int32>("sensor_1", 10);
    ros::Subscriber feedback2_sub = nh.subscribe("vel_feedback2", 10, feedbackCallback);

    ros::Rate loop_rate(10); // 10Hz

    while (ros::ok())
    {
        std_msgs::Int32 msg;
        msg.data = 100;

        sensor1_pub.publish(msg);

        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}