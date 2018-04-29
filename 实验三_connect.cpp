#include <iostream>
#include <opencv2/core/core.hpp>
#include <imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>

using namespace std;
using namespace cv;

void __copyto(Mat origin, Mat sur, Mat mask, CvPoint point);
void __copy(Mat origin, Mat sur, CvPoint point);
void __merge(vector<Mat> elephant, vector<Mat> mask, Mat result);
Mat mask_mat(Mat elephant);
Mat threshhold_segment(Mat img);

int main(int argc, char* argv[]) {
	int img_width = 0,img_height=690;
	CvPoint P; vector<Mat> elephant; vector<Mat> mask;
	P.x = P.y = 0;
	for (int i = 0; i < 8; i++) {
		elephant.push_back(imread(format("./result/elephant_%d.jpg", i), 1));
		mask.push_back(mask_mat(elephant[i]));
		img_width += elephant[i].cols;
		cout << elephant.size() <<' '<< elephant[i].rows<<' '<<elephant[i].cols<< endl;
	}
	Mat result( img_height,img_width, CV_8UC3,Scalar(255, 255, 255));
	__merge(elephant,mask,result);
	namedWindow("Image", 0);
	imshow("Image", result);
	waitKey();
	system("pause");
	return 0;
}

void __merge(vector<Mat> elephant, vector<Mat> mask,Mat result) {
	CvPoint P; int bound_l, bound_r; Rect rect;
	P.x = P.y = 0;
	for (int i = 0; i < 8; i++) {
		switch (i)
		{
		case 0:
			bound_l = 0; bound_r = 0;
			rect = Rect(bound_r, 0, elephant[i].cols - bound_r, elephant[i].rows);
			P.x -= bound_l;
			__copyto(result, elephant[i](rect), mask[i](rect), P);
			P.x += elephant[i].cols-bound_r;
			break;
		case 1:
			bound_l =8; bound_r = 11;
			rect = Rect(bound_r, 0, elephant[i].cols - bound_r, elephant[i].rows);
			P.x -= bound_l;
			__copyto(result, elephant[i](rect), mask[i](rect), P);
			P.x += elephant[i].cols - bound_r;
			break;
		case 2:
			bound_l = 17; bound_r = 30;
			rect = Rect(bound_r, 0, elephant[i].cols - bound_r, elephant[i].rows);
			P.x -= bound_l;
			__copyto(result, elephant[i](rect), mask[i](rect), P);
			P.x += elephant[i].cols - bound_r;
			break;
		case 3:
			bound_l = 15; bound_r = 3;
			rect = Rect(bound_r, 0, elephant[i].cols - bound_r, elephant[i].rows);
			P.x -= bound_l;
			__copyto(result, elephant[i](rect), mask[i](rect), P);
			P.x += elephant[i].cols - bound_r;
			break;
		case 4:
			bound_l = 20; bound_r = 20;
			rect = Rect(bound_r, 0, elephant[i].cols - bound_r, elephant[i].rows);
			P.x -= bound_l;
			__copyto(result, elephant[i](rect), mask[i](rect), P);
			P.x += elephant[i].cols - bound_r;
			break;
		case 5:
			bound_l = 15; bound_r = 10;
			rect = Rect(bound_r, 0, elephant[i].cols - bound_r, elephant[i].rows);
			P.x -= bound_l;
			__copyto(result, elephant[i](rect), mask[i](rect), P);
			P.x += elephant[i].cols - bound_r;
			break;
		case 6:
			bound_l = 6; bound_r = 21;
			rect = Rect(bound_r, 0, elephant[i].cols - bound_r, elephant[i].rows);
			P.x -= bound_l;
			__copyto(result, elephant[i](rect), mask[i](rect), P);
			P.x += elephant[i].cols - bound_r;
			break;
		case 7:
			bound_l = 9; bound_r = 13;
			rect = Rect(bound_r, 0, elephant[i].cols - bound_r, elephant[i].rows);
			P.x -= bound_l;
			__copyto(result, elephant[i](rect), mask[i](rect), P);
			P.x += elephant[i].cols - bound_r;
			break;
		default:
			break;
		}
	}
}
Mat mask_mat(Mat elephant) {
	Mat gra = threshhold_segment(elephant);
	Mat mask = Mat::zeros(gra.rows, gra.cols, CV_8UC1);
	int nr, nc;
	nr = elephant.rows; nc = elephant.cols;
	cout << "the rows cols of result:" << nr << ' ' << nc << endl;
	cout << "the rows cols of mask:" << mask.rows << ' ' << mask.cols << endl;
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			if (gra.at<uchar>(i, j) != 255) {
				//cout << "true"<<endl;
				elephant.at<Vec3b>(i, j)[0] = 0;
				elephant.at<Vec3b>(i, j)[1] = 0;
				elephant.at<Vec3b>(i, j)[2] = 0;
			}
			else {
				mask.at<uchar>(i, j) = 1;
				//cout << "false" << endl;
			}
		}
	}
	return mask;
}
void __copyto(Mat origin, Mat sur, Mat mask,CvPoint point) {
	cout << "the rows cols of sur:" << sur.rows << ' ' << sur.cols<<endl;
	cout << "the rows cols of mask:" << mask.rows << ' ' << mask.cols<<endl;
	cout << "the rows cols of origin:" << origin.rows << ' ' << origin.cols<<endl;
	int nr, nc;
	nr = sur.rows; nc = sur.cols;
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			if (mask.at<uchar>(i, j) == 1) {
				origin.at<Vec3b>(i + point.y, j + point.x)[0] = sur.at<Vec3b>(i, j)[0];
				origin.at<Vec3b>(i + point.y, j + point.x)[1] = sur.at<Vec3b>(i, j)[1];
				origin.at<Vec3b>(i + point.y, j + point.x)[2] = sur.at<Vec3b>(i, j)[2];
			}
		}
	}
}

void __copy(Mat origin, Mat sur, CvPoint point) {
	cout << "the rows cols of sur:" << sur.rows << ' ' << sur.cols << endl;
	cout << "the rows cols of origin:" << origin.rows << ' ' << origin.cols << endl;
	int nr, nc;
	nr = sur.rows; nc = sur.cols;
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
				origin.at<Vec3b>(i + point.y, j + point.x)[0] = sur.at<Vec3b>(i, j)[0];
				origin.at<Vec3b>(i + point.y, j + point.x)[1] = sur.at<Vec3b>(i, j)[1];
				origin.at<Vec3b>(i + point.y, j + point.x)[2] = sur.at<Vec3b>(i, j)[2];			
		}
	}
}

Mat threshhold_segment(Mat img) {
	Mat gray;
	cvtColor(img, gray, CV_RGB2GRAY);
	Mat dst, histogram_image;
	threshold(gray, dst, 200, 255, THRESH_BINARY_INV);
	return dst;
}