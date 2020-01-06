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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParamSettingForm
{
public:

    void setupUi(QWidget *ParamSettingForm)
    {
        if (ParamSettingForm->objectName().isEmpty())
            ParamSettingForm->setObjectName(QStringLiteral("ParamSettingForm"));
        ParamSettingForm->resize(400, 300);

        retranslateUi(ParamSettingForm);

        QMetaObject::connectSlotsByName(ParamSettingForm);
    } // setupUi

    void retranslateUi(QWidget *ParamSettingForm)
    {
        ParamSettingForm->setWindowTitle(QApplication::translate("ParamSettingForm", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ParamSettingForm: public Ui_ParamSettingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMSETTINGFORM_H
