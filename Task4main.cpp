#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

Mat src = imread("D:/(C)(C++)/TaskImage/4.jpg");
Mat clo = src.clone();
Mat CLO = src.clone();
Mat element = getStructuringElement(MORPH_RECT, Size(1, 1));

void Sprite(Mat &clo)
{
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	Mat clo1 = src.clone();
	Mat cloHSV;
	cvtColor(clo, clo, COLOR_BGR2HSV);
	inRange(clo, Scalar(26, 60, 66), Scalar(68, 255, 255), cloHSV);
	blur(cloHSV, cloHSV, Size(3, 3));

	findContours(cloHSV, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<vector<Point>>::iterator area = contours.begin();
	for (; area != contours.end(); )
	{
		double dconArea = contourArea(*area);
		if (dconArea < 2000)
		{
			area = contours.erase(area);
		}
		else
		{
			++area;
		}
	}

	vector<Point> tempPoint;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint.push_back(contours[k][m]);
		}
	}
	
	RotatedRect box = minAreaRect(Mat(tempPoint));
	Point2f vertex[4];
	box.points(vertex);

	Mat clo1HSV;
	cvtColor(clo1, clo1, COLOR_BGR2HSV);
	inRange(clo1, Scalar(30, 197, 141), Scalar(45, 228, 255), clo1HSV);
	erode(clo1HSV, clo1HSV, element);
	findContours(clo1HSV, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Point> tempPoint1;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint1.push_back(contours[k][m]);
		}
	}

	RotatedRect box1 = minAreaRect(Mat(tempPoint1));
	Point2f p[4];
	box1.points(p);
	int x = p[2].x;
	int y = p[2].y;
	Point2f p1[1];
	p1[0].x = vertex[1].x;
	p1[0].y = y;
	rectangle(CLO, p1[0], vertex[3], Scalar(77, 255, 255));
	putText(CLO, "Sprite", p1[0], FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 0.1, 8);
	contours.clear();
	hierarchy.clear();
}

void bigcola(Mat& clo2)
{
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	Mat clo2_1 = src.clone();
	Mat clo2HSV;
	cvtColor(clo2, clo2, COLOR_BGR2HSV);
	inRange(clo2, Scalar(67, 0, 0), Scalar(180, 255, 255), clo2HSV);
	erode(clo2HSV, clo2HSV, element);
	blur(clo2HSV, clo2HSV, Size(3, 3));
	findContours(clo2HSV, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));

	vector<vector<Point>>::iterator area = contours.begin();
	for (; area != contours.end(); )
	{
		double dconArea = contourArea(*area);
		if (dconArea < 8000)
		{
			area = contours.erase(area);
		}
		else
		{
			++area;
		}
	}

	vector<Point> tempPoint;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint.push_back(contours[k][m]);
		}
	}

	RotatedRect box = minAreaRect(Mat(tempPoint));
	Point2f vertex[4];
	box.points(vertex);
	Point2f p[1];

	Mat clo2_1HSV;
	cvtColor(clo2_1, clo2_1, COLOR_BGR2HSV);
	inRange(clo2_1, Scalar(177, 245, 140), Scalar(178, 255, 255), clo2_1HSV);
	erode(clo2_1HSV, clo2_1HSV, element);
	blur(clo2_1HSV, clo2_1HSV, Size(3, 3));
	findContours(clo2_1HSV, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Point> tempPoint2;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint2.push_back(contours[k][m]);
		}
	}
	RotatedRect box2 = minAreaRect(Mat(tempPoint2));
	Point2f p2[4];
	box2.points(p2);
	Point2f p_2[3];
	p_2[0].x = vertex[1].x;;
	p_2[0].y = p2[2].y;
	p_2[1].x = vertex[3].x;
	p_2[1].y = vertex[1].y;
	rectangle(CLO, p_2[0], p_2[1], Scalar(77, 255, 255));
	p_2[2].x = p_2[1].x;
	p_2[2].y = p_2[0].y;
	putText(CLO, "Cola", p_2[2], FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 0.1, 8);
	contours.clear();
	hierarchy.clear();
}

void plastic(Mat& clo)
{
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	Mat cloHSV;
	cvtColor(clo, clo, COLOR_BGR2HSV);
	inRange(clo, Scalar(22, 84, 150), Scalar(25, 255, 160), cloHSV);
	erode(cloHSV, cloHSV, element);
	findContours(cloHSV, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Point>tempPoint;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint.push_back(contours[k][m]);
		}
	}
	RotatedRect box = minAreaRect(Mat(tempPoint));
	Point2f p1[4];
	box.points(p1);

	Mat clo4_1 = src.clone();
	Mat clo4_1HSV;
	cvtColor(clo4_1, clo4_1, COLOR_BGR2HSV);
	inRange(clo4_1, Scalar(173, 245, 149), Scalar(175, 255, 255), clo4_1HSV);
	erode(clo4_1HSV, clo4_1HSV, element);
	findContours(clo4_1HSV, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Point>tempPoint1;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint1.push_back(contours[k][m]);
		}
	}
	RotatedRect box1 = minAreaRect(Mat(tempPoint1));
	Point2f p2[4];
	box1.points(p2);

	Mat clo4_2 = src.clone();
	Mat clo4_2HSV;
	cvtColor(clo4_2, clo4_2, COLOR_BGR2HSV);
	inRange(clo4_2, Scalar(177, 190, 204), Scalar(178, 197, 255), clo4_2HSV);
	erode(clo4_2HSV, clo4_2HSV, element);
	findContours(clo4_2HSV, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Point>tempPoint2;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint2.push_back(contours[k][m]);
		}
	}
	RotatedRect box2 = minAreaRect(Mat(tempPoint2));
	Point2f p3[4];
	box2.points(p3);
	p3[1];
	Point2f p0[3];
	p0[0].x = p3[1].x;
	p0[0].y = p2[2].y;
	p0[1].x = p3[3].x;
	p0[1].y = p1[0].y;
	rectangle(CLO, p0[0], p0[1], Scalar(70, 255, 255));
	p0[2].x = p0[0].x;
	p0[2].y = p1[0].y + 20;
	putText(CLO, "plastic cup", p0[2], FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 0.1, 8);
	contours.clear();
	hierarchy.clear();
}


void smallcola(Mat& clo3)
{
	Mat clo3_1 = src.clone();
	/*
    */
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	Mat clo3_1hsv;
	cvtColor(clo3_1, clo3_1, COLOR_BGR2HSV);
	inRange(clo3_1, Scalar(179, 157, 90), Scalar(180, 172, 95), clo3_1hsv);
	erode(clo3_1hsv, clo3_1hsv, element);
	findContours(clo3_1hsv, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Point>tempPoint1;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint1.push_back(contours[k][m]);
		}
	}
	RotatedRect box1 = minAreaRect(Mat(tempPoint1));
	Point2f p1[4];
	box1.points(p1);
	//rectangle(src, p1[0], p1[2], Scalar(77, 255, 255));
	p1[0].y;//ÖÐÏßµ×

	Mat clo3_2 = clo.clone();
	Mat clo3_2Hsv;
	cvtColor(clo3_2, clo3_2, COLOR_BGR2HSV);
	inRange(clo3_2, Scalar(33, 153, 72), Scalar(50, 177, 82), clo3_2Hsv);
	findContours(clo3_2Hsv, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Point>tempPoint2;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint2.push_back(contours[k][m]);
		}
	}
	RotatedRect box2 = minAreaRect(Mat(tempPoint2));
	Point2f p2[4];
	box2.points(p2);
	//rectangle(src, p2[1], p2[2], Scalar(77, 255, 255));
	//p2[1].¶¥

	Mat clo3_3 = clo.clone();
	Mat clo3_3HSV;
	cvtColor(clo3_3, clo3_3, COLOR_BGR2HSV);
	inRange(clo3_3, Scalar(18, 237, 107), Scalar(69, 247, 108), clo3_3HSV);
	erode(clo3_3HSV, clo3_3HSV, element);
	findContours(clo3_3HSV, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Point>tempPoint3;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint3.push_back(contours[k][m]);
		}
	}
	RotatedRect box3 = minAreaRect(Mat(tempPoint3));
	Point2f p3[4];
	box3.points(p3);

	Point2f p0[3];
	p0[0].x = p3[2].x;
	p0[0].y = p2[1].y;
	p0[1].x = p0[0].x + (p1[0].x - p3[2].x) * 2;
	p0[1].y = p1[0].y;
	rectangle(CLO, p0[0], p0[1], Scalar(77, 255, 255));
	putText(CLO, "cola", p0[0], FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 0.1, 8);
	contours.clear();
	hierarchy.clear();
	//*/
}

void milkbox(Mat& clo5)
{
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	Mat clo5HSV;
	cvtColor(clo5, clo5, COLOR_BGR2HSV);
	inRange(clo5, Scalar(12, 50, 108), Scalar(13, 60, 114), clo5HSV);
	erode(clo5HSV, clo5HSV, element);
	findContours(clo5HSV, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Point>tempPoint1;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint1.push_back(contours[k][m]);
		}
	}
	RotatedRect box1 = minAreaRect(Mat(tempPoint1));
	Point2f p1[4];
	box1.points(p1);

	Mat clo5_1 = src.clone();
	Mat clo5_1HSV;
	cvtColor(clo5_1, clo5_1, COLOR_BGR2HSV);
	inRange(clo5_1, Scalar(9, 183, 200), Scalar(16, 255, 255), clo5_1HSV);
	erode(clo5_1HSV, clo5_1HSV, element);
	findContours(clo5_1HSV, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Point>tempPoint2;
	for (int k = 0; k < contours.size(); k++)
	{
		for (int m = 0; m < contours[k].size(); m++)
		{
			tempPoint2.push_back(contours[k][m]);
		}
	}
	RotatedRect box2 = minAreaRect(Mat(tempPoint2));
	Point2f p2[4];
	box2.points(p2);
	Point2f p0[1];
	p0[0].x = p2[3].x;
	p0[0].y = p1[3].y;
	rectangle(CLO, p2[2], p0[0], Scalar(77, 255, 255));
	putText(CLO, "Milk box", p2[2], FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 0.1, 8);
	contours.clear();
	hierarchy.clear();
}




int main(int argc, char* argv[])
{
	resize(src, src, Size(640, 480));
 	resize(clo, clo, Size(640, 480));
	resize(CLO, CLO, Size(640, 480));
	Mat clo2 = clo.clone();
	Mat clo3 = clo.clone();
	Mat clo4 = clo.clone();
	Mat clo5 = clo.clone();
	/*
	rectangle(src, Rect(92, 123, 118, 245), Scalar(0, 0, 255), 1, 1, 0);
	rectangle(src, Rect(260, 267, 52, 88), Scalar(0, 0, 255), 1, 1, 0);
	rectangle(src, Rect(337, 227, 72, 128), Scalar(0, 0, 255), 1, 1, 0);
	rectangle(src, Rect(437, 123, 120, 245), Scalar(0, 0, 255), 1, 1, 0);
	rectangle(src, Rect(267, 110, 143, 187), Scalar(0, 0, 255), 1, 1, 0);
	*/
	Sprite(clo);
	bigcola(clo2);
	//rectangle(src, Rect(260, 267, 52, 88), Scalar(0, 0, 255), 1, 1, 0);
	smallcola(clo3);
	plastic(clo4);
	milkbox(clo5);
	imshow("dst", CLO);
	waitKey(0);
	return 0;
}

