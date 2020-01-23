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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keyboard
{
public:
    QPushButton *Q_KBBut;
    QPushButton *A_KBBut;
    QPushButton *shift_KBBut;
    QPushButton *space_KBBut;
    QPushButton *one_KBBut;
    QPushButton *two_KBBut;
    QPushButton *three_KBBut;
    QPushButton *four_KBBut;
    QPushButton *five_KBBut;
    QPushButton *six_KBBut;
    QPushButton *seven_KBBut;
    QPushButton *eight_KBBut;
    QPushButton *nine_KBBut;
    QPushButton *zero_KBBut;
    QPushButton *backspace_KBBut;
    QPushButton *I_KBBut;
    QPushButton *W_KBBut;
    QPushButton *O_KBBut;
    QPushButton *T_KBBut;
    QPushButton *R_KBBut;
    QPushButton *P_KBBut;
    QPushButton *Y_KBBut;
    QPushButton *E_KBBut;
    QPushButton *U_KBBut;
    QPushButton *S_KBBut;
    QPushButton *D_KBBut;
    QPushButton *F_KBBut;
    QPushButton *G_KBBut;
    QPushButton *H_KBBut;
    QPushButton *J_KBBut;
    QPushButton *K_KBBut;
    QPushButton *L_KBBut;
    QPushButton *enter_KBBut;
    QPushButton *N_KBBut;
    QPushButton *C_KBBut;
    QPushButton *B_KBBut;
    QPushButton *symbol_KBBut;
    QPushButton *X_KBBut;
    QPushButton *V_KBBut;
    QPushButton *M_KBBut;
    QPushButton *Z_KBBut;
    QPushButton *period_KBBut;
    QPushButton *comma_KBBut;
    QPushButton *language_KBBut;
    QPushButton *hide_KBBut;
    QPushButton *Esc_KBBut;

    void setupUi(QWidget *keyboard)
    {
        if (keyboard->objectName().isEmpty())
            keyboard->setObjectName(QStringLiteral("keyboard"));
        keyboard->resize(791, 321);
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(7);
        font.setBold(true);
        font.setWeight(75);
        keyboard->setFont(font);
        keyboard->setStyleSheet(QStringLiteral("background-color: rgb(119,117,128);"));
        Q_KBBut = new QPushButton(keyboard);
        Q_KBBut->setObjectName(QStringLiteral("Q_KBBut"));
        Q_KBBut->setGeometry(QRect(20, 105, 52, 52));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        Q_KBBut->setFont(font1);
        Q_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        A_KBBut = new QPushButton(keyboard);
        A_KBBut->setObjectName(QStringLiteral("A_KBBut"));
        A_KBBut->setGeometry(QRect(55, 158, 52, 52));
        A_KBBut->setFont(font1);
        A_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        shift_KBBut = new QPushButton(keyboard);
        shift_KBBut->setObjectName(QStringLiteral("shift_KBBut"));
        shift_KBBut->setGeometry(QRect(20, 211, 52, 52));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        shift_KBBut->setFont(font2);
        shift_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        space_KBBut = new QPushButton(keyboard);
        space_KBBut->setObjectName(QStringLiteral("space_KBBut"));
        space_KBBut->setGeometry(QRect(230, 264, 331, 52));
        space_KBBut->setFont(font1);
        space_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        one_KBBut = new QPushButton(keyboard);
        one_KBBut->setObjectName(QStringLiteral("one_KBBut"));
        one_KBBut->setGeometry(QRect(90, 50, 52, 52));
        one_KBBut->setFont(font1);
        one_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        two_KBBut = new QPushButton(keyboard);
        two_KBBut->setObjectName(QStringLiteral("two_KBBut"));
        two_KBBut->setGeometry(QRect(160, 50, 52, 52));
        two_KBBut->setFont(font1);
        two_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        three_KBBut = new QPushButton(keyboard);
        three_KBBut->setObjectName(QStringLiteral("three_KBBut"));
        three_KBBut->setGeometry(QRect(230, 50, 52, 52));
        three_KBBut->setFont(font1);
        three_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        four_KBBut = new QPushButton(keyboard);
        four_KBBut->setObjectName(QStringLiteral("four_KBBut"));
        four_KBBut->setGeometry(QRect(300, 50, 52, 52));
        four_KBBut->setFont(font1);
        four_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        five_KBBut = new QPushButton(keyboard);
        five_KBBut->setObjectName(QStringLiteral("five_KBBut"));
        five_KBBut->setGeometry(QRect(370, 50, 52, 52));
        five_KBBut->setFont(font1);
        five_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        six_KBBut = new QPushButton(keyboard);
        six_KBBut->setObjectName(QStringLiteral("six_KBBut"));
        six_KBBut->setGeometry(QRect(440, 50, 52, 52));
        six_KBBut->setFont(font1);
        six_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        seven_KBBut = new QPushButton(keyboard);
        seven_KBBut->setObjectName(QStringLiteral("seven_KBBut"));
        seven_KBBut->setGeometry(QRect(510, 50, 52, 52));
        seven_KBBut->setFont(font1);
        seven_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        eight_KBBut = new QPushButton(keyboard);
        eight_KBBut->setObjectName(QStringLiteral("eight_KBBut"));
        eight_KBBut->setGeometry(QRect(580, 50, 52, 52));
        eight_KBBut->setFont(font1);
        eight_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        nine_KBBut = new QPushButton(keyboard);
        nine_KBBut->setObjectName(QStringLiteral("nine_KBBut"));
        nine_KBBut->setGeometry(QRect(650, 50, 52, 52));
        nine_KBBut->setFont(font1);
        nine_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        zero_KBBut = new QPushButton(keyboard);
        zero_KBBut->setObjectName(QStringLiteral("zero_KBBut"));
        zero_KBBut->setGeometry(QRect(720, 50, 52, 52));
        zero_KBBut->setFont(font1);
        zero_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        backspace_KBBut = new QPushButton(keyboard);
        backspace_KBBut->setObjectName(QStringLiteral("backspace_KBBut"));
        backspace_KBBut->setGeometry(QRect(720, 105, 52, 52));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(16);
        backspace_KBBut->setFont(font3);
        backspace_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        I_KBBut = new QPushButton(keyboard);
        I_KBBut->setObjectName(QStringLiteral("I_KBBut"));
        I_KBBut->setGeometry(QRect(510, 105, 52, 52));
        I_KBBut->setFont(font1);
        I_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        W_KBBut = new QPushButton(keyboard);
        W_KBBut->setObjectName(QStringLiteral("W_KBBut"));
        W_KBBut->setGeometry(QRect(90, 105, 52, 52));
        W_KBBut->setFont(font1);
        W_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        O_KBBut = new QPushButton(keyboard);
        O_KBBut->setObjectName(QStringLiteral("O_KBBut"));
        O_KBBut->setGeometry(QRect(580, 105, 52, 52));
        O_KBBut->setFont(font1);
        O_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        T_KBBut = new QPushButton(keyboard);
        T_KBBut->setObjectName(QStringLiteral("T_KBBut"));
        T_KBBut->setGeometry(QRect(300, 105, 52, 52));
        T_KBBut->setFont(font1);
        T_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        R_KBBut = new QPushButton(keyboard);
        R_KBBut->setObjectName(QStringLiteral("R_KBBut"));
        R_KBBut->setGeometry(QRect(230, 105, 52, 52));
        R_KBBut->setFont(font1);
        R_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        P_KBBut = new QPushButton(keyboard);
        P_KBBut->setObjectName(QStringLiteral("P_KBBut"));
        P_KBBut->setGeometry(QRect(650, 105, 52, 52));
        P_KBBut->setFont(font1);
        P_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        Y_KBBut = new QPushButton(keyboard);
        Y_KBBut->setObjectName(QStringLiteral("Y_KBBut"));
        Y_KBBut->setGeometry(QRect(370, 105, 52, 52));
        Y_KBBut->setFont(font1);
        Y_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        E_KBBut = new QPushButton(keyboard);
        E_KBBut->setObjectName(QStringLiteral("E_KBBut"));
        E_KBBut->setGeometry(QRect(160, 105, 52, 52));
        E_KBBut->setFont(font1);
        E_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        U_KBBut = new QPushButton(keyboard);
        U_KBBut->setObjectName(QStringLiteral("U_KBBut"));
        U_KBBut->setGeometry(QRect(440, 105, 52, 52));
        U_KBBut->setFont(font1);
        U_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        S_KBBut = new QPushButton(keyboard);
        S_KBBut->setObjectName(QStringLiteral("S_KBBut"));
        S_KBBut->setGeometry(QRect(125, 158, 52, 52));
        S_KBBut->setFont(font1);
        S_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        D_KBBut = new QPushButton(keyboard);
        D_KBBut->setObjectName(QStringLiteral("D_KBBut"));
        D_KBBut->setGeometry(QRect(195, 158, 52, 52));
        D_KBBut->setFont(font1);
        D_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        F_KBBut = new QPushButton(keyboard);
        F_KBBut->setObjectName(QStringLiteral("F_KBBut"));
        F_KBBut->setGeometry(QRect(265, 158, 52, 52));
        F_KBBut->setFont(font1);
        F_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        G_KBBut = new QPushButton(keyboard);
        G_KBBut->setObjectName(QStringLiteral("G_KBBut"));
        G_KBBut->setGeometry(QRect(335, 158, 52, 52));
        G_KBBut->setFont(font1);
        G_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        H_KBBut = new QPushButton(keyboard);
        H_KBBut->setObjectName(QStringLiteral("H_KBBut"));
        H_KBBut->setGeometry(QRect(405, 158, 52, 52));
        H_KBBut->setFont(font1);
        H_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        J_KBBut = new QPushButton(keyboard);
        J_KBBut->setObjectName(QStringLiteral("J_KBBut"));
        J_KBBut->setGeometry(QRect(475, 158, 52, 52));
        J_KBBut->setFont(font1);
        J_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        K_KBBut = new QPushButton(keyboard);
        K_KBBut->setObjectName(QStringLiteral("K_KBBut"));
        K_KBBut->setGeometry(QRect(545, 158, 52, 52));
        K_KBBut->setFont(font1);
        K_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        L_KBBut = new QPushButton(keyboard);
        L_KBBut->setObjectName(QStringLiteral("L_KBBut"));
        L_KBBut->setGeometry(QRect(615, 158, 52, 52));
        L_KBBut->setFont(font1);
        L_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        enter_KBBut = new QPushButton(keyboard);
        enter_KBBut->setObjectName(QStringLiteral("enter_KBBut"));
        enter_KBBut->setGeometry(QRect(685, 158, 87, 52));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setWeight(75);
        enter_KBBut->setFont(font4);
        enter_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        N_KBBut = new QPushButton(keyboard);
        N_KBBut->setObjectName(QStringLiteral("N_KBBut"));
        N_KBBut->setGeometry(QRect(440, 211, 52, 52));
        N_KBBut->setFont(font1);
        N_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        C_KBBut = new QPushButton(keyboard);
        C_KBBut->setObjectName(QStringLiteral("C_KBBut"));
        C_KBBut->setGeometry(QRect(230, 211, 52, 52));
        C_KBBut->setFont(font1);
        C_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        B_KBBut = new QPushButton(keyboard);
        B_KBBut->setObjectName(QStringLiteral("B_KBBut"));
        B_KBBut->setGeometry(QRect(370, 211, 52, 52));
        B_KBBut->setFont(font1);
        B_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        symbol_KBBut = new QPushButton(keyboard);
        symbol_KBBut->setObjectName(QStringLiteral("symbol_KBBut"));
        symbol_KBBut->setGeometry(QRect(720, 211, 52, 52));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(12);
        symbol_KBBut->setFont(font5);
        symbol_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        X_KBBut = new QPushButton(keyboard);
        X_KBBut->setObjectName(QStringLiteral("X_KBBut"));
        X_KBBut->setGeometry(QRect(160, 211, 52, 52));
        X_KBBut->setFont(font1);
        X_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        V_KBBut = new QPushButton(keyboard);
        V_KBBut->setObjectName(QStringLiteral("V_KBBut"));
        V_KBBut->setGeometry(QRect(300, 211, 52, 52));
        V_KBBut->setFont(font1);
        V_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        M_KBBut = new QPushButton(keyboard);
        M_KBBut->setObjectName(QStringLiteral("M_KBBut"));
        M_KBBut->setGeometry(QRect(510, 211, 52, 52));
        M_KBBut->setFont(font1);
        M_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        Z_KBBut = new QPushButton(keyboard);
        Z_KBBut->setObjectName(QStringLiteral("Z_KBBut"));
        Z_KBBut->setGeometry(QRect(90, 211, 52, 52));
        Z_KBBut->setFont(font1);
        Z_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        period_KBBut = new QPushButton(keyboard);
        period_KBBut->setObjectName(QStringLiteral("period_KBBut"));
        period_KBBut->setGeometry(QRect(650, 211, 52, 52));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font6.setPointSize(18);
        font6.setBold(true);
        font6.setWeight(75);
        period_KBBut->setFont(font6);
        period_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        comma_KBBut = new QPushButton(keyboard);
        comma_KBBut->setObjectName(QStringLiteral("comma_KBBut"));
        comma_KBBut->setGeometry(QRect(580, 211, 52, 52));
        comma_KBBut->setFont(font6);
        comma_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        language_KBBut = new QPushButton(keyboard);
        language_KBBut->setObjectName(QStringLiteral("language_KBBut"));
        language_KBBut->setGeometry(QRect(131, 264, 81, 52));
        language_KBBut->setFont(font1);
        language_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        hide_KBBut = new QPushButton(keyboard);
        hide_KBBut->setObjectName(QStringLiteral("hide_KBBut"));
        hide_KBBut->setGeometry(QRect(580, 264, 81, 52));
        hide_KBBut->setFont(font1);
        hide_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        Esc_KBBut = new QPushButton(keyboard);
        Esc_KBBut->setObjectName(QStringLiteral("Esc_KBBut"));
        Esc_KBBut->setGeometry(QRect(20, 50, 52, 52));
        Esc_KBBut->setFont(font1);
        Esc_KBBut->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));

        retranslateUi(keyboard);

        QMetaObject::connectSlotsByName(keyboard);
    } // setupUi

    void retranslateUi(QWidget *keyboard)
    {
        keyboard->setWindowTitle(QApplication::translate("keyboard", "keyboard", 0));
        Q_KBBut->setText(QApplication::translate("keyboard", "Q", 0));
        A_KBBut->setText(QApplication::translate("keyboard", "A", 0));
        shift_KBBut->setText(QApplication::translate("keyboard", "\342\207\221", 0));
        space_KBBut->setText(QApplication::translate("keyboard", "Space", 0));
        one_KBBut->setText(QApplication::translate("keyboard", "1", 0));
        two_KBBut->setText(QApplication::translate("keyboard", "2", 0));
        three_KBBut->setText(QApplication::translate("keyboard", "3", 0));
        four_KBBut->setText(QApplication::translate("keyboard", "4", 0));
        five_KBBut->setText(QApplication::translate("keyboard", "5", 0));
        six_KBBut->setText(QApplication::translate("keyboard", "6", 0));
        seven_KBBut->setText(QApplication::translate("keyboard", "7", 0));
        eight_KBBut->setText(QApplication::translate("keyboard", "8", 0));
        nine_KBBut->setText(QApplication::translate("keyboard", "9", 0));
        zero_KBBut->setText(QApplication::translate("keyboard", "0", 0));
        backspace_KBBut->setText(QApplication::translate("keyboard", "\342\206\220", 0));
        I_KBBut->setText(QApplication::translate("keyboard", "I", 0));
        W_KBBut->setText(QApplication::translate("keyboard", "W", 0));
        O_KBBut->setText(QApplication::translate("keyboard", "O", 0));
        T_KBBut->setText(QApplication::translate("keyboard", "T", 0));
        R_KBBut->setText(QApplication::translate("keyboard", "R", 0));
        P_KBBut->setText(QApplication::translate("keyboard", "P", 0));
        Y_KBBut->setText(QApplication::translate("keyboard", "Y", 0));
        E_KBBut->setText(QApplication::translate("keyboard", "E", 0));
        U_KBBut->setText(QApplication::translate("keyboard", "U", 0));
        S_KBBut->setText(QApplication::translate("keyboard", "S", 0));
        D_KBBut->setText(QApplication::translate("keyboard", "D", 0));
        F_KBBut->setText(QApplication::translate("keyboard", "F", 0));
        G_KBBut->setText(QApplication::translate("keyboard", "G", 0));
        H_KBBut->setText(QApplication::translate("keyboard", "H", 0));
        J_KBBut->setText(QApplication::translate("keyboard", "J", 0));
        K_KBBut->setText(QApplication::translate("keyboard", "K", 0));
        L_KBBut->setText(QApplication::translate("keyboard", "L", 0));
        enter_KBBut->setText(QApplication::translate("keyboard", "\342\206\265", 0));
        N_KBBut->setText(QApplication::translate("keyboard", "N", 0));
        C_KBBut->setText(QApplication::translate("keyboard", "C", 0));
        B_KBBut->setText(QApplication::translate("keyboard", "B", 0));
        symbol_KBBut->setText(QApplication::translate("keyboard", "Sym", 0));
        X_KBBut->setText(QApplication::translate("keyboard", "X", 0));
        V_KBBut->setText(QApplication::translate("keyboard", "V", 0));
        M_KBBut->setText(QApplication::translate("keyboard", "M", 0));
        Z_KBBut->setText(QApplication::translate("keyboard", "Z", 0));
        period_KBBut->setText(QApplication::translate("keyboard", ".", 0));
        comma_KBBut->setText(QApplication::translate("keyboard", ",", 0));
        language_KBBut->setText(QApplication::translate("keyboard", "\360\237\214\220", 0));
        hide_KBBut->setText(QString());
        Esc_KBBut->setText(QApplication::translate("keyboard", "Esc", 0));
    } // retranslateUi

};

namespace Ui {
    class keyboard: public Ui_keyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
