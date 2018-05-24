#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

void cannyDetect( cv::Mat &img )
{
	cv::namedWindow("Original",cv::WINDOW_AUTOSIZE );
	cv::namedWindow("Gray",cv::WINDOW_AUTOSIZE );
	cv::namedWindow("cannyDetect",cv::WINDOW_AUTOSIZE );

	cv::imshow( "Original",img );
	
	cv::Mat img_gray;
	cv::cvtColor( img, img_gray,cv::COLOR_BGR2GRAY );
	cv::imshow("Gray",img_gray );
	
	cv::Mat img_canny;
	cv::Canny( img_gray,img_canny,10,100,3,true );
	cv::imshow( "cannyDetect", img_canny ) ;
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

	cannyDetect( img );
	
	return 0;
}
