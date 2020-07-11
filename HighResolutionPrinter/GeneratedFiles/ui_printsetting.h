/********************************************************************************
** Form generated from reading UI file 'printsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTSETTING_H
#define UI_PRINTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <lineedit_click.h>

QT_BEGIN_NAMESPACE

class Ui_printSetting
{
public:
    QTabWidget *printSetTabWid;
    QWidget *printStyleTab;
    QPushButton *printSpeedRedBut;
    QLabel *trigLab;
    QLabel *printSpeedShowLab;
    QPushButton *printSpeedAddBut;
    QLabel *printSpeedLab;
    QComboBox *trigComBox;
    QComboBox *inkjetComBox;
    QLabel *inkjetLab;
    QComboBox *printDirComBox;
    QLabel *printDirLab;
    QLabel *printDelayLab;
    QPushButton *printDelayRedBut;
    QLabel *printDelayShowLab;
    QPushButton *printDelayAddBut;
    QLabel *synFrequencyLab;
    QPushButton *synFrequencyRedBut;
    QLabel *synFrequencyShowLab;
    QPushButton *synFrequencyAddBut;
    QPushButton *printGrayAddBut;
    QLabel *printGrayShowLab;
    QLabel *printGrayLab;
    QPushButton *printGrayRedBut;
    QCheckBox *synWheelCheckBox;
    QCheckBox *voiceCheckBox;
    QLabel *printStyleBGLabel;
    QLabel *encoderResLab;
    QLabel *wheelDiameterLab;
    QLabel *pulseWidthLab;
    QLabel *proLineSpeedLab;
    QLabel *proLineSpeedShowLab;
    lineedit_click *encoderResLineEdit;
    lineedit_click *pulseWidthLineEdit;
    lineedit_click *wheelDiameterLineEdit;
    QWidget *settingTab;
    QLabel *XDPILab;
    QRadioButton *XDPI100RadioBut;
    QRadioButton *XDPI150RadioBut;
    QRadioButton *XDPI200RadioBut;
    QRadioButton *XDPI300RadioBut;
    QCheckBox *repetePrintCheckBox;
    QLabel *repeteNumShowLab;
    QPushButton *repeteNumAddBut;
    QLabel *repeteLab;
    QPushButton *repeteNumRedBut;
    QPushButton *repeteDelayRedBut;
    QLabel *repeteDelayShowLab;
    QPushButton *repeteDelayAddBut;
    QLabel *repeteDelayLab;
    QLabel *settingBGLabel;
    QLabel *YDPILab;
    QRadioButton *YDPI300RadioBut;
    QRadioButton *YDPI600RadioBut;
    QRadioButton *XDPI600RadioBut;
    QLabel *horizonalReverseLab;
    QLabel *verticalReverseLab;
    QComboBox *horizonalReverseComBox;
    QComboBox *verticalReverseComBox;
    QWidget *nozzleSetTab;
    QLabel *inkTypeLab;
    QCheckBox *adaptParaCheckBox;
    QLabel *voltShowLab;
    QPushButton *voltAddBut;
    QLabel *inkVoltLab;
    QPushButton *voltRedBut;
    QLabel *PWShowLab;
    QPushButton *PWAddBut;
    QLabel *PWLab;
    QPushButton *PWRedBut;
    QLabel *nozzleSelLab;
    QPushButton *offsetRedBut;
    QLabel *offsetShowLab;
    QPushButton *offsetAddBut;
    QLabel *offsetLab;
    QRadioButton *nozzleSel2RadioBut;
    QRadioButton *nozzleSel1RadioBut;
    QLabel *flashSprayLab;
    QCheckBox *flashSprayCheckBox;
    QLabel *flashSprayInternalShowLab;
    QLabel *flashSprayInternalLab;
    QPushButton *flashSprayInternalRedBut;
    QPushButton *flashSprayInternalAddBut;
    QCheckBox *isCombineCheckBox;
    QLabel *printSetBGLabel;
    QWidget *UVSettingTab;
    QLabel *UVSetBGLabel;
    QCheckBox *isUVCheckBox;
    QPushButton *startTimeAddBut;
    QPushButton *delayTimeRedBut;
    QPushButton *startTimeRedBut;
    QLabel *delayTimeShowLab;
    QPushButton *delayTimeAddBut;
    QLabel *delayTimeLab;
    QLabel *startTimeShowLab;
    QLabel *startTimeLab;

    void setupUi(QWidget *printSetting)
    {
        if (printSetting->objectName().isEmpty())
            printSetting->setObjectName(QStringLiteral("printSetting"));
        printSetting->resize(1133, 651);
        printSetting->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        printSetTabWid = new QTabWidget(printSetting);
        printSetTabWid->setObjectName(QStringLiteral("printSetTabWid"));
        printSetTabWid->setGeometry(QRect(20, 20, 1021, 621));
        printSetTabWid->setMaximumSize(QSize(1021, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        printSetTabWid->setFont(font);
        printSetTabWid->setStyleSheet(QLatin1String("QTabBar::tab{width:255}\n"
"QTabBar::tab{height:50}"));
        printStyleTab = new QWidget();
        printStyleTab->setObjectName(QStringLiteral("printStyleTab"));
        printSpeedRedBut = new QPushButton(printStyleTab);
        printSpeedRedBut->setObjectName(QStringLiteral("printSpeedRedBut"));
        printSpeedRedBut->setGeometry(QRect(310, 50, 41, 41));
        printSpeedRedBut->setMinimumSize(QSize(41, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        printSpeedRedBut->setFont(font1);
        printSpeedRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        trigLab = new QLabel(printStyleTab);
        trigLab->setObjectName(QStringLiteral("trigLab"));
        trigLab->setGeometry(QRect(610, 80, 151, 41));
        trigLab->setMinimumSize(QSize(101, 41));
        trigLab->setFont(font);
        trigLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        trigLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printSpeedShowLab = new QLabel(printStyleTab);
        printSpeedShowLab->setObjectName(QStringLiteral("printSpeedShowLab"));
        printSpeedShowLab->setGeometry(QRect(350, 50, 131, 41));
        printSpeedShowLab->setMinimumSize(QSize(0, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        printSpeedShowLab->setFont(font2);
        printSpeedShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        printSpeedShowLab->setAlignment(Qt::AlignCenter);
        printSpeedAddBut = new QPushButton(printStyleTab);
        printSpeedAddBut->setObjectName(QStringLiteral("printSpeedAddBut"));
        printSpeedAddBut->setGeometry(QRect(480, 50, 41, 41));
        printSpeedAddBut->setMinimumSize(QSize(41, 41));
        printSpeedAddBut->setFont(font1);
        printSpeedAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printSpeedLab = new QLabel(printStyleTab);
        printSpeedLab->setObjectName(QStringLiteral("printSpeedLab"));
        printSpeedLab->setGeometry(QRect(70, 50, 221, 41));
        printSpeedLab->setMinimumSize(QSize(101, 41));
        printSpeedLab->setFont(font);
        printSpeedLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        printSpeedLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        trigComBox = new QComboBox(printStyleTab);
        trigComBox->setObjectName(QStringLiteral("trigComBox"));
        trigComBox->setGeometry(QRect(760, 80, 181, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(14);
        trigComBox->setFont(font3);
        trigComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        inkjetComBox = new QComboBox(printStyleTab);
        inkjetComBox->setObjectName(QStringLiteral("inkjetComBox"));
        inkjetComBox->setGeometry(QRect(760, 160, 181, 41));
        inkjetComBox->setFont(font3);
        inkjetComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        inkjetLab = new QLabel(printStyleTab);
        inkjetLab->setObjectName(QStringLiteral("inkjetLab"));
        inkjetLab->setGeometry(QRect(610, 160, 151, 41));
        inkjetLab->setMinimumSize(QSize(101, 41));
        inkjetLab->setFont(font);
        inkjetLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        inkjetLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printDirComBox = new QComboBox(printStyleTab);
        printDirComBox->setObjectName(QStringLiteral("printDirComBox"));
        printDirComBox->setGeometry(QRect(760, 240, 181, 41));
        printDirComBox->setFont(font3);
        printDirComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printDirLab = new QLabel(printStyleTab);
        printDirLab->setObjectName(QStringLiteral("printDirLab"));
        printDirLab->setGeometry(QRect(610, 240, 151, 41));
        printDirLab->setMinimumSize(QSize(101, 41));
        printDirLab->setFont(font);
        printDirLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        printDirLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printDelayLab = new QLabel(printStyleTab);
        printDelayLab->setObjectName(QStringLiteral("printDelayLab"));
        printDelayLab->setGeometry(QRect(70, 120, 221, 41));
        printDelayLab->setMinimumSize(QSize(101, 41));
        printDelayLab->setFont(font);
        printDelayLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        printDelayLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printDelayRedBut = new QPushButton(printStyleTab);
        printDelayRedBut->setObjectName(QStringLiteral("printDelayRedBut"));
        printDelayRedBut->setGeometry(QRect(310, 120, 41, 41));
        printDelayRedBut->setMinimumSize(QSize(41, 41));
        printDelayRedBut->setFont(font1);
        printDelayRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printDelayShowLab = new QLabel(printStyleTab);
        printDelayShowLab->setObjectName(QStringLiteral("printDelayShowLab"));
        printDelayShowLab->setGeometry(QRect(350, 120, 131, 41));
        printDelayShowLab->setMinimumSize(QSize(0, 41));
        printDelayShowLab->setFont(font2);
        printDelayShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        printDelayShowLab->setAlignment(Qt::AlignCenter);
        printDelayAddBut = new QPushButton(printStyleTab);
        printDelayAddBut->setObjectName(QStringLiteral("printDelayAddBut"));
        printDelayAddBut->setGeometry(QRect(480, 120, 41, 41));
        printDelayAddBut->setMinimumSize(QSize(41, 41));
        printDelayAddBut->setFont(font1);
        printDelayAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        synFrequencyLab = new QLabel(printStyleTab);
        synFrequencyLab->setObjectName(QStringLiteral("synFrequencyLab"));
        synFrequencyLab->setGeometry(QRect(70, 190, 221, 41));
        synFrequencyLab->setMinimumSize(QSize(101, 41));
        synFrequencyLab->setFont(font);
        synFrequencyLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        synFrequencyLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        synFrequencyRedBut = new QPushButton(printStyleTab);
        synFrequencyRedBut->setObjectName(QStringLiteral("synFrequencyRedBut"));
        synFrequencyRedBut->setGeometry(QRect(310, 190, 41, 41));
        synFrequencyRedBut->setMinimumSize(QSize(41, 41));
        synFrequencyRedBut->setFont(font1);
        synFrequencyRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        synFrequencyShowLab = new QLabel(printStyleTab);
        synFrequencyShowLab->setObjectName(QStringLiteral("synFrequencyShowLab"));
        synFrequencyShowLab->setGeometry(QRect(350, 190, 131, 41));
        synFrequencyShowLab->setMinimumSize(QSize(0, 41));
        synFrequencyShowLab->setFont(font2);
        synFrequencyShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        synFrequencyShowLab->setAlignment(Qt::AlignCenter);
        synFrequencyAddBut = new QPushButton(printStyleTab);
        synFrequencyAddBut->setObjectName(QStringLiteral("synFrequencyAddBut"));
        synFrequencyAddBut->setGeometry(QRect(480, 190, 41, 41));
        synFrequencyAddBut->setMinimumSize(QSize(41, 41));
        synFrequencyAddBut->setFont(font1);
        synFrequencyAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printGrayAddBut = new QPushButton(printStyleTab);
        printGrayAddBut->setObjectName(QStringLiteral("printGrayAddBut"));
        printGrayAddBut->setGeometry(QRect(480, 260, 41, 41));
        printGrayAddBut->setMinimumSize(QSize(41, 41));
        printGrayAddBut->setFont(font1);
        printGrayAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printGrayShowLab = new QLabel(printStyleTab);
        printGrayShowLab->setObjectName(QStringLiteral("printGrayShowLab"));
        printGrayShowLab->setGeometry(QRect(350, 260, 131, 41));
        printGrayShowLab->setMinimumSize(QSize(0, 41));
        printGrayShowLab->setFont(font2);
        printGrayShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        printGrayShowLab->setAlignment(Qt::AlignCenter);
        printGrayLab = new QLabel(printStyleTab);
        printGrayLab->setObjectName(QStringLiteral("printGrayLab"));
        printGrayLab->setGeometry(QRect(70, 260, 221, 41));
        printGrayLab->setMinimumSize(QSize(101, 41));
        printGrayLab->setFont(font);
        printGrayLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        printGrayLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printGrayRedBut = new QPushButton(printStyleTab);
        printGrayRedBut->setObjectName(QStringLiteral("printGrayRedBut"));
        printGrayRedBut->setGeometry(QRect(310, 260, 41, 41));
        printGrayRedBut->setMinimumSize(QSize(41, 41));
        printGrayRedBut->setFont(font1);
        printGrayRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        synWheelCheckBox = new QCheckBox(printStyleTab);
        synWheelCheckBox->setObjectName(QStringLiteral("synWheelCheckBox"));
        synWheelCheckBox->setGeometry(QRect(610, 330, 201, 31));
        synWheelCheckBox->setFont(font);
        synWheelCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        synWheelCheckBox->setChecked(false);
        synWheelCheckBox->setAutoRepeat(false);
        voiceCheckBox = new QCheckBox(printStyleTab);
        voiceCheckBox->setObjectName(QStringLiteral("voiceCheckBox"));
        voiceCheckBox->setGeometry(QRect(610, 460, 101, 31));
        voiceCheckBox->setFont(font);
        voiceCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        voiceCheckBox->setChecked(false);
        voiceCheckBox->setAutoRepeat(false);
        printStyleBGLabel = new QLabel(printStyleTab);
        printStyleBGLabel->setObjectName(QStringLiteral("printStyleBGLabel"));
        printStyleBGLabel->setGeometry(QRect(0, 0, 1016, 571));
        printStyleBGLabel->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        printStyleBGLabel->setFrameShape(QFrame::StyledPanel);
        encoderResLab = new QLabel(printStyleTab);
        encoderResLab->setObjectName(QStringLiteral("encoderResLab"));
        encoderResLab->setGeometry(QRect(70, 330, 251, 41));
        encoderResLab->setMinimumSize(QSize(101, 41));
        encoderResLab->setFont(font);
        encoderResLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        encoderResLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        wheelDiameterLab = new QLabel(printStyleTab);
        wheelDiameterLab->setObjectName(QStringLiteral("wheelDiameterLab"));
        wheelDiameterLab->setGeometry(QRect(70, 400, 221, 41));
        wheelDiameterLab->setMinimumSize(QSize(101, 41));
        wheelDiameterLab->setFont(font);
        wheelDiameterLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        wheelDiameterLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pulseWidthLab = new QLabel(printStyleTab);
        pulseWidthLab->setObjectName(QStringLiteral("pulseWidthLab"));
        pulseWidthLab->setGeometry(QRect(70, 470, 251, 41));
        pulseWidthLab->setMinimumSize(QSize(101, 41));
        pulseWidthLab->setFont(font);
        pulseWidthLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        pulseWidthLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        proLineSpeedLab = new QLabel(printStyleTab);
        proLineSpeedLab->setObjectName(QStringLiteral("proLineSpeedLab"));
        proLineSpeedLab->setGeometry(QRect(610, 380, 221, 41));
        proLineSpeedLab->setMinimumSize(QSize(101, 41));
        proLineSpeedLab->setFont(font);
        proLineSpeedLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        proLineSpeedLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        proLineSpeedShowLab = new QLabel(printStyleTab);
        proLineSpeedShowLab->setObjectName(QStringLiteral("proLineSpeedShowLab"));
        proLineSpeedShowLab->setGeometry(QRect(830, 380, 131, 41));
        proLineSpeedShowLab->setMinimumSize(QSize(0, 41));
        proLineSpeedShowLab->setFont(font2);
        proLineSpeedShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
""));
        proLineSpeedShowLab->setFrameShape(QFrame::StyledPanel);
        proLineSpeedShowLab->setAlignment(Qt::AlignCenter);
        encoderResLineEdit = new lineedit_click(printStyleTab);
        encoderResLineEdit->setObjectName(QStringLiteral("encoderResLineEdit"));
        encoderResLineEdit->setGeometry(QRect(350, 330, 131, 41));
        encoderResLineEdit->setFont(font);
        encoderResLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pulseWidthLineEdit = new lineedit_click(printStyleTab);
        pulseWidthLineEdit->setObjectName(QStringLiteral("pulseWidthLineEdit"));
        pulseWidthLineEdit->setGeometry(QRect(350, 470, 131, 41));
        pulseWidthLineEdit->setFont(font);
        pulseWidthLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        wheelDiameterLineEdit = new lineedit_click(printStyleTab);
        wheelDiameterLineEdit->setObjectName(QStringLiteral("wheelDiameterLineEdit"));
        wheelDiameterLineEdit->setGeometry(QRect(350, 400, 131, 41));
        wheelDiameterLineEdit->setFont(font);
        wheelDiameterLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        printSetTabWid->addTab(printStyleTab, QString());
        printStyleBGLabel->raise();
        printSpeedRedBut->raise();
        trigLab->raise();
        printSpeedShowLab->raise();
        printSpeedAddBut->raise();
        printSpeedLab->raise();
        trigComBox->raise();
        inkjetComBox->raise();
        inkjetLab->raise();
        printDirComBox->raise();
        printDirLab->raise();
        printDelayLab->raise();
        printDelayRedBut->raise();
        printDelayShowLab->raise();
        printDelayAddBut->raise();
        synFrequencyLab->raise();
        synFrequencyRedBut->raise();
        synFrequencyShowLab->raise();
        synFrequencyAddBut->raise();
        printGrayAddBut->raise();
        printGrayShowLab->raise();
        printGrayLab->raise();
        printGrayRedBut->raise();
        synWheelCheckBox->raise();
        voiceCheckBox->raise();
        encoderResLab->raise();
        wheelDiameterLab->raise();
        pulseWidthLab->raise();
        proLineSpeedLab->raise();
        proLineSpeedShowLab->raise();
        encoderResLineEdit->raise();
        pulseWidthLineEdit->raise();
        wheelDiameterLineEdit->raise();
        settingTab = new QWidget();
        settingTab->setObjectName(QStringLiteral("settingTab"));
        XDPILab = new QLabel(settingTab);
        XDPILab->setObjectName(QStringLiteral("XDPILab"));
        XDPILab->setGeometry(QRect(80, 80, 101, 41));
        XDPILab->setMinimumSize(QSize(101, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setPointSize(16);
        XDPILab->setFont(font4);
        XDPILab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        XDPILab->setAlignment(Qt::AlignCenter);
        XDPI100RadioBut = new QRadioButton(settingTab);
        XDPI100RadioBut->setObjectName(QStringLiteral("XDPI100RadioBut"));
        XDPI100RadioBut->setGeometry(QRect(220, 80, 91, 41));
        XDPI100RadioBut->setFont(font4);
        XDPI100RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        XDPI150RadioBut = new QRadioButton(settingTab);
        XDPI150RadioBut->setObjectName(QStringLiteral("XDPI150RadioBut"));
        XDPI150RadioBut->setGeometry(QRect(360, 80, 91, 41));
        XDPI150RadioBut->setFont(font4);
        XDPI150RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        XDPI200RadioBut = new QRadioButton(settingTab);
        XDPI200RadioBut->setObjectName(QStringLiteral("XDPI200RadioBut"));
        XDPI200RadioBut->setGeometry(QRect(500, 80, 91, 41));
        XDPI200RadioBut->setFont(font4);
        XDPI200RadioBut->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        XDPI300RadioBut = new QRadioButton(settingTab);
        XDPI300RadioBut->setObjectName(QStringLiteral("XDPI300RadioBut"));
        XDPI300RadioBut->setGeometry(QRect(640, 80, 91, 41));
        XDPI300RadioBut->setFont(font4);
        XDPI300RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        repetePrintCheckBox = new QCheckBox(settingTab);
        repetePrintCheckBox->setObjectName(QStringLiteral("repetePrintCheckBox"));
        repetePrintCheckBox->setGeometry(QRect(520, 260, 181, 31));
        repetePrintCheckBox->setFont(font);
        repetePrintCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        repetePrintCheckBox->setChecked(false);
        repetePrintCheckBox->setAutoRepeat(false);
        repeteNumShowLab = new QLabel(settingTab);
        repeteNumShowLab->setObjectName(QStringLiteral("repeteNumShowLab"));
        repeteNumShowLab->setGeometry(QRect(750, 340, 160, 41));
        repeteNumShowLab->setMinimumSize(QSize(0, 41));
        repeteNumShowLab->setFont(font2);
        repeteNumShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        repeteNumShowLab->setAlignment(Qt::AlignCenter);
        repeteNumAddBut = new QPushButton(settingTab);
        repeteNumAddBut->setObjectName(QStringLiteral("repeteNumAddBut"));
        repeteNumAddBut->setGeometry(QRect(910, 340, 41, 41));
        repeteNumAddBut->setMinimumSize(QSize(41, 41));
        repeteNumAddBut->setFont(font1);
        repeteNumAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteLab = new QLabel(settingTab);
        repeteLab->setObjectName(QStringLiteral("repeteLab"));
        repeteLab->setGeometry(QRect(520, 340, 191, 41));
        repeteLab->setMinimumSize(QSize(101, 41));
        repeteLab->setFont(font);
        repeteLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        repeteLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        repeteNumRedBut = new QPushButton(settingTab);
        repeteNumRedBut->setObjectName(QStringLiteral("repeteNumRedBut"));
        repeteNumRedBut->setGeometry(QRect(710, 340, 41, 41));
        repeteNumRedBut->setMinimumSize(QSize(41, 41));
        repeteNumRedBut->setFont(font1);
        repeteNumRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteDelayRedBut = new QPushButton(settingTab);
        repeteDelayRedBut->setObjectName(QStringLiteral("repeteDelayRedBut"));
        repeteDelayRedBut->setGeometry(QRect(710, 420, 41, 41));
        repeteDelayRedBut->setMinimumSize(QSize(41, 41));
        repeteDelayRedBut->setFont(font1);
        repeteDelayRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteDelayShowLab = new QLabel(settingTab);
        repeteDelayShowLab->setObjectName(QStringLiteral("repeteDelayShowLab"));
        repeteDelayShowLab->setGeometry(QRect(750, 420, 160, 41));
        repeteDelayShowLab->setMinimumSize(QSize(0, 41));
        repeteDelayShowLab->setFont(font2);
        repeteDelayShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        repeteDelayShowLab->setAlignment(Qt::AlignCenter);
        repeteDelayAddBut = new QPushButton(settingTab);
        repeteDelayAddBut->setObjectName(QStringLiteral("repeteDelayAddBut"));
        repeteDelayAddBut->setGeometry(QRect(910, 420, 41, 41));
        repeteDelayAddBut->setMinimumSize(QSize(41, 41));
        repeteDelayAddBut->setFont(font1);
        repeteDelayAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteDelayLab = new QLabel(settingTab);
        repeteDelayLab->setObjectName(QStringLiteral("repeteDelayLab"));
        repeteDelayLab->setGeometry(QRect(520, 420, 191, 41));
        repeteDelayLab->setMinimumSize(QSize(101, 41));
        repeteDelayLab->setFont(font);
        repeteDelayLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        repeteDelayLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        settingBGLabel = new QLabel(settingTab);
        settingBGLabel->setObjectName(QStringLiteral("settingBGLabel"));
        settingBGLabel->setGeometry(QRect(0, 0, 1016, 571));
        settingBGLabel->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        YDPILab = new QLabel(settingTab);
        YDPILab->setObjectName(QStringLiteral("YDPILab"));
        YDPILab->setGeometry(QRect(80, 150, 101, 41));
        YDPILab->setMinimumSize(QSize(101, 41));
        YDPILab->setFont(font4);
        YDPILab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        YDPILab->setAlignment(Qt::AlignCenter);
        YDPI300RadioBut = new QRadioButton(settingTab);
        YDPI300RadioBut->setObjectName(QStringLiteral("YDPI300RadioBut"));
        YDPI300RadioBut->setGeometry(QRect(220, 150, 91, 41));
        YDPI300RadioBut->setFont(font4);
        YDPI300RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        YDPI600RadioBut = new QRadioButton(settingTab);
        YDPI600RadioBut->setObjectName(QStringLiteral("YDPI600RadioBut"));
        YDPI600RadioBut->setGeometry(QRect(360, 150, 91, 41));
        YDPI600RadioBut->setFont(font4);
        YDPI600RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        XDPI600RadioBut = new QRadioButton(settingTab);
        XDPI600RadioBut->setObjectName(QStringLiteral("XDPI600RadioBut"));
        XDPI600RadioBut->setGeometry(QRect(780, 80, 91, 41));
        XDPI600RadioBut->setFont(font4);
        XDPI600RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        horizonalReverseLab = new QLabel(settingTab);
        horizonalReverseLab->setObjectName(QStringLiteral("horizonalReverseLab"));
        horizonalReverseLab->setGeometry(QRect(100, 290, 131, 41));
        horizonalReverseLab->setMinimumSize(QSize(101, 41));
        horizonalReverseLab->setFont(font);
        horizonalReverseLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        horizonalReverseLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalReverseLab = new QLabel(settingTab);
        verticalReverseLab->setObjectName(QStringLiteral("verticalReverseLab"));
        verticalReverseLab->setGeometry(QRect(100, 370, 131, 41));
        verticalReverseLab->setMinimumSize(QSize(101, 41));
        verticalReverseLab->setFont(font);
        verticalReverseLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        verticalReverseLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizonalReverseComBox = new QComboBox(settingTab);
        horizonalReverseComBox->setObjectName(QStringLiteral("horizonalReverseComBox"));
        horizonalReverseComBox->setGeometry(QRect(250, 290, 130, 41));
        horizonalReverseComBox->setFont(font3);
        horizonalReverseComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        verticalReverseComBox = new QComboBox(settingTab);
        verticalReverseComBox->setObjectName(QStringLiteral("verticalReverseComBox"));
        verticalReverseComBox->setGeometry(QRect(250, 370, 130, 41));
        verticalReverseComBox->setFont(font3);
        verticalReverseComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printSetTabWid->addTab(settingTab, QString());
        settingBGLabel->raise();
        XDPILab->raise();
        XDPI100RadioBut->raise();
        XDPI150RadioBut->raise();
        XDPI200RadioBut->raise();
        XDPI300RadioBut->raise();
        repetePrintCheckBox->raise();
        repeteNumShowLab->raise();
        repeteNumAddBut->raise();
        repeteLab->raise();
        repeteNumRedBut->raise();
        repeteDelayRedBut->raise();
        repeteDelayShowLab->raise();
        repeteDelayAddBut->raise();
        repeteDelayLab->raise();
        YDPILab->raise();
        YDPI300RadioBut->raise();
        YDPI600RadioBut->raise();
        XDPI600RadioBut->raise();
        horizonalReverseLab->raise();
        verticalReverseLab->raise();
        horizonalReverseComBox->raise();
        verticalReverseComBox->raise();
        nozzleSetTab = new QWidget();
        nozzleSetTab->setObjectName(QStringLiteral("nozzleSetTab"));
        inkTypeLab = new QLabel(nozzleSetTab);
        inkTypeLab->setObjectName(QStringLiteral("inkTypeLab"));
        inkTypeLab->setGeometry(QRect(430, 60, 151, 41));
        inkTypeLab->setMinimumSize(QSize(101, 41));
        inkTypeLab->setFont(font);
        inkTypeLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        inkTypeLab->setAlignment(Qt::AlignCenter);
        adaptParaCheckBox = new QCheckBox(nozzleSetTab);
        adaptParaCheckBox->setObjectName(QStringLiteral("adaptParaCheckBox"));
        adaptParaCheckBox->setGeometry(QRect(80, 150, 221, 31));
        adaptParaCheckBox->setFont(font);
        adaptParaCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        adaptParaCheckBox->setChecked(false);
        adaptParaCheckBox->setAutoRepeat(false);
        voltShowLab = new QLabel(nozzleSetTab);
        voltShowLab->setObjectName(QStringLiteral("voltShowLab"));
        voltShowLab->setGeometry(QRect(440, 140, 131, 41));
        voltShowLab->setMinimumSize(QSize(0, 41));
        voltShowLab->setFont(font2);
        voltShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        voltShowLab->setAlignment(Qt::AlignCenter);
        voltAddBut = new QPushButton(nozzleSetTab);
        voltAddBut->setObjectName(QStringLiteral("voltAddBut"));
        voltAddBut->setGeometry(QRect(570, 140, 41, 41));
        voltAddBut->setMinimumSize(QSize(41, 41));
        voltAddBut->setFont(font1);
        voltAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        inkVoltLab = new QLabel(nozzleSetTab);
        inkVoltLab->setObjectName(QStringLiteral("inkVoltLab"));
        inkVoltLab->setGeometry(QRect(300, 140, 101, 41));
        inkVoltLab->setMinimumSize(QSize(101, 41));
        inkVoltLab->setFont(font);
        inkVoltLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        inkVoltLab->setAlignment(Qt::AlignCenter);
        voltRedBut = new QPushButton(nozzleSetTab);
        voltRedBut->setObjectName(QStringLiteral("voltRedBut"));
        voltRedBut->setGeometry(QRect(400, 140, 41, 41));
        voltRedBut->setMinimumSize(QSize(41, 41));
        voltRedBut->setFont(font1);
        voltRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        PWShowLab = new QLabel(nozzleSetTab);
        PWShowLab->setObjectName(QStringLiteral("PWShowLab"));
        PWShowLab->setGeometry(QRect(790, 140, 131, 41));
        PWShowLab->setMinimumSize(QSize(0, 41));
        PWShowLab->setFont(font2);
        PWShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        PWShowLab->setAlignment(Qt::AlignCenter);
        PWAddBut = new QPushButton(nozzleSetTab);
        PWAddBut->setObjectName(QStringLiteral("PWAddBut"));
        PWAddBut->setGeometry(QRect(920, 140, 41, 41));
        PWAddBut->setMinimumSize(QSize(41, 41));
        PWAddBut->setFont(font1);
        PWAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        PWLab = new QLabel(nozzleSetTab);
        PWLab->setObjectName(QStringLiteral("PWLab"));
        PWLab->setGeometry(QRect(650, 140, 101, 41));
        PWLab->setMinimumSize(QSize(101, 41));
        PWLab->setFont(font);
        PWLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        PWLab->setAlignment(Qt::AlignCenter);
        PWRedBut = new QPushButton(nozzleSetTab);
        PWRedBut->setObjectName(QStringLiteral("PWRedBut"));
        PWRedBut->setGeometry(QRect(750, 140, 41, 41));
        PWRedBut->setMinimumSize(QSize(41, 41));
        PWRedBut->setFont(font1);
        PWRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        nozzleSelLab = new QLabel(nozzleSetTab);
        nozzleSelLab->setObjectName(QStringLiteral("nozzleSelLab"));
        nozzleSelLab->setGeometry(QRect(410, 230, 191, 41));
        nozzleSelLab->setMinimumSize(QSize(101, 41));
        nozzleSelLab->setFont(font);
        nozzleSelLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        nozzleSelLab->setAlignment(Qt::AlignCenter);
        offsetRedBut = new QPushButton(nozzleSetTab);
        offsetRedBut->setObjectName(QStringLiteral("offsetRedBut"));
        offsetRedBut->setGeometry(QRect(750, 300, 41, 41));
        offsetRedBut->setMinimumSize(QSize(41, 41));
        offsetRedBut->setFont(font1);
        offsetRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        offsetShowLab = new QLabel(nozzleSetTab);
        offsetShowLab->setObjectName(QStringLiteral("offsetShowLab"));
        offsetShowLab->setGeometry(QRect(790, 300, 131, 41));
        offsetShowLab->setMinimumSize(QSize(0, 41));
        offsetShowLab->setFont(font2);
        offsetShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        offsetShowLab->setAlignment(Qt::AlignCenter);
        offsetAddBut = new QPushButton(nozzleSetTab);
        offsetAddBut->setObjectName(QStringLiteral("offsetAddBut"));
        offsetAddBut->setGeometry(QRect(920, 300, 41, 41));
        offsetAddBut->setMinimumSize(QSize(41, 41));
        offsetAddBut->setFont(font1);
        offsetAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        offsetLab = new QLabel(nozzleSetTab);
        offsetLab->setObjectName(QStringLiteral("offsetLab"));
        offsetLab->setGeometry(QRect(630, 300, 121, 41));
        offsetLab->setMinimumSize(QSize(101, 41));
        offsetLab->setFont(font);
        offsetLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        offsetLab->setAlignment(Qt::AlignCenter);
        nozzleSel2RadioBut = new QRadioButton(nozzleSetTab);
        nozzleSel2RadioBut->setObjectName(QStringLiteral("nozzleSel2RadioBut"));
        nozzleSel2RadioBut->setGeometry(QRect(470, 300, 81, 41));
        nozzleSel2RadioBut->setFont(font4);
        nozzleSel2RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        nozzleSel1RadioBut = new QRadioButton(nozzleSetTab);
        nozzleSel1RadioBut->setObjectName(QStringLiteral("nozzleSel1RadioBut"));
        nozzleSel1RadioBut->setGeometry(QRect(370, 300, 81, 41));
        nozzleSel1RadioBut->setFont(font4);
        nozzleSel1RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        flashSprayLab = new QLabel(nozzleSetTab);
        flashSprayLab->setObjectName(QStringLiteral("flashSprayLab"));
        flashSprayLab->setGeometry(QRect(410, 390, 191, 41));
        flashSprayLab->setMinimumSize(QSize(101, 41));
        flashSprayLab->setFont(font);
        flashSprayLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        flashSprayLab->setAlignment(Qt::AlignCenter);
        flashSprayCheckBox = new QCheckBox(nozzleSetTab);
        flashSprayCheckBox->setObjectName(QStringLiteral("flashSprayCheckBox"));
        flashSprayCheckBox->setGeometry(QRect(300, 460, 181, 40));
        flashSprayCheckBox->setFont(font);
        flashSprayCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        flashSprayCheckBox->setChecked(false);
        flashSprayCheckBox->setAutoRepeat(false);
        flashSprayInternalShowLab = new QLabel(nozzleSetTab);
        flashSprayInternalShowLab->setObjectName(QStringLiteral("flashSprayInternalShowLab"));
        flashSprayInternalShowLab->setGeometry(QRect(620, 460, 131, 41));
        flashSprayInternalShowLab->setMinimumSize(QSize(0, 41));
        flashSprayInternalShowLab->setFont(font2);
        flashSprayInternalShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        flashSprayInternalShowLab->setAlignment(Qt::AlignCenter);
        flashSprayInternalLab = new QLabel(nozzleSetTab);
        flashSprayInternalLab->setObjectName(QStringLiteral("flashSprayInternalLab"));
        flashSprayInternalLab->setGeometry(QRect(480, 460, 101, 41));
        flashSprayInternalLab->setMinimumSize(QSize(101, 41));
        flashSprayInternalLab->setFont(font);
        flashSprayInternalLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        flashSprayInternalLab->setAlignment(Qt::AlignCenter);
        flashSprayInternalRedBut = new QPushButton(nozzleSetTab);
        flashSprayInternalRedBut->setObjectName(QStringLiteral("flashSprayInternalRedBut"));
        flashSprayInternalRedBut->setGeometry(QRect(580, 460, 41, 41));
        flashSprayInternalRedBut->setMinimumSize(QSize(41, 41));
        flashSprayInternalRedBut->setFont(font1);
        flashSprayInternalRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        flashSprayInternalAddBut = new QPushButton(nozzleSetTab);
        flashSprayInternalAddBut->setObjectName(QStringLiteral("flashSprayInternalAddBut"));
        flashSprayInternalAddBut->setGeometry(QRect(750, 460, 41, 41));
        flashSprayInternalAddBut->setMinimumSize(QSize(41, 41));
        flashSprayInternalAddBut->setFont(font1);
        flashSprayInternalAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        isCombineCheckBox = new QCheckBox(nozzleSetTab);
        isCombineCheckBox->setObjectName(QStringLiteral("isCombineCheckBox"));
        isCombineCheckBox->setGeometry(QRect(120, 300, 181, 31));
        isCombineCheckBox->setFont(font);
        isCombineCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        isCombineCheckBox->setChecked(false);
        isCombineCheckBox->setAutoRepeat(false);
        printSetBGLabel = new QLabel(nozzleSetTab);
        printSetBGLabel->setObjectName(QStringLiteral("printSetBGLabel"));
        printSetBGLabel->setGeometry(QRect(0, 0, 1016, 571));
        printSetBGLabel->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        printSetTabWid->addTab(nozzleSetTab, QString());
        printSetBGLabel->raise();
        inkTypeLab->raise();
        adaptParaCheckBox->raise();
        voltShowLab->raise();
        voltAddBut->raise();
        inkVoltLab->raise();
        voltRedBut->raise();
        PWShowLab->raise();
        PWAddBut->raise();
        PWLab->raise();
        PWRedBut->raise();
        nozzleSelLab->raise();
        offsetRedBut->raise();
        offsetShowLab->raise();
        offsetAddBut->raise();
        offsetLab->raise();
        nozzleSel2RadioBut->raise();
        nozzleSel1RadioBut->raise();
        flashSprayLab->raise();
        flashSprayCheckBox->raise();
        flashSprayInternalShowLab->raise();
        flashSprayInternalLab->raise();
        flashSprayInternalRedBut->raise();
        flashSprayInternalAddBut->raise();
        isCombineCheckBox->raise();
        UVSettingTab = new QWidget();
        UVSettingTab->setObjectName(QStringLiteral("UVSettingTab"));
        UVSetBGLabel = new QLabel(UVSettingTab);
        UVSetBGLabel->setObjectName(QStringLiteral("UVSetBGLabel"));
        UVSetBGLabel->setGeometry(QRect(0, 0, 1016, 571));
        UVSetBGLabel->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        isUVCheckBox = new QCheckBox(UVSettingTab);
        isUVCheckBox->setObjectName(QStringLiteral("isUVCheckBox"));
        isUVCheckBox->setGeometry(QRect(300, 170, 201, 31));
        isUVCheckBox->setFont(font);
        isUVCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        isUVCheckBox->setChecked(false);
        isUVCheckBox->setAutoRepeat(false);
        startTimeAddBut = new QPushButton(UVSettingTab);
        startTimeAddBut->setObjectName(QStringLiteral("startTimeAddBut"));
        startTimeAddBut->setGeometry(QRect(860, 330, 41, 41));
        startTimeAddBut->setMinimumSize(QSize(41, 41));
        startTimeAddBut->setFont(font1);
        startTimeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        delayTimeRedBut = new QPushButton(UVSettingTab);
        delayTimeRedBut->setObjectName(QStringLiteral("delayTimeRedBut"));
        delayTimeRedBut->setGeometry(QRect(490, 240, 41, 41));
        delayTimeRedBut->setMinimumSize(QSize(41, 41));
        delayTimeRedBut->setFont(font1);
        delayTimeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        startTimeRedBut = new QPushButton(UVSettingTab);
        startTimeRedBut->setObjectName(QStringLiteral("startTimeRedBut"));
        startTimeRedBut->setGeometry(QRect(490, 330, 41, 41));
        startTimeRedBut->setMinimumSize(QSize(41, 41));
        startTimeRedBut->setFont(font1);
        startTimeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        delayTimeShowLab = new QLabel(UVSettingTab);
        delayTimeShowLab->setObjectName(QStringLiteral("delayTimeShowLab"));
        delayTimeShowLab->setGeometry(QRect(530, 240, 331, 41));
        delayTimeShowLab->setMinimumSize(QSize(0, 41));
        delayTimeShowLab->setFont(font2);
        delayTimeShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        delayTimeShowLab->setAlignment(Qt::AlignCenter);
        delayTimeAddBut = new QPushButton(UVSettingTab);
        delayTimeAddBut->setObjectName(QStringLiteral("delayTimeAddBut"));
        delayTimeAddBut->setGeometry(QRect(860, 240, 41, 41));
        delayTimeAddBut->setMinimumSize(QSize(41, 41));
        delayTimeAddBut->setFont(font1);
        delayTimeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        delayTimeLab = new QLabel(UVSettingTab);
        delayTimeLab->setObjectName(QStringLiteral("delayTimeLab"));
        delayTimeLab->setGeometry(QRect(300, 240, 191, 41));
        delayTimeLab->setMinimumSize(QSize(101, 41));
        delayTimeLab->setFont(font);
        delayTimeLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        delayTimeLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        startTimeShowLab = new QLabel(UVSettingTab);
        startTimeShowLab->setObjectName(QStringLiteral("startTimeShowLab"));
        startTimeShowLab->setGeometry(QRect(530, 330, 331, 41));
        startTimeShowLab->setMinimumSize(QSize(0, 41));
        startTimeShowLab->setFont(font2);
        startTimeShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        startTimeShowLab->setAlignment(Qt::AlignCenter);
        startTimeLab = new QLabel(UVSettingTab);
        startTimeLab->setObjectName(QStringLiteral("startTimeLab"));
        startTimeLab->setGeometry(QRect(300, 330, 191, 41));
        startTimeLab->setMinimumSize(QSize(101, 41));
        startTimeLab->setFont(font);
        startTimeLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        startTimeLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printSetTabWid->addTab(UVSettingTab, QString());

        retranslateUi(printSetting);

        printSetTabWid->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(printSetting);
    } // setupUi

    void retranslateUi(QWidget *printSetting)
    {
        printSetting->setWindowTitle(QApplication::translate("printSetting", "printSetting", 0));
        printSpeedRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        trigLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\247\246\345\217\221\346\226\271\345\274\217</span></p></body></html>", 0));
        printSpeedShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">85</span></p></body></html>", 0));
        printSpeedAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        printSpeedLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\351\200\237\345\272\246m/min</span></p></body></html>", 0));
        inkjetLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\226\267\345\242\250\346\226\271\345\274\217</span></p></body></html>", 0));
        printDirLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\346\226\271\345\220\221</span></p></body></html>", 0));
        printDelayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\345\273\266\350\277\237mm</span></p></body></html>", 0));
        printDelayRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        printDelayShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">20</span></p></body></html>", 0));
        printDelayAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        synFrequencyLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\220\214\346\255\245\345\200\215\351\242\221</span></p></body></html>", 0));
        synFrequencyRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        synFrequencyShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        synFrequencyAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        printGrayAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        printGrayShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        printGrayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\347\201\260\345\272\246</span></p></body></html>", 0));
        printGrayRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        synWheelCheckBox->setText(QApplication::translate("printSetting", "\345\220\257\347\224\250\345\220\214\346\255\245\350\275\256", 0));
        voiceCheckBox->setText(QApplication::translate("printSetting", "\345\243\260\351\237\263", 0));
        printStyleBGLabel->setText(QString());
        encoderResLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\274\226\347\240\201\345\231\250\345\210\206\350\276\250\347\216\207P/r</span></p></body></html>", 0));
        wheelDiameterLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\235\240\350\275\256\347\233\264\345\276\204</span>mm</p></body></html>", 0));
        pulseWidthLab->setText(QApplication::translate("printSetting", "<html><head/><body><p>\347\224\265\347\234\274\346\234\211\346\225\210\350\204\211\345\256\275<span style=\" font-family:'\347\255\211\347\272\277'; font-size:14pt;\">\316\274s</span></p></body></html>", 0));
        proLineSpeedLab->setText(QApplication::translate("printSetting", "<html><head/><body><p>\344\272\247\347\272\277\351\200\237\345\272\246m/min</p></body></html>", 0));
        proLineSpeedShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0.32</span></p></body></html>", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(printStyleTab), QApplication::translate("printSetting", "\345\237\272\347\241\200\350\256\276\347\275\256", 0));
        XDPILab->setText(QApplication::translate("printSetting", "<html><head/><body><p align=\"center\">X\346\226\271\345\220\221DPI</p></body></html>", 0));
        XDPI100RadioBut->setText(QApplication::translate("printSetting", "100", 0));
        XDPI150RadioBut->setText(QApplication::translate("printSetting", "150", 0));
        XDPI200RadioBut->setText(QApplication::translate("printSetting", "200", 0));
        XDPI300RadioBut->setText(QApplication::translate("printSetting", "300", 0));
        repetePrintCheckBox->setText(QApplication::translate("printSetting", "\351\207\215\345\244\215\346\211\223\345\215\260", 0));
        repeteNumShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        repeteNumAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        repeteLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\207\215\345\244\215\346\254\241\346\225\260</span></p></body></html>", 0));
        repeteNumRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        repeteDelayRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        repeteDelayShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">100</span></p></body></html>", 0));
        repeteDelayAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        repeteDelayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\207\215\345\244\215\345\273\266\346\227\266</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">ms</span></p></body></html>", 0));
        settingBGLabel->setText(QString());
        YDPILab->setText(QApplication::translate("printSetting", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; color:#ffffff;\">Y\346\226\271\345\220\221DPI</span></p></body></html>", 0));
        YDPI300RadioBut->setText(QApplication::translate("printSetting", "300", 0));
        YDPI600RadioBut->setText(QApplication::translate("printSetting", "600", 0));
        XDPI600RadioBut->setText(QApplication::translate("printSetting", "600", 0));
        horizonalReverseLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\267\246\345\217\263\347\277\273\350\275\254</span></p></body></html>", 0));
        verticalReverseLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\344\270\212\344\270\213\351\242\240\345\200\222</span></p></body></html>", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(settingTab), QApplication::translate("printSetting", "\351\253\230\347\272\247\350\256\276\347\275\256", 0));
        inkTypeLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\242\250\346\260\264\347\261\273\345\236\213</span></p></body></html>", 0));
        adaptParaCheckBox->setText(QApplication::translate("printSetting", "\350\207\252\351\200\202\345\272\224\345\217\202\346\225\260", 0));
        voltShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">8.5</span></p></body></html>", 0));
        voltAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        inkVoltLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\224\265\345\216\213</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">V</span></p></body></html>", 0));
        voltRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        PWShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1.8</span></p></body></html>", 0));
        PWAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        PWLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\204\211\345\256\275</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">ms</span></p></body></html>", 0));
        PWRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        nozzleSelLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\226\267\345\244\264\351\200\211\346\213\251</span></p></body></html>", 0));
        offsetRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        offsetShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        offsetAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        offsetLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\201\217\347\247\273\351\207\217</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">mm</span></p></body></html>", 0));
        nozzleSel2RadioBut->setText(QApplication::translate("printSetting", "2", 0));
        nozzleSel1RadioBut->setText(QApplication::translate("printSetting", "1", 0));
        flashSprayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\227\262\345\226\267\350\256\276\347\275\256</span></p></body></html>", 0));
        flashSprayCheckBox->setText(QApplication::translate("printSetting", "\351\227\262\345\226\267", 0));
        flashSprayInternalShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">5</span></p></body></html>", 0));
        flashSprayInternalLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\227\264\351\232\224</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">s</span></p></body></html>", 0));
        flashSprayInternalRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        flashSprayInternalAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        isCombineCheckBox->setText(QApplication::translate("printSetting", "\346\213\274\346\216\245", 0));
        printSetBGLabel->setText(QString());
        printSetTabWid->setTabText(printSetTabWid->indexOf(nozzleSetTab), QApplication::translate("printSetting", "\345\226\267\345\244\264\350\256\276\347\275\256", 0));
        UVSetBGLabel->setText(QString());
        isUVCheckBox->setText(QApplication::translate("printSetting", "\345\220\257\347\224\250\346\212\245\350\255\246\347\201\257", 0));
        startTimeAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        delayTimeRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        startTimeRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        delayTimeShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">500</span></p></body></html>", 0));
        delayTimeAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        delayTimeLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\273\266\351\225\277\346\227\266\351\227\264/ms</span></p></body></html>", 0));
        startTimeShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">500</span></p></body></html>", 0));
        startTimeLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\274\200\345\247\213\346\227\266\351\225\277/ms</span></p></body></html>", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(UVSettingTab), QApplication::translate("printSetting", "\346\212\245\350\255\246\347\201\257\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class printSetting: public Ui_printSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTSETTING_H
