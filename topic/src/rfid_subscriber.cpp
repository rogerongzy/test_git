#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include"topic/rfid_msg.h"

void subscriberCallback(const topic::rfid_msg::ConstPtr& msg)
{
    printf("test1=%s, test2=%010u\n",msg->epc.c_str() ,msg->time);
}

int main(int argc, char **argv)
{
        ros::Subscriber rfid_subscriber;
        ros::init(argc, argv,"rfid_subscriber");
        ros::NodeHandle nh;
        rfid_subscriber = nh.subscribe("/rfid_message", 5, &subscriberCallback);
        ros::Rate loop_rate(10);
        while (ros::ok())
        {
               loop_rate.sleep();
                ros::spinOnce(); // ros::spin();
        }

        return 0;
}
