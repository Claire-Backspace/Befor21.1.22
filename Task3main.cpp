
/*
#include<iostream>
//#include<time.h>
#include <stdlib.h>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;
//#define WINDOW_NAME "win"
//int ThresholdValue = 100;
//int ThresholdType = 3;
Mat gray;
Mat src = imread("D:/(C)(C++)/TaskImage/3/15.jpg", WINDOW_AUTOSIZE);
Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
//void MyEllipse();
//void print();
//void thres(int, void*);

int w = src.cols;
int h = src.rows;
cv::Mat combine = cv::Mat::zeros(w, h, src.type());
Mat srcROI1 = combine(Rect(0, 0, w / 3, h / 3));
Mat srcROI2 = combine(Rect(w / 3, 0, w / 3, h / 3));
Mat srcROI3 = combine(Rect(w / 3 * 2, 0, w / 3, h / 3));
Mat srcROI4 = combine(Rect(0, w / 3, w / 3, h / 3));
Mat srcROI5 = combine(Rect(w / 3, h / 3, h / 3, h / 3));
Mat srcROI6 = combine(Rect(w / 3 * 2, h / 3, w / 3, h / 3));
Mat srcROI7 = combine(Rect(0, w / 3 * 2, w / 3, h / 3));
Mat srcROI8 = combine(Rect(w / 3, h / 3 * 2, w / 3, h / 3));
Mat srcROI9 = combine(Rect(w / 3 * 2, h / 3 * 2, w / 3, h / 3));

Mat srce[10];
int main()
{
	//int i = 1 + (int)72 * rand() / (RAND_MAX + 1);
	namedWindow("a", WINDOW_NORMAL);
	resizeWindow("a", Size(800, 800));
	cvtColor(src, src, COLOR_BGR2GRAY);
	erode(src, src, element);
	threshold(src, src, 80, 255, THRESH_BINARY);
	namedWindow("b", WINDOW_NORMAL);
	resizeWindow("b", Size(400, 400));

	srce[1] = src(Rect(0, 0, w / 3, h / 3));
	srce[2] = src(Rect(w / 3, 0, w / 3, h / 3));
	srce[3] = src(Rect(w / 3 * 2, 0, w / 3, h / 3));
	srce[4] = src(Rect(0, h / 3, w / 3, h / 3));
	srce[5] = src(Rect(w / 3, h / 3, w / 3, h / 3));
	srce[6] = src(Rect(w / 3 * 2, h / 3, w / 3, h / 3));
	srce[7] = src(Rect(0, h / 3 * 2, w / 3, h / 3));
	srce[8] = src(Rect(w / 3, h / 3 * 2, w / 3, h / 3));
	srce[9] = src(Rect(w / 3 * 2, h / 3 * 2, w / 3, h / 3));
/*
Rect(int _x,int _y,int _width,int _height);
参数意思为：左上角x坐标
左上角y坐标
矩形的宽
矩形的高
*/
	putText(src, "tern", Point(300, 500), FONT_HERSHEY_SIMPLEX, 10.0, Scalar(125, 0, 0), 30, 8, false);
	//createTrackbar("modle", WINDOW_NAME, &ThresholdType, 4, thres);
	//createTrackbar("modle", WINDOW_NAME, &ThresholdValue, 255, thres);
	//thres();

	namedWindow("九宫格");

	imshow("九宫格", combine);
	waitKey(0);

	return 0;
}

void judgement()
{

}
*/

#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;
void jugement(int arr[]);

int print_px_value(Mat& im)
{
    int counter = 0;
    int rowNumber = im.rows;  //行数
    int colNumber = im.cols * im.channels();  //列数 x 通道数=每一行元素的个数

    //双重循环，遍历所有的像素值
    for (int i = 0; i < rowNumber; i++)  //行循环
    {
        uchar* data = im.ptr<uchar>(i);  //获取第i行的首地址
        for (int j = 0; j < colNumber; j++)   //列循环
        {
            //data[j] = data[j] / div * div + div / 2;
            //cout << (int)data[j] << endl;
            if (data[j] == 0) counter += 1;

        }  //行处理结束
    }
    //cout<<counter<<endl;
    return counter;
}
Mat src = imread("D:/(C)(C++)/TaskImage/3/47.jpg", 0);
Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
int main()
{
    double t = (double)cv::getTickCount();//开始计时
    resize(src, src, Size(640, 480));
    Mat clone_image = src.clone();
    threshold(clone_image, clone_image, 90, 255, THRESH_BINARY);
    //imshow("a", clone_image);
    waitKey(0);
    int x = 0;
    int y = 0;
    int width = clone_image.cols;
    int height = clone_image.rows;
    Rect area1(x, y, width / 3, height / 3);
    Rect area2(x + width / 3, y, width / 3, height / 3);
    Rect area3(x + width / 3 * 2, y, width / 3, height / 3);
    Rect area4(x, y + height / 3, width / 3, height / 3);
    Rect area5(x + width / 3, y + height / 3, width / 3, height / 3);
    Rect area6(x + width / 3 * 2, y + height / 3, width / 3, height / 3);
    Rect area7(x, y + height / 3 * 2, width / 3, height / 3);
    Rect area8(x + width / 3, y + height / 3 * 2, width / 3, height / 3);
    Rect area9(x + width / 3 * 2, y + height / 3 * 2, width / 3, height / 3);
    Mat dst1 = clone_image(area1);
    Mat dst2 = clone_image(area2);
    Mat dst3 = clone_image(area3);
    Mat dst4 = clone_image(area4);
    Mat dst5 = clone_image(area5);
    Mat dst6 = clone_image(area6);
    Mat dst7 = clone_image(area7);
    Mat dst8 = clone_image(area8);
    Mat dst9 = clone_image(area9);


    //print_px_value(dst8);
    int arr[9];
    arr[0] = print_px_value(dst1);
    arr[1] = print_px_value(dst2);
    arr[2] = print_px_value(dst3);
    arr[3] = print_px_value(dst4);
    arr[4] = print_px_value(dst5);
    arr[5] = print_px_value(dst6);
    arr[6] = print_px_value(dst7);
    arr[7] = print_px_value(dst8);
    arr[8] = print_px_value(dst9);



    /*
        imshow("dst1",dst1);
        imshow("dst2",dst2);
        imshow("dst3",dst3);
        imshow("dst4",dst4);
        imshow("dst5",dst5);
        imshow("dst6",dst6);
        imshow("dst7",dst7);
        imshow("dst8",dst8);
        imshow("dst9",dst9);
        waitKey(0);
    */

    //cout << arr[6] << endl;
    t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();//结束计时
    int fps = int(1.0 / t);//转换为帧率
    cout << "FPS: " << fps << endl;//输出帧率
    jugement(arr);
    return 0;
}
void print_straight()
{
    putText(src, "straight", Point(100, 100), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 2, 8);
    imshow("juge", src);
    waitKey(0);

}

void print_turn_right()
{
    putText(src, "turn right", Point(100, 100), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 2, 8);
    imshow("juge", src);
    waitKey(0);
}

void print_turn_left()
{
    putText(src, "turn left", Point(100, 100), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 2, 8);
    imshow("juge", src);
    waitKey(0);
}



void jugement(int arr[])
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] >= 2000 && arr[i] <= 4750)
        {
            arr[i] = 1;
        }
        else if (arr[i] >= 4750)
        {
            arr[i] = 2;
        }
        else
        {
            arr[i] = 0;
        }
    }
    if (arr[4] == 2 && arr[7] == 2)
    {
        if (arr[1] == 2 && arr[0] < 2 && arr[3] < 2 && arr[6] < 2 && arr[2] < 2 && arr[5] < 2 && arr[8] < 2)
        {
            print_straight();
        }
        else if (arr[1] == 2 && (arr[0] == 2 || arr[3] == 2 || arr[6] == 2))
        {
            print_turn_left();
        }
        else if (arr[1] == 2 && (arr[2] == 2 || arr[5] == 2 || arr[8] == 2))
        {
            print_turn_right();
        }
        else if (arr[1] < 2 && (arr[0] > 1 || arr[3] > 1 || arr[6] > 1))
        {
            print_turn_left();
        }
        else if (arr[1] < 2 && (arr[2] > 1 || arr[5] > 1 || arr[8] > 1))
        {
            print_turn_right();
        }
        else print_straight();
    }
    else print_straight();
}
