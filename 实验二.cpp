#include<iostream>  
#include <opencv2/core/core.hpp>    
#include <opencv2/highgui/highgui.hpp> 
#include<imgproc/imgproc.hpp>  

using namespace std;
using namespace cv;

int main() {

	Mat image = cvLoadImage("animals.jpg");
	Mat grayImage;
	cvtColor(image, grayImage, CV_BGR2GRAY);
	//转换为二值图 
	Mat binaryImage;
	threshold(grayImage, binaryImage, 90, 255, CV_THRESH_BINARY);

	//二值图 这里进行了像素反转，因为一般我们用255白色表示前景（物体），用0黑色表示背景  
	Mat reverseBinaryImage;
	bitwise_not(binaryImage, reverseBinaryImage);
	namedWindow("image");
	imshow("image", reverseBinaryImage);

	vector <vector<Point>>contours;
	findContours(reverseBinaryImage,
		contours,	//轮廓的数组
		CV_RETR_EXTERNAL,	//获取外轮廓
		CV_CHAIN_APPROX_NONE);	//获取每个轮廓的每个像素
								//在白色图像上绘制黑色轮廓
	Mat result(reverseBinaryImage.size(), CV_8U, Scalar(255));
	drawContours(result, contours,
		-1,	//绘制所有轮廓
		Scalar(0),	//颜色为黑色
		2);	//轮廓线的绘制宽度为2

	namedWindow("contours");
	imshow("contours", result);

	//移除过长或过短的轮廓
	int cmin = 100;	//最小轮廓长度
	int cmax = 1000;	//最大轮廓
	vector<vector<Point>>::const_iterator itc = contours.begin();
	while (itc != contours.end())
	{
		if (itc->size() < cmin || itc->size() > cmax)
			itc = contours.erase(itc);
		else
			++itc;
	}

	//在白色图像上绘制黑色轮廓
	Mat result_erase(binaryImage.size(), CV_8U, Scalar(255));
	drawContours(result_erase, contours,
		-1,	//绘制所有轮廓
		Scalar(0),	//颜色为黑色
		2);	//轮廓线的绘制宽度为2

			//namedWindow("contours_erase");
			//imshow("contours_erase", result_erase);

			//测试包围盒
	Rect r0 = boundingRect(Mat(contours[0]));
	rectangle(result_erase, r0, Scalar(128), 2);
	Rect r1 = boundingRect(Mat(contours[1]));
	rectangle(result_erase, r1, Scalar(128), 2);

	//测试最小包围圆
	float radius;
	Point2f center;
	minEnclosingCircle(Mat(contours[2]), center, radius);
	circle(result_erase, Point(center), static_cast<int>(radius), Scalar(128), 2);

	//测试多边形近似
	vector <Point> poly;
	approxPolyDP(Mat(contours[3]),
		poly,
		5,	//近似的精确度
		true);	//这是个闭合形状

				//遍历每个片段进行绘制
	vector<Point>::const_iterator itp = poly.begin();
	while (itp != (poly.end() - 1))
	{
		line(result_erase, *itp, *(itp + 1), Scalar(128), 2);
		++itp;
	}

	//首尾用直线相连
	line(result_erase, *(poly.begin()), *(poly.end() - 1), Scalar(128), 2);

	//凸包是另一种多边形近似,计算凸包
	vector <Point> hull;
	convexHull(Mat(contours[4]), hull);

	vector<Point>::const_iterator ith = hull.begin();
	while (ith != (hull.end() - 1))
	{
		line(result_erase, *ith, *(ith + 1), Scalar(128), 2);
		++ith;
	}
	line(result_erase, *(hull.begin()), *(hull.end() - 1), Scalar(128), 2);

	//另一种强大的描述符力矩
	//测试力矩
	//遍历所有轮廓
	itc = contours.begin();
	while (itc != contours.end())
	{
		//计算所有的力矩
		Moments mom = moments(Mat(*itc++));
		//绘制质心
		circle(result_erase,
			Point(mom.m10 / mom.m00, mom.m01 / mom.m00),	//质心坐标转换为整数
			2,
			Scalar(0),
			2);	//绘制黑点
	}

	namedWindow("contours_erase");
	imshow("contours_erase", result_erase);
	waitKey(0);
	return 0;
}