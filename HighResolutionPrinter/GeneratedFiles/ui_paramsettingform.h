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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
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
    QPushButton *paraExitBut;
    QLabel *paraManageBackLabel;
    QPushButton *resetBut;
    QPushButton *savePrintSetBut;

    void setupUi(QWidget *ParamSettingForm)
    {
        if (ParamSettingForm->objectName().isEmpty())
            ParamSettingForm->setObjectName(QStringLiteral("ParamSettingForm"));
        ParamSettingForm->resize(1024, 600);
        ParamSettingForm->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        printSettingBut = new QPushButton(ParamSettingForm);
        printSettingBut->setObjectName(QStringLiteral("printSettingBut"));
        printSettingBut->setGeometry(QRect(4, 70, 90, 90));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(18);
        printSettingBut->setFont(font);
        printSettingBut->setStyleSheet(QLatin1String("background-image: url(:/Images/printSetting.bmp);\n"
"color: rgb(255, 255, 255);"));
        sysSettingBut = new QPushButton(ParamSettingForm);
        sysSettingBut->setObjectName(QStringLiteral("sysSettingBut"));
        sysSettingBut->setGeometry(QRect(4, 190, 90, 90));
        sysSettingBut->setFont(font);
        sysSettingBut->setStyleSheet(QLatin1String("background-image: url(:/Images/sysSetting.bmp);\n"
"color: rgb(255, 255, 255);"));
        countSettingBut = new QPushButton(ParamSettingForm);
        countSettingBut->setObjectName(QStringLiteral("countSettingBut"));
        countSettingBut->setGeometry(QRect(30, 330, 0, 0));
        countSettingBut->setFont(font);
        countSettingBut->setStyleSheet(QLatin1String("background-image: url(:/Images/countSetting.bmp);\n"
"color: rgb(255, 255, 255);"));
        aboutMacBut = new QPushButton(ParamSettingForm);
        aboutMacBut->setObjectName(QStringLiteral("aboutMacBut"));
        aboutMacBut->setGeometry(QRect(4, 310, 90, 90));
        aboutMacBut->setFont(font);
        aboutMacBut->setStyleSheet(QLatin1String("background-image: url(:/Images/aboutMac.bmp);\n"
"color: rgb(255, 255, 255);"));
        paraManageStacWid = new QStackedWidget(ParamSettingForm);
        paraManageStacWid->setObjectName(QStringLiteral("paraManageStacWid"));
        paraManageStacWid->setGeometry(QRect(98, 0, 926, 591));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        paraManageStacWid->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        paraManageStacWid->addWidget(page_2);
        paraExitBut = new QPushButton(ParamSettingForm);
        paraExitBut->setObjectName(QStringLiteral("paraExitBut"));
        paraExitBut->setGeometry(QRect(4, 430, 90, 90));
        paraExitBut->setFont(font);
        paraExitBut->setStyleSheet(QLatin1String("background-image: url(:/Images/exit.bmp);\n"
"color: rgb(255, 255, 255);"));
        paraManageBackLabel = new QLabel(ParamSettingForm);
        paraManageBackLabel->setObjectName(QStringLiteral("paraManageBackLabel"));
        paraManageBackLabel->setGeometry(QRect(0, 0, 1024, 600));
        paraManageBackLabel->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        resetBut = new QPushButton(ParamSettingForm);
        resetBut->setObjectName(QStringLiteral("resetBut"));
        resetBut->setGeometry(QRect(370, 540, 111, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        resetBut->setFont(font1);
        resetBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        savePrintSetBut = new QPushButton(ParamSettingForm);
        savePrintSetBut->setObjectName(QStringLiteral("savePrintSetBut"));
        savePrintSetBut->setGeometry(QRect(650, 540, 111, 40));
        savePrintSetBut->setFont(font1);
        savePrintSetBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        paraManageBackLabel->raise();
        printSettingBut->raise();
        sysSettingBut->raise();
        countSettingBut->raise();
        aboutMacBut->raise();
        paraExitBut->raise();
        paraManageStacWid->raise();
        resetBut->raise();
        savePrintSetBut->raise();

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
        paraExitBut->setText(QApplication::translate("ParamSettingForm", "\351\200\200\345\207\272", 0));
        paraManageBackLabel->setText(QString());
        resetBut->setText(QApplication::translate("ParamSettingForm", "\351\207\215\347\275\256", 0));
        savePrintSetBut->setText(QApplication::translate("ParamSettingForm", "\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class ParamSettingForm: public Ui_ParamSettingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMSETTINGFORM_H
