#include <ostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void salt_papper_noise(Mat img, int num)
{
    int col, row;
    for(int i = 0; i < num; i++)
    {
        col = rand() % img.cols;
        row = rand() % img.rows;
        
        // 彩色图3通道：蓝、绿和红
        img.at<Vec3b>(row, col)[0] = 255;
        img.at<Vec3b>(row, col)[1] = 255;
        img.at<Vec3b>(row, col)[2] = 255;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "usage: " << argv[0] << " <Large Image Path> <Count of Salt>" << endl;
        return -1;
    }

    // 加载图片
    Mat img;
    img = imread(argv[1]);
    if (!img.data)
    {
        cout << "error: No image data" << endl;
        return -1;
    }

    const int num = atoi(argv[2]);

    // 模拟椒盐噪声效果
    salt_papper_noise(img, num);
   
    // 展示合并之后的图片
    String winName = "ImageViewer";
    namedWindow(winName, WINDOW_AUTOSIZE);
    imshow(winName, img);

    waitKey(0);

    return 0;
}
