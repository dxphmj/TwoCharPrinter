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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QLabel *hourShowBut;
    QPushButton *reduceHourBut;
    QPushButton *addMinBut;
    QLabel *minShowBut;
    QPushButton *reduceMinBut;
    QPushButton *addSecondBut;
    QLabel *secondShowBut;
    QPushButton *reduceSecondBut;
    QPushButton *addYearBut;
    QLabel *yearShowBut;
    QPushButton *reduceYearBut;
    QPushButton *addMonthBut;
    QLabel *monthShowBut;
    QPushButton *reduceMonthBut;
    QPushButton *addDayBut;
    QLabel *dayShowBut;
    QPushButton *reduceDayBut;
    QLabel *sysLanguageLab;
    QComboBox *comboBox;

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
        font.setPointSize(14);
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
        hourShowBut = new QLabel(sysSetting);
        hourShowBut->setObjectName(QStringLiteral("hourShowBut"));
        hourShowBut->setGeometry(QRect(132, 415, 63, 51));
        hourShowBut->setMinimumSize(QSize(63, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        hourShowBut->setFont(font1);
        hourShowBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        hourShowBut->setAlignment(Qt::AlignCenter);
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
        minShowBut = new QLabel(sysSetting);
        minShowBut->setObjectName(QStringLiteral("minShowBut"));
        minShowBut->setGeometry(QRect(339, 415, 63, 51));
        minShowBut->setMinimumSize(QSize(63, 51));
        minShowBut->setFont(font1);
        minShowBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        minShowBut->setAlignment(Qt::AlignCenter);
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
        secondShowBut = new QLabel(sysSetting);
        secondShowBut->setObjectName(QStringLiteral("secondShowBut"));
        secondShowBut->setGeometry(QRect(546, 415, 63, 51));
        secondShowBut->setMinimumSize(QSize(63, 51));
        secondShowBut->setFont(font1);
        secondShowBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        secondShowBut->setAlignment(Qt::AlignCenter);
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
        yearShowBut = new QLabel(sysSetting);
        yearShowBut->setObjectName(QStringLiteral("yearShowBut"));
        yearShowBut->setGeometry(QRect(132, 173, 63, 51));
        yearShowBut->setMinimumSize(QSize(63, 51));
        yearShowBut->setFont(font1);
        yearShowBut->setAlignment(Qt::AlignCenter);
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
        monthShowBut = new QLabel(sysSetting);
        monthShowBut->setObjectName(QStringLiteral("monthShowBut"));
        monthShowBut->setGeometry(QRect(339, 173, 63, 51));
        monthShowBut->setMinimumSize(QSize(63, 51));
        monthShowBut->setFont(font1);
        monthShowBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        monthShowBut->setAlignment(Qt::AlignCenter);
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
        dayShowBut = new QLabel(sysSetting);
        dayShowBut->setObjectName(QStringLiteral("dayShowBut"));
        dayShowBut->setGeometry(QRect(546, 173, 63, 51));
        dayShowBut->setMinimumSize(QSize(63, 51));
        dayShowBut->setFont(font1);
        dayShowBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        dayShowBut->setAlignment(Qt::AlignCenter);
        reduceDayBut = new QPushButton(sysSetting);
        reduceDayBut->setObjectName(QStringLiteral("reduceDayBut"));
        reduceDayBut->setGeometry(QRect(546, 230, 63, 63));
        reduceDayBut->setMinimumSize(QSize(63, 51));
        reduceDayBut->setStyleSheet(QLatin1String("background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        sysLanguageLab = new QLabel(sysSetting);
        sysLanguageLab->setObjectName(QStringLiteral("sysLanguageLab"));
        sysLanguageLab->setGeometry(QRect(782, 241, 141, 41));
        sysLanguageLab->setMinimumSize(QSize(141, 41));
        sysLanguageLab->setFont(font);
        sysLanguageLab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        sysLanguageLab->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(sysSetting);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(782, 289, 141, 31));
        comboBox->setMinimumSize(QSize(141, 31));
        comboBox->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 230);"));
        addHourBut->raise();
        hourShowBut->raise();
        reduceHourBut->raise();
        addMinBut->raise();
        minShowBut->raise();
        reduceMinBut->raise();
        addSecondBut->raise();
        secondShowBut->raise();
        reduceSecondBut->raise();
        addYearBut->raise();
        yearShowBut->raise();
        reduceYearBut->raise();
        addMonthBut->raise();
        monthShowBut->raise();
        reduceMonthBut->raise();
        addDayBut->raise();
        dayShowBut->raise();
        reduceDayBut->raise();
        sysLanguageLab->raise();
        comboBox->raise();
        backLightLab->raise();
        lightHorSlider->raise();
        sysTimeSetLab->raise();

        retranslateUi(sysSetting);

        QMetaObject::connectSlotsByName(sysSetting);
    } // setupUi

    void retranslateUi(QWidget *sysSetting)
    {
        sysSetting->setWindowTitle(QApplication::translate("sysSetting", "sysSetting", 0));
        backLightLab->setText(QApplication::translate("sysSetting", "\350\203\214\345\205\211\344\272\256\345\272\246", 0));
        sysTimeSetLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\263\273\347\273\237\346\227\266\351\227\264</span></p></body></html>", 0));
        addHourBut->setText(QString());
        hourShowBut->setText(QApplication::translate("sysSetting", "13", 0));
        reduceHourBut->setText(QString());
        addMinBut->setText(QString());
        minShowBut->setText(QApplication::translate("sysSetting", "27", 0));
        reduceMinBut->setText(QString());
        addSecondBut->setText(QString());
        secondShowBut->setText(QApplication::translate("sysSetting", "30", 0));
        reduceSecondBut->setText(QString());
        addYearBut->setText(QString());
        yearShowBut->setStyleSheet(QApplication::translate("sysSetting", "color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);", 0));
        yearShowBut->setText(QApplication::translate("sysSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">2020</span></p></body></html>", 0));
        reduceYearBut->setText(QString());
        addMonthBut->setText(QString());
        monthShowBut->setText(QApplication::translate("sysSetting", "01", 0));
        reduceMonthBut->setText(QString());
        addDayBut->setText(QString());
        dayShowBut->setText(QApplication::translate("sysSetting", "08", 0));
        reduceDayBut->setText(QString());
        sysLanguageLab->setText(QApplication::translate("sysSetting", "\347\263\273\347\273\237\350\257\255\350\250\200", 0));
    } // retranslateUi

};

namespace Ui {
    class sysSetting: public Ui_sysSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSSETTING_H
