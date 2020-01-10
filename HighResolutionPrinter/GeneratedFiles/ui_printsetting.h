/********************************************************************************
** Form generated from reading UI file 'printsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTSETTING_H
#define UI_PRINTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_printSetting
{
public:
    QTabWidget *printSetTabWid;
    QWidget *tab;
    QWidget *tab_3;
    QWidget *tab_2;
    QWidget *tab_4;

    void setupUi(QWidget *printSetting)
    {
        if (printSetting->objectName().isEmpty())
            printSetting->setObjectName(QStringLiteral("printSetting"));
        printSetting->resize(1061, 691);
        printSetting->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        printSetTabWid = new QTabWidget(printSetting);
        printSetTabWid->setObjectName(QStringLiteral("printSetTabWid"));
        printSetTabWid->setGeometry(QRect(20, 20, 1021, 651));
        printSetTabWid->setMaximumSize(QSize(1021, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        printSetTabWid->setFont(font);
        printSetTabWid->setStyleSheet(QLatin1String("QTabBar::tab{width:255}\n"
"QTabBar::tab{height:50}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        printSetTabWid->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        printSetTabWid->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        printSetTabWid->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        printSetTabWid->addTab(tab_4, QString());

        retranslateUi(printSetting);

        printSetTabWid->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(printSetting);
    } // setupUi

    void retranslateUi(QWidget *printSetting)
    {
        printSetting->setWindowTitle(QApplication::translate("printSetting", "printSetting", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(tab), QApplication::translate("printSetting", "\346\211\223\345\215\260\351\243\216\346\240\274", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(tab_3), QApplication::translate("printSetting", "\351\253\230\347\272\247\350\256\276\347\275\256", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(tab_2), QApplication::translate("printSetting", "\345\226\267\345\244\264\350\256\276\347\275\256", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(tab_4), QApplication::translate("printSetting", "UV\347\201\257\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class printSetting: public Ui_printSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTSETTING_H
