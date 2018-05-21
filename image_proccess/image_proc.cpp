// C++
#include <iostream>
using namespace std;

// OpenCV
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

int main(int argc ,char** argv)
{
	Mat img = imread("./image1.jpg",IMREAD_COLOR);
	if( img.empty() )
	{
		cout<<"read image1 fail!"<<endl;
		return -1;
	}
	namedWindow("image1",WINDOW_AUTOSIZE);
	imshow("image1",img);
	waitKey(0);
	return 0;
}
