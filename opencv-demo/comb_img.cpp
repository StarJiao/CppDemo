#include<opencv2/opencv.hpp>

using namespace cv;

int main( )
{
	//-----------------------------------【二、初级图像混合】--------------------------------------
	//     描述：二、初级图像混合
	//-----------------------------------------------------------------------------------------------
	//载入图片
	Mat image = imread("test.png");
	Mat logo = imread("timg.jpg");

	//载入后先显示
	namedWindow("source", WINDOW_AUTOSIZE);
	imshow("source", image);

	namedWindow("logo", WINDOW_AUTOSIZE);
	imshow("logo", logo);

	//定义一个Mat类型，用于存放，图像的ROI
	Mat imageROI;
	//方法一
	imageROI = image(Rect(500, 640, logo.cols, logo.rows));
	//方法二
	//imageROI=image(Range(350,350+logo.rows),Range(800,800+logo.cols));

	//将logo加到原图上
	addWeighted(imageROI, 0.7, logo, 0.4 ,0.0, imageROI);

	//显示结果
	namedWindow("comb");
	imshow("comb",image);

	//-----------------------------------【三、图像的输出】--------------------------------------
	//     描述：将一个Mat图像输出到图像文件
	//-----------------------------------------------------------------------------------------------
	//输出一张jpg图片到工程目录下
	imwrite("comb.jpg",image);

	waitKey();

	return 0;
}
