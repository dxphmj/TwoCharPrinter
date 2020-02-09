/********************************************************************************
** Form generated from reading UI file 'variableqr.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VARIABLEQR_H
#define UI_VARIABLEQR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_variableQR
{
public:
    QPushButton *returnVarQRBut;

    void setupUi(QWidget *variableQR)
    {
        if (variableQR->objectName().isEmpty())
            variableQR->setObjectName(QStringLiteral("variableQR"));
        variableQR->resize(1061, 791);
        returnVarQRBut = new QPushButton(variableQR);
        returnVarQRBut->setObjectName(QStringLiteral("returnVarQRBut"));
        returnVarQRBut->setGeometry(QRect(830, 670, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        returnVarQRBut->setFont(font);
        returnVarQRBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));

        retranslateUi(variableQR);

        QMetaObject::connectSlotsByName(variableQR);
    } // setupUi

    void retranslateUi(QWidget *variableQR)
    {
        variableQR->setWindowTitle(QApplication::translate("variableQR", "variableQR", 0));
        returnVarQRBut->setText(QApplication::translate("variableQR", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class variableQR: public Ui_variableQR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIABLEQR_H
