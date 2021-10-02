#include <ostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/saturate.hpp>

using namespace cv;
using namespace std;

// 锐化处理
void sharpen(const Mat& orgImg, Mat& outImg)
{
    outImg.create(orgImg.size(), orgImg.type());
    int channels = orgImg.channels();
    int cols = (orgImg.cols - 1) * channels;

    // 暂时不处理首行和最后一行
    int rows = orgImg.rows - 1;
    for (int row = 1; row < rows; row++)
    {
        uchar* sharpenRowData = outImg.ptr<uchar>(row);
        const uchar* prevRowData = orgImg.ptr<const uchar>(row - 1);
        const uchar* currRowData = orgImg.ptr<const uchar>(row);
        const uchar* nextRowData = orgImg.ptr<const uchar>(row + 1);

        for (int col = channels; col < cols; col++)
        {
            // sharpene_pixel = 5 * current - left - right - up - down
            *sharpenRowData++ = saturate_cast<uchar>(5 * currRowData[col] - currRowData[col - channels] - currRowData[col + channels] - prevRowData[col] - nextRowData[col]);
        } 

        outImg.row(0).setTo(Scalar(0));
        outImg.row(outImg.rows - 1).setTo(Scalar(0));
        outImg.col(0).setTo(Scalar(0));
        outImg.col(outImg.cols - 1).setTo(Scalar(0));
    }
}

// 锐化处理
void sharpen2D(const Mat& orgImg, Mat& outImg)
{
    Mat kernel(3, 3, CV_32F, Scalar(0));

    // sharpene_pixel = 5 * current - left - right - up - down
    kernel.at<float>(1, 1) = 5.0;
    kernel.at<float>(0, 1) = -1.0;
    kernel.at<float>(2, 1) = -1.0;
    kernel.at<float>(1, 0) = -1.0;
    kernel.at<float>(1, 2) = -1.0;

    // 滤波处理
    filter2D(orgImg, outImg, orgImg.depth(), kernel);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "usage: " << argv[0] << " <Image Path>" << endl;
        return -1;
    }

    // 加载图片
    Mat img;
    img = imread(argv[1], IMREAD_GRAYSCALE);
    if (!img.data)
    {
        cout << "error: No image data" << endl;
        return -1;
    }

    // 锐化处理：基于拉普拉斯算子。图像边缘会放大，图片变得更尖锐
    Mat result;
    // sharpen(img, result);
    sharpen2D(img, result);

    String winName = "ImageViewer";
    namedWindow(winName, WINDOW_AUTOSIZE);
    imshow(winName, result);

    waitKey(0);

    return 0;
}
