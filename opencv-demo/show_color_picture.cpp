#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
	Mat mat(300, 500, CV_8UC3, Scalar(255, 100, 0));
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("iamge", mat);
	cout << mat.channels() << endl;
	cout << mat.depth() << endl;
	waitKey(0);

	return 0;
}
