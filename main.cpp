
#include "stdafx.h"
#include "opencv2\opencv.hpp"
#include <iostream>
#include <math.h>
#include <cmath>
#define PI 3.14159265
using namespace cv;
using namespace std;


unsigned char DrawFrame_OR_GetPoint = 1;        //1畫框，2取點
void on_mouse(int EVENT, int x, int y, int flags, void* ustc);



//If you have an idea what size circles you are looking for, 
//then it would be best to set min_radius and max_radius accordingly.Otherwise, 
//it will return anything circular of any size.
//
//Parameters 1 and 2 don't affect accuracy as such, more reliability. Param 1 will set the sensitivity; how strong the edges of the circles need to be.
//Too high and it won't detect anything, too low and it will find too much clutter.
//Param 2 will set how many edge points it needs to find to declare that it's found a circle. Again, too high will detect nothing, 
//too low will declare anything to be a circle. The ideal value of param 2 will be related to the circumference of the circles.

//void mouseEvent(int event, int x, int y, int flags, void *param)
//{
//	IplImage* img = (IplImage*)param;
//	if (event == EVENT_LBUTTONDBLCLK);
//	{
//		printf("%d,%d\n", x, y);
//	}
//}

void CreatTxt(char* pathName, unsigned char* rBuffer, int length)//建立txt檔案
{
	char* path = "C:\\Users\\Security\\Downloads\\OPENCV3_HW\\OPENCV3_HW\\OPENCV3_HW\\Circules.txt"; // 你要建立檔案的路徑
	ofstream fout(pathName);
	if (fout) { // 如果建立成功
		for (int i = 0; i < length; i++)
		{
			fout << "test" << endl; // 使用與cout同樣的方式進行寫入


		}

		fout.close();  // 執行完操作後關閉檔案控制代碼
	}
}

int main(int argv, char **argc)
{
	Mat test = imread("img31.png", IMREAD_UNCHANGED);
	//imshow("img01", test);
	namedWindow("DealImg", WINDOW_NORMAL);
	Mat test1 = imread("img31.png", IMREAD_UNCHANGED);

	int radius = 1;
	int degree = 0;
	float arrx[36];
	float arry[36];
	for (int i = 0; i < 36; i++)
	{

		arrx[i] = 0 - radius * cos(degree * PI / 180);
		arry[i] = 0 - radius * sin(degree * PI / 180);

		degree += 10;
	}
	ofstream outfile;

	outfile.open("Circle.txt", ios::trunc);

	outfile << "0 ";

	for (int i = 0; i < 36; i++)
	{
		outfile << arrx[i] << " " << arry[i] << " ";
	}
	outfile << endl << "1 ";


	imshow("DealImg", test1);
	setMouseCallback("DealImg", on_mouse, (void*)(&test1)); //呼叫回撥函式 
	waitKey(0);
	destroyWindow("DealImg");

	//rectangle(test, Handle_rect, Scalar(255, 0, 0), 3, 8, 0);//能夠實時顯示在畫矩形視窗時的痕跡

	//IplImage *img = cvLoadImage("img01.png", 1);
	//cvNamedWindow("windows", 1);

	//cvSetMouseCallback("windows", mouseEvent, &img);


	Mat src = imread("img01_edit.png", 1);

	if (!src.data)
	{
		return -1;
	}
	Mat src_gray;
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	medianBlur(src_gray, src_gray, 5);
	//GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
	vector<Vec3f> circles;

	HoughCircles(src_gray, circles, HOUGH_GRADIENT, 1,
		src_gray.rows / 50,  // change this value to detect circles with different distances to each other
		30, 10, 20, 25 // change the last two parameters
					   // (min_radius & max_radius) to detect larger circles
	);

	//show image result
	//
	//for (size_t i = 0; i < circles.size(); i++)
	//{
	//	Vec3i c = circles[i];
	//	Point center = Point(c[0], c[1]);
	//	// circle center
	//	circle(src, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
	//	// circle outline
	//	int radius = c[2];
	//	circle(src, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
	//}

	/*cout << "total number of points: " << circles.size() << endl;


	for (size_t j = 0; j < circles.size(); j++)
	{
		Vec3i c = circles[j];
		cout << "x : " << c[0] << " y : " << c[1] << endl;
		cout << j << " original x : " << arrx[j] << "  original y : " << arry[j] << endl;

	}*/

	outfile << circles[14][0] << " " << circles[14][1] << " " << circles[20][0] << " " << circles[20][1] << " " << circles[21][0] << " " << circles[21][1] << " " << circles[16][0] << " " << circles[16][1]<<" ";
	outfile << circles[2][0] << " " << circles[2][1] << " " << circles[12][0] << " " << circles[12][1] << " " << circles[4][0] << " " << circles[4][1] << " " << circles[5][0] << " " << circles[5][1] << " " << circles[6][0] << " " << circles[6][1] << " " << circles[0][0] << " " << circles[0][1] << " ";
	outfile << circles[10][0] << " " << circles[10][1] << " " << circles[3][0] << " " << circles[3][1] << " " << circles[7][0] << " " << circles[7][1] << " " << circles[1][0] << " " << circles[1][1] << " " << circles[11][0] << " " << circles[11][1] << " " << circles[9][0] << " " << circles[9][1] << " ";
	outfile << circles[8][0] << " " << circles[8][1] << " " << circles[13][0] << " " << circles[13][1] << " " << circles[19][0] << " " << circles[19][1] << " " << circles[18][0] << " " << circles[18][1] << " " << circles[27][0] << " " << circles[27][1] << " " << circles[34][0] << " " << circles[34][1] << " ";
	outfile << circles[17][0] << " " << circles[17][1] << " " << circles[29][0] << " " << circles[29][1] << " " << circles[33][0] << " " << circles[33][1] << " " << circles[32][0] << " " << circles[32][1] << " " << circles[25][0] << " " << circles[25][1] << " " << circles[24][0] << " " << circles[24][1] << " ";
	outfile << circles[26][0] << " " << circles[26][1] << " " << circles[22][0] << " " << circles[22][1] << " " << circles[30][0] << " " << circles[30][1] << " " << circles[15][0] << " " << circles[15][1] << " " << circles[23][0] << " " << circles[23][1] << " " << circles[28][0] << " " << circles[28][1] << " ";
	outfile << circles[35][0] << " " << circles[35][1] << " " << circles[31][0] << " " << circles[31][1] << endl;

	outfile << "7 ";

	Mat src07 = imread("img07_edit.png", 1);

	if (!src.data)
	{
		return -1;
	}
	Mat src_gray07;
	cvtColor(src07, src_gray07, COLOR_BGR2GRAY);
	medianBlur(src_gray07, src_gray07, 5);
	//GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
	vector<Vec3f> circles07;

	HoughCircles(src_gray07, circles07, HOUGH_GRADIENT, 1,
		src_gray07.rows / 50,  // change this value to detect circles with different distances to each other
		30, 10, 20, 25 // change the last two parameters
					   // (min_radius & max_radius) to detect larger circles
	);


	outfile << circles07[2][0] << " " << circles07[2][1] << " " << circles07[5][0] << " " << circles07[5][1] << " " << circles07[10][0] << " " << circles07[10][1] << " " << circles07[13][0] << " " << circles07[13][1]<<" ";
	outfile << circles07[22][0] << " " << circles07[22][1] << " " << circles07[26][0] << " " << circles07[26][1] << " " << circles07[25][0] << " " << circles07[25][1] << " " << circles07[16][0] << " " << circles07[16][1] << " " << circles07[18][0] << " " << circles07[18][1] << " " << circles07[34][0] << " " << circles07[34][1] << " ";
	outfile << circles07[24][0] << " " << circles07[24][1] << " " << circles07[32][0] << " " << circles07[32][1] << " " << circles07[31][0] << " " << circles07[31][1] << " " << circles07[29][0] << " " << circles07[29][1] << " " << circles07[30][0] << " " << circles07[30][1] << " " << circles07[15][0] << " " << circles07[15][1] << " ";
	outfile << circles07[23][0] << " " << circles07[23][1] << " " << circles07[17][0] << " " << circles07[17][1] << " " << circles07[33][0] << " " << circles07[33][1] << " " << circles07[12][0] << " " << circles07[12][1] << " " << circles07[19][0] << " " << circles07[19][1] << " " << circles07[20][0] << " " << circles07[20][1] << " ";
	outfile << circles07[21][0] << " " << circles07[21][1] << " " << circles07[35][0] << " " << circles07[35][1] << " " << circles07[27][0] << " " << circles07[27][1] << " " << circles07[28][0] << " " << circles07[28][1] << " " << circles07[14][0] << " " << circles07[14][1] << " " << circles07[6][0] << " " << circles07[6][1] << " ";
	outfile << circles07[11][0] << " " << circles07[11][1] << " " << circles07[0][0] << " " << circles07[0][1] << " " << circles07[1][0] << " " << circles07[1][1] << " " << circles07[8][0] << " " << circles07[8][1] << " " << circles07[9][0] << " " << circles07[9][1] << " " << circles07[4][0] << " " << circles07[4][1] << " ";
	outfile << circles07[7][0] << " " << circles07[7][1] << " " << circles07[3][0] << " " << circles07[3][1] << endl;

	outfile << "13 ";

	Mat src13 = imread("img13_edit.png", 1);

	if (!src.data)
	{
		return -1;
	}
	Mat src_gray13;
	cvtColor(src13, src_gray13, COLOR_BGR2GRAY);
	medianBlur(src_gray13, src_gray13, 5);
	//GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
	vector<Vec3f> circles13;

	HoughCircles(src_gray13, circles13, HOUGH_GRADIENT, 1,
		src_gray13.rows / 50,  // change this value to detect circles with different distances to each other
		30, 10, 20, 25 // change the last two parameters
					   // (min_radius & max_radius) to detect larger circles
	);

	outfile << circles13[34][0] << " " << circles13[34][1] << " " << circles13[25][0] << " " << circles13[25][1] << " " << circles13[18][0] << " " << circles13[18][1] << " " << circles13[33][0] << " " << circles13[33][1]<<" ";
	outfile << circles13[28][0] << " " << circles13[28][1] << " " << circles13[31][0] << " " << circles13[31][1] << " " << circles13[15][0] << " " << circles13[15][1] << " " << circles13[30][0] << " " << circles13[30][1] << " " << circles13[35][0] << " " << circles13[35][1] << " " << circles13[17][0] << " " << circles13[17][1] << " ";
	outfile << circles13[22][0] << " " << circles13[22][1] << " " << circles13[32][0] << " " << circles13[32][1] << " " << circles13[23][0] << " " << circles13[23][1] << " " << circles13[24][0] << " " << circles13[24][1] << " " << circles13[29][0] << " " << circles13[29][1] << " " << circles13[19][0] << " " << circles13[19][1] << " ";
	outfile << circles13[16][0] << " " << circles13[16][1] << " " << circles13[13][0] << " " << circles13[13][1] << " " << circles13[27][0] << " " << circles13[27][1] << " " << circles13[20][0] << " " << circles13[20][1] << " " << circles13[21][0] << " " << circles13[21][1] << " " << circles13[11][0] << " " << circles13[11][1] << " ";
	outfile << circles13[6][0] << " " << circles13[6][1] << " " << circles13[3][0] << " " << circles13[3][1] << " " << circles13[7][0] << " " << circles13[7][1] << " " << circles13[12][0] << " " << circles13[12][1] << " " << circles13[9][0] << " " << circles13[9][1] << " " << circles13[8][0] << " " << circles13[8][1] << " ";
	outfile << circles13[1][0] << " " << circles13[1][1] << " " << circles13[2][0] << " " << circles13[2][1] << " " << circles13[10][0] << " " << circles13[10][1] << " " << circles13[4][0] << " " << circles13[4][1] << " " << circles13[0][0] << " " << circles13[0][1] << " " << circles13[14][0] << " " << circles13[14][1] << " ";
	outfile << circles13[5][0] << " " << circles13[5][1] << " " << circles13[26][0] << " " << circles13[26][1] << endl;

	outfile << "19 ";

	Mat src19 = imread("img19_edit.png", 1);

	if (!src.data)
	{
		return -1;
	}
	Mat src_gray19;
	cvtColor(src19, src_gray19, COLOR_BGR2GRAY);
	medianBlur(src_gray19, src_gray19, 5);
	//GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
	vector<Vec3f> circles19;

	HoughCircles(src_gray19, circles19, HOUGH_GRADIENT, 1,
		src_gray19.rows / 50,  // change this value to detect circles with different distances to each other
		30, 10, 20, 25 // change the last two parameters
					   // (min_radius & max_radius) to detect larger circles
	);


	outfile << circles19[18][0] << " " << circles19[18][1] << " " << circles19[34][0] << " " << circles19[34][1] << " " << circles19[33][0] << " " << circles19[33][1] << " " << circles19[25][0] << " " << circles19[25][1]<<" ";
	outfile << circles19[20][0] << " " << circles19[20][1] << " " << circles19[27][0] << " " << circles19[27][1] << " " << circles19[35][0] << " " << circles19[35][1] << " " << circles19[22][0] << " " << circles19[22][1] << " " << circles19[23][0] << " " << circles19[23][1] << " " << circles19[30][0] << " " << circles19[30][1] << " ";
	outfile << circles19[28][0] << " " << circles19[28][1] << " " << circles19[31][0] << " " << circles19[31][1] << " " << circles19[32][0] << " " << circles19[32][1] << " " << circles19[11][0] << " " << circles19[11][1] << " " << circles19[17][0] << " " << circles19[17][1] << " " << circles19[9][0] << " " << circles19[9][1] << " ";
	outfile << circles19[6][0] << " " << circles19[6][1] << " " << circles19[10][0] << " " << circles19[10][1] << " " << circles19[1][0] << " " << circles19[1][1] << " " << circles19[5][0] << " " << circles19[5][1] << " " << circles19[7][0] << " " << circles19[7][1] << " " << circles19[14][0] << " " << circles19[14][1] << " ";
	outfile << circles19[3][0] << " " << circles19[3][1] << " " << circles19[2][0] << " " << circles19[2][1] << " " << circles19[4][0] << " " << circles19[4][1] << " " << circles19[0][0] << " " << circles19[0][1] << " " << circles19[8][0] << " " << circles19[8][1] << " " << circles19[12][0] << " " << circles19[12][1] << " ";
	outfile << circles19[13][0] << " " << circles19[13][1] << " " << circles19[29][0] << " " << circles19[29][1] << " " << circles19[26][0] << " " << circles19[26][1] << " " << circles19[24][0] << " " << circles19[24][1] << " " << circles19[16][0] << " " << circles19[16][1] << " " << circles19[19][0] << " " << circles19[19][1] << " ";
	outfile << circles19[15][0] << " " << circles19[15][1] << " " << circles19[21][0] << " " << circles19[21][1] << endl;

	outfile << "25 ";

	Mat src25 = imread("img25_edit.png", 1);

	if (!src.data)
	{
		return -1;
	}
	Mat src_gray25;
	cvtColor(src25, src_gray25, COLOR_BGR2GRAY);
	medianBlur(src_gray25, src_gray25, 5);
	//GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
	vector<Vec3f> circles25;

	HoughCircles(src_gray25, circles25, HOUGH_GRADIENT, 1,
		src_gray25.rows / 50,  // change this value to detect circles with different distances to each other
		30, 10, 20, 25 // change the last two parameters
					   // (min_radius & max_radius) to detect larger circles
	);



	outfile << circles25[30][0] << " " << circles25[30][1] << " " << circles25[25][0] << " " << circles25[25][1] << " " << circles25[31][0] << " " << circles25[31][1] << " " << circles25[27][0] << " " << circles25[27][1]<<" ";
	outfile << circles25[12][0] << " " << circles25[12][1] << " " << circles25[16][0] << " " << circles25[16][1] << " " << circles25[34][0] << " " << circles25[34][1] << " " << circles25[18][0] << " " << circles25[18][1] << " " << circles25[19][0] << " " << circles25[19][1] << " " << circles25[10][0] << " " << circles25[10][1] << " ";
	outfile << circles25[8][0] << " " << circles25[8][1] << " " << circles25[0][0] << " " << circles25[0][1] << " " << circles25[5][0] << " " << circles25[5][1] << " " << circles25[6][0] << " " << circles25[6][1] << " " << circles25[9][0] << " " << circles25[9][1] << " " << circles25[7][0] << " " << circles25[7][1] << " ";
	outfile << circles25[2][0] << " " << circles25[2][1] << " " << circles25[4][0] << " " << circles25[4][1] << " " << circles25[11][0] << " " << circles25[11][1] << " " << circles25[3][0] << " " << circles25[3][1] << " " << circles25[1][0] << " " << circles25[1][1] << " " << circles25[24][0] << " " << circles25[24][1] << " ";
	outfile << circles25[13][0] << " " << circles25[13][1] << " " << circles25[17][0] << " " << circles25[17][1] << " " << circles25[15][0] << " " << circles25[15][1] << " " << circles25[23][0] << " " << circles25[23][1] << " " << circles25[26][0] << " " << circles25[26][1] << " " << circles25[14][0] << " " << circles25[14][1] << " ";
	outfile << circles25[22][0] << " " << circles25[22][1] << " " << circles25[29][0] << " " << circles25[29][1] << " " << circles25[33][0] << " " << circles25[33][1] << " " << circles25[20][0] << " " << circles25[20][1] << " " << circles25[35][0] << " " << circles25[35][1] << " " << circles25[32][0] << " " << circles25[32][1] << " ";
	outfile << circles25[28][0] << " " << circles25[28][1] << " " << circles25[21][0] << " " << circles25[21][1] << endl;

	outfile << "31 ";
	namedWindow("Circle Detect", CV_WINDOW_AUTOSIZE);
	imshow("Circle Detect", src);

	Mat src31 = imread("img31_edit.png", 1);

	if (!src.data)
	{
		return -1;
	}
	Mat src_gray31;
	cvtColor(src31, src_gray31, COLOR_BGR2GRAY);
	medianBlur(src_gray31, src_gray31, 5);
	//GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
	vector<Vec3f> circles31;

	HoughCircles(src_gray31, circles31, HOUGH_GRADIENT, 1,
		src_gray25.rows / 50,  // change this value to detect circles with different distances to each other
		30, 10, 20, 25 // change the last two parameters
					   // (min_radius & max_radius) to detect larger circles
	);

	outfile << circles31[4][0] << " " << circles31[4][1] << " " << circles31[5][0] << " " << circles31[5][1] << " " << circles31[6][0] << " " << circles31[6][1] << " " << circles31[2][0] << " " << circles31[2][1]<<" ";
	outfile << circles31[3][0] << " " << circles31[3][1] << " " << circles31[10][0] << " " << circles31[10][1] << " " << circles31[7][0] << " " << circles31[7][1] << " " << circles31[0][0] << " " << circles31[0][1] << " " << circles31[12][0] << " " << circles31[12][1] << " " << circles31[14][0] << " " << circles31[14][1] << " ";
	outfile << circles31[13][0] << " " << circles31[13][1] << " " << circles31[31][0] << " " << circles31[31][1] << " " << circles31[25][0] << " " << circles31[25][1] << " " << circles31[29][0] << " " << circles31[29][1] << " " << circles31[21][0] << " " << circles31[21][1] << " " << circles31[11][0] << " " << circles31[11][1] << " ";
	outfile << circles31[20][0] << " " << circles31[20][1] << " " << circles31[18][0] << " " << circles31[18][1] << " " << circles31[33][0] << " " << circles31[33][1] << " " << circles31[23][0] << " " << circles31[23][1] << " " << circles31[27][0] << " " << circles31[27][1] << " " << circles31[34][0] << " " << circles31[34][1] << " ";
	outfile << circles31[17][0] << " " << circles31[17][1] << " " << circles31[32][0] << " " << circles31[32][1] << " " << circles31[28][0] << " " << circles31[28][1] << " " << 665 << " " << 302<< " " << circles31[24][0] << " " << circles31[24][1] << " " << circles31[30][0] << " " << circles31[30][1] << " ";
	outfile << circles31[26][0] << " " << circles31[26][1] << " " << circles31[22][0] << " " << circles31[22][1] << " " << circles31[19][0] << " " << circles31[19][1] << " " << circles31[15][0] << " " << circles31[15][1] << " " << circles31[16][0] << " " << circles31[16][1] << " " << circles31[9][0] << " " << circles31[9][1] << " ";
	outfile << circles31[8][0] << " " << circles31[8][1] << " " << circles31[1][0] << " " << circles31[1][1] << endl;
	float matrix01[7][72];

	outfile.close();
	double a;
	fstream input;
	input.open("Circle.txt", ios::in);
	input >> a;
	for (int i = 0; i < 72; i++) {
		input >> matrix01[0][i];
	}
	input >> a;
	for (int i = 0; i < 72; i++) {
		input >> matrix01[1][i];
	}
	input >> a;
	for (int i = 0; i < 72; i++) {
		input >> matrix01[2][i];
	}
	input >> a;
	for (int i = 0; i < 72; i++) {
		input >> matrix01[3][i];
	}
	input >> a;
	for (int i = 0; i < 72; i++) {
		input >> matrix01[4][i];
	}
	input >> a;
	for (int i = 0; i < 72; i++) {
		input >> matrix01[5][i];
	}
	input >> a;
	for (int i = 0; i < 72; i++) {
		input >> matrix01[6][i];
	}
	input.close();
	//input done
	float matrixm[72][11];
	float matrixm2[72][11];
	float matrixm3[72][11];
	float matrixm4[72][11];
	float matrixm5[72][11];
	float matrixm6[72][11];
	//matrixm[0][0] = matrix01[0][0];
	////matrixm[2][0] = matrix01[0][2];
	//matrixm[0][1] = matrix01[0][1];
	////matrixm[2][1] = matrix01[0][3];
	//matrixm[0][2] = 0;
	////matrixm[2][2] = 0;
	//matrixm[0][3] = 1;
	//matrixm[0][4] = 0;
	//matrixm[0][5] = 0;
	//matrixm[0][6] = 0;
	//matrixm[0][7] = 0;
	//matrixm[0][8] = 0 - (matrix01[1][0] * matrix01[0][0]);
	////matrixm[2][8] = 0 - (matrix01[1][2] * matrix01[0][2]);
	////matrixm[4][8] = 0 - (matrix01[1][4] * matrix01[0][4]);
	//matrixm[0][9] = 0 - (matrix01[1][0] * matrix01[0][1]);
	////matrixm[2][9] = 0 - (matrix01[1][2] * matrix01[0][3]);
	////matrixm[4][9] = 0 - (matrix01[1][4] * matrix01[0][5]);
	//matrixm[0][10] = 0;
	
	int c = 0;

	//for (int i = 0; i < 72; i = i + 2) {
	//	for (int j = 0; j < 2; j++) {
	//		matrixm[i][j] = matrix01[0][c];
	//		c++;
	//	}
	//}
	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm[i][8] = 0 - (matrix01[1][i] * matrix01[0][i]);
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm[i][9] = 0 - (matrix01[1][i] * matrix01[0][i+1]);
	//}
	//
	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm[i][2] = 0;
	//	matrixm[i][3] = 1;
	//	matrixm[i][4] = 0;
	//	matrixm[i][5] = 0;
	//	matrixm[i][6] = 0;
	//	matrixm[i][7] = 0;
	//	matrixm[i][10] = 0;
	//}


	////matrixm[1][0] = 0;
	//////matrixm[3][0] = 0;
	////matrixm[1][1] = 0;
	////matrixm[1][2] = 0;
	////matrixm[1][3] = 0;
	////matrixm[1][4] = matrix01[0][0];
	//////matrix[3][4] = matrix01[0][2];
	////matrixm[1][5] = matrix01[0][1];
	//////matrix[3][5] = matrix01[0][3];
	////matrixm[1][6] = 0;
	////matrixm[1][7] = 1;
	////matrixm[1][8] = 0 - (matrix01[1][1] * matrix01[0][0]);
	////matrixm[1][9] = 0 - (matrix01[1][1] * matrix01[0][1]);
	////matrixm[1][10] = 0;

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm[i][0] = 0;
	//	matrixm[i][1] = 0;
	//	matrixm[i][2] = 0;
	//	matrixm[i][3] = 0;
	//	matrixm[i][6] = 0;
	//	matrixm[i][7] = 1;
	//	matrixm[i][10] = 0;
	//}

	//int d = 0;
	//for (int i = 1; i < 72; i = i + 2) {
	//	for (int j = 4; j < 6; j++) {
	//		matrixm[i][j] = matrix01[0][d];
	//		d++;
	//	}
	//}
	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm[i][8] = 0 - (matrix01[1][i] * matrix01[0][i-1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm[i][9] = 0 - (matrix01[1][i] * matrix01[0][i]);
	//}

	////second time 
	//c = 0;

	//for (int i = 0; i < 72; i = i + 2) {
	//	for (int j = 0; j < 2; j++) {
	//		matrixm2[i][j] = matrix01[0][c];
	//		c++;
	//	}
	//}
	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm2[i][8] = 0 - (matrix01[2][i] * matrix01[0][i]);
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm2[i][9] = 0 - (matrix01[2][i] * matrix01[0][i + 1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm2[i][0] = 0;
	//	matrixm2[i][1] = 0;
	//	matrixm2[i][2] = 0;
	//	matrixm2[i][3] = 0;
	//	matrixm2[i][6] = 0;
	//	matrixm2[i][7] = 1;
	//	matrixm2[i][10] = 0;
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm2[i][2] = 0;
	//	matrixm2[i][3] = 1;
	//	matrixm2[i][4] = 0;
	//	matrixm2[i][5] = 0;
	//	matrixm2[i][6] = 0;
	//	matrixm2[i][7] = 0;
	//	matrixm2[i][10] = 0;
	//}

	//int d = 0;
	//for (int i = 1; i < 72; i = i + 2) {
	//	for (int j = 4; j < 6; j++) {
	//		matrixm2[i][j] = matrix01[0][d];
	//		d++;
	//	}
	//}
	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm2[i][8] = 0 - (matrix01[2][i] * matrix01[0][i - 1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm2[i][9] = 0 - (matrix01[2][i] * matrix01[0][i]);
	//}

	////third time 
	//c = 0;

	//for (int i = 0; i < 72; i = i + 2) {
	//	for (int j = 0; j < 2; j++) {
	//		matrixm3[i][j] = matrix01[0][c];
	//		c++;
	//	}
	//}
	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm3[i][8] = 0 - (matrix01[3][i] * matrix01[0][i]);
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm3[i][9] = 0 - (matrix01[3][i] * matrix01[0][i + 1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm3[i][0] = 0;
	//	matrixm3[i][1] = 0;
	//	matrixm3[i][2] = 0;
	//	matrixm3[i][3] = 0;
	//	matrixm3[i][6] = 0;
	//	matrixm3[i][7] = 1;
	//	matrixm3[i][10] = 0;
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm3[i][2] = 0;
	//	matrixm3[i][3] = 1;
	//	matrixm3[i][4] = 0;
	//	matrixm3[i][5] = 0;
	//	matrixm3[i][6] = 0;
	//	matrixm3[i][7] = 0;
	//	matrixm3[i][10] = 0;
	//}

	//d = 0;
	//for (int i = 1; i < 72; i = i + 2) {
	//	for (int j = 4; j < 6; j++) {
	//		matrixm3[i][j] = matrix01[0][d];
	//		d++;
	//	}
	//}
	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm3[i][8] = 0 - (matrix01[3][i] * matrix01[0][i - 1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm3[i][9] = 0 - (matrix01[3][i] * matrix01[0][i]);
	//}
	////forth time 
	//c = 0;

	//for (int i = 0; i < 72; i = i + 2) {
	//	for (int j = 0; j < 2; j++) {
	//		matrixm4[i][j] = matrix01[0][c];
	//		c++;
	//	}
	//}
	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm4[i][8] = 0 - (matrix01[4][i] * matrix01[0][i]);
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm4[i][9] = 0 - (matrix01[4][i] * matrix01[0][i + 1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm4[i][0] = 0;
	//	matrixm4[i][1] = 0;
	//	matrixm4[i][2] = 0;
	//	matrixm4[i][3] = 0;
	//	matrixm4[i][6] = 0;
	//	matrixm4[i][7] = 1;
	//	matrixm4[i][10] = 0;
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm4[i][2] = 0;
	//	matrixm4[i][3] = 1;
	//	matrixm4[i][4] = 0;
	//	matrixm4[i][5] = 0;
	//	matrixm4[i][6] = 0;
	//	matrixm4[i][7] = 0;
	//	matrixm4[i][10] = 0;
	//}

	//d = 0;
	//for (int i = 1; i < 72; i = i + 2) {
	//	for (int j = 4; j < 6; j++) {
	//		matrixm4[i][j] = matrix01[0][d];
	//		d++;
	//	}
	//}
	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm4[i][8] = 0 - (matrix01[4][i] * matrix01[0][i - 1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm4[i][9] = 0 - (matrix01[4][i] * matrix01[0][i]);
	//}

	////fifth time 
	//c = 0;

	//for (int i = 0; i < 72; i = i + 2) {
	//	for (int j = 0; j < 2; j++) {
	//		matrixm5[i][j] = matrix01[0][c];
	//		c++;
	//	}
	//}
	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm5[i][8] = 0 - (matrix01[5][i] * matrix01[0][i]);
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm5[i][9] = 0 - (matrix01[5][i] * matrix01[0][i + 1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm5[i][0] = 0;
	//	matrixm5[i][1] = 0;
	//	matrixm5[i][2] = 0;
	//	matrixm5[i][3] = 0;
	//	matrixm5[i][6] = 0;
	//	matrixm5[i][7] = 1;
	//	matrixm5[i][10] = 0;
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm5[i][2] = 0;
	//	matrixm5[i][3] = 1;
	//	matrixm5[i][4] = 0;
	//	matrixm5[i][5] = 0;
	//	matrixm5[i][6] = 0;
	//	matrixm5[i][7] = 0;
	//	matrixm5[i][10] = 0;
	//}

	//d = 0;
	//for (int i = 1; i < 72; i = i + 2) {
	//	for (int j = 4; j < 6; j++) {
	//		matrixm5[i][j] = matrix01[0][d];
	//		d++;
	//	}
	//}
	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm5[i][8] = 0 - (matrix01[5][i] * matrix01[0][i - 1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm5[i][9] = 0 - (matrix01[5][i] * matrix01[0][i]);
	//}

	////sixth time 
	//c = 0;

	//for (int i = 0; i < 72; i = i + 2) {
	//	for (int j = 0; j < 2; j++) {
	//		matrixm6[i][j] = matrix01[0][c];
	//		c++;
	//	}
	//}
	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm6[i][8] = 0 - (matrix01[6][i] * matrix01[0][i]);
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm6[i][9] = 0 - (matrix01[6][i] * matrix01[0][i + 1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm6[i][0] = 0;
	//	matrixm6[i][1] = 0;
	//	matrixm6[i][2] = 0;
	//	matrixm6[i][3] = 0;
	//	matrixm6[i][6] = 0;
	//	matrixm6[i][7] = 1;
	//	matrixm6[i][10] = 0;
	//}

	//for (int i = 0; i < 72; i = i + 2) {
	//	matrixm6[i][2] = 0;
	//	matrixm6[i][3] = 1;
	//	matrixm6[i][4] = 0;
	//	matrixm6[i][5] = 0;
	//	matrixm6[i][6] = 0;
	//	matrixm6[i][7] = 0;
	//	matrixm6[i][10] = 0;
	//}

	//d = 0;
	//for (int i = 1; i < 72; i = i + 2) {
	//	for (int j = 4; j < 6; j++) {
	//		matrixm6[i][j] = matrix01[0][d];
	//		d++;
	//	}
	//}
	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm6[i][8] = 0 - (matrix01[6][i] * matrix01[0][i - 1]);
	//}

	//for (int i = 1; i < 72; i = i + 2) {
	//	matrixm6[i][9] = 0 - (matrix01[6][i] * matrix01[0][i]);
	//}

	//print out 
	/*for (int i = 0; i < 72; i++) {
		for (int j = 0; j < 11; j++) {
			cout << matrixm2[i][j] << "  ";
		}
		cout << endl;
	}*/
	Mat mb = Mat::zeros(11, 1, CV_64F);
	Mat mb2 = Mat::zeros(11, 1, CV_64F);
	Mat mb3 = Mat::zeros(11, 1, CV_64F);
	Mat mb4 = Mat::zeros(11, 1, CV_64F);
	Mat mb5 = Mat::zeros(11, 1, CV_64F);
	Mat mb6 = Mat::zeros(11, 1, CV_64F);


	Mat matrixm01 = Mat::zeros(72, 11, CV_64F);
	Mat matrixm02 = Mat::zeros(72, 11, CV_64F);
	Mat matrixm03 = Mat::zeros(72, 11, CV_64F);
	Mat matrixm04 = Mat::zeros(72, 11, CV_64F);
	Mat matrixm05 = Mat::zeros(72, 11, CV_64F);
	Mat matrixm06 = Mat::zeros(72, 11, CV_64F);

	Mat matrixuv01 = Mat::zeros(72, 1, CV_64F);
	Mat matrixuv02 = Mat::zeros(72, 1, CV_64F);
	Mat matrixuv03 = Mat::zeros(72, 1, CV_64F);
	Mat matrixuv04 = Mat::zeros(72, 1, CV_64F);
	Mat matrixuv05 = Mat::zeros(72, 1, CV_64F);
	Mat matrixuv06 = Mat::zeros(72, 1, CV_64F);

	Mat h1 = Mat::zeros(3, 3, CV_64F);
	Mat h2 = Mat::zeros(3, 3, CV_64F);
	Mat h3 = Mat::zeros(3, 3, CV_64F);
	Mat h4 = Mat::zeros(3, 3, CV_64F);
	Mat h5 = Mat::zeros(3, 3, CV_64F);
	Mat h6 = Mat::zeros(3, 3, CV_64F);



	for (int i = 0; i < 72; i++) {
		matrixuv01.at<double>(i, 0) = matrix01[1][i];
		matrixuv02.at<double>(i, 0) = matrix01[2][i];
		matrixuv03.at<double>(i, 0) = matrix01[3][i];
		matrixuv04.at<double>(i, 0) = matrix01[4][i];
		matrixuv05.at<double>(i, 0) = matrix01[5][i];
		matrixuv06.at<double>(i, 0) = matrix01[6][i];
	}


    c = 0;

	for (int i = 0; i < 72; i = i + 2) {
		for (int j = 0; j < 2; j++) {
			matrixm01.at<double>(i, j) = matrix01[0][c];
			c++;
		}
	}
	for (int i = 0; i < 72; i = i + 2) {
		matrixm01.at<double>(i,8) = 0 - (matrix01[1][i] * matrix01[0][i]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm01.at<double>(i, 9) = 0 - (matrix01[1][i] * matrix01[0][i+1]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm01.at<double>(i, 2) = 0;
		matrixm01.at<double>(i, 3) = 1;
		matrixm01.at<double>(i, 4) = 0;
		matrixm01.at<double>(i, 5) = 0;
		matrixm01.at<double>(i, 6) = 0;
		matrixm01.at<double>(i, 7) = 0;
		matrixm01.at<double>(i, 10) = 0;
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm01.at<double>(i, 0) = 0;
		matrixm01.at<double>(i, 1) = 0;
		matrixm01.at<double>(i, 2) = 0;
		matrixm01.at<double>(i, 3) = 0;
		matrixm01.at<double>(i, 6) = 0;
		matrixm01.at<double>(i, 7) = 1;
		matrixm01.at<double>(i, 10) = 0;
	}

	 int d = 0;
	for (int i = 1; i < 72; i = i + 2) {
		for (int j = 4; j < 6; j++) {
			matrixm01.at<double>(i,j) = matrix01[0][d];
			d++;
		}
	}
	for (int i = 1; i < 72; i = i + 2) {
		matrixm01.at<double>(i,8) = 0 - (matrix01[1][i] * matrix01[0][i - 1]);
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm01.at<double>(i,9) = 0 - (matrix01[1][i] * matrix01[0][i]);
	}

	//2 

	c = 0;

	for (int i = 0; i < 72; i = i + 2) {
		for (int j = 0; j < 2; j++) {
			matrixm02.at<double>(i, j) = matrix01[0][c];
			c++;
		}
	}
	for (int i = 0; i < 72; i = i + 2) {
		matrixm02.at<double>(i, 8) = 0 - (matrix01[2][i] * matrix01[0][i]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm02.at<double>(i, 9) = 0 - (matrix01[2][i] * matrix01[0][i + 1]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm02.at<double>(i, 2) = 0;
		matrixm02.at<double>(i, 3) = 1;
		matrixm02.at<double>(i, 4) = 0;
		matrixm02.at<double>(i, 5) = 0;
		matrixm02.at<double>(i, 6) = 0;
		matrixm02.at<double>(i, 7) = 0;
		matrixm02.at<double>(i, 10) = 0;
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm02.at<double>(i, 0) = 0;
		matrixm02.at<double>(i, 1) = 0;
		matrixm02.at<double>(i, 2) = 0;
		matrixm02.at<double>(i, 3) = 0;
		matrixm02.at<double>(i, 6) = 0;
		matrixm02.at<double>(i, 7) = 1;
		matrixm02.at<double>(i, 10) = 0;
	}

	d = 0;
	for (int i = 1; i < 72; i = i + 2) {
		for (int j = 4; j < 6; j++) {
			matrixm02.at<double>(i, j) = matrix01[0][d];
			d++;
		}
	}
	for (int i = 1; i < 72; i = i + 2) {
		matrixm02.at<double>(i, 8) = 0 - (matrix01[2][i] * matrix01[0][i - 1]);
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm02.at<double>(i, 9) = 0 - (matrix01[2][i] * matrix01[0][i]);
	}

	//3
	c = 0;

	for (int i = 0; i < 72; i = i + 2) {
		for (int j = 0; j < 2; j++) {
			matrixm03.at<double>(i, j) = matrix01[0][c];
			c++;
		}
	}
	for (int i = 0; i < 72; i = i + 2) {
		matrixm03.at<double>(i, 8) = 0 - (matrix01[3][i] * matrix01[0][i]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm03.at<double>(i, 9) = 0 - (matrix01[3][i] * matrix01[0][i + 1]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm03.at<double>(i, 2) = 0;
		matrixm03.at<double>(i, 3) = 1;
		matrixm03.at<double>(i, 4) = 0;
		matrixm03.at<double>(i, 5) = 0;
		matrixm03.at<double>(i, 6) = 0;
		matrixm03.at<double>(i, 7) = 0;
		matrixm03.at<double>(i, 10) = 0;
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm03.at<double>(i, 0) = 0;
		matrixm03.at<double>(i, 1) = 0;
		matrixm03.at<double>(i, 2) = 0;
		matrixm03.at<double>(i, 3) = 0;
		matrixm03.at<double>(i, 6) = 0;
		matrixm03.at<double>(i, 7) = 1;
		matrixm03.at<double>(i, 10) = 0;
	}

	d = 0;
	for (int i = 1; i < 72; i = i + 2) {
		for (int j = 4; j < 6; j++) {
			matrixm03.at<double>(i, j) = matrix01[0][d];
			d++;
		}
	}
	for (int i = 1; i < 72; i = i + 2) {
		matrixm03.at<double>(i, 8) = 0 - (matrix01[4][i] * matrix01[0][i - 1]);
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm03.at<double>(i, 9) = 0 - (matrix01[4][i] * matrix01[0][i]);
	}

	//4
	c = 0;

	for (int i = 0; i < 72; i = i + 2) {
		for (int j = 0; j < 2; j++) {
			matrixm04.at<double>(i, j) = matrix01[0][c];
			c++;
		}
	}
	for (int i = 0; i < 72; i = i + 2) {
		matrixm04.at<double>(i, 8) = 0 - (matrix01[4][i] * matrix01[0][i]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm04.at<double>(i, 9) = 0 - (matrix01[4][i] * matrix01[0][i + 1]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm04.at<double>(i, 2) = 0;
		matrixm04.at<double>(i, 3) = 1;
		matrixm04.at<double>(i, 4) = 0;
		matrixm04.at<double>(i, 5) = 0;
		matrixm04.at<double>(i, 6) = 0;
		matrixm04.at<double>(i, 7) = 0;
		matrixm04.at<double>(i, 10) = 0;
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm04.at<double>(i, 0) = 0;
		matrixm04.at<double>(i, 1) = 0;
		matrixm04.at<double>(i, 2) = 0;
		matrixm04.at<double>(i, 3) = 0;
		matrixm04.at<double>(i, 6) = 0;
		matrixm04.at<double>(i, 7) = 1;
		matrixm04.at<double>(i, 10) = 0;
	}

	d = 0;
	for (int i = 1; i < 72; i = i + 2) {
		for (int j = 4; j < 6; j++) {
			matrixm04.at<double>(i, j) = matrix01[0][d];
			d++;
		}
	}
	for (int i = 1; i < 72; i = i + 2) {
		matrixm04.at<double>(i, 8) = 0 - (matrix01[4][i] * matrix01[0][i - 1]);
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm04.at<double>(i, 9) = 0 - (matrix01[4][i] * matrix01[0][i]);
	}

	//5

	c = 0;

	for (int i = 0; i < 72; i = i + 2) {
		for (int j = 0; j < 2; j++) {
			matrixm05.at<double>(i, j) = matrix01[0][c];
			c++;
		}
	}
	for (int i = 0; i < 72; i = i + 2) {
		matrixm05.at<double>(i, 8) = 0 - (matrix01[5][i] * matrix01[0][i]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm05.at<double>(i, 9) = 0 - (matrix01[5][i] * matrix01[0][i + 1]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm05.at<double>(i, 2) = 0;
		matrixm05.at<double>(i, 3) = 1;
		matrixm05.at<double>(i, 4) = 0;
		matrixm05.at<double>(i, 5) = 0;
		matrixm05.at<double>(i, 6) = 0;
		matrixm05.at<double>(i, 7) = 0;
		matrixm05.at<double>(i, 10) = 0;
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm05.at<double>(i, 0) = 0;
		matrixm05.at<double>(i, 1) = 0;
		matrixm05.at<double>(i, 2) = 0;
		matrixm05.at<double>(i, 3) = 0;
		matrixm05.at<double>(i, 6) = 0;
		matrixm05.at<double>(i, 7) = 1;
		matrixm05.at<double>(i, 10) = 0;
	}

	d = 0;
	for (int i = 1; i < 72; i = i + 2) {
		for (int j = 4; j < 6; j++) {
			matrixm05.at<double>(i, j) = matrix01[0][d];
			d++;
		}
	}
	for (int i = 1; i < 72; i = i + 2) {
		matrixm05.at<double>(i, 8) = 0 - (matrix01[5][i] * matrix01[0][i - 1]);
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm05.at<double>(i, 9) = 0 - (matrix01[5][i] * matrix01[0][i]);
	}

	//6
	c = 0;

	for (int i = 0; i < 72; i = i + 2) {
		for (int j = 0; j < 2; j++) {
			matrixm06.at<double>(i, j) = matrix01[0][c];
			c++;
		}
	}
	for (int i = 0; i < 72; i = i + 2) {
		matrixm06.at<double>(i, 8) = 0 - (matrix01[6][i] * matrix01[0][i]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm06.at<double>(i, 9) = 0 - (matrix01[6][i] * matrix01[0][i + 1]);
	}

	for (int i = 0; i < 72; i = i + 2) {
		matrixm06.at<double>(i, 2) = 0;
		matrixm06.at<double>(i, 3) = 1;
		matrixm06.at<double>(i, 4) = 0;
		matrixm06.at<double>(i, 5) = 0;
		matrixm06.at<double>(i, 6) = 0;
		matrixm06.at<double>(i, 7) = 0;
		matrixm06.at<double>(i, 10) = 0;
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm06.at<double>(i, 0) = 0;
		matrixm06.at<double>(i, 1) = 0;
		matrixm06.at<double>(i, 2) = 0;
		matrixm06.at<double>(i, 3) = 0;
		matrixm06.at<double>(i, 6) = 0;
		matrixm06.at<double>(i, 7) = 1;
		matrixm06.at<double>(i, 10) = 0;
	}

	d = 0;
	for (int i = 1; i < 72; i = i + 2) {
		for (int j = 4; j < 6; j++) {
			matrixm06.at<double>(i, j) = matrix01[0][d];
			d++;
		}
	}
	for (int i = 1; i < 72; i = i + 2) {
		matrixm06.at<double>(i, 8) = 0 - (matrix01[6][i] * matrix01[0][i - 1]);
	}

	for (int i = 1; i < 72; i = i + 2) {
		matrixm06.at<double>(i, 9) = 0 - (matrix01[6][i] * matrix01[0][i]);
	}


	//cout << matrixm02;
	mb = matrixm01.inv(DECOMP_SVD) * matrixuv01; 
	mb2 = matrixm02.inv(DECOMP_SVD) * matrixuv02;
	mb3 = matrixm03.inv(DECOMP_SVD) * matrixuv03;
	mb4 = matrixm04.inv(DECOMP_SVD) * matrixuv04;
	mb5 = matrixm05.inv(DECOMP_SVD) * matrixuv05;
	mb6 = matrixm06.inv(DECOMP_SVD) * matrixuv06;
	
	//cout << " mb1:  " << mb << endl << " mb2: " << mb2 << endl << "mb3: " << mb3 << endl << "mb4: " << mb4 << endl << "mb5: " << mb5 << endl;
	//cout << "mb6: " << mb6 << endl;

	h1.at<double>(0, 0) = mb.at<double>(0, 0);
	h1.at<double>(1, 0) = mb.at<double>(1, 0);
	h1.at<double>(2, 0) = mb.at<double>(3, 0);
	h1.at<double>(0, 1) = mb.at<double>(4, 0);
	h1.at<double>(1, 1) = mb.at<double>(5, 0);
	h1.at<double>(2, 1) = mb.at<double>(7, 0);
	h1.at<double>(0, 2) = mb.at<double>(8, 0);
	h1.at<double>(1, 2) = mb.at<double>(9, 0);
	h1.at<double>(2, 2) = 1;

	h2.at<double>(0, 0) = mb2.at<double>(0, 0);
	h2.at<double>(1, 0) = mb2.at<double>(1, 0);
	h2.at<double>(2, 0) = mb2.at<double>(3, 0);
	h2.at<double>(0, 1) = mb2.at<double>(4, 0);
	h2.at<double>(1, 1) = mb2.at<double>(5, 0);
	h2.at<double>(2, 1) = mb2.at<double>(7, 0);
	h2.at<double>(0, 2) = mb2.at<double>(8, 0);
	h2.at<double>(1, 2) = mb2.at<double>(9, 0);
	h2.at<double>(2, 2) = 1;

	h3.at<double>(0, 0) = mb3.at<double>(0, 0);
	h3.at<double>(1, 0) = mb3.at<double>(1, 0);
	h3.at<double>(2, 0) = mb3.at<double>(3, 0);
	h3.at<double>(0, 1) = mb3.at<double>(4, 0);
	h3.at<double>(1, 1) = mb3.at<double>(5, 0);
	h3.at<double>(2, 1) = mb3.at<double>(7, 0);
	h3.at<double>(0, 2) = mb3.at<double>(8, 0);
	h3.at<double>(1, 2) = mb3.at<double>(9, 0);
	h3.at<double>(2, 2) = 1;

	h4.at<double>(0, 0) = mb4.at<double>(0, 0);
	h4.at<double>(1, 0) = mb4.at<double>(1, 0);
	h4.at<double>(2, 0) = mb4.at<double>(3, 0);
	h4.at<double>(0, 1) = mb4.at<double>(4, 0);
	h4.at<double>(1, 1) = mb4.at<double>(5, 0);
	h4.at<double>(2, 1) = mb4.at<double>(7, 0);
	h4.at<double>(0, 2) = mb4.at<double>(8, 0);
	h4.at<double>(1, 2) = mb4.at<double>(9, 0);
	h4.at<double>(2, 2) = 1;

	h5.at<double>(0, 0) = mb5.at<double>(0, 0);
	h5.at<double>(1, 0) = mb5.at<double>(1, 0);
	h5.at<double>(2, 0) = mb5.at<double>(3, 0);
	h5.at<double>(0, 1) = mb5.at<double>(4, 0);
	h5.at<double>(1, 1) = mb5.at<double>(5, 0);
	h5.at<double>(2, 1) = mb5.at<double>(7, 0);
	h5.at<double>(0, 2) = mb5.at<double>(8, 0);
	h5.at<double>(1, 2) = mb5.at<double>(9, 0);
	h5.at<double>(2, 2) = 1;

	h6.at<double>(0, 0) = mb6.at<double>(0, 0);
	h6.at<double>(1, 0) = mb6.at<double>(1, 0);
	h6.at<double>(2, 0) = mb6.at<double>(3, 0);
	h6.at<double>(0, 1) = mb6.at<double>(4, 0);
	h6.at<double>(1, 1) = mb6.at<double>(5, 0);
	h6.at<double>(2, 1) = mb6.at<double>(7, 0);
	h6.at<double>(0, 2) = mb6.at<double>(8, 0);
	h6.at<double>(1, 2) = mb6.at<double>(9, 0);
	h6.at<double>(2, 2) = 1;

	//V12
	Mat v1201 = Mat::zeros(1, 6, CV_64F);
	Mat v1202 = Mat::zeros(1, 6, CV_64F);
	Mat v1203 = Mat::zeros(1, 6, CV_64F);
	Mat v1204 = Mat::zeros(1, 6, CV_64F);
	Mat v1205 = Mat::zeros(1, 6, CV_64F);
	Mat v1206 = Mat::zeros(1, 6, CV_64F);

	Mat v1101 = Mat::zeros(1, 6, CV_64F);
	Mat v1102 = Mat::zeros(1, 6, CV_64F);
	Mat v1103 = Mat::zeros(1, 6, CV_64F);
	Mat v1104 = Mat::zeros(1, 6, CV_64F);
	Mat v1105 = Mat::zeros(1, 6, CV_64F);
	Mat v1106 = Mat::zeros(1, 6, CV_64F);

	Mat V1 = Mat::zeros(2, 6, CV_64F);
	Mat V2 = Mat::zeros(2, 6, CV_64F);
	Mat V3 = Mat::zeros(2, 6, CV_64F);
	Mat V4 = Mat::zeros(2, 6, CV_64F);
	Mat V5 = Mat::zeros(2, 6, CV_64F);
	Mat V6 = Mat::zeros(2, 6, CV_64F);
	
	v1201.at<double>(0, 0) = h1.at<double>(0, 0) * h1.at<double>(1, 0);
	v1201.at<double>(0, 1) = h1.at<double>(0, 0) * h1.at<double>(1, 1) + h1.at<double>(0, 1)*h1.at<double>(1, 0);
	v1201.at<double>(0, 2) = h1.at<double>(0, 1) * h1.at<double>(1, 1);
	v1201.at<double>(0, 3) = h1.at<double>(0, 2) * h1.at<double>(1, 0) + h1.at<double>(0, 0)*h1.at<double>(1, 2);
	v1201.at<double>(0, 4) = h1.at<double>(0, 2) * h1.at<double>(1, 1) + h1.at<double>(0, 1)*h1.at<double>(1, 2);
	v1201.at<double>(0, 5) = h1.at<double>(0, 2) * h1.at<double>(1, 2);


	v1202.at<double>(0, 0) = h2.at<double>(0, 0) * h2.at<double>(1, 0);
	v1202.at<double>(0, 1) = h2.at<double>(0, 0) * h2.at<double>(1, 1) + h2.at<double>(0, 1)*h2.at<double>(1, 0);
	v1202.at<double>(0, 2) = h2.at<double>(0, 1) * h2.at<double>(1, 1);
	v1202.at<double>(0, 3) = h2.at<double>(0, 2) * h2.at<double>(1, 0) + h2.at<double>(0, 0)*h2.at<double>(1, 2);
	v1202.at<double>(0, 4) = h2.at<double>(0, 2) * h2.at<double>(1, 1) + h2.at<double>(0, 1)*h2.at<double>(1, 2);
	v1202.at<double>(0, 5) = h2.at<double>(0, 2) * h2.at<double>(1, 2);

	v1203.at<double>(0, 0) = h3.at<double>(0, 0) * h3.at<double>(1, 0);
	v1203.at<double>(0, 1) = h3.at<double>(0, 0) * h3.at<double>(1, 1) + h3.at<double>(0, 1)*h3.at<double>(1, 0);
	v1203.at<double>(0, 2) = h3.at<double>(0, 1) * h3.at<double>(1, 1);
	v1203.at<double>(0, 3) = h3.at<double>(0, 2) * h3.at<double>(1, 0) + h3.at<double>(0, 0)*h3.at<double>(1, 2);
	v1203.at<double>(0, 4) = h3.at<double>(0, 2) * h3.at<double>(1, 1) + h3.at<double>(0, 1)*h3.at<double>(1, 2);
	v1203.at<double>(0, 5) = h3.at<double>(0, 2) * h3.at<double>(1, 2);


	v1204.at<double>(0, 0) = h4.at<double>(0, 0) * h4.at<double>(1, 0);
	v1204.at<double>(0, 1) = h4.at<double>(0, 0) * h4.at<double>(1, 1) + h4.at<double>(0, 1)*h4.at<double>(1, 0);
	v1204.at<double>(0, 2) = h4.at<double>(0, 1) * h4.at<double>(1, 1);
	v1204.at<double>(0, 3) = h4.at<double>(0, 2) * h4.at<double>(1, 0) + h4.at<double>(0, 0)*h4.at<double>(1, 2);
	v1204.at<double>(0, 4) = h4.at<double>(0, 2) * h4.at<double>(1, 1) + h4.at<double>(0, 1)*h4.at<double>(1, 2);
	v1204.at<double>(0, 5) = h4.at<double>(0, 2) * h4.at<double>(1, 2);

	v1205.at<double>(0, 0) = h5.at<double>(0, 0) * h5.at<double>(1, 0);
	v1205.at<double>(0, 1) = h5.at<double>(0, 0) * h5.at<double>(1, 1) + h5.at<double>(0, 1)*h5.at<double>(1, 0);
	v1205.at<double>(0, 2) = h5.at<double>(0, 1) * h5.at<double>(1, 1);
	v1205.at<double>(0, 3) = h5.at<double>(0, 2) * h5.at<double>(1, 0) + h5.at<double>(0, 0)*h5.at<double>(1, 2);
	v1205.at<double>(0, 4) = h5.at<double>(0, 2) * h5.at<double>(1, 1) + h5.at<double>(0, 1)*h5.at<double>(1, 2);
	v1205.at<double>(0, 5) = h5.at<double>(0, 2) * h5.at<double>(1, 2);

	v1206.at<double>(0, 0) = h6.at<double>(0, 0) * h6.at<double>(1, 0);
	v1206.at<double>(0, 1) = h6.at<double>(0, 0) * h6.at<double>(1, 1) + h6.at<double>(0, 1)*h6.at<double>(1, 0);
	v1206.at<double>(0, 2) = h6.at<double>(0, 1) * h6.at<double>(1, 1);
	v1206.at<double>(0, 3) = h6.at<double>(0, 2) * h6.at<double>(1, 0) + h6.at<double>(0, 0)*h6.at<double>(1, 2);
	v1206.at<double>(0, 4) = h6.at<double>(0, 2) * h6.at<double>(1, 1) + h6.at<double>(0, 1)*h6.at<double>(1, 2);
	v1206.at<double>(0, 5) = h6.at<double>(0, 2) * h6.at<double>(1, 2);

	v1101.at<double>(0, 0) = h1.at<double>(0, 0)*h1.at<double>(0, 0) - h1.at<double>(1, 0)*h1.at<double>(1, 0);
	v1101.at<double>(0, 1) = h1.at<double>(0, 0)*h1.at<double>(0, 1) + h1.at<double>(0, 1)*h1.at<double>(0,0)-h1.at<double>(1,0)*h1.at<double>(1,1)-h1.at<double>(1,1)*h1.at<double>(1,0);
	v1101.at<double>(0, 2) = h1.at<double>(0, 1)*h1.at<double>(0, 1) - h1.at<double>(1, 1)*h1.at<double>(1, 1);
	v1101.at<double>(0, 3) = h1.at<double>(0, 2)*h1.at<double>(0, 0) + h1.at<double>(0, 0)*h1.at<double>(0, 2)-h1.at<double>(1,2)*h1.at<double>(1,0)-h1.at<double>(1,0)*h1.at<double>(1,2);
	v1101.at<double>(0, 4) = h1.at<double>(0, 2)*h1.at<double>(0, 1) + h1.at<double>(0, 1)*h1.at<double>(0, 2) - h1.at<double>(1, 2)*h1.at<double>(1, 1) - h1.at<double>(1, 1)*h1.at<double>(1, 2);
	v1101.at<double>(0, 5) = h1.at<double>(0, 2)*h1.at<double>(0, 2) - h1.at<double>(1, 2)*h1.at<double>(1, 2);

	v1102.at<double>(0, 0) = h2.at<double>(0, 0)*h2.at<double>(0, 0) - h2.at<double>(1, 0)*h2.at<double>(1, 0);
	v1102.at<double>(0, 1) = h2.at<double>(0, 0)*h2.at<double>(0, 1) + h2.at<double>(0, 1)*h2.at<double>(0, 0) - h2.at<double>(1, 0)*h2.at<double>(1, 1) - h2.at<double>(1, 1) *h2.at<double>(1, 0);
	v1102.at<double>(0, 2) = h2.at<double>(0, 1)*h2.at<double>(0, 1) - h2.at<double>(1, 1)*h2.at<double>(1, 1);
	v1102.at<double>(0, 3) = h2.at<double>(0, 2)*h2.at<double>(0, 0) + h2.at<double>(0, 0)*h2.at<double>(0, 2) - h2.at<double>(1, 2)*h2.at<double>(1, 0) - h2.at<double>(1, 0)*h2.at<double>(1, 2);
	v1102.at<double>(0, 4) = h2.at<double>(0, 2)*h2.at<double>(0, 1) + h2.at<double>(0, 1)*h2.at<double>(0, 2) - h2.at<double>(1, 2)*h2.at<double>(1, 1) - h2.at<double>(1, 1)*h2.at<double>(1, 2);
	v1102.at<double>(0, 5) = h2.at<double>(0, 2)*h2.at<double>(0, 2) - h2.at<double>(1, 2)*h2.at<double>(1, 2);

	v1103.at<double>(0, 0) = h3.at<double>(0, 0)*h3.at<double>(0, 0) - h3.at<double>(1, 0)*h3.at<double>(1, 0);
	v1103.at<double>(0, 1) = h3.at<double>(0, 0)*h3.at<double>(0, 1) + h3.at<double>(0, 1)*h3.at<double>(0, 0) - h3.at<double>(1, 0)*h3.at<double>(1, 1) - h3.at<double>(1, 1) * h3.at<double>(1, 0);
	v1103.at<double>(0, 2) = h3.at<double>(0, 1)*h3.at<double>(0, 1) - h3.at<double>(1, 1)*h3.at<double>(1, 1);
	v1103.at<double>(0, 3) = h3.at<double>(0, 2)*h3.at<double>(0, 0) + h3.at<double>(0, 0)*h3.at<double>(0, 2) - h3.at<double>(1, 2)*h3.at<double>(1, 0) - h3.at<double>(1, 0)*h3.at<double>(1, 2);
	v1103.at<double>(0, 4) = h3.at<double>(0, 2)*h3.at<double>(0, 1) + h3.at<double>(0, 1)*h3.at<double>(0, 2) - h3.at<double>(1, 2)*h3.at<double>(1, 1) - h3.at<double>(1, 1)*h3.at<double>(1, 2);
	v1103.at<double>(0, 5) = h3.at<double>(0, 2)*h3.at<double>(0, 2) - h3.at<double>(1, 2)*h3.at<double>(1, 2);
	

	v1104.at<double>(0, 0) = h4.at<double>(0, 0)*h4.at<double>(0, 0) - h4.at<double>(1, 0)*h4.at<double>(1, 0);
	v1104.at<double>(0, 1) = h4.at<double>(0, 0)*h4.at<double>(0, 1) + h4.at<double>(0, 1)*h4.at<double>(0, 0) - h4.at<double>(1, 0)*h4.at<double>(1, 1) - h4.at<double>(1, 1) * h4.at<double>(1, 0);
	v1104.at<double>(0, 2) = h4.at<double>(0, 1)*h4.at<double>(0, 1) - h4.at<double>(1, 1)*h4.at<double>(1, 1);
	v1104.at<double>(0, 3) = h4.at<double>(0, 2)*h4.at<double>(0, 0) + h4.at<double>(0, 0)*h4.at<double>(0, 2) - h4.at<double>(1, 2)*h4.at<double>(1, 0) - h4.at<double>(1, 0)*h4.at<double>(1, 2);
	v1104.at<double>(0, 4) = h4.at<double>(0, 2)*h4.at<double>(0, 1) + h4.at<double>(0, 1)*h4.at<double>(0, 2) - h4.at<double>(1, 2)*h4.at<double>(1, 1) - h4.at<double>(1, 1)*h4.at<double>(1, 2);
	v1104.at<double>(0, 5) = h4.at<double>(0, 2)*h4.at<double>(0, 2) - h4.at<double>(1, 2)*h4.at<double>(1, 2);

	v1105.at<double>(0, 0) = h5.at<double>(0, 0)*h5.at<double>(0, 0) - h5.at<double>(1, 0)*h5.at<double>(1, 0);
	v1105.at<double>(0, 1) = h5.at<double>(0, 0)*h5.at<double>(0, 1) + h5.at<double>(0, 1)*h5.at<double>(0, 0) - h5.at<double>(1, 0)*h5.at<double>(1, 1) - h5.at<double>(1, 1) * h5.at<double>(1, 0);
	v1105.at<double>(0, 2) = h5.at<double>(0, 1)*h5.at<double>(0, 1) - h5.at<double>(1, 1)*h5.at<double>(1, 1);
	v1105.at<double>(0, 3) = h5.at<double>(0, 2)*h5.at<double>(0, 0) + h5.at<double>(0, 0)*h5.at<double>(0, 2) - h5.at<double>(1, 2)*h5.at<double>(1, 0) - h5.at<double>(1, 0)*h5.at<double>(1, 2);
	v1105.at<double>(0, 4) = h5.at<double>(0, 2)*h5.at<double>(0, 1) + h5.at<double>(0, 1)*h5.at<double>(0, 2) - h5.at<double>(1, 2)*h5.at<double>(1, 1) - h5.at<double>(1, 1)*h5.at<double>(1, 2);
	v1105.at<double>(0, 5) = h5.at<double>(0, 2)*h5.at<double>(0, 2) - h5.at<double>(1, 2)*h5.at<double>(1, 2);


	v1106.at<double>(0, 0) = h6.at<double>(0, 0)*h6.at<double>(0, 0) - h6.at<double>(1, 0)*h6.at<double>(1, 0);
	v1106.at<double>(0, 1) = h6.at<double>(0, 0)*h6.at<double>(0, 1) + h6.at<double>(0, 1)*h6.at<double>(0, 0) - h6.at<double>(1, 0)*h6.at<double>(1, 1) - h6.at<double>(1, 1) * h6.at<double>(1, 0);
	v1106.at<double>(0, 2) = h6.at<double>(0, 1)*h6.at<double>(0, 1) - h6.at<double>(1, 1)*h6.at<double>(1, 1);
	v1106.at<double>(0, 3) = h6.at<double>(0, 2)*h6.at<double>(0, 0) + h6.at<double>(0, 0)*h6.at<double>(0, 2) - h6.at<double>(1, 2)*h6.at<double>(1, 0) - h6.at<double>(1, 0)*h6.at<double>(1, 2);
	v1106.at<double>(0, 4) = h6.at<double>(0, 2)*h6.at<double>(0, 1) + h6.at<double>(0, 1)*h6.at<double>(0, 2) - h6.at<double>(1, 2)*h6.at<double>(1, 1) - h6.at<double>(1, 1)*h6.at<double>(1, 2);
	v1106.at<double>(0, 5) = h6.at<double>(0, 2)*h6.at<double>(0, 2) - h6.at<double>(1, 2)*h6.at<double>(1, 2);

	V1.row(0) = v1201.row(0) + 0;
	V1.row(1) = v1101.row(0) + 0;
	V2.row(0) = v1202.row(0)+0;
	V2.row(1) = v1102.row(0)+0;
	V3.row(0) = v1203.row(0)+0;
	V3.row(1) = v1103.row(0)+0;
	V4.row(0) = v1204.row(0)+0;
	V4.row(1) = v1104.row(0)+0;
	V5.row(0) = v1205.row(0)+0;
	V5.row(1) = v1105.row(0)+0;
	V6.row(0) = v1206.row(0)+0;
	V6.row(1) = v1106.row(0)+0;


	Mat bigV = Mat::zeros(12, 6, CV_64F);

	bigV.row(0) = V1.row(0)+0;
	bigV.row(1) = V1.row(1)+0;
	bigV.row(2) = V2.row(0)+0;
	bigV.row(3) = V2.row(1)+0;
	bigV.row(4) = V3.row(0)+0;
	bigV.row(5) = V3.row(1)+0;
	bigV.row(6) = V4.row(0)+0;
	bigV.row(7) = V4.row(1)+0; 
	bigV.row(8) = V5.row(0)+0;
	bigV.row(9) = V5.row(1)+0;
	bigV.row(10) = V6.row(0)+0;
	bigV.row(11) = V6.row(1)+0;

	Mat Vbright = Mat::zeros(12, 1, CV_64F);
	Vbright.col(0) = 0 - bigV.col(5)+0;
	
	Mat smallV = Mat::zeros(12, 5, CV_64F);
	smallV.col(0) = bigV.col(0)+0;
	smallV.col(1) = bigV.col(1)+0;
	smallV.col(2) = bigV.col(2)+0;
	smallV.col(3) = bigV.col(3)+0;
	smallV.col(4) = bigV.col(4)+0;

	Mat finalb = Mat::zeros(5, 1, CV_64F);
	
	finalb = smallV.inv(DECOMP_SVD) * Vbright;

	cout << "finalb" << finalb << endl;

	float lambda , u0, v0, fx, fy = 0;
	float alpha, beta;
	float gama;

	v0 = (finalb.at<double>(1, 0)*finalb.at<double>(3, 0) - finalb.at<double>(0, 0)*finalb.at<double>(4, 0)) / (finalb.at<double>(0, 0)*finalb.at<double>(2, 0) - finalb.at<double>(1, 0)*finalb.at<double>(1, 0));
	lambda = 1 - ((finalb.at<double>(3, 0)*finalb.at<double>(3, 0) + v0*(finalb.at<double>(1, 0)*finalb.at<double>(3, 0) - finalb.at<double>(0, 0)*finalb.at<double>(4, 0))) / finalb.at<double>(0, 0));
	alpha = sqrt(lambda/ finalb.at<double>(0, 0));
	beta = sqrt(lambda* finalb.at<double>(0, 0) / (finalb.at<double>(0, 0)*finalb.at<double>(2, 0) - finalb.at<double>(1, 0)*finalb.at<double>(1, 0)));
	gama = 0 - (finalb.at<double>(1, 0)*alpha*alpha*beta / lambda);
	u0 = (gama * v0 / beta) - (finalb.at<double>(3, 0)*alpha*alpha / lambda);
	u0 = abs(u0);



	cout << "v0: " << v0 << endl << "lambda = " << lambda << endl << "alpha: " << alpha << endl << "beta: " << beta << endl << "gama: " << gama << endl << "u0: " << u0 << endl;
	/*cout << a << endl;

	for (int j = 0; j < 7; j++) {

		for (int i = 0; i < 36; i++) {
			cout << matrix01[j][i] << "  ";
		}
		cout << endl;
	}*/

	ofstream outfilecamera;

	outfile.open("Camera.txt", ios::trunc);

	outfile << alpha << " " << beta << endl << u0 << " " << v0 << endl << gama << endl;


	Mat finalH11 = Mat::zeros(3, 1, CV_64F);
	Mat finalH12 = Mat::zeros(3, 1, CV_64F);
	Mat finalH13 = Mat::zeros(3, 1, CV_64F);
	Mat finalH21 = Mat::zeros(3, 1, CV_64F);
	Mat finalH22 = Mat::zeros(3, 1, CV_64F);
	Mat finalH23 = Mat::zeros(3, 1, CV_64F);
	Mat finalH31 = Mat::zeros(3, 1, CV_64F);
	Mat finalH32 = Mat::zeros(3, 1, CV_64F);
	Mat finalH33 = Mat::zeros(3, 1, CV_64F);
	Mat finalH41 = Mat::zeros(3, 1, CV_64F);
	Mat finalH42 = Mat::zeros(3, 1, CV_64F);
	Mat finalH43 = Mat::zeros(3, 1, CV_64F);
	Mat finalH51 = Mat::zeros(3, 1, CV_64F);
	Mat finalH52 = Mat::zeros(3, 1, CV_64F);
	Mat finalH53 = Mat::zeros(3, 1, CV_64F);
	Mat finalH61 = Mat::zeros(3, 1, CV_64F);
	Mat finalH62 = Mat::zeros(3, 1, CV_64F);
	Mat finalH63 = Mat::zeros(3, 1, CV_64F);


	finalH11.col(0) = h1.row(0).t();
	finalH12.col(0) = h1.row(1).t();
	finalH13.col(0) = h1.row(2).t()+0;
	finalH21.col(0) = h2.row(0).t();
	finalH22.col(0) = h2.row(1).t();
	finalH23.col(0) = h2.row(2).t()+0;
	finalH31.col(0) = h3.row(0).t();
	finalH32.col(0) = h3.row(1).t();
	finalH33.col(0) = h3.row(2).t();
	finalH41.col(0) = h4.row(0).t();
	finalH42.col(0) = h4.row(1).t();
	finalH43.col(0) = h4.row(2).t();
	finalH51.col(0) = h5.row(0).t();
	finalH52.col(0) = h5.row(1).t();
	finalH53.col(0) = h5.row(2).t();
	finalH61.col(0) = h6.row(0).t();
	finalH62.col(0) = h6.row(1).t();
	finalH63.col(0) = h6.row(2).t();


	//cout << finalH11 << " " << finalH12 << " " << finalH13 << endl << finalH21 << " " << finalH22 << " " << finalH23;
	Mat finalr11 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r1 , x rotation
	Mat finalr12 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r2, y rotation
	Mat finalr13 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r3, z rotation (r1 與 r2相乘 一個對一個)
	Mat finalt1 = Mat::zeros(3, 1, CV_64F);   // 平移

	Mat MatrixA = Mat::zeros(3,3,CV_64F);
	//cvCrossProduct(mat1, mat2, resultmat);

	Mat finalr21 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r1 , x rotation
	Mat finalr22 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r2, y rotation
	Mat finalr23 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r3, z rotation (r1 與 r2相乘 一個對一個)
	Mat finalt2 = Mat::zeros(3, 1, CV_64F);   // 平移

	Mat finalr31 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r1 , x rotation
	Mat finalr32 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r2, y rotation
	Mat finalr33 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r3, z rotation (r1 與 r2相乘 一個對一個)
	Mat finalt3 = Mat::zeros(3, 1, CV_64F);   // 平移

	Mat finalr41 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r1 , x rotation
	Mat finalr42 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r2, y rotation
	Mat finalr43 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r3, z rotation (r1 與 r2相乘 一個對一個)
	Mat finalt4 = Mat::zeros(3, 1, CV_64F);   // 平移

	Mat finalr51 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r1 , x rotation
	Mat finalr52 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r2, y rotation
	Mat finalr53 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r3, z rotation (r1 與 r2相乘 一個對一個)
	Mat finalt5 = Mat::zeros(3, 1, CV_64F);   // 平移

	Mat finalr61 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r1 , x rotation
	Mat finalr62 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r2, y rotation
	Mat finalr63 = Mat::zeros(3, 1, CV_64F);  //地一張圖的r3, z rotation (r1 與 r2相乘 一個對一個)
	Mat finalt6 = Mat::zeros(3, 1, CV_64F);   // 平移

	
	MatrixA.at<double>(0, 0) = alpha;
	MatrixA.at<double>(0, 1) = gama;
	MatrixA.at<double>(0, 2) = u0;
	MatrixA.at<double>(1, 0) = 0;
	MatrixA.at<double>(1, 1) = beta;
	MatrixA.at<double>(1, 2) = v0;
	MatrixA.at<double>(2, 0) = 0;
	MatrixA.at<double>(2, 1) = 0;
	MatrixA.at<double>(2, 2) = 1;
	cout << endl;
	cout << MatrixA;


	//cout << finalH2;

	lambda = 1 / norm(MatrixA.inv(DECOMP_SVD)*finalH11);

	finalr11 = lambda * MatrixA.inv(DECOMP_SVD) * finalH11;
	finalr12 = lambda * MatrixA.inv(DECOMP_SVD) * finalH12;
	finalr13 = finalr11.cross(finalr12);
	finalt1 = lambda * MatrixA.inv(DECOMP_SVD) * finalH13;

	cout << endl;
	cout << finalr11 << endl << finalr12 << endl << finalr13 << endl << finalt1<<endl;
	cout << lambda;

	lambda = 1 / norm(MatrixA.inv(DECOMP_SVD)*finalH21);
	

	finalr21 = lambda * MatrixA.inv(DECOMP_SVD) * finalH21;
	finalr22 = lambda * MatrixA.inv(DECOMP_SVD) * finalH22;
	finalr23 = finalr21.cross(finalr22);
	finalt2 = lambda * MatrixA.inv(DECOMP_SVD) * finalH23;

	lambda = 1 / norm(MatrixA.inv(DECOMP_SVD)*finalH31);

	finalr31 = lambda * MatrixA.inv(DECOMP_SVD) * finalH31;
	finalr32 = lambda * MatrixA.inv(DECOMP_SVD) * finalH32;
	finalr33 = finalr31.cross(finalr32);
	finalt3 = lambda * MatrixA.inv(DECOMP_SVD) * finalH33;

	lambda = 1 / norm(MatrixA.inv(DECOMP_SVD)*finalH41);
	finalr41 = lambda * MatrixA.inv(DECOMP_SVD) * finalH41;
	finalr42 = lambda * MatrixA.inv(DECOMP_SVD) * finalH42;
	finalr43 = finalr41.cross(finalr42);
	finalt4 = lambda * MatrixA.inv(DECOMP_SVD) * finalH43;
	lambda = 1 / norm(MatrixA.inv(DECOMP_SVD)*finalH51);
	finalr51 = lambda * MatrixA.inv(DECOMP_SVD) * finalH51;
	finalr52 = lambda * MatrixA.inv(DECOMP_SVD) * finalH52;
	finalr53 = finalr51.cross(finalr52);
	finalt5 = lambda * MatrixA.inv(DECOMP_SVD) * finalH53;

	lambda = 1 / norm(MatrixA.inv(DECOMP_SVD)*finalH61);
	finalr61 = lambda * MatrixA.inv(DECOMP_SVD) * finalH61;
	finalr62 = lambda * MatrixA.inv(DECOMP_SVD) * finalH62;
	finalr63 = finalr61.cross(finalr62);
	finalt6 = lambda * MatrixA.inv(DECOMP_SVD) * finalH63;
	


	//cout << "finalt1" << finalH13.col(0) << " " << finalH23.col(0) << " " << finalt3 << " " << finalt4 << " " << finalt5;

	//euler
	float cida1, cida2, fi1, fi2, omega1, omega2;

	
	//if (finalr11.at<double>(2, 0) != 1 && finalr12.at<double>(2, 0) != -1) {

	cida1 = - asin(finalr11.at<double>(2, 0));
	cida2 = PI - cida1;

	fi1 = atan2(finalr12.at<double>(2,0)/cos(cida1),finalr13.at<double>(2,0)/cos(cida1));
	fi2 = atan2(finalr12.at<double>(2,0) / cos(cida2), finalr13.at<double>(2, 0) / cos(cida2));
	
	omega1 = atan2(finalr11.at<double>(1, 0) / cos(cida1), finalr11.at<double>(0, 0) / cos(cida1));
	omega2 = atan2(finalr11.at<double>(1, 0) / cos(cida2), finalr11.at<double>(0, 0) / cos(cida2));
	//}


	outfile << fi1 * 180 / PI << " " << cida1 * 180 / PI << " " << omega1 * 180 / PI << endl;
	outfile << finalt1.at<double>(0, 0) << " " << finalt1.at<double>(1, 0) << " " << finalt1.at<double>(2, 0) << endl;


	cida1 = -asin(finalr21.at<double>(2, 0));
	cida2 = PI - cida1;

	fi1 = atan2(finalr22.at<double>(2, 0) / cos(cida1), finalr23.at<double>(2, 0) / cos(cida1));
	fi2 = atan2(finalr22.at<double>(2, 0) / cos(cida2), finalr23.at<double>(2, 0) / cos(cida2));

	omega1 = atan2(finalr21.at<double>(1, 0) / cos(cida1), finalr21.at<double>(0, 0) / cos(cida1));
	omega2 = atan2(finalr21.at<double>(1, 0) / cos(cida2), finalr21.at<double>(0, 0) / cos(cida2));

	outfile << fi1 * 180 / PI << " " << cida1 * 180 / PI << " " << omega1 * 180 / PI << endl;
	outfile << finalt2.at<double>(0, 0) << " " << finalt2.at<double>(1, 0) << " " << finalt2.at<double>(2, 0) <<endl;


	cida1 = -asin(finalr31.at<double>(2, 0));
	cida2 = PI - cida1;

	fi1 = atan2(finalr32.at<double>(2, 0) / cos(cida1), finalr33.at<double>(2, 0) / cos(cida1));
	fi2 = atan2(finalr32.at<double>(2, 0) / cos(cida2), finalr33.at<double>(2, 0) / cos(cida2));

	omega1 = atan2(finalr31.at<double>(1, 0) / cos(cida1), finalr31.at<double>(0, 0) / cos(cida1));
	omega2 = atan2(finalr31.at<double>(1, 0) / cos(cida2), finalr31.at<double>(0, 0) / cos(cida2));

	outfile << fi1 * 180 / PI << " " << cida1 * 180 / PI << " " << omega1 * 180 / PI << endl ;
	outfile << finalt3.at<double>(0, 0) << " " << finalt3.at<double>(1, 0) << " " << finalt3.at<double>(2, 0) << endl;

	cida1 = -asin(finalr21.at<double>(2, 0));
	cida2 = PI - cida1;

	fi1 = atan2(finalr42.at<double>(2, 0) / cos(cida1), finalr43.at<double>(2, 0) / cos(cida1));
	fi2 = atan2(finalr42.at<double>(2, 0) / cos(cida2), finalr43.at<double>(2, 0) / cos(cida2));

	omega1 = atan2(finalr41.at<double>(1, 0) / cos(cida1), finalr41.at<double>(0, 0) / cos(cida1));
	omega2 = atan2(finalr41.at<double>(1, 0) / cos(cida2), finalr41.at<double>(0, 0) / cos(cida2));

	outfile << fi1 * 180 / PI << " " << cida1 * 180 / PI << " " << omega1 * 180 / PI << endl;
	outfile << finalt4.at<double>(0, 0) << " " << finalt4.at<double>(1, 0) << " " << finalt4.at<double>(2, 0) << endl;


	cida1 = -asin(finalr51.at<double>(2, 0));
	cida2 = PI - cida1;

	fi1 = atan2(finalr52.at<double>(2, 0) / cos(cida1), finalr53.at<double>(2, 0) / cos(cida1));
	fi2 = atan2(finalr52.at<double>(2, 0) / cos(cida2), finalr53.at<double>(2, 0) / cos(cida2));

	omega1 = atan2(finalr51.at<double>(1, 0) / cos(cida1), finalr51.at<double>(0, 0) / cos(cida1));
	omega2 = atan2(finalr51.at<double>(1, 0) / cos(cida2), finalr51.at<double>(0, 0) / cos(cida2));

	outfile << fi1 * 180 / PI << " " << cida1 * 180 / PI << " " << omega1 * 180 / PI << endl;
	outfile << finalt5.at<double>(0, 0) << " " << finalt5.at<double>(1, 0) << " " << finalt5.at<double>(2, 0) << endl;

	cida1 = -asin(finalr21.at<double>(2, 0));
	cida2 = PI - cida1;

	fi1 = atan2(finalr62.at<double>(2, 0) / cos(cida1), finalr63.at<double>(2, 0) / cos(cida1));
	fi2 = atan2(finalr62.at<double>(2, 0) / cos(cida2), finalr23.at<double>(2, 0) / cos(cida2));

	omega1 = atan2(finalr61.at<double>(1, 0) / cos(cida1), finalr61.at<double>(0, 0) / cos(cida1));
	omega2 = atan2(finalr61.at<double>(1, 0) / cos(cida2), finalr61.at<double>(0, 0) / cos(cida2));

	outfile << fi1 * 180 / PI << " " << cida1 * 180 / PI << " " << omega1 * 180 / PI << " "  << endl;
	outfile << finalt6.at<double>(0, 0) << " " << finalt6.at<double>(1, 0) << " " << finalt6.at<double>(2, 0) << endl;
	
	outfilecamera.close();

	waitKey(0);
}


void on_mouse(int EVENT, int x, int y, int flags, void* ustc)
{	
	Point Pre_pt = (x, y);
	char Txt_Point = 0;
	Mat image = imread("img01.png", IMREAD_UNCHANGED);
	//ofstream outfile;

	//outfile.open("Circle.txt");

	if (EVENT == EVENT_LBUTTONDBLCLK) {
		printf("( %d , %d )", x, y);
		//outfile << x << " " << y << " ";
		putText(image, ".", Pre_pt,
			CV_FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 0, 0, 255), 1, 8);
		circle(image, Pre_pt, 2, Scalar(255, 0, 0, 0), CV_FILLED, CV_AA, 0);//劃圓 	
	}
	//imshow("DealImg", image);
}
