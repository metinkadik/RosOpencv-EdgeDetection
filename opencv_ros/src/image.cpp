#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include "opencv2/imgproc/imgproc.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

image_transport::Subscriber sub;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
           cv::Mat img;
           img = cv_bridge::toCvShare(msg,"bgr8" )->image;
           cv::Mat contours;
           cv::Mat gray_image;

           cvtColor(img, gray_image, CV_RGB2GRAY );

           cv::Canny(img,contours,10,350);

           cv::imshow("Image",img);
           cv::imshow("Canny",contours);
           cv::imwrite("save.jpg",contours);
           cv::waitKey(30);

    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR(" '%s' den 'jpg' formatina donusum yapilamadi", msg->encoding.c_str());
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_listener");
    ros::NodeHandle n;
    image_transport::ImageTransport it(n);
    sub = it.subscribe("camera/rgb/image_raw", 1, imageCallback);
    ros::spin();
    cv::destroyWindow("view");
}
