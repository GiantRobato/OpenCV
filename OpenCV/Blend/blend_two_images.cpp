#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv){
	double alpha = 0.5;
	double beta;
	double input;

	//src1 and src2 are self-explainable
	//dst is the output image after cross dissolving the two images together
	Mat src1, src2, dst;

	//Asking user input
	std::cout << " Simple Linear Blender " << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "* Enter alpha [0-1]: ";
	std::cin >> input;

	if(input >= 0 && input <= 1){
		alpha = input;
	}

	src1 = imread("../../../images/LinuxLogo.jpg");
	src2 = imread("../../../images/WindowsLogo.jpg");

	//check for valid input
	if(!src1.data){
		std::cout << "Error loading src1 \n" << std::endl;;
		return -1;
	}
	if(!src2.data){
		std::cout << "Error loading src2 \n" << std::endl;
		return -1;
	}

	//Create the display window
	namedWindow("Linear Blend", 1);
	beta = (1.0 - alpha);

	
	addWeighted(src1, alpha, src2, beta, 0.0, dst);

	imshow("Linear Blend",dst);

	waitKey(0);
	return 0;
}
