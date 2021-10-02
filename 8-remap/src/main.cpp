#include <ostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/saturate.hpp>

using namespace cv;
using namespace std;

// remap成波浪形状
void remap2Wave(const Mat& orgImg, Mat& outImg)
{
    Mat mapX(orgImg.rows, orgImg.cols, CV_32F);
    Mat mapY(orgImg.rows, orgImg.cols, CV_32F);

    for (int row = 0; row < orgImg.rows; row++)
    {
        for (int col = 0; col < orgImg.cols; col++)
        {
            mapX.at<float>(row, col) = col; // 波浪形，保持同一列
            mapY.at<float>(row, col) = row + 5 * sin(col / 10.0); // 波浪形，行按照正弦曲线波动
        }
    }

    remap(orgImg, outImg, mapX, mapY, INTER_LINEAR);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "usage: " << argv[0] << " <Backgroup Image Path>>" << endl;
        return -1;
    }

    // 加载图片
    Mat orgImg;
    orgImg = imread(argv[1]);
    if (!orgImg.data)
    {
        cout << "error: No image data" << endl;
        return -1;
    }

    // 波浪处理
    Mat result;
    remap2Wave(orgImg, result);

    String winName = "ImageViewer";
    namedWindow(winName, WINDOW_AUTOSIZE);
    imshow(winName, result);

    waitKey(0);

    return 0;
}
