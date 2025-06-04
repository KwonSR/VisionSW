#ifndef IMAGEOBJECT_H
#define IMAGEOBJECT_H

#include <vector>

using namespace std;

class ImageObject
{
public:
    ImageObject(int width, int height, int channel);
    ~ImageObject();

public:
    int m_width = 0;
    int m_height = 0;
    int m_channel = 0;
    vector<unsigned char> m_data;
};

#endif // IMAGEOBJECT_H
