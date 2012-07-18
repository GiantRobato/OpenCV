#include <cv.h>								//our Computer Vision library	
#include <highgui.h>						//Needed in order to create GUI elements

int main(int argc, char** argv){			//agrc gives us how many arguments we passed in and agrv gives us the actual arguments

	//we create a pointer called image and point it towards the image we gave as our first argument in the command line
	IplImage* img = cvLoadImage(argv[1]);	

	//This creates a GUI window which we can reference back to later by calling "MyWindow"
	cvNamedWindow("MyWindow");

	//cvShowImage (ironically enough) shows the image that we loaded in previously, into the GUI window we made called "MyWindow"
	cvShowImage("MyWindow", img);the indow 

	//cvWaitKey(0) means that the window will wait forever until any key is pressed
	cvWaitKey(0);

	//cvDestroyWindow takes in as an argument the string name of a window created by cvNamedWindow and destroys it
	cvDestroyWindow("MyWindow");

	//cvReleaseImage takes in a pointer to an image and frees it from memory. Now, we can reuse the img variable but you
	//can't use the image that we previously loaded in as an argument
	cvReleaseImage(&img);

	//ends the program
	return 0;
}
