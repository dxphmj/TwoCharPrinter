/********************************************************************************
** Form generated from reading UI file 'keyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keyboard
{
public:

    void setupUi(QWidget *keyboard)
    {
        if (keyboard->objectName().isEmpty())
            keyboard->setObjectName(QStringLiteral("keyboard"));
        keyboard->resize(791, 321);

        retranslateUi(keyboard);

        QMetaObject::connectSlotsByName(keyboard);
    } // setupUi

    void retranslateUi(QWidget *keyboard)
    {
        keyboard->setWindowTitle(QApplication::translate("keyboard", "keyboard", 0));
    } // retranslateUi

};

namespace Ui {
    class keyboard: public Ui_keyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
