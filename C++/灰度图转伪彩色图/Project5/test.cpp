#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;

int main(int argc, char* argv[])
{

	Mat img = imread("1.jpg", CV_LOAD_IMAGE_GRAYSCALE);//���ûҶȸ�ʽ��ȡͼƬ
	namedWindow("bmp_img");
	imshow("bmp_img", img);

	Mat img_pseudocolor(img.rows, img.cols, CV_8UC3);//����RGBͼ�񣬲���CV_8UC3�̳��ĵ������н���
	int tmp = 0;
	for (int y = 0; y<img.rows; y++)//תΪα��ɫͼ��ľ����㷨
	{
		for (int x = 0; x<img.cols; x++)
		{
			tmp = img.at<unsigned char>(y, x);
			img_pseudocolor.at<Vec3b>(y, x)[0] = abs(255 - tmp); //blue
			img_pseudocolor.at<Vec3b>(y, x)[1] = abs(127 - tmp); //green
			img_pseudocolor.at<Vec3b>(y, x)[2] = abs(0 - tmp); //red
		}
	}
	namedWindow("img_pseudocolor");
	imshow("img_pseudocolor", img_pseudocolor);
	waitKey(0);
	destroyAllWindows();
	return 0;
}