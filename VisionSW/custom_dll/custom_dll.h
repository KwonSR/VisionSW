#ifndef CUSTOM_DLL_H
#define CUSTOM_DLL_H

#include "Custom_dll_global.h"
#include "imageobject.h"

class CUSTOM_DLL_EXPORT Custom_dll
{
public:
    Custom_dll();
    ~Custom_dll();

    bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize);
};

#endif // CUSTOM_DLL_H
