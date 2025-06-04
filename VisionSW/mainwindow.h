#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

#include <opencv_4.9.0_cmake/include/opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

using namespace std;
using namespace cv;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool load_setting_value();
    void clear_ui();
    void writelog(QString msg);
    void checkLogFile();
    bool isGrayImage(string path);
    bool isSameImage(Mat img1, Mat img2);

private slots:
    void reloadClicked();
    void startClicked();
    void compareClicked();

    void onRunFinished(QString filename, qint64 time, bool type);

private:
    Ui::MainWindow *ui;

    vector<string> path;
    int kernelSize = 0;
    bool isLoaded = true;

    QString exePath = QCoreApplication::applicationDirPath();
    QString logPath = exePath + "/" + "image_blur.log";

    int total_image_cnt = 0;
};
#endif // MAINWINDOW_H
