#include "ros/ros.h"
#include "nav_msgs/Odometry.h"


void chatterCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  ROS_INFO("Seq: [%d]", msg->header.seq);
  ROS_INFO("Position-> x: [%f], y: [%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
  ROS_INFO("Orientation-> x: [%f], y: [%f], z: [%f], w: [%f]", msg->pose.pose.orientation.x, msg->pose.pose.orientation.y, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  ROS_INFO("Vel-> Linear: [%f], Angular: [%f]", msg->twist.twist.linear.x,msg->twist.twist.angular.z);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "odometry");


  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("odom", 1000, chatterCallback);


  ros::spin();

  return 0;
}
