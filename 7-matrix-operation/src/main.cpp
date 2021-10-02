#include <ostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/saturate.hpp>

using namespace cv;
using namespace std;

// 图像矩阵运算
void matrixOperation(const Mat& backgroupImg, const Mat& foregroupImg, Mat& outImg)
{
   addWeighted(backgroupImg, 0.9, foregroupImg, 0.55, 0.0, outImg);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "usage: " << argv[0] << " <Backgroup Image Path> <Foregroup Image Path>" << endl;
        return -1;
    }

    // 加载图片
    Mat backgroupImg;
    backgroupImg = imread(argv[1]);
    if (!backgroupImg.data)
    {
        cout << "error: No image data" << endl;
        return -1;
    }

    Mat foregroupImg;
    foregroupImg = imread(argv[2]);
    if (!foregroupImg.data)
    {
        cout << "error: No image data" << endl;
        return -1;
    }

    // 锐化处理：基于拉普拉斯算子。图像边缘会放大，图片变得更尖锐
    Mat result;
    matrixOperation(backgroupImg, foregroupImg, result);

    String winName = "ImageViewer";
    namedWindow(winName, WINDOW_AUTOSIZE);
    imshow(winName, result);

    waitKey(0);

    return 0;
}
