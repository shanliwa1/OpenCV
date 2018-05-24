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

	int x  = img.cols / 2;
	int y = img.rows / 2;
	cv::Vec3b intensity = img.at< cv::Vec3b >( y,x ) ;
	std::cout<<"Blue: "<<(unsigned int)intensity[0]<<", Green: "<<(unsigned int)intensity[1]
		<<",Red: "<<(unsigned int)intensity[2]<<std::endl;

	
	return 0;
}
