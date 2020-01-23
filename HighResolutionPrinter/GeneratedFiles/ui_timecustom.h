/********************************************************************************
** Form generated from reading UI file 'timecustom.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMECUSTOM_H
#define UI_TIMECUSTOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_timeCustom
{
public:
    QLabel *timePreLab;
    QLabel *datePreLab;
    QListWidget *timeTypeListWid;
    QLabel *timeTypeLab;
    QComboBox *fontDateComBox;
    QLabel *fontDateLab;
    QComboBox *offsetDateComBox;
    QLabel *offsetDateLab;
    QLabel *offsetValDateLab;
    QLineEdit *offsetValDateLineEdit;
    QLabel *offsetUnitDateLab;
    QListWidget *offsetUnitDateListWid;
    QPushButton *addTimeTypeBut;
    QPushButton *OKDateBut;
    QPushButton *cancelDateBut;

    void setupUi(QWidget *timeCustom)
    {
        if (timeCustom->objectName().isEmpty())
            timeCustom->setObjectName(QStringLiteral("timeCustom"));
        timeCustom->resize(1061, 761);
        timeCustom->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        timePreLab = new QLabel(timeCustom);
        timePreLab->setObjectName(QStringLiteral("timePreLab"));
        timePreLab->setGeometry(QRect(40, 40, 141, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        timePreLab->setFont(font);
        timePreLab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        timePreLab->setAlignment(Qt::AlignCenter);
        datePreLab = new QLabel(timeCustom);
        datePreLab->setObjectName(QStringLiteral("datePreLab"));
        datePreLab->setGeometry(QRect(190, 40, 831, 41));
        datePreLab->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        timeTypeListWid = new QListWidget(timeCustom);
        timeTypeListWid->setObjectName(QStringLiteral("timeTypeListWid"));
        timeTypeListWid->setGeometry(QRect(180, 155, 331, 491));
        timeTypeLab = new QLabel(timeCustom);
        timeTypeLab->setObjectName(QStringLiteral("timeTypeLab"));
        timeTypeLab->setGeometry(QRect(30, 385, 141, 41));
        timeTypeLab->setFont(font);
        timeTypeLab->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        timeTypeLab->setAlignment(Qt::AlignCenter);
        fontDateComBox = new QComboBox(timeCustom);
        fontDateComBox->setObjectName(QStringLiteral("fontDateComBox"));
        fontDateComBox->setGeometry(QRect(820, 170, 181, 31));
        fontDateComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontDateLab = new QLabel(timeCustom);
        fontDateLab->setObjectName(QStringLiteral("fontDateLab"));
        fontDateLab->setGeometry(QRect(720, 165, 101, 41));
        fontDateLab->setMinimumSize(QSize(101, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        fontDateLab->setFont(font1);
        fontDateLab->setAlignment(Qt::AlignCenter);
        offsetDateComBox = new QComboBox(timeCustom);
        offsetDateComBox->setObjectName(QStringLiteral("offsetDateComBox"));
        offsetDateComBox->setGeometry(QRect(820, 275, 181, 31));
        offsetDateComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        offsetDateLab = new QLabel(timeCustom);
        offsetDateLab->setObjectName(QStringLiteral("offsetDateLab"));
        offsetDateLab->setGeometry(QRect(720, 270, 101, 41));
        offsetDateLab->setMinimumSize(QSize(101, 41));
        offsetDateLab->setFont(font1);
        offsetDateLab->setAlignment(Qt::AlignCenter);
        offsetValDateLab = new QLabel(timeCustom);
        offsetValDateLab->setObjectName(QStringLiteral("offsetValDateLab"));
        offsetValDateLab->setGeometry(QRect(720, 365, 101, 41));
        offsetValDateLab->setMinimumSize(QSize(101, 41));
        offsetValDateLab->setFont(font1);
        offsetValDateLab->setAlignment(Qt::AlignCenter);
        offsetValDateLineEdit = new QLineEdit(timeCustom);
        offsetValDateLineEdit->setObjectName(QStringLiteral("offsetValDateLineEdit"));
        offsetValDateLineEdit->setGeometry(QRect(820, 365, 181, 41));
        offsetValDateLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        offsetUnitDateLab = new QLabel(timeCustom);
        offsetUnitDateLab->setObjectName(QStringLiteral("offsetUnitDateLab"));
        offsetUnitDateLab->setGeometry(QRect(720, 475, 101, 41));
        offsetUnitDateLab->setMinimumSize(QSize(101, 41));
        offsetUnitDateLab->setFont(font1);
        offsetUnitDateLab->setAlignment(Qt::AlignCenter);
        offsetUnitDateListWid = new QListWidget(timeCustom);
        offsetUnitDateListWid->setObjectName(QStringLiteral("offsetUnitDateListWid"));
        offsetUnitDateListWid->setGeometry(QRect(820, 465, 181, 181));
        addTimeTypeBut = new QPushButton(timeCustom);
        addTimeTypeBut->setObjectName(QStringLiteral("addTimeTypeBut"));
        addTimeTypeBut->setGeometry(QRect(530, 605, 131, 41));
        addTimeTypeBut->setFont(font);
        addTimeTypeBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        OKDateBut = new QPushButton(timeCustom);
        OKDateBut->setObjectName(QStringLiteral("OKDateBut"));
        OKDateBut->setGeometry(QRect(270, 700, 131, 41));
        OKDateBut->setFont(font);
        OKDateBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        cancelDateBut = new QPushButton(timeCustom);
        cancelDateBut->setObjectName(QStringLiteral("cancelDateBut"));
        cancelDateBut->setGeometry(QRect(700, 700, 131, 41));
        cancelDateBut->setFont(font);
        cancelDateBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));

        retranslateUi(timeCustom);

        QMetaObject::connectSlotsByName(timeCustom);
    } // setupUi

    void retranslateUi(QWidget *timeCustom)
    {
        timeCustom->setWindowTitle(QApplication::translate("timeCustom", "timeCustom", 0));
        timePreLab->setText(QApplication::translate("timeCustom", "\346\227\245\346\234\237/\346\227\266\351\227\264", 0));
        datePreLab->setText(QString());
        timeTypeLab->setText(QApplication::translate("timeCustom", "\347\261\273\345\236\213", 0));
        fontDateLab->setText(QApplication::translate("timeCustom", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\344\275\223</span></p></body></html>", 0));
        offsetDateLab->setText(QApplication::translate("timeCustom", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\201\217\347\247\273</span></p></body></html>", 0));
        offsetValDateLab->setText(QApplication::translate("timeCustom", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\201\217\347\247\273\345\200\274</span></p></body></html>", 0));
        offsetUnitDateLab->setText(QApplication::translate("timeCustom", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\201\217\347\247\273\345\215\225\344\275\215</span></p></body></html>", 0));
        addTimeTypeBut->setText(QApplication::translate("timeCustom", "ADD", 0));
        OKDateBut->setText(QApplication::translate("timeCustom", "\347\241\256\345\256\232", 0));
        cancelDateBut->setText(QApplication::translate("timeCustom", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class timeCustom: public Ui_timeCustom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMECUSTOM_H
