#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
	VideoCapture capture;
	capture.open( 0 );
	if ( !capture.isOpened() ) {
		return 1;
	}
	Mat frame;
	Mat flip_frame;
	bool stop = false;
	while ( !stop ){
		capture >> frame;
		flip(frame, flip_frame, 1);
		imshow("capture", flip_frame);
		if ( waitKey(30) >= 0){
			stop = true;
		}
	}
	
	return 0;
}
