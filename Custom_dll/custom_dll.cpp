#include "custom_dll.h"

Custom_dll::Custom_dll()
{

}

Custom_dll::~Custom_dll()
{

}

bool Custom_dll::ImageBlur(const ImageObject *src, ImageObject *dst, const int kernelSize)
{
    int width = src->m_width;
    int height = src->m_height;
    vector<unsigned char> data = src->m_data;

    int paddingSize = kernelSize / 2;
    int re_width = width + paddingSize * 2;
    int re_height = height + paddingSize * 2;

    // add padding
    vector<int> padding(re_width * re_height, 0);
    for(int i = 0 ; i < re_height ; i++)
    {
        for(int j = 0 ; j < re_width ; j++)
        {
            int origin_x = j - paddingSize;
            int origin_y = i - paddingSize;

            if(origin_y < 0)
                origin_y = 0;
            else if(origin_y >= height)
                origin_y = height - 1;

            if(origin_x < 0)
                origin_x = 0;
            else if(origin_x >= width)
                origin_x = width - 1;

            padding[i * re_width + j] = data[origin_y * width + origin_x];
        }
    }

    // total sum
    vector<int> total_sum(re_width * re_height, 0);
    for(int i = 0 ; i < re_height ; i++)
    {
        int row_sum = 0;
        for(int j = 0 ; j < re_width ; j++)
        {
            row_sum += padding[i * re_width + j];
            if(i == 0)
                total_sum[i * re_width + j] = row_sum;
            else
                total_sum[i * re_width + j] = total_sum[(i - 1) * re_width + j] + row_sum;
        }
    }

    // blur
    vector<unsigned char> blur(width * height, 0);
    for(int i = paddingSize ; i < height + paddingSize ; i++)
    {
        for(int j = paddingSize ; j < width + paddingSize ; j++)
        {
            int x1 = j - paddingSize;
            int y1 = i - paddingSize;
            int x2 = j + paddingSize;
            int y2 = i + paddingSize;

            int total = total_sum[y2 * re_width + x2];

            if(x1 > 0)
                total -= total_sum[y2 * re_width + (x1 - 1)];
            if(y1 > 0)
                total -= total_sum[(y1 - 1) * re_width + x2];
            if(x1 > 0 && y1 > 0)
                total += total_sum[(y1 - 1) * re_width + (x1 - 1)];

            blur[(i - paddingSize) * width + (j - paddingSize)] = static_cast<unsigned char>(total / (kernelSize * kernelSize));
        }
    }

    for(int i = 0 ; i < width * height ; i++)
        dst->m_data[i] = blur[i];

    return true;
}
