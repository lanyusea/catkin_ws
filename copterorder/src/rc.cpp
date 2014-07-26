#include <iostream>
#include <ros/ros.h>
#include "roscopter/APMCommand.h"
#include "roscopter/SendWaypoint.h"
#include "roscopter/SendWaypointList.h"
#include "roscopter/XBEECommand.h"
using namespace std;


int main(int argc, char ** argv)
{
    ros::init(argc,argv, "rf");
    ros::NodeHandle nh;

    ros::ServiceClient apm_cmd_ = nh.serviceClient<roscopter::APMCommand>("command");

    roscopter::APMCommand srv;
    ROS_INFO("Trying to arm");
    if (apm_cmd_.call(srv))
        ROS_WARN("Arm request complete");
    else
        ROS_ERROR("Arm request incomplete");

    roscopter::SendWaypoint wayptListPub = rospy.Publisher('/waypoint_list', roscopter.msg.WaypointList);
    roscopter::SendWaypoint wayptListMsg = roscopter.msg.WaypointList();

}


