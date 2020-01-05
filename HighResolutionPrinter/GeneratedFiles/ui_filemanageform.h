/********************************************************************************
** Form generated from reading UI file 'filemanageform.ui'
**
** Created: Sun Jan 5 18:41:32 2020
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMANAGEFORM_H
#define UI_FILEMANAGEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManageForm
{
public:

    void setupUi(QWidget *FileManageForm)
    {
        if (FileManageForm->objectName().isEmpty())
            FileManageForm->setObjectName(QString::fromUtf8("FileManageForm"));
        FileManageForm->resize(400, 300);

        retranslateUi(FileManageForm);

        QMetaObject::connectSlotsByName(FileManageForm);
    } // setupUi

    void retranslateUi(QWidget *FileManageForm)
    {
        FileManageForm->setWindowTitle(QApplication::translate("FileManageForm", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FileManageForm: public Ui_FileManageForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEFORM_H
