/********************************************************************************
** Form generated from reading UI file 'variabledm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VARIABLEDM_H
#define UI_VARIABLEDM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_variableDM
{
public:
    QPushButton *returnVarDMBut;

    void setupUi(QWidget *variableDM)
    {
        if (variableDM->objectName().isEmpty())
            variableDM->setObjectName(QStringLiteral("variableDM"));
        variableDM->resize(1061, 761);
        returnVarDMBut = new QPushButton(variableDM);
        returnVarDMBut->setObjectName(QStringLiteral("returnVarDMBut"));
        returnVarDMBut->setGeometry(QRect(850, 620, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        returnVarDMBut->setFont(font);
        returnVarDMBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));

        retranslateUi(variableDM);

        QMetaObject::connectSlotsByName(variableDM);
    } // setupUi

    void retranslateUi(QWidget *variableDM)
    {
        variableDM->setWindowTitle(QApplication::translate("variableDM", "variableDM", 0));
        returnVarDMBut->setText(QApplication::translate("variableDM", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class variableDM: public Ui_variableDM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIABLEDM_H
