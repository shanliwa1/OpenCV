#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>


int main( int argc ,char* argv[] )
{
	if( argc <= 1 )
	{
		std::cout<<"Usage: ./videoWriter argvv[1] "<<std::endl;
		return -1;
	}
	cv::namedWindow( "InputVideo", cv::WINDOW_AUTOSIZE );
	cv::namedWindow( "OutputVideo", cv::WINDOW_AUTOSIZE );

	cv::VideoCapture cap;
	cap.open( argv[1] );
	double fps = cap.get( cv::CAP_PROP_FPS );
	cv::Size size( (int)cap.get( cv::CAP_PROP_FRAME_WIDTH), 
	               (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT) ) ;
	
	cv::VideoWriter writer;
	writer.open( argv[2] ,CV_FOURCC('M','J','P','G'),fps,size);

	cv::Mat logpolar_frame ,bgr_frame;

	while( 1 )
	{
		cap >> bgr_frame;
		if( bgr_frame.empty() ) break;

		cv::imshow( "InputVideo", bgr_frame );

		cv::logPolar(
			bgr_frame,
			logpolar_frame,
			cv::Point2f( bgr_frame.cols/2 , bgr_frame.rows/2 ),
			40,
			cv::WARP_FILL_OUTLIERS
		);

		cv::imshow( "OutputVideo", logpolar_frame );
		writer<<logpolar_frame;

		char c = cv::waitKey( 10 ) ;
		if( c == 27 ) break;

	}
	cap.release() ;
	return 0;
}
