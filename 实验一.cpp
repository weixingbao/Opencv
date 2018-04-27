//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/ml/ml.hpp>
//
//using namespace cv;
//using namespace std;
//Mat copy_tree(Mat img, Mat label);
//Mat threshhold_segment(Mat img);
//Mat Kmeans_segment(Mat img);
//Mat rectangle(Mat img);
//void __copyto(Mat origin, Mat sur, Mat mask, CvPoint point);
//CvPoint P1, P2,P3;
//
//int main(int argc, char* argv[])
//{
//	Mat img = imread("tree.jpg");
//	P1.x = 540;
//	P1.y = 195;
//	P2.x = 810;
//	P2.y = 508;
//	P3.x = 200;
//	P3.y = 195;
//	//typedef BOOST_TYPEOF(*img.data) ElementType;
//	//输出图像信息，像素点查看
//	int tree_type;
//	cout << "the type of the tree:" << img.type()<<endl;
//	cout << "channels："<<img.channels()<<"dims:"<<img.dims<<"rows:"<<img.rows<<"cols"<<img.cols << endl;
//	cout << "the img[700][400]:" << img.begin<Vec3b>()[0]	 << ' ' << img.begin<Vec3b>()[1] << ' ' << img.begin<Vec3b>()[2] << endl;
//	cout << "the img[700][400]:" << (int)img.at<Vec3b>(0,0)[0] << ' ' << (int)img.at<Vec3b>(0, 0)[1] << ' ' << (int)img.at<Vec3b>(0, 0)[2] << endl;
//	cout << img.at<Vec3b>(0, 0);
//	namedWindow("Source Image", 0);
//	imshow("Source Image", img);
//	//阈值分割
//	Mat dst = threshhold_segment(img);
//	namedWindow("dst Image", 1);
//	imshow("dst Image", dst);
//	//Kmeans分割
//	Mat img1 = rectangle(Kmeans_segment(img));
//	namedWindow("K-Means分割效果", 2);
//	imshow("K-Means分割效果", img1);
//	//copy tree and move '
//	Mat result = copy_tree(img, img1);
//	namedWindow("copy效果", 3);
//	imshow("copy效果", result);
//
//	
//	//namedWindow("copy效果", 0);
//	//imshow("copy效果", img);
//	waitKey();
//	return 0;
//}
//
//Mat copy_tree(Mat img, Mat label) {
//	Mat origin = img.clone();
//	Rect rect = Rect(P1.x, P1.y, P2.x-P1.x, P2.y-P1.y);
//	//reuslt是彩色 copy是灰度
//	Mat result = origin(rect).clone();
//	Mat copy = label(rect).clone();
//	Mat mask = Mat::zeros(copy.rows,copy.cols, CV_8UC1);
//
//	int nr, nc;
//	nr = result.rows; nc = result.cols;
//	cout << "the rows cols of result:" << nr << ' ' << nc<<endl;
//	cout << "the rows cols of mask:" << mask.rows << ' ' << mask.cols<<endl;
//	for (int i = 0; i < nr; i++) {
//		for (int j = 0; j < nc; j++) {
//			if (copy.at<uchar>(i, j) != 255) {
//				result.at<Vec3b>(i, j)[0] = 0;
//				result.at<Vec3b>(i, j)[1] = 0;
//				result.at<Vec3b>(i, j)[2] = 0;
//			}
//			else
//				mask.at<uchar>(i, j) = 1;
//		}
//	}
//	cout << "copyto"<<endl;
//	//将result复制到origin
//	__copyto(origin, result, mask, P3);
//	return origin;
//
//}
//void __copyto(Mat origin, Mat sur, Mat mask,CvPoint point) {
//	cout << "the rows cols of sur:" << sur.rows << ' ' << sur.cols<<endl;
//	cout << "the rows cols of mask:" << mask.rows << ' ' << mask.cols<<endl;
//	cout << "the rows cols of origin:" << origin.rows << ' ' << origin.cols<<endl;
//	int nr, nc;
//	nr = sur.rows; nc = sur.cols;
//	for (int i = 0; i < nr; i++) {
//		for (int j = 0; j < nc; j++) {
//			if (mask.at<uchar>(i, j) == 1) {
//				//mask.at<uchar>(i, j) = 1;
//				//cout << origin.at<Vec3b>(i + point.y, j + point.x);
//				origin.at<Vec3b>(i + point.y, j + point.x)[0] = sur.at<Vec3b>(i, j)[0];
//				origin.at<Vec3b>(i + point.y, j + point.x)[1] = sur.at<Vec3b>(i, j)[1];
//				origin.at<Vec3b>(i + point.y, j + point.x)[2] = sur.at<Vec3b>(i, j)[2];
//			}
//		}
//	}
//}
//
//Mat rectangle(Mat img) {
//	Mat origin = img.clone();
//	Scalar value;
//	rectangle(origin, P1, P2, Scalar(66, 66, 66), 1, 1, 0);
//	return origin;
//}
//Mat threshhold_segment(Mat img) {
//	Mat gray;
//	cvtColor(img, gray, CV_RGB2GRAY);
//	Mat dst;
//	threshold(gray, dst, 60, 255, THRESH_BINARY_INV);
//	return dst;
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