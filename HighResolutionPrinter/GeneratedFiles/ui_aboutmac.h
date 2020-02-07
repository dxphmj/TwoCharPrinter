/********************************************************************************
** Form generated from reading UI file 'aboutmac.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTMAC_H
#define UI_ABOUTMAC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutMac
{
public:

    void setupUi(QWidget *aboutMac)
    {
        if (aboutMac->objectName().isEmpty())
            aboutMac->setObjectName(QStringLiteral("aboutMac"));
        aboutMac->resize(1061, 651);

        retranslateUi(aboutMac);

        QMetaObject::connectSlotsByName(aboutMac);
    } // setupUi

    void retranslateUi(QWidget *aboutMac)
    {
        aboutMac->setWindowTitle(QApplication::translate("aboutMac", "aboutMac", 0));
    } // retranslateUi

};

namespace Ui {
    class aboutMac: public Ui_aboutMac {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTMAC_H
