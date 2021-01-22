#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace cv;
int g_MedianBlurValue = 10;

//����ͼ��
Mat img, kernel;
//��һ��ͼ��
Mat bgr;
//HLSͼ��
Mat hls;
//ɫ��
int hmin = 0;
int hmin_Max = 360;
int hmax = 355;
int hmax_Max = 360;
//����
int lmin = 160;
int lmin_Max = 255;
int lmax = 255;
int lmax_Max = 255;
//���Ͷ�
int smin = 0;
int smin_Max = 255;
int smax = 105;
int smax_Max = 255;
//��ʾԭͼ�Ĵ���
string windowName = "src";
//��ɫ����
string dstName = "dst";
Mat dst;//���ͼ��

void callBack(int, void*)
{
	//���ͼ��
	dst = Mat::zeros(bgr.size(), CV_32FC3);
	//����
	Mat mask;
	inRange(hls, Scalar(hmin, lmin / float(lmin_Max), smin / float(smin_Max)), Scalar(hmax, lmax / float(lmax_Max), smax / float(smax_Max)), mask);
	for (int r = 0; r < bgr.rows; r++)
	{
		for (int c = 0; c < bgr.cols; c++)
		{
			if (mask.at<uchar>(r, c) == 255)
			{
				dst.at<Vec3f>(r, c) = bgr.at<Vec3f>(r, c);
			}
		}
	}
	//���ͼ��
	imshow(dstName, dst);
	//�������ͼ��
	//��������ת��
	dst.convertTo(dst, CV_8UC3, 255, 0);
	imwrite("dst.jpg", dst);
}

void HLS(int, void*)
{
	imshow(windowName, img);
	img.convertTo(bgr, CV_32FC3, 1.0 / 255, 0);
	//��ɫ�ռ�ת��
	cvtColor(bgr, hls, COLOR_BGR2HLS);
	//���ͼ��
	namedWindow(dstName, WINDOW_GUI_EXPANDED);
	//ɫ��
	createTrackbar("hmin", dstName, &hmin, hmin_Max, callBack);
	createTrackbar("hmax", dstName, &hmax, hmax_Max, callBack);
	//����
	createTrackbar("lmin", dstName, &lmin, lmin_Max, callBack);
	createTrackbar("lmax", dstName, &lmax, lmax_Max, callBack);
	//���Ͷ�
	createTrackbar("smin", dstName, &smin, smin_Max, callBack);
	createTrackbar("smax", dstName, &smax, smax_Max, callBack);
}


void on_MedianBlur(int, void*)
{

	Mat g_dstImage, grayImage, dstImage, result, dstImage1;

	grayImage = g_dstImage.clone();
	cvtColor(dst, grayImage, COLOR_BGR2GRAY);
	threshold(grayImage, result, 40, 40, THRESH_BINARY);
	imshow("��ֵ", result);

	kernel = getStructuringElement(MORPH_RECT, Size(2, 2));
	Mat out;
	erode(result, out, kernel, Point(-1, -1), 3);

	dstImage = out.clone();
	medianBlur(out, dstImage, g_MedianBlurValue * 2 + 1);
	imshow("����ֵ�˲���", dstImage);

	inRange(dstImage, Scalar(40, 43, 35), Scalar(195, 165, 185), dstImage1);
	imshow("������inRange()����ʵ����ֵ����", dstImage1);

}


int main(int argc, char* argv[])
{
	//����ͼ��
	img = imread("D:/(C)(C++)/TaskImage/1.png", IMREAD_COLOR);
	if (!img.data || img.channels() != 3)
		return -1;
	imshow(windowName, img);
	//����ͼ��Ҷ�ֵ�Ĺ�һ��
	HLS(0, 0);
	callBack(0, 0);

	// ��ֵ�˲�����������
	namedWindow("����ֵ�˲���", 1);
	//�����켣��
	createTrackbar("����ֵ��", "����ֵ�˲���", &g_MedianBlurValue, 50, on_MedianBlur);
	on_MedianBlur(0, 0);

	waitKey(0);
	return 0;
}