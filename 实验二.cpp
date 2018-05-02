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
	//ת��Ϊ��ֵͼ 
	Mat binaryImage;
	threshold(grayImage, binaryImage, 90, 255, CV_THRESH_BINARY);

	//��ֵͼ ������������ط�ת����Ϊһ��������255��ɫ��ʾǰ�������壩����0��ɫ��ʾ����  
	Mat reverseBinaryImage;
	bitwise_not(binaryImage, reverseBinaryImage);
	namedWindow("image");
	imshow("image", reverseBinaryImage);

	vector <vector<Point>>contours;
	findContours(reverseBinaryImage,
		contours,	//����������
		CV_RETR_EXTERNAL,	//��ȡ������
		CV_CHAIN_APPROX_NONE);	//��ȡÿ��������ÿ������
								//�ڰ�ɫͼ���ϻ��ƺ�ɫ����
	Mat result(reverseBinaryImage.size(), CV_8U, Scalar(255));
	drawContours(result, contours,
		-1,	//������������
		Scalar(0),	//��ɫΪ��ɫ
		2);	//�����ߵĻ��ƿ��Ϊ2

	namedWindow("contours");
	imshow("contours", result);

	//�Ƴ���������̵�����
	int cmin = 100;	//��С��������
	int cmax = 1000;	//�������
	vector<vector<Point>>::const_iterator itc = contours.begin();
	while (itc != contours.end())
	{
		if (itc->size() < cmin || itc->size() > cmax)
			itc = contours.erase(itc);
		else
			++itc;
	}

	//�ڰ�ɫͼ���ϻ��ƺ�ɫ����
	Mat result_erase(binaryImage.size(), CV_8U, Scalar(255));
	drawContours(result_erase, contours,
		-1,	//������������
		Scalar(0),	//��ɫΪ��ɫ
		2);	//�����ߵĻ��ƿ��Ϊ2

			//namedWindow("contours_erase");
			//imshow("contours_erase", result_erase);

			//���԰�Χ��
	Rect r0 = boundingRect(Mat(contours[0]));
	rectangle(result_erase, r0, Scalar(128), 2);
	Rect r1 = boundingRect(Mat(contours[1]));
	rectangle(result_erase, r1, Scalar(128), 2);

	//������С��ΧԲ
	float radius;
	Point2f center;
	minEnclosingCircle(Mat(contours[2]), center, radius);
	circle(result_erase, Point(center), static_cast<int>(radius), Scalar(128), 2);

	//���Զ���ν���
	vector <Point> poly;
	approxPolyDP(Mat(contours[3]),
		poly,
		5,	//���Ƶľ�ȷ��
		true);	//���Ǹ��պ���״

				//����ÿ��Ƭ�ν��л���
	vector<Point>::const_iterator itp = poly.begin();
	while (itp != (poly.end() - 1))
	{
		line(result_erase, *itp, *(itp + 1), Scalar(128), 2);
		++itp;
	}

	//��β��ֱ������
	line(result_erase, *(poly.begin()), *(poly.end() - 1), Scalar(128), 2);

	//͹������һ�ֶ���ν���,����͹��
	vector <Point> hull;
	convexHull(Mat(contours[4]), hull);

	vector<Point>::const_iterator ith = hull.begin();
	while (ith != (hull.end() - 1))
	{
		line(result_erase, *ith, *(ith + 1), Scalar(128), 2);
		++ith;
	}
	line(result_erase, *(hull.begin()), *(hull.end() - 1), Scalar(128), 2);

	//��һ��ǿ�������������
	//��������
	//������������
	itc = contours.begin();
	while (itc != contours.end())
	{
		//�������е�����
		Moments mom = moments(Mat(*itc++));
		//��������
		circle(result_erase,
			Point(mom.m10 / mom.m00, mom.m01 / mom.m00),	//��������ת��Ϊ����
			2,
			Scalar(0),
			2);	//���ƺڵ�
	}

	namedWindow("contours_erase");
	imshow("contours_erase", result_erase);
	waitKey(0);
	return 0;
}