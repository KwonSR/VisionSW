#ifndef OPENCV_DLL_GLOBAL_H
#define OPENCV_DLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OPENCV_DLL_LIBRARY)
#define OPENCV_DLL_EXPORT Q_DECL_EXPORT
#else
#define OPENCV_DLL_EXPORT Q_DECL_IMPORT
#endif

#endif // OPENCV_DLL_GLOBAL_H
