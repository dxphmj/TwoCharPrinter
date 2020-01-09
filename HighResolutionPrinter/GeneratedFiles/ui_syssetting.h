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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sysSetting
{
public:
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QPushButton *addHourBut;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_10;
    QPushButton *reduceHourBut;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_6;
    QPushButton *addMinBut;
    QSpacerItem *verticalSpacer_11;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_12;
    QPushButton *reduceMinBut;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_7;
    QPushButton *addSecondBut;
    QSpacerItem *verticalSpacer_13;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_14;
    QPushButton *reduceSecondBut;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *addYearBut;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QPushButton *reduceYearBut;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addMonthBut;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_4;
    QPushButton *reduceMonthBut;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addDayBut;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_6;
    QPushButton *reduceDayBut;
    QLabel *backLightLab;
    QSlider *lightHorSlider;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QLabel *sysLanguageLab;
    QComboBox *comboBox;
    QLabel *sysTimeSetLab;

    void setupUi(QWidget *sysSetting)
    {
        if (sysSetting->objectName().isEmpty())
            sysSetting->setObjectName(QStringLiteral("sysSetting"));
        sysSetting->resize(1061, 691);
        layoutWidget_3 = new QWidget(sysSetting);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(130, 330, 511, 221));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        addHourBut = new QPushButton(layoutWidget_3);
        addHourBut->setObjectName(QStringLiteral("addHourBut"));
        addHourBut->setMinimumSize(QSize(93, 51));

        verticalLayout_5->addWidget(addHourBut);

        verticalSpacer_9 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_9);

        label_5 = new QLabel(layoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(93, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        verticalSpacer_10 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_10);

        reduceHourBut = new QPushButton(layoutWidget_3);
        reduceHourBut->setObjectName(QStringLiteral("reduceHourBut"));
        reduceHourBut->setMinimumSize(QSize(93, 51));

        verticalLayout_5->addWidget(reduceHourBut);


        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalSpacer_3 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        addMinBut = new QPushButton(layoutWidget_3);
        addMinBut->setObjectName(QStringLiteral("addMinBut"));
        addMinBut->setMinimumSize(QSize(93, 51));

        verticalLayout_6->addWidget(addMinBut);

        verticalSpacer_11 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_11);

        label_6 = new QLabel(layoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(93, 51));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_6);

        verticalSpacer_12 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_12);

        reduceMinBut = new QPushButton(layoutWidget_3);
        reduceMinBut->setObjectName(QStringLiteral("reduceMinBut"));
        reduceMinBut->setMinimumSize(QSize(93, 51));

        verticalLayout_6->addWidget(reduceMinBut);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalSpacer_4 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        addSecondBut = new QPushButton(layoutWidget_3);
        addSecondBut->setObjectName(QStringLiteral("addSecondBut"));
        addSecondBut->setMinimumSize(QSize(93, 51));

        verticalLayout_7->addWidget(addSecondBut);

        verticalSpacer_13 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_13);

        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(93, 51));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_7);

        verticalSpacer_14 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_14);

        reduceSecondBut = new QPushButton(layoutWidget_3);
        reduceSecondBut->setObjectName(QStringLiteral("reduceSecondBut"));
        reduceSecondBut->setMinimumSize(QSize(93, 51));

        verticalLayout_7->addWidget(reduceSecondBut);


        horizontalLayout_2->addLayout(verticalLayout_7);

        layoutWidget = new QWidget(sysSetting);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 88, 511, 221));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addYearBut = new QPushButton(layoutWidget);
        addYearBut->setObjectName(QStringLiteral("addYearBut"));
        addYearBut->setMinimumSize(QSize(93, 51));

        verticalLayout->addWidget(addYearBut);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(93, 51));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        reduceYearBut = new QPushButton(layoutWidget);
        reduceYearBut->setObjectName(QStringLiteral("reduceYearBut"));
        reduceYearBut->setMinimumSize(QSize(93, 51));

        verticalLayout->addWidget(reduceYearBut);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addMonthBut = new QPushButton(layoutWidget);
        addMonthBut->setObjectName(QStringLiteral("addMonthBut"));
        addMonthBut->setMinimumSize(QSize(93, 51));

        verticalLayout_2->addWidget(addMonthBut);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(93, 51));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        reduceMonthBut = new QPushButton(layoutWidget);
        reduceMonthBut->setObjectName(QStringLiteral("reduceMonthBut"));
        reduceMonthBut->setMinimumSize(QSize(93, 51));

        verticalLayout_2->addWidget(reduceMonthBut);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        addDayBut = new QPushButton(layoutWidget);
        addDayBut->setObjectName(QStringLiteral("addDayBut"));
        addDayBut->setMinimumSize(QSize(93, 51));

        verticalLayout_3->addWidget(addDayBut);

        verticalSpacer_5 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(93, 51));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        verticalSpacer_6 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        reduceDayBut = new QPushButton(layoutWidget);
        reduceDayBut->setObjectName(QStringLiteral("reduceDayBut"));
        reduceDayBut->setMinimumSize(QSize(93, 51));

        verticalLayout_3->addWidget(reduceDayBut);


        horizontalLayout->addLayout(verticalLayout_3);

        backLightLab = new QLabel(sysSetting);
        backLightLab->setObjectName(QStringLiteral("backLightLab"));
        backLightLab->setGeometry(QRect(110, 600, 141, 41));
        backLightLab->setMinimumSize(QSize(141, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        backLightLab->setFont(font1);
        backLightLab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        backLightLab->setAlignment(Qt::AlignCenter);
        lightHorSlider = new QSlider(sysSetting);
        lightHorSlider->setObjectName(QStringLiteral("lightHorSlider"));
        lightHorSlider->setGeometry(QRect(250, 600, 391, 41));
        lightHorSlider->setStyleSheet(QStringLiteral(""));
        lightHorSlider->setOrientation(Qt::Horizontal);
        layoutWidget1 = new QWidget(sysSetting);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(781, 240, 143, 81));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        sysLanguageLab = new QLabel(layoutWidget1);
        sysLanguageLab->setObjectName(QStringLiteral("sysLanguageLab"));
        sysLanguageLab->setMinimumSize(QSize(141, 41));
        sysLanguageLab->setFont(font1);
        sysLanguageLab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        sysLanguageLab->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(sysLanguageLab);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(141, 31));

        verticalLayout_4->addWidget(comboBox);

        sysTimeSetLab = new QLabel(sysSetting);
        sysTimeSetLab->setObjectName(QStringLiteral("sysTimeSetLab"));
        sysTimeSetLab->setGeometry(QRect(320, 40, 141, 41));
        sysTimeSetLab->setMinimumSize(QSize(141, 41));
        sysTimeSetLab->setFont(font1);
        sysTimeSetLab->setAlignment(Qt::AlignCenter);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget_3->raise();
        backLightLab->raise();
        lightHorSlider->raise();
        sysTimeSetLab->raise();

        retranslateUi(sysSetting);

        QMetaObject::connectSlotsByName(sysSetting);
    } // setupUi

    void retranslateUi(QWidget *sysSetting)
    {
        sysSetting->setWindowTitle(QApplication::translate("sysSetting", "sysSetting", 0));
        addHourBut->setText(QString());
        label_5->setText(QApplication::translate("sysSetting", "13", 0));
        reduceHourBut->setText(QString());
        addMinBut->setText(QString());
        label_6->setText(QApplication::translate("sysSetting", "27", 0));
        reduceMinBut->setText(QString());
        addSecondBut->setText(QString());
        label_7->setText(QApplication::translate("sysSetting", "30", 0));
        reduceSecondBut->setText(QString());
        addYearBut->setText(QString());
        label->setText(QApplication::translate("sysSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">2020</span></p></body></html>", 0));
        reduceYearBut->setText(QString());
        addMonthBut->setText(QString());
        label_2->setText(QApplication::translate("sysSetting", "01", 0));
        reduceMonthBut->setText(QString());
        addDayBut->setText(QString());
        label_3->setText(QApplication::translate("sysSetting", "08", 0));
        reduceDayBut->setText(QString());
        backLightLab->setText(QApplication::translate("sysSetting", "\350\203\214\345\205\211\344\272\256\345\272\246", 0));
        sysLanguageLab->setText(QApplication::translate("sysSetting", "\347\263\273\347\273\237\350\257\255\350\250\200", 0));
        sysTimeSetLab->setText(QApplication::translate("sysSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\263\273\347\273\237\346\227\266\351\227\264</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class sysSetting: public Ui_sysSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSSETTING_H
