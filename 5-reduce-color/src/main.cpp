#include <ostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 扫描图片所有颜色
void reduceColor(Mat img, int reduceFactor)
{
    int rows = img.rows;
    int cols = img.cols * img.channels();

    for (int row = 0; row < rows; row++)
    {
        uchar* rowData = img.ptr(row);

        for (int col = 0; col < cols; col++)
        {
            rowData[col] = rowData[col] / reduceFactor * reduceFactor + reduceFactor / 2;
        }
    }
    
}

void reduceColorV2(Mat img, int reduceFactor)
{
    int rows = img.rows;
    int cols = img.cols * img.channels();
    uchar mask = 0xFF << reduceFactor;

    for (int row = 0; row < rows; row++)
    {
        uchar* rowData = img.ptr(row);

        for (int col = 0; col < cols; col++)
        {
            rowData[col] &= mask;
            rowData[col] += rowData[col] >> 1;
        }
    }
}

void reduceBlue(Mat img, int reduceFactor)
{
    int rows = img.rows;
    int cols = img.cols * img.channels();

    for (int row = 0; row < rows; row++)
    {
        uchar* rowData = img.ptr(row);

        for (int col = 0; col < cols; )
        {
            rowData[col] = 0;

            col += 3;
        }
    }
    
}

void reduceGreen(Mat img, int reduceFactor)
{
    int rows = img.rows;
    int cols = img.cols * img.channels();

    for (int row = 0; row < rows; row++)
    {
        uchar* rowData = img.ptr(row);

        for (int col = 1; col < cols; )
        {
            rowData[col] = 0;

            col += 3;
        }
    }
    
}

void reduceRed(Mat img, int reduceFactor)
{
    int rows = img.rows;
    int cols = img.cols * img.channels();

    for (int row = 0; row < rows; row++)
    {
        uchar* rowData = img.ptr(row);

        for (int col = 2; col < cols; )
        {
            rowData[col] = 0;

            col += 3;
        }
    }
    
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "usage: " << argv[0] << " <Image Path> <Reduce Factor>" << endl;
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
    
    const int reduceFactor = atoi(argv[2]);

    // 减色处理
    // reduceColor(img, reduceFactor);
    // reduceBlue(img, reduceFactor);
    // reduceGreen(img, reduceFactor);
    // reduceRed(img, reduceFactor);
    reduceColorV2(img, reduceFactor);

    // 展示合并之后的图片
    String winName = "ImageViewer";
    namedWindow(winName, WINDOW_AUTOSIZE);
    imshow(winName, img);

    waitKey(0);

    return 0;
}
