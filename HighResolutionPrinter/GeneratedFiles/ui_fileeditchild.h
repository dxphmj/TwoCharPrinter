/********************************************************************************
** Form generated from reading UI file 'fileeditchild.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEEDITCHILD_H
#define UI_FILEEDITCHILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileEditChild
{
public:
    QPushButton *saveBut;
    QPushButton *editBut;
    QTextEdit *editPreviewText;
    QPushButton *saveasBut;
    QPushButton *delBut;
    QScrollBar *textpreviewScrollBar;
    QTabWidget *typeTab;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *FileEditChild)
    {
        if (FileEditChild->objectName().isEmpty())
            FileEditChild->setObjectName(QStringLiteral("FileEditChild"));
        FileEditChild->resize(1061, 761);
        saveBut = new QPushButton(FileEditChild);
        saveBut->setObjectName(QStringLiteral("saveBut"));
        saveBut->setGeometry(QRect(880, 540, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        saveBut->setFont(font);
        editBut = new QPushButton(FileEditChild);
        editBut->setObjectName(QStringLiteral("editBut"));
        editBut->setGeometry(QRect(880, 450, 131, 41));
        editBut->setFont(font);
        editPreviewText = new QTextEdit(FileEditChild);
        editPreviewText->setObjectName(QStringLiteral("editPreviewText"));
        editPreviewText->setGeometry(QRect(10, 10, 1041, 241));
        saveasBut = new QPushButton(FileEditChild);
        saveasBut->setObjectName(QStringLiteral("saveasBut"));
        saveasBut->setGeometry(QRect(880, 630, 131, 41));
        saveasBut->setFont(font);
        delBut = new QPushButton(FileEditChild);
        delBut->setObjectName(QStringLiteral("delBut"));
        delBut->setGeometry(QRect(880, 360, 131, 41));
        delBut->setFont(font);
        textpreviewScrollBar = new QScrollBar(FileEditChild);
        textpreviewScrollBar->setObjectName(QStringLiteral("textpreviewScrollBar"));
        textpreviewScrollBar->setGeometry(QRect(10, 250, 1041, 26));
        textpreviewScrollBar->setOrientation(Qt::Horizontal);
        typeTab = new QTabWidget(FileEditChild);
        typeTab->setObjectName(QStringLiteral("typeTab"));
        typeTab->setGeometry(QRect(10, 290, 821, 461));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        typeTab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        typeTab->addTab(tab_2, QString());

        retranslateUi(FileEditChild);

        QMetaObject::connectSlotsByName(FileEditChild);
    } // setupUi

    void retranslateUi(QWidget *FileEditChild)
    {
        FileEditChild->setWindowTitle(QApplication::translate("FileEditChild", "FileEditChild", 0));
        saveBut->setText(QApplication::translate("FileEditChild", "\344\277\235\345\255\230", 0));
        editBut->setText(QApplication::translate("FileEditChild", "\347\274\226\350\276\221", 0));
        saveasBut->setText(QApplication::translate("FileEditChild", "\345\217\246\345\255\230\344\270\272", 0));
        delBut->setText(QApplication::translate("FileEditChild", "\345\210\240\351\231\244", 0));
        typeTab->setTabText(typeTab->indexOf(tab), QApplication::translate("FileEditChild", "Tab 1", 0));
        typeTab->setTabText(typeTab->indexOf(tab_2), QApplication::translate("FileEditChild", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class FileEditChild: public Ui_FileEditChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEDITCHILD_H
