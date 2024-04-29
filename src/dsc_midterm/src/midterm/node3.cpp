#include "ros/ros.h"
#include "std_msgs/Int32.h"

int cmd_value = 0;

void cmdCallback(const std_msgs::Int32::ConstPtr& msg){ 
    cmd_value = msg->data;
    ROS_INFO("I heared: [vel_cmd: %d]", cmd_value);
}

int main(int argc, char **argv){
    
    ros::init(argc, argv, "node3");

    ros::NodeHandle nh;

    ros::Publisher feedback1_pub = nh.advertise<std_msgs::Int32>("vel_feedback", 10);
    ros::Subscriber cmd_sub = nh.subscribe("vel_cmd", 10, cmdCallback);

    ros::Rate loop_rate(10); // 10Hz

    while(ros::ok()){
        
        std_msgs::Int32 msg;
        msg.data = cmd_value + 100;

        feedback1_pub.publish(msg);

        loop_rate.sleep();

        ros::spinOnce();

    }

    return 0;
}