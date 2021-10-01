#include <ostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "usage: " << argv[0] << " <Image Path>" << endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1]);
    if (!image.data)
    {
        cout << "error: No image data" << endl;
        return -1;
    }

    String winName = "ImageViewer";

    namedWindow(winName, WINDOW_AUTOSIZE);
    imshow(winName, image);

    waitKey(0);

    return 0;
}
