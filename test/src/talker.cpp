#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv) {

		ros::init(argc, argv, "talker"); //NEED ros::init() before using any other part of ROS system.
		ros::NodeHandle n; //the main access point to communications with ROS.

		ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
		ros::Rate loop_rate(10);

		int count = 0;
		//stuff msg with data and then publish it.
		while (ros::ok()) {
				std_msgs::String msg;
				std::stringstream ss;
				ss << "YEAA BOII " << count;
				msg.data = ss.str();

				ROS_INFO("%s", msg.data.c_str()); //prints out

				chatter_pub.publish(msg); //publishes & sends messages
				ros::spinOnce();
				loop_rate.sleep();
				++count;
		}

		return 0;
}
