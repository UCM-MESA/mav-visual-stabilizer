#include "ros/ros.h"
//#include "std_msgs/String.h"
#include <geometry_msgs/PoseStamped.h>
#include "gazebo_msgs/ModelStates.h"

geometry_msgs::PoseStamped p;

void chatterCallBack(const gazebo_msgs::ModelStates::ConstPtr& msg) {

//		ROS_INFO("%s is at: (%f, %f, %f)", msg->name[2].c_str(), msg->pose[2].position.x, msg->pose[2].position.y, msg->pose[2].position.z);
		p.pose.position.x = msg->pose[2].position.x;
		p.pose.position.y = msg->pose[2].position.y;
		p.pose.position.z = msg->pose[2].position.z;
		p.pose.orientation.x = msg->pose[2].orientation.x;
		p.pose.orientation.y = msg->pose[2].orientation.y;
		p.pose.orientation.z = msg->pose[2].orientation.z;
		p.pose.orientation.w = msg->pose[2].orientation.w;
}

int main( int argc, char **argv) {
		ros::init(argc, argv, "pub_pose");
		ros::NodeHandle n;
		ros::Rate rate(20.0);
		ros::Subscriber sub = n.subscribe("gazebo/model_states", 1000, chatterCallBack);
		ros::Publisher pos_pub = n.advertise<geometry_msgs::PoseStamped>("mavros/vision_pose/pose", 10);

		//ros::Publisher pos_pub2 = n.advertise<geometry_msgs::PoseStamped>("chatter", 10);
		while (ros::ok()) {
				geometry_msgs::PoseStamped pose = p;
				pos_pub.publish(pose);
				ROS_INFO("published to mavros/vision_pose/pose");
				//pos_pub2.publish(pose);
				ros::spinOnce();
				rate.sleep();
		}

		return 0;
}
