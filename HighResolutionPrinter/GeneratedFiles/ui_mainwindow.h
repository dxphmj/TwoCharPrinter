/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *fileManageBut;
    QLabel *timeDispLab;
    QLabel *previewLab;
    QLabel *printParaLab;
    QPushButton *paraManageBut;
    QPushButton *startPrintBut;
    QPushButton *closeBut;
    QLabel *roolLab;
    QProgressBar *print1Prog;
    QProgressBar *print2Prog;
    QLabel *No1Lab;
    QLabel *No2Lab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 800);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        fileManageBut = new QPushButton(centralWidget);
        fileManageBut->setObjectName(QStringLiteral("fileManageBut"));
        fileManageBut->setGeometry(QRect(1120, 50, 141, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        fileManageBut->setFont(font);
        fileManageBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/fileManage.bmp);"));
        fileManageBut->setIconSize(QSize(20, 20));
        fileManageBut->setAutoDefault(false);
        timeDispLab = new QLabel(centralWidget);
        timeDispLab->setObjectName(QStringLiteral("timeDispLab"));
        timeDispLab->setGeometry(QRect(0, 0, 1281, 51));
        timeDispLab->setTextFormat(Qt::AutoText);
        timeDispLab->setMargin(1);
        previewLab = new QLabel(centralWidget);
        previewLab->setObjectName(QStringLiteral("previewLab"));
        previewLab->setGeometry(QRect(0, 60, 1121, 221));
        previewLab->setLayoutDirection(Qt::LeftToRight);
        printParaLab = new QLabel(centralWidget);
        printParaLab->setObjectName(QStringLiteral("printParaLab"));
        printParaLab->setGeometry(QRect(0, 280, 821, 381));
        printParaLab->setMargin(0);
        paraManageBut = new QPushButton(centralWidget);
        paraManageBut->setObjectName(QStringLiteral("paraManageBut"));
        paraManageBut->setGeometry(QRect(1120, 210, 141, 141));
        paraManageBut->setFont(font);
        paraManageBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/paraManage.bmp);"));
        startPrintBut = new QPushButton(centralWidget);
        startPrintBut->setObjectName(QStringLiteral("startPrintBut"));
        startPrintBut->setGeometry(QRect(1120, 370, 141, 141));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startPrintBut->sizePolicy().hasHeightForWidth());
        startPrintBut->setSizePolicy(sizePolicy);
        startPrintBut->setFont(font);
        startPrintBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/startPrint.bmp);"));
        closeBut = new QPushButton(centralWidget);
        closeBut->setObjectName(QStringLiteral("closeBut"));
        closeBut->setGeometry(QRect(1120, 530, 141, 141));
        closeBut->setFont(font);
        closeBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/closeSys.bmp);"));
        roolLab = new QLabel(centralWidget);
        roolLab->setObjectName(QStringLiteral("roolLab"));
        roolLab->setGeometry(QRect(0, 680, 1271, 51));
        print1Prog = new QProgressBar(centralWidget);
        print1Prog->setObjectName(QStringLiteral("print1Prog"));
        print1Prog->setGeometry(QRect(860, 340, 81, 271));
        print1Prog->setValue(24);
        print1Prog->setOrientation(Qt::Vertical);
        print2Prog = new QProgressBar(centralWidget);
        print2Prog->setObjectName(QStringLiteral("print2Prog"));
        print2Prog->setGeometry(QRect(977, 340, 81, 271));
        print2Prog->setValue(24);
        print2Prog->setOrientation(Qt::Vertical);
        No1Lab = new QLabel(centralWidget);
        No1Lab->setObjectName(QStringLiteral("No1Lab"));
        No1Lab->setGeometry(QRect(860, 620, 72, 15));
        No1Lab->setAlignment(Qt::AlignCenter);
        No2Lab = new QLabel(centralWidget);
        No2Lab->setObjectName(QStringLiteral("No2Lab"));
        No2Lab->setGeometry(QRect(985, 620, 72, 15));
        No2Lab->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        fileManageBut->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\347\256\241\347\220\206", 0));
        timeDispLab->setText(QApplication::translate("MainWindow", "\345\244\232\345\212\237\350\203\275\346\231\272\350\203\275\345\226\267\347\240\201\346\234\272", 0));
        previewLab->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        printParaLab->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        paraManageBut->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\347\256\241\347\220\206", 0));
        startPrintBut->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\211\223\345\215\260", 0));
        closeBut->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\347\263\273\347\273\237", 0));
        roolLab->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        No1Lab->setText(QApplication::translate("MainWindow", "No.1", 0));
        No2Lab->setText(QApplication::translate("MainWindow", "No.2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
