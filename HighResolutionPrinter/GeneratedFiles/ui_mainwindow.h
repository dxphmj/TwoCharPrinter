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
    QLabel *nameDispLab;
    QLabel *previewLab;
    QLabel *fileNmaeLab;
    QPushButton *paraManageBut;
    QPushButton *startPrintBut;
    QPushButton *closeBut;
    QLabel *roolLab;
    QProgressBar *print1Prog;
    QProgressBar *print2Prog;
    QLabel *No1Lab;
    QLabel *No2Lab;
    QLabel *timeShowLab;
    QLabel *signalParaLab;
    QLabel *printParaLab;
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
        fileManageBut->setGeometry(QRect(1120, 50, 144, 144));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        fileManageBut->setFont(font);
        fileManageBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/fileManage.bmp);"));
        fileManageBut->setIconSize(QSize(20, 20));
        fileManageBut->setAutoDefault(false);
        nameDispLab = new QLabel(centralWidget);
        nameDispLab->setObjectName(QStringLiteral("nameDispLab"));
        nameDispLab->setGeometry(QRect(0, 0, 631, 51));
        nameDispLab->setFont(font);
        nameDispLab->setTextFormat(Qt::AutoText);
        nameDispLab->setMargin(1);
        previewLab = new QLabel(centralWidget);
        previewLab->setObjectName(QStringLiteral("previewLab"));
        previewLab->setGeometry(QRect(0, 60, 1121, 221));
        previewLab->setLayoutDirection(Qt::LeftToRight);
        fileNmaeLab = new QLabel(centralWidget);
        fileNmaeLab->setObjectName(QStringLiteral("fileNmaeLab"));
        fileNmaeLab->setGeometry(QRect(0, 280, 273, 381));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        fileNmaeLab->setFont(font1);
        fileNmaeLab->setMargin(0);
        paraManageBut = new QPushButton(centralWidget);
        paraManageBut->setObjectName(QStringLiteral("paraManageBut"));
        paraManageBut->setGeometry(QRect(1120, 210, 144, 144));
        paraManageBut->setFont(font);
        paraManageBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/paraManage.bmp);"));
        startPrintBut = new QPushButton(centralWidget);
        startPrintBut->setObjectName(QStringLiteral("startPrintBut"));
        startPrintBut->setGeometry(QRect(1120, 370, 144, 144));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startPrintBut->sizePolicy().hasHeightForWidth());
        startPrintBut->setSizePolicy(sizePolicy);
        startPrintBut->setFont(font);
        startPrintBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/startPrint.bmp);"));
        closeBut = new QPushButton(centralWidget);
        closeBut->setObjectName(QStringLiteral("closeBut"));
        closeBut->setGeometry(QRect(1120, 530, 144, 144));
        closeBut->setFont(font);
        closeBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/closeSys.bmp);"));
        roolLab = new QLabel(centralWidget);
        roolLab->setObjectName(QStringLiteral("roolLab"));
        roolLab->setGeometry(QRect(0, 680, 1271, 51));
        roolLab->setFont(font);
        print1Prog = new QProgressBar(centralWidget);
        print1Prog->setObjectName(QStringLiteral("print1Prog"));
        print1Prog->setGeometry(QRect(875, 340, 81, 271));
        print1Prog->setValue(24);
        print1Prog->setOrientation(Qt::Vertical);
        print2Prog = new QProgressBar(centralWidget);
        print2Prog->setObjectName(QStringLiteral("print2Prog"));
        print2Prog->setGeometry(QRect(992, 340, 81, 271));
        print2Prog->setValue(24);
        print2Prog->setOrientation(Qt::Vertical);
        No1Lab = new QLabel(centralWidget);
        No1Lab->setObjectName(QStringLiteral("No1Lab"));
        No1Lab->setGeometry(QRect(876, 620, 81, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        No1Lab->setFont(font2);
        No1Lab->setAlignment(Qt::AlignCenter);
        No2Lab = new QLabel(centralWidget);
        No2Lab->setObjectName(QStringLiteral("No2Lab"));
        No2Lab->setGeometry(QRect(990, 620, 81, 31));
        No2Lab->setFont(font2);
        No2Lab->setAlignment(Qt::AlignCenter);
        timeShowLab = new QLabel(centralWidget);
        timeShowLab->setObjectName(QStringLiteral("timeShowLab"));
        timeShowLab->setGeometry(QRect(650, 0, 631, 51));
        timeShowLab->setFont(font);
        signalParaLab = new QLabel(centralWidget);
        signalParaLab->setObjectName(QStringLiteral("signalParaLab"));
        signalParaLab->setGeometry(QRect(290, 280, 273, 381));
        signalParaLab->setFont(font1);
        signalParaLab->setMargin(0);
        printParaLab = new QLabel(centralWidget);
        printParaLab->setObjectName(QStringLiteral("printParaLab"));
        printParaLab->setGeometry(QRect(580, 290, 273, 381));
        printParaLab->setFont(font1);
        printParaLab->setMargin(0);
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
        nameDispLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\244\232\345\212\237\350\203\275\346\231\272\350\203\275\345\226\267\347\240\201\346\234\272</span></p></body></html>", 0));
        previewLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">TextLabel</span></p></body></html>", 0));
        fileNmaeLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\226\207\344\273\266\345\220\215\357\274\232default.spr</span></p><p><br/></p><p><span style=\" color:#ffffff;\">\350\256\241\346\225\260\345\200\274\357\274\232100</span></p></body></html>", 0));
        paraManageBut->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\347\256\241\347\220\206", 0));
        startPrintBut->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\211\223\345\215\260", 0));
        closeBut->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\347\263\273\347\273\237", 0));
        roolLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\270\251\351\246\250\346\217\220\347\244\272\357\274\232\350\257\267\344\270\215\350\246\201\345\234\250\346\211\223\345\215\260\350\277\207\347\250\213\344\270\255\346\213\224\346\216\211\345\242\250\347\233\222\357\274\214\351\230\262\346\255\242\345\226\267\345\230\264\345\240\265\345\241\236\343\200\202</span></p></body></html>", 0));
        No1Lab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffffff;\">\345\242\250\347\233\2221</span></p></body></html>", 0));
        No2Lab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\242\250\347\233\2222</span></p></body></html>", 0));
        timeShowLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" color:#ffffff;\">2020/1/9 16:38:25</span></p></body></html>", 0));
        signalParaLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\224\265\345\216\213\357\274\2328.8V</span><br/></p><p><span style=\" color:#ffffff;\">\350\204\211\345\256\275\357\274\2321.8</span><br/></p><p><span style=\" color:#ffffff;\">\347\201\260\345\272\246\357\274\2325</span></p></body></html>", 0));
        printParaLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\200\237\345\272\246\357\274\23240</span><br/></p><p><span style=\" color:#ffffff;\">\345\273\266\346\227\266\357\274\232152</span><br/></p><p><span style=\" color:#ffffff;\">\346\226\271\345\220\221\357\274\232\351\200\206\345\220\221</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
