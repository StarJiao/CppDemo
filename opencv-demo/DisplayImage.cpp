#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* arg[]){
	if(argc != 3){
		cout<<"use: demo <image_path> <flag>[-1,0,1,2,4]\n"<<endl;
		return -1;
	}
	Mat img;
	//img = imread(arg[1] , CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
	img = imread(arg[1] , atoi(arg[2]));
	if(!img.data){
		cout<<"image no data"<<endl;
		return -1;
	}
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("img", img);

	imwrite("grey.jpg",img);

	waitKey(5000);

	return 0;

