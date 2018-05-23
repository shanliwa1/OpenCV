#include <iostream>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

int main( int argc , char *argv[] )
{
	cv::namedWindow( "Video", cv::WINDOW_AUTOSIZE );
	cv::VideoCapture cap;
	cap.open( std::string( argv[1] ) );

	cv::Mat frame;
	while( 1 )
	{
		cap >> frame;
		if( frame.empty() ) break;
		cv::imshow( "Video", frame) ;
		if( cv::waitKey( 30 ) >= 0 ) break;
	}
	return 0;
}
