#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include"topic/rfid_msg.h"

class MyClass
{
        private:
                unsigned int index;
                ros::Publisher rfid_publisher;
        public:
                void id_initialize(unsigned int num);
                unsigned int get_index();
                void publisher_init(int argc, char **argv);
                void info_publish();
};

void MyClass::id_initialize(unsigned int num)
{
        this->index = num;
}

unsigned int MyClass::get_index()
{
        return this->index;
}

void MyClass::publisher_init(int argc, char **argv)
{
        ros::init(argc, argv, "rfid_publisher");
        ros::NodeHandle nh;
        this->rfid_publisher = nh.advertise<topic::rfid_msg>("/rfid_message", 10);
}

void MyClass::info_publish()
{
        topic::rfid_msg rfid_infos;
        rfid_infos.epc = "123123123XXZZ";
        rfid_infos.time = 1235894632;
        rfid_infos.idx = this->get_index();
        rfid_infos.mode = 2;
        rfid_infos.ant = 27;
        // publisher.publish(rfid_infos);
        this->rfid_publisher.publish(rfid_infos);
}

int main(int argc, char **argv)
{
        MyClass AClass;
        AClass.id_initialize(5);

        // ros::init(argc, argv,"rfid_publisher");
        // ros::NodeHandle nh;
        // ros::Publisher rfid_publisher = nh.advertise<topic::rfid_msg>("/rfid_message", 10);  // queue length
        AClass.publisher_init(argc, argv);

        ros::Rate loop_rate(10); // frequency
        while (ros::ok()) // can be replaced by while(1), but would go wrong when stopping, ask for a keyboard interupt
        {
                AClass.info_publish();

                // topic::rfid_msg rfid_infos;
                // rfid_infos.epc = "123123123XXZZ";
                // rfid_infos.time = 1235894632;
                // // rfid_infos.idx = 28;
                // rfid_infos.idx = AClass.get_index();
                // rfid_infos.mode = 2;
                // rfid_infos.ant = 27;
                // rfid_publisher.publish(rfid_infos);
        
                loop_rate.sleep();
        }

        return 0;
}
