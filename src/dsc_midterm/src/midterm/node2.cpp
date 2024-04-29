#include "ros/ros.h"
#include "std_msgs/Int32.h"

int sensor1_value = 0;
int sensor2_value = 0;
int feedback_value = 0;

void sensor1Callback(const std_msgs::Int32::ConstPtr& msg){ // * Subscribe 이후 로직을 위한 Callback 함수
    sensor1_value = msg->data;
    ROS_INFO("I heared: [sensor1: %d]", sensor1_value);
}

void sensor2Callback(const std_msgs::Int32::ConstPtr& msg){ // * Subscribe 이후 로직을 위한 Callback 함수
    sensor2_value = msg->data;
    ROS_INFO("I heared: [sensor2: %d]", sensor2_value);
}

void feedbackCallback(const std_msgs::Int32::ConstPtr& msg){ // * Subscribe 이후 로직을 위한 Callback 함수
    feedback_value = msg->data;
    ROS_INFO("I heared: [vel_feedback: %d]", feedback_value);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node2");

    ros::NodeHandle nh;

    ros::Publisher cmd_pub = nh.advertise<std_msgs::Int32>("vel_cmd", 10);
    ros::Publisher feedback2_pub = nh.advertise<std_msgs::Int32>("vel_feedback2", 10);

    ros::Subscriber sensor1_sub = nh.subscribe("sensor_1", 10, sensor1Callback);
    ros::Subscriber sensor2_sub = nh.subscribe("sensor_2", 10, sensor2Callback);
    ros::Subscriber feedback1_sub = nh.subscribe("vel_feedback", 10, feedbackCallback);

    ros::Rate loop_rate(10); 

    while (ros::ok())
    {
        std_msgs::Int32 msg;
        std_msgs::Int32 feedback_msg;
        msg.data = sensor1_value + sensor2_value;
        feedback_msg.data = feedback_value / 10;
        
        feedback2_pub.publish(feedback_msg);

        for(int i=0; i<10; i++){
            cmd_pub.publish(msg);    
            
            loop_rate.sleep();

            ros::spinOnce();
        }
    }

    return 0;
}
