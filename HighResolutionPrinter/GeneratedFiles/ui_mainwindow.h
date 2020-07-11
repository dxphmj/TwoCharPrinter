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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <roll.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *fileManageBut;
    QLabel *previewLab;
    QLabel *fileNmaeLab;
    QPushButton *paraManageBut;
    QPushButton *startPrintBut;
    QPushButton *closeBut;
    roll *roolLab;
    QProgressBar *print1Prog;
    QProgressBar *print2Prog;
    QLabel *No1Lab;
    QLabel *No2Lab;
    QLabel *timeShowLab;
    QLabel *voltMWLab;
    QLabel *progCtrlLab;
    QLabel *countValMWLab;
    QLabel *PWMWLab;
    QLabel *grayMWLab;
    QLabel *dirMWLab;
    QLabel *speedMWLab;
    QLabel *timeDelayMWLab;
    QLabel *fileNameShowLab;
    QLabel *countValShowMWLab;
    QLabel *voltShowMWLab;
    QLabel *voltUnitMWLab;
    QLabel *PWShowMWLab;
    QLabel *grayShowMWLab;
    QLabel *speedShowMWLab;
    QLabel *timeDelayShowMWLab;
    QLabel *dirShowMWLab;
    QLabel *nameDispLab;
    QPushButton *pushButton;
    QLabel *pulseWidthUnitMWLab;
    QLabel *speedUnitMWLab;
    QLabel *timeDelayUnitMWLab;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 799);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        fileManageBut = new QPushButton(centralWidget);
        fileManageBut->setObjectName(QStringLiteral("fileManageBut"));
        fileManageBut->setGeometry(QRect(1120, 80, 144, 144));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(18);
        fileManageBut->setFont(font);
        fileManageBut->setStyleSheet(QLatin1String("background-image: url(:/Images/fileManage.bmp);\n"
"color: rgb(255, 255, 255);"));
        fileManageBut->setIconSize(QSize(20, 20));
        fileManageBut->setAutoDefault(false);
        previewLab = new QLabel(centralWidget);
        previewLab->setObjectName(QStringLiteral("previewLab"));
        previewLab->setGeometry(QRect(10, 80, 1101, 331));
        previewLab->setLayoutDirection(Qt::LeftToRight);
        previewLab->setStyleSheet(QStringLiteral("background-color: rgb(77,61, 139);"));
        fileNmaeLab = new QLabel(centralWidget);
        fileNmaeLab->setObjectName(QStringLiteral("fileNmaeLab"));
        fileNmaeLab->setGeometry(QRect(10, 420, 111, 155));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        fileNmaeLab->setFont(font1);
        fileNmaeLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        fileNmaeLab->setMargin(0);
        paraManageBut = new QPushButton(centralWidget);
        paraManageBut->setObjectName(QStringLiteral("paraManageBut"));
        paraManageBut->setGeometry(QRect(1120, 250, 144, 144));
        paraManageBut->setFont(font);
        paraManageBut->setStyleSheet(QLatin1String("background-image: url(:/Images/paraManage.bmp);\n"
"color: rgb(255, 255, 255);"));
        startPrintBut = new QPushButton(centralWidget);
        startPrintBut->setObjectName(QStringLiteral("startPrintBut"));
        startPrintBut->setGeometry(QRect(1120, 420, 144, 144));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startPrintBut->sizePolicy().hasHeightForWidth());
        startPrintBut->setSizePolicy(sizePolicy);
        startPrintBut->setFont(font);
        startPrintBut->setStyleSheet(QLatin1String("background-image: url(:/Images/startPrint.bmp);\n"
"color: rgb(255, 255, 255);"));
        closeBut = new QPushButton(centralWidget);
        closeBut->setObjectName(QStringLiteral("closeBut"));
        closeBut->setGeometry(QRect(1120, 590, 144, 144));
        closeBut->setFont(font);
        closeBut->setStyleSheet(QLatin1String("background-image: url(:/Images/closeSys.bmp);\n"
"color: rgb(255, 255, 255);"));
        roolLab = new roll(centralWidget);
        roolLab->setObjectName(QStringLiteral("roolLab"));
        roolLab->setGeometry(QRect(10, 740, 1261, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(28);
        roolLab->setFont(font2);
        roolLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        print1Prog = new QProgressBar(centralWidget);
        print1Prog->setObjectName(QStringLiteral("print1Prog"));
        print1Prog->setGeometry(QRect(905, 450, 51, 211));
        print1Prog->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        print1Prog->setValue(69);
        print1Prog->setTextVisible(true);
        print1Prog->setOrientation(Qt::Vertical);
        print2Prog = new QProgressBar(centralWidget);
        print2Prog->setObjectName(QStringLiteral("print2Prog"));
        print2Prog->setGeometry(QRect(1022, 450, 51, 211));
        print2Prog->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        print2Prog->setValue(50);
        print2Prog->setOrientation(Qt::Vertical);
        No1Lab = new QLabel(centralWidget);
        No1Lab->setObjectName(QStringLiteral("No1Lab"));
        No1Lab->setGeometry(QRect(870, 670, 121, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(12);
        No1Lab->setFont(font3);
        No1Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        No1Lab->setAlignment(Qt::AlignCenter);
        No2Lab = new QLabel(centralWidget);
        No2Lab->setObjectName(QStringLiteral("No2Lab"));
        No2Lab->setGeometry(QRect(990, 670, 121, 31));
        No2Lab->setFont(font3);
        No2Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        No2Lab->setAlignment(Qt::AlignCenter);
        timeShowLab = new QLabel(centralWidget);
        timeShowLab->setObjectName(QStringLiteral("timeShowLab"));
        timeShowLab->setGeometry(QRect(640, 0, 641, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(16);
        timeShowLab->setFont(font4);
        timeShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 130);\n"
"color: rgb(255, 255, 255);"));
        voltMWLab = new QLabel(centralWidget);
        voltMWLab->setObjectName(QStringLiteral("voltMWLab"));
        voltMWLab->setGeometry(QRect(290, 420, 121, 103));
        voltMWLab->setFont(font1);
        voltMWLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        voltMWLab->setMargin(0);
        progCtrlLab = new QLabel(centralWidget);
        progCtrlLab->setObjectName(QStringLiteral("progCtrlLab"));
        progCtrlLab->setGeometry(QRect(850, 420, 271, 311));
        progCtrlLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        countValMWLab = new QLabel(centralWidget);
        countValMWLab->setObjectName(QStringLiteral("countValMWLab"));
        countValMWLab->setGeometry(QRect(10, 576, 111, 155));
        countValMWLab->setFont(font1);
        countValMWLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        countValMWLab->setMargin(0);
        PWMWLab = new QLabel(centralWidget);
        PWMWLab->setObjectName(QStringLiteral("PWMWLab"));
        PWMWLab->setGeometry(QRect(290, 524, 121, 103));
        PWMWLab->setFont(font1);
        PWMWLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        PWMWLab->setMargin(0);
        grayMWLab = new QLabel(centralWidget);
        grayMWLab->setObjectName(QStringLiteral("grayMWLab"));
        grayMWLab->setGeometry(QRect(290, 628, 121, 103));
        grayMWLab->setFont(font1);
        grayMWLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        grayMWLab->setMargin(0);
        dirMWLab = new QLabel(centralWidget);
        dirMWLab->setObjectName(QStringLiteral("dirMWLab"));
        dirMWLab->setGeometry(QRect(550, 628, 121, 103));
        dirMWLab->setFont(font1);
        dirMWLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        dirMWLab->setMargin(0);
        speedMWLab = new QLabel(centralWidget);
        speedMWLab->setObjectName(QStringLiteral("speedMWLab"));
        speedMWLab->setGeometry(QRect(550, 420, 121, 103));
        speedMWLab->setFont(font1);
        speedMWLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        speedMWLab->setMargin(0);
        timeDelayMWLab = new QLabel(centralWidget);
        timeDelayMWLab->setObjectName(QStringLiteral("timeDelayMWLab"));
        timeDelayMWLab->setGeometry(QRect(550, 524, 121, 103));
        timeDelayMWLab->setFont(font1);
        timeDelayMWLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        timeDelayMWLab->setMargin(0);
        fileNameShowLab = new QLabel(centralWidget);
        fileNameShowLab->setObjectName(QStringLiteral("fileNameShowLab"));
        fileNameShowLab->setGeometry(QRect(120, 420, 170, 155));
        fileNameShowLab->setFont(font1);
        fileNameShowLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        fileNameShowLab->setMargin(0);
        countValShowMWLab = new QLabel(centralWidget);
        countValShowMWLab->setObjectName(QStringLiteral("countValShowMWLab"));
        countValShowMWLab->setGeometry(QRect(120, 576, 170, 155));
        countValShowMWLab->setFont(font1);
        countValShowMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        countValShowMWLab->setMargin(0);
        voltShowMWLab = new QLabel(centralWidget);
        voltShowMWLab->setObjectName(QStringLiteral("voltShowMWLab"));
        voltShowMWLab->setGeometry(QRect(410, 420, 71, 103));
        voltShowMWLab->setFont(font1);
        voltShowMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        voltShowMWLab->setMargin(0);
        voltUnitMWLab = new QLabel(centralWidget);
        voltUnitMWLab->setObjectName(QStringLiteral("voltUnitMWLab"));
        voltUnitMWLab->setGeometry(QRect(450, 420, 101, 103));
        voltUnitMWLab->setFont(font1);
        voltUnitMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        voltUnitMWLab->setMargin(0);
        PWShowMWLab = new QLabel(centralWidget);
        PWShowMWLab->setObjectName(QStringLiteral("PWShowMWLab"));
        PWShowMWLab->setGeometry(QRect(410, 524, 71, 103));
        PWShowMWLab->setFont(font1);
        PWShowMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        PWShowMWLab->setMargin(0);
        grayShowMWLab = new QLabel(centralWidget);
        grayShowMWLab->setObjectName(QStringLiteral("grayShowMWLab"));
        grayShowMWLab->setGeometry(QRect(410, 629, 141, 103));
        grayShowMWLab->setFont(font1);
        grayShowMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        grayShowMWLab->setMargin(0);
        speedShowMWLab = new QLabel(centralWidget);
        speedShowMWLab->setObjectName(QStringLiteral("speedShowMWLab"));
        speedShowMWLab->setGeometry(QRect(670, 420, 81, 103));
        speedShowMWLab->setFont(font1);
        speedShowMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        speedShowMWLab->setMargin(0);
        timeDelayShowMWLab = new QLabel(centralWidget);
        timeDelayShowMWLab->setObjectName(QStringLiteral("timeDelayShowMWLab"));
        timeDelayShowMWLab->setGeometry(QRect(670, 524, 91, 103));
        timeDelayShowMWLab->setFont(font1);
        timeDelayShowMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        timeDelayShowMWLab->setMargin(0);
        dirShowMWLab = new QLabel(centralWidget);
        dirShowMWLab->setObjectName(QStringLiteral("dirShowMWLab"));
        dirShowMWLab->setGeometry(QRect(670, 628, 181, 103));
        dirShowMWLab->setFont(font1);
        dirShowMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        dirShowMWLab->setMargin(0);
        nameDispLab = new QLabel(centralWidget);
        nameDispLab->setObjectName(QStringLiteral("nameDispLab"));
        nameDispLab->setGeometry(QRect(0, 0, 641, 71));
        nameDispLab->setFont(font4);
        nameDispLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(18, 677, 91, 50));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"\346\245\267\344\275\223\";"));
        pulseWidthUnitMWLab = new QLabel(centralWidget);
        pulseWidthUnitMWLab->setObjectName(QStringLiteral("pulseWidthUnitMWLab"));
        pulseWidthUnitMWLab->setGeometry(QRect(460, 520, 91, 103));
        pulseWidthUnitMWLab->setFont(font1);
        pulseWidthUnitMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        pulseWidthUnitMWLab->setMargin(0);
        speedUnitMWLab = new QLabel(centralWidget);
        speedUnitMWLab->setObjectName(QStringLiteral("speedUnitMWLab"));
        speedUnitMWLab->setGeometry(QRect(740, 420, 111, 103));
        speedUnitMWLab->setFont(font1);
        speedUnitMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        speedUnitMWLab->setMargin(0);
        timeDelayUnitMWLab = new QLabel(centralWidget);
        timeDelayUnitMWLab->setObjectName(QStringLiteral("timeDelayUnitMWLab"));
        timeDelayUnitMWLab->setGeometry(QRect(710, 520, 141, 110));
        timeDelayUnitMWLab->setFont(font1);
        timeDelayUnitMWLab->setStyleSheet(QLatin1String("background-color: rgb(77,61, 139);\n"
"color: rgb(255, 255, 255);"));
        timeDelayUnitMWLab->setMargin(0);
        MainWindow->setCentralWidget(centralWidget);
        progCtrlLab->raise();
        fileManageBut->raise();
        previewLab->raise();
        fileNmaeLab->raise();
        paraManageBut->raise();
        startPrintBut->raise();
        closeBut->raise();
        roolLab->raise();
        print1Prog->raise();
        print2Prog->raise();
        No1Lab->raise();
        No2Lab->raise();
        timeShowLab->raise();
        voltMWLab->raise();
        countValMWLab->raise();
        PWMWLab->raise();
        grayMWLab->raise();
        dirMWLab->raise();
        speedMWLab->raise();
        timeDelayMWLab->raise();
        fileNameShowLab->raise();
        countValShowMWLab->raise();
        voltUnitMWLab->raise();
        grayShowMWLab->raise();
        dirShowMWLab->raise();
        nameDispLab->raise();
        pushButton->raise();
        pulseWidthUnitMWLab->raise();
        speedUnitMWLab->raise();
        timeDelayUnitMWLab->raise();
        voltShowMWLab->raise();
        PWShowMWLab->raise();
        speedShowMWLab->raise();
        timeDelayShowMWLab->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        fileManageBut->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\347\256\241\347\220\206", 0));
        previewLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
        fileNmaeLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\346\226\207\344\273\266\345\220\215\357\274\232</span></p></body></html>", 0));
        paraManageBut->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\347\256\241\347\220\206", 0));
        startPrintBut->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\211\223\345\215\260", 0));
        closeBut->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\347\263\273\347\273\237", 0));
        roolLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
        No1Lab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffffff;\">\345\242\250\347\233\2221</span></p></body></html>", 0));
        No2Lab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\242\250\347\233\2222</span></p></body></html>", 0));
        timeShowLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:26pt; color:#ffffff;\">2020-1-10 10:09   </span></p></body></html>", 0));
        voltMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\347\224\265\345\216\213\357\274\232</span></p></body></html>", 0));
        progCtrlLab->setText(QString());
        countValMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\350\256\241\346\225\260\345\200\274\357\274\232</span></p></body></html>", 0));
        PWMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\350\204\211\345\256\275\357\274\232</span></p></body></html>", 0));
        grayMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\347\201\260\345\272\246\357\274\232</span></p></body></html>", 0));
        dirMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\346\226\271\345\220\221\357\274\232</span></p></body></html>", 0));
        speedMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\351\200\237\345\272\246\357\274\232</span></p></body></html>", 0));
        timeDelayMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">\345\273\266\350\277\237\357\274\232</span></p></body></html>", 0));
        fileNameShowLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        countValShowMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        voltShowMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        voltUnitMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">V</span></p></body></html>", 0));
        PWShowMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        grayShowMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        speedShowMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        timeDelayShowMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        dirShowMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        nameDispLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; color:#ffffff;\">  \345\244\232\345\212\237\350\203\275\346\231\272\350\203\275\345\226\267\347\240\201\346\234\272</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", 0));
        pulseWidthUnitMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-family:'\347\255\211\347\272\277';\">\316\274s</span></p></body></html>", 0));
        speedUnitMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">m/min</p></body></html>", 0));
        timeDelayUnitMWLab->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">mm</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
