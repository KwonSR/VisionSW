QT -= gui

TEMPLATE = lib
DEFINES += OPENCV_DLL_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    imageobject.cpp \
    opencv_dll.cpp

HEADERS += \
    imageobject.h \
    opencv_dll_global.h \
    opencv_dll.h


INCLUDEPATH += $$PWD/opencv_4.9.0_cmake/include
CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/opencv_4.9.0_cmake/lib -lopencv_world490d
} else {
    LIBS += -L$$PWD/opencv_4.9.0_cmake/lib -lopencv_world490
}


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
