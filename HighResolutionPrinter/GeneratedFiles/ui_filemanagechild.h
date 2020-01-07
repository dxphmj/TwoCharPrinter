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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManageChild
{
public:
    QListView *filelistView;
    QPushButton *localFileBut;
    QPushButton *UdiskFileBut;
    QTextBrowser *filePrivewtextBro;
    QScrollBar *filePreHorScrollBar;
    QScrollBar *filePreVerScrollBar;
    QPushButton *loadSeleFileBut;
    QPushButton *editSeleFileBut;
    QPushButton *delSeleFileBut;
    QPushButton *copyFile2localBut;

    void setupUi(QWidget *FileManageChild)
    {
        if (FileManageChild->objectName().isEmpty())
            FileManageChild->setObjectName(QStringLiteral("FileManageChild"));
        FileManageChild->resize(1061, 761);
        filelistView = new QListView(FileManageChild);
        filelistView->setObjectName(QStringLiteral("filelistView"));
        filelistView->setGeometry(QRect(10, 10, 431, 641));
        localFileBut = new QPushButton(FileManageChild);
        localFileBut->setObjectName(QStringLiteral("localFileBut"));
        localFileBut->setGeometry(QRect(60, 680, 131, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(15);
        localFileBut->setFont(font);
        UdiskFileBut = new QPushButton(FileManageChild);
        UdiskFileBut->setObjectName(QStringLiteral("UdiskFileBut"));
        UdiskFileBut->setGeometry(QRect(250, 680, 131, 51));
        UdiskFileBut->setFont(font);
        filePrivewtextBro = new QTextBrowser(FileManageChild);
        filePrivewtextBro->setObjectName(QStringLiteral("filePrivewtextBro"));
        filePrivewtextBro->setGeometry(QRect(460, 10, 551, 301));
        filePreHorScrollBar = new QScrollBar(FileManageChild);
        filePreHorScrollBar->setObjectName(QStringLiteral("filePreHorScrollBar"));
        filePreHorScrollBar->setGeometry(QRect(460, 310, 551, 25));
        filePreHorScrollBar->setOrientation(Qt::Horizontal);
        filePreVerScrollBar = new QScrollBar(FileManageChild);
        filePreVerScrollBar->setObjectName(QStringLiteral("filePreVerScrollBar"));
        filePreVerScrollBar->setGeometry(QRect(1010, 10, 25, 301));
        filePreVerScrollBar->setOrientation(Qt::Vertical);
        loadSeleFileBut = new QPushButton(FileManageChild);
        loadSeleFileBut->setObjectName(QStringLiteral("loadSeleFileBut"));
        loadSeleFileBut->setGeometry(QRect(550, 390, 371, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        loadSeleFileBut->setFont(font1);
        editSeleFileBut = new QPushButton(FileManageChild);
        editSeleFileBut->setObjectName(QStringLiteral("editSeleFileBut"));
        editSeleFileBut->setGeometry(QRect(550, 480, 371, 61));
        editSeleFileBut->setFont(font1);
        delSeleFileBut = new QPushButton(FileManageChild);
        delSeleFileBut->setObjectName(QStringLiteral("delSeleFileBut"));
        delSeleFileBut->setGeometry(QRect(550, 570, 371, 61));
        delSeleFileBut->setFont(font1);
        copyFile2localBut = new QPushButton(FileManageChild);
        copyFile2localBut->setObjectName(QStringLiteral("copyFile2localBut"));
        copyFile2localBut->setGeometry(QRect(550, 660, 371, 61));
        copyFile2localBut->setFont(font1);

        retranslateUi(FileManageChild);

        QMetaObject::connectSlotsByName(FileManageChild);
    } // setupUi

    void retranslateUi(QWidget *FileManageChild)
    {
        FileManageChild->setWindowTitle(QApplication::translate("FileManageChild", "FileManageChild", 0));
        localFileBut->setText(QApplication::translate("FileManageChild", "\346\234\254\345\234\260\346\226\207\344\273\266", 0));
        UdiskFileBut->setText(QApplication::translate("FileManageChild", "U\347\233\230\346\226\207\344\273\266", 0));
        loadSeleFileBut->setText(QApplication::translate("FileManageChild", "\345\212\240\350\275\275\351\200\211\344\270\255\346\226\207\344\273\266", 0));
        editSeleFileBut->setText(QApplication::translate("FileManageChild", "\347\274\226\350\276\221\351\200\211\344\270\255\346\226\207\344\273\266", 0));
        delSeleFileBut->setText(QApplication::translate("FileManageChild", "\345\210\240\351\231\244\351\200\211\344\270\255\346\226\207\344\273\266", 0));
        copyFile2localBut->setText(QApplication::translate("FileManageChild", "\345\244\215\345\210\266\345\210\260\346\234\254\345\234\260", 0));
    } // retranslateUi

};

namespace Ui {
    class FileManageChild: public Ui_FileManageChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGECHILD_H
