QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    imageobject.cpp \
    main.cpp \
    mainwindow.cpp \
    worker.cpp

HEADERS += \
    imageobject.h \
    mainwindow.h \
    worker.h

FORMS += \
    mainwindow.ui

# define pwd path(.pro location) 지워도 될듯
DEFINES += ROOT_PATH=\\\"$$PWD\\\"

INCLUDEPATH += $$PWD/opencv_4.9.0_cmake/include
CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/opencv_4.9.0_cmake/lib -lopencv_world490d
} else {
    LIBS += -L$$PWD/opencv_4.9.0_cmake/lib -lopencv_world490
}

# LIBS += -L$$PWD/opencv_dll -lopencv_dll
# INCLUDEPATH += $$PWD/opencv_dll/
# LIBS += -L$$PWD/custom_dll -lcustom_dll
# INCLUDEPATH += $$PWD/custom_dll/

# 헤더 경로 지정
INCLUDEPATH += $$PWD/opencv_dll/include/
INCLUDEPATH += $$PWD/custom_dll/include/
# DLL import (링크)
CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/opencv_dll/debug -lopencv_dll
    LIBS += -L$$PWD/custom_dll/debug -lcustom_dll
} else {
    LIBS += -L$$PWD/opencv_dll/release -lopencv_dll
    LIBS += -L$$PWD/custom_dll/release -lcustom_dll
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
