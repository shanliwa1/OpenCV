// C++
#include <iostream>
using namespace std;

//OpenCV
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;


int main( int argc ,char **argv )
{
	Mat img_cell = imread( argv[1] ,0 );
	if( img_cell.empty() )
	{
		cout<<"image loaded fail.."<<endl;
		return -1;
	}

	namedWindow("img_cell",WINDOW_AUTOSIZE );
	imshow( "img_cell",img_cell );

	// laplacian transformation
	Mat img_lap;
	Laplacian( img_cell,img_lap,CV_32F,3) ;
	namedWindow("Laplacian" ,WINDOW_AUTOSIZE );
	imshow( "Laplacian",img_lap );
	
	// median filter
	Mat img_med;
	medianBlur( img_lap, img_med ,3 );
	namedWindow("medi",WINDOW_AUTOSIZE ) ;
	imshow( "medi",img_med ) ;

	//threshold
	Mat img_thre;
	threshold( img_cell ,img_thre,90,255,THRESH_BINARY );
	namedWindow("Threshold",WINDOW_AUTOSIZE);
	imshow("Threshold",img_thre);

	//Open operate
	Mat img_open;
	Mat ele = Mat::ones(Size(2,3),img_thre.type()  ) ;
	morphologyEx( img_thre,img_open,2,ele );
	namedWindow("Open",WINDOW_AUTOSIZE );
	imshow("Open",img_open);

	// find contours
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	Mat img_canny;
	Canny( img_open,img_canny,120,120*2 );
	namedWindow("Canny",WINDOW_AUTOSIZE );
	imshow("Canny",img_canny);
	
	vector<Vec3f> houghCir ;
	HoughCircles( img_canny,houghCir,HOUGH_GRADIENT,3,2);
	cout<<"cells is "<<houghCir.size()<<endl;

	Mat gauDown;
	pyrDown(img_canny,gauDown );
	namedWindow("Gaussian",WINDOW_AUTOSIZE );
	imshow("Gaussian",gauDown);

	Mat lapUp;
	pyrUp( img_canny,lapUp);
	namedWindow("lapUp",WINDOW_AUTOSIZE);
	imshow("lapUp",lapUp);

	findContours( img_canny,
				  contours,
				  hierarchy,
				  RETR_TREE,
				  CHAIN_APPROX_SIMPLE,
				  Point(0,0));
	cout<<"This picture contains: "<<contours.size()<<" cells."<<endl;
	char c = waitKey( 0 );


	return 0;
}

