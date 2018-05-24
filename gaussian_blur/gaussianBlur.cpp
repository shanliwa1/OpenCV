#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

void gaussianBlur( cv::Mat & img )
{
	cv::namedWindow("original Image",cv::WINDOW_AUTOSIZE );
	cv::namedWindow("GaussianBlur",cv::WINDOW_AUTOSIZE );

	cv::imshow("original Image",img );
	cv::Mat out;
	cv::GaussianBlur( img,out,cv::Size(5,5),3,3);
	cv::GaussianBlur( out,out,cv::Size(5,5),3,3);

	cv::imshow( "GaussianBlur" , out );
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

	gaussianBlur( img );
	
	return 0;
}
