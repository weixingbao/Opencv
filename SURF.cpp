//#include <cv.h>
//#include <highgui.h>
//#include <stdlib.h>
////#pragma comment(lib,"opencv_core245.lib")
////#pragma comment(lib,"opencv_highgui245.lib")
//int main() {
//	//char* file[3] = { "1.jpg","2.jpg","3.jpg" };//3张原始图片    
//	IplImage* pImg[3];
//	int i;
//
//	//for (i = 0; i<3; ++i)
//	pImg[0] = cvLoadImage("1.jpg");
//	pImg[1] = cvLoadImage("2.jpg");
//	pImg[2] = cvLoadImage("3.jpg");
//	int sw = pImg[0]->width;
//	int sh = pImg[0]->height;
//	IplImage* dstImg = cvCreateImage(cvSize(sw * 3, sh), pImg[0]->depth, pImg[0]->nChannels);
//
//	cvZero(dstImg);
//	printf("Please wait...\n");
//
//	for (i = 0; i<3; ++i) {
//		cvSetImageROI(dstImg, cvRect(i*sw, 0, sw, sh));
//		cvCopy(pImg[i], dstImg);
//		cvResetImageROI(dstImg);
//	}
//
//	cvNamedWindow("dstImg");
//	cvShowImage("dstImg", dstImg);
//	cvSaveImage("result1.jpg", dstImg);//拼接图片之一    
//
//	cvWaitKey(0);
//
//	for (i = 0; i<3; ++i)
//		cvReleaseImage(&pImg[i]);
//
//	cvReleaseImage(&dstImg);
//	cvDestroyWindow("dstImg");
//	system("pause");
//	return 0;
//}