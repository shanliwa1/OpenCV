#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

void pyramid( cv::Mat &img )
{
	cv::namedWindow("Original",cv::WINDOW_AUTOSIZE );
	cv::namedWindow("pyramid",cv::WINDOW_AUTOSIZE );
	cv::imshow("Original",img);
	std::cout<<"The size of original image: "<<img.size()<<std::endl;

	cv::Mat py_img;
	cv::pyrDown( img, py_img );  // GaussinaBlur and pyramid
	cv::imshow("pyramid",py_img);
	std::cout<<"The size of after pyramid image: "<<py_img.size()<<std::endl;
	cv::waitKey( 0 );

}

int main( int argc ,char* argv[] )
{
	cv::Mat img = cv::imread( argv[1] , 1 );
	if( img.empty() )
	{
		std::cout<<"read image fail..."<<std::endl;
		return -1;
	}

	pyramid( img );
	
	return 0;
}
