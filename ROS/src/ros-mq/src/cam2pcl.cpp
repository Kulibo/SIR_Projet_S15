#include "ros/ros.h"
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>

int main(int argc, char **argv) {

    ros::init(argc, argv, "cam2pcl");
    ros::NodeHandle n;
    image_transport::imagetransport it(n);
//    image_transport::publisher      pub = it.advertise("/image_out", 1);
//    image_transport::subscriber     sub = it.subscribe("/image_in", 1, boost::bind(on_image, boost::ref(pub), _1));
 
    /*TODO */
    ros::spin();    
    return 0;

}
/*
 *
 * void on_image(image_transport::publisher& pub, 
	      const sensor_msgs::imageconstptr& msg) {

  cv_bridge::cvimageconstptr bridge_input;
  try {
    bridge_input = cv_bridge::tocvshare(msg,sensor_msgs::image_encodings::rgb8);
  }
  catch (cv::exception& e) {
    std::ostringstream errstr;
    errstr << "cv_bridge exception caught: " << e.what();
    return;
  }
  
  const cv::mat& input  = bridge_input->image;
  cv::mat        output   (input.rows, input.cols, cv_8uc3);

  unsigned int size           = input.rows * input.cols * 3;
  unsigned char* begin_input  = (unsigned char*)(input.data);
  unsigned char* end_input    = (unsigned char*)(input.data) + size;
  unsigned char* out          = (unsigned char*)(output.data);
  unsigned char* in           = begin_input;

  // this is an efficient way to process each channel in each pixel,
  // with an iterator taste.
  while(in != end_input) *(out++) = 255 - *(in++);

  pub.publish(cv_bridge::cvimage(msg->header, "rgb8", output).toimagemsg());
  // bridge_input is handled by a smart-pointer. no explicit delete needed.
}
*/
