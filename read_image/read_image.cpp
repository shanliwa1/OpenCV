#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

int main( int argc ,char* argv[] )
{
	cv::Mat img = cv::imread( argv[1] , 1 );
	if( img.empty() )
	{
		std::cout<<"read image fail..."<<std::endl;
		return -1;
	}

	cv::namedWindow( "Exampe1" , cv::WINDOW_AUTOSIZE ) ;
	cv::imshow( "Example1" , img );
	cv::waitKey( 0 );
	cv::destroyWindow( "Example1");
	return 0;
}
