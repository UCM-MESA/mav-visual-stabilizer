#include "ros/ros.h"
//#include "std_msgs/String.h"
#include "gazebo_msgs/ModelStates.h"

void chatterCallBack(const gazebo_msgs::ModelStates::ConstPtr& msg) {
		
		ROS_INFO("%s is at: (%f, %f, %f)", msg->name[1].c_str(), msg->pose[1].position.x, msg->pose[1].position.y, msg->pose[1].position.z);
}

int main( int argc, char **argv) {
		ros::init(argc, argv, "listener");
		ros::NodeHandle n;
		ros::Rate rate(2.0);
		ros::Subscriber sub = n.subscribe("gazebo/model_states", 1000, chatterCallBack);
		
		while (ros::ok()) {
				ros::spinOnce();
				rate.sleep();
		}
		return 0;
}
