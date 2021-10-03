#include <ostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/saturate.hpp>

using namespace cv;
using namespace std;

// 颜色检测
void detectColor(const Mat& img, Vec3b target, Mat& outImg)
{
    outImg.create(img.size(), CV_8U);

    Mat_<uchar>::iterator outIter = outImg.begin<uchar>();
    Mat_<Vec3b>::const_iterator imgIter = img.begin<Vec3b>();
    Mat_<Vec3b>::const_iterator imgEnd = img.end<Vec3b>();

    int dist = 0;
    const int maxDist = 300;
    for ( ; imgIter != imgEnd; imgIter++, outIter++)
    {
        Vec3b curr = *imgIter;
        // dist = std::abs((curr[0] - target[0]) + (curr[1] - target[1]) + (curr[2] - target[2]));
        dist = static_cast<int>(norm<int, 3>(Vec3i(curr[0] - target[0], curr[1] - target[1], curr[2] - target[2])));
        *outIter = dist < maxDist? 255 : 0;
    }
}

// 颜色检测
void detectColorLab(const Mat& img, Vec3b target, Mat& outImg)
{
    outImg.create(img.size(), CV_8U);

    // 感知均匀（perceptual uniform）设备无关（device-independent）
    Mat lab;
    cvtColor(img, lab, COLOR_BGR2Lab);

    Mat targetImg(1, 1, CV_8UC3);
    targetImg.at<Vec3b>(0, 0) = target;
    cvtColor(targetImg, targetImg, COLOR_BGR2Lab);
    target = targetImg.at<Vec3b>(0, 0);

    Mat_<uchar>::iterator outIter = outImg.begin<uchar>();
    Mat_<Vec3b>::const_iterator imgIter = lab.begin<Vec3b>();
    Mat_<Vec3b>::const_iterator imgEnd = lab.end<Vec3b>();

    int dist = 0;
    const int maxDist = 180;
    for ( ; imgIter != imgEnd; imgIter++, outIter++)
    {
        Vec3b curr = *imgIter;
        // dist = std::abs((curr[0] - target[0]) + (curr[1] - target[1]) + (curr[2] - target[2]));
        dist = static_cast<int>(norm<int, 3>(Vec3i(curr[0] - target[0], curr[1] - target[1], curr[2] - target[2])));
        *outIter = dist < maxDist? 255 : 0;     
    }
}

// 颜色检测
void detectColorLuv(const Mat& img, Vec3b target, Mat& outImg)
{
    outImg.create(img.size(), CV_8U);

    Mat luv;
    cvtColor(img, luv, COLOR_BGR2Luv);

    Mat targetImg(1, 1, CV_8UC3);
    targetImg.at<Vec3b>(0, 0) = target;
    cvtColor(targetImg, targetImg, COLOR_BGR2Luv);
    target = targetImg.at<Vec3b>(0, 0);

    Mat_<uchar>::iterator outIter = outImg.begin<uchar>();
    Mat_<Vec3b>::const_iterator imgIter = luv.begin<Vec3b>();
    Mat_<Vec3b>::const_iterator imgEnd = luv.end<Vec3b>();

    int dist = 0;
    const int maxDist = 175;
    for ( ; imgIter != imgEnd; imgIter++, outIter++)
    {
        Vec3b curr = *imgIter;
        // dist = std::abs((curr[0] - target[0]) + (curr[1] - target[1]) + (curr[2] - target[2]));
        dist = static_cast<int>(norm<int, 3>(Vec3i(curr[0] - target[0], curr[1] - target[1], curr[2] - target[2])));
        *outIter = dist < maxDist? 255 : 0;     
    }
}

// 颜色检测
void detectColorXYZ(const Mat& img, Vec3b target, Mat& outImg)
{
    outImg.create(img.size(), CV_8U);

    Mat xyz;
    cvtColor(img, xyz, COLOR_BGR2XYZ);

    Mat targetImg(1, 1, CV_8UC3);
    targetImg.at<Vec3b>(0, 0) = target;
    cvtColor(targetImg, targetImg, COLOR_BGR2XYZ);
    target = targetImg.at<Vec3b>(0, 0);

    Mat_<uchar>::iterator outIter = outImg.begin<uchar>();
    Mat_<Vec3b>::const_iterator imgIter = xyz.begin<Vec3b>();
    Mat_<Vec3b>::const_iterator imgEnd = xyz.end<Vec3b>();

    int dist = 0;
    const int maxDist = 210;
    for ( ; imgIter != imgEnd; imgIter++, outIter++)
    {
        Vec3b curr = *imgIter;
        // dist = std::abs((curr[0] - target[0]) + (curr[1] - target[1]) + (curr[2] - target[2]));
        dist = static_cast<int>(norm<int, 3>(Vec3i(curr[0] - target[0], curr[1] - target[1], curr[2] - target[2])));
        *outIter = dist < maxDist? 255 : 0;     
    }
}

// 颜色检测
void detectColorHSV(const Mat& img, Vec3b target, Mat& outImg)
{
    outImg.create(img.size(), CV_8U);

    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);

    Mat targetImg(1, 1, CV_8UC3);
    targetImg.at<Vec3b>(0, 0) = target;
    cvtColor(targetImg, targetImg, COLOR_BGR2HSV);
    target = targetImg.at<Vec3b>(0, 0);

    Mat_<uchar>::iterator outIter = outImg.begin<uchar>();
    Mat_<Vec3b>::const_iterator imgIter = hsv.begin<Vec3b>();
    Mat_<Vec3b>::const_iterator imgEnd = hsv.end<Vec3b>();

    int dist = 0;
    const int maxDist = 250;
    for ( ; imgIter != imgEnd; imgIter++, outIter++)
    {
        Vec3b curr = *imgIter;
        // dist = std::abs((curr[0] - target[0]) + (curr[1] - target[1]) + (curr[2] - target[2]));
        dist = static_cast<int>(norm<int, 3>(Vec3i(curr[0] - target[0], curr[1] - target[1], curr[2] - target[2])));
        *outIter = dist < maxDist? 255 : 0;     
    }
}

// 颜色检测
void detectColorHLS(const Mat& img, Vec3b target, Mat& outImg)
{
    outImg.create(img.size(), CV_8U);

    Mat hls;
    cvtColor(img, hls, COLOR_BGR2HLS);

    Mat targetImg(1, 1, CV_8UC3);
    targetImg.at<Vec3b>(0, 0) = target;
    cvtColor(targetImg, targetImg, COLOR_BGR2HLS);
    target = targetImg.at<Vec3b>(0, 0);

    Mat_<uchar>::iterator outIter = outImg.begin<uchar>();
    Mat_<Vec3b>::const_iterator imgIter = hls.begin<Vec3b>();
    Mat_<Vec3b>::const_iterator imgEnd = hls.end<Vec3b>();

    int dist = 0;
    const int maxDist = 250;
    for ( ; imgIter != imgEnd; imgIter++, outIter++)
    {
        Vec3b curr = *imgIter;
        // dist = std::abs((curr[0] - target[0]) + (curr[1] - target[1]) + (curr[2] - target[2]));
        dist = static_cast<int>(norm<int, 3>(Vec3i(curr[0] - target[0], curr[1] - target[1], curr[2] - target[2])));
        *outIter = dist < maxDist? 255 : 0;     
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "usage: " << argv[0] << " <Image Path>>" << endl;
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

    // 波浪处理
    Mat result;
    Vec3b target(255, 0, 0);
    detectColorHLS(img, target, result);

    String winName = "ImageViewer";
    namedWindow(winName, WINDOW_AUTOSIZE);
    imshow(winName, result);

    waitKey(0);

    return 0;
}
