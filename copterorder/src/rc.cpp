#include <iostream>
#include <ros/ros.h>
#include "roscopter/APMCommand.h"
#include "roscopter/SendWaypoint.h"
#include "roscopter/SendWaypointList.h"
#include "roscopter/XBEECommand.h"
using namespace std;

class CMD {
    public:
        CMD() {
            mode = 12;
        }
        int getMode() {
            return mode;
        }
        void changeCMD(int newCMD) {
            if ((newCMD>=0)&&(newCMD<=12)){
                mode = newCMD;
                cout << "cmd updated" << endl;
            }
            else
                cout << "invalid cmd" <<endl;
        }
        string getName(){
            switch (mode){
                case 1:
                    return "LAUNCH";break;
                case 2:
                    return "LAND";break;
                case 3:
                    return "ARM";break;
                case 4:
                    return "DISARM";break;
                case 5:
                    return "SET MANUAL";break;
                case 6:
                    return "SET HOLD";break;
                case 7:
                    return "SET STABILIZE";break;
                case 8:
                    return "SET ALT_HOLD";break;
                case 9:
                    return "SET AUTO"; break;
                case 10:
                    return "SET LOITER"; break;
                case 11:
                    return "SET LAND";break;
                case 12:
                    return "RC control";break;
            }
        }
    private:
        int mode;

};


void publishCMD(ros::ServiceClient client, CMD cmd) {
    roscopter::APMCommand srv;
    srv.request.command = cmd.getMode();
    if (client.call(srv)) {
        ROS_INFO("Publish successful, mode: %s", cmd.getName().c_str());
    }
}

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "rf");
    ros::NodeHandle nh;
    ros::ServiceClient commandClient = nh.serviceClient<roscopter::APMCommand>("command");
    CMD cmd;

    //ros::Publisher waypointPub = nh.advertise<roscopter::SendWaypoint>()
    ros::ServiceClient waypointPub = nh.serviceClient<roscopter::SendWaypoint>("waypoint");



//TODO:
//ros::service::call /command for mode change
//

//TODO:
//7param:https://github.com/epsilonorion/roscopter/wiki/Exploring-Waypoint-Control

//TODO:
//publish to /send_rc node to rewrite RC channel value
//topic /rc is published by mavlink for current rc value
//
    return 0;
}
