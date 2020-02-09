/********************************************************************************
** Form generated from reading UI file 'numkeyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMKEYBOARD_H
#define UI_NUMKEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_numkeyboard
{
public:
    QLabel *backgroundNumKBLabel;
    QPushButton *three_NumKBBut;
    QPushButton *two_NumKBBut;
    QPushButton *one_NumKBBut;
    QPushButton *six_NumKBBut;
    QPushButton *four_NumKBBut;
    QPushButton *five_NumKBBut;
    QPushButton *nine_NumKBBut;
    QPushButton *eight_NumKBBut;
    QPushButton *seven_NumKBBut;
    QPushButton *zero_NumKBBut;
    QPushButton *period_NumKBBut;
    QPushButton *minus_NumKBBut;
    QPushButton *devide_NumKBBut;
    QPushButton *multiple_NumKBBut;
    QPushButton *Esc_NumKBBut;
    QPushButton *add_NumKBBut;
    QPushButton *enter_NumKBBut;
    QPushButton *backspace_NumKBBut;

    void setupUi(QWidget *numkeyboard)
    {
        if (numkeyboard->objectName().isEmpty())
            numkeyboard->setObjectName(QStringLiteral("numkeyboard"));
        numkeyboard->resize(271, 301);
        backgroundNumKBLabel = new QLabel(numkeyboard);
        backgroundNumKBLabel->setObjectName(QStringLiteral("backgroundNumKBLabel"));
        backgroundNumKBLabel->setGeometry(QRect(0, 0, 271, 301));
        backgroundNumKBLabel->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        three_NumKBBut = new QPushButton(numkeyboard);
        three_NumKBBut->setObjectName(QStringLiteral("three_NumKBBut"));
        three_NumKBBut->setGeometry(QRect(142, 190, 52, 52));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        three_NumKBBut->setFont(font);
        three_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        two_NumKBBut = new QPushButton(numkeyboard);
        two_NumKBBut->setObjectName(QStringLiteral("two_NumKBBut"));
        two_NumKBBut->setGeometry(QRect(77, 190, 52, 52));
        two_NumKBBut->setFont(font);
        two_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        one_NumKBBut = new QPushButton(numkeyboard);
        one_NumKBBut->setObjectName(QStringLiteral("one_NumKBBut"));
        one_NumKBBut->setGeometry(QRect(13, 190, 52, 52));
        one_NumKBBut->setFont(font);
        one_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        six_NumKBBut = new QPushButton(numkeyboard);
        six_NumKBBut->setObjectName(QStringLiteral("six_NumKBBut"));
        six_NumKBBut->setGeometry(QRect(142, 129, 52, 52));
        six_NumKBBut->setFont(font);
        six_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        four_NumKBBut = new QPushButton(numkeyboard);
        four_NumKBBut->setObjectName(QStringLiteral("four_NumKBBut"));
        four_NumKBBut->setGeometry(QRect(13, 129, 52, 52));
        four_NumKBBut->setFont(font);
        four_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        five_NumKBBut = new QPushButton(numkeyboard);
        five_NumKBBut->setObjectName(QStringLiteral("five_NumKBBut"));
        five_NumKBBut->setGeometry(QRect(77, 129, 52, 52));
        five_NumKBBut->setFont(font);
        five_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        nine_NumKBBut = new QPushButton(numkeyboard);
        nine_NumKBBut->setObjectName(QStringLiteral("nine_NumKBBut"));
        nine_NumKBBut->setGeometry(QRect(142, 69, 52, 52));
        nine_NumKBBut->setFont(font);
        nine_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        eight_NumKBBut = new QPushButton(numkeyboard);
        eight_NumKBBut->setObjectName(QStringLiteral("eight_NumKBBut"));
        eight_NumKBBut->setGeometry(QRect(77, 69, 52, 52));
        eight_NumKBBut->setFont(font);
        eight_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        seven_NumKBBut = new QPushButton(numkeyboard);
        seven_NumKBBut->setObjectName(QStringLiteral("seven_NumKBBut"));
        seven_NumKBBut->setGeometry(QRect(13, 69, 52, 52));
        seven_NumKBBut->setFont(font);
        seven_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        zero_NumKBBut = new QPushButton(numkeyboard);
        zero_NumKBBut->setObjectName(QStringLiteral("zero_NumKBBut"));
        zero_NumKBBut->setGeometry(QRect(77, 250, 116, 52));
        zero_NumKBBut->setFont(font);
        zero_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        period_NumKBBut = new QPushButton(numkeyboard);
        period_NumKBBut->setObjectName(QStringLiteral("period_NumKBBut"));
        period_NumKBBut->setGeometry(QRect(13, 250, 52, 52));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        period_NumKBBut->setFont(font1);
        period_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        minus_NumKBBut = new QPushButton(numkeyboard);
        minus_NumKBBut->setObjectName(QStringLiteral("minus_NumKBBut"));
        minus_NumKBBut->setGeometry(QRect(206, 69, 52, 52));
        minus_NumKBBut->setFont(font);
        minus_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        devide_NumKBBut = new QPushButton(numkeyboard);
        devide_NumKBBut->setObjectName(QStringLiteral("devide_NumKBBut"));
        devide_NumKBBut->setGeometry(QRect(77, 8, 52, 52));
        devide_NumKBBut->setFont(font);
        devide_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        multiple_NumKBBut = new QPushButton(numkeyboard);
        multiple_NumKBBut->setObjectName(QStringLiteral("multiple_NumKBBut"));
        multiple_NumKBBut->setGeometry(QRect(142, 8, 52, 52));
        multiple_NumKBBut->setFont(font);
        multiple_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        Esc_NumKBBut = new QPushButton(numkeyboard);
        Esc_NumKBBut->setObjectName(QStringLiteral("Esc_NumKBBut"));
        Esc_NumKBBut->setGeometry(QRect(13, 8, 52, 52));
        Esc_NumKBBut->setFont(font);
        Esc_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        add_NumKBBut = new QPushButton(numkeyboard);
        add_NumKBBut->setObjectName(QStringLiteral("add_NumKBBut"));
        add_NumKBBut->setGeometry(QRect(206, 129, 52, 52));
        add_NumKBBut->setFont(font);
        add_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        enter_NumKBBut = new QPushButton(numkeyboard);
        enter_NumKBBut->setObjectName(QStringLiteral("enter_NumKBBut"));
        enter_NumKBBut->setGeometry(QRect(206, 190, 52, 112));
        enter_NumKBBut->setFont(font);
        enter_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        backspace_NumKBBut = new QPushButton(numkeyboard);
        backspace_NumKBBut->setObjectName(QStringLiteral("backspace_NumKBBut"));
        backspace_NumKBBut->setGeometry(QRect(206, 8, 52, 52));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(16);
        backspace_NumKBBut->setFont(font2);
        backspace_NumKBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));

        retranslateUi(numkeyboard);

        QMetaObject::connectSlotsByName(numkeyboard);
    } // setupUi

    void retranslateUi(QWidget *numkeyboard)
    {
        numkeyboard->setWindowTitle(QApplication::translate("numkeyboard", "numkeyboard", 0));
        backgroundNumKBLabel->setText(QString());
        three_NumKBBut->setText(QApplication::translate("numkeyboard", "3", 0));
        two_NumKBBut->setText(QApplication::translate("numkeyboard", "2", 0));
        one_NumKBBut->setText(QApplication::translate("numkeyboard", "1", 0));
        six_NumKBBut->setText(QApplication::translate("numkeyboard", "6", 0));
        four_NumKBBut->setText(QApplication::translate("numkeyboard", "4", 0));
        five_NumKBBut->setText(QApplication::translate("numkeyboard", "5", 0));
        nine_NumKBBut->setText(QApplication::translate("numkeyboard", "9", 0));
        eight_NumKBBut->setText(QApplication::translate("numkeyboard", "8", 0));
        seven_NumKBBut->setText(QApplication::translate("numkeyboard", "7", 0));
        zero_NumKBBut->setText(QApplication::translate("numkeyboard", "0", 0));
        period_NumKBBut->setText(QApplication::translate("numkeyboard", ".", 0));
        minus_NumKBBut->setText(QApplication::translate("numkeyboard", "-", 0));
        devide_NumKBBut->setText(QApplication::translate("numkeyboard", "/", 0));
        multiple_NumKBBut->setText(QApplication::translate("numkeyboard", "*", 0));
        Esc_NumKBBut->setText(QApplication::translate("numkeyboard", "Esc", 0));
        add_NumKBBut->setText(QApplication::translate("numkeyboard", "+", 0));
        enter_NumKBBut->setText(QApplication::translate("numkeyboard", "\342\206\265", 0));
        backspace_NumKBBut->setText(QApplication::translate("numkeyboard", "\342\206\220", 0));
    } // retranslateUi

};

namespace Ui {
    class numkeyboard: public Ui_numkeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMKEYBOARD_H
