#ifndef OPENCV_DLL_H
#define OPENCV_DLL_H

#include "opencv_dll_global.h"
#include "imageobject.h"

using namespace std;
using namespace cv;

class OPENCV_DLL_EXPORT Opencv_dll
{
public:
    Opencv_dll();
    ~Opencv_dll();

    bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize);
};

#endif // OPENCV_DLL_H
