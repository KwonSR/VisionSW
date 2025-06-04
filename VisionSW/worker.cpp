#include "worker.h"

#include <QElapsedTimer>

Worker::Worker()
{

}
Worker::~Worker()
{

}
void Worker::setParam(QString path, QString savepath, int kernel, bool isCheckOpenCV)
{
    m_path = path;
    m_savepath = savepath;
    m_kernelSize = kernel;
    m_isCheckOpenCV = isCheckOpenCV;
}

void Worker::run()
{
    QElapsedTimer timer;
    timer.start();

    Mat image = imread(exePath.toStdString() + m_path.toStdString(), IMREAD_GRAYSCALE);
    ImageObject image_src = ImageObject::Mat_to_ImageObject(image);
    ImageObject *image_dst = new ImageObject(image.cols, image.rows, 1);
    Mat result;

    QFileInfo fileInfo(m_path);
    QString filename = fileInfo.fileName();

    if(m_isCheckOpenCV)
    {
        opencv.ImageBlur(&image_src, image_dst, m_kernelSize);
        result = image_dst->ImageObject_to_Mat();
        imwrite(exePath.toStdString() + m_savepath.toStdString() + "/opencv_" + filename.toStdString(), result);
    }
    else
    {
        custom.ImageBlur(&image_src, image_dst, m_kernelSize);
        result = image_dst->ImageObject_to_Mat();
        imwrite(exePath.toStdString() + m_savepath.toStdString() + "/custom_" + filename.toStdString(), result);
    }
    qint64 elapsed = timer.elapsed();

    qDebug() << "Done!";

    emit run_finished(filename, elapsed, m_isCheckOpenCV);
    delete image_dst;
}
