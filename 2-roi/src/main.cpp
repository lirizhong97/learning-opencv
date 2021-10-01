#include <ostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "usage: " << argv[0] << " <Large Image Path> <Small Image Path>" << endl;
        return -1;
    }

    // 加载图片
    Mat largeImg;
    largeImg = imread(argv[1]);
    if (!largeImg.data)
    {
        cout << "error: No image data" << endl;
        return -1;
    }

    Mat smallImg;
    smallImg = imread(argv[2]);
    if (!smallImg.data)
    {
        cout << "error: No image data" << endl;
        return -1;
    }

    // 计算兴趣区域：左上角
    Rect region = Rect(0, 0, smallImg.cols, smallImg.rows);

    // 指向原图区域缓冲区
    Mat roiImg(largeImg, region);

    // 将图片数据拷贝到原图区域缓冲区
    smallImg.copyTo(roiImg);

    // 展示合并之后的图片
    String winName = "ImageViewer";
    namedWindow(winName, WINDOW_AUTOSIZE);
    imshow(winName, largeImg);

    waitKey(0);

    return 0;
}
