/********************************************************************************
** Form generated from reading UI file 'countsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTSETTING_H
#define UI_COUNTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_countSetting
{
public:
    QLabel *counterOneLab;
    QLabel *currentVal1Lab;
    QPushButton *printTimeRedBut;
    QLabel *printTimeLab;
    QPushButton *printTimeAddBut;
    QLabel *printTimeShowLab;
    QPushButton *curValAdd1But;
    QPushButton *curValRed1But;
    QLabel *currentValShow1Lab;
    QLabel *stepValShow1Lab;
    QPushButton *stepAdd1But;
    QLabel *stepVal1Lab;
    QPushButton *stepRed1But;
    QPushButton *maxRed1But;
    QPushButton *initialAdd1But;
    QLabel *initialValShow1Lab;
    QLabel *initialVal1Lab;
    QPushButton *maxAdd1But;
    QLabel *maxVal1Lab;
    QPushButton *initialRed1But;
    QLabel *maxValShow1Lab;
    QPushButton *repeteRed1But;
    QPushButton *repeteAdd1But;
    QLabel *repeteTimeShow1Lab;
    QLabel *repeteTime1Lab;
    QLabel *repeteTime2Lab;
    QPushButton *initialAdd2But;
    QLabel *stepVal2Lab;
    QLabel *stepValShow2Lab;
    QPushButton *stepAdd2But;
    QLabel *currentVal2Lab;
    QPushButton *repeteAdd2But;
    QLabel *maxVal2Lab;
    QLabel *counterTwoLab;
    QPushButton *curValAdd2But;
    QLabel *initialValShow2Lab;
    QLabel *repeteTimeShow2Lab;
    QPushButton *curValRed2But;
    QLabel *initialVal2Lab;
    QPushButton *stepRed2But;
    QLabel *maxValShow2Lab;
    QLabel *currentValShow2Lab;
    QPushButton *initialRed2But;
    QPushButton *maxRed2But;
    QPushButton *repeteRed2But;
    QPushButton *maxAdd2But;

    void setupUi(QWidget *countSetting)
    {
        if (countSetting->objectName().isEmpty())
            countSetting->setObjectName(QStringLiteral("countSetting"));
        countSetting->resize(1061, 651);
        counterOneLab = new QLabel(countSetting);
        counterOneLab->setObjectName(QStringLiteral("counterOneLab"));
        counterOneLab->setGeometry(QRect(430, 20, 141, 41));
        counterOneLab->setMinimumSize(QSize(141, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        counterOneLab->setFont(font);
        counterOneLab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        counterOneLab->setAlignment(Qt::AlignCenter);
        currentVal1Lab = new QLabel(countSetting);
        currentVal1Lab->setObjectName(QStringLiteral("currentVal1Lab"));
        currentVal1Lab->setGeometry(QRect(60, 90, 141, 41));
        currentVal1Lab->setMinimumSize(QSize(141, 41));
        currentVal1Lab->setFont(font);
        currentVal1Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        currentVal1Lab->setAlignment(Qt::AlignCenter);
        printTimeRedBut = new QPushButton(countSetting);
        printTimeRedBut->setObjectName(QStringLiteral("printTimeRedBut"));
        printTimeRedBut->setGeometry(QRect(330, 600, 41, 41));
        printTimeRedBut->setMinimumSize(QSize(41, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        printTimeRedBut->setFont(font1);
        printTimeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printTimeLab = new QLabel(countSetting);
        printTimeLab->setObjectName(QStringLiteral("printTimeLab"));
        printTimeLab->setGeometry(QRect(120, 600, 191, 41));
        printTimeLab->setMinimumSize(QSize(141, 41));
        printTimeLab->setFont(font);
        printTimeLab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        printTimeLab->setAlignment(Qt::AlignCenter);
        printTimeAddBut = new QPushButton(countSetting);
        printTimeAddBut->setObjectName(QStringLiteral("printTimeAddBut"));
        printTimeAddBut->setGeometry(QRect(840, 600, 41, 41));
        printTimeAddBut->setMinimumSize(QSize(41, 41));
        printTimeAddBut->setFont(font1);
        printTimeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printTimeShowLab = new QLabel(countSetting);
        printTimeShowLab->setObjectName(QStringLiteral("printTimeShowLab"));
        printTimeShowLab->setGeometry(QRect(380, 600, 451, 41));
        printTimeShowLab->setMinimumSize(QSize(451, 41));
        printTimeShowLab->setFont(font);
        printTimeShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        printTimeShowLab->setAlignment(Qt::AlignCenter);
        curValAdd1But = new QPushButton(countSetting);
        curValAdd1But->setObjectName(QStringLiteral("curValAdd1But"));
        curValAdd1But->setGeometry(QRect(460, 90, 41, 41));
        curValAdd1But->setMinimumSize(QSize(41, 41));
        curValAdd1But->setFont(font1);
        curValAdd1But->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);"));
        curValRed1But = new QPushButton(countSetting);
        curValRed1But->setObjectName(QStringLiteral("curValRed1But"));
        curValRed1But->setGeometry(QRect(200, 90, 41, 41));
        curValRed1But->setMinimumSize(QSize(41, 41));
        curValRed1But->setFont(font1);
        curValRed1But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        currentValShow1Lab = new QLabel(countSetting);
        currentValShow1Lab->setObjectName(QStringLiteral("currentValShow1Lab"));
        currentValShow1Lab->setGeometry(QRect(250, 90, 201, 41));
        currentValShow1Lab->setMinimumSize(QSize(0, 41));
        currentValShow1Lab->setFont(font);
        currentValShow1Lab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        currentValShow1Lab->setAlignment(Qt::AlignCenter);
        stepValShow1Lab = new QLabel(countSetting);
        stepValShow1Lab->setObjectName(QStringLiteral("stepValShow1Lab"));
        stepValShow1Lab->setGeometry(QRect(760, 90, 201, 41));
        stepValShow1Lab->setMinimumSize(QSize(0, 41));
        stepValShow1Lab->setFont(font);
        stepValShow1Lab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        stepValShow1Lab->setAlignment(Qt::AlignCenter);
        stepAdd1But = new QPushButton(countSetting);
        stepAdd1But->setObjectName(QStringLiteral("stepAdd1But"));
        stepAdd1But->setGeometry(QRect(970, 90, 41, 41));
        stepAdd1But->setMinimumSize(QSize(41, 41));
        stepAdd1But->setFont(font1);
        stepAdd1But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        stepVal1Lab = new QLabel(countSetting);
        stepVal1Lab->setObjectName(QStringLiteral("stepVal1Lab"));
        stepVal1Lab->setGeometry(QRect(570, 90, 141, 41));
        stepVal1Lab->setMinimumSize(QSize(141, 41));
        stepVal1Lab->setFont(font);
        stepVal1Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        stepVal1Lab->setAlignment(Qt::AlignCenter);
        stepRed1But = new QPushButton(countSetting);
        stepRed1But->setObjectName(QStringLiteral("stepRed1But"));
        stepRed1But->setGeometry(QRect(710, 90, 41, 41));
        stepRed1But->setMinimumSize(QSize(41, 41));
        stepRed1But->setFont(font1);
        stepRed1But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        maxRed1But = new QPushButton(countSetting);
        maxRed1But->setObjectName(QStringLiteral("maxRed1But"));
        maxRed1But->setGeometry(QRect(710, 160, 41, 41));
        maxRed1But->setMinimumSize(QSize(41, 41));
        maxRed1But->setFont(font1);
        maxRed1But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        initialAdd1But = new QPushButton(countSetting);
        initialAdd1But->setObjectName(QStringLiteral("initialAdd1But"));
        initialAdd1But->setGeometry(QRect(460, 160, 41, 41));
        initialAdd1But->setMinimumSize(QSize(41, 41));
        initialAdd1But->setFont(font1);
        initialAdd1But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        initialValShow1Lab = new QLabel(countSetting);
        initialValShow1Lab->setObjectName(QStringLiteral("initialValShow1Lab"));
        initialValShow1Lab->setGeometry(QRect(250, 160, 201, 41));
        initialValShow1Lab->setMinimumSize(QSize(0, 41));
        initialValShow1Lab->setFont(font);
        initialValShow1Lab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        initialValShow1Lab->setAlignment(Qt::AlignCenter);
        initialVal1Lab = new QLabel(countSetting);
        initialVal1Lab->setObjectName(QStringLiteral("initialVal1Lab"));
        initialVal1Lab->setGeometry(QRect(60, 160, 141, 41));
        initialVal1Lab->setMinimumSize(QSize(141, 41));
        initialVal1Lab->setFont(font);
        initialVal1Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        initialVal1Lab->setAlignment(Qt::AlignCenter);
        maxAdd1But = new QPushButton(countSetting);
        maxAdd1But->setObjectName(QStringLiteral("maxAdd1But"));
        maxAdd1But->setGeometry(QRect(970, 160, 41, 41));
        maxAdd1But->setMinimumSize(QSize(41, 41));
        maxAdd1But->setFont(font1);
        maxAdd1But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        maxVal1Lab = new QLabel(countSetting);
        maxVal1Lab->setObjectName(QStringLiteral("maxVal1Lab"));
        maxVal1Lab->setGeometry(QRect(570, 160, 141, 41));
        maxVal1Lab->setMinimumSize(QSize(141, 41));
        maxVal1Lab->setFont(font);
        maxVal1Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        maxVal1Lab->setAlignment(Qt::AlignCenter);
        initialRed1But = new QPushButton(countSetting);
        initialRed1But->setObjectName(QStringLiteral("initialRed1But"));
        initialRed1But->setGeometry(QRect(200, 160, 41, 41));
        initialRed1But->setMinimumSize(QSize(41, 41));
        initialRed1But->setFont(font1);
        initialRed1But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        maxValShow1Lab = new QLabel(countSetting);
        maxValShow1Lab->setObjectName(QStringLiteral("maxValShow1Lab"));
        maxValShow1Lab->setGeometry(QRect(760, 160, 201, 41));
        maxValShow1Lab->setMinimumSize(QSize(0, 41));
        maxValShow1Lab->setFont(font);
        maxValShow1Lab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        maxValShow1Lab->setAlignment(Qt::AlignCenter);
        repeteRed1But = new QPushButton(countSetting);
        repeteRed1But->setObjectName(QStringLiteral("repeteRed1But"));
        repeteRed1But->setGeometry(QRect(200, 230, 41, 41));
        repeteRed1But->setMinimumSize(QSize(41, 41));
        repeteRed1But->setFont(font1);
        repeteRed1But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        repeteAdd1But = new QPushButton(countSetting);
        repeteAdd1But->setObjectName(QStringLiteral("repeteAdd1But"));
        repeteAdd1But->setGeometry(QRect(460, 230, 41, 41));
        repeteAdd1But->setMinimumSize(QSize(41, 41));
        repeteAdd1But->setFont(font1);
        repeteAdd1But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        repeteTimeShow1Lab = new QLabel(countSetting);
        repeteTimeShow1Lab->setObjectName(QStringLiteral("repeteTimeShow1Lab"));
        repeteTimeShow1Lab->setGeometry(QRect(250, 230, 201, 41));
        repeteTimeShow1Lab->setMinimumSize(QSize(0, 41));
        repeteTimeShow1Lab->setFont(font);
        repeteTimeShow1Lab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        repeteTimeShow1Lab->setAlignment(Qt::AlignCenter);
        repeteTime1Lab = new QLabel(countSetting);
        repeteTime1Lab->setObjectName(QStringLiteral("repeteTime1Lab"));
        repeteTime1Lab->setGeometry(QRect(0, 230, 201, 41));
        repeteTime1Lab->setMinimumSize(QSize(141, 41));
        repeteTime1Lab->setFont(font);
        repeteTime1Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        repeteTime1Lab->setAlignment(Qt::AlignCenter);
        repeteTime2Lab = new QLabel(countSetting);
        repeteTime2Lab->setObjectName(QStringLiteral("repeteTime2Lab"));
        repeteTime2Lab->setGeometry(QRect(0, 520, 201, 41));
        repeteTime2Lab->setMinimumSize(QSize(141, 41));
        repeteTime2Lab->setFont(font);
        repeteTime2Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        repeteTime2Lab->setAlignment(Qt::AlignCenter);
        initialAdd2But = new QPushButton(countSetting);
        initialAdd2But->setObjectName(QStringLiteral("initialAdd2But"));
        initialAdd2But->setGeometry(QRect(460, 450, 41, 41));
        initialAdd2But->setMinimumSize(QSize(41, 41));
        initialAdd2But->setFont(font1);
        initialAdd2But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        stepVal2Lab = new QLabel(countSetting);
        stepVal2Lab->setObjectName(QStringLiteral("stepVal2Lab"));
        stepVal2Lab->setGeometry(QRect(570, 380, 141, 41));
        stepVal2Lab->setMinimumSize(QSize(141, 41));
        stepVal2Lab->setFont(font);
        stepVal2Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        stepVal2Lab->setAlignment(Qt::AlignCenter);
        stepValShow2Lab = new QLabel(countSetting);
        stepValShow2Lab->setObjectName(QStringLiteral("stepValShow2Lab"));
        stepValShow2Lab->setGeometry(QRect(760, 380, 201, 41));
        stepValShow2Lab->setMinimumSize(QSize(0, 41));
        stepValShow2Lab->setFont(font);
        stepValShow2Lab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        stepValShow2Lab->setAlignment(Qt::AlignCenter);
        stepAdd2But = new QPushButton(countSetting);
        stepAdd2But->setObjectName(QStringLiteral("stepAdd2But"));
        stepAdd2But->setGeometry(QRect(970, 380, 41, 41));
        stepAdd2But->setMinimumSize(QSize(41, 41));
        stepAdd2But->setFont(font1);
        stepAdd2But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        currentVal2Lab = new QLabel(countSetting);
        currentVal2Lab->setObjectName(QStringLiteral("currentVal2Lab"));
        currentVal2Lab->setGeometry(QRect(60, 380, 141, 41));
        currentVal2Lab->setMinimumSize(QSize(141, 41));
        currentVal2Lab->setFont(font);
        currentVal2Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        currentVal2Lab->setAlignment(Qt::AlignCenter);
        repeteAdd2But = new QPushButton(countSetting);
        repeteAdd2But->setObjectName(QStringLiteral("repeteAdd2But"));
        repeteAdd2But->setGeometry(QRect(460, 520, 41, 41));
        repeteAdd2But->setMinimumSize(QSize(41, 41));
        repeteAdd2But->setFont(font1);
        repeteAdd2But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        maxVal2Lab = new QLabel(countSetting);
        maxVal2Lab->setObjectName(QStringLiteral("maxVal2Lab"));
        maxVal2Lab->setGeometry(QRect(570, 450, 141, 41));
        maxVal2Lab->setMinimumSize(QSize(141, 41));
        maxVal2Lab->setFont(font);
        maxVal2Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        maxVal2Lab->setAlignment(Qt::AlignCenter);
        counterTwoLab = new QLabel(countSetting);
        counterTwoLab->setObjectName(QStringLiteral("counterTwoLab"));
        counterTwoLab->setGeometry(QRect(430, 310, 141, 41));
        counterTwoLab->setMinimumSize(QSize(141, 41));
        counterTwoLab->setFont(font);
        counterTwoLab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        counterTwoLab->setAlignment(Qt::AlignCenter);
        curValAdd2But = new QPushButton(countSetting);
        curValAdd2But->setObjectName(QStringLiteral("curValAdd2But"));
        curValAdd2But->setGeometry(QRect(460, 380, 41, 41));
        curValAdd2But->setMinimumSize(QSize(41, 41));
        curValAdd2But->setFont(font1);
        curValAdd2But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        initialValShow2Lab = new QLabel(countSetting);
        initialValShow2Lab->setObjectName(QStringLiteral("initialValShow2Lab"));
        initialValShow2Lab->setGeometry(QRect(250, 450, 201, 41));
        initialValShow2Lab->setMinimumSize(QSize(0, 41));
        initialValShow2Lab->setFont(font);
        initialValShow2Lab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        initialValShow2Lab->setAlignment(Qt::AlignCenter);
        repeteTimeShow2Lab = new QLabel(countSetting);
        repeteTimeShow2Lab->setObjectName(QStringLiteral("repeteTimeShow2Lab"));
        repeteTimeShow2Lab->setGeometry(QRect(250, 520, 201, 41));
        repeteTimeShow2Lab->setMinimumSize(QSize(0, 41));
        repeteTimeShow2Lab->setFont(font);
        repeteTimeShow2Lab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        repeteTimeShow2Lab->setAlignment(Qt::AlignCenter);
        curValRed2But = new QPushButton(countSetting);
        curValRed2But->setObjectName(QStringLiteral("curValRed2But"));
        curValRed2But->setGeometry(QRect(200, 380, 41, 41));
        curValRed2But->setMinimumSize(QSize(41, 41));
        curValRed2But->setFont(font1);
        curValRed2But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        initialVal2Lab = new QLabel(countSetting);
        initialVal2Lab->setObjectName(QStringLiteral("initialVal2Lab"));
        initialVal2Lab->setGeometry(QRect(60, 450, 141, 41));
        initialVal2Lab->setMinimumSize(QSize(141, 41));
        initialVal2Lab->setFont(font);
        initialVal2Lab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        initialVal2Lab->setAlignment(Qt::AlignCenter);
        stepRed2But = new QPushButton(countSetting);
        stepRed2But->setObjectName(QStringLiteral("stepRed2But"));
        stepRed2But->setGeometry(QRect(710, 380, 41, 41));
        stepRed2But->setMinimumSize(QSize(41, 41));
        stepRed2But->setFont(font1);
        stepRed2But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        maxValShow2Lab = new QLabel(countSetting);
        maxValShow2Lab->setObjectName(QStringLiteral("maxValShow2Lab"));
        maxValShow2Lab->setGeometry(QRect(760, 450, 201, 41));
        maxValShow2Lab->setMinimumSize(QSize(0, 41));
        maxValShow2Lab->setFont(font);
        maxValShow2Lab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        maxValShow2Lab->setAlignment(Qt::AlignCenter);
        currentValShow2Lab = new QLabel(countSetting);
        currentValShow2Lab->setObjectName(QStringLiteral("currentValShow2Lab"));
        currentValShow2Lab->setGeometry(QRect(250, 380, 201, 41));
        currentValShow2Lab->setMinimumSize(QSize(0, 41));
        currentValShow2Lab->setFont(font);
        currentValShow2Lab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        currentValShow2Lab->setAlignment(Qt::AlignCenter);
        initialRed2But = new QPushButton(countSetting);
        initialRed2But->setObjectName(QStringLiteral("initialRed2But"));
        initialRed2But->setGeometry(QRect(200, 450, 41, 41));
        initialRed2But->setMinimumSize(QSize(41, 41));
        initialRed2But->setFont(font1);
        initialRed2But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        maxRed2But = new QPushButton(countSetting);
        maxRed2But->setObjectName(QStringLiteral("maxRed2But"));
        maxRed2But->setGeometry(QRect(710, 450, 41, 41));
        maxRed2But->setMinimumSize(QSize(41, 41));
        maxRed2But->setFont(font1);
        maxRed2But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteRed2But = new QPushButton(countSetting);
        repeteRed2But->setObjectName(QStringLiteral("repeteRed2But"));
        repeteRed2But->setGeometry(QRect(200, 520, 41, 41));
        repeteRed2But->setMinimumSize(QSize(41, 41));
        repeteRed2But->setFont(font1);
        repeteRed2But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 255);"));
        maxAdd2But = new QPushButton(countSetting);
        maxAdd2But->setObjectName(QStringLiteral("maxAdd2But"));
        maxAdd2But->setGeometry(QRect(970, 450, 41, 41));
        maxAdd2But->setMinimumSize(QSize(41, 41));
        maxAdd2But->setFont(font1);
        maxAdd2But->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));

        retranslateUi(countSetting);

        QMetaObject::connectSlotsByName(countSetting);
    } // setupUi

    void retranslateUi(QWidget *countSetting)
    {
        countSetting->setWindowTitle(QApplication::translate("countSetting", "countSetting", 0));
        counterOneLab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\256\241\346\225\260\345\231\2501</span></p></body></html>", 0));
        currentVal1Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\275\223\345\211\215\345\200\274</span></p></body></html>", 0));
        printTimeRedBut->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        printTimeLab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\346\254\241\346\225\260</span></p></body></html>", 0));
        printTimeAddBut->setText(QApplication::translate("countSetting", "\357\274\213", 0));
        printTimeShowLab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        curValAdd1But->setText(QApplication::translate("countSetting", "\357\274\213", 0));
        curValRed1But->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        currentValShow1Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        stepValShow1Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        stepAdd1But->setText(QApplication::translate("countSetting", "\357\274\213", 0));
        stepVal1Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\255\245\350\277\233\345\200\274</span></p></body></html>", 0));
        stepRed1But->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        maxRed1But->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        initialAdd1But->setText(QApplication::translate("countSetting", "\357\274\213", 0));
        initialValShow1Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        initialVal1Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\210\235\345\247\213\345\200\274</span></p></body></html>", 0));
        maxAdd1But->setText(QApplication::translate("countSetting", "\357\274\213", 0));
        maxVal1Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\234\200\345\244\247\345\200\274</span></p></body></html>", 0));
        initialRed1But->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        maxValShow1Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">999999</span></p></body></html>", 0));
        repeteRed1But->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        repeteAdd1But->setText(QApplication::translate("countSetting", "\357\274\213", 0));
        repeteTimeShow1Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        repeteTime1Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\207\215\345\244\215\346\254\241\346\225\260</span></p></body></html>", 0));
        repeteTime2Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\207\215\345\244\215\346\254\241\346\225\260</span></p></body></html>", 0));
        initialAdd2But->setText(QApplication::translate("countSetting", "\357\274\213", 0));
        stepVal2Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\255\245\350\277\233\345\200\274</span></p></body></html>", 0));
        stepValShow2Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        stepAdd2But->setText(QApplication::translate("countSetting", "\357\274\213", 0));
        currentVal2Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\275\223\345\211\215\345\200\274</span></p></body></html>", 0));
        repeteAdd2But->setText(QApplication::translate("countSetting", "\357\274\213", 0));
        maxVal2Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\234\200\345\244\247\345\200\274</span></p></body></html>", 0));
        counterTwoLab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\256\241\346\225\260\345\231\2502</span></p></body></html>", 0));
        curValAdd2But->setText(QApplication::translate("countSetting", "\357\274\213", 0));
        initialValShow2Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        repeteTimeShow2Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        curValRed2But->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        initialVal2Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\210\235\345\247\213\345\200\274</span></p></body></html>", 0));
        stepRed2But->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        maxValShow2Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">999999</span></p></body></html>", 0));
        currentValShow2Lab->setText(QApplication::translate("countSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        initialRed2But->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        maxRed2But->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        repeteRed2But->setText(QApplication::translate("countSetting", "\357\274\215", 0));
        maxAdd2But->setText(QApplication::translate("countSetting", "\357\274\213", 0));
    } // retranslateUi

};

namespace Ui {
    class countSetting: public Ui_countSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTSETTING_H
