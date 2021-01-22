#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

//int GaussianBlurValue = 5;

vector<vector<Point>>contours;
vector<Vec4i>hierarchy;

int main(int argc, char** argv)
{
	Mat output, grayimage;
	Mat srcimage = imread("D:/(C)(C++)/TaskImage/2.png", 1);
	cvtColor(srcimage, grayimage, COLOR_BGR2GRAY);
	imshow("hui", grayimage);
	//inRange(grayimage, Scalar(11, 43, 46), Scalar(25, 255, 255), grayimage);
	threshold(grayimage, grayimage, 120, 150, THRESH_BINARY);
	
	
	imshow("2", grayimage);
	Canny(grayimage, grayimage, 400, 800, 3);
	imshow("canny", grayimage);

	//blur(grayimage, grayimage, Size(3, 3));
	
	//GaussianBlur(grayimage, grayimage, Size(GaussianBlurValue * 2 + 1, GaussianBlurValue * 2 + 1), 0, 0);
	//imshow("gaussian", grayimage);

	
	findContours(grayimage, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	imshow("find", grayimage);
    vector<vector<Point>>::iterator area = contours.begin();
	for ( ; area != contours.end(); )
	{
		double dconArea = contourArea(*area);
		if (dconArea < 340 )
		{
			area = contours.erase(area);
		}
		else
		{
			++area;
		}
	}

	Mat drawing = Mat::zeros(grayimage.size(), CV_8UC3);
	for (unsigned int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(34, 255, 255);
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}

	imshow("shaixuan", drawing);

	 waitKey(0);

	 return 0;
	 
 }
 
 

/*

#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/types_c.h>
#include<opencv2/core/core.hpp>
 //#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat hsvImage, grayImage, dstImageOne, dstImageTwo, dstImageThree;

	//����ԭͼ
	Mat srcImage = imread("D:/(C)(C++)/TaskImage/2.png");
	//��ʾԭͼ
	imshow("��ԭͼ��", srcImage);
	//ת��Ϊhsv
	cvtColor(srcImage, hsvImage, CV_BGR2HSV);
	//��ɫת��
	inRange(hsvImage, Scalar(11, 43, 46), Scalar(25, 255, 255), dstImageOne);
	//��˹ģ��
	GaussianBlur(dstImageOne, dstImageTwo, Size(1, 1), 0, 0);
	//��Ե���
	Canny(dstImageTwo, dstImageThree, 1, 2, 3);
	//Ѱ������
	vector<vector<Point>>contours;
	vector<Vec4i> hierarchy;
	findContours(dstImageThree, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	//���������Сɸѡ����
	vector<vector<Point>>::iterator iter = contours.begin();
	for (; iter != contours.end();)
	{
		double dconArea = contourArea(*iter);
		if (dconArea < 190)
		{
			iter = contours.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	//�������
	Mat drawing = Mat::zeros(dstImageThree.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(34, 255, 255);
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}
	//��ʾЧ��ͼ
	imshow("��Ч��ͼ��",drawing);
	waitKey(0);
	return 0;
}


*/