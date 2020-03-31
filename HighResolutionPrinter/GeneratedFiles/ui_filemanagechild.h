/********************************************************************************
** Form generated from reading UI file 'filemanagechild.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMANAGECHILD_H
#define UI_FILEMANAGECHILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <lineedit_click.h>

QT_BEGIN_NAMESPACE

class Ui_FileManageChild
{
public:
    QListWidget *filelistWidget;
    QTextEdit *filePrivewtextEdit;
    QScrollBar *filePreHorScrollBar;
    QPushButton *copyFile2localBut;
    QPushButton *UdiskFileBut;
    QPushButton *loadSeleFileBut;
    QPushButton *localFileBut;
    QPushButton *editSeleFileBut;
    QPushButton *delSeleFileBut;
    QPushButton *OKFileNameBut;
    lineedit_click *fileNmaeLineEdit;

    void setupUi(QWidget *FileManageChild)
    {
        if (FileManageChild->objectName().isEmpty())
            FileManageChild->setObjectName(QStringLiteral("FileManageChild"));
        FileManageChild->resize(1061, 761);
        filelistWidget = new QListWidget(FileManageChild);
        filelistWidget->setObjectName(QStringLiteral("filelistWidget"));
        filelistWidget->setGeometry(QRect(10, 280, 221, 471));
        filelistWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        filePrivewtextEdit = new QTextEdit(FileManageChild);
        filePrivewtextEdit->setObjectName(QStringLiteral("filePrivewtextEdit"));
        filePrivewtextEdit->setGeometry(QRect(10, 10, 1021, 241));
        filePrivewtextEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        filePreHorScrollBar = new QScrollBar(FileManageChild);
        filePreHorScrollBar->setObjectName(QStringLiteral("filePreHorScrollBar"));
        filePreHorScrollBar->setGeometry(QRect(10, 251, 1021, 25));
        filePreHorScrollBar->setOrientation(Qt::Horizontal);
        copyFile2localBut = new QPushButton(FileManageChild);
        copyFile2localBut->setObjectName(QStringLiteral("copyFile2localBut"));
        copyFile2localBut->setGeometry(QRect(530, 660, 371, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        copyFile2localBut->setFont(font);
        copyFile2localBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        UdiskFileBut = new QPushButton(FileManageChild);
        UdiskFileBut->setObjectName(QStringLiteral("UdiskFileBut"));
        UdiskFileBut->setGeometry(QRect(300, 580, 131, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(15);
        UdiskFileBut->setFont(font1);
        UdiskFileBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        loadSeleFileBut = new QPushButton(FileManageChild);
        loadSeleFileBut->setObjectName(QStringLiteral("loadSeleFileBut"));
        loadSeleFileBut->setGeometry(QRect(530, 390, 371, 61));
        loadSeleFileBut->setFont(font);
        loadSeleFileBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        localFileBut = new QPushButton(FileManageChild);
        localFileBut->setObjectName(QStringLiteral("localFileBut"));
        localFileBut->setGeometry(QRect(300, 480, 131, 51));
        localFileBut->setFont(font1);
        localFileBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        editSeleFileBut = new QPushButton(FileManageChild);
        editSeleFileBut->setObjectName(QStringLiteral("editSeleFileBut"));
        editSeleFileBut->setGeometry(QRect(530, 480, 371, 61));
        editSeleFileBut->setFont(font);
        editSeleFileBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        delSeleFileBut = new QPushButton(FileManageChild);
        delSeleFileBut->setObjectName(QStringLiteral("delSeleFileBut"));
        delSeleFileBut->setGeometry(QRect(530, 570, 371, 61));
        delSeleFileBut->setFont(font);
        delSeleFileBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        OKFileNameBut = new QPushButton(FileManageChild);
        OKFileNameBut->setObjectName(QStringLiteral("OKFileNameBut"));
        OKFileNameBut->setGeometry(QRect(940, 290, 101, 51));
        OKFileNameBut->setFont(font1);
        OKFileNameBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fileNmaeLineEdit = new lineedit_click(FileManageChild);
        fileNmaeLineEdit->setObjectName(QStringLiteral("fileNmaeLineEdit"));
        fileNmaeLineEdit->setGeometry(QRect(240, 290, 691, 51));
        fileNmaeLineEdit->setFont(font);
        fileNmaeLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        retranslateUi(FileManageChild);

        QMetaObject::connectSlotsByName(FileManageChild);
    } // setupUi

    void retranslateUi(QWidget *FileManageChild)
    {
        FileManageChild->setWindowTitle(QApplication::translate("FileManageChild", "FileManageChild", 0));
        copyFile2localBut->setText(QApplication::translate("FileManageChild", "\345\244\215\345\210\266\345\210\260\346\234\254\345\234\260", 0));
        UdiskFileBut->setText(QApplication::translate("FileManageChild", "U\347\233\230\346\226\207\344\273\266", 0));
        loadSeleFileBut->setText(QApplication::translate("FileManageChild", "\345\212\240\350\275\275\351\200\211\344\270\255\346\226\207\344\273\266", 0));
        localFileBut->setText(QApplication::translate("FileManageChild", "\346\234\254\345\234\260\346\226\207\344\273\266", 0));
        editSeleFileBut->setText(QApplication::translate("FileManageChild", "\347\274\226\350\276\221\351\200\211\344\270\255\346\226\207\344\273\266", 0));
        delSeleFileBut->setText(QApplication::translate("FileManageChild", "\345\210\240\351\231\244\351\200\211\344\270\255\346\226\207\344\273\266", 0));
        OKFileNameBut->setText(QApplication::translate("FileManageChild", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class FileManageChild: public Ui_FileManageChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGECHILD_H
