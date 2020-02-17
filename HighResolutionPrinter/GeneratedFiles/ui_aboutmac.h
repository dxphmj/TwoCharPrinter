/********************************************************************************
** Form generated from reading UI file 'aboutmac.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTMAC_H
#define UI_ABOUTMAC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutMac
{
public:
    QLabel *aboutMacBGLab;
    QLabel *jetCodeIDShowLab;
    QLabel *jetCodeIDLab;
    QLabel *mainBoardIDShowLab;
    QLabel *mainBoardIDLab;
    QLabel *boardHardVersionLab;
    QLabel *boardHardUpdateLab;
    QLabel *boardSoftVersionLab;
    QLabel *boardSoftUpdateLab;
    QLabel *sysSoftVersionLab;
    QLabel *sysSoftUpdateLab;
    QLabel *jetCodeShowLab;
    QLabel *jetCodeLab;
    QLabel *boardHardUpdateShowLab;
    QLabel *boardHardVersionShowLab;
    QLabel *boardSoftVersionShowLab;
    QLabel *boardSoftUpdateShowLab;
    QLabel *sysSoftVersionShowLab;
    QLabel *sysSoftUpdateShowLab;

    void setupUi(QWidget *aboutMac)
    {
        if (aboutMac->objectName().isEmpty())
            aboutMac->setObjectName(QStringLiteral("aboutMac"));
        aboutMac->resize(1061, 651);
        aboutMacBGLab = new QLabel(aboutMac);
        aboutMacBGLab->setObjectName(QStringLiteral("aboutMacBGLab"));
        aboutMacBGLab->setGeometry(QRect(0, 0, 1061, 651));
        aboutMacBGLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        jetCodeIDShowLab = new QLabel(aboutMac);
        jetCodeIDShowLab->setObjectName(QStringLiteral("jetCodeIDShowLab"));
        jetCodeIDShowLab->setGeometry(QRect(480, 160, 241, 41));
        jetCodeIDShowLab->setMinimumSize(QSize(0, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        jetCodeIDShowLab->setFont(font);
        jetCodeIDShowLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        jetCodeIDShowLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        jetCodeIDLab = new QLabel(aboutMac);
        jetCodeIDLab->setObjectName(QStringLiteral("jetCodeIDLab"));
        jetCodeIDLab->setGeometry(QRect(210, 160, 241, 41));
        jetCodeIDLab->setMinimumSize(QSize(0, 41));
        jetCodeIDLab->setFont(font);
        jetCodeIDLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        jetCodeIDLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        mainBoardIDShowLab = new QLabel(aboutMac);
        mainBoardIDShowLab->setObjectName(QStringLiteral("mainBoardIDShowLab"));
        mainBoardIDShowLab->setGeometry(QRect(480, 210, 241, 41));
        mainBoardIDShowLab->setMinimumSize(QSize(0, 41));
        mainBoardIDShowLab->setFont(font);
        mainBoardIDShowLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        mainBoardIDShowLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        mainBoardIDLab = new QLabel(aboutMac);
        mainBoardIDLab->setObjectName(QStringLiteral("mainBoardIDLab"));
        mainBoardIDLab->setGeometry(QRect(210, 210, 241, 41));
        mainBoardIDLab->setMinimumSize(QSize(0, 41));
        mainBoardIDLab->setFont(font);
        mainBoardIDLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        mainBoardIDLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        boardHardVersionLab = new QLabel(aboutMac);
        boardHardVersionLab->setObjectName(QStringLiteral("boardHardVersionLab"));
        boardHardVersionLab->setGeometry(QRect(210, 260, 241, 41));
        boardHardVersionLab->setMinimumSize(QSize(0, 41));
        boardHardVersionLab->setFont(font);
        boardHardVersionLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        boardHardVersionLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        boardHardUpdateLab = new QLabel(aboutMac);
        boardHardUpdateLab->setObjectName(QStringLiteral("boardHardUpdateLab"));
        boardHardUpdateLab->setGeometry(QRect(210, 310, 241, 41));
        boardHardUpdateLab->setMinimumSize(QSize(0, 41));
        boardHardUpdateLab->setFont(font);
        boardHardUpdateLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        boardHardUpdateLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        boardSoftVersionLab = new QLabel(aboutMac);
        boardSoftVersionLab->setObjectName(QStringLiteral("boardSoftVersionLab"));
        boardSoftVersionLab->setGeometry(QRect(210, 360, 241, 41));
        boardSoftVersionLab->setMinimumSize(QSize(0, 41));
        boardSoftVersionLab->setFont(font);
        boardSoftVersionLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        boardSoftVersionLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        boardSoftUpdateLab = new QLabel(aboutMac);
        boardSoftUpdateLab->setObjectName(QStringLiteral("boardSoftUpdateLab"));
        boardSoftUpdateLab->setGeometry(QRect(210, 410, 241, 41));
        boardSoftUpdateLab->setMinimumSize(QSize(0, 41));
        boardSoftUpdateLab->setFont(font);
        boardSoftUpdateLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        boardSoftUpdateLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sysSoftVersionLab = new QLabel(aboutMac);
        sysSoftVersionLab->setObjectName(QStringLiteral("sysSoftVersionLab"));
        sysSoftVersionLab->setGeometry(QRect(210, 460, 241, 41));
        sysSoftVersionLab->setMinimumSize(QSize(0, 41));
        sysSoftVersionLab->setFont(font);
        sysSoftVersionLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        sysSoftVersionLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sysSoftUpdateLab = new QLabel(aboutMac);
        sysSoftUpdateLab->setObjectName(QStringLiteral("sysSoftUpdateLab"));
        sysSoftUpdateLab->setGeometry(QRect(210, 510, 241, 41));
        sysSoftUpdateLab->setMinimumSize(QSize(0, 41));
        sysSoftUpdateLab->setFont(font);
        sysSoftUpdateLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        sysSoftUpdateLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        jetCodeShowLab = new QLabel(aboutMac);
        jetCodeShowLab->setObjectName(QStringLiteral("jetCodeShowLab"));
        jetCodeShowLab->setGeometry(QRect(480, 110, 241, 41));
        jetCodeShowLab->setMinimumSize(QSize(0, 41));
        jetCodeShowLab->setFont(font);
        jetCodeShowLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        jetCodeShowLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        jetCodeLab = new QLabel(aboutMac);
        jetCodeLab->setObjectName(QStringLiteral("jetCodeLab"));
        jetCodeLab->setGeometry(QRect(210, 110, 241, 41));
        jetCodeLab->setMinimumSize(QSize(0, 41));
        jetCodeLab->setFont(font);
        jetCodeLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        jetCodeLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        boardHardUpdateShowLab = new QLabel(aboutMac);
        boardHardUpdateShowLab->setObjectName(QStringLiteral("boardHardUpdateShowLab"));
        boardHardUpdateShowLab->setGeometry(QRect(480, 310, 241, 41));
        boardHardUpdateShowLab->setMinimumSize(QSize(0, 41));
        boardHardUpdateShowLab->setFont(font);
        boardHardUpdateShowLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        boardHardUpdateShowLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        boardHardVersionShowLab = new QLabel(aboutMac);
        boardHardVersionShowLab->setObjectName(QStringLiteral("boardHardVersionShowLab"));
        boardHardVersionShowLab->setGeometry(QRect(480, 260, 241, 41));
        boardHardVersionShowLab->setMinimumSize(QSize(0, 41));
        boardHardVersionShowLab->setFont(font);
        boardHardVersionShowLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        boardHardVersionShowLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        boardSoftVersionShowLab = new QLabel(aboutMac);
        boardSoftVersionShowLab->setObjectName(QStringLiteral("boardSoftVersionShowLab"));
        boardSoftVersionShowLab->setGeometry(QRect(480, 360, 241, 41));
        boardSoftVersionShowLab->setMinimumSize(QSize(0, 41));
        boardSoftVersionShowLab->setFont(font);
        boardSoftVersionShowLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        boardSoftVersionShowLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        boardSoftUpdateShowLab = new QLabel(aboutMac);
        boardSoftUpdateShowLab->setObjectName(QStringLiteral("boardSoftUpdateShowLab"));
        boardSoftUpdateShowLab->setGeometry(QRect(480, 410, 241, 41));
        boardSoftUpdateShowLab->setMinimumSize(QSize(0, 41));
        boardSoftUpdateShowLab->setFont(font);
        boardSoftUpdateShowLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        boardSoftUpdateShowLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        sysSoftVersionShowLab = new QLabel(aboutMac);
        sysSoftVersionShowLab->setObjectName(QStringLiteral("sysSoftVersionShowLab"));
        sysSoftVersionShowLab->setGeometry(QRect(480, 460, 241, 41));
        sysSoftVersionShowLab->setMinimumSize(QSize(0, 41));
        sysSoftVersionShowLab->setFont(font);
        sysSoftVersionShowLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        sysSoftVersionShowLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        sysSoftUpdateShowLab = new QLabel(aboutMac);
        sysSoftUpdateShowLab->setObjectName(QStringLiteral("sysSoftUpdateShowLab"));
        sysSoftUpdateShowLab->setGeometry(QRect(480, 510, 241, 41));
        sysSoftUpdateShowLab->setMinimumSize(QSize(0, 41));
        sysSoftUpdateShowLab->setFont(font);
        sysSoftUpdateShowLab->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        sysSoftUpdateShowLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(aboutMac);

        QMetaObject::connectSlotsByName(aboutMac);
    } // setupUi

    void retranslateUi(QWidget *aboutMac)
    {
        aboutMac->setWindowTitle(QApplication::translate("aboutMac", "aboutMac", 0));
        aboutMacBGLab->setText(QString());
        jetCodeIDShowLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">NO633101</span></p></body></html>", 0));
        jetCodeIDLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\226\267\347\240\201\346\234\272ID</span></p></body></html>", 0));
        mainBoardIDShowLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">202002161724</span></p></body></html>", 0));
        mainBoardIDLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">\344\270\273\346\235\277ID</span></p></body></html>", 0));
        boardHardVersionLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">\344\270\273\346\235\277\347\241\254\344\273\266\347\211\210\346\234\254</span></p></body></html>", 0));
        boardHardUpdateLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\233\264\346\226\260\346\227\266\351\227\264</span></p></body></html>", 0));
        boardSoftVersionLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">\344\270\273\346\235\277\350\275\257\344\273\266\347\211\210\346\234\254</span></p></body></html>", 0));
        boardSoftUpdateLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\233\264\346\226\260\346\227\266\351\227\264</span></p></body></html>", 0));
        sysSoftVersionLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\263\273\347\273\237\350\275\257\344\273\266\347\211\210\346\234\254</span></p></body></html>", 0));
        sysSoftUpdateLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\233\264\346\226\260\346\227\266\351\227\264</span></p></body></html>", 0));
        jetCodeShowLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">C200</span></p></body></html>", 0));
        jetCodeLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\226\267\347\240\201\346\234\272\345\236\213\345\217\267</span></p></body></html>", 0));
        boardHardUpdateShowLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">202002020</span></p></body></html>", 0));
        boardHardVersionShowLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">1.0.1</span></p></body></html>", 0));
        boardSoftVersionShowLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">1.0.1</span></p></body></html>", 0));
        boardSoftUpdateShowLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">202002020</span></p></body></html>", 0));
        sysSoftVersionShowLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">2.0.1</span></p></body></html>", 0));
        sysSoftUpdateShowLab->setText(QApplication::translate("aboutMac", "<html><head/><body><p><span style=\" color:#ffffff;\">202002020</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class aboutMac: public Ui_aboutMac {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTMAC_H
