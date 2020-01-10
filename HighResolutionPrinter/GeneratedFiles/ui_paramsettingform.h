/********************************************************************************
** Form generated from reading UI file 'paramsettingform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMSETTINGFORM_H
#define UI_PARAMSETTINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParamSettingForm
{
public:
    QPushButton *printSettingBut;
    QPushButton *sysSettingBut;
    QPushButton *countSettingBut;
    QPushButton *aboutMacBut;
    QStackedWidget *paraManageStacWid;
    QWidget *page;
    QWidget *page_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *savePrintSetBut;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitBut;

    void setupUi(QWidget *ParamSettingForm)
    {
        if (ParamSettingForm->objectName().isEmpty())
            ParamSettingForm->setObjectName(QStringLiteral("ParamSettingForm"));
        ParamSettingForm->resize(1280, 800);
        ParamSettingForm->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        printSettingBut = new QPushButton(ParamSettingForm);
        printSettingBut->setObjectName(QStringLiteral("printSettingBut"));
        printSettingBut->setGeometry(QRect(30, 110, 144, 144));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        printSettingBut->setFont(font);
        printSettingBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/printSetting.bmp);"));
        sysSettingBut = new QPushButton(ParamSettingForm);
        sysSettingBut->setObjectName(QStringLiteral("sysSettingBut"));
        sysSettingBut->setGeometry(QRect(30, 260, 144, 144));
        sysSettingBut->setFont(font);
        sysSettingBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/sysSetting.bmp);"));
        countSettingBut = new QPushButton(ParamSettingForm);
        countSettingBut->setObjectName(QStringLiteral("countSettingBut"));
        countSettingBut->setGeometry(QRect(30, 410, 144, 144));
        countSettingBut->setFont(font);
        countSettingBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/countSetting.bmp);"));
        aboutMacBut = new QPushButton(ParamSettingForm);
        aboutMacBut->setObjectName(QStringLiteral("aboutMacBut"));
        aboutMacBut->setGeometry(QRect(30, 560, 144, 144));
        aboutMacBut->setFont(font);
        aboutMacBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/aboutMac.bmp);"));
        paraManageStacWid = new QStackedWidget(ParamSettingForm);
        paraManageStacWid->setObjectName(QStringLiteral("paraManageStacWid"));
        paraManageStacWid->setGeometry(QRect(200, 20, 1061, 691));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        paraManageStacWid->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        paraManageStacWid->addWidget(page_2);
        layoutWidget = new QWidget(ParamSettingForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(390, 730, 671, 38));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        savePrintSetBut = new QPushButton(layoutWidget);
        savePrintSetBut->setObjectName(QStringLiteral("savePrintSetBut"));
        savePrintSetBut->setFont(font);
        savePrintSetBut->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(savePrintSetBut);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        quitBut = new QPushButton(layoutWidget);
        quitBut->setObjectName(QStringLiteral("quitBut"));
        quitBut->setFont(font);
        quitBut->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(quitBut);


        retranslateUi(ParamSettingForm);

        QMetaObject::connectSlotsByName(ParamSettingForm);
    } // setupUi

    void retranslateUi(QWidget *ParamSettingForm)
    {
        ParamSettingForm->setWindowTitle(QApplication::translate("ParamSettingForm", "Form", 0));
        printSettingBut->setText(QApplication::translate("ParamSettingForm", "\346\211\223\345\215\260\350\256\276\347\275\256", 0));
        sysSettingBut->setText(QApplication::translate("ParamSettingForm", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        countSettingBut->setText(QApplication::translate("ParamSettingForm", "\350\256\241\346\225\260\350\256\276\347\275\256", 0));
        aboutMacBut->setText(QApplication::translate("ParamSettingForm", "\345\205\263\344\272\216\346\234\254\346\234\272", 0));
        savePrintSetBut->setText(QApplication::translate("ParamSettingForm", "\344\277\235\345\255\230", 0));
        quitBut->setText(QApplication::translate("ParamSettingForm", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class ParamSettingForm: public Ui_ParamSettingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMSETTINGFORM_H
