/********************************************************************************
** Form generated from reading UI file 'symbolwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMBOLWIDGET_H
#define UI_SYMBOLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_symbolWidget
{
public:

    void setupUi(QWidget *symbolWidget)
    {
        if (symbolWidget->objectName().isEmpty())
            symbolWidget->setObjectName(QStringLiteral("symbolWidget"));
        symbolWidget->resize(791, 321);
        symbolWidget->setStyleSheet(QStringLiteral("background-color: rgb(119,117,128);"));

        retranslateUi(symbolWidget);

        QMetaObject::connectSlotsByName(symbolWidget);
    } // setupUi

    void retranslateUi(QWidget *symbolWidget)
    {
        symbolWidget->setWindowTitle(QApplication::translate("symbolWidget", "symbolWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class symbolWidget: public Ui_symbolWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMBOLWIDGET_H
