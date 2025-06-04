#include "opencv_dll.h"

Opencv_dll::Opencv_dll()
{
}
Opencv_dll::~Opencv_dll()
{
}

bool Opencv_dll::ImageBlur(const ImageObject *src, ImageObject *dst, const int kernelSize)
{
    Mat input_mat = src->ImageObject_to_Mat();
    Mat output_mat;

    Size kernel_size(kernelSize, kernelSize);

    blur(input_mat, output_mat, kernel_size);

    *dst = ImageObject::Mat_to_ImageObject(output_mat);

    return true;
}
