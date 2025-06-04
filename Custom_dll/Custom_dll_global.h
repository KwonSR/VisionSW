#ifndef CUSTOM_DLL_GLOBAL_H
#define CUSTOM_DLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CUSTOM_DLL_LIBRARY)
#define CUSTOM_DLL_EXPORT Q_DECL_EXPORT
#else
#define CUSTOM_DLL_EXPORT Q_DECL_IMPORT
#endif

#endif // CUSTOM_DLL_GLOBAL_H
