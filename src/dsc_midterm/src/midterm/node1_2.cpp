#include <ros/ros.h>
#include <std_msgs/Int32.h>

int value;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node1_2");

    ros::NodeHandle nh;

    ros::Publisher sensor2_pub = nh.advertise<std_msgs::Int32>("sensor_2", 10);

    ros::Rate loop_rate(1);

    value = 1;

    while (ros::ok())
    {
        std_msgs::Int32 msg;
        msg.data = value;

        sensor2_pub.publish(msg);

        value += 2;

        loop_rate.sleep();
    }

    return 0;
}
