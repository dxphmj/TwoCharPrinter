/********************************************************************************
** Form generated from reading UI file 'variblewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VARIBLEWIDGET_H
#define UI_VARIBLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_varibleWidget
{
public:
    QPushButton *returnVarTextBut;

    void setupUi(QWidget *varibleWidget)
    {
        if (varibleWidget->objectName().isEmpty())
            varibleWidget->setObjectName(QStringLiteral("varibleWidget"));
        varibleWidget->resize(1061, 761);
        returnVarTextBut = new QPushButton(varibleWidget);
        returnVarTextBut->setObjectName(QStringLiteral("returnVarTextBut"));
        returnVarTextBut->setGeometry(QRect(730, 660, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        returnVarTextBut->setFont(font);
        returnVarTextBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));

        retranslateUi(varibleWidget);

        QMetaObject::connectSlotsByName(varibleWidget);
    } // setupUi

    void retranslateUi(QWidget *varibleWidget)
    {
        varibleWidget->setWindowTitle(QApplication::translate("varibleWidget", "varibleWidget", 0));
        returnVarTextBut->setText(QApplication::translate("varibleWidget", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class varibleWidget: public Ui_varibleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIBLEWIDGET_H
