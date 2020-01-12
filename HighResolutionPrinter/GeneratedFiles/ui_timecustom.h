/********************************************************************************
** Form generated from reading UI file 'timecustom.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMECUSTOM_H
#define UI_TIMECUSTOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_timeCustom
{
public:

    void setupUi(QWidget *timeCustom)
    {
        if (timeCustom->objectName().isEmpty())
            timeCustom->setObjectName(QStringLiteral("timeCustom"));
        timeCustom->resize(1061, 761);

        retranslateUi(timeCustom);

        QMetaObject::connectSlotsByName(timeCustom);
    } // setupUi

    void retranslateUi(QWidget *timeCustom)
    {
        timeCustom->setWindowTitle(QApplication::translate("timeCustom", "timeCustom", 0));
    } // retranslateUi

};

namespace Ui {
    class timeCustom: public Ui_timeCustom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMECUSTOM_H
