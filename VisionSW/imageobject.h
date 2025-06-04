#ifndef IMAGEOBJECT_H
#define IMAGEOBJECT_H


#include <vector>
#include <QDebug>
#include <opencv_4.9.0_cmake/include/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class ImageObject
{
public:
    ImageObject(int width, int height, int channel);
    ~ImageObject();

    Mat ImageObject_to_Mat() const;
    static ImageObject Mat_to_ImageObject(Mat mat);

public:
    int m_width = 0;
    int m_height = 0;
    int m_channel = 0;
    vector<unsigned char> m_data;
};

#endif // IMAGEOBJECT_H


//========================================================
// Mat convert_vec_to_mat(vector<unsigned char> &data);
// vector<unsigned char> convert_mat_to_vec(Mat image);
// vector<vector<unsigned char>> convert_mat_to_vec1(Mat image);






















































