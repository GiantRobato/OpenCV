#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

	double alpha;	//Contrast control
	int beta;		//Brightness control

	Mat image = imread(argv[1]);

	//Uses the size and type of the input image to create an empty matrix with
	//The correct type and size
	Mat new_image = Mat::zeros(image.size(),image.type());

	cout << " Basic Linear Transforms " << endl;
	cout << "-------------------------" << endl;
	cout << "* Enter the alpha value [1.0 - 3.0]: " << endl;
	cin >> alpha;
	cout << "* Enter the beta value [0-100]" << endl;
	cin >> beta;

	//iterate through each pixel
	for(int x = 0; x < image.rows; x++){
		for(int y = 0; y < image.cols; y++){
			for(int c = 0; c < 3; c++){
				new_image.at<Vec3b>(x,y)[c] = saturate_cast<uchar>(alpha*( image.at<Vec3b>(x,y)[c]) + beta);
			}
		}
	}

	//Create displays
	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	//Show output
	imshow("Original Image", image);
	imshow("New Image", new_image);

	waitKey(0);
	return 0;

}
