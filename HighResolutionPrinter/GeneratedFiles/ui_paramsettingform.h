/********************************************************************************
** Form generated from reading UI file 'paramsettingform.ui'
**
** Created: Sun Jan 5 18:41:32 2020
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMSETTINGFORM_H
#define UI_PARAMSETTINGFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParamSettingForm
{
public:

    void setupUi(QWidget *ParamSettingForm)
    {
        if (ParamSettingForm->objectName().isEmpty())
            ParamSettingForm->setObjectName(QString::fromUtf8("ParamSettingForm"));
        ParamSettingForm->resize(400, 300);

        retranslateUi(ParamSettingForm);

        QMetaObject::connectSlotsByName(ParamSettingForm);
    } // setupUi

    void retranslateUi(QWidget *ParamSettingForm)
    {
        ParamSettingForm->setWindowTitle(QApplication::translate("ParamSettingForm", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ParamSettingForm: public Ui_ParamSettingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMSETTINGFORM_H
