//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/ml/ml.hpp>
//#include<cstring>
//#include "histogram.cpp"
//using namespace cv;
//using namespace std;
//Mat copy_tree(Mat img, Mat label);
//Mat threshhold_segment(Mat img);
//Mat Kmeans_segment(Mat img);
//void __copy(Mat origin, Mat sur, CvPoint point);
//Mat rectangle__(Mat img, CvPoint P_1, CvPoint P_2);
//void __copyto(Mat origin, Mat sur, Mat mask, CvPoint point);
//Mat __rectangle(Mat img, int x1, int y1, int x2, int y2);
//Mat _histogram(Mat img);
//Mat mask_mat(Mat elephant);
//CvPoint P1,P2,P3,P4,P5,P6,P7,P8,P0;
//
//int main(int argc, char* argv[])
//{
//	Mat img = imread("elephant.jpg"), img_rect,source=img.clone();
//	vector<Mat> elephant;
//	vector<Mat> mask;
//	P1.x = 60;
//	P1.y = 10;
//	P2.x = 160;
//	P2.y = 800;
//	//typedef BOOST_TYPEOF(*img.data) ElementType;
//	//输出图像信息，像素点查看
//	int tree_type;
//	cout << "the type of the image:" << img.type()<<endl;
//	cout << "channels："<<img.channels()<<"dims:"<<img.dims<<"rows:"<<img.rows<<"cols"<<img.cols << endl;
//	cout << "the img begin:" << img.begin<Vec3b>()[0]	 << ' ' << img.begin<Vec3b>()[1] << ' ' << img.begin<Vec3b>()[2] << endl;
//	cout << "the img[0][0]:" << (int)img.at<Vec3b>(0,0)[0] << ' ' << (int)img.at<Vec3b>(0, 0)[1] << ' ' << (int)img.at<Vec3b>(0, 0)[2] << endl;
//	cout << img.at<Vec3b>(0, 0);
//	//原图
//	namedWindow("Source Image", 0);
//	imshow("Source Image", img);
//	//histogram
//	Mat his = _histogram(img);
//	namedWindow("histogram", 1);
//	imshow("histogram", his);
//	//画框
//	Rect rect = Rect(0,0,0,0);
//	for (int i = 1; i <= 8; i++) {
//		switch (i)
//		{
//		case 1:
//			rect = Rect(60, 10, 160-60, 700-10);//100
//			elephant.push_back(img(rect).clone());
//			img = __rectangle(img, 60,10,160,700);
//		case 2:
//			rect = Rect(170, 10, 250-170, 700-10); //80
//			elephant.push_back(img(rect).clone());
//			img = __rectangle(img, 170,10,250,700);
//		case 3:
//			rect = Rect(260, 10, 380-260, 700-10);//120
//			elephant.push_back(img(rect).clone());
//			img = __rectangle(img, 260,10,380,700);
//		case 4:
//			rect = Rect(393, 10, 490-393, 700-10);//97
//			elephant.push_back(img(rect).clone());
//			img = __rectangle(img, 393,10,490,700);
//		case 5:
//			rect = Rect(502, 10, 580-502, 700-10);//78
//			elephant.push_back(img(rect).clone());
//			img = __rectangle(img, 502,10,580,700);
//		case 6:
//			rect = Rect(590, 10, 682-590, 700-10);//92
//			elephant.push_back(img(rect).clone());
//			img = __rectangle(img, 590,10,682,700);
//		case 7:
//			rect = Rect(695, 10, 795-695, 700-10);//100
//			elephant.push_back(img(rect).clone());
//			img = __rectangle(img,695,10,795,700);
//		case 8:
//			rect = Rect(800, 10, 903-800, 700-10);//103
//			elephant.push_back(img(rect).clone());
//			img = __rectangle(img, 800,10,903,700);
//		default:
//			break;
//		}
//	}
//	namedWindow("Image", 2);
//	imshow("Image", img);
//	//复制存储图像
//	int img_width = 103 + 100 + 92 + 78 + 97 + 120 + 80 + 100,img_height=690;
//	Mat result = Mat::zeros( img_height,img_width, CV_8UC3);
//	CvPoint P;
//	P.x = P.y = 0;__copy(result, elephant[4], P); imwrite(format("./result/elephant_0.jpg"), elephant[4]); mask.push_back(mask_mat(elephant[4]));
//	P.x = 78; __copy(result, elephant[0], P); imwrite(format("./result/elephant_1.jpg"), elephant[0]); mask.push_back(mask_mat(elephant[0]));
//	P.x = 178; __copy(result, elephant[7], P); imwrite(format("./result/elephant_2.jpg"), elephant[7]); mask.push_back(mask_mat(elephant[7]));
//	P.x = 178+103; __copy(result, elephant[2], P); imwrite(format("./result/elephant_3.jpg"), elephant[2]); mask.push_back(mask_mat(elephant[2]));
//	P.x = 178 + 103+120; __copy(result, elephant[5], P); imwrite(format("./result/elephant_4.jpg"), elephant[5]); mask.push_back(mask_mat(elephant[4]));
//	P.x = 178 + 103 + 120+92; __copy(result, elephant[3],P); imwrite(format("./result/elephant_5.jpg"), elephant[3]); mask.push_back(mask_mat(elephant[3]));
//	P.x = 178 + 103 + 120 + 92 + 97; __copy(result, elephant[6], P); imwrite(format("./result/elephant_6.jpg"), elephant[6]); mask.push_back(mask_mat(elephant[6]));
//	P.x = 178 + 103 + 120 + 92 + 97 + 100; __copy(result, elephant[1], P); imwrite(format("./result/elephant_7.jpg"), elephant[1]); mask.push_back(mask_mat(elephant[1]));
//	namedWindow("result", 3);
//	imshow("result", result);
//	
//
//
//	namedWindow("tr", 5);
//	imshow("tr", elephant[1]);
//
//	waitKey();
//	return 0;
//}
////-----------------------------------------------------------------------------------------------------
//
//Mat __merge(vector<Mat> elephant, vector<Mat> mask) {
//	int img_width = 103 + 100 + 92 + 78 + 97 + 120 + 80 + 100, img_height = 690,bound=0;
//	CvPoint P;
//	P.x = P.y = 0;
//	Mat result = Mat::zeros(img_height, img_width, CV_8UC3);
//	for (int i = 0; i < 8; i++) {
//		switch (i)
//		{
//		case 1:
//			bound = 0;
//			P.x -= bound;
//			//__copyto(result,elephant[])
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//
//
//
//Mat mask_mat(Mat elephant) {
//	Mat gra = threshhold_segment(elephant);
//	Mat mask = Mat::zeros(gra.rows,gra.cols, CV_8UC1);
//	int nr, nc;
//	nr = elephant.rows; nc = elephant.cols;
//	cout << "the rows cols of result:" << nr << ' ' << nc<<endl;
//	cout << "the rows cols of mask:" << mask.rows << ' ' << mask.cols<<endl;
//	for (int i = 0; i < nr; i++) {
//		for (int j = 0; j < nc; j++) {
//			if (gra.at<uchar>(i, j) != 255) {
//				//cout << "true"<<endl;
//				elephant.at<Vec3b>(i, j)[0] = 0;
//				elephant.at<Vec3b>(i, j)[1] = 0;
//				elephant.at<Vec3b>(i, j)[2] = 0;
//			}
//			else {
//				mask.at<uchar>(i, j) = 1;
//				//cout << "false" << endl;
//			}
//		}
//	}
//	return mask;
//}
//
//void __copyto(Mat origin, Mat sur, Mat mask,CvPoint point) {
//	cout << "the rows cols of sur:" << sur.rows << ' ' << sur.cols<<endl;
//	cout << "the rows cols of mask:" << mask.rows << ' ' << mask.cols<<endl;
//	cout << "the rows cols of origin:" << origin.rows << ' ' << origin.cols<<endl;
//	int nr, nc;
//	nr = sur.rows; nc = sur.cols;
//	for (int i = 0; i < nr; i++) {
//		for (int j = 0; j < nc; j++) {
//			if (mask.at<uchar>(i, j) == 1) {
//				origin.at<Vec3b>(i + point.y, j + point.x)[0] = sur.at<Vec3b>(i, j)[0];
//				origin.at<Vec3b>(i + point.y, j + point.x)[1] = sur.at<Vec3b>(i, j)[1];
//				origin.at<Vec3b>(i + point.y, j + point.x)[2] = sur.at<Vec3b>(i, j)[2];
//			}
//		}
//	}
//}
//
//void __copy(Mat origin, Mat sur, CvPoint point) {
//	cout << "the rows cols of sur:" << sur.rows << ' ' << sur.cols << endl;
//	cout << "the rows cols of origin:" << origin.rows << ' ' << origin.cols << endl;
//	int nr, nc;
//	nr = sur.rows; nc = sur.cols;
//	for (int i = 0; i < nr; i++) {
//		for (int j = 0; j < nc; j++) {
//				origin.at<Vec3b>(i + point.y, j + point.x)[0] = sur.at<Vec3b>(i, j)[0];
//				origin.at<Vec3b>(i + point.y, j + point.x)[1] = sur.at<Vec3b>(i, j)[1];
//				origin.at<Vec3b>(i + point.y, j + point.x)[2] = sur.at<Vec3b>(i, j)[2];			
//		}
//	}
//}
//
//Mat rectangle__(Mat img, CvPoint P_1, CvPoint P_2) {
//	Mat origin = img.clone();
//	Scalar value;
//	rectangle(origin, P_1, P_2, Scalar(0, 0, 255), 1, 1, 0);
//	return origin;
//}
//Mat __rectangle(Mat img, int x1,int y1,int x2,int y2) {
//	Mat origin = img.clone();
//	Scalar value;
//	CvPoint P_1, P_2;
//	P_1.x = x1; P_1.y = y1;
//	P_2.x = x2; P_2.y = y2;
//	rectangle(origin, P_1, P_2, Scalar(66, 66, 66), 1, 1, 0);
//	return origin;
//}
//Mat threshhold_segment(Mat img) {
//	Mat gray;
//	cvtColor(img, gray, CV_RGB2GRAY);
//	Mat dst, histogram_image;
//	threshold(gray, dst, 200, 255, THRESH_BINARY_INV);
//	return dst;
//}
//Mat _histogram(Mat img) {
//	Histogram h;
//	Mat dst, histogram_image;
//	dst = img.clone();
//	histogram_image = h.getHistogramImage(dst);
//	return histogram_image;
//}
//Mat Kmeans_segment(Mat img) {
//	Mat samples(img.cols*img.rows, 1, CV_32FC3);
//	//标记矩阵，32位整形 
//	Mat labels(img.cols*img.rows, 1, CV_32SC1);
//	uchar* p;
//	int i, j, k = 0;
//	for (i = 0; i < img.rows; i++)
//	{
//		p = img.ptr<uchar>(i);
//		for (j = 0; j< img.cols; j++)
//		{
//			samples.at<Vec3f>(k, 0)[0] = float(p[j * 3]);
//			samples.at<Vec3f>(k, 0)[1] = float(p[j * 3 + 1]);
//			samples.at<Vec3f>(k, 0)[2] = float(p[j * 3 + 2]);
//			k++;
//		}
//	}
//
//	int clusterCount = 3;
//	Mat centers(clusterCount, 1, samples.type());
//	kmeans(samples, clusterCount, labels,
//		TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0),
//		3, KMEANS_PP_CENTERS, centers);
//	//我们已知有3个聚类，用不同的灰度层表示。 
//	Mat img1(img.rows, img.cols, CV_8UC1);
//	float step = 255 / (clusterCount - 1);
//	k = 0;
//	for (i = 0; i < img1.rows; i++)
//	{
//		int tt;
//		p = img1.ptr<uchar>(i);
//		for (j = 0; j< img1.cols; j++)
//		{
//			tt = labels.at<int>(k, 0);
//			k++;
//			p[j] = 255 - tt*step;
//			//cout << float(p[j])<<"     " << tt << endl;
//		}
//		//cout << float(p[0]) << "     " << tt << endl;
//	}
//	return img1;
//}