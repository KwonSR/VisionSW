/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *statusLabel;
    QLabel *statusValue;
    QPushButton *reloadButton;
    QLabel *ImageLabel;
    QTextEdit *ImageText_1;
    QTextEdit *ImageText_2;
    QTextEdit *ImageText_3;
    QLabel *ImageLabel_1;
    QLabel *ImageLabel_2;
    QLabel *ImageLabel_3;
    QLabel *saveLabel;
    QTextEdit *saveText;
    QLabel *kernelLabel;
    QLabel *kernelValue;
    QRadioButton *cv_radioButton;
    QRadioButton *custom_radioButton;
    QLabel *blurLabel;
    QPushButton *startButton;
    QPushButton *compareButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 576);
        MainWindow->setMinimumSize(QSize(400, 450));
        MainWindow->setMaximumSize(QSize(400, 700));
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(20, 20, 116, 21));
        statusValue = new QLabel(centralwidget);
        statusValue->setObjectName("statusValue");
        statusValue->setGeometry(QRect(20, 50, 111, 31));
        statusValue->setAlignment(Qt::AlignCenter);
        reloadButton = new QPushButton(centralwidget);
        reloadButton->setObjectName("reloadButton");
        reloadButton->setGeometry(QRect(150, 40, 80, 24));
        ImageLabel = new QLabel(centralwidget);
        ImageLabel->setObjectName("ImageLabel");
        ImageLabel->setGeometry(QRect(20, 100, 101, 31));
        ImageText_1 = new QTextEdit(centralwidget);
        ImageText_1->setObjectName("ImageText_1");
        ImageText_1->setGeometry(QRect(70, 140, 311, 30));
        QFont font1;
        font1.setPointSize(9);
        ImageText_1->setFont(font1);
        ImageText_1->setReadOnly(true);
        ImageText_2 = new QTextEdit(centralwidget);
        ImageText_2->setObjectName("ImageText_2");
        ImageText_2->setGeometry(QRect(70, 180, 311, 30));
        ImageText_2->setFont(font1);
        ImageText_2->setReadOnly(true);
        ImageText_3 = new QTextEdit(centralwidget);
        ImageText_3->setObjectName("ImageText_3");
        ImageText_3->setGeometry(QRect(70, 220, 311, 30));
        ImageText_3->setFont(font1);
        ImageText_3->setReadOnly(true);
        ImageLabel_1 = new QLabel(centralwidget);
        ImageLabel_1->setObjectName("ImageLabel_1");
        ImageLabel_1->setGeometry(QRect(20, 140, 48, 21));
        ImageLabel_1->setAlignment(Qt::AlignCenter);
        ImageLabel_2 = new QLabel(centralwidget);
        ImageLabel_2->setObjectName("ImageLabel_2");
        ImageLabel_2->setGeometry(QRect(20, 180, 48, 21));
        ImageLabel_2->setAlignment(Qt::AlignCenter);
        ImageLabel_3 = new QLabel(centralwidget);
        ImageLabel_3->setObjectName("ImageLabel_3");
        ImageLabel_3->setGeometry(QRect(20, 220, 48, 21));
        ImageLabel_3->setAlignment(Qt::AlignCenter);
        saveLabel = new QLabel(centralwidget);
        saveLabel->setObjectName("saveLabel");
        saveLabel->setGeometry(QRect(20, 370, 101, 31));
        saveText = new QTextEdit(centralwidget);
        saveText->setObjectName("saveText");
        saveText->setGeometry(QRect(20, 410, 361, 30));
        QFont font2;
        font2.setPointSize(11);
        saveText->setFont(font2);
        saveText->setReadOnly(true);
        kernelLabel = new QLabel(centralwidget);
        kernelLabel->setObjectName("kernelLabel");
        kernelLabel->setGeometry(QRect(250, 20, 116, 21));
        kernelLabel->setAlignment(Qt::AlignCenter);
        kernelValue = new QLabel(centralwidget);
        kernelValue->setObjectName("kernelValue");
        kernelValue->setGeometry(QRect(260, 50, 101, 21));
        kernelValue->setAlignment(Qt::AlignCenter);
        cv_radioButton = new QRadioButton(centralwidget);
        cv_radioButton->setObjectName("cv_radioButton");
        cv_radioButton->setGeometry(QRect(70, 300, 121, 22));
        cv_radioButton->setChecked(true);
        custom_radioButton = new QRadioButton(centralwidget);
        custom_radioButton->setObjectName("custom_radioButton");
        custom_radioButton->setGeometry(QRect(230, 300, 121, 22));
        blurLabel = new QLabel(centralwidget);
        blurLabel->setObjectName("blurLabel");
        blurLabel->setGeometry(QRect(20, 270, 101, 31));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(150, 330, 100, 30));
        compareButton = new QPushButton(centralwidget);
        compareButton->setObjectName("compareButton");
        compareButton->setGeometry(QRect(130, 470, 131, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Load Setting.ini", nullptr));
        statusValue->setText(QCoreApplication::translate("MainWindow", "Incomplete", nullptr));
        reloadButton->setText(QCoreApplication::translate("MainWindow", "Reload", nullptr));
        ImageLabel->setText(QCoreApplication::translate("MainWindow", "Image File", nullptr));
        ImageLabel_1->setText(QCoreApplication::translate("MainWindow", "(1)", nullptr));
        ImageLabel_2->setText(QCoreApplication::translate("MainWindow", "(2)", nullptr));
        ImageLabel_3->setText(QCoreApplication::translate("MainWindow", "(3)", nullptr));
        saveLabel->setText(QCoreApplication::translate("MainWindow", "Save path", nullptr));
        kernelLabel->setText(QCoreApplication::translate("MainWindow", "Kernel Size", nullptr));
        kernelValue->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        cv_radioButton->setText(QCoreApplication::translate("MainWindow", "opencv_blur", nullptr));
        custom_radioButton->setText(QCoreApplication::translate("MainWindow", "custom_blur", nullptr));
        blurLabel->setText(QCoreApplication::translate("MainWindow", "Select Blur", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        compareButton->setText(QCoreApplication::translate("MainWindow", "Compare Result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
