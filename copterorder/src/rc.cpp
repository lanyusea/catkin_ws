#include <iostream>
#include <ros/ros.h>
using namespace std;

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "rf");
    ros::NodeHandle nh_;
    ros::Publisher pub_;

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
