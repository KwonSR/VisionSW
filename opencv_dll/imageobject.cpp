#include "imageobject.h"

ImageObject::ImageObject(int width, int height, int channel)
{
    m_width = width;
    m_height = height;
    m_channel = channel;

    m_data.resize(m_width * m_height * m_channel);
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
    memcpy(obj.m_data.data(), mat.data, mat.cols * mat.rows);

    return obj;
}
