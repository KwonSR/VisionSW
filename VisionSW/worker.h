#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QCoreApplication>
#include <QFileInfo>

#include "opencv_dll/opencv_dll.h"
#include "custom_dll/custom_dll.h"

using namespace std;

class Worker : public QThread
{
    Q_OBJECT
protected:
    void run() override;

public:
    Worker();
    ~Worker();
    void setParam(QString path, QString savepath, int kernel, bool isCheckOpenCV);

signals:
    void run_finished(QString filename, qint64 time, bool type);

private:
    QString m_path;
    QString m_savepath;
    QString exePath = QCoreApplication::applicationDirPath();

    string m_filename;

    bool m_isCheckOpenCV;
    int m_kernelSize = 0;

    Opencv_dll opencv;
    Custom_dll custom;
};

#endif // WORKER_H
