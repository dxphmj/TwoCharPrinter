/********************************************************************************
** Form generated from reading UI file 'filemanageform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMANAGEFORM_H
#define UI_FILEMANAGEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilemanageForm
{
public:

    void setupUi(QWidget *FilemanageForm)
    {
        if (FilemanageForm->objectName().isEmpty())
            FilemanageForm->setObjectName(QStringLiteral("FilemanageForm"));
        FilemanageForm->resize(400, 300);

        retranslateUi(FilemanageForm);

        QMetaObject::connectSlotsByName(FilemanageForm);
    } // setupUi

    void retranslateUi(QWidget *FilemanageForm)
    {
        FilemanageForm->setWindowTitle(QApplication::translate("FilemanageForm", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class FilemanageForm: public Ui_FilemanageForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEFORM_H
