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
cv::Mat src, dst;
double min_bd_th = 0.05;
double asp_ratio = 0.8;
double inv_asp_ratio = (1/asp_ratio);
//int bc
int top;
int bottom;
int right;
int left;
//cv::Scalar value;

// void disp_img(std::string file_name){
    
//     // int right, left;

//     src = cv::imread(file_name);
    
//     if (src.empty())
//     {
//      std::cout << "Could not open or find the image" << std::endl;
//      std::cin.get(); //wait for any key press
    
//     }
    
//     if(src.rows > src.cols){
//         top = min_bd_th*src.rows;
//         bottom = top;
//         right = ((2*top + src.rows)*inv_asp_ratio - src.cols)*0.5;
//         right = left;
//     } else if (src.rows < src.cols){
//         right = min_bd_th*src.cols;
//         left = right;
//         top =((2*right +src.cols)*asp_ratio - src.rows)*0.5;
//         bottom = top;
//     }else{
//         top = 0.05*src.rows;
//         bottom = top;
//         right =((2*min_bd_th+1)*src.rows*inv_asp_ratio - src.rows)*0.5;
//     }
    
//     cv::Scalar value(0, 0, 0);
    
//     cv::copyMakeBorder(src, dst, top, bottom, right, left, cv::BORDER_CONSTANT, value);
//     cv::String windowName = "The Guitar"; //Name of the window

//     cv::namedWindow(windowName); // Create a window

//     cv::imshow(windowName, dst); // Show our image inside the created window.

//     cv::waitKey(0); // Wait for any keystroke in the window

//     cv::destroyWindow(windowName); //destroy the created window
// }


int main(int argc, char** argv){

  cv::CommandLineParser parser(argc, argv,
                               "{@input   |lena.jpg|input image}");

  String imageName = parser.get<String>("@input");
  // As usual we load our source image (src)
  src = imread( samples::findFile( imageName ), IMREAD_COLOR ); // Load an image
 
  // Check if image is loaded fine
  if( src.empty() )
  {
    printf("Error opening image: %s\n", imageName.c_str());
    return EXIT_FAILURE;
  }



    // src = cv::imread("/Users/danyalsiddiqui/test_scripts/Test2_img.jpg");
    
    // if (src.empty())
    // {
    //  std::cout << "Could not open or find the image" << std::endl;
    //  std::cin.get(); //wait for any key press
    //     return -1;
    // }

    
    // Check for failure
    // if (src.empty())
    // {
    //  std::cout << "Could not open or find the image" << std::endl;
    //  std::cin.get(); //wait for any key press
    //     return -1;
    // }

    
    
    cv::Scalar value(255, 255, 255);
    
    int right, left;
    
    if(src.rows > src.cols){
        top = min_bd_th*src.rows;
        bottom = top;
        right = ((2*top + src.rows)*inv_asp_ratio - src.cols)*0.5;
        right = left;
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
    
    std::cout << top ;
    
    cv::copyMakeBorder(src, dst, top, bottom, right, left, cv::BORDER_CONSTANT, value);
    cv::String windowName = "The Guitar"; //Name of the window

    cv::namedWindow(windowName); // Create a window

    cv::imshow(windowName, dst); // Show our image inside the created window.

    cv::waitKey(0); // Wait for any keystroke in the window

    cv::destroyWindow(windowName); //destroy the created window

    // std::string f_name = "/Users/danyalsiddiqui/test_scripts/Test2_img.jpg";
    
    // disp_img(f_name);
    
    
    return 0;
}
