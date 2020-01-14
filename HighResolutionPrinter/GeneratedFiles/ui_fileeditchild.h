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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <lineedit_click.h>

QT_BEGIN_NAMESPACE

class Ui_FileEditChild
{
public:
    QPushButton *saveBut;
    QTextEdit *editPreviewText;
    QPushButton *saveasBut;
    QPushButton *delBut;
    QScrollBar *textpreviewScrollBar;
    QTabWidget *typeTab;
    QWidget *textTab;
    lineedit_click *wordLineEdit;
    QPushButton *degreeTextRedBut;
    QLabel *fontTypeTextLab;
    QLabel *degreeTextShowLab;
    QLabel *rotateTextLab;
    QPushButton *degreeTextAddBut;
    QLabel *fontSizeTextLab;
    QLabel *internalTextLab;
    QPushButton *internalTextAddBut;
    QPushButton *internalTextRedBut;
    QLabel *internalShowTextLab;
    QComboBox *fontTypeTextComBox;
    QComboBox *fontSizeTextComBox;
    QPushButton *variableTextBut;
    QPushButton *newTextBut;
    QWidget *timeTab;
    QPushButton *internalTimeAddBut;
    QLabel *degreeTimeShowLab;
    QComboBox *fontSizeTimeComBox;
    QLabel *internalTimeLab;
    QPushButton *degreeTimeAddBut;
    QPushButton *internalTimeRedBut;
    QLabel *rotateTimeLab;
    QPushButton *degreeTimeRedBut;
    QPushButton *customTimeBut;
    QLabel *fontTypeTimeLab;
    QComboBox *fontTypeTimeComBox;
    QLabel *fontSizeTimeLab;
    QLabel *currentValShowTimeLab;
    QComboBox *typeTimeComBox;
    QLabel *typeTimeLab;
    QPushButton *newTimeBut;
    QWidget *serialTab;
    QLabel *degreeSerialShowLab;
    QLabel *fontSizeSerialLab;
    QLabel *typeSerialLab;
    QLabel *fontTypeSerialLab;
    QLabel *rotateSerialLab;
    QComboBox *typeSerialComBox;
    QLabel *currentValShowSerialLab;
    QLabel *internalSerialLab;
    QPushButton *degreeSerialRedBut;
    QPushButton *internalSerialAddBut;
    QPushButton *degreeSerialAddBut;
    QComboBox *fontTypeSerialComBox;
    QPushButton *internalSerialRedBut;
    QComboBox *fontSizeSerialComBox;
    QLabel *scaleSerialLab;
    QLabel *cateSerialLab;
    QComboBox *scaleSerialComBox;
    QComboBox *cateSerialComBox;
    QCheckBox *natureNumCheckBox;
    QPushButton *newSerialBut;
    QWidget *bmpTab;
    QLabel *heightBmpShowBmpLab;
    QPushButton *heightBmpAddBut;
    QPushButton *heightBmpRedBut;
    QPushButton *degreeBmpAddBut;
    QPushButton *degreeBmpRedBut;
    QLabel *heightBmpLab;
    QLabel *degreeBmpShowLab;
    QLabel *rotateBmpLab;
    QLabel *widthBmpLab;
    QLabel *widthShowBmpLab;
    QPushButton *widthBmpAddBut;
    QPushButton *widthBmpRedBut;
    QPushButton *selBmpBut;
    QCheckBox *reverseBmpCheckBox;
    QPushButton *newBmpBut;
    QLabel *bmpPreviewLab;
    QWidget *barCodeTab;
    lineedit_click *barCodeLineEdit;
    QLabel *zoomShowBarCodeLab;
    QPushButton *zoomBarCodeRedBut;
    QPushButton *variableBarCodeBut;
    QPushButton *degreeBarCodeRedBut;
    QPushButton *zoomBarCodeAddBut;
    QPushButton *degreeBarCodeAddBut;
    QLabel *typeBarCodeLab;
    QLabel *degreeBarCodeShowLab;
    QLabel *zoomBarCodeLab;
    QComboBox *typeBarCodeComBox;
    QLabel *rotateBarCodeLab;
    QPushButton *heightBarCodeAddBut;
    QLabel *heightBarCodeLab;
    QPushButton *heightBarCodeRedBut;
    QLabel *heightBarCodeShowQRLab;
    QCheckBox *showNumCheckBox;
    QPushButton *newBarCodeBut;
    QWidget *QRCodeTab;
    lineedit_click *QRCodeLineEdit;
    QLabel *preciseQRLab;
    QLabel *zoomShowQRLab;
    QPushButton *variableQRBut;
    QComboBox *preciseQRComBox;
    QLabel *degreeQRShowLab;
    QPushButton *degreeQRAddBut;
    QLabel *zoomQRLab;
    QComboBox *sideLenQRComBox;
    QPushButton *degreeQRRedBut;
    QLabel *rotateQRLab;
    QPushButton *zoomQRAddBut;
    QLabel *sideLenQRLab;
    QPushButton *zoomQRRedBut;
    QCheckBox *reverseCheckBox;
    QPushButton *newQRBut;
    QWidget *tab_2;
    QPushButton *variableDMBut;
    QPushButton *degreeDMAddBut;
    QPushButton *zoomDMRedBut;
    QPushButton *degreeDMRedBut;
    QLabel *zoomDMLab;
    QLabel *rotateDMLab;
    QLabel *sideLenDMLab;
    QComboBox *sideLenDMComBox;
    QLabel *degreeDMShowLab;
    QPushButton *zoomDMAddBut;
    QLabel *zoomShowDMLab;
    lineedit_click *DMCodeLineEdit;
    QPushButton *newDMBut;
    QPushButton *moveUpBut;
    QPushButton *moveRightBut;
    QPushButton *moveDownBut;
    QPushButton *moveLeftBut;
    QLabel *controlLab;
    QStackedWidget *keyboardStackWid;
    QWidget *page_3;
    QWidget *page_4;

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
        saveBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        editPreviewText = new QTextEdit(FileEditChild);
        editPreviewText->setObjectName(QStringLiteral("editPreviewText"));
        editPreviewText->setGeometry(QRect(10, 10, 1041, 241));
        editPreviewText->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        saveasBut = new QPushButton(FileEditChild);
        saveasBut->setObjectName(QStringLiteral("saveasBut"));
        saveasBut->setGeometry(QRect(950, 430, 101, 51));
        saveasBut->setFont(font);
        saveasBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        delBut = new QPushButton(FileEditChild);
        delBut->setObjectName(QStringLiteral("delBut"));
        delBut->setGeometry(QRect(895, 360, 101, 51));
        delBut->setFont(font);
        delBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        textpreviewScrollBar = new QScrollBar(FileEditChild);
        textpreviewScrollBar->setObjectName(QStringLiteral("textpreviewScrollBar"));
        textpreviewScrollBar->setGeometry(QRect(10, 250, 1041, 26));
        textpreviewScrollBar->setStyleSheet(QStringLiteral(""));
        textpreviewScrollBar->setOrientation(Qt::Horizontal);
        typeTab = new QTabWidget(FileEditChild);
        typeTab->setObjectName(QStringLiteral("typeTab"));
        typeTab->setGeometry(QRect(10, 290, 819, 461));
        typeTab->setFont(font);
        typeTab->setStyleSheet(QLatin1String("QTabBar::tab{width:117}\n"
"QTabBar::tab{height:50}"));
        textTab = new QWidget();
        textTab->setObjectName(QStringLiteral("textTab"));
        wordLineEdit = new lineedit_click(textTab);
        wordLineEdit->setObjectName(QStringLiteral("wordLineEdit"));
        wordLineEdit->setGeometry(QRect(10, 20, 791, 51));
        wordLineEdit->setFont(font);
        wordLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        degreeTextRedBut = new QPushButton(textTab);
        degreeTextRedBut->setObjectName(QStringLiteral("degreeTextRedBut"));
        degreeTextRedBut->setGeometry(QRect(160, 140, 41, 41));
        degreeTextRedBut->setMinimumSize(QSize(41, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        degreeTextRedBut->setFont(font1);
        degreeTextRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontTypeTextLab = new QLabel(textTab);
        fontTypeTextLab->setObjectName(QStringLiteral("fontTypeTextLab"));
        fontTypeTextLab->setGeometry(QRect(440, 140, 101, 41));
        fontTypeTextLab->setMinimumSize(QSize(101, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        fontTypeTextLab->setFont(font2);
        fontTypeTextLab->setAlignment(Qt::AlignCenter);
        degreeTextShowLab = new QLabel(textTab);
        degreeTextShowLab->setObjectName(QStringLiteral("degreeTextShowLab"));
        degreeTextShowLab->setGeometry(QRect(200, 140, 131, 41));
        degreeTextShowLab->setMinimumSize(QSize(0, 41));
        degreeTextShowLab->setFont(font2);
        degreeTextShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        degreeTextShowLab->setAlignment(Qt::AlignCenter);
        rotateTextLab = new QLabel(textTab);
        rotateTextLab->setObjectName(QStringLiteral("rotateTextLab"));
        rotateTextLab->setGeometry(QRect(60, 140, 101, 41));
        rotateTextLab->setMinimumSize(QSize(101, 41));
        rotateTextLab->setFont(font2);
        rotateTextLab->setAlignment(Qt::AlignCenter);
        degreeTextAddBut = new QPushButton(textTab);
        degreeTextAddBut->setObjectName(QStringLiteral("degreeTextAddBut"));
        degreeTextAddBut->setGeometry(QRect(330, 140, 41, 41));
        degreeTextAddBut->setMinimumSize(QSize(41, 41));
        degreeTextAddBut->setFont(font1);
        degreeTextAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontSizeTextLab = new QLabel(textTab);
        fontSizeTextLab->setObjectName(QStringLiteral("fontSizeTextLab"));
        fontSizeTextLab->setGeometry(QRect(440, 240, 101, 41));
        fontSizeTextLab->setMinimumSize(QSize(101, 41));
        fontSizeTextLab->setFont(font2);
        fontSizeTextLab->setAlignment(Qt::AlignCenter);
        internalTextLab = new QLabel(textTab);
        internalTextLab->setObjectName(QStringLiteral("internalTextLab"));
        internalTextLab->setGeometry(QRect(60, 240, 101, 41));
        internalTextLab->setMinimumSize(QSize(101, 41));
        internalTextLab->setFont(font2);
        internalTextLab->setAlignment(Qt::AlignCenter);
        internalTextAddBut = new QPushButton(textTab);
        internalTextAddBut->setObjectName(QStringLiteral("internalTextAddBut"));
        internalTextAddBut->setGeometry(QRect(330, 240, 41, 41));
        internalTextAddBut->setMinimumSize(QSize(41, 41));
        internalTextAddBut->setFont(font1);
        internalTextAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        internalTextRedBut = new QPushButton(textTab);
        internalTextRedBut->setObjectName(QStringLiteral("internalTextRedBut"));
        internalTextRedBut->setGeometry(QRect(160, 240, 41, 41));
        internalTextRedBut->setMinimumSize(QSize(41, 41));
        internalTextRedBut->setFont(font1);
        internalTextRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        internalShowTextLab = new QLabel(textTab);
        internalShowTextLab->setObjectName(QStringLiteral("internalShowTextLab"));
        internalShowTextLab->setGeometry(QRect(200, 240, 131, 41));
        internalShowTextLab->setMinimumSize(QSize(0, 41));
        internalShowTextLab->setFont(font2);
        internalShowTextLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        internalShowTextLab->setAlignment(Qt::AlignCenter);
        fontTypeTextComBox = new QComboBox(textTab);
        fontTypeTextComBox->setObjectName(QStringLiteral("fontTypeTextComBox"));
        fontTypeTextComBox->setGeometry(QRect(540, 145, 181, 31));
        fontTypeTextComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontSizeTextComBox = new QComboBox(textTab);
        fontSizeTextComBox->setObjectName(QStringLiteral("fontSizeTextComBox"));
        fontSizeTextComBox->setGeometry(QRect(540, 245, 181, 31));
        fontSizeTextComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        variableTextBut = new QPushButton(textTab);
        variableTextBut->setObjectName(QStringLiteral("variableTextBut"));
        variableTextBut->setGeometry(QRect(160, 330, 181, 41));
        variableTextBut->setFont(font);
        variableTextBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        newTextBut = new QPushButton(textTab);
        newTextBut->setObjectName(QStringLiteral("newTextBut"));
        newTextBut->setGeometry(QRect(540, 330, 181, 41));
        newTextBut->setFont(font);
        newTextBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTab->addTab(textTab, QString());
        timeTab = new QWidget();
        timeTab->setObjectName(QStringLiteral("timeTab"));
        internalTimeAddBut = new QPushButton(timeTab);
        internalTimeAddBut->setObjectName(QStringLiteral("internalTimeAddBut"));
        internalTimeAddBut->setGeometry(QRect(340, 170, 41, 41));
        internalTimeAddBut->setMinimumSize(QSize(41, 41));
        internalTimeAddBut->setFont(font1);
        internalTimeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeTimeShowLab = new QLabel(timeTab);
        degreeTimeShowLab->setObjectName(QStringLiteral("degreeTimeShowLab"));
        degreeTimeShowLab->setGeometry(QRect(210, 70, 131, 41));
        degreeTimeShowLab->setMinimumSize(QSize(0, 41));
        degreeTimeShowLab->setFont(font2);
        degreeTimeShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        degreeTimeShowLab->setAlignment(Qt::AlignCenter);
        fontSizeTimeComBox = new QComboBox(timeTab);
        fontSizeTimeComBox->setObjectName(QStringLiteral("fontSizeTimeComBox"));
        fontSizeTimeComBox->setGeometry(QRect(550, 165, 181, 31));
        fontSizeTimeComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        internalTimeLab = new QLabel(timeTab);
        internalTimeLab->setObjectName(QStringLiteral("internalTimeLab"));
        internalTimeLab->setGeometry(QRect(70, 170, 101, 41));
        internalTimeLab->setMinimumSize(QSize(101, 41));
        internalTimeLab->setFont(font2);
        internalTimeLab->setAlignment(Qt::AlignCenter);
        degreeTimeAddBut = new QPushButton(timeTab);
        degreeTimeAddBut->setObjectName(QStringLiteral("degreeTimeAddBut"));
        degreeTimeAddBut->setGeometry(QRect(340, 70, 41, 41));
        degreeTimeAddBut->setMinimumSize(QSize(41, 41));
        degreeTimeAddBut->setFont(font1);
        degreeTimeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        internalTimeRedBut = new QPushButton(timeTab);
        internalTimeRedBut->setObjectName(QStringLiteral("internalTimeRedBut"));
        internalTimeRedBut->setGeometry(QRect(170, 170, 41, 41));
        internalTimeRedBut->setMinimumSize(QSize(41, 41));
        internalTimeRedBut->setFont(font1);
        internalTimeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        rotateTimeLab = new QLabel(timeTab);
        rotateTimeLab->setObjectName(QStringLiteral("rotateTimeLab"));
        rotateTimeLab->setGeometry(QRect(70, 70, 101, 41));
        rotateTimeLab->setMinimumSize(QSize(101, 41));
        rotateTimeLab->setFont(font2);
        rotateTimeLab->setAlignment(Qt::AlignCenter);
        degreeTimeRedBut = new QPushButton(timeTab);
        degreeTimeRedBut->setObjectName(QStringLiteral("degreeTimeRedBut"));
        degreeTimeRedBut->setGeometry(QRect(170, 70, 41, 41));
        degreeTimeRedBut->setMinimumSize(QSize(41, 41));
        degreeTimeRedBut->setFont(font1);
        degreeTimeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        customTimeBut = new QPushButton(timeTab);
        customTimeBut->setObjectName(QStringLiteral("customTimeBut"));
        customTimeBut->setGeometry(QRect(170, 260, 181, 41));
        customTimeBut->setFont(font);
        customTimeBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontTypeTimeLab = new QLabel(timeTab);
        fontTypeTimeLab->setObjectName(QStringLiteral("fontTypeTimeLab"));
        fontTypeTimeLab->setGeometry(QRect(450, 70, 101, 41));
        fontTypeTimeLab->setMinimumSize(QSize(101, 41));
        fontTypeTimeLab->setFont(font2);
        fontTypeTimeLab->setAlignment(Qt::AlignCenter);
        fontTypeTimeComBox = new QComboBox(timeTab);
        fontTypeTimeComBox->setObjectName(QStringLiteral("fontTypeTimeComBox"));
        fontTypeTimeComBox->setGeometry(QRect(550, 75, 181, 31));
        fontTypeTimeComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontSizeTimeLab = new QLabel(timeTab);
        fontSizeTimeLab->setObjectName(QStringLiteral("fontSizeTimeLab"));
        fontSizeTimeLab->setGeometry(QRect(450, 160, 101, 41));
        fontSizeTimeLab->setMinimumSize(QSize(101, 41));
        fontSizeTimeLab->setFont(font2);
        fontSizeTimeLab->setAlignment(Qt::AlignCenter);
        currentValShowTimeLab = new QLabel(timeTab);
        currentValShowTimeLab->setObjectName(QStringLiteral("currentValShowTimeLab"));
        currentValShowTimeLab->setGeometry(QRect(210, 170, 131, 41));
        currentValShowTimeLab->setMinimumSize(QSize(0, 41));
        currentValShowTimeLab->setFont(font2);
        currentValShowTimeLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        currentValShowTimeLab->setAlignment(Qt::AlignCenter);
        typeTimeComBox = new QComboBox(timeTab);
        typeTimeComBox->setObjectName(QStringLiteral("typeTimeComBox"));
        typeTimeComBox->setGeometry(QRect(550, 260, 181, 31));
        typeTimeComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTimeLab = new QLabel(timeTab);
        typeTimeLab->setObjectName(QStringLiteral("typeTimeLab"));
        typeTimeLab->setGeometry(QRect(450, 255, 101, 41));
        typeTimeLab->setMinimumSize(QSize(101, 41));
        typeTimeLab->setFont(font2);
        typeTimeLab->setAlignment(Qt::AlignCenter);
        newTimeBut = new QPushButton(timeTab);
        newTimeBut->setObjectName(QStringLiteral("newTimeBut"));
        newTimeBut->setGeometry(QRect(550, 340, 181, 41));
        newTimeBut->setFont(font);
        newTimeBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTab->addTab(timeTab, QString());
        serialTab = new QWidget();
        serialTab->setObjectName(QStringLiteral("serialTab"));
        degreeSerialShowLab = new QLabel(serialTab);
        degreeSerialShowLab->setObjectName(QStringLiteral("degreeSerialShowLab"));
        degreeSerialShowLab->setGeometry(QRect(210, 180, 131, 41));
        degreeSerialShowLab->setMinimumSize(QSize(0, 41));
        degreeSerialShowLab->setFont(font2);
        degreeSerialShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        degreeSerialShowLab->setAlignment(Qt::AlignCenter);
        fontSizeSerialLab = new QLabel(serialTab);
        fontSizeSerialLab->setObjectName(QStringLiteral("fontSizeSerialLab"));
        fontSizeSerialLab->setGeometry(QRect(450, 105, 101, 41));
        fontSizeSerialLab->setMinimumSize(QSize(101, 41));
        fontSizeSerialLab->setFont(font2);
        fontSizeSerialLab->setAlignment(Qt::AlignCenter);
        typeSerialLab = new QLabel(serialTab);
        typeSerialLab->setObjectName(QStringLiteral("typeSerialLab"));
        typeSerialLab->setGeometry(QRect(450, 175, 101, 41));
        typeSerialLab->setMinimumSize(QSize(101, 41));
        typeSerialLab->setFont(font2);
        typeSerialLab->setAlignment(Qt::AlignCenter);
        fontTypeSerialLab = new QLabel(serialTab);
        fontTypeSerialLab->setObjectName(QStringLiteral("fontTypeSerialLab"));
        fontTypeSerialLab->setGeometry(QRect(450, 35, 101, 41));
        fontTypeSerialLab->setMinimumSize(QSize(101, 41));
        fontTypeSerialLab->setFont(font2);
        fontTypeSerialLab->setAlignment(Qt::AlignCenter);
        rotateSerialLab = new QLabel(serialTab);
        rotateSerialLab->setObjectName(QStringLiteral("rotateSerialLab"));
        rotateSerialLab->setGeometry(QRect(70, 180, 101, 41));
        rotateSerialLab->setMinimumSize(QSize(101, 41));
        rotateSerialLab->setFont(font2);
        rotateSerialLab->setAlignment(Qt::AlignCenter);
        typeSerialComBox = new QComboBox(serialTab);
        typeSerialComBox->setObjectName(QStringLiteral("typeSerialComBox"));
        typeSerialComBox->setGeometry(QRect(550, 180, 181, 31));
        typeSerialComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        currentValShowSerialLab = new QLabel(serialTab);
        currentValShowSerialLab->setObjectName(QStringLiteral("currentValShowSerialLab"));
        currentValShowSerialLab->setGeometry(QRect(210, 260, 131, 41));
        currentValShowSerialLab->setMinimumSize(QSize(0, 41));
        currentValShowSerialLab->setFont(font2);
        currentValShowSerialLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        currentValShowSerialLab->setAlignment(Qt::AlignCenter);
        internalSerialLab = new QLabel(serialTab);
        internalSerialLab->setObjectName(QStringLiteral("internalSerialLab"));
        internalSerialLab->setGeometry(QRect(70, 260, 101, 41));
        internalSerialLab->setMinimumSize(QSize(101, 41));
        internalSerialLab->setFont(font2);
        internalSerialLab->setAlignment(Qt::AlignCenter);
        degreeSerialRedBut = new QPushButton(serialTab);
        degreeSerialRedBut->setObjectName(QStringLiteral("degreeSerialRedBut"));
        degreeSerialRedBut->setGeometry(QRect(170, 180, 41, 41));
        degreeSerialRedBut->setMinimumSize(QSize(41, 41));
        degreeSerialRedBut->setFont(font1);
        degreeSerialRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        internalSerialAddBut = new QPushButton(serialTab);
        internalSerialAddBut->setObjectName(QStringLiteral("internalSerialAddBut"));
        internalSerialAddBut->setGeometry(QRect(340, 260, 41, 41));
        internalSerialAddBut->setMinimumSize(QSize(41, 41));
        internalSerialAddBut->setFont(font1);
        internalSerialAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeSerialAddBut = new QPushButton(serialTab);
        degreeSerialAddBut->setObjectName(QStringLiteral("degreeSerialAddBut"));
        degreeSerialAddBut->setGeometry(QRect(340, 180, 41, 41));
        degreeSerialAddBut->setMinimumSize(QSize(41, 41));
        degreeSerialAddBut->setFont(font1);
        degreeSerialAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontTypeSerialComBox = new QComboBox(serialTab);
        fontTypeSerialComBox->setObjectName(QStringLiteral("fontTypeSerialComBox"));
        fontTypeSerialComBox->setGeometry(QRect(550, 40, 181, 31));
        fontTypeSerialComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        internalSerialRedBut = new QPushButton(serialTab);
        internalSerialRedBut->setObjectName(QStringLiteral("internalSerialRedBut"));
        internalSerialRedBut->setGeometry(QRect(170, 260, 41, 41));
        internalSerialRedBut->setMinimumSize(QSize(41, 41));
        internalSerialRedBut->setFont(font1);
        internalSerialRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontSizeSerialComBox = new QComboBox(serialTab);
        fontSizeSerialComBox->setObjectName(QStringLiteral("fontSizeSerialComBox"));
        fontSizeSerialComBox->setGeometry(QRect(550, 110, 181, 31));
        fontSizeSerialComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        scaleSerialLab = new QLabel(serialTab);
        scaleSerialLab->setObjectName(QStringLiteral("scaleSerialLab"));
        scaleSerialLab->setGeometry(QRect(70, 105, 101, 41));
        scaleSerialLab->setMinimumSize(QSize(101, 41));
        scaleSerialLab->setFont(font2);
        scaleSerialLab->setAlignment(Qt::AlignCenter);
        cateSerialLab = new QLabel(serialTab);
        cateSerialLab->setObjectName(QStringLiteral("cateSerialLab"));
        cateSerialLab->setGeometry(QRect(70, 35, 101, 41));
        cateSerialLab->setMinimumSize(QSize(101, 41));
        cateSerialLab->setFont(font2);
        cateSerialLab->setAlignment(Qt::AlignCenter);
        scaleSerialComBox = new QComboBox(serialTab);
        scaleSerialComBox->setObjectName(QStringLiteral("scaleSerialComBox"));
        scaleSerialComBox->setGeometry(QRect(170, 110, 211, 31));
        scaleSerialComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        cateSerialComBox = new QComboBox(serialTab);
        cateSerialComBox->setObjectName(QStringLiteral("cateSerialComBox"));
        cateSerialComBox->setGeometry(QRect(170, 40, 211, 31));
        cateSerialComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        natureNumCheckBox = new QCheckBox(serialTab);
        natureNumCheckBox->setObjectName(QStringLiteral("natureNumCheckBox"));
        natureNumCheckBox->setGeometry(QRect(550, 340, 181, 41));
        natureNumCheckBox->setFont(font2);
        natureNumCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        natureNumCheckBox->setChecked(false);
        natureNumCheckBox->setAutoRepeat(false);
        newSerialBut = new QPushButton(serialTab);
        newSerialBut->setObjectName(QStringLiteral("newSerialBut"));
        newSerialBut->setGeometry(QRect(550, 260, 181, 41));
        newSerialBut->setFont(font);
        newSerialBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTab->addTab(serialTab, QString());
        bmpTab = new QWidget();
        bmpTab->setObjectName(QStringLiteral("bmpTab"));
        heightBmpShowBmpLab = new QLabel(bmpTab);
        heightBmpShowBmpLab->setObjectName(QStringLiteral("heightBmpShowBmpLab"));
        heightBmpShowBmpLab->setGeometry(QRect(200, 170, 131, 41));
        heightBmpShowBmpLab->setMinimumSize(QSize(0, 41));
        heightBmpShowBmpLab->setFont(font2);
        heightBmpShowBmpLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        heightBmpShowBmpLab->setAlignment(Qt::AlignCenter);
        heightBmpAddBut = new QPushButton(bmpTab);
        heightBmpAddBut->setObjectName(QStringLiteral("heightBmpAddBut"));
        heightBmpAddBut->setGeometry(QRect(330, 170, 41, 41));
        heightBmpAddBut->setMinimumSize(QSize(41, 41));
        heightBmpAddBut->setFont(font1);
        heightBmpAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        heightBmpRedBut = new QPushButton(bmpTab);
        heightBmpRedBut->setObjectName(QStringLiteral("heightBmpRedBut"));
        heightBmpRedBut->setGeometry(QRect(160, 170, 41, 41));
        heightBmpRedBut->setMinimumSize(QSize(41, 41));
        heightBmpRedBut->setFont(font1);
        heightBmpRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeBmpAddBut = new QPushButton(bmpTab);
        degreeBmpAddBut->setObjectName(QStringLiteral("degreeBmpAddBut"));
        degreeBmpAddBut->setGeometry(QRect(330, 80, 41, 41));
        degreeBmpAddBut->setMinimumSize(QSize(41, 41));
        degreeBmpAddBut->setFont(font1);
        degreeBmpAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeBmpRedBut = new QPushButton(bmpTab);
        degreeBmpRedBut->setObjectName(QStringLiteral("degreeBmpRedBut"));
        degreeBmpRedBut->setGeometry(QRect(160, 80, 41, 41));
        degreeBmpRedBut->setMinimumSize(QSize(41, 41));
        degreeBmpRedBut->setFont(font1);
        degreeBmpRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        heightBmpLab = new QLabel(bmpTab);
        heightBmpLab->setObjectName(QStringLiteral("heightBmpLab"));
        heightBmpLab->setGeometry(QRect(60, 170, 101, 41));
        heightBmpLab->setMinimumSize(QSize(101, 41));
        heightBmpLab->setFont(font2);
        heightBmpLab->setAlignment(Qt::AlignCenter);
        degreeBmpShowLab = new QLabel(bmpTab);
        degreeBmpShowLab->setObjectName(QStringLiteral("degreeBmpShowLab"));
        degreeBmpShowLab->setGeometry(QRect(200, 80, 131, 41));
        degreeBmpShowLab->setMinimumSize(QSize(0, 41));
        degreeBmpShowLab->setFont(font2);
        degreeBmpShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        degreeBmpShowLab->setAlignment(Qt::AlignCenter);
        rotateBmpLab = new QLabel(bmpTab);
        rotateBmpLab->setObjectName(QStringLiteral("rotateBmpLab"));
        rotateBmpLab->setGeometry(QRect(60, 80, 101, 41));
        rotateBmpLab->setMinimumSize(QSize(101, 41));
        rotateBmpLab->setFont(font2);
        rotateBmpLab->setAlignment(Qt::AlignCenter);
        widthBmpLab = new QLabel(bmpTab);
        widthBmpLab->setObjectName(QStringLiteral("widthBmpLab"));
        widthBmpLab->setGeometry(QRect(60, 260, 101, 41));
        widthBmpLab->setMinimumSize(QSize(101, 41));
        widthBmpLab->setFont(font2);
        widthBmpLab->setAlignment(Qt::AlignCenter);
        widthShowBmpLab = new QLabel(bmpTab);
        widthShowBmpLab->setObjectName(QStringLiteral("widthShowBmpLab"));
        widthShowBmpLab->setGeometry(QRect(200, 260, 131, 41));
        widthShowBmpLab->setMinimumSize(QSize(0, 41));
        widthShowBmpLab->setFont(font2);
        widthShowBmpLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        widthShowBmpLab->setAlignment(Qt::AlignCenter);
        widthBmpAddBut = new QPushButton(bmpTab);
        widthBmpAddBut->setObjectName(QStringLiteral("widthBmpAddBut"));
        widthBmpAddBut->setGeometry(QRect(330, 260, 41, 41));
        widthBmpAddBut->setMinimumSize(QSize(41, 41));
        widthBmpAddBut->setFont(font1);
        widthBmpAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        widthBmpRedBut = new QPushButton(bmpTab);
        widthBmpRedBut->setObjectName(QStringLiteral("widthBmpRedBut"));
        widthBmpRedBut->setGeometry(QRect(160, 260, 41, 41));
        widthBmpRedBut->setMinimumSize(QSize(41, 41));
        widthBmpRedBut->setFont(font1);
        widthBmpRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        selBmpBut = new QPushButton(bmpTab);
        selBmpBut->setObjectName(QStringLiteral("selBmpBut"));
        selBmpBut->setGeometry(QRect(440, 350, 141, 41));
        selBmpBut->setFont(font);
        selBmpBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        reverseBmpCheckBox = new QCheckBox(bmpTab);
        reverseBmpCheckBox->setObjectName(QStringLiteral("reverseBmpCheckBox"));
        reverseBmpCheckBox->setGeometry(QRect(160, 350, 181, 41));
        reverseBmpCheckBox->setFont(font2);
        reverseBmpCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        reverseBmpCheckBox->setChecked(false);
        reverseBmpCheckBox->setAutoRepeat(false);
        newBmpBut = new QPushButton(bmpTab);
        newBmpBut->setObjectName(QStringLiteral("newBmpBut"));
        newBmpBut->setGeometry(QRect(620, 350, 141, 41));
        newBmpBut->setFont(font);
        newBmpBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        bmpPreviewLab = new QLabel(bmpTab);
        bmpPreviewLab->setObjectName(QStringLiteral("bmpPreviewLab"));
        bmpPreviewLab->setGeometry(QRect(410, 50, 381, 251));
        bmpPreviewLab->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        typeTab->addTab(bmpTab, QString());
        barCodeTab = new QWidget();
        barCodeTab->setObjectName(QStringLiteral("barCodeTab"));
        barCodeLineEdit = new lineedit_click(barCodeTab);
        barCodeLineEdit->setObjectName(QStringLiteral("barCodeLineEdit"));
        barCodeLineEdit->setGeometry(QRect(10, 20, 791, 51));
        barCodeLineEdit->setFont(font);
        barCodeLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        zoomShowBarCodeLab = new QLabel(barCodeTab);
        zoomShowBarCodeLab->setObjectName(QStringLiteral("zoomShowBarCodeLab"));
        zoomShowBarCodeLab->setGeometry(QRect(210, 190, 131, 41));
        zoomShowBarCodeLab->setMinimumSize(QSize(0, 41));
        zoomShowBarCodeLab->setFont(font2);
        zoomShowBarCodeLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        zoomShowBarCodeLab->setAlignment(Qt::AlignCenter);
        zoomBarCodeRedBut = new QPushButton(barCodeTab);
        zoomBarCodeRedBut->setObjectName(QStringLiteral("zoomBarCodeRedBut"));
        zoomBarCodeRedBut->setGeometry(QRect(170, 190, 41, 41));
        zoomBarCodeRedBut->setMinimumSize(QSize(41, 41));
        zoomBarCodeRedBut->setFont(font1);
        zoomBarCodeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        variableBarCodeBut = new QPushButton(barCodeTab);
        variableBarCodeBut->setObjectName(QStringLiteral("variableBarCodeBut"));
        variableBarCodeBut->setGeometry(QRect(550, 190, 181, 41));
        variableBarCodeBut->setFont(font);
        variableBarCodeBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeBarCodeRedBut = new QPushButton(barCodeTab);
        degreeBarCodeRedBut->setObjectName(QStringLiteral("degreeBarCodeRedBut"));
        degreeBarCodeRedBut->setGeometry(QRect(170, 105, 41, 41));
        degreeBarCodeRedBut->setMinimumSize(QSize(41, 41));
        degreeBarCodeRedBut->setFont(font1);
        degreeBarCodeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        zoomBarCodeAddBut = new QPushButton(barCodeTab);
        zoomBarCodeAddBut->setObjectName(QStringLiteral("zoomBarCodeAddBut"));
        zoomBarCodeAddBut->setGeometry(QRect(340, 190, 41, 41));
        zoomBarCodeAddBut->setMinimumSize(QSize(41, 41));
        zoomBarCodeAddBut->setFont(font1);
        zoomBarCodeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeBarCodeAddBut = new QPushButton(barCodeTab);
        degreeBarCodeAddBut->setObjectName(QStringLiteral("degreeBarCodeAddBut"));
        degreeBarCodeAddBut->setGeometry(QRect(340, 105, 41, 41));
        degreeBarCodeAddBut->setMinimumSize(QSize(41, 41));
        degreeBarCodeAddBut->setFont(font1);
        degreeBarCodeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeBarCodeLab = new QLabel(barCodeTab);
        typeBarCodeLab->setObjectName(QStringLiteral("typeBarCodeLab"));
        typeBarCodeLab->setGeometry(QRect(450, 105, 101, 41));
        typeBarCodeLab->setMinimumSize(QSize(101, 41));
        typeBarCodeLab->setFont(font2);
        typeBarCodeLab->setAlignment(Qt::AlignCenter);
        degreeBarCodeShowLab = new QLabel(barCodeTab);
        degreeBarCodeShowLab->setObjectName(QStringLiteral("degreeBarCodeShowLab"));
        degreeBarCodeShowLab->setGeometry(QRect(210, 105, 131, 41));
        degreeBarCodeShowLab->setMinimumSize(QSize(0, 41));
        degreeBarCodeShowLab->setFont(font2);
        degreeBarCodeShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        degreeBarCodeShowLab->setAlignment(Qt::AlignCenter);
        zoomBarCodeLab = new QLabel(barCodeTab);
        zoomBarCodeLab->setObjectName(QStringLiteral("zoomBarCodeLab"));
        zoomBarCodeLab->setGeometry(QRect(70, 190, 101, 41));
        zoomBarCodeLab->setMinimumSize(QSize(101, 41));
        zoomBarCodeLab->setFont(font2);
        zoomBarCodeLab->setAlignment(Qt::AlignCenter);
        typeBarCodeComBox = new QComboBox(barCodeTab);
        typeBarCodeComBox->setObjectName(QStringLiteral("typeBarCodeComBox"));
        typeBarCodeComBox->setGeometry(QRect(550, 110, 181, 31));
        typeBarCodeComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        rotateBarCodeLab = new QLabel(barCodeTab);
        rotateBarCodeLab->setObjectName(QStringLiteral("rotateBarCodeLab"));
        rotateBarCodeLab->setGeometry(QRect(70, 105, 101, 41));
        rotateBarCodeLab->setMinimumSize(QSize(101, 41));
        rotateBarCodeLab->setFont(font2);
        rotateBarCodeLab->setAlignment(Qt::AlignCenter);
        heightBarCodeAddBut = new QPushButton(barCodeTab);
        heightBarCodeAddBut->setObjectName(QStringLiteral("heightBarCodeAddBut"));
        heightBarCodeAddBut->setGeometry(QRect(340, 280, 41, 41));
        heightBarCodeAddBut->setMinimumSize(QSize(41, 41));
        heightBarCodeAddBut->setFont(font1);
        heightBarCodeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        heightBarCodeLab = new QLabel(barCodeTab);
        heightBarCodeLab->setObjectName(QStringLiteral("heightBarCodeLab"));
        heightBarCodeLab->setGeometry(QRect(70, 280, 101, 41));
        heightBarCodeLab->setMinimumSize(QSize(101, 41));
        heightBarCodeLab->setFont(font2);
        heightBarCodeLab->setAlignment(Qt::AlignCenter);
        heightBarCodeRedBut = new QPushButton(barCodeTab);
        heightBarCodeRedBut->setObjectName(QStringLiteral("heightBarCodeRedBut"));
        heightBarCodeRedBut->setGeometry(QRect(170, 280, 41, 41));
        heightBarCodeRedBut->setMinimumSize(QSize(41, 41));
        heightBarCodeRedBut->setFont(font1);
        heightBarCodeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        heightBarCodeShowQRLab = new QLabel(barCodeTab);
        heightBarCodeShowQRLab->setObjectName(QStringLiteral("heightBarCodeShowQRLab"));
        heightBarCodeShowQRLab->setGeometry(QRect(210, 280, 131, 41));
        heightBarCodeShowQRLab->setMinimumSize(QSize(0, 41));
        heightBarCodeShowQRLab->setFont(font2);
        heightBarCodeShowQRLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        heightBarCodeShowQRLab->setAlignment(Qt::AlignCenter);
        showNumCheckBox = new QCheckBox(barCodeTab);
        showNumCheckBox->setObjectName(QStringLiteral("showNumCheckBox"));
        showNumCheckBox->setGeometry(QRect(550, 360, 181, 31));
        showNumCheckBox->setFont(font2);
        showNumCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        showNumCheckBox->setChecked(false);
        showNumCheckBox->setAutoRepeat(false);
        newBarCodeBut = new QPushButton(barCodeTab);
        newBarCodeBut->setObjectName(QStringLiteral("newBarCodeBut"));
        newBarCodeBut->setGeometry(QRect(550, 280, 181, 41));
        newBarCodeBut->setFont(font);
        newBarCodeBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTab->addTab(barCodeTab, QString());
        QRCodeTab = new QWidget();
        QRCodeTab->setObjectName(QStringLiteral("QRCodeTab"));
        QRCodeLineEdit = new lineedit_click(QRCodeTab);
        QRCodeLineEdit->setObjectName(QStringLiteral("QRCodeLineEdit"));
        QRCodeLineEdit->setGeometry(QRect(10, 20, 791, 51));
        QRCodeLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        preciseQRLab = new QLabel(QRCodeTab);
        preciseQRLab->setObjectName(QStringLiteral("preciseQRLab"));
        preciseQRLab->setGeometry(QRect(450, 105, 101, 41));
        preciseQRLab->setMinimumSize(QSize(101, 41));
        preciseQRLab->setFont(font2);
        preciseQRLab->setAlignment(Qt::AlignCenter);
        zoomShowQRLab = new QLabel(QRCodeTab);
        zoomShowQRLab->setObjectName(QStringLiteral("zoomShowQRLab"));
        zoomShowQRLab->setGeometry(QRect(210, 195, 131, 41));
        zoomShowQRLab->setMinimumSize(QSize(0, 41));
        zoomShowQRLab->setFont(font2);
        zoomShowQRLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        zoomShowQRLab->setAlignment(Qt::AlignCenter);
        variableQRBut = new QPushButton(QRCodeTab);
        variableQRBut->setObjectName(QStringLiteral("variableQRBut"));
        variableQRBut->setGeometry(QRect(170, 290, 181, 41));
        variableQRBut->setFont(font);
        variableQRBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        preciseQRComBox = new QComboBox(QRCodeTab);
        preciseQRComBox->setObjectName(QStringLiteral("preciseQRComBox"));
        preciseQRComBox->setGeometry(QRect(550, 110, 181, 31));
        preciseQRComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeQRShowLab = new QLabel(QRCodeTab);
        degreeQRShowLab->setObjectName(QStringLiteral("degreeQRShowLab"));
        degreeQRShowLab->setGeometry(QRect(210, 105, 131, 41));
        degreeQRShowLab->setMinimumSize(QSize(0, 41));
        degreeQRShowLab->setFont(font2);
        degreeQRShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        degreeQRShowLab->setAlignment(Qt::AlignCenter);
        degreeQRAddBut = new QPushButton(QRCodeTab);
        degreeQRAddBut->setObjectName(QStringLiteral("degreeQRAddBut"));
        degreeQRAddBut->setGeometry(QRect(340, 105, 41, 41));
        degreeQRAddBut->setMinimumSize(QSize(41, 41));
        degreeQRAddBut->setFont(font1);
        degreeQRAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        zoomQRLab = new QLabel(QRCodeTab);
        zoomQRLab->setObjectName(QStringLiteral("zoomQRLab"));
        zoomQRLab->setGeometry(QRect(70, 195, 101, 41));
        zoomQRLab->setMinimumSize(QSize(101, 41));
        zoomQRLab->setFont(font2);
        zoomQRLab->setAlignment(Qt::AlignCenter);
        sideLenQRComBox = new QComboBox(QRCodeTab);
        sideLenQRComBox->setObjectName(QStringLiteral("sideLenQRComBox"));
        sideLenQRComBox->setGeometry(QRect(550, 190, 181, 31));
        sideLenQRComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeQRRedBut = new QPushButton(QRCodeTab);
        degreeQRRedBut->setObjectName(QStringLiteral("degreeQRRedBut"));
        degreeQRRedBut->setGeometry(QRect(170, 105, 41, 41));
        degreeQRRedBut->setMinimumSize(QSize(41, 41));
        degreeQRRedBut->setFont(font1);
        degreeQRRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        rotateQRLab = new QLabel(QRCodeTab);
        rotateQRLab->setObjectName(QStringLiteral("rotateQRLab"));
        rotateQRLab->setGeometry(QRect(70, 105, 101, 41));
        rotateQRLab->setMinimumSize(QSize(101, 41));
        rotateQRLab->setFont(font2);
        rotateQRLab->setAlignment(Qt::AlignCenter);
        zoomQRAddBut = new QPushButton(QRCodeTab);
        zoomQRAddBut->setObjectName(QStringLiteral("zoomQRAddBut"));
        zoomQRAddBut->setGeometry(QRect(340, 195, 41, 41));
        zoomQRAddBut->setMinimumSize(QSize(41, 41));
        zoomQRAddBut->setFont(font1);
        zoomQRAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        sideLenQRLab = new QLabel(QRCodeTab);
        sideLenQRLab->setObjectName(QStringLiteral("sideLenQRLab"));
        sideLenQRLab->setGeometry(QRect(450, 185, 101, 41));
        sideLenQRLab->setMinimumSize(QSize(101, 41));
        sideLenQRLab->setFont(font2);
        sideLenQRLab->setAlignment(Qt::AlignCenter);
        zoomQRRedBut = new QPushButton(QRCodeTab);
        zoomQRRedBut->setObjectName(QStringLiteral("zoomQRRedBut"));
        zoomQRRedBut->setGeometry(QRect(170, 195, 41, 41));
        zoomQRRedBut->setMinimumSize(QSize(41, 41));
        zoomQRRedBut->setFont(font1);
        zoomQRRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        reverseCheckBox = new QCheckBox(QRCodeTab);
        reverseCheckBox->setObjectName(QStringLiteral("reverseCheckBox"));
        reverseCheckBox->setGeometry(QRect(550, 360, 181, 31));
        reverseCheckBox->setFont(font2);
        reverseCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        reverseCheckBox->setChecked(false);
        reverseCheckBox->setAutoRepeat(false);
        newQRBut = new QPushButton(QRCodeTab);
        newQRBut->setObjectName(QStringLiteral("newQRBut"));
        newQRBut->setGeometry(QRect(550, 290, 181, 41));
        newQRBut->setFont(font);
        newQRBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTab->addTab(QRCodeTab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        variableDMBut = new QPushButton(tab_2);
        variableDMBut->setObjectName(QStringLiteral("variableDMBut"));
        variableDMBut->setGeometry(QRect(540, 260, 181, 41));
        variableDMBut->setFont(font);
        variableDMBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeDMAddBut = new QPushButton(tab_2);
        degreeDMAddBut->setObjectName(QStringLiteral("degreeDMAddBut"));
        degreeDMAddBut->setGeometry(QRect(320, 160, 41, 41));
        degreeDMAddBut->setMinimumSize(QSize(41, 41));
        degreeDMAddBut->setFont(font1);
        degreeDMAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        zoomDMRedBut = new QPushButton(tab_2);
        zoomDMRedBut->setObjectName(QStringLiteral("zoomDMRedBut"));
        zoomDMRedBut->setGeometry(QRect(150, 260, 41, 41));
        zoomDMRedBut->setMinimumSize(QSize(41, 41));
        zoomDMRedBut->setFont(font1);
        zoomDMRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeDMRedBut = new QPushButton(tab_2);
        degreeDMRedBut->setObjectName(QStringLiteral("degreeDMRedBut"));
        degreeDMRedBut->setGeometry(QRect(150, 160, 41, 41));
        degreeDMRedBut->setMinimumSize(QSize(41, 41));
        degreeDMRedBut->setFont(font1);
        degreeDMRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        zoomDMLab = new QLabel(tab_2);
        zoomDMLab->setObjectName(QStringLiteral("zoomDMLab"));
        zoomDMLab->setGeometry(QRect(50, 260, 101, 41));
        zoomDMLab->setMinimumSize(QSize(101, 41));
        zoomDMLab->setFont(font2);
        zoomDMLab->setAlignment(Qt::AlignCenter);
        rotateDMLab = new QLabel(tab_2);
        rotateDMLab->setObjectName(QStringLiteral("rotateDMLab"));
        rotateDMLab->setGeometry(QRect(50, 160, 101, 41));
        rotateDMLab->setMinimumSize(QSize(101, 41));
        rotateDMLab->setFont(font2);
        rotateDMLab->setAlignment(Qt::AlignCenter);
        sideLenDMLab = new QLabel(tab_2);
        sideLenDMLab->setObjectName(QStringLiteral("sideLenDMLab"));
        sideLenDMLab->setGeometry(QRect(440, 160, 101, 41));
        sideLenDMLab->setMinimumSize(QSize(101, 41));
        sideLenDMLab->setFont(font2);
        sideLenDMLab->setAlignment(Qt::AlignCenter);
        sideLenDMComBox = new QComboBox(tab_2);
        sideLenDMComBox->setObjectName(QStringLiteral("sideLenDMComBox"));
        sideLenDMComBox->setGeometry(QRect(540, 165, 181, 31));
        sideLenDMComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeDMShowLab = new QLabel(tab_2);
        degreeDMShowLab->setObjectName(QStringLiteral("degreeDMShowLab"));
        degreeDMShowLab->setGeometry(QRect(190, 160, 131, 41));
        degreeDMShowLab->setMinimumSize(QSize(0, 41));
        degreeDMShowLab->setFont(font2);
        degreeDMShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        degreeDMShowLab->setAlignment(Qt::AlignCenter);
        zoomDMAddBut = new QPushButton(tab_2);
        zoomDMAddBut->setObjectName(QStringLiteral("zoomDMAddBut"));
        zoomDMAddBut->setGeometry(QRect(320, 260, 41, 41));
        zoomDMAddBut->setMinimumSize(QSize(41, 41));
        zoomDMAddBut->setFont(font1);
        zoomDMAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        zoomShowDMLab = new QLabel(tab_2);
        zoomShowDMLab->setObjectName(QStringLiteral("zoomShowDMLab"));
        zoomShowDMLab->setGeometry(QRect(190, 260, 131, 41));
        zoomShowDMLab->setMinimumSize(QSize(0, 41));
        zoomShowDMLab->setFont(font2);
        zoomShowDMLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        zoomShowDMLab->setAlignment(Qt::AlignCenter);
        DMCodeLineEdit = new lineedit_click(tab_2);
        DMCodeLineEdit->setObjectName(QStringLiteral("DMCodeLineEdit"));
        DMCodeLineEdit->setGeometry(QRect(10, 20, 791, 51));
        DMCodeLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        newDMBut = new QPushButton(tab_2);
        newDMBut->setObjectName(QStringLiteral("newDMBut"));
        newDMBut->setGeometry(QRect(540, 350, 181, 41));
        newDMBut->setFont(font);
        newDMBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTab->addTab(tab_2, QString());
        moveUpBut = new QPushButton(FileEditChild);
        moveUpBut->setObjectName(QStringLiteral("moveUpBut"));
        moveUpBut->setGeometry(QRect(910, 530, 63, 63));
        moveUpBut->setFont(font);
        moveUpBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        moveRightBut = new QPushButton(FileEditChild);
        moveRightBut->setObjectName(QStringLiteral("moveRightBut"));
        moveRightBut->setGeometry(QRect(980, 600, 63, 63));
        moveRightBut->setFont(font);
        moveRightBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-image: url(:/Images/moveright.bmp);\n"
"border-radius:10px;"));
        moveDownBut = new QPushButton(FileEditChild);
        moveDownBut->setObjectName(QStringLiteral("moveDownBut"));
        moveDownBut->setGeometry(QRect(910, 670, 63, 63));
        moveDownBut->setFont(font);
        moveDownBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        moveLeftBut = new QPushButton(FileEditChild);
        moveLeftBut->setObjectName(QStringLiteral("moveLeftBut"));
        moveLeftBut->setGeometry(QRect(840, 600, 63, 63));
        moveLeftBut->setFont(font);
        moveLeftBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-image: url(:/Images/moveleft.bmp);\n"
"border-radius:10px;"));
        controlLab = new QLabel(FileEditChild);
        controlLab->setObjectName(QStringLiteral("controlLab"));
        controlLab->setGeometry(QRect(830, 290, 221, 461));
        controlLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        keyboardStackWid = new QStackedWidget(FileEditChild);
        keyboardStackWid->setObjectName(QStringLiteral("keyboardStackWid"));
        keyboardStackWid->setGeometry(QRect(20, 420, 791, 321));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        keyboardStackWid->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        keyboardStackWid->addWidget(page_4);
        keyboardStackWid->raise();
        controlLab->raise();
        saveBut->raise();
        editPreviewText->raise();
        saveasBut->raise();
        delBut->raise();
        textpreviewScrollBar->raise();
        moveUpBut->raise();
        moveRightBut->raise();
        moveDownBut->raise();
        moveLeftBut->raise();
        typeTab->raise();

        retranslateUi(FileEditChild);

        typeTab->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(FileEditChild);
    } // setupUi

    void retranslateUi(QWidget *FileEditChild)
    {
        FileEditChild->setWindowTitle(QApplication::translate("FileEditChild", "FileEditChild", 0));
        saveBut->setText(QApplication::translate("FileEditChild", "\344\277\235\345\255\230", 0));
        saveasBut->setText(QApplication::translate("FileEditChild", "\345\217\246\345\255\230\344\270\272", 0));
        delBut->setText(QApplication::translate("FileEditChild", "\345\210\240\351\231\244", 0));
        degreeTextRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        fontTypeTextLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\344\275\223</span></p></body></html>", 0));
        degreeTextShowLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        rotateTextLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\227\213\350\275\254</span></p></body></html>", 0));
        degreeTextAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        fontSizeTextLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\345\217\267</span></p></body></html>", 0));
        internalTextLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\227\264\350\267\235</span></p></body></html>", 0));
        internalTextAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        internalTextRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        internalShowTextLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        variableTextBut->setText(QApplication::translate("FileEditChild", "\345\217\257\345\217\230", 0));
        newTextBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        typeTab->setTabText(typeTab->indexOf(textTab), QApplication::translate("FileEditChild", "\346\226\207\345\255\227", 0));
        internalTimeAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        degreeTimeShowLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        internalTimeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\227\264\350\267\235</span></p></body></html>", 0));
        degreeTimeAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        internalTimeRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        rotateTimeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\227\213\350\275\254</span></p></body></html>", 0));
        degreeTimeRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        customTimeBut->setText(QApplication::translate("FileEditChild", "\350\207\252\345\256\232\344\271\211", 0));
        fontTypeTimeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\344\275\223</span></p></body></html>", 0));
        fontSizeTimeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\345\217\267</span></p></body></html>", 0));
        currentValShowTimeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        typeTimeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\261\273\345\236\213</span></p></body></html>", 0));
        newTimeBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        typeTab->setTabText(typeTab->indexOf(timeTab), QApplication::translate("FileEditChild", "\346\227\266\351\227\264", 0));
        degreeSerialShowLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        fontSizeSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\345\217\267</span></p></body></html>", 0));
        typeSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\261\273\345\236\213</span></p></body></html>", 0));
        fontTypeSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\344\275\223</span></p></body></html>", 0));
        rotateSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\227\213\350\275\254</span></p></body></html>", 0));
        currentValShowSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        internalSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\227\264\350\267\235</span></p></body></html>", 0));
        degreeSerialRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        internalSerialAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        degreeSerialAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        internalSerialRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        scaleSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\277\233\344\275\215\345\210\266</span></p></body></html>", 0));
        cateSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\261\273\345\210\253</span></p></body></html>", 0));
        natureNumCheckBox->setText(QApplication::translate("FileEditChild", "\350\207\252\347\204\266\346\225\260", 0));
        newSerialBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        typeTab->setTabText(typeTab->indexOf(serialTab), QApplication::translate("FileEditChild", "\345\272\217\345\217\267", 0));
        heightBmpShowBmpLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        heightBmpAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        heightBmpRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        degreeBmpAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        degreeBmpRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        heightBmpLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\253\230\345\272\246</span></p></body></html>", 0));
        degreeBmpShowLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        rotateBmpLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\227\213\350\275\254</span></p></body></html>", 0));
        widthBmpLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\256\275\345\272\246</span></p></body></html>", 0));
        widthShowBmpLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        widthBmpAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        widthBmpRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        selBmpBut->setText(QApplication::translate("FileEditChild", "\351\200\211\346\213\251\345\233\276\345\275\242", 0));
        reverseBmpCheckBox->setText(QApplication::translate("FileEditChild", "\345\217\215\350\211\262", 0));
        newBmpBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        bmpPreviewLab->setText(QString());
        typeTab->setTabText(typeTab->indexOf(bmpTab), QApplication::translate("FileEditChild", "\345\233\276\347\211\207", 0));
        zoomShowBarCodeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        zoomBarCodeRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        variableBarCodeBut->setText(QApplication::translate("FileEditChild", "\345\217\257\345\217\230", 0));
        degreeBarCodeRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        zoomBarCodeAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        degreeBarCodeAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        typeBarCodeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\261\273\345\236\213</span></p></body></html>", 0));
        degreeBarCodeShowLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        zoomBarCodeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\274\251\346\224\276</span></p></body></html>", 0));
        rotateBarCodeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\227\213\350\275\254</span></p></body></html>", 0));
        heightBarCodeAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        heightBarCodeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\253\230\345\272\246</span></p></body></html>", 0));
        heightBarCodeRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        heightBarCodeShowQRLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        showNumCheckBox->setText(QApplication::translate("FileEditChild", "\346\230\276\347\244\272\346\225\260\345\255\227", 0));
        newBarCodeBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        typeTab->setTabText(typeTab->indexOf(barCodeTab), QApplication::translate("FileEditChild", "\346\235\241\345\275\242\347\240\201", 0));
        preciseQRLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\262\276\345\272\246</span></p></body></html>", 0));
        zoomShowQRLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        variableQRBut->setText(QApplication::translate("FileEditChild", "\345\217\257\345\217\230", 0));
        degreeQRShowLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        degreeQRAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        zoomQRLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\274\251\346\224\276</span></p></body></html>", 0));
        degreeQRRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        rotateQRLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\227\213\350\275\254</span></p></body></html>", 0));
        zoomQRAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        sideLenQRLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\276\271\351\225\277</span></p></body></html>", 0));
        zoomQRRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        reverseCheckBox->setText(QApplication::translate("FileEditChild", "\345\217\215\350\211\262", 0));
        newQRBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        typeTab->setTabText(typeTab->indexOf(QRCodeTab), QApplication::translate("FileEditChild", "QR\347\240\201", 0));
        variableDMBut->setText(QApplication::translate("FileEditChild", "\345\217\257\345\217\230", 0));
        degreeDMAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        zoomDMRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        degreeDMRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        zoomDMLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\274\251\346\224\276</span></p></body></html>", 0));
        rotateDMLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\227\213\350\275\254</span></p></body></html>", 0));
        sideLenDMLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\261\273\345\236\213</span></p></body></html>", 0));
        degreeDMShowLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        zoomDMAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        zoomShowDMLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        newDMBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        typeTab->setTabText(typeTab->indexOf(tab_2), QApplication::translate("FileEditChild", "DM\347\240\201", 0));
        moveUpBut->setText(QString());
        moveRightBut->setText(QString());
        moveDownBut->setText(QString());
        moveLeftBut->setText(QString());
        controlLab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileEditChild: public Ui_FileEditChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEDITCHILD_H
