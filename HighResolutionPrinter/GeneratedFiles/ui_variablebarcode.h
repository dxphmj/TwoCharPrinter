/********************************************************************************
** Form generated from reading UI file 'variablebarcode.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VARIABLEBARCODE_H
#define UI_VARIABLEBARCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_variableBarCode
{
public:
    QPushButton *returnVarBarCodeBut;

    void setupUi(QWidget *variableBarCode)
    {
        if (variableBarCode->objectName().isEmpty())
            variableBarCode->setObjectName(QStringLiteral("variableBarCode"));
        variableBarCode->resize(1061, 761);
        returnVarBarCodeBut = new QPushButton(variableBarCode);
        returnVarBarCodeBut->setObjectName(QStringLiteral("returnVarBarCodeBut"));
        returnVarBarCodeBut->setGeometry(QRect(800, 630, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        returnVarBarCodeBut->setFont(font);
        returnVarBarCodeBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));

        retranslateUi(variableBarCode);

        QMetaObject::connectSlotsByName(variableBarCode);
    } // setupUi

    void retranslateUi(QWidget *variableBarCode)
    {
        variableBarCode->setWindowTitle(QApplication::translate("variableBarCode", "variableBarCode", 0));
        returnVarBarCodeBut->setText(QApplication::translate("variableBarCode", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class variableBarCode: public Ui_variableBarCode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIABLEBARCODE_H
