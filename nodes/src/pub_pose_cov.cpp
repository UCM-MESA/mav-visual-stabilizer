#include "ros/ros.h"
//#include "std_msgs/String.h"
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include "gazebo_msgs/ModelStates.h"

geometry_msgs::PoseWithCovarianceStamped p;

void chatterCallBack(const gazebo_msgs::ModelStates::ConstPtr& msg) {

//		ROS_INFO("%s is at: (%f, %f, %f)", msg->name[2].c_str(), msg->pose[2].position.x, msg->pose[2].position.y, msg->pose[2].position.z);
		p.pose.pose.position.x = msg->pose[2].position.x;
		p.pose.pose.position.y = msg->pose[2].position.y;
		p.pose.pose.position.z = msg->pose[2].position.z;
		p.pose.pose.orientation.x = msg->pose[2].orientation.x;
		p.pose.pose.orientation.y = msg->pose[2].orientation.y;
		p.pose.pose.orientation.z = msg->pose[2].orientation.z;
		p.pose.pose.orientation.w = msg->pose[2].orientation.w;
		p.pose.covariance = {1, 0, 0, 0, 0, 0,
												 0, 1, 0, 0, 0, 0,
												 0, 0, 1, 0, 0, 0,
												 0, 0, 0, 1, 0, 0,
												 0, 0, 0, 0, 1, 0,
												 0, 0, 0, 0, 0, 1};
}

int main( int argc, char **argv) {
		ros::init(argc, argv, "pub_pose_cov");
		ros::NodeHandle n;
		ros::Rate rate(20.0);
		ros::Subscriber sub = n.subscribe("gazebo/model_states", 1000, chatterCallBack);
		ros::Publisher pos_pub = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("mavros/vision_pose/pose_cov", 10);

		//ros::Publisher pos_pub2 = n.advertise<geometry_msgs::PoseStamped>("chatter", 10);
		while (ros::ok()) {
				geometry_msgs::PoseWithCovarianceStamped pose = p;
				pos_pub.publish(pose);
				ROS_INFO("published to mavros/vision_pose/pose_cov");
				//pos_pub2.publish(pose);
				ros::spinOnce();
				rate.sleep();
		}

		return 0;
}
