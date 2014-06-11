#include <iostream>
#include <ros/ros.h>
#include "roscopter/APMCommand.h"
#include "roscopter/SendWaypoint.h"
#include "roscopter/SendWaypointList.h"
#include "roscopter/XBEECommand.srv"
using namespace std;

int command = 12;

void changeCMD(int newMode) {
    command = newMode;
}

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "rf");
    ros::NodeHandle nh_;
    ros::Publisher pub_;

    ros::ServiceClient commandClient = n.serviceClient<roscopter::APMCommand>("command");

    roscopter::APMCommand srv;
    srv.request.command = command;

//TODO:
//ros::service::call /command for mode change
//

//TODO:
//ros::service::call /waypoint to set destination
//7param:https://github.com/epsilonorion/roscopter/wiki/Exploring-Waypoint-Control

//TODO:
//publish to /send_rc node to rewrite RC channel value
//topic /rc is published by mavlink for current rc value
//
    return 0;
}
