#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "worker.h"

#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->reloadButton, &QPushButton::clicked, this, &MainWindow::reloadClicked);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startClicked);
    connect(ui->compareButton, &QPushButton::clicked, this, &MainWindow::compareClicked);

    checkLogFile();         // check image_blur.log file is exist
    load_setting_value();   // load setting value in setting.ini
}

MainWindow::~MainWindow()
{
    path.clear();
    delete ui;
}

void MainWindow::checkLogFile()
{
    QFile file(logPath);

    if(!file.exists())
    {
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            file.close();
        }
    }
}

void MainWindow::writelog(QString msg)
{
    QFile file(logPath);

    file.open(QIODevice::Append | QIODevice::Text);

    QTextStream out(&file);
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    out << "[" << timestamp << "] " << msg << "\n";

    file.close();
}

void MainWindow::clear_ui()
{
    isLoaded = true;
    ui->kernelValue->setText("-");
    ui->ImageText_1->clear();
    ui->ImageText_2->clear();
    ui->ImageText_3->clear();
    ui->saveText->clear();
    total_image_cnt = 0;
}

void MainWindow::reloadClicked()
{
    qDebug() << "Reload!";
    if(!path.empty())
        path.clear();
    bool val = load_setting_value();

    if(val)
        ui->statusValue->setText("Complete");
    else
        ui->statusValue->setText("InComplete");
}

void MainWindow::compareClicked()
{
    if(total_image_cnt == 6)
    {
        QString resultPath = QCoreApplication::applicationDirPath() + "/result";
        QString opencv_path;
        QString custom_path;
        QString filename;

        for(int i = 0 ; i < 3 ; i++)
        {
            QFileInfo fileInfo(QString::fromStdString(path[i]));
            filename = fileInfo.fileName();

            opencv_path = resultPath + "/opencv_" +filename;
            custom_path = resultPath + "/custom_" +filename;

            Mat opencv_mat = imread(opencv_path.toStdString(), IMREAD_UNCHANGED);
            Mat custom_mat = imread(custom_path.toStdString(), IMREAD_UNCHANGED);

            if(isSameImage(opencv_mat, custom_mat))
            {
                writelog("File: " + filename);
                writelog("\t\t -> Same Image");
            }
            else
            {
                writelog("File: " + filename);
                writelog("\t\t -> Diff Image");
            }
        }
    }
}

bool MainWindow::isSameImage(Mat img1, Mat img2)
{
    if(img1.size() != img2.size() || img1.type() != img2.type())
    {
        return false;
    }

    Mat diff;
    absdiff(img1, img2, diff);

    return countNonZero(diff.reshape(1)) == 0 ? true : false;
}


void MainWindow::startClicked()
{
    if(ui->cv_radioButton->isChecked() && isLoaded == true)
    {
        qDebug() << "opencv!";
        writelog("=====Opencv_dll.dll Start=====");
        for(int i = 0 ; i < 3 ; i++)
        {
            Worker *work = new Worker();
            work->setParam(QString::fromStdString(path[i]), QString::fromStdString(path[3]), kernelSize, true);

            connect(work, &Worker::run_finished, this, &MainWindow::onRunFinished);
            connect(work, &QThread::finished, work, &QObject::deleteLater);

            work->start();
            writelog("\t ->" + exePath + QString::fromStdString(path[i]));
        }
    }
    else if(ui->custom_radioButton->isChecked() && isLoaded == true)
    {
        qDebug() << "Custom!";
        for(int i = 0 ; i < 3 ; i++)
        {
            Worker *work = new Worker();
            work->setParam(QString::fromStdString(path[i]), QString::fromStdString(path[3]), kernelSize, false);

            connect(work, &Worker::run_finished, this, &MainWindow::onRunFinished);
            connect(work, &QThread::finished, work, &QObject::deleteLater);

            work->start();
        }
    }
}

void MainWindow::onRunFinished(QString filename, qint64 time, bool type)
{
    QString dll_name = type == true ? "opencv" : "custom";
    qDebug() << "<" + dll_name + ">" + filename + " Finished!";
    writelog("\t\t <" + dll_name + ">" + filename + " processing time: " + QString::number(time) + "ms");
    total_image_cnt++;
}

bool MainWindow::isGrayImage(string path)
{
    Mat img = imread(exePath.toStdString() + path, IMREAD_UNCHANGED);

    return img.channels() == 1 ? true : false;
}

bool MainWindow::load_setting_value()
{
    QString exepath = QCoreApplication::applicationDirPath();
    QString filepath = QCoreApplication::applicationDirPath() + "/setting.ini";
    if(!QFile::exists(filepath))
    {
        qDebug() << "File not exist. Check file path";
        writelog("File not exist. Check file path");
        isLoaded = false;
        return false;
    }

    QFile file(filepath);
    if(file.open(QIODevice::ReadOnly))
    {
        QString title;
        while(!file.atEnd())
        {
            QString line = file.readLine();
            line.replace("\r\n", "");

            if(line == "<path>" || line == "<kernel size>" || line == "<savepath>")
            {
                title = line;
                continue;
            }

            if(title == "<path>")
            {
                if(isGrayImage(line.toStdString()))
                {
                    path.push_back(line.toStdString());
                }
                else
                {
                    writelog("This image is not Gray Image");
                    writelog("\t-> File path = " + exePath + line);
                    file.close();
                    isLoaded = false;
                    return false;
                }
            }
            else if(title == "<kernel size>")
                kernelSize = line.toInt();
            else
                path.push_back(line.toStdString());
        }
        file.close();

        if(path.size() < 4)
        {
            qDebug() << "Please Check number of image file in setting.ini";
            writelog("Please Check number of image file in setting.ini");
            isLoaded = false;
            clear_ui();
            return false;
        }

        if(kernelSize < 21 || kernelSize % 2 == 0)
        {
            qDebug() << "Please Check kernelSize in setting.ini";
            writelog("Please Check kernelSize in setting.ini");
            clear_ui();
            isLoaded = false;
            return false;
        }
    }

    ui->statusValue->setText("Complete");
    ui->kernelValue->setText(QString::number(kernelSize));
    ui->ImageText_1->setText(exepath + QString::fromStdString(path[0]));
    ui->ImageText_2->setText(exepath + QString::fromStdString(path[1]));
    ui->ImageText_3->setText(exepath + QString::fromStdString(path[2]));
    ui->saveText->setText(exepath + QString::fromStdString(path[3]));

    writelog("Load setting.ini Compelete");
    writelog("\t-> File path 1 = " + exePath + QString::fromStdString(path[0]));
    writelog("\t-> File path 2 = " + exePath + QString::fromStdString(path[1]));
    writelog("\t-> File path 3 = " + exePath + QString::fromStdString(path[2]));
    writelog("\t-> save path = " + exePath + QString::fromStdString(path[3]));
    writelog("\t-> kernelSize = " + QString::number(kernelSize));

    return true;
}
