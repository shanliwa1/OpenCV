#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <fstream>

int g_slider_position = 0;
int g_run = 1,g_dontset = 0;
cv::VideoCapture g_cap;

void onTrackbarSlide( int pos ,void *)
{
	g_cap.set( cv::CAP_PROP_POS_FRAMES,pos);
	if( !g_dontset )
		g_run = 1;
	g_dontset = 0;
}

int main( int argc ,char* argv[] )
{
	cv::namedWindow("Video",cv::WINDOW_AUTOSIZE) ;
	g_cap.open( std::string( argv[1] ) );
	int frames = (int) g_cap.get( cv::CAP_PROP_FRAME_COUNT );
	int tmpw = (int)g_cap.get( cv::CAP_PROP_FRAME_WIDTH );
	int tmph = (int)g_cap.get( cv::CAP_PROP_FRAME_HEIGHT );
	std::cout<<"Vedio has: "<<frames<<" frames of dimensions( "<<tmpw<<","<<tmph
		<<")."<<std::endl;
	
	cv::createTrackbar( "Position","Video",&g_slider_position,frames,onTrackbarSlide);

	cv::Mat frame;

	while(1)
	{
		if( g_run != 0 )
		{
			g_cap >> frame; if( frame.empty() ) break;
			int current_pos = (int)g_cap.get( cv::CAP_PROP_POS_FRAMES );
			g_dontset=1;

			cv::setTrackbarPos( "Position" ,"Video",current_pos);
			cv::imshow( "Video",frame);
			g_run -= 1;
		}
		char c = (char)cv::waitKey(10);
		if( c == 's') 
		{
			g_run =1 ;
			std::cout<<"Run,mode,run = "<<g_run<<std::endl;
		}

		if( c == 'r' )
		{
			g_run = -1;
			std::cout<<"Run mode,run = "<<g_run<<std::endl;
		}

		if( c == 27 )
		{
			break;
		}
	}
	return 0;
}
