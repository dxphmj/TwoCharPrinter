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
#include <QtWidgets/QLineEdit>
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
    QLabel *fontTypeTextLab;
    QLabel *fontSizeTextLab;
    QComboBox *fontTypeTextComBox;
    QComboBox *fontSizeTextComBox;
    QPushButton *variableTextBut;
    QPushButton *newTextBut;
    QWidget *timeTab;
    QComboBox *fontSizeTimeComBox;
    QPushButton *customTimeBut;
    QLabel *fontTypeTimeLab;
    QComboBox *fontTypeTimeComBox;
    QLabel *fontSizeTimeLab;
    QComboBox *typeTimeComBox;
    QLabel *typeTimeLab;
    QPushButton *newTimeBut;
    QWidget *serialTab;
    QLabel *formatSerialLab;
    QLabel *fontTypeSerialLab;
    QComboBox *fontTypeSerialComBox;
    QComboBox *formatSerialComBox;
    QLabel *counterSerialLab;
    QComboBox *counterSerialComBox;
    QPushButton *newSerialBut;
    lineedit_click *serialLineEdit;
    QLabel *initialValSerialLab;
    QLineEdit *initialValSerialLineEdit;
    QLabel *termValSerialLab;
    QLineEdit *termValSerialLineEdit;
    QLineEdit *startValSerialLineEdit;
    QLabel *startValSerialLab;
    QLineEdit *stepLenSerialLineEdit;
    QLabel *stepLenSerialLab;
    QLineEdit *reptCountSerialLineEdit;
    QLabel *reptCountSerialLab;
    QLineEdit *digitSerialLineEdit;
    QLabel *digitSerialLab;
    QWidget *bmpTab;
    QLabel *heightBmpShowBmpLab;
    QPushButton *heightBmpAddBut;
    QPushButton *heightBmpRedBut;
    QLabel *heightBmpLab;
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
    QPushButton *zoomBarCodeAddBut;
    QLabel *typeBarCodeLab;
    QLabel *zoomBarCodeLab;
    QComboBox *typeBarCodeComBox;
    QPushButton *heightBarCodeAddBut;
    QLabel *heightBarCodeLab;
    QPushButton *heightBarCodeRedBut;
    QLabel *heightBarCodeShowQRLab;
    QCheckBox *showNumCheckBox;
    QPushButton *newBarCodeBut;
    QWidget *QRCodeTab;
    lineedit_click *QRCodeLineEdit;
    QPushButton *variableQRBut;
    QCheckBox *reverseCheckBox;
    QPushButton *newQRBut;
    QComboBox *sideLenQRComBox;
    QLabel *sideLenQRLab;
    QWidget *tab_2;
    QPushButton *variableDMBut;
    QLabel *sideLenDMLab;
    QComboBox *sideLenDMComBox;
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
    QPushButton *degreeTextAddBut;
    QLabel *degreeTextShowLab;
    QPushButton *degreeTextRedBut;
    QLabel *rotateTextLab;
    QPushButton *internalTextAddBut;
    QPushButton *internalTextRedBut;
    QLabel *internalShowTextLab;
    QLabel *internalTextLab;

    void setupUi(QWidget *FileEditChild)
    {
        if (FileEditChild->objectName().isEmpty())
            FileEditChild->setObjectName(QStringLiteral("FileEditChild"));
        FileEditChild->resize(1061, 761);
        saveBut = new QPushButton(FileEditChild);
        saveBut->setObjectName(QStringLiteral("saveBut"));
        saveBut->setGeometry(QRect(840, 370, 101, 51));
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
        saveasBut->setGeometry(QRect(950, 370, 101, 51));
        saveasBut->setFont(font);
        saveasBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        delBut = new QPushButton(FileEditChild);
        delBut->setObjectName(QStringLiteral("delBut"));
        delBut->setGeometry(QRect(895, 300, 101, 51));
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
        fontTypeTextLab = new QLabel(textTab);
        fontTypeTextLab->setObjectName(QStringLiteral("fontTypeTextLab"));
        fontTypeTextLab->setGeometry(QRect(60, 170, 101, 41));
        fontTypeTextLab->setMinimumSize(QSize(101, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        fontTypeTextLab->setFont(font1);
        fontTypeTextLab->setAlignment(Qt::AlignCenter);
        fontSizeTextLab = new QLabel(textTab);
        fontSizeTextLab->setObjectName(QStringLiteral("fontSizeTextLab"));
        fontSizeTextLab->setGeometry(QRect(440, 170, 101, 41));
        fontSizeTextLab->setMinimumSize(QSize(101, 41));
        fontSizeTextLab->setFont(font1);
        fontSizeTextLab->setAlignment(Qt::AlignCenter);
        fontTypeTextComBox = new QComboBox(textTab);
        fontTypeTextComBox->setObjectName(QStringLiteral("fontTypeTextComBox"));
        fontTypeTextComBox->setGeometry(QRect(160, 175, 181, 31));
        fontTypeTextComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontSizeTextComBox = new QComboBox(textTab);
        fontSizeTextComBox->setObjectName(QStringLiteral("fontSizeTextComBox"));
        fontSizeTextComBox->setGeometry(QRect(540, 175, 181, 31));
        fontSizeTextComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        variableTextBut = new QPushButton(textTab);
        variableTextBut->setObjectName(QStringLiteral("variableTextBut"));
        variableTextBut->setGeometry(QRect(160, 310, 181, 41));
        variableTextBut->setFont(font);
        variableTextBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        newTextBut = new QPushButton(textTab);
        newTextBut->setObjectName(QStringLiteral("newTextBut"));
        newTextBut->setGeometry(QRect(540, 310, 181, 41));
        newTextBut->setFont(font);
        newTextBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTab->addTab(textTab, QString());
        timeTab = new QWidget();
        timeTab->setObjectName(QStringLiteral("timeTab"));
        fontSizeTimeComBox = new QComboBox(timeTab);
        fontSizeTimeComBox->setObjectName(QStringLiteral("fontSizeTimeComBox"));
        fontSizeTimeComBox->setGeometry(QRect(550, 90, 181, 31));
        fontSizeTimeComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        customTimeBut = new QPushButton(timeTab);
        customTimeBut->setObjectName(QStringLiteral("customTimeBut"));
        customTimeBut->setGeometry(QRect(550, 200, 181, 41));
        customTimeBut->setFont(font);
        customTimeBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontTypeTimeLab = new QLabel(timeTab);
        fontTypeTimeLab->setObjectName(QStringLiteral("fontTypeTimeLab"));
        fontTypeTimeLab->setGeometry(QRect(70, 85, 101, 41));
        fontTypeTimeLab->setMinimumSize(QSize(101, 41));
        fontTypeTimeLab->setFont(font1);
        fontTypeTimeLab->setAlignment(Qt::AlignCenter);
        fontTypeTimeComBox = new QComboBox(timeTab);
        fontTypeTimeComBox->setObjectName(QStringLiteral("fontTypeTimeComBox"));
        fontTypeTimeComBox->setGeometry(QRect(170, 90, 181, 31));
        fontTypeTimeComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        fontSizeTimeLab = new QLabel(timeTab);
        fontSizeTimeLab->setObjectName(QStringLiteral("fontSizeTimeLab"));
        fontSizeTimeLab->setGeometry(QRect(450, 85, 101, 41));
        fontSizeTimeLab->setMinimumSize(QSize(101, 41));
        fontSizeTimeLab->setFont(font1);
        fontSizeTimeLab->setAlignment(Qt::AlignCenter);
        typeTimeComBox = new QComboBox(timeTab);
        typeTimeComBox->setObjectName(QStringLiteral("typeTimeComBox"));
        typeTimeComBox->setGeometry(QRect(170, 195, 181, 31));
        typeTimeComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTimeLab = new QLabel(timeTab);
        typeTimeLab->setObjectName(QStringLiteral("typeTimeLab"));
        typeTimeLab->setGeometry(QRect(70, 190, 101, 41));
        typeTimeLab->setMinimumSize(QSize(101, 41));
        typeTimeLab->setFont(font1);
        typeTimeLab->setAlignment(Qt::AlignCenter);
        newTimeBut = new QPushButton(timeTab);
        newTimeBut->setObjectName(QStringLiteral("newTimeBut"));
        newTimeBut->setGeometry(QRect(550, 330, 181, 41));
        newTimeBut->setFont(font);
        newTimeBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTab->addTab(timeTab, QString());
        serialTab = new QWidget();
        serialTab->setObjectName(QStringLiteral("serialTab"));
        formatSerialLab = new QLabel(serialTab);
        formatSerialLab->setObjectName(QStringLiteral("formatSerialLab"));
        formatSerialLab->setGeometry(QRect(490, 295, 101, 41));
        formatSerialLab->setMinimumSize(QSize(101, 41));
        formatSerialLab->setFont(font1);
        formatSerialLab->setAlignment(Qt::AlignCenter);
        fontTypeSerialLab = new QLabel(serialTab);
        fontTypeSerialLab->setObjectName(QStringLiteral("fontTypeSerialLab"));
        fontTypeSerialLab->setGeometry(QRect(490, 245, 101, 41));
        fontTypeSerialLab->setMinimumSize(QSize(101, 41));
        fontTypeSerialLab->setFont(font1);
        fontTypeSerialLab->setAlignment(Qt::AlignCenter);
        fontTypeSerialComBox = new QComboBox(serialTab);
        fontTypeSerialComBox->setObjectName(QStringLiteral("fontTypeSerialComBox"));
        fontTypeSerialComBox->setGeometry(QRect(590, 250, 131, 31));
        fontTypeSerialComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        formatSerialComBox = new QComboBox(serialTab);
        formatSerialComBox->setObjectName(QStringLiteral("formatSerialComBox"));
        formatSerialComBox->setGeometry(QRect(590, 300, 131, 31));
        formatSerialComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        counterSerialLab = new QLabel(serialTab);
        counterSerialLab->setObjectName(QStringLiteral("counterSerialLab"));
        counterSerialLab->setGeometry(QRect(490, 195, 101, 41));
        counterSerialLab->setMinimumSize(QSize(101, 41));
        counterSerialLab->setFont(font1);
        counterSerialLab->setAlignment(Qt::AlignCenter);
        counterSerialComBox = new QComboBox(serialTab);
        counterSerialComBox->setObjectName(QStringLiteral("counterSerialComBox"));
        counterSerialComBox->setGeometry(QRect(590, 200, 131, 31));
        counterSerialComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        newSerialBut = new QPushButton(serialTab);
        newSerialBut->setObjectName(QStringLiteral("newSerialBut"));
        newSerialBut->setGeometry(QRect(570, 360, 161, 41));
        newSerialBut->setFont(font);
        newSerialBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        serialLineEdit = new lineedit_click(serialTab);
        serialLineEdit->setObjectName(QStringLiteral("serialLineEdit"));
        serialLineEdit->setGeometry(QRect(10, 20, 791, 51));
        serialLineEdit->setFont(font);
        serialLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        initialValSerialLab = new QLabel(serialTab);
        initialValSerialLab->setObjectName(QStringLiteral("initialValSerialLab"));
        initialValSerialLab->setGeometry(QRect(40, 110, 101, 41));
        initialValSerialLab->setMinimumSize(QSize(101, 41));
        initialValSerialLab->setFont(font1);
        initialValSerialLab->setAlignment(Qt::AlignCenter);
        initialValSerialLineEdit = new QLineEdit(serialTab);
        initialValSerialLineEdit->setObjectName(QStringLiteral("initialValSerialLineEdit"));
        initialValSerialLineEdit->setGeometry(QRect(140, 110, 131, 41));
        initialValSerialLineEdit->setFont(font);
        initialValSerialLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        termValSerialLab = new QLabel(serialTab);
        termValSerialLab->setObjectName(QStringLiteral("termValSerialLab"));
        termValSerialLab->setGeometry(QRect(40, 170, 101, 41));
        termValSerialLab->setMinimumSize(QSize(101, 41));
        termValSerialLab->setFont(font1);
        termValSerialLab->setAlignment(Qt::AlignCenter);
        termValSerialLineEdit = new QLineEdit(serialTab);
        termValSerialLineEdit->setObjectName(QStringLiteral("termValSerialLineEdit"));
        termValSerialLineEdit->setGeometry(QRect(140, 170, 131, 41));
        termValSerialLineEdit->setFont(font);
        termValSerialLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        startValSerialLineEdit = new QLineEdit(serialTab);
        startValSerialLineEdit->setObjectName(QStringLiteral("startValSerialLineEdit"));
        startValSerialLineEdit->setGeometry(QRect(140, 230, 131, 41));
        startValSerialLineEdit->setFont(font);
        startValSerialLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        startValSerialLab = new QLabel(serialTab);
        startValSerialLab->setObjectName(QStringLiteral("startValSerialLab"));
        startValSerialLab->setGeometry(QRect(40, 230, 101, 41));
        startValSerialLab->setMinimumSize(QSize(101, 41));
        startValSerialLab->setFont(font1);
        startValSerialLab->setAlignment(Qt::AlignCenter);
        stepLenSerialLineEdit = new QLineEdit(serialTab);
        stepLenSerialLineEdit->setObjectName(QStringLiteral("stepLenSerialLineEdit"));
        stepLenSerialLineEdit->setGeometry(QRect(140, 290, 131, 41));
        stepLenSerialLineEdit->setFont(font);
        stepLenSerialLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        stepLenSerialLab = new QLabel(serialTab);
        stepLenSerialLab->setObjectName(QStringLiteral("stepLenSerialLab"));
        stepLenSerialLab->setGeometry(QRect(40, 290, 101, 41));
        stepLenSerialLab->setMinimumSize(QSize(101, 41));
        stepLenSerialLab->setFont(font1);
        stepLenSerialLab->setAlignment(Qt::AlignCenter);
        reptCountSerialLineEdit = new QLineEdit(serialTab);
        reptCountSerialLineEdit->setObjectName(QStringLiteral("reptCountSerialLineEdit"));
        reptCountSerialLineEdit->setGeometry(QRect(590, 100, 131, 41));
        reptCountSerialLineEdit->setFont(font);
        reptCountSerialLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        reptCountSerialLab = new QLabel(serialTab);
        reptCountSerialLab->setObjectName(QStringLiteral("reptCountSerialLab"));
        reptCountSerialLab->setGeometry(QRect(490, 100, 101, 41));
        reptCountSerialLab->setMinimumSize(QSize(101, 41));
        reptCountSerialLab->setFont(font1);
        reptCountSerialLab->setAlignment(Qt::AlignCenter);
        digitSerialLineEdit = new QLineEdit(serialTab);
        digitSerialLineEdit->setObjectName(QStringLiteral("digitSerialLineEdit"));
        digitSerialLineEdit->setGeometry(QRect(590, 150, 131, 41));
        digitSerialLineEdit->setFont(font);
        digitSerialLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        digitSerialLab = new QLabel(serialTab);
        digitSerialLab->setObjectName(QStringLiteral("digitSerialLab"));
        digitSerialLab->setGeometry(QRect(490, 150, 101, 41));
        digitSerialLab->setMinimumSize(QSize(101, 41));
        digitSerialLab->setFont(font1);
        digitSerialLab->setAlignment(Qt::AlignCenter);
        typeTab->addTab(serialTab, QString());
        bmpTab = new QWidget();
        bmpTab->setObjectName(QStringLiteral("bmpTab"));
        heightBmpShowBmpLab = new QLabel(bmpTab);
        heightBmpShowBmpLab->setObjectName(QStringLiteral("heightBmpShowBmpLab"));
        heightBmpShowBmpLab->setGeometry(QRect(200, 110, 131, 41));
        heightBmpShowBmpLab->setMinimumSize(QSize(0, 41));
        heightBmpShowBmpLab->setFont(font1);
        heightBmpShowBmpLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        heightBmpShowBmpLab->setAlignment(Qt::AlignCenter);
        heightBmpAddBut = new QPushButton(bmpTab);
        heightBmpAddBut->setObjectName(QStringLiteral("heightBmpAddBut"));
        heightBmpAddBut->setGeometry(QRect(330, 110, 41, 41));
        heightBmpAddBut->setMinimumSize(QSize(41, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        heightBmpAddBut->setFont(font2);
        heightBmpAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        heightBmpRedBut = new QPushButton(bmpTab);
        heightBmpRedBut->setObjectName(QStringLiteral("heightBmpRedBut"));
        heightBmpRedBut->setGeometry(QRect(160, 110, 41, 41));
        heightBmpRedBut->setMinimumSize(QSize(41, 41));
        heightBmpRedBut->setFont(font2);
        heightBmpRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        heightBmpLab = new QLabel(bmpTab);
        heightBmpLab->setObjectName(QStringLiteral("heightBmpLab"));
        heightBmpLab->setGeometry(QRect(60, 110, 101, 41));
        heightBmpLab->setMinimumSize(QSize(101, 41));
        heightBmpLab->setFont(font1);
        heightBmpLab->setAlignment(Qt::AlignCenter);
        widthBmpLab = new QLabel(bmpTab);
        widthBmpLab->setObjectName(QStringLiteral("widthBmpLab"));
        widthBmpLab->setGeometry(QRect(60, 220, 101, 41));
        widthBmpLab->setMinimumSize(QSize(101, 41));
        widthBmpLab->setFont(font1);
        widthBmpLab->setAlignment(Qt::AlignCenter);
        widthShowBmpLab = new QLabel(bmpTab);
        widthShowBmpLab->setObjectName(QStringLiteral("widthShowBmpLab"));
        widthShowBmpLab->setGeometry(QRect(200, 220, 131, 41));
        widthShowBmpLab->setMinimumSize(QSize(0, 41));
        widthShowBmpLab->setFont(font1);
        widthShowBmpLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        widthShowBmpLab->setAlignment(Qt::AlignCenter);
        widthBmpAddBut = new QPushButton(bmpTab);
        widthBmpAddBut->setObjectName(QStringLiteral("widthBmpAddBut"));
        widthBmpAddBut->setGeometry(QRect(330, 220, 41, 41));
        widthBmpAddBut->setMinimumSize(QSize(41, 41));
        widthBmpAddBut->setFont(font2);
        widthBmpAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        widthBmpRedBut = new QPushButton(bmpTab);
        widthBmpRedBut->setObjectName(QStringLiteral("widthBmpRedBut"));
        widthBmpRedBut->setGeometry(QRect(160, 220, 41, 41));
        widthBmpRedBut->setMinimumSize(QSize(41, 41));
        widthBmpRedBut->setFont(font2);
        widthBmpRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        selBmpBut = new QPushButton(bmpTab);
        selBmpBut->setObjectName(QStringLiteral("selBmpBut"));
        selBmpBut->setGeometry(QRect(440, 360, 141, 41));
        selBmpBut->setFont(font);
        selBmpBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        reverseBmpCheckBox = new QCheckBox(bmpTab);
        reverseBmpCheckBox->setObjectName(QStringLiteral("reverseBmpCheckBox"));
        reverseBmpCheckBox->setGeometry(QRect(160, 330, 181, 41));
        reverseBmpCheckBox->setFont(font1);
        reverseBmpCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        reverseBmpCheckBox->setChecked(false);
        reverseBmpCheckBox->setAutoRepeat(false);
        newBmpBut = new QPushButton(bmpTab);
        newBmpBut->setObjectName(QStringLiteral("newBmpBut"));
        newBmpBut->setGeometry(QRect(620, 360, 141, 41));
        newBmpBut->setFont(font);
        newBmpBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        bmpPreviewLab = new QLabel(bmpTab);
        bmpPreviewLab->setObjectName(QStringLiteral("bmpPreviewLab"));
        bmpPreviewLab->setGeometry(QRect(410, 90, 381, 251));
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
        zoomShowBarCodeLab->setGeometry(QRect(210, 210, 131, 41));
        zoomShowBarCodeLab->setMinimumSize(QSize(0, 41));
        zoomShowBarCodeLab->setFont(font1);
        zoomShowBarCodeLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        zoomShowBarCodeLab->setAlignment(Qt::AlignCenter);
        zoomBarCodeRedBut = new QPushButton(barCodeTab);
        zoomBarCodeRedBut->setObjectName(QStringLiteral("zoomBarCodeRedBut"));
        zoomBarCodeRedBut->setGeometry(QRect(170, 210, 41, 41));
        zoomBarCodeRedBut->setMinimumSize(QSize(41, 41));
        zoomBarCodeRedBut->setFont(font2);
        zoomBarCodeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        variableBarCodeBut = new QPushButton(barCodeTab);
        variableBarCodeBut->setObjectName(QStringLiteral("variableBarCodeBut"));
        variableBarCodeBut->setGeometry(QRect(550, 120, 181, 41));
        variableBarCodeBut->setFont(font);
        variableBarCodeBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        zoomBarCodeAddBut = new QPushButton(barCodeTab);
        zoomBarCodeAddBut->setObjectName(QStringLiteral("zoomBarCodeAddBut"));
        zoomBarCodeAddBut->setGeometry(QRect(340, 210, 41, 41));
        zoomBarCodeAddBut->setMinimumSize(QSize(41, 41));
        zoomBarCodeAddBut->setFont(font2);
        zoomBarCodeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeBarCodeLab = new QLabel(barCodeTab);
        typeBarCodeLab->setObjectName(QStringLiteral("typeBarCodeLab"));
        typeBarCodeLab->setGeometry(QRect(70, 125, 101, 41));
        typeBarCodeLab->setMinimumSize(QSize(101, 41));
        typeBarCodeLab->setFont(font1);
        typeBarCodeLab->setAlignment(Qt::AlignCenter);
        zoomBarCodeLab = new QLabel(barCodeTab);
        zoomBarCodeLab->setObjectName(QStringLiteral("zoomBarCodeLab"));
        zoomBarCodeLab->setGeometry(QRect(70, 210, 101, 41));
        zoomBarCodeLab->setMinimumSize(QSize(101, 41));
        zoomBarCodeLab->setFont(font1);
        zoomBarCodeLab->setAlignment(Qt::AlignCenter);
        typeBarCodeComBox = new QComboBox(barCodeTab);
        typeBarCodeComBox->setObjectName(QStringLiteral("typeBarCodeComBox"));
        typeBarCodeComBox->setGeometry(QRect(170, 130, 211, 31));
        typeBarCodeComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        heightBarCodeAddBut = new QPushButton(barCodeTab);
        heightBarCodeAddBut->setObjectName(QStringLiteral("heightBarCodeAddBut"));
        heightBarCodeAddBut->setGeometry(QRect(340, 300, 41, 41));
        heightBarCodeAddBut->setMinimumSize(QSize(41, 41));
        heightBarCodeAddBut->setFont(font2);
        heightBarCodeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        heightBarCodeLab = new QLabel(barCodeTab);
        heightBarCodeLab->setObjectName(QStringLiteral("heightBarCodeLab"));
        heightBarCodeLab->setGeometry(QRect(70, 300, 101, 41));
        heightBarCodeLab->setMinimumSize(QSize(101, 41));
        heightBarCodeLab->setFont(font1);
        heightBarCodeLab->setAlignment(Qt::AlignCenter);
        heightBarCodeRedBut = new QPushButton(barCodeTab);
        heightBarCodeRedBut->setObjectName(QStringLiteral("heightBarCodeRedBut"));
        heightBarCodeRedBut->setGeometry(QRect(170, 300, 41, 41));
        heightBarCodeRedBut->setMinimumSize(QSize(41, 41));
        heightBarCodeRedBut->setFont(font2);
        heightBarCodeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        heightBarCodeShowQRLab = new QLabel(barCodeTab);
        heightBarCodeShowQRLab->setObjectName(QStringLiteral("heightBarCodeShowQRLab"));
        heightBarCodeShowQRLab->setGeometry(QRect(210, 300, 131, 41));
        heightBarCodeShowQRLab->setMinimumSize(QSize(0, 41));
        heightBarCodeShowQRLab->setFont(font1);
        heightBarCodeShowQRLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        heightBarCodeShowQRLab->setAlignment(Qt::AlignCenter);
        showNumCheckBox = new QCheckBox(barCodeTab);
        showNumCheckBox->setObjectName(QStringLiteral("showNumCheckBox"));
        showNumCheckBox->setGeometry(QRect(550, 310, 181, 31));
        showNumCheckBox->setFont(font1);
        showNumCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        showNumCheckBox->setChecked(false);
        showNumCheckBox->setAutoRepeat(false);
        newBarCodeBut = new QPushButton(barCodeTab);
        newBarCodeBut->setObjectName(QStringLiteral("newBarCodeBut"));
        newBarCodeBut->setGeometry(QRect(550, 210, 181, 41));
        newBarCodeBut->setFont(font);
        newBarCodeBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTab->addTab(barCodeTab, QString());
        QRCodeTab = new QWidget();
        QRCodeTab->setObjectName(QStringLiteral("QRCodeTab"));
        QRCodeLineEdit = new lineedit_click(QRCodeTab);
        QRCodeLineEdit->setObjectName(QStringLiteral("QRCodeLineEdit"));
        QRCodeLineEdit->setGeometry(QRect(10, 20, 791, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        QRCodeLineEdit->setFont(font3);
        QRCodeLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        variableQRBut = new QPushButton(QRCodeTab);
        variableQRBut->setObjectName(QStringLiteral("variableQRBut"));
        variableQRBut->setGeometry(QRect(550, 130, 181, 41));
        variableQRBut->setFont(font);
        variableQRBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        reverseCheckBox = new QCheckBox(QRCodeTab);
        reverseCheckBox->setObjectName(QStringLiteral("reverseCheckBox"));
        reverseCheckBox->setGeometry(QRect(170, 240, 181, 31));
        reverseCheckBox->setFont(font1);
        reverseCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        reverseCheckBox->setChecked(false);
        reverseCheckBox->setAutoRepeat(false);
        newQRBut = new QPushButton(QRCodeTab);
        newQRBut->setObjectName(QStringLiteral("newQRBut"));
        newQRBut->setGeometry(QRect(550, 230, 181, 41));
        newQRBut->setFont(font);
        newQRBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        sideLenQRComBox = new QComboBox(QRCodeTab);
        sideLenQRComBox->setObjectName(QStringLiteral("sideLenQRComBox"));
        sideLenQRComBox->setGeometry(QRect(170, 140, 181, 31));
        sideLenQRComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        sideLenQRLab = new QLabel(QRCodeTab);
        sideLenQRLab->setObjectName(QStringLiteral("sideLenQRLab"));
        sideLenQRLab->setGeometry(QRect(70, 135, 101, 41));
        sideLenQRLab->setMinimumSize(QSize(101, 41));
        sideLenQRLab->setFont(font1);
        sideLenQRLab->setAlignment(Qt::AlignCenter);
        typeTab->addTab(QRCodeTab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        variableDMBut = new QPushButton(tab_2);
        variableDMBut->setObjectName(QStringLiteral("variableDMBut"));
        variableDMBut->setGeometry(QRect(540, 160, 181, 41));
        variableDMBut->setFont(font);
        variableDMBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        sideLenDMLab = new QLabel(tab_2);
        sideLenDMLab->setObjectName(QStringLiteral("sideLenDMLab"));
        sideLenDMLab->setGeometry(QRect(50, 160, 101, 41));
        sideLenDMLab->setMinimumSize(QSize(101, 41));
        sideLenDMLab->setFont(font1);
        sideLenDMLab->setAlignment(Qt::AlignCenter);
        sideLenDMComBox = new QComboBox(tab_2);
        sideLenDMComBox->setObjectName(QStringLiteral("sideLenDMComBox"));
        sideLenDMComBox->setGeometry(QRect(150, 165, 211, 31));
        sideLenDMComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        DMCodeLineEdit = new lineedit_click(tab_2);
        DMCodeLineEdit->setObjectName(QStringLiteral("DMCodeLineEdit"));
        DMCodeLineEdit->setGeometry(QRect(10, 20, 791, 51));
        DMCodeLineEdit->setFont(font);
        DMCodeLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        newDMBut = new QPushButton(tab_2);
        newDMBut->setObjectName(QStringLiteral("newDMBut"));
        newDMBut->setGeometry(QRect(540, 260, 181, 41));
        newDMBut->setFont(font);
        newDMBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        typeTab->addTab(tab_2, QString());
        moveUpBut = new QPushButton(FileEditChild);
        moveUpBut->setObjectName(QStringLiteral("moveUpBut"));
        moveUpBut->setGeometry(QRect(910, 550, 63, 63));
        moveUpBut->setFont(font);
        moveUpBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-image: url(:/Images/moveup.bmp);\n"
"border-radius:10px;"));
        moveRightBut = new QPushButton(FileEditChild);
        moveRightBut->setObjectName(QStringLiteral("moveRightBut"));
        moveRightBut->setGeometry(QRect(980, 620, 63, 63));
        moveRightBut->setFont(font);
        moveRightBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-image: url(:/Images/moveright.bmp);\n"
"border-radius:10px;"));
        moveDownBut = new QPushButton(FileEditChild);
        moveDownBut->setObjectName(QStringLiteral("moveDownBut"));
        moveDownBut->setGeometry(QRect(910, 690, 63, 63));
        moveDownBut->setFont(font);
        moveDownBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-image: url(:/Images/movedown.bmp);\n"
"border-radius:10px;"));
        moveLeftBut = new QPushButton(FileEditChild);
        moveLeftBut->setObjectName(QStringLiteral("moveLeftBut"));
        moveLeftBut->setGeometry(QRect(840, 620, 63, 63));
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
        degreeTextAddBut = new QPushButton(FileEditChild);
        degreeTextAddBut->setObjectName(QStringLiteral("degreeTextAddBut"));
        degreeTextAddBut->setGeometry(QRect(1010, 450, 41, 41));
        degreeTextAddBut->setMinimumSize(QSize(41, 41));
        degreeTextAddBut->setFont(font2);
        degreeTextAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        degreeTextShowLab = new QLabel(FileEditChild);
        degreeTextShowLab->setObjectName(QStringLiteral("degreeTextShowLab"));
        degreeTextShowLab->setGeometry(QRect(940, 450, 71, 41));
        degreeTextShowLab->setMinimumSize(QSize(0, 41));
        degreeTextShowLab->setFont(font1);
        degreeTextShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        degreeTextShowLab->setAlignment(Qt::AlignCenter);
        degreeTextRedBut = new QPushButton(FileEditChild);
        degreeTextRedBut->setObjectName(QStringLiteral("degreeTextRedBut"));
        degreeTextRedBut->setGeometry(QRect(900, 450, 41, 41));
        degreeTextRedBut->setMinimumSize(QSize(41, 41));
        degreeTextRedBut->setFont(font2);
        degreeTextRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        rotateTextLab = new QLabel(FileEditChild);
        rotateTextLab->setObjectName(QStringLiteral("rotateTextLab"));
        rotateTextLab->setGeometry(QRect(840, 450, 61, 41));
        rotateTextLab->setMinimumSize(QSize(41, 41));
        rotateTextLab->setFont(font1);
        rotateTextLab->setAlignment(Qt::AlignCenter);
        internalTextAddBut = new QPushButton(FileEditChild);
        internalTextAddBut->setObjectName(QStringLiteral("internalTextAddBut"));
        internalTextAddBut->setGeometry(QRect(1010, 500, 41, 41));
        internalTextAddBut->setMinimumSize(QSize(41, 41));
        internalTextAddBut->setFont(font2);
        internalTextAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        internalTextRedBut = new QPushButton(FileEditChild);
        internalTextRedBut->setObjectName(QStringLiteral("internalTextRedBut"));
        internalTextRedBut->setGeometry(QRect(900, 500, 41, 41));
        internalTextRedBut->setMinimumSize(QSize(41, 41));
        internalTextRedBut->setFont(font2);
        internalTextRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        internalShowTextLab = new QLabel(FileEditChild);
        internalShowTextLab->setObjectName(QStringLiteral("internalShowTextLab"));
        internalShowTextLab->setGeometry(QRect(940, 500, 71, 41));
        internalShowTextLab->setMinimumSize(QSize(0, 41));
        internalShowTextLab->setFont(font1);
        internalShowTextLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        internalShowTextLab->setAlignment(Qt::AlignCenter);
        internalTextLab = new QLabel(FileEditChild);
        internalTextLab->setObjectName(QStringLiteral("internalTextLab"));
        internalTextLab->setGeometry(QRect(840, 500, 61, 41));
        internalTextLab->setMinimumSize(QSize(41, 41));
        internalTextLab->setFont(font1);
        internalTextLab->setAlignment(Qt::AlignCenter);
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
        degreeTextAddBut->raise();
        degreeTextShowLab->raise();
        degreeTextRedBut->raise();
        rotateTextLab->raise();
        internalTextAddBut->raise();
        internalTextRedBut->raise();
        internalShowTextLab->raise();
        internalTextLab->raise();

        retranslateUi(FileEditChild);

        typeTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FileEditChild);
    } // setupUi

    void retranslateUi(QWidget *FileEditChild)
    {
        FileEditChild->setWindowTitle(QApplication::translate("FileEditChild", "FileEditChild", 0));
        saveBut->setText(QApplication::translate("FileEditChild", "\344\277\235\345\255\230", 0));
        saveasBut->setText(QApplication::translate("FileEditChild", "\345\217\246\345\255\230\344\270\272", 0));
        delBut->setText(QApplication::translate("FileEditChild", "\345\210\240\351\231\244", 0));
        fontTypeTextLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\344\275\223</span></p></body></html>", 0));
        fontSizeTextLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\345\217\267</span></p></body></html>", 0));
        variableTextBut->setText(QApplication::translate("FileEditChild", "\345\217\257\345\217\230", 0));
        newTextBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        typeTab->setTabText(typeTab->indexOf(textTab), QApplication::translate("FileEditChild", "\346\226\207\345\255\227", 0));
        customTimeBut->setText(QApplication::translate("FileEditChild", "\350\207\252\345\256\232\344\271\211", 0));
        fontTypeTimeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\344\275\223</span></p></body></html>", 0));
        fontSizeTimeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\345\217\267</span></p></body></html>", 0));
        typeTimeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\261\273\345\236\213</span></p></body></html>", 0));
        newTimeBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        typeTab->setTabText(typeTab->indexOf(timeTab), QApplication::translate("FileEditChild", "\346\227\266\351\227\264", 0));
        formatSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\240\274\345\274\217</span></p></body></html>", 0));
        fontTypeSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\255\227\344\275\223</span></p></body></html>", 0));
        counterSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\256\241\346\225\260\345\231\250</span></p></body></html>", 0));
        newSerialBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        initialValSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\265\267\345\247\213\345\200\274</span></p></body></html>", 0));
        termValSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\273\210\346\255\242\345\200\274</span></p></body></html>", 0));
        startValSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\274\200\345\247\213\345\200\274</span></p></body></html>", 0));
        stepLenSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\255\245\351\225\277</span></p></body></html>", 0));
        reptCountSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\207\215\345\244\215\350\256\241\346\225\260</span></p></body></html>", 0));
        digitSerialLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\344\275\215\346\225\260</span></p></body></html>", 0));
        typeTab->setTabText(typeTab->indexOf(serialTab), QApplication::translate("FileEditChild", "\345\272\217\345\217\267", 0));
        heightBmpShowBmpLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        heightBmpAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        heightBmpRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        heightBmpLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\253\230\345\272\246</span></p></body></html>", 0));
        widthBmpLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\256\275\345\272\246</span></p></body></html>", 0));
        widthShowBmpLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        widthBmpAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        widthBmpRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        selBmpBut->setText(QApplication::translate("FileEditChild", "\351\200\211\346\213\251\345\233\276\345\275\242", 0));
        reverseBmpCheckBox->setText(QApplication::translate("FileEditChild", "\345\217\215\350\211\262", 0));
        newBmpBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        bmpPreviewLab->setText(QString());
        typeTab->setTabText(typeTab->indexOf(bmpTab), QApplication::translate("FileEditChild", "\345\233\276\347\211\207", 0));
        zoomShowBarCodeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        zoomBarCodeRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        variableBarCodeBut->setText(QApplication::translate("FileEditChild", "\345\217\257\345\217\230", 0));
        zoomBarCodeAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        typeBarCodeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\261\273\345\236\213</span></p></body></html>", 0));
        zoomBarCodeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\274\251\346\224\276</span></p></body></html>", 0));
        heightBarCodeAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        heightBarCodeLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\253\230\345\272\246</span></p></body></html>", 0));
        heightBarCodeRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        heightBarCodeShowQRLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">21</span></p></body></html>", 0));
        showNumCheckBox->setText(QApplication::translate("FileEditChild", "\346\230\276\347\244\272\346\225\260\345\255\227", 0));
        newBarCodeBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        typeTab->setTabText(typeTab->indexOf(barCodeTab), QApplication::translate("FileEditChild", "\346\235\241\345\275\242\347\240\201", 0));
        variableQRBut->setText(QApplication::translate("FileEditChild", "\345\217\257\345\217\230", 0));
        reverseCheckBox->setText(QApplication::translate("FileEditChild", "\345\217\215\350\211\262", 0));
        newQRBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        sideLenQRLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\276\271\351\225\277</span></p></body></html>", 0));
        typeTab->setTabText(typeTab->indexOf(QRCodeTab), QApplication::translate("FileEditChild", "QR\347\240\201", 0));
        variableDMBut->setText(QApplication::translate("FileEditChild", "\345\217\257\345\217\230", 0));
        sideLenDMLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\261\273\345\236\213</span></p></body></html>", 0));
        newDMBut->setText(QApplication::translate("FileEditChild", "\346\226\260\345\273\272", 0));
        typeTab->setTabText(typeTab->indexOf(tab_2), QApplication::translate("FileEditChild", "DM\347\240\201", 0));
        moveUpBut->setText(QString());
        moveRightBut->setText(QString());
        moveDownBut->setText(QString());
        moveLeftBut->setText(QString());
        controlLab->setText(QString());
        degreeTextAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        degreeTextShowLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        degreeTextRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        rotateTextLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\227\213\350\275\254</span></p></body></html>", 0));
        internalTextAddBut->setText(QApplication::translate("FileEditChild", "\357\274\213", 0));
        internalTextRedBut->setText(QApplication::translate("FileEditChild", "\357\274\215", 0));
        internalShowTextLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        internalTextLab->setText(QApplication::translate("FileEditChild", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\227\264\350\267\235</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class FileEditChild: public Ui_FileEditChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEDITCHILD_H
