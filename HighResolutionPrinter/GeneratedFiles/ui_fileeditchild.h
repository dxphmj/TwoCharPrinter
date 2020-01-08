/********************************************************************************
** Form generated from reading UI file 'fileeditchild.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEEDITCHILD_H
#define UI_FILEEDITCHILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileEditChild
{
public:
    QPushButton *saveBut;
    QPushButton *editBut;
    QTextEdit *editPreviewText;
    QPushButton *saveasBut;
    QPushButton *delBut;
    QScrollBar *textpreviewScrollBar;
    QTabWidget *typeTab;
    QWidget *tab;
    QLineEdit *wordLineEdit;
    QPushButton *degreeRedBut;
    QLabel *fontTypeLab;
    QLabel *degreeShowLab;
    QLabel *rotateLab;
    QPushButton *degreeAddBut;
    QPushButton *stepAdd1But_2;
    QLabel *stepValShow1Lab_2;
    QLabel *fontSizeLab;
    QLabel *internalLab;
    QPushButton *internalAddBut;
    QPushButton *internalRedBut;
    QPushButton *stepRed1But_2;
    QLabel *currentValShow1Lab_2;
    QComboBox *comboBox;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QLineEdit *barCodeLineEdit;
    QWidget *tab_7;
    QLineEdit *QRCodeLineEdit;
    QWidget *tab_2;
    QPushButton *moveUpBut;
    QPushButton *moveRightBut;
    QPushButton *moveDownBut;
    QPushButton *moveLeftBut;

    void setupUi(QWidget *FileEditChild)
    {
        if (FileEditChild->objectName().isEmpty())
            FileEditChild->setObjectName(QStringLiteral("FileEditChild"));
        FileEditChild->resize(1061, 761);
        saveBut = new QPushButton(FileEditChild);
        saveBut->setObjectName(QStringLiteral("saveBut"));
        saveBut->setGeometry(QRect(840, 430, 101, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        saveBut->setFont(font);
        editBut = new QPushButton(FileEditChild);
        editBut->setObjectName(QStringLiteral("editBut"));
        editBut->setGeometry(QRect(840, 360, 101, 51));
        editBut->setFont(font);
        editPreviewText = new QTextEdit(FileEditChild);
        editPreviewText->setObjectName(QStringLiteral("editPreviewText"));
        editPreviewText->setGeometry(QRect(10, 10, 1041, 241));
        saveasBut = new QPushButton(FileEditChild);
        saveasBut->setObjectName(QStringLiteral("saveasBut"));
        saveasBut->setGeometry(QRect(950, 430, 101, 51));
        saveasBut->setFont(font);
        delBut = new QPushButton(FileEditChild);
        delBut->setObjectName(QStringLiteral("delBut"));
        delBut->setGeometry(QRect(950, 360, 101, 51));
        delBut->setFont(font);
        textpreviewScrollBar = new QScrollBar(FileEditChild);
        textpreviewScrollBar->setObjectName(QStringLiteral("textpreviewScrollBar"));
        textpreviewScrollBar->setGeometry(QRect(10, 250, 1041, 26));
        textpreviewScrollBar->setOrientation(Qt::Horizontal);
        typeTab = new QTabWidget(FileEditChild);
        typeTab->setObjectName(QStringLiteral("typeTab"));
        typeTab->setGeometry(QRect(10, 290, 819, 461));
        typeTab->setFont(font);
        typeTab->setStyleSheet(QLatin1String("QTabBar::tab{width:117}\n"
"QTabBar::tab{height:50}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        wordLineEdit = new QLineEdit(tab);
        wordLineEdit->setObjectName(QStringLiteral("wordLineEdit"));
        wordLineEdit->setGeometry(QRect(10, 20, 791, 51));
        degreeRedBut = new QPushButton(tab);
        degreeRedBut->setObjectName(QStringLiteral("degreeRedBut"));
        degreeRedBut->setGeometry(QRect(160, 140, 41, 41));
        degreeRedBut->setMinimumSize(QSize(41, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        degreeRedBut->setFont(font1);
        fontTypeLab = new QLabel(tab);
        fontTypeLab->setObjectName(QStringLiteral("fontTypeLab"));
        fontTypeLab->setGeometry(QRect(440, 140, 101, 41));
        fontTypeLab->setMinimumSize(QSize(101, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        fontTypeLab->setFont(font2);
        fontTypeLab->setAlignment(Qt::AlignCenter);
        degreeShowLab = new QLabel(tab);
        degreeShowLab->setObjectName(QStringLiteral("degreeShowLab"));
        degreeShowLab->setGeometry(QRect(200, 140, 131, 41));
        degreeShowLab->setMinimumSize(QSize(0, 41));
        degreeShowLab->setFont(font2);
        degreeShowLab->setAlignment(Qt::AlignCenter);
        rotateLab = new QLabel(tab);
        rotateLab->setObjectName(QStringLiteral("rotateLab"));
        rotateLab->setGeometry(QRect(60, 140, 101, 41));
        rotateLab->setMinimumSize(QSize(101, 41));
        rotateLab->setFont(font2);
        rotateLab->setAlignment(Qt::AlignCenter);
        degreeAddBut = new QPushButton(tab);
        degreeAddBut->setObjectName(QStringLiteral("degreeAddBut"));
        degreeAddBut->setGeometry(QRect(330, 140, 41, 41));
        degreeAddBut->setMinimumSize(QSize(41, 41));
        degreeAddBut->setFont(font1);
        stepAdd1But_2 = new QPushButton(tab);
        stepAdd1But_2->setObjectName(QStringLiteral("stepAdd1But_2"));
        stepAdd1But_2->setGeometry(QRect(710, 240, 41, 41));
        stepAdd1But_2->setMinimumSize(QSize(41, 41));
        stepAdd1But_2->setFont(font1);
        stepValShow1Lab_2 = new QLabel(tab);
        stepValShow1Lab_2->setObjectName(QStringLiteral("stepValShow1Lab_2"));
        stepValShow1Lab_2->setGeometry(QRect(580, 240, 131, 41));
        stepValShow1Lab_2->setMinimumSize(QSize(0, 41));
        stepValShow1Lab_2->setFont(font2);
        stepValShow1Lab_2->setAlignment(Qt::AlignCenter);
        fontSizeLab = new QLabel(tab);
        fontSizeLab->setObjectName(QStringLiteral("fontSizeLab"));
        fontSizeLab->setGeometry(QRect(440, 240, 101, 41));
        fontSizeLab->setMinimumSize(QSize(101, 41));
        fontSizeLab->setFont(font2);
        fontSizeLab->setAlignment(Qt::AlignCenter);
        internalLab = new QLabel(tab);
        internalLab->setObjectName(QStringLiteral("internalLab"));
        internalLab->setGeometry(QRect(60, 240, 101, 41));
        internalLab->setMinimumSize(QSize(101, 41));
        internalLab->setFont(font2);
        internalLab->setAlignment(Qt::AlignCenter);
        internalAddBut = new QPushButton(tab);
        internalAddBut->setObjectName(QStringLiteral("internalAddBut"));
        internalAddBut->setGeometry(QRect(330, 240, 41, 41));
        internalAddBut->setMinimumSize(QSize(41, 41));
        internalAddBut->setFont(font1);
        internalRedBut = new QPushButton(tab);
        internalRedBut->setObjectName(QStringLiteral("internalRedBut"));
        internalRedBut->setGeometry(QRect(160, 240, 41, 41));
        internalRedBut->setMinimumSize(QSize(41, 41));
        internalRedBut->setFont(font1);
        stepRed1But_2 = new QPushButton(tab);
        stepRed1But_2->setObjectName(QStringLiteral("stepRed1But_2"));
        stepRed1But_2->setGeometry(QRect(540, 240, 41, 41));
        stepRed1But_2->setMinimumSize(QSize(41, 41));
        stepRed1But_2->setFont(font1);
        currentValShow1Lab_2 = new QLabel(tab);
        currentValShow1Lab_2->setObjectName(QStringLiteral("currentValShow1Lab_2"));
        currentValShow1Lab_2->setGeometry(QRect(200, 240, 131, 41));
        currentValShow1Lab_2->setMinimumSize(QSize(0, 41));
        currentValShow1Lab_2->setFont(font2);
        currentValShow1Lab_2->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(540, 145, 151, 31));
        typeTab->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        typeTab->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        typeTab->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        typeTab->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        barCodeLineEdit = new QLineEdit(tab_6);
        barCodeLineEdit->setObjectName(QStringLiteral("barCodeLineEdit"));
        barCodeLineEdit->setGeometry(QRect(10, 20, 791, 51));
        typeTab->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        QRCodeLineEdit = new QLineEdit(tab_7);
        QRCodeLineEdit->setObjectName(QStringLiteral("QRCodeLineEdit"));
        QRCodeLineEdit->setGeometry(QRect(10, 20, 791, 51));
        typeTab->addTab(tab_7, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        typeTab->addTab(tab_2, QString());
        moveUpBut = new QPushButton(FileEditChild);
        moveUpBut->setObjectName(QStringLiteral("moveUpBut"));
        moveUpBut->setGeometry(QRect(890, 530, 101, 51));
        moveUpBut->setFont(font);
        moveRightBut = new QPushButton(FileEditChild);
        moveRightBut->setObjectName(QStringLiteral("moveRightBut"));
        moveRightBut->setGeometry(QRect(950, 600, 101, 51));
        moveRightBut->setFont(font);
        moveDownBut = new QPushButton(FileEditChild);
        moveDownBut->setObjectName(QStringLiteral("moveDownBut"));
        moveDownBut->setGeometry(QRect(890, 670, 101, 51));
        moveDownBut->setFont(font);
        moveLeftBut = new QPushButton(FileEditChild);
        moveLeftBut->setObjectName(QStringLiteral("moveLeftBut"));
        moveLeftBut->setGeometry(QRect(830, 600, 101, 51));
        moveLeftBut->setFont(font);

        retranslateUi(FileEditChild);

        typeTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FileEditChild);
    } // setupUi

    void retranslateUi(QWidget *FileEditChild)
    {
        FileEditChild->setWindowTitle(QApplication::translate("FileEditChild", "FileEditChild", 0));
        saveBut->setText(QApplication::translate("FileEditChild", "\344\277\235\345\255\230", 0));
        editBut->setText(QApplication::translate("FileEditChild", "\347\274\226\350\276\221", 0));
        saveasBut->setText(QApplication::translate("FileEditChild", "\345\217\246\345\255\230\344\270\272", 0));
        delBut->setText(QApplication::translate("FileEditChild", "\345\210\240\351\231\244", 0));
        degreeRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        fontTypeLab->setText(QApplication::translate("FileEditChild", "\345\255\227\344\275\223", 0));
        degreeShowLab->setText(QApplication::translate("FileEditChild", "0", 0));
        rotateLab->setText(QApplication::translate("FileEditChild", "\346\227\213\350\275\254", 0));
        degreeAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        stepAdd1But_2->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        stepValShow1Lab_2->setText(QApplication::translate("FileEditChild", "0", 0));
        fontSizeLab->setText(QApplication::translate("FileEditChild", "\345\255\227\345\217\267", 0));
        internalLab->setText(QApplication::translate("FileEditChild", "\351\227\264\350\267\235", 0));
        internalAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        internalRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        stepRed1But_2->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        currentValShow1Lab_2->setText(QApplication::translate("FileEditChild", "0", 0));
        typeTab->setTabText(typeTab->indexOf(tab), QApplication::translate("FileEditChild", "\346\226\207\345\255\227", 0));
        typeTab->setTabText(typeTab->indexOf(tab_3), QApplication::translate("FileEditChild", "\346\227\266\351\227\264", 0));
        typeTab->setTabText(typeTab->indexOf(tab_4), QApplication::translate("FileEditChild", "\345\272\217\345\217\267", 0));
        typeTab->setTabText(typeTab->indexOf(tab_5), QApplication::translate("FileEditChild", "\345\233\276\347\211\207", 0));
        typeTab->setTabText(typeTab->indexOf(tab_6), QApplication::translate("FileEditChild", "\346\235\241\345\275\242\347\240\201", 0));
        typeTab->setTabText(typeTab->indexOf(tab_7), QApplication::translate("FileEditChild", "QR\347\240\201", 0));
        typeTab->setTabText(typeTab->indexOf(tab_2), QApplication::translate("FileEditChild", "DM\347\240\201", 0));
        moveUpBut->setText(QApplication::translate("FileEditChild", "\344\270\212\347\247\273", 0));
        moveRightBut->setText(QApplication::translate("FileEditChild", "\345\217\263\347\247\273", 0));
        moveDownBut->setText(QApplication::translate("FileEditChild", "\344\270\213\347\247\273", 0));
        moveLeftBut->setText(QApplication::translate("FileEditChild", "\345\267\246\347\247\273", 0));
    } // retranslateUi

};

namespace Ui {
    class FileEditChild: public Ui_FileEditChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEDITCHILD_H
