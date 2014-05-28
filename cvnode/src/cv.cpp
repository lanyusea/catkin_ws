#include <iostream>
#include <string>
#include <vector>
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

cv_bridge::CvImagePtr cv_ptr;
Mat InImage;

int main(int argc,char **argv)
{
	ros::init(argc, argv, "cvhandler");
	ros::NodeHandle nh;

	image_transport::ImageTransport it(nh);
	image_transport::Subscriber imgSub;

	imgSub = it.subscribe("/camera/image", 1, imageCallback);
	ros::spin();
	return 0;
}

void imageCallback(const sensor_msgs::ImageConstPtr& msg) {

}
