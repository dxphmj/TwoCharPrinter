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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sysSetting
{
public:
    QLabel *backLightLab;
    QSlider *lightHorSlider;
    QLabel *sysTimeSetLab;
    QPushButton *addHourBut;
    QLabel *hourShowLab;
    QPushButton *reduceHourBut;
    QPushButton *addMinBut;
    QLabel *minShowLab;
    QPushButton *reduceMinBut;
    QPushButton *addSecondBut;
    QLabel *secondShowLab;
    QPushButton *reduceSecondBut;
    QPushButton *addYearBut;
    QLabel *yearShowLab;
    QPushButton *reduceYearBut;
    QPushButton *addMonthBut;
    QLabel *monthShowLab;
    QPushButton *reduceMonthBut;
    QPushButton *addDayBut;
    QLabel *dayShowLab;
    QPushButton *reduceDayBut;
    QLabel *sysLanguageLab;
    QListWidget *sysLanguageListWid;

    void setupUi(QWidget *sysSetting)
    {
        if (sysSetting->objectName().isEmpty())
            sysSetting->setObjectName(QStringLiteral("sysSetting"));
        sysSetting->resize(1061, 691);
        backLightLab = new QLabel(sysSetting);
        backLightLab->setObjectName(QStringLiteral("backLightLab"));
        backLightLab->setGeometry(QRect(110, 600, 141, 41));
        backLightLab->setMinimumSize(QSize(141, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        backLightLab->setFont(font);
        backLightLab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        backLightLab->setAlignment(Qt::AlignCenter);
        lightHorSlider = new QSlider(sysSetting);
        lightHorSlider->setObjectName(QStringLiteral("lightHorSlider"));
        lightHorSlider->setGeometry(QRect(250, 600, 391, 41));
        lightHorSlider->setStyleSheet(QStringLiteral(""));
        lightHorSlider->setOrientation(Qt::Horizontal);
        sysTimeSetLab = new QLabel(sysSetting);
        sysTimeSetLab->setObjectName(QStringLiteral("sysTimeSetLab"));
        sysTimeSetLab->setGeometry(QRect(320, 40, 141, 41));
        sysTimeSetLab->setMinimumSize(QSize(141, 41));
        sysTimeSetLab->setFont(font);
        sysTimeSetLab->setAlignment(Qt::AlignCenter);
        addHourBut = new QPushButton(sysSetting);
        addHourBut->setObjectName(QStringLiteral("addHourBut"));
        addHourBut->setGeometry(QRect(132, 345, 63, 63));
        addHourBut->setMinimumSize(QSize(63, 51));
        addHourBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        hourShowLab = new QLabel(sysSetting);
        hourShowLab->setObjectName(QStringLiteral("hourShowLab"));
        hourShowLab->setGeometry(QRect(132, 415, 63, 51));
        hourShowLab->setMinimumSize(QSize(63, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        hourShowLab->setFont(font1);
        hourShowLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        hourShowLab->setAlignment(Qt::AlignCenter);
        reduceHourBut = new QPushButton(sysSetting);
        reduceHourBut->setObjectName(QStringLiteral("reduceHourBut"));
        reduceHourBut->setGeometry(QRect(132, 472, 63, 63));
        reduceHourBut->setMinimumSize(QSize(63, 51));
        reduceHourBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        addMinBut = new QPushButton(sysSetting);
        addMinBut->setObjectName(QStringLiteral("addMinBut"));
        addMinBut->setGeometry(QRect(339, 345, 63, 63));
        addMinBut->setMinimumSize(QSize(63, 51));
        addMinBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        minShowLab = new QLabel(sysSetting);
        minShowLab->setObjectName(QStringLiteral("minShowLab"));
        minShowLab->setGeometry(QRect(339, 415, 63, 51));
        minShowLab->setMinimumSize(QSize(63, 51));
        minShowLab->setFont(font1);
        minShowLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        minShowLab->setAlignment(Qt::AlignCenter);
        reduceMinBut = new QPushButton(sysSetting);
        reduceMinBut->setObjectName(QStringLiteral("reduceMinBut"));
        reduceMinBut->setGeometry(QRect(339, 472, 63, 63));
        reduceMinBut->setMinimumSize(QSize(63, 51));
        reduceMinBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        addSecondBut = new QPushButton(sysSetting);
        addSecondBut->setObjectName(QStringLiteral("addSecondBut"));
        addSecondBut->setGeometry(QRect(546, 345, 63, 63));
        addSecondBut->setMinimumSize(QSize(63, 51));
        addSecondBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        secondShowLab = new QLabel(sysSetting);
        secondShowLab->setObjectName(QStringLiteral("secondShowLab"));
        secondShowLab->setGeometry(QRect(546, 415, 63, 51));
        secondShowLab->setMinimumSize(QSize(63, 51));
        secondShowLab->setFont(font1);
        secondShowLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        secondShowLab->setAlignment(Qt::AlignCenter);
        reduceSecondBut = new QPushButton(sysSetting);
        reduceSecondBut->setObjectName(QStringLiteral("reduceSecondBut"));
        reduceSecondBut->setGeometry(QRect(546, 472, 63, 63));
        reduceSecondBut->setMinimumSize(QSize(63, 51));
        reduceSecondBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        addYearBut = new QPushButton(sysSetting);
        addYearBut->setObjectName(QStringLiteral("addYearBut"));
        addYearBut->setGeometry(QRect(132, 103, 63, 63));
        addYearBut->setMinimumSize(QSize(63, 51));
        addYearBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:5px;"));
        yearShowLab = new QLabel(sysSetting);
        yearShowLab->setObjectName(QStringLiteral("yearShowLab"));
        yearShowLab->setGeometry(QRect(132, 173, 63, 51));
        yearShowLab->setMinimumSize(QSize(63, 51));
        yearShowLab->setFont(font1);
        yearShowLab->setAlignment(Qt::AlignCenter);
        reduceYearBut = new QPushButton(sysSetting);
        reduceYearBut->setObjectName(QStringLiteral("reduceYearBut"));
        reduceYearBut->setGeometry(QRect(132, 230, 63, 63));
        reduceYearBut->setMinimumSize(QSize(63, 51));
        reduceYearBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        addMonthBut = new QPushButton(sysSetting);
        addMonthBut->setObjectName(QStringLiteral("addMonthBut"));
        addMonthBut->setGeometry(QRect(339, 103, 63, 63));
        addMonthBut->setMinimumSize(QSize(63, 51));
        addMonthBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        monthShowLab = new QLabel(sysSetting);
        monthShowLab->setObjectName(QStringLiteral("monthShowLab"));
        monthShowLab->setGeometry(QRect(339, 173, 63, 51));
        monthShowLab->setMinimumSize(QSize(63, 51));
        monthShowLab->setFont(font1);
        monthShowLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        monthShowLab->setAlignment(Qt::AlignCenter);
        reduceMonthBut = new QPushButton(sysSetting);
        reduceMonthBut->setObjectName(QStringLiteral("reduceMonthBut"));
        reduceMonthBut->setGeometry(QRect(339, 230, 63, 63));
        reduceMonthBut->setMinimumSize(QSize(63, 51));
        reduceMonthBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        addDayBut = new QPushButton(sysSetting);
        addDayBut->setObjectName(QStringLiteral("addDayBut"));
        addDayBut->setGeometry(QRect(546, 103, 63, 63));
        addDayBut->setMinimumSize(QSize(63, 51));
        addDayBut->setStyleSheet(QLatin1String("background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        dayShowLab = new QLabel(sysSetting);
        dayShowLab->setObjectName(QStringLiteral("dayShowLab"));
        dayShowLab->setGeometry(QRect(546, 173, 63, 51));
        dayShowLab->setMinimumSize(QSize(63, 51));
        dayShowLab->setFont(font1);
        dayShowLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        dayShowLab->setAlignment(Qt::AlignCenter);
        reduceDayBut = new QPushButton(sysSetting);
        reduceDayBut->setObjectName(QStringLiteral("reduceDayBut"));
        reduceDayBut->setGeometry(QRect(546, 230, 63, 63));
        reduceDayBut->setMinimumSize(QSize(63, 51));
        reduceDayBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        sysLanguageLab = new QLabel(sysSetting);
        sysLanguageLab->setObjectName(QStringLiteral("sysLanguageLab"));
        sysLanguageLab->setGeometry(QRect(782, 161, 141, 41));
        sysLanguageLab->setMinimumSize(QSize(141, 41));
        sysLanguageLab->setFont(font);
        sysLanguageLab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        sysLanguageLab->setAlignment(Qt::AlignCenter);
        sysLanguageListWid = new QListWidget(sysSetting);
        sysLanguageListWid->setObjectName(QStringLiteral("sysLanguageListWid"));
        sysLanguageListWid->setGeometry(QRect(730, 210, 256, 301));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(14);
        sysLanguageListWid->setFont(font2);
        sysLanguageListWid->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        addHourBut->raise();
        hourShowLab->raise();
        reduceHourBut->raise();
        addMinBut->raise();
        minShowLab->raise();
        reduceMinBut->raise();
        addSecondBut->raise();
        secondShowLab->raise();
        reduceSecondBut->raise();
        addYearBut->raise();
        yearShowLab->raise();
        reduceYearBut->raise();
        addMonthBut->raise();
        monthShowLab->raise();
        reduceMonthBut->raise();
        addDayBut->raise();
        dayShowLab->raise();
        reduceDayBut->raise();
        sysLanguageLab->raise();
        backLightLab->raise();
        lightHorSlider->raise();
        sysTimeSetLab->raise();
        sysLanguageListWid->raise();

        retranslateUi(sysSetting);

        QMetaObject::connectSlotsByName(sysSetting);
    } // setupUi

    void retranslateUi(QWidget *sysSetting)
    {
        sysSetting->setWindowTitle(QApplication::translate("sysSetting", "sysSetting", 0));
        backLightLab->setText(QApplication::translate("sysSetting", "\350\203\214\345\205\211\344\272\256\345\272\246", 0));
        sysTimeSetLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\263\273\347\273\237\346\227\266\351\227\264</span></p></body></html>", 0));
        addHourBut->setText(QString());
        hourShowLab->setText(QApplication::translate("sysSetting", "13", 0));
        reduceHourBut->setText(QString());
        addMinBut->setText(QString());
        minShowLab->setText(QApplication::translate("sysSetting", "27", 0));
        reduceMinBut->setText(QString());
        addSecondBut->setText(QString());
        secondShowLab->setText(QApplication::translate("sysSetting", "30", 0));
        reduceSecondBut->setText(QString());
        addYearBut->setText(QString());
        yearShowLab->setStyleSheet(QApplication::translate("sysSetting", "color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);", 0));
        yearShowLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">2020</span></p></body></html>", 0));
        reduceYearBut->setText(QString());
        addMonthBut->setText(QString());
        monthShowLab->setText(QApplication::translate("sysSetting", "1", 0));
        reduceMonthBut->setText(QString());
        addDayBut->setText(QString());
        dayShowLab->setText(QApplication::translate("sysSetting", "8", 0));
        reduceDayBut->setText(QString());
        sysLanguageLab->setText(QApplication::translate("sysSetting", "\347\263\273\347\273\237\350\257\255\350\250\200", 0));
    } // retranslateUi

};

namespace Ui {
    class sysSetting: public Ui_sysSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSSETTING_H
