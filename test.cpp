//#include<opencv2/core/core.hpp>  
//#include<opencv2/highgui/highgui.hpp>  
//#include <opencv2/imgproc/imgproc.hpp>  
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//void __copyto(Mat origin, Mat sur, Mat mask, CvPoint point);
//CvPoint p;
//void main()
//	{
//	p.x = 100;
//	p.y = 100;
//	Mat srcImage1 = imread("1.png");  //source的意思
//	Mat logoImage = imread("2.png");
//
//	if (!srcImage1.data)
//	{
//		std::cout << "读入图片失败" << std::endl;
//		system("pause");
//		return;
//	}
//	if (!logoImage.data)
//	{
//		std::cout << "读入图片失败" << std::endl;
//		system("pause");
//		return;
//	}
//	//Mat imageROI = srcImage1(Rect(0, 0, logoImage.cols, logoImage.rows));
//	//Mat mask = imread("2.png", 1);
//	Mat mask = Mat::ones(logoImage.rows, logoImage.cols, CV_8UC1);
//	//logoImage.copyTo(imageROI, mask);
//	//logoImage.copyTo(imageROI);
//
//	__copyto(srcImage1, logoImage, mask, p);
//
//	namedWindow("效果图",0);
//	imshow("效果图", srcImage1);
//	waitKey();
//
//}
//
//void __copyto(Mat origin, Mat sur, Mat mask, CvPoint point) {
//	int nr, nc;
//	nr = sur.rows; nc = sur.cols;
//
//	cout << "hello"<<endl;
//	cout << "the sur nr nc is " << nr << nc<<endl;
//	for (int i = 0; i < nr; i++) {
//		for (int j = 0; j < nc; j++) {
//			//cout << mask.at<uchar>(i, j);
//			if (mask.at<uchar>(i, j) == 1) {
//				//mask.at<uchar>(i, j) = 1;
//				//cout << origin.at<Vec3b>(i + point.y, j + point.x);
//				origin.at<Vec3b>(i + point.y, j + point.x)[0] = sur.at<Vec3b>(i , j)[0];
//				origin.at<Vec3b>(i + point.y, j + point.x)[1] = sur.at<Vec3b>(i , j)[1];
//				origin.at<Vec3b>(i + point.y, j + point.x)[2] = sur.at<Vec3b>(i , j)[2];
//				//cout<<origin.at<Vec3b>(i + point.y, j + point.x)[0] <<"       "<< sur.at<Vec3b>(i + point.y, j + point.x)[0]<<endl;
//			}
//		}
//	}
//	cout << "finished";
//}