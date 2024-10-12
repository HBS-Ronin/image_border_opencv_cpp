//
//  main.cpp
//  image_border
//
//  Created by Danyal Ahmad Siddiqui on 05/06/2023.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;
Mat src, dst;
double min_bd_th = 0.05;
double asp_ratio = 0.8;
double inv_asp_ratio = (1/asp_ratio);
//int bc
int top;
int bottom;
int right;
int left;
//cv::Scalar value;

void disp_img(Mat* img, double min_bd_th, double asp_ratio, unsigned char red, unsigned char green, unsigned char blue){
    

   Mat src = *img;
   Mat dst;

   double inv_asp_ratio = (1/asp_ratio);
   //int bc
   int top;
   int bottom;
   int right;
   int left;

//    double min_bd_th = 0.05;
//    double asp_ratio = 0.8;
//    unsigned char red = 255;
//    unsigned char green = 255;
//    unsigned char blue = 255;

    // src = cv::imread(file_name);
    // src = *img;

    
    if (src.empty())
    {
     std::cout << "Could not open or find the image" << std::endl;
     std::cin.get(); //wait for any key press
    
    }
    
    if(src.rows > src.cols){
        top = min_bd_th*src.rows;
        bottom = top;
        right = ((2*top + src.rows)*inv_asp_ratio - src.cols)*0.5;
        left = right;
    } else if (src.rows < src.cols){
        right = min_bd_th*src.cols;
        left = right;
        top =((2*right +src.cols)*asp_ratio - src.rows)*0.5;
        bottom = top;
    }else{
        top = 0.05*src.rows;
        bottom = top;
        right =((2*min_bd_th+1)*src.rows*inv_asp_ratio - src.rows)*0.5;
    }
    
    cv::Scalar value(red, green, blue);
    
    cv::copyMakeBorder(src, dst, top, bottom, right, left, cv::BORDER_CONSTANT, value);
    cv::String windowName = "The Guitar"; //Name of the window

    cv::namedWindow(windowName); // Create a window

    cv::imshow(windowName, dst); // Show our image inside the created window.

    cv::waitKey(0); // Wait for any keystroke in the window

    cv::destroyWindow(windowName); //destroy the created window
}


int main(int argc, char** argv){

  cv::CommandLineParser parser(argc, argv,
                               "{@input             |lena.jpg|input image}"
	  			"{min_border_thick m|0.05| the minimumn border thickness as a relative value}"
				"{aspect_ratio     a|1| aspect ratio of the image}"
				"{red 	           r|255| amount of red in the border}"
				"{green            g|255| amount of the green in the border}"
				"{blue             b|255| amount of blue in the border}");
  String imageName = parser.get<String>("@input");
  double min_bd_th = parser.get<double>("min_border_thick");
  double asp_ratio = parser.get<double>("aspect_ratio");
  int int_red = parser.get<int>("red");
  int int_green = parser.get<int>("green");
  int int_blue= parser.get<int>("blue");


  unsigned char red = static_cast<unsigned char>(int_red);
  unsigned char green = static_cast<unsigned char>(int_green);
  unsigned char blue = static_cast<unsigned char>(int_blue);
  // As usual we load our source image (src)
  src = imread( samples::findFile( imageName ), IMREAD_COLOR ); // Load an image
 
  if( src.empty() )
  {
    printf("Error opening image: %s\n", imageName.c_str());
    return EXIT_FAILURE;
  }
    // cout << "address of image" << &src << endl;
    disp_img(&src, min_bd_th, asp_ratio, red, green, blue);
    
    return 0;
}
