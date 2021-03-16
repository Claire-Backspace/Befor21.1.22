#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<cmath>
using namespace cv;
using namespace std;

Mat element = getStructuringElement(MORPH_RECT, Size(1, 1));
int main()
{
	Mat src = imread("D:/(C)(C++)/TaskImage/5.jpg");
	
	resize(src, src, Size(src.cols / 17, src.rows / 17));

	Mat dst1;
	float distance = 60;
	float high = 20;
	float hypotenuse;
	hypotenuse = sqrt((distance * distance) + (high * high));
	//cout << hypotenuse << endl;63.2456
	float x = hypotenuse / distance;
	dst1 = Mat::zeros(Size(src.cols, src.rows * x), CV_8UC3); //yan mo
	Mat clo1 = src.clone();
	resize(clo1, clo1, Size(src.cols, src.rows * x));
	//Ô­Í¼×ª¸©ÊÓÕÒÔ²
	Mat cloth;
	cloth = src.clone();
	Mat thr;
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	cvtColor(cloth, cloth, COLOR_BGR2HSV);
	inRange(cloth, Scalar(50, 40, 40), Scalar(180, 255, 255), thr);
	//imshow("", thr);
	findContours(thr, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0, 0));
	vector<Rect> boundRect(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		boundRect[i] = boundingRect(Mat(contours[i]));
		//rectangle(src, boundRect[i].tl(), boundRect[i].br(), Scalar(77,  255, 255), 2);
	}
	Point2f left = boundRect[0].tl();//(0, 176)
	double Left = left.y;
	//cout << boundRect[0].tl() << endl;
	//imshow("thr", thr);

	//F = (ÏñËØ¿í¶ÈP * ¾àÀëD)/WÎïÌå¿í¶È£»
	//D = FW/P
	
	double BulletR = 4.2;
	double bulletr = 1.7;
	double F = 4.35675;

	Point2f pc[5];//´¢´æÔ²ÐÄ£»
	int ballr[5];//´¢´æ°ë¾¶£»
	Mat clo2, clo1gray;
	clo2 = src.clone();
	cvtColor(clo2, clo1gray, COLOR_BGR2GRAY);
	medianBlur(clo1gray, clo1gray, 3);
	vector<Vec3f>circles;
	HoughCircles(clo1gray, circles, HOUGH_GRADIENT, 1.55, 15, 100, 40, 10, 40);
	for (size_t i = 0; i < circles.size(); i++)
	{
		Vec3f c = circles[i];
		//yuan
		//circle(src, Point(c[0], c[1]), c[2], Scalar(77, 255, 255), 2, LINE_AA);
		circle(dst1, Point(c[0], c[1]), c[2], Scalar(77, 255, 255), 2, LINE_AA);//»­µ½ÑÚÄ¤
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		pc[i] = center;
		ballr[i] = radius;
		//yuanxin
		//circle(, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		/*
		cout << radius << endl;
		cout<<center<<endl;
		cout << pc[i] << endl;
		cout << clo1.rows << endl;//558*/
	}

	//double yellowBullet = (F * BulletR) / pc[0];
	//cout << yellowBullet << endl;

	Mat clo = src.clone();
	Mat clogray;
	cvtColor(clo, clogray, COLOR_BGR2GRAY);
	medianBlur(clogray, clogray, 3);
	vector<Vec3f>circles1;
	HoughCircles(clogray, circles1, HOUGH_GRADIENT, 1.55, 15, 100, 40, 10, 40);
	for (size_t i = 0; i < circles1.size(); i++)
	{
		Vec3f c = circles1[i];
		//yuan
		//circle(src, Point(c[0], c[1]), c[2], Scalar(77, 255, 255), 2, LINE_AA);
		circle(clo, Point(c[0], c[1]), c[2], Scalar(77, 255, 255), 2, LINE_AA);//»­µ½cloneÍ¼
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		/*
		cout << radius << endl;
		cout << center << endl;
		cout << clo.rows << endl;530
		cout << clo.cols << endl;707
		*/	
	}
	cout << "the size of the circles = " << circles1.size() << endl;
	double ROWS = clo.rows;
	double COLS = clo.cols;
	double BLUR = distance / (ROWS - Left);
	//cout << BLUR << endl;0.169....
	double yellow_BulletD = (ROWS - pc[0].y) * BLUR;
	cout << "»ÆÉ«´óÇò£º" << yellow_BulletD << endl;
	double red_BulletD = (ROWS - pc[1].y) * BLUR;
	cout << "ºìÉ«´óÇò£º" << red_BulletD << endl;
	double right_white_BulletD = (ROWS - pc[2].y) * BLUR + (BulletR - bulletr);
	cout << "ÓÒ²à°×Çò£º" << right_white_BulletD << endl;
	double middle_white_BulletD = (ROWS - pc[3].y) * BLUR;
	cout << "ÖÐ¼ä°×Çò£º" << middle_white_BulletD << endl;
	double left_white_BulletD = (ROWS - pc[4].y) * BLUR;
	cout << "×ó²à°×Çò£º" << left_white_BulletD << endl;
	//imshow("src", src);
	imshow("dst1", dst1);
	imshow("clo", clo);
	waitKey(0);
}