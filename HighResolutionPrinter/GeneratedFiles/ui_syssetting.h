/********************************************************************************
** Form generated from reading UI file 'syssetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSSETTING_H
#define UI_SYSSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sysSetting
{
public:
    QTabWidget *sysSetTabWid;
    QWidget *sysSetTab;
    QLabel *sysParaSetBGLabel;
    QLabel *dayShowLab;
    QPushButton *reduceYearBut;
    QPushButton *addHourBut;
    QPushButton *addMinBut;
    QLabel *sysMonthTextLab;
    QPushButton *reduceMinBut;
    QSlider *lightHorSlider;
    QPushButton *addSecondBut;
    QPushButton *reduceDayBut;
    QLabel *sysDateTextLab;
    QLabel *backLightLab;
    QLabel *sysDayTextLab;
    QLabel *monthShowLab;
    QLabel *secondShowLab;
    QPushButton *addDayBut;
    QListWidget *sysLanguageListWid;
    QPushButton *addYearBut;
    QPushButton *reduceSecondBut;
    QPushButton *addMonthBut;
    QPushButton *reduceHourBut;
    QLabel *sysLanguageLab;
    QLabel *minShowLab;
    QPushButton *reduceMonthBut;
    QLabel *hourShowLab;
    QLabel *sysTimeTextLab;
    QLabel *yearShowLab;
    QLabel *sysTimeSignal2;
    QLabel *sysTimeSetLab;
    QLabel *sysTimeSignal1;
    QLabel *sysYearTextLab;
    QWidget *userManageTab;
    QLabel *userManageBGLabel;

    void setupUi(QWidget *sysSetting)
    {
        if (sysSetting->objectName().isEmpty())
            sysSetting->setObjectName(QStringLiteral("sysSetting"));
        sysSetting->resize(926, 600);
        sysSetting->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        sysSetTabWid = new QTabWidget(sysSetting);
        sysSetTabWid->setObjectName(QStringLiteral("sysSetTabWid"));
        sysSetTabWid->setGeometry(QRect(0, 10, 926, 591));
        sysSetTabWid->setMaximumSize(QSize(1021, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        sysSetTabWid->setFont(font);
        sysSetTabWid->setStyleSheet(QLatin1String("QTabBar::tab{width:255}\n"
"QTabBar::tab{height:50}\n"
""));
        sysSetTab = new QWidget();
        sysSetTab->setObjectName(QStringLiteral("sysSetTab"));
        sysParaSetBGLabel = new QLabel(sysSetTab);
        sysParaSetBGLabel->setObjectName(QStringLiteral("sysParaSetBGLabel"));
        sysParaSetBGLabel->setGeometry(QRect(0, 0, 926, 560));
        sysParaSetBGLabel->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        dayShowLab = new QLabel(sysSetTab);
        dayShowLab->setObjectName(QStringLiteral("dayShowLab"));
        dayShowLab->setGeometry(QRect(380, 130, 63, 51));
        dayShowLab->setMinimumSize(QSize(63, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        dayShowLab->setFont(font1);
        dayShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        dayShowLab->setAlignment(Qt::AlignCenter);
        reduceYearBut = new QPushButton(sysSetTab);
        reduceYearBut->setObjectName(QStringLiteral("reduceYearBut"));
        reduceYearBut->setGeometry(QRect(140, 180, 63, 63));
        reduceYearBut->setMinimumSize(QSize(51, 51));
        reduceYearBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        addHourBut = new QPushButton(sysSetTab);
        addHourBut->setObjectName(QStringLiteral("addHourBut"));
        addHourBut->setGeometry(QRect(140, 250, 63, 63));
        addHourBut->setMinimumSize(QSize(51, 51));
        addHourBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        addMinBut = new QPushButton(sysSetTab);
        addMinBut->setObjectName(QStringLiteral("addMinBut"));
        addMinBut->setGeometry(QRect(260, 250, 63, 63));
        addMinBut->setMinimumSize(QSize(51, 51));
        addMinBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        sysMonthTextLab = new QLabel(sysSetTab);
        sysMonthTextLab->setObjectName(QStringLiteral("sysMonthTextLab"));
        sysMonthTextLab->setGeometry(QRect(320, 130, 61, 51));
        sysMonthTextLab->setFont(font);
        sysMonthTextLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        sysMonthTextLab->setAlignment(Qt::AlignCenter);
        reduceMinBut = new QPushButton(sysSetTab);
        reduceMinBut->setObjectName(QStringLiteral("reduceMinBut"));
        reduceMinBut->setGeometry(QRect(260, 360, 63, 63));
        reduceMinBut->setMinimumSize(QSize(51, 51));
        reduceMinBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        lightHorSlider = new QSlider(sysSetTab);
        lightHorSlider->setObjectName(QStringLiteral("lightHorSlider"));
        lightHorSlider->setGeometry(QRect(620, 380, 231, 41));
        lightHorSlider->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        lightHorSlider->setOrientation(Qt::Horizontal);
        addSecondBut = new QPushButton(sysSetTab);
        addSecondBut->setObjectName(QStringLiteral("addSecondBut"));
        addSecondBut->setGeometry(QRect(380, 250, 63, 63));
        addSecondBut->setMinimumSize(QSize(51, 51));
        addSecondBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        reduceDayBut = new QPushButton(sysSetTab);
        reduceDayBut->setObjectName(QStringLiteral("reduceDayBut"));
        reduceDayBut->setGeometry(QRect(380, 180, 63, 63));
        reduceDayBut->setMinimumSize(QSize(51, 51));
        reduceDayBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        sysDateTextLab = new QLabel(sysSetTab);
        sysDateTextLab->setObjectName(QStringLiteral("sysDateTextLab"));
        sysDateTextLab->setGeometry(QRect(40, 130, 91, 51));
        sysDateTextLab->setFont(font);
        sysDateTextLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        sysDateTextLab->setAlignment(Qt::AlignCenter);
        backLightLab = new QLabel(sysSetTab);
        backLightLab->setObjectName(QStringLiteral("backLightLab"));
        backLightLab->setGeometry(QRect(490, 380, 131, 41));
        backLightLab->setFont(font);
        backLightLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        backLightLab->setAlignment(Qt::AlignCenter);
        sysDayTextLab = new QLabel(sysSetTab);
        sysDayTextLab->setObjectName(QStringLiteral("sysDayTextLab"));
        sysDayTextLab->setGeometry(QRect(440, 130, 61, 51));
        sysDayTextLab->setFont(font);
        sysDayTextLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        sysDayTextLab->setAlignment(Qt::AlignCenter);
        monthShowLab = new QLabel(sysSetTab);
        monthShowLab->setObjectName(QStringLiteral("monthShowLab"));
        monthShowLab->setGeometry(QRect(260, 130, 63, 51));
        monthShowLab->setMinimumSize(QSize(63, 51));
        monthShowLab->setFont(font1);
        monthShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        monthShowLab->setAlignment(Qt::AlignCenter);
        secondShowLab = new QLabel(sysSetTab);
        secondShowLab->setObjectName(QStringLiteral("secondShowLab"));
        secondShowLab->setGeometry(QRect(380, 310, 63, 51));
        secondShowLab->setMinimumSize(QSize(63, 51));
        secondShowLab->setFont(font1);
        secondShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        secondShowLab->setAlignment(Qt::AlignCenter);
        addDayBut = new QPushButton(sysSetTab);
        addDayBut->setObjectName(QStringLiteral("addDayBut"));
        addDayBut->setGeometry(QRect(380, 70, 63, 63));
        addDayBut->setMinimumSize(QSize(51, 51));
        addDayBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        sysLanguageListWid = new QListWidget(sysSetTab);
        sysLanguageListWid->setObjectName(QStringLiteral("sysLanguageListWid"));
        sysLanguageListWid->setGeometry(QRect(550, 70, 290, 301));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(14);
        sysLanguageListWid->setFont(font2);
        sysLanguageListWid->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        addYearBut = new QPushButton(sysSetTab);
        addYearBut->setObjectName(QStringLiteral("addYearBut"));
        addYearBut->setGeometry(QRect(140, 70, 61, 61));
        addYearBut->setMinimumSize(QSize(51, 51));
        addYearBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:5px;"));
        reduceSecondBut = new QPushButton(sysSetTab);
        reduceSecondBut->setObjectName(QStringLiteral("reduceSecondBut"));
        reduceSecondBut->setGeometry(QRect(380, 360, 63, 63));
        reduceSecondBut->setMinimumSize(QSize(51, 51));
        reduceSecondBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        addMonthBut = new QPushButton(sysSetTab);
        addMonthBut->setObjectName(QStringLiteral("addMonthBut"));
        addMonthBut->setGeometry(QRect(260, 70, 63, 63));
        addMonthBut->setMinimumSize(QSize(51, 51));
        addMonthBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        reduceHourBut = new QPushButton(sysSetTab);
        reduceHourBut->setObjectName(QStringLiteral("reduceHourBut"));
        reduceHourBut->setGeometry(QRect(140, 360, 63, 63));
        reduceHourBut->setMinimumSize(QSize(51, 51));
        reduceHourBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        sysLanguageLab = new QLabel(sysSetTab);
        sysLanguageLab->setObjectName(QStringLiteral("sysLanguageLab"));
        sysLanguageLab->setGeometry(QRect(600, 20, 191, 41));
        sysLanguageLab->setMinimumSize(QSize(141, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(18);
        sysLanguageLab->setFont(font3);
        sysLanguageLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        sysLanguageLab->setAlignment(Qt::AlignCenter);
        minShowLab = new QLabel(sysSetTab);
        minShowLab->setObjectName(QStringLiteral("minShowLab"));
        minShowLab->setGeometry(QRect(260, 310, 63, 51));
        minShowLab->setMinimumSize(QSize(63, 51));
        minShowLab->setFont(font1);
        minShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        minShowLab->setAlignment(Qt::AlignCenter);
        reduceMonthBut = new QPushButton(sysSetTab);
        reduceMonthBut->setObjectName(QStringLiteral("reduceMonthBut"));
        reduceMonthBut->setGeometry(QRect(260, 180, 63, 63));
        reduceMonthBut->setMinimumSize(QSize(51, 51));
        reduceMonthBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        hourShowLab = new QLabel(sysSetTab);
        hourShowLab->setObjectName(QStringLiteral("hourShowLab"));
        hourShowLab->setGeometry(QRect(140, 310, 63, 51));
        hourShowLab->setMinimumSize(QSize(63, 51));
        hourShowLab->setFont(font1);
        hourShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        hourShowLab->setAlignment(Qt::AlignCenter);
        sysTimeTextLab = new QLabel(sysSetTab);
        sysTimeTextLab->setObjectName(QStringLiteral("sysTimeTextLab"));
        sysTimeTextLab->setGeometry(QRect(50, 310, 91, 51));
        sysTimeTextLab->setMinimumSize(QSize(91, 41));
        sysTimeTextLab->setFont(font);
        sysTimeTextLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        sysTimeTextLab->setAlignment(Qt::AlignCenter);
        yearShowLab = new QLabel(sysSetTab);
        yearShowLab->setObjectName(QStringLiteral("yearShowLab"));
        yearShowLab->setGeometry(QRect(140, 130, 63, 51));
        yearShowLab->setMinimumSize(QSize(63, 51));
        yearShowLab->setFont(font1);
        yearShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        yearShowLab->setAlignment(Qt::AlignCenter);
        sysTimeSignal2 = new QLabel(sysSetTab);
        sysTimeSignal2->setObjectName(QStringLiteral("sysTimeSignal2"));
        sysTimeSignal2->setGeometry(QRect(320, 310, 61, 51));
        sysTimeSignal2->setFont(font);
        sysTimeSignal2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        sysTimeSignal2->setAlignment(Qt::AlignCenter);
        sysTimeSetLab = new QLabel(sysSetTab);
        sysTimeSetLab->setObjectName(QStringLiteral("sysTimeSetLab"));
        sysTimeSetLab->setGeometry(QRect(220, 20, 141, 41));
        sysTimeSetLab->setMinimumSize(QSize(141, 41));
        sysTimeSetLab->setFont(font3);
        sysTimeSetLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        sysTimeSetLab->setAlignment(Qt::AlignCenter);
        sysTimeSignal1 = new QLabel(sysSetTab);
        sysTimeSignal1->setObjectName(QStringLiteral("sysTimeSignal1"));
        sysTimeSignal1->setGeometry(QRect(200, 310, 61, 51));
        sysTimeSignal1->setFont(font);
        sysTimeSignal1->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        sysTimeSignal1->setAlignment(Qt::AlignCenter);
        sysYearTextLab = new QLabel(sysSetTab);
        sysYearTextLab->setObjectName(QStringLiteral("sysYearTextLab"));
        sysYearTextLab->setGeometry(QRect(200, 130, 61, 51));
        sysYearTextLab->setFont(font);
        sysYearTextLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        sysYearTextLab->setAlignment(Qt::AlignCenter);
        sysSetTabWid->addTab(sysSetTab, QString());
        sysParaSetBGLabel->raise();
        dayShowLab->raise();
        sysMonthTextLab->raise();
        lightHorSlider->raise();
        reduceDayBut->raise();
        sysDateTextLab->raise();
        backLightLab->raise();
        sysDayTextLab->raise();
        monthShowLab->raise();
        secondShowLab->raise();
        addDayBut->raise();
        reduceSecondBut->raise();
        sysLanguageLab->raise();
        minShowLab->raise();
        hourShowLab->raise();
        sysTimeTextLab->raise();
        yearShowLab->raise();
        sysTimeSignal2->raise();
        sysTimeSetLab->raise();
        sysTimeSignal1->raise();
        sysYearTextLab->raise();
        addYearBut->raise();
        reduceYearBut->raise();
        addMonthBut->raise();
        reduceMonthBut->raise();
        addHourBut->raise();
        reduceHourBut->raise();
        addMinBut->raise();
        reduceMinBut->raise();
        addSecondBut->raise();
        sysLanguageListWid->raise();
        userManageTab = new QWidget();
        userManageTab->setObjectName(QStringLiteral("userManageTab"));
        userManageBGLabel = new QLabel(userManageTab);
        userManageBGLabel->setObjectName(QStringLiteral("userManageBGLabel"));
        userManageBGLabel->setGeometry(QRect(0, 0, 926, 560));
        userManageBGLabel->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        sysSetTabWid->addTab(userManageTab, QString());

        retranslateUi(sysSetting);

        sysSetTabWid->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(sysSetting);
    } // setupUi

    void retranslateUi(QWidget *sysSetting)
    {
        sysSetting->setWindowTitle(QApplication::translate("sysSetting", "sysSetting", 0));
        sysParaSetBGLabel->setText(QString());
        dayShowLab->setText(QApplication::translate("sysSetting", "8", 0));
        reduceYearBut->setText(QString());
        addHourBut->setText(QString());
        addMinBut->setText(QString());
        sysMonthTextLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p>\346\234\210</p></body></html>", 0));
        reduceMinBut->setText(QString());
        addSecondBut->setText(QString());
        reduceDayBut->setText(QString());
        sysDateTextLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p>\346\227\245\346\234\237</p></body></html>", 0));
        backLightLab->setText(QApplication::translate("sysSetting", "\350\203\214\345\205\211\344\272\256\345\272\246", 0));
        sysDayTextLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p>\346\227\245</p></body></html>", 0));
        monthShowLab->setText(QApplication::translate("sysSetting", "1", 0));
        secondShowLab->setText(QApplication::translate("sysSetting", "30", 0));
        addDayBut->setText(QString());
        addYearBut->setText(QString());
        reduceSecondBut->setText(QString());
        addMonthBut->setText(QString());
        reduceHourBut->setText(QString());
        sysLanguageLab->setText(QApplication::translate("sysSetting", "\347\263\273\347\273\237\350\257\255\350\250\200", 0));
        minShowLab->setText(QApplication::translate("sysSetting", "27", 0));
        reduceMonthBut->setText(QString());
        hourShowLab->setText(QApplication::translate("sysSetting", "13", 0));
        sysTimeTextLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p>\346\227\266\351\227\264</p></body></html>", 0));
        yearShowLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">2020</span></p></body></html>", 0));
        sysTimeSignal2->setText(QApplication::translate("sysSetting", "<html><head/><body><p>:</p></body></html>", 0));
        sysTimeSetLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\263\273\347\273\237\346\227\266\351\227\264</span></p></body></html>", 0));
        sysTimeSignal1->setText(QApplication::translate("sysSetting", "<html><head/><body><p>:</p></body></html>", 0));
        sysYearTextLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p>\345\271\264</p></body></html>", 0));
        sysSetTabWid->setTabText(sysSetTabWid->indexOf(sysSetTab), QApplication::translate("sysSetting", "\347\263\273\347\273\237\347\216\257\345\242\203", 0));
        userManageBGLabel->setText(QString());
        sysSetTabWid->setTabText(sysSetTabWid->indexOf(userManageTab), QApplication::translate("sysSetting", "\347\224\250\346\210\267\347\256\241\347\220\206", 0));
    } // retranslateUi

};

namespace Ui {
    class sysSetting: public Ui_sysSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSSETTING_H
