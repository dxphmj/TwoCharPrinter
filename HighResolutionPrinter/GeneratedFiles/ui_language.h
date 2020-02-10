/********************************************************************************
** Form generated from reading UI file 'language.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGE_H
#define UI_LANGUAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_language
{
public:
    QPushButton *LanEnglish;
    QPushButton *LanChinese;
    QPushButton *LanArabic;
    QPushButton *LanCzech;
    QPushButton *LanDutch;
    QPushButton *LanHindi;
    QPushButton *LanFarsi;
    QPushButton *LanGerman;
    QPushButton *LanFinnish;
    QPushButton *LanHungarian;
    QPushButton *LanRussian;
    QPushButton *LanJapanese;
    QPushButton *LanKorean;
    QPushButton *LanItalian;
    QPushButton *LanPortuguese;
    QPushButton *Lan1;
    QPushButton *OKLanBut;
    QPushButton *LanThai;
    QPushButton *LanSpanish;
    QPushButton *LanSwedish;
    QLabel *backgroundLanLabel;

    void setupUi(QWidget *language)
    {
        if (language->objectName().isEmpty())
            language->setObjectName(QStringLiteral("language"));
        language->resize(727, 321);
        LanEnglish = new QPushButton(language);
        LanEnglish->setObjectName(QStringLiteral("LanEnglish"));
        LanEnglish->setGeometry(QRect(2, 3, 143, 77));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(16);
        LanEnglish->setFont(font);
        LanEnglish->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanChinese = new QPushButton(language);
        LanChinese->setObjectName(QStringLiteral("LanChinese"));
        LanChinese->setGeometry(QRect(147, 3, 143, 77));
        LanChinese->setFont(font);
        LanChinese->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanArabic = new QPushButton(language);
        LanArabic->setObjectName(QStringLiteral("LanArabic"));
        LanArabic->setGeometry(QRect(292, 3, 143, 77));
        LanArabic->setFont(font);
        LanArabic->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanCzech = new QPushButton(language);
        LanCzech->setObjectName(QStringLiteral("LanCzech"));
        LanCzech->setGeometry(QRect(437, 3, 143, 77));
        LanCzech->setFont(font);
        LanCzech->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanDutch = new QPushButton(language);
        LanDutch->setObjectName(QStringLiteral("LanDutch"));
        LanDutch->setGeometry(QRect(582, 3, 143, 77));
        LanDutch->setFont(font);
        LanDutch->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanHindi = new QPushButton(language);
        LanHindi->setObjectName(QStringLiteral("LanHindi"));
        LanHindi->setGeometry(QRect(437, 82, 143, 77));
        LanHindi->setFont(font);
        LanHindi->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanFarsi = new QPushButton(language);
        LanFarsi->setObjectName(QStringLiteral("LanFarsi"));
        LanFarsi->setGeometry(QRect(2, 82, 143, 77));
        LanFarsi->setFont(font);
        LanFarsi->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanGerman = new QPushButton(language);
        LanGerman->setObjectName(QStringLiteral("LanGerman"));
        LanGerman->setGeometry(QRect(292, 82, 143, 77));
        LanGerman->setFont(font);
        LanGerman->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanFinnish = new QPushButton(language);
        LanFinnish->setObjectName(QStringLiteral("LanFinnish"));
        LanFinnish->setGeometry(QRect(147, 82, 143, 77));
        LanFinnish->setFont(font);
        LanFinnish->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanHungarian = new QPushButton(language);
        LanHungarian->setObjectName(QStringLiteral("LanHungarian"));
        LanHungarian->setGeometry(QRect(582, 82, 143, 77));
        LanHungarian->setFont(font);
        LanHungarian->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanRussian = new QPushButton(language);
        LanRussian->setObjectName(QStringLiteral("LanRussian"));
        LanRussian->setGeometry(QRect(582, 161, 143, 77));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(14);
        LanRussian->setFont(font1);
        LanRussian->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanJapanese = new QPushButton(language);
        LanJapanese->setObjectName(QStringLiteral("LanJapanese"));
        LanJapanese->setGeometry(QRect(147, 161, 143, 77));
        LanJapanese->setFont(font);
        LanJapanese->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanKorean = new QPushButton(language);
        LanKorean->setObjectName(QStringLiteral("LanKorean"));
        LanKorean->setGeometry(QRect(292, 161, 143, 77));
        LanKorean->setFont(font);
        LanKorean->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanItalian = new QPushButton(language);
        LanItalian->setObjectName(QStringLiteral("LanItalian"));
        LanItalian->setGeometry(QRect(2, 161, 143, 77));
        LanItalian->setFont(font);
        LanItalian->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanPortuguese = new QPushButton(language);
        LanPortuguese->setObjectName(QStringLiteral("LanPortuguese"));
        LanPortuguese->setGeometry(QRect(437, 161, 143, 77));
        LanPortuguese->setFont(font);
        LanPortuguese->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        Lan1 = new QPushButton(language);
        Lan1->setObjectName(QStringLiteral("Lan1"));
        Lan1->setGeometry(QRect(437, 240, 143, 77));
        Lan1->setFont(font);
        Lan1->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        OKLanBut = new QPushButton(language);
        OKLanBut->setObjectName(QStringLiteral("OKLanBut"));
        OKLanBut->setGeometry(QRect(582, 240, 143, 77));
        OKLanBut->setFont(font);
        OKLanBut->setStyleSheet(QLatin1String("background-color: rgb(182,181,186);\n"
"color: rgb(0, 0, 0);"));
        LanThai = new QPushButton(language);
        LanThai->setObjectName(QStringLiteral("LanThai"));
        LanThai->setGeometry(QRect(292, 240, 143, 77));
        LanThai->setFont(font);
        LanThai->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanSpanish = new QPushButton(language);
        LanSpanish->setObjectName(QStringLiteral("LanSpanish"));
        LanSpanish->setGeometry(QRect(2, 240, 143, 77));
        LanSpanish->setFont(font);
        LanSpanish->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        LanSwedish = new QPushButton(language);
        LanSwedish->setObjectName(QStringLiteral("LanSwedish"));
        LanSwedish->setGeometry(QRect(147, 240, 143, 77));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(12);
        LanSwedish->setFont(font2);
        LanSwedish->setStyleSheet(QStringLiteral("background-color: rgb(182,181,186);"));
        backgroundLanLabel = new QLabel(language);
        backgroundLanLabel->setObjectName(QStringLiteral("backgroundLanLabel"));
        backgroundLanLabel->setGeometry(QRect(0, 0, 727, 321));
        backgroundLanLabel->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        backgroundLanLabel->raise();
        LanEnglish->raise();
        LanChinese->raise();
        LanArabic->raise();
        LanCzech->raise();
        LanDutch->raise();
        LanHindi->raise();
        LanFarsi->raise();
        LanGerman->raise();
        LanFinnish->raise();
        LanHungarian->raise();
        LanRussian->raise();
        LanJapanese->raise();
        LanKorean->raise();
        LanItalian->raise();
        LanPortuguese->raise();
        Lan1->raise();
        OKLanBut->raise();
        LanThai->raise();
        LanSpanish->raise();
        LanSwedish->raise();

        retranslateUi(language);

        QMetaObject::connectSlotsByName(language);
    } // setupUi

    void retranslateUi(QWidget *language)
    {
        language->setWindowTitle(QApplication::translate("language", "language", 0));
        LanEnglish->setText(QApplication::translate("language", "English", 0));
        LanChinese->setText(QApplication::translate("language", "\347\256\200\344\275\223\344\270\255\346\226\207", 0));
        LanArabic->setText(QApplication::translate("language", "\302\240\330\271\330\261\330\250\331\212 \330\214", 0));
        LanCzech->setText(QApplication::translate("language", "\304\214esko", 0));
        LanDutch->setText(QApplication::translate("language", "Dutch", 0));
        LanHindi->setText(QApplication::translate("language", "\340\244\271\340\244\277\340\244\250\340\245\215\340\244\246\340\245\200", 0));
        LanFarsi->setText(QApplication::translate("language", "\331\201\330\247\330\261\330\263\333\214\342\200\216", 0));
        LanGerman->setText(QApplication::translate("language", "Deutsch", 0));
        LanFinnish->setText(QApplication::translate("language", "Suomi", 0));
        LanHungarian->setText(QApplication::translate("language", "MagyarName", 0));
        LanRussian->setText(QApplication::translate("language", "\321\200\321\203\321\201\321\201\320\272\320\270\320\271\321\217\320\267\321\213\320\272", 0));
        LanJapanese->setText(QApplication::translate("language", "\346\227\245\346\234\254\350\252\236", 0));
        LanKorean->setText(QApplication::translate("language", "\355\225\234\352\265\255\354\226\264", 0));
        LanItalian->setText(QApplication::translate("language", "Italiano", 0));
        LanPortuguese->setText(QApplication::translate("language", "Portugu\303\252s", 0));
        Lan1->setText(QString());
        OKLanBut->setText(QApplication::translate("language", "\347\241\256\345\256\232", 0));
        LanThai->setText(QApplication::translate("language", "\340\270\240\340\270\262\340\270\251\340\270\262\340\271\204\340\270\227\340\270\242", 0));
        LanSpanish->setText(QApplication::translate("language", "Espa\303\261ol", 0));
        LanSwedish->setText(QApplication::translate("language", "Svenskt spr\303\245k", 0));
        backgroundLanLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class language: public Ui_language {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGE_H
