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
