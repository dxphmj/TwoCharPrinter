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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilemanageForm
{
public:
    QPushButton *editFileBut;
    QPushButton *manageFileBut;
    QPushButton *exitBut;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QLabel *fileControlLab;
    QLabel *fileManageBackLabel;

    void setupUi(QWidget *FilemanageForm)
    {
        if (FilemanageForm->objectName().isEmpty())
            FilemanageForm->setObjectName(QStringLiteral("FilemanageForm"));
        FilemanageForm->resize(1280, 800);
        FilemanageForm->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        editFileBut = new QPushButton(FilemanageForm);
        editFileBut->setObjectName(QStringLiteral("editFileBut"));
        editFileBut->setGeometry(QRect(10, 120, 144, 144));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        editFileBut->setFont(font);
        editFileBut->setStyleSheet(QLatin1String("background-image: url(:/Images/editFile.bmp);\n"
"color: rgb(255, 255, 255);"));
        manageFileBut = new QPushButton(FilemanageForm);
        manageFileBut->setObjectName(QStringLiteral("manageFileBut"));
        manageFileBut->setGeometry(QRect(10, 340, 144, 144));
        manageFileBut->setFont(font);
        manageFileBut->setStyleSheet(QLatin1String("background-image: url(:/Images/manageFile.bmp);\n"
"color: rgb(255, 255, 255);"));
        exitBut = new QPushButton(FilemanageForm);
        exitBut->setObjectName(QStringLiteral("exitBut"));
        exitBut->setGeometry(QRect(10, 560, 144, 144));
        exitBut->setFont(font);
        exitBut->setStyleSheet(QLatin1String("background-image: url(:/Images/exit.bmp);\n"
"color: rgb(255, 255, 255);"));
        stackedWidget = new QStackedWidget(FilemanageForm);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(190, 20, 1061, 761));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        fileControlLab = new QLabel(FilemanageForm);
        fileControlLab->setObjectName(QStringLiteral("fileControlLab"));
        fileControlLab->setGeometry(QRect(10, 19, 181, 761));
        fileControlLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        fileManageBackLabel = new QLabel(FilemanageForm);
        fileManageBackLabel->setObjectName(QStringLiteral("fileManageBackLabel"));
        fileManageBackLabel->setGeometry(QRect(0, 0, 1280, 800));
        fileManageBackLabel->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        fileManageBackLabel->raise();
        fileControlLab->raise();
        editFileBut->raise();
        manageFileBut->raise();
        exitBut->raise();
        stackedWidget->raise();

        retranslateUi(FilemanageForm);

        QMetaObject::connectSlotsByName(FilemanageForm);
    } // setupUi

    void retranslateUi(QWidget *FilemanageForm)
    {
        FilemanageForm->setWindowTitle(QApplication::translate("FilemanageForm", "Form", 0));
        editFileBut->setText(QApplication::translate("FilemanageForm", "\347\274\226\350\276\221\346\226\207\344\273\266", 0));
        manageFileBut->setText(QApplication::translate("FilemanageForm", "\347\256\241\347\220\206\346\226\207\344\273\266", 0));
        exitBut->setText(QApplication::translate("FilemanageForm", "\351\200\200\345\207\272", 0));
        fileControlLab->setText(QString());
        fileManageBackLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FilemanageForm: public Ui_FilemanageForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEFORM_H
