#include "imageobject.h"

ImageObject::ImageObject(int width, int height, int channel)
{
    m_width = width;
    m_height = height;
    m_channel = channel;

    m_data.resize(m_width * m_height * m_channel);

    qDebug() << m_width;
    qDebug() << m_height;
    qDebug() << m_channel;
    qDebug() << m_data.size();



    // ImageObject img = "C:\\Users\\User\\Desktop\\image\\test_gray.jpg";
    // Mat image = imread("C:\\Users\\User\\Desktop\\image\\test_gray.jpg");

    // vector<vector<unsigned char>> buf = convert_mat_to_vec1(image);

    // qDebug() << "buf size =" << buf.size();
    // qDebug() << "buf[0] size =" << buf[0].size();

    // vector<vector<unsigned char>> dst(362, vector<unsigned char>(438, 0));

    // Size kernel(21, 21);

    // blur(buf, dst, kernel);

    // imshow("image", image);
    // imshow("dst", dst);

    // for(int i = 0 ; i < m_data.size() ; i++)
    // {
    //     m_data[i] = i % 255;
    // }

    // cv::Mat mat(m_height, m_width, CV_8UC1, m_data.data());
    // cv::imshow("data", mat);
    // cv::waitKey(0);
}


ImageObject::~ImageObject()
{
    m_data.clear();
}

Mat ImageObject::ImageObject_to_Mat() const
{
    Mat image(m_height, m_width, CV_8UC1);
    memcpy(image.data, m_data.data(), m_data.size());

    return image;
}

ImageObject ImageObject::Mat_to_ImageObject(Mat mat)
{
    ImageObject obj(mat.cols, mat.rows, 1);
    memcpy(obj.m_data.data(), mat.data, mat.cols * mat.rows * 1);

    return obj;
}


//================================================================================================
// Mat ImageObject::convert_vec_to_mat(vector<unsigned char> &data)
// {
//     cv::Mat mat(m_height, m_width, CV_8UC1, m_data.data());
//     return mat;
// }

// vector<unsigned char> ImageObject::convert_mat_to_vec(Mat image)
// {
//     // grayscale image -> elemSize = 1
//     vector<unsigned char> buf(image.data, image.data + image.total());
//     return buf;
// }

// vector<vector<unsigned char> > ImageObject::convert_mat_to_vec1(Mat image)
// {

//     // row y / col x
//     vector<vector<unsigned char>> dat;
//     qDebug() << image.rows;
//     qDebug() << image.cols;


//     for(int i = 0 ; i < image.rows ; i++)
//     {
//         vector<unsigned char> d;
//         for(int j = 0 ; j < image.cols ; j++)
//         {
//             // qDebug() << image.at<unsigned char>(j, i);
//             d.push_back(image.at<unsigned char>(i, j));
//         }
//         // break;
//         dat.push_back(d);
//         d.clear();
//     }

//     return dat;


//     // vector<vector<unsigned char>> buf(image.data, image.data + image.total());
//     // return buf;
// }










































