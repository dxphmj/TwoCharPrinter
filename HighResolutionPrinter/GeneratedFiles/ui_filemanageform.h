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

class Ui_FileManageForm
{
public:

    void setupUi(QWidget *FileManageForm)
    {
        if (FileManageForm->objectName().isEmpty())
            FileManageForm->setObjectName(QStringLiteral("FileManageForm"));
        FileManageForm->resize(400, 300);

        retranslateUi(FileManageForm);

        QMetaObject::connectSlotsByName(FileManageForm);
    } // setupUi

    void retranslateUi(QWidget *FileManageForm)
    {
        FileManageForm->setWindowTitle(QApplication::translate("FileManageForm", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class FileManageForm: public Ui_FileManageForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEFORM_H
