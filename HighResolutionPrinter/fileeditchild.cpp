#include "ui_fileeditchild.h"
#include "lineedit_click.h"
#include "fileeditchild.h"
#include <QTableWidget>
#include <QMouseEvent>
#include "backend\zint.h"
#include <QFileDialog>
#include "filemanageform.h"
#include "filemanagechild.h"
#include "ui_filemanagechild.h"
#include "keyboard.h"
#include "language.h"
#include "numkeyboard.h"
#include "time.h"
#include "syssetting.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paramsettingform.h"
#include "automessagebox.h"
#include <tchar.h>


FileEditChild::FileEditChild(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::FileEditChild)
{
	ui->setupUi(this);
	/*m_LineeditChange = WordLineedit;*/

	connect(ui->variableTextBut,SIGNAL(clicked()),this,SLOT(variableTextBut_clicked()));
	connect(ui->variableBarCodeBut,SIGNAL(clicked()),this,SLOT(variableBarCodeBut_clicked()));
	connect(ui->variableQRBut,SIGNAL(clicked()),this,SLOT(variableQRBut_clicked()));
	connect(ui->variableDMBut,SIGNAL(clicked()),this,SLOT(variableDMBut_clicked()));
	//connect(ui->customTimeBut,SIGNAL(clicked()),this,SLOT(customTimeBut_clicked()));
	connect(ui->selBmpBut,SIGNAL(clicked()),this,SLOT(selBmpBut_clicked()));
	connect(ui->delBut,SIGNAL(clicked()),this,SLOT(delBut_clicked()));
	connect(ui->wordLineEdit,SIGNAL(clicked()),this,SLOT(wordLineEdit_clicked()));
	connect(ui->barCodeLineEdit,SIGNAL(clicked()),this,SLOT(barCodeLineEdit_clicked()));
	connect(ui->QRCodeLineEdit,SIGNAL(clicked()),this,SLOT(QRCodeLineEdit_clicked()));
	connect(ui->DMCodeLineEdit,SIGNAL(clicked()),this,SLOT(DMCodeLineEdit_clicked()));
	connect(ui->newTextBut,SIGNAL(clicked()),this,SLOT(newTextBut_clicked()));
	connect(ui->newBmpBut,SIGNAL(clicked()),this,SLOT(newBmpBut_clicked()));
	connect(ui->newBarCodeBut,SIGNAL(clicked()),this,SLOT(newBarCodeBut_clicked()));
	connect(ui->newQRBut,SIGNAL(clicked()),this,SLOT(newQRBut_clicked()));
	connect(ui->newDMBut,SIGNAL(clicked()),this,SLOT(newDMBut_clicked()));
	connect(ui->internalTextAddBut,SIGNAL(clicked()),this,SLOT(internalTextAddBut_clicked()));
	connect(ui->internalTextRedBut,SIGNAL(clicked()),this,SLOT(internalTextRedBut_clicked()));
	connect(ui->moveUpBut,SIGNAL(clicked()),this,SLOT(moveUpBut_clicked()));
	connect(ui->moveDownBut,SIGNAL(clicked()),this,SLOT(moveDownBut_clicked()));
	connect(ui->moveLeftBut,SIGNAL(clicked()),this,SLOT(moveLeftBut_clicked()));
	connect(ui->moveRightBut,SIGNAL(clicked()),this,SLOT(moveRightBut_clicked()));
	connect(ui->showNumCheckBox,SIGNAL(stateChanged()),this,SLOT(showNumCheckBox_clicked()));
	connect(ui->heightBarCodeAddBut,SIGNAL(clicked()),this,SLOT(heightBarCodeAddBut_clicked()));
	connect(ui->heightBarCodeRedBut,SIGNAL(clicked()),this,SLOT(heightBarCodeRedButt_clicked()));
	
	connect(ui->newTimeBut,SIGNAL(clicked()),this,SLOT(newTimeBut_clicked()));

	connect(ui->saveasBut,SIGNAL(clicked()),this,SLOT(saveasBut_clicked()));
	connect(ui->saveBut,SIGNAL(clicked()),this,SLOT(saveBut_clicked()));
	connect(ui->addTimeBut,SIGNAL(clicked()),this,SLOT(addTimeBut_clicked()));
	connect(ui->concelTimeBut,SIGNAL(clicked()),this,SLOT(concelTimeBut_clicked()));

	connect(ui->SkewComBox,SIGNAL(currentIndexChanged()),this,SLOT(SkewComBox_clicked()));
	connect(ui->refreshTimeBut,SIGNAL(clicked()),this,SLOT(refreshTimeBut_clicked()));
	connect(ui->newSerialBut,SIGNAL(clicked()),this,SLOT(newSerialNumber_click()));

	connect(ui->SkewSkewValueEdit,SIGNAL(clicked()),this,SLOT(SkewSkewValueEdit_clicked()));
	connect(ui->initialValSerialLineEdit,SIGNAL(clicked()),this,SLOT(initialValSerialLineEdit_clicked()));
	connect(ui->termValSerialLineEdit,SIGNAL(clicked()),this,SLOT(termValSerialLineEdit_clicked()));
	connect(ui->startValSerialLineEdit,SIGNAL(clicked()),this,SLOT(startValSerialLineEdit_clicked()));
    connect(ui->stepLenSerialLineEdit,SIGNAL(clicked()),this,SLOT(stepLenSerialLineEdit_clicked()));
	connect(ui->reptCountSerialLineEdit,SIGNAL(clicked()),this,SLOT(reptCountSerialLineEdit_clicked()));
	connect(ui->digitSerialLineEdit,SIGNAL(clicked()),this,SLOT(digitSerialLineEdit_clicked()));
	connect(ui->heightBmpShowBmpLineEdit,SIGNAL(clicked()),this,SLOT(heightBmpShowBmpLineEdit_clicked()));
	connect(ui->widthShowBmpLineEdit,SIGNAL(clicked()),this,SLOT(widthShowBmpLineEdit_clicked()));
	connect(ui->textpreviewScrollBar,SIGNAL(valueChanged(int)),this,SLOT(ScrollBarChanged(int)));
	connect(ui->pixelComBox,SIGNAL(currentIndexChanged()),this,SLOT(ChangePixel()));
	connect(ui->typeTab,SIGNAL(currentChanged(int)),this,SLOT(ChangeTabLineEdit()));
	connect(ui->typeTab,SIGNAL(currentChanged(int)),this,SLOT(KeyboardConceal_clicked()));
	connect(ui->startValSerialLineEdit,SIGNAL(editingFinished()),this,SLOT(SerialNumberstartchange()));
	connect(ui->heightBmpShowBmpLineEdit,SIGNAL(textChanged(QString)),this,SLOT(PreviewBmpChange()));
	connect(ui->widthShowBmpLineEdit,SIGNAL(textChanged(QString)),this,SLOT(PreviewBmpChange()));

	connect(ui->degreeTextRedBut,SIGNAL(clicked()),this,SLOT(degreeTextRedBut()));
	connect(ui->degreeTextAddBut,SIGNAL(clicked()),this,SLOT(degreeTextAddBut()));
	connect(ui->internalTextRedBut,SIGNAL(clicked()),this,SLOT(internalTextRedBut()));
	connect(ui->internalTextAddBut,SIGNAL(clicked()),this,SLOT(internalTextAddBut()));

	connect(ui->wordLineEdit,SIGNAL(textChanged(QString)),this,SLOT(OnEnChangeEditInput_clicked()));
	connect(ui->barCodeLineEdit,SIGNAL(textChanged(QString)),this,SLOT(OnEnChangeEditInput_clicked()));
	connect(ui->QRCodeLineEdit,SIGNAL(textChanged(QString)),this,SLOT(OnEnChangeEditInput_clicked()));
	connect(ui->DMCodeLineEdit,SIGNAL(textChanged(QString)),this,SLOT(OnEnChangeEditInput_clicked()));
	connect(ui->textIDShowSft1LineEdit,SIGNAL(textChanged(QString)),this,SLOT(OnEnChangeEditInput_clicked()));
	connect(ui->textIDShowSft2LineEdit,SIGNAL(textChanged(QString)),this,SLOT(OnEnChangeEditInput_clicked()));
	connect(ui->textIDShowSft3LineEdit,SIGNAL(textChanged(QString)),this,SLOT(OnEnChangeEditInput_clicked()));
	connect(ui->textIDShowSft4LineEdit,SIGNAL(textChanged(QString)),this,SLOT(OnEnChangeEditInput_clicked()));

	m_ShiftLineEditType = NULL;
	connect(ui->shiftNumShowLineEdit,SIGNAL(clicked()),this,SLOT(shiftNumShowLineEdit_clicked()));
	connect(ui->textLenShowLineEdit,SIGNAL(clicked()),this,SLOT(textLenShowLineEdit_clicked()));
	connect(ui->startTimeShowSft1LineEdit,SIGNAL(clicked()),this,SLOT(startTimeShowSft1LineEdit_clicked()));
	connect(ui->textIDShowSft1LineEdit,SIGNAL(clicked()),this,SLOT(textIDShowSft1LineEdit_clicked()));
	connect(ui->startTimeShowSft2LineEdit,SIGNAL(clicked()),this,SLOT(startTimeShowSft2LineEdit_clicked()));
	connect(ui->textIDShowSft2LineEdit,SIGNAL(clicked()),this,SLOT(textIDShowSft2LineEdit_clicked()));
	connect(ui->startTimeShowSft3LineEdit,SIGNAL(clicked()),this,SLOT(startTimeShowSft3LineEdit_clicked()));
	connect(ui->textIDShowSft3LineEdit,SIGNAL(clicked()),this,SLOT(textIDShowSft3LineEdit_clicked()));
	connect(ui->startTimeShowSft4LineEdit,SIGNAL(clicked()),this,SLOT(startTimeShowSft4LineEdit_clicked()));
	connect(ui->textIDShowSft4LineEdit,SIGNAL(clicked()),this,SLOT(textIDShowSft4LineEdit_clicked()));
	

	//m_time = new QTimer;
	//m_time->start(0);
	//connect(m_time,SIGNAL(timeout()),this,SLOT(getCurTime()));
	connect(ui->newShiftBut ,SIGNAL(clicked()),this,SLOT(newShiftBut()));


    ui->wordLineEdit->setFocus();

	ui->shiftNumShowLineEdit->setFocus();
	ui->textLenShowLineEdit->setFocus();
	ui->startTimeShowSft1LineEdit->setFocus();

	keyboardWidget = new keyboard(this);
	keyboardWidget->setVisible(false);
	ui->typeTab->setCurrentIndex(0);

	languageWidget = new language(keyboardWidget);
	languageWidget->setVisible(false);

	numkeyboardWidget = new numkeyboard(ui->typeTab);
	numkeyboardWidget->setVisible(false);
	ui->typeTab->setCurrentIndex(0);
	ui->rimwideLab->setText(QString::number(0));
	ui->editPreviewText->installEventFilter(this);
	ui->editPreviewText->viewport()->installEventFilter(this);

	ui->typeTab->setStyleSheet("QTabWidget:pane{ \
							  boder: -2px solid white;top: -2px;background-color:rgb(0, 0, 230);}\
							  QTabBar::tab{font:'楷体' 16pt;color: white;height:50px; width:92px; background-color:rgb(0, 0, 230); margin-right: 2px; margin-bottom:-2px;}\
							  QTabBar::tab:selected{border:1px solid white;border-bottom-color: none;}\
							  QTabBar::tab:!selected{border-bottom: 3px solid white;}\
							  ");
	ui->showNumCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									  QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									  ");
	ui->reverseCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									  QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									  ");
	ui->reverseBmpCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
		                                  QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
										 ");
	ui->proportionBmpCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
										  QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
										  ");
	ui->moveUpBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveup.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveup.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->moveDownBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/movedown.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/movedown.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->moveLeftBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveleft.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveleft.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->moveRightBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveright.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveright.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->concelTimeBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/repeal.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
									QPushButton:pressed{border-image: url(:/Images/repeal.bmp);border: 1px solid rgb(12 , 138 , 235);\
									padding-left:7px;padding-top:7px;}\
									"); 

	ui->degreeTextShowLab->setStyleSheet("background-color: rgb(72,61, 139);color: rgb(255, 255, 255);"); 
	ui->internalShowTextLab->setStyleSheet("background-color: rgb(72,61, 139);color: rgb(255, 255, 255);"); 
	//ui->degreeTimeShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->currentValShowTimeLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->degreeSerialShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->currentValShowSerialLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->degreeBmpShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->heightBmpShowBmpLab->setStyleSheet("background-color: rgb(72,61, 139);color: rgb(255, 255, 255);"); 
	//ui->widthShowBmpLab->setStyleSheet("background-color: rgb(72,61, 139);color: rgb(255, 255, 255);"); 
	//ui->degreeBarCodeShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->zoomShowBarCodeLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->heightBarCodeShowQRLab->setStyleSheet("background-color: rgb(72,61, 139);color: rgb(255, 255, 255);"); 
    //ui->degreeQRShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->zoomShowQRLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->degreeDMShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->zoomShowDMLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	
	//画布宽度item选项（单位：5x5像素）
	ui->pixelComBox->addItem(QStringLiteral("5px"));//0
	ui->pixelComBox->addItem(QStringLiteral("7px"));//1
	ui->pixelComBox->addItem(QStringLiteral("9px"));//2
	ui->pixelComBox->addItem(QStringLiteral("12px"));//3
	ui->pixelComBox->addItem(QStringLiteral("19px"));//4
	ui->pixelComBox->addItem(QStringLiteral("25px"));//5
	ui->pixelComBox->addItem(QStringLiteral("48px"));//6
	ui->pixelComBox->setCurrentIndex(4);

	//移动速度item选项（单位：5x5像素点）
	ui->moveSpeedComBox->addItem(QStringLiteral("1"));//0
	ui->moveSpeedComBox->addItem(QStringLiteral("2"));//1
	ui->moveSpeedComBox->addItem(QStringLiteral("5"));//2
	ui->moveSpeedComBox->addItem(QStringLiteral("10"));//3
	ui->moveSpeedComBox->addItem(QStringLiteral("50"));//4

	ui->typeBarCodeComBox->addItem(QStringLiteral("EANX"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("CODE39"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("CODE93"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("CODE128"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("UPCA"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("UPCE"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("ITF14"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("PDF417"));
	ui->typeBarCodeComBox->setCurrentIndex(1);

	ui->sideLenQRComBox->addItem(QStringLiteral("21 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("25 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("29 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("33 px"));
	//ui->sideLenQRComBox->addItem(QStringLiteral("37 px"));
	ui->sideLenQRComBox->setCurrentIndex(1);
	
	ui->sideLenDMComBox->addItem(QStringLiteral("Automatic"));
	ui->sideLenDMComBox->addItem(QStringLiteral("18x18"));
	ui->sideLenDMComBox->addItem(QStringLiteral("20x20"));
	ui->sideLenDMComBox->addItem(QStringLiteral("22x22"));
	ui->sideLenDMComBox->addItem(QStringLiteral("24x24"));
	ui->sideLenDMComBox->addItem(QStringLiteral("32x32"));
	ui->sideLenDMComBox->addItem(QStringLiteral("36x36"));
	ui->sideLenDMComBox->addItem(QStringLiteral("40x40"));
	ui->sideLenDMComBox->addItem(QStringLiteral("8x18"));
	ui->sideLenDMComBox->addItem(QStringLiteral("8x32"));
	ui->sideLenDMComBox->addItem(QStringLiteral("12x26"));
	ui->sideLenDMComBox->addItem(QStringLiteral("12x36"));
	ui->sideLenDMComBox->addItem(QStringLiteral("16x36"));
	ui->sideLenDMComBox->addItem(QStringLiteral("16x48"));
	ui->sideLenDMComBox->setCurrentIndex(0);
	degreenum=0;
	degreenumQr=9;
	degreenumDM=0;
	Zoomfactor=1;
	ZoomfactorQr=1;
	ZoomfactorDM=1;

	Barheight=21;

	ui->typerimComBox->addItem(QStringLiteral("No border"));
	ui->typerimComBox->addItem(QStringLiteral("Bind"));
	ui->typerimComBox->addItem(QStringLiteral("Box"));
	ui->typerimComBox->setCurrentIndex(0);
	
	connect(ui->whitespaceAddBut,SIGNAL(clicked()),this,SLOT(whitespaceAddBut_clicked()));
	connect(ui->whitespaceRedBut,SIGNAL(clicked()),this,SLOT(whitespaceRedButt_clicked()));
	connect(ui->rimwideAddBut,SIGNAL(clicked()),this,SLOT(rimwideAddBut_clicked()));
	connect(ui->rimwideRedBut,SIGNAL(clicked()),this,SLOT(rimwideRedButt_clicked()));

 //	m_MessagePrint.ReadObjectsFromXml("User\\Label\\qr.lab");
    //m_MessagePrint.ReadObjectsFromXml("User\\Label\\qr.lab");
	//m_MessagePrint.ReadBmp("D:\\1.bmp");
	//Create2Dcode(8,"1");
	ui->SkewSkewValueEdit->setText("0");
	ui->SkewUUnitlistWidget->addItem("Year");
	ui->SkewUUnitlistWidget->addItem("Month");
	ui->SkewUUnitlistWidget->addItem("Day");
	ui->SkewUUnitlistWidget->addItem("Hour");
	ui->SkewUUnitlistWidget->addItem("Minute");
	ui->fontSizeTimeComBox->addItem("5x5");
	ui->fontSizeTimeComBox->addItem("7x5");
	ui->fontSizeTimeComBox->addItem("12x12");
	ui->fontSizeTimeComBox->addItem("16x12");
	ui->fontSizeTimeComBox->setCurrentIndex(0);
	ui->fontTypeTimeComBox->addItem(QStringLiteral("仿宋简体"));
	ui->fontTypeTimeComBox->addItem(QStringLiteral("楷体简体"));
	ui->fontTypeTimeComBox->addItem(QStringLiteral("黑体简体"));
	ui->fontTypeTimeComBox->addItem(QStringLiteral("宋体简体"));
	ui->fontTypeTimeComBox->setCurrentIndex(0);
	ui->SkewComBox->addItem("OFF");
	ui->SkewComBox->addItem("ON");
	ui->SkewComBox->setCurrentIndex(0);
	ui->FormatlistWidget->addItem("%Y - Year (0000 - 9999)");
	ui->FormatlistWidget->addItem("%y - Year (00 - 99)");
	ui->FormatlistWidget->addItem("%m - Month (01 - 12)");
	ui->FormatlistWidget->addItem("%d - Day  (01 - 31)");
	ui->FormatlistWidget->addItem("%H - Hour (00 - 23)");
	ui->FormatlistWidget->addItem("%h - Hour (01 - 12)");
	//ui->FormatlistWidget->addItem("%p - A.M. / P.M. "));
	ui->FormatlistWidget->addItem("%M - Minute (00 - 59)");
	ui->FormatlistWidget->addItem("%S - Second (00 - 59)");
	ui->FormatlistWidget->addItem("%U - Week, Sunday first (00 - 53)");
	ui->FormatlistWidget->addItem("%W - Week, Monday first (00 - 53)");
	//ui->FormatlistWidget->addItem("%V - Weekday (1 - 7; Sunday is 1)");
	//ui->FormatlistWidget->addItem("%v - Weekday (1 - 7; Monday is 1)"));
	ui->FormatlistWidget->addItem("%w - Weekday (0 - 6; Sunday is 0)");
	//ui->FormatlistWidget->addItem("%w - Weekday (0 - 6; Monday is 0)"));
	//ui->FormatlistWidget->addItem("%Q - Quarter number of year (1 - 4)"));
	ui->FormatlistWidget->addItem("%j - Day number of year (001 - 366)");
	ui->FormatlistWidget->addItem("%a - Abbreviated weekday name");
	ui->FormatlistWidget->addItem("%A - Full weekday name");
	ui->FormatlistWidget->addItem("%b - Abbreviated month name");
	ui->FormatlistWidget->addItem("%B - Full month name");
	ui->FormatlistWidget->addItem("%p - am / pm");

	ui->delBut->setText(QStringLiteral("清空"));

	ui->textpreviewScrollBar->setRange(0,100);
	ui->editPreviewText->setGeometry(10, 10, 3121, 241);

	//序列号的初始化
	ui->initialValSerialLineEdit->setText("1");
	ui->termValSerialLineEdit->setText("100");
	ui->startValSerialLineEdit->setText("1");
	ui->stepLenSerialLineEdit->setText("1");
	ui->reptCountSerialLineEdit->setText("1");
	ui->digitSerialLineEdit->setText("9");
	ui->fontTypeSerialComBox->addItem(QStringLiteral("5x5"));
	ui->fontTypeSerialComBox->addItem(QStringLiteral("7x5"));
	ui->fontTypeSerialComBox->addItem(QStringLiteral("12x12"));
	ui->fontTypeSerialComBox->addItem(QStringLiteral("16x12"));
	ui->fontTypeSerialComBox->setCurrentIndex(0);
	ui->counterSerialComBox->addItem(QStringLiteral("计数器1"));
	ui->counterSerialComBox->addItem(QStringLiteral("计数器2"));
	ui->counterSerialComBox->addItem(QStringLiteral("计数器3"));
	ui->counterSerialComBox->addItem(QStringLiteral("计数器4"));
	ui->counterSerialComBox->setEnabled(0);
	ui->counterSerialComBox->setCurrentIndex(0);
	ui->formatSerialComBox->addItem(QStringLiteral("左侧补0"));
	ui->formatSerialComBox->addItem(QStringLiteral("左侧空白"));
	ui->formatSerialComBox->addItem(QStringLiteral("右侧空白"));
	ui->formatSerialComBox->setCurrentIndex(0);
	serialcount=1;
	ui->serialLineEdit->setText("000000001");
	SerialNumber_length=0;
	Serialfirst=1; 


	/*for(int i=0 ; i<1;i++)
	{*/
	//fcb = new QFontComboBox(this->ui->fontSizeTextComBox);
	/*}
    */
	//fcb->setFontFilters(QFontComboBox::AllFonts);
	///*fc[1]->setFontFilters(QFontComboBox::ScalableFonts);
	//fc[2]->setFontFilters(QFontComboBox::NonScalableFonts);
	//fc[3]->setFontFilters(QFontComboBox::MonospacedFonts);
	//fc[4]->setFontFilters(QFontComboBox::ProportionalFonts);*/

	/*int ypos = 30 ;*/
	/*for(int i=0;i<1;i++)
	{*/
	//fcb->setGeometry(100,470,300,41);
	//	ypos += 40 ;
	/*}*/
	/*label = new QLabel("用此标签查看字体效果",this);
	label->setGeometry(10,230,200,30);
	connect(fc[0],SIGNAL(currentFontChanged(QFont)),this,SLOT(changedFont(QFont)));*/
 
#ifdef BIG_CHAR
	ui->fontSizeTextComBox->setVisible(false);
	ui->fontTypeTextComBox->addItem(QStringLiteral("5x5"));
	ui->fontTypeTextComBox->addItem(QStringLiteral("7x5"));
	ui->fontTypeTextComBox->addItem(QStringLiteral("12x12"));
	ui->fontTypeTextComBox->addItem(QStringLiteral("16x12"));
	ui->fontTypeTextComBox->setCurrentIndex(0); 

#else
	FontComboBoxChoose = new QFontComboBox(this->ui->fontTypeTextComBox);
	FontComboBoxChoose->setFontFilters(QFontComboBox::AllFonts);
	FontComboBoxChoose->setGeometry(0,0,181,41);
	
	/*ui->fontTypeTextComBox->addItem(QStringLiteral("仿宋简体"));
	ui->fontTypeTextComBox->addItem(QStringLiteral("楷体简体"));
	ui->fontTypeTextComBox->addItem(QStringLiteral("黑体简体"));
	ui->fontTypeTextComBox->addItem(QStringLiteral("宋体简体"));
	ui->fontTypeTextComBox->setCurrentIndex(0);*/

	ui->fontSizeTextComBox->setVisible(true);
	ui->fontSizeTextComBox->addItem(QStringLiteral("5"));
	ui->fontSizeTextComBox->addItem(QStringLiteral("7"));
	ui->fontSizeTextComBox->addItem(QStringLiteral("9"));
	ui->fontSizeTextComBox->addItem(QStringLiteral("11"));
	ui->fontSizeTextComBox->setCurrentIndex(0);

#endif

}

FileEditChild::~FileEditChild()
{
}

void FileEditChild::ScrollBarChanged(int value)
{
	double p = static_cast<double>(value)/static_cast<double>(ui->textpreviewScrollBar->maximum());
	ui->editPreviewText->move(-2080*p,10);
}

void FileEditChild::ChangePixel()
{
	QPainter qFramePainter(this->ui->editPreviewText);
	DrawBackFrame(&qFramePainter);
}

void FileEditChild::shiftNumShowLineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->shiftNumShowLineEdit);
	m_ShiftLineEditType = 1;
	ClickChooseLanguage();
}

void FileEditChild::textLenShowLineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->textLenShowLineEdit);
	m_ShiftLineEditType = 2;
	ClickChooseLanguage();
}

void FileEditChild::startTimeShowSft1LineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->startTimeShowSft1LineEdit);
	m_ShiftLineEditType = 3;
	ClickChooseLanguage();
}

void FileEditChild::textIDShowSft1LineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->textIDShowSft1LineEdit);
	m_ShiftLineEditType = 4;
	ClickChooseLanguage();
}

void FileEditChild::startTimeShowSft2LineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->startTimeShowSft2LineEdit);
	m_ShiftLineEditType = 5;
	ClickChooseLanguage();
}

void FileEditChild::textIDShowSft2LineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->textIDShowSft2LineEdit);
	m_ShiftLineEditType = 6;
	ClickChooseLanguage();
}

void FileEditChild::startTimeShowSft3LineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->startTimeShowSft3LineEdit);
	m_ShiftLineEditType = 7;
	ClickChooseLanguage();
}

void FileEditChild::textIDShowSft3LineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->textIDShowSft3LineEdit);
	m_ShiftLineEditType = 8;
	ClickChooseLanguage();
}

void FileEditChild::startTimeShowSft4LineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->startTimeShowSft4LineEdit);
	m_ShiftLineEditType = 9;
	ClickChooseLanguage();
}

void FileEditChild::textIDShowSft4LineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->textIDShowSft4LineEdit);
	m_ShiftLineEditType = 10;
	ClickChooseLanguage();
}

void FileEditChild::OnEnChangeEditInput_clicked()//阿拉伯连笔
{	
	QString inputtext;
	int nIndex = ui->typeTab->currentIndex();
	switch(nIndex)//获取主编辑框文本
	{
		case 0:	//wordLineEdit文本框
			{
				inputtext = ui->wordLineEdit->text();
				break;
			}
		case 4:
			{
				if (m_ShiftLineEditType == 4)
				{
					inputtext = ui->textIDShowSft1LineEdit->text();
				}
				else if (m_ShiftLineEditType == 6)
				{
					inputtext = ui->textIDShowSft2LineEdit->text();
				}
				else if (m_ShiftLineEditType == 8)
				{
					inputtext = ui->textIDShowSft3LineEdit->text();
				}
				else if (m_ShiftLineEditType == 10)
				{
					inputtext = ui->textIDShowSft4LineEdit->text();
				}
				break;
			}
		case 5:	//wordLineEdit文本框
			{
				inputtext = ui->barCodeLineEdit->text();
				break;
			}
		case 6:	//wordLineEdit文本框
			{
				inputtext = ui->QRCodeLineEdit->text();
				break;
			}
		case 7:	//wordLineEdit文本框
			{
				inputtext = ui->DMCodeLineEdit->text();
				break;
			}
	}
	/*m_edit_input.GetWindowText(inputtext);*/
	if (keyboardWidget->m_LanType == 5 ||keyboardWidget->m_LanType == 23 ||keyboardWidget->m_LanType == 24 
		||keyboardWidget->m_LanType == 25 ||keyboardWidget->m_LanType == 26 ||keyboardWidget->m_LantypeReverse== 8)//判断当前是否是阿拉伯文本
	{
		QString outputtext = disposeinputtext(inputtext);
		if ( outputtext != inputtext )
		{
		//m_edit_input.SetWindowText(outputtext);
			switch(nIndex)//获取主编辑框文本
			{
			case 0:	
				{
					ui->wordLineEdit->setText(outputtext);
					break;
				}
			case 4:
				{
					if (m_ShiftLineEditType == 4)
					{
						ui->textIDShowSft1LineEdit->setText(outputtext);
					}
					else if (m_ShiftLineEditType == 6)
					{
						ui->textIDShowSft2LineEdit->setText(outputtext);
					}
					else if (m_ShiftLineEditType == 8)
					{
						ui->textIDShowSft3LineEdit->setText(outputtext);
					}
					else if (m_ShiftLineEditType == 10)
					{
						ui->textIDShowSft4LineEdit->setText(outputtext);
					}
					break;
				}
			case 5:	
				{
					ui->barCodeLineEdit->setText(outputtext);
					break;
				}
			case 6:	
				{
					ui->QRCodeLineEdit->setText(outputtext);
					break;
				}
			case 7:	
				{
					ui->DMCodeLineEdit->setText(outputtext);
					break;
				}
		     }
	      }
	}
}

void FileEditChild::DrawBackFrame(QPainter *qFramePainter)
{
	//绘图统一放到eventFilter 中进行绘制，这里只是改变相关变量值
	QPen qGrayPen(Qt::lightGray,1,Qt::SolidLine,Qt::SquareCap,Qt::MiterJoin);
	QPen qRedPen(Qt::red,4,Qt::SolidLine,Qt::RoundCap,Qt::BevelJoin);

	QMap <QString,int> PixelMap;
	PixelMap.insert("5px",25);
	PixelMap.insert("7px",35);
	PixelMap.insert("9px",45);
	PixelMap.insert("12px",60);
	PixelMap.insert("19px",95);
	PixelMap.insert("25px",125);
	PixelMap.insert("48px",240);

	QString CurPixelItem = this->ui->pixelComBox->currentText();
	int i,j;
	for (i=0; i<=3121; i+=5)
	{
		//画列
		qFramePainter->setPen(qGrayPen);
		qFramePainter->drawLine(i,240-PixelMap[CurPixelItem],i,241);
	}
	for (j=240; j>=240-PixelMap[CurPixelItem]; j-=5)
	{
		//画行
		qFramePainter->setPen(qGrayPen);
		qFramePainter->drawLine(0,j,3121,j);
	}
	qFramePainter->setPen(qRedPen);
	qFramePainter->drawLine(0,240,0,240-PixelMap[CurPixelItem]);
	qFramePainter->drawLine(0,240,3120,240);
	qFramePainter->drawLine(0,240-PixelMap[CurPixelItem],3120,240-PixelMap[CurPixelItem]);
	qFramePainter->drawLine(3120,240,3120,240-PixelMap[CurPixelItem]);

	//获得Matrix 及 Piexl的值
	m_MessagePrint.Matrix = PixelMap[CurPixelItem]/5;
	m_MessagePrint.strMatrix = "1L"+ m_MessagePrint.to_String(m_MessagePrint.Matrix)+"M";
	m_MessagePrint.Pixel = m_MessagePrint.Matrix;
}

void FileEditChild::Create2Dcode(int nType,QString strContent)
{
	GenerateBarCodeBmp();
	QString str = getNum(ui->heightBarCodeShowQRLab->text());
	int heightvalue1 = str.toInt();
	char* strFileName = "User/logo/output.bmp";
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	int nH = pLoad.height();
	QImage pImage;
	pImage = pLoad.toImage();
	pImage = pImage.scaled(pImage.width(),heightvalue1, Qt::IgnoreAspectRatio, Qt::SmoothTransformation); 

	CBarcodeOBJ* bmpObj = new CBarcodeOBJ;
	bmpObj->intLineStart=0;
	bmpObj->intRowStart=0;
	bmpObj->strType1="text";
	bmpObj->strType2="2Dcode";
	bmpObj->strText=strFileName;
	bmpObj->strCodeContent=strContent.toStdString();
	bmpObj->intLineSize=pImage.height();
	bmpObj->intRowSize=pImage.width();
	bmpObj->intBarcodeType=nType;
	bmpObj->intBarType= ui->typeBarCodeComBox->currentIndex();
	bmpObj->intBarWhite = ui->whitespaceLab->text().toInt();
	bmpObj->intSW=1;
	bmpObj->intSS=0;
	bmpObj->booNEG=false;
	bmpObj->booBWDx=false;
	bmpObj->booBWDy=false;

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
			if(average < 200)
				bmpObj->boDotBmp[bmpObj->intRowStart +x][bmpObj->intLineStart+bmpObj->intLineSize -y-1] = true;
			else
				bmpObj->boDotBmp[bmpObj->intRowStart +x][bmpObj->intLineStart+bmpObj->intLineSize -y-1] = false;
		}  

	}  
	bmpObj->booFocus = true;
	m_MessagePrint.OBJ_Vec.push_back(bmpObj); 
	if (nW ==0 && nH ==0)
	{
		delBut_clicked();
	}
	QString get = QString(QLatin1String(strFileName)).toUtf8();
	//删除文件
	QFile::remove(get);
}

void FileEditChild::CreateQrcode(int nType,QString strContent)
{	
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;
	int v;

	//error_number = 0;
	//QString angle1=ui->degreeQRShowLab->text();//暂时注掉
	//int angle2=angle1.toInt();
	//rotate_angle = angle2;
	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = nType; 
	my_symbol->scale =0.5;

	v=ui->sideLenQRComBox->currentIndex();
	my_symbol->option_2 = v+1;//option_1为容错等级，option_2为版本大小公式为:(V - 1) * 4 + 21；
	if (ui->reverseCheckBox->isChecked())
	{
	strcpy_s(my_symbol->fgcolour, "ffffff");
	strcpy_s(my_symbol->bgcolour, "000000");
	}
	batch_mode = 0;
	mirror_mode = 0;
	 error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
	
	if (error_number != 0)
	{
		/* some error occurred */
		string errortext = my_symbol->errtxt;
		informationMessage(errortext);
	}
	generated = 1;
	int xPos=0;
	int yPos=0;
	for(int i=0;i<m_MessagePrint.OBJ_Vec.size();i++)
	{
		if (m_MessagePrint.OBJ_Vec.at(i)->booFocus)
		{
			m_MessagePrint.OBJ_Vec.at(i)->booFocus=false;
			yPos = m_MessagePrint.OBJ_Vec.at(i)->intLineStart;
			xPos = m_MessagePrint.OBJ_Vec.at(i)->intRowSize+m_MessagePrint.OBJ_Vec.at(i)->intRowStart;
		}
	}

	CQRcodeOBJ* bmpObj = new CQRcodeOBJ;
	bmpObj->intLineStart=yPos;
	bmpObj->intRowStart=xPos;
	bmpObj->strType1="text";
	bmpObj->strType2="qrcode";
	bmpObj->intLineSize=my_symbol->bitmap_height;
	bmpObj->intRowSize=my_symbol->bitmap_width;
	bmpObj->intQRVersion = ui->sideLenQRComBox->currentIndex()+1;

	//以下先写死
	bmpObj->intSW=1;
	bmpObj->intSS=1;
	bmpObj->booNEG=false;
	bmpObj->booBWDx=false;
	bmpObj->booBWDy=false;
	i = 0;
	int r, g, b;

	for (int row = 0; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
				bmpObj->boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				//		bmpObj.boDotBmp[col][row-proportion] = false;
				bmpObj->boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	bmpObj->strText = strContent.toStdString();
	bmpObj->booFocus = true;
	m_MessagePrint.OBJ_Vec.push_back(bmpObj); 
	if (my_symbol->bitmap_height ==0 && my_symbol->bitmap_width ==0)
	{
		delBut_clicked();
	}

}

void FileEditChild::CreateDMcode(int nType,QString strContent)
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;

	error_number = 0;
	
	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = 1;
	my_symbol->symbology = 71;
	my_symbol->scale =0.5;

	my_symbol->option_2 = nType;
	if (ui->reverseDMCheckBox->isChecked())
	{
		strcpy_s(my_symbol->fgcolour, "ffffff");
		strcpy_s(my_symbol->bgcolour, "000000");
	}
	batch_mode = 0;
	mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);

	if (error_number != 0)
	{
		/* some error occurred */
		string errortext = my_symbol->errtxt;
		informationMessage(errortext);
	}
	generated = 1;

	int xPos=0;
	int yPos=0;
	for(int i=0;i<m_MessagePrint.OBJ_Vec.size();i++)
	{
		if (m_MessagePrint.OBJ_Vec.at(i)->booFocus)
		{
			m_MessagePrint.OBJ_Vec.at(i)->booFocus=false;
			yPos = m_MessagePrint.OBJ_Vec.at(i)->intLineStart;
			xPos = m_MessagePrint.OBJ_Vec.at(i)->intRowSize+m_MessagePrint.OBJ_Vec.at(i)->intRowStart;
		}
	}

	CDMcodeOBJ* bmpObj = new CDMcodeOBJ;
	bmpObj->intLineStart=yPos;
	bmpObj->intRowStart=xPos;
	bmpObj->strType1="text";
	bmpObj->strType2="datamatrix";
	bmpObj->intLineSize=my_symbol->bitmap_height;
	bmpObj->intRowSize=my_symbol->bitmap_width;
	bmpObj->intDMsize = nType;
	bmpObj->intDMrow = ui->sideLenDMComBox->currentIndex();
	bmpObj->strDMContent = strContent.toStdString();
	bmpObj->strText = strContent.toStdString();
	//以下先写死
	bmpObj->intSW=1;
	bmpObj->intSS=1;
	bmpObj->booNEG=false;
	bmpObj->booBWDx=false;
	bmpObj->booBWDy=false;
	i = 0;
	int r, g, b;

	for (int row = 0; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
				bmpObj->boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				//		bmpObj.boDotBmp[col][row-proportion] = false;
				bmpObj->boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	bmpObj->strText = strContent.toStdString();
	bmpObj->booFocus = true;
	m_MessagePrint.OBJ_Vec.push_back(bmpObj); 

}

int FileEditChild::GetCharLenFromFont(string txtFont, bool LineOrRow)
{
	map<string,int> fntMap2;
	fntMap2.clear();
	fntMap2.insert(make_pair("5x5",0));
	fntMap2.insert(make_pair("7x5",1));
	fntMap2.insert(make_pair("12x12",2));
	fntMap2.insert(make_pair("16x12",3));

	int RowLength;
	int LineLength;

	switch(fntMap2[txtFont])
	{
	case 0:
		LineLength = 5;
		RowLength = 6;
		break;
	case 1:
		LineLength = 7;
		RowLength = 6;
		break;
	case 2:
		LineLength = 12;
		RowLength = 13;
		break;
	case 3:
		LineLength = 16;
		RowLength = 13;
		break;
	}

	if (LineOrRow == false)
	{
		return LineLength;
	}
	else
	{
		return RowLength;
	}
}

void FileEditChild::PushBackTextOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW)
{
	CTextOBJ* textObj = new CTextOBJ;
	textObj->strType1 = "text";
	textObj->strType2 = "text";
	textObj->strFont = txtFont;
	textObj->strText = txtContent;
	int txtLength = txtContent.length();
	textObj->intLineSize = GetCharLenFromFont(txtFont,false);
	textObj->intRowSize = GetCharLenFromFont(txtFont,true) * txtLength;
	textObj->intLineStart = txtLineStart;
	textObj->intRowStart = txtRowStart;
	textObj->intSW = txtSW;
	textObj->intSS = txtSS;
	textObj->booNEG = txtNEG;
	textObj->booBWDx = txtBWDx;
	textObj->booBWDy = txtBWDy;

	textObj->booFocus = true;
	m_MessagePrint.OBJ_Vec.push_back(textObj); 
}

void FileEditChild::LoadLocalFile()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(parentWidget()); 
 	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
	m_MessagePrint.ReadObjectsFromXml(pFilemanageForm->FormFileManageChild->GetCurXmlFile());
}

void FileEditChild::paintDot()
{
	QPainter painter(ui->editPreviewText);
	m_MessagePrint.DrawDot(&painter);
}

bool FileEditChild::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui->editPreviewText && event->type() == QEvent::Paint)
	{
		paintDot();
		QPainter qFramePainter(this->ui->editPreviewText);
		DrawBackFrame(&qFramePainter);
	}
	else if (watched == ui->editPreviewText->viewport() && event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
		MouseBeenPressed(mouseEvent);
		this->update();
	}
	else if (watched == ui->editPreviewText->viewport() && event->type() == QEvent::MouseButtonRelease)
	{
		QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
		MouseBeenReleased(mouseEvent);
		this->boolMousePressed = false;
		this->update();
	}
	else if (watched == ui->editPreviewText->viewport() && event->type() == QEvent::MouseMove)
	{
		QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
		MouseMoved(mouseEvent);
		this->update();
	}
	return QWidget::eventFilter(watched, event);
}

void FileEditChild::MouseBeenPressed(QMouseEvent *event)
{
	this->pointMousePressed = event->pos();
	int nLin = (241-pointMousePressed.y())/5;
	int nRow = pointMousePressed.x()/5;
	
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			int x1 = m_MessagePrint.OBJ_Vec[i]->intRowStart;
			int y1 = m_MessagePrint.OBJ_Vec[i]->intLineStart;
			int deltX = m_MessagePrint.OBJ_Vec[i]->intRowSize;
			int deltY = m_MessagePrint.OBJ_Vec[i]->intLineSize;
			
			if (nLin>=y1 && nLin<=(y1+deltY) && nRow>=x1 && nRow<=(x1+deltX))
			{
				m_MessagePrint.OBJ_Vec[i]->booBeenDragged = false;
				this->boolMousePressed = true;
				return;
			}
		}
	}
	this->boolMousePressed = false;
}

void FileEditChild::MouseBeenReleased(QMouseEvent *event)
{
	this->pointMousePressed = event->pos();
	QPoint p_Relative = event->pos();
	m_MessagePrint.CtrlCurObjChoice(p_Relative);
	GetObjSettingsFromScreen();
}

void FileEditChild::MouseMoved(QMouseEvent *event)
{
	if (this->boolMousePressed)
	{
		QPoint p_NewMousePoint = event->pos();
		int nLin,nRow,nNewLin,nNewRow; 
		nLin = ( 241 - pointMousePressed.y() ) / 5;
		nRow = pointMousePressed.x() / 5;
		nNewLin = ( 241 - p_NewMousePoint.y() ) / 5;
		nNewRow = p_NewMousePoint.x() / 5;
		for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
		{
			if (m_MessagePrint.OBJ_Vec[i]->booFocus)
			{
				/*if (nNewLin>=m_MessagePrint.OBJ_Vec[i].intLineStart && nNewLin<=(m_MessagePrint.OBJ_Vec[i].intLineStart+m_MessagePrint.OBJ_Vec[i].intLineSize)
				&& nNewRow>=m_MessagePrint.OBJ_Vec[i].intRowStart && nNewRow<=(m_MessagePrint.OBJ_Vec[i].intRowStart+m_MessagePrint.OBJ_Vec[i].intRowSize))
				{}*/
				const int DeltaX = nRow - m_MessagePrint.OBJ_Vec[i]->intRowStart;
				const int DeltaY = nLin - m_MessagePrint.OBJ_Vec[i]->intLineStart;
				if ( (nNewRow - DeltaX) < 0 )
				{
					m_MessagePrint.OBJ_Vec[i]->intRowStart = 0;
				}
				else if ( (nNewRow - DeltaX) > (624 - m_MessagePrint.OBJ_Vec[i]->intRowSize) )
				{
					m_MessagePrint.OBJ_Vec[i]->intRowStart = 624 - m_MessagePrint.OBJ_Vec[i]->intRowSize;
				}
				else if ( (nNewLin - DeltaY) < 0 )
				{
					m_MessagePrint.OBJ_Vec[i]->intLineStart = 0;
				}
				else if ( (nNewLin - DeltaY) > (48 - m_MessagePrint.OBJ_Vec[i]->intLineSize) )
				{
					m_MessagePrint.OBJ_Vec[i]->intLineStart = 48 - m_MessagePrint.OBJ_Vec[i]->intLineSize;
				}
				else
				{
					m_MessagePrint.OBJ_Vec[i]->intRowStart = nNewRow - DeltaX;
					m_MessagePrint.OBJ_Vec[i]->intLineStart = nNewLin - DeltaY;
				}
				m_MessagePrint.OBJ_Vec[i]->booBeenDragged = true;
				break;
				/*else
				{
					m_MessagePrint.OBJ_Vec[i].booBeenDragged = false;
					return;
				}*/
			}
		}
		pointMousePressed = event->pos();
	}
}

QString str2qstr(const string str)  
{  
	return QString::fromLocal8Bit(str.data());  
} 

void FileEditChild::GetObjSettingsFromScreen()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget()); 
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
	MainWindow *pMainWindow = qobject_cast<MainWindow*>(pFilemanageForm->parentWidget());
	sysSetting *psysSetting = qobject_cast<sysSetting*>(pMainWindow->m_paramsetting->m_sysSetting);

	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			CTextOBJ* pTextObj = (CTextOBJ*)(&m_MessagePrint.OBJ_Vec[i]); ;

			QString tmpStr = str2qstr(m_MessagePrint.OBJ_Vec[i]->strText);
			this->ui->internalShowTextLab->setText(QString::number(m_MessagePrint.OBJ_Vec[i]->intSS));
			if (m_MessagePrint.OBJ_Vec[i]->strType2 == "text")
			{
				this->ui->typeTab->setCurrentIndex(0);
				this->ui->wordLineEdit->setText(tmpStr);
				
				switch (psysSetting->m_SelLanguage)
				{
				case 0:
					this->ui->newTextBut->setText(QStringLiteral("تعديل"));
					break;
				case 1:
					this->ui->newTextBut->setText(QStringLiteral("修改"));
					break;
				case 5:
					this->ui->newTextBut->setText(QStringLiteral("Modify"));
					break;
				}
				
				map<string,int> gfntMap;
				gfntMap.clear();
				gfntMap.insert(make_pair("5x5",0));
				gfntMap.insert(make_pair("7x5",1));
				gfntMap.insert(make_pair("12x12",2));
				gfntMap.insert(make_pair("16x12",3));
				switch(gfntMap[m_MessagePrint.OBJ_Vec[i]->strFont])
				{
				case 0:
					this->ui->fontTypeTextComBox->setCurrentIndex(0);
					break;
				case 1:
					this->ui->fontTypeTextComBox->setCurrentIndex(1);
					break;
				case 2:
					this->ui->fontTypeTextComBox->setCurrentIndex(2);
					break;
				case 3:
					this->ui->fontTypeTextComBox->setCurrentIndex(3);
					break;
				}
				
			}
			else if (m_MessagePrint.OBJ_Vec[i]->strType2 == "time")
			{
				CTimeOBJ *pTimeObj = (CTimeOBJ *)(m_MessagePrint.OBJ_Vec[i]);
				this->ui->typeTab->setCurrentIndex(1);
				this->ui->DateTimeEdit->setText(QString::fromStdString(pTimeObj->strTime));
				this->ui->SkewSkewValueEdit->setText(QString::number(pTimeObj->intTimeOffSet));
				this->ui->SkewComBox->setCurrentIndex(pTimeObj->booETimeOffSet);
				this->ui->SkewUUnitlistWidget->setCurrentRow(pTimeObj->strTimeOffSet);
				map<string,int> gfntMap;
				gfntMap.clear();
				gfntMap.insert(make_pair("5x5",0));
				gfntMap.insert(make_pair("7x5",1));
				gfntMap.insert(make_pair("12x12",2));
				gfntMap.insert(make_pair("16x12",3));
				switch(gfntMap[m_MessagePrint.OBJ_Vec[i]->strFont])
				{
				case 0:
					this->ui->fontSizeTimeComBox->setCurrentIndex(0);
					break;
				case 1:
					this->ui->fontSizeTimeComBox->setCurrentIndex(1);
					break;
				case 2:
					this->ui->fontSizeTimeComBox->setCurrentIndex(2);
					break;
				case 3:
					this->ui->fontSizeTimeComBox->setCurrentIndex(3);
					break;
				}

				this->ui->PreviewEdit->setText(tmpStr);
				switch (psysSetting->m_SelLanguage)
				{
				case 0:
					this->ui->newTimeBut->setText(QStringLiteral("تعديل"));
					break;
				case 1:
					this->ui->newTimeBut->setText(QStringLiteral("修改"));
					break;
				case 5:
					this->ui->newTimeBut->setText(QStringLiteral("Modify"));
					break;
				}
				
			}
			else if (m_MessagePrint.OBJ_Vec[i]->strType2 == "serial")
			{
				this->ui->typeTab->setCurrentIndex(2);
				this->ui->serialLineEdit->setText(tmpStr);
				switch (psysSetting->m_SelLanguage)
				{
				case 0:
					this->ui->newSerialBut->setText(QStringLiteral("تعديل"));
					break;
				case 1:
					this->ui->newSerialBut->setText(QStringLiteral("修改"));
					break;
				case 5:
					this->ui->newSerialBut->setText(QStringLiteral("Modify"));
					break;
				}
				
			}
			else if (m_MessagePrint.OBJ_Vec[i]->strType2 == "logo")
			{
				this->ui->typeTab->setCurrentIndex(3);
				//this->ui->serialLineEdit->setText(tmpStr);
				switch (psysSetting->m_SelLanguage)
				{
				case 0:
					this->ui->newBmpBut->setText(QStringLiteral("تعديل"));
					break;
				case 1:
					this->ui->newBmpBut->setText(QStringLiteral("修改"));
					break;
				case 5:
					this->ui->newBmpBut->setText(QStringLiteral("Modify"));
					break;
				}
				
			}
			else if (m_MessagePrint.OBJ_Vec[i]->strType2 == "2Dcode")
			{
				CBarcodeOBJ *pBarcodeObj = (CBarcodeOBJ *)(m_MessagePrint.OBJ_Vec[i]);
				this->ui->typeTab->setCurrentIndex(4);
				this->ui->barCodeLineEdit->setText(QString::fromStdString(pBarcodeObj->strCodeContent));
				this->ui->typeBarCodeComBox->setCurrentIndex(pBarcodeObj->intBarType);
				this->ui->heightBarCodeShowQRLab->setText(QString::number(pBarcodeObj->intLineSize));
				this->ui->whitespaceLab->setText(QString::number(pBarcodeObj->intBarWhite));
				switch (psysSetting->m_SelLanguage)
				{
				case 0:
					this->ui->newBarCodeBut->setText(QStringLiteral("تعديل"));
					break;
				case 1:
					this->ui->newBarCodeBut->setText(QStringLiteral("修改"));
					break;
				case 5:
					this->ui->newBarCodeBut->setText(QStringLiteral("Modify"));
					break;
				}
				
			}
			else if (m_MessagePrint.OBJ_Vec[i]->strType2 == "qrcode")
			{
				CQRcodeOBJ *pQRcodeObj = (CQRcodeOBJ *)(m_MessagePrint.OBJ_Vec[i]);
				this->ui->typeTab->setCurrentIndex(5);
				this->ui->QRCodeLineEdit->setText(tmpStr);
				this->ui->sideLenQRComBox->setCurrentIndex(pQRcodeObj->intQRVersion-1);
				switch (psysSetting->m_SelLanguage)
				{
				case 0:
					this->ui->newQRBut->setText(QStringLiteral("تعديل"));
					break;
				case 1:
					this->ui->newQRBut->setText(QStringLiteral("修改"));
					break;
				case 5:
					this->ui->newQRBut->setText(QStringLiteral("Modify"));
					break;
				}
				
			}
			else if (m_MessagePrint.OBJ_Vec[i]->strType2 == "datamatrix")
			{
				CDMcodeOBJ *pDMcodeObj = (CDMcodeOBJ *)(m_MessagePrint.OBJ_Vec[i]);
				this->ui->typeTab->setCurrentIndex(6);
				this->ui->DMCodeLineEdit->setText(tmpStr);
				this->ui->sideLenDMComBox->setCurrentIndex(pDMcodeObj->intDMrow);
				switch (psysSetting->m_SelLanguage)
				{
				case 0:
					this->ui->newDMBut->setText(QStringLiteral("تعديل"));
					break;
				case 1:
					this->ui->newDMBut->setText(QStringLiteral("修改"));
					break;
				case 5:
					this->ui->newDMBut->setText(QStringLiteral("Modify"));
					break;
				}
			
				//this->ui->newDMBut->setText(QStringLiteral("修改"));
			}
			switch (psysSetting->m_SelLanguage)
			{
			case 0:
				this->ui->delBut->setText(QStringLiteral("حذف"));
				break;
			case 1:
				this->ui->delBut->setText(QStringLiteral("删除"));
				break;
			case 5:
				this->ui->delBut->setText(QStringLiteral("Del"));
				break;
			}
			
			
			return;
		}
	}
	//设置右侧框基础参数
	switch (psysSetting->m_SelLanguage)
	{
	case 0:
		this->ui->delBut->setText(QStringLiteral("تعديل"));
		this->ui->internalShowTextLab->setText("0");

		//设置文本typeTab
		this->ui->wordLineEdit->setText("");
		this->ui->newTextBut->setText(QStringLiteral("الجديدة"));
		this->ui->fontTypeTextComBox->setCurrentIndex(0);

		//设置时间typeTab
		this->ui->PreviewEdit->setText("");
		this->ui->DateTimeEdit->setText("");
		this->ui->newTimeBut->setText(QStringLiteral("الجديدة"));

		//设置序列号typeTab
		this->ui->serialLineEdit->setText("");
		this->ui->newSerialBut->setText(QStringLiteral("الجديدة"));

		//设置图片typeTab
		this->ui->newBmpBut->setText(QStringLiteral("الجديدة"));

		//设置条形码typeTab
		this->ui->barCodeLineEdit->setText("");
		this->ui->typeBarCodeComBox->setCurrentIndex(1);
		this->ui->heightBarCodeShowQRLab->setText("21");
		this->ui->whitespaceLab->setText("9");
		this->ui->showNumCheckBox ->setChecked(1);
		this->ui->newBarCodeBut->setText(QStringLiteral("الجديدة"));

		//设置QR码typeTab
		this->ui->QRCodeLineEdit->setText("");
		this->ui->newQRBut->setText(QStringLiteral("الجديدة"));

		//设置DM码typeTab
		this->ui->DMCodeLineEdit->setText("");
		this->ui->newDMBut->setText(QStringLiteral("الجديدة"));
		break;
	case 1:
		this->ui->delBut->setText(QStringLiteral("清空"));
		this->ui->internalShowTextLab->setText("0");

		//设置文本typeTab
		this->ui->wordLineEdit->setText("");
		this->ui->newTextBut->setText(QStringLiteral("新建"));
		this->ui->fontTypeTextComBox->setCurrentIndex(0);

		//设置时间typeTab
		this->ui->PreviewEdit->setText("");
		this->ui->DateTimeEdit->setText("");
		this->ui->newTimeBut->setText(QStringLiteral("新建"));

		//设置序列号typeTab
		this->ui->serialLineEdit->setText("");
		this->ui->newSerialBut->setText(QStringLiteral("新建"));

		//设置图片typeTab
		this->ui->newBmpBut->setText(QStringLiteral("新建"));

		//设置条形码typeTab
		this->ui->barCodeLineEdit->setText("");
		this->ui->typeBarCodeComBox->setCurrentIndex(1);
		this->ui->heightBarCodeShowQRLab->setText("21");
		this->ui->whitespaceLab->setText("9");
		this->ui->showNumCheckBox ->setChecked(1);
		this->ui->newBarCodeBut->setText(QStringLiteral("新建"));

		//设置QR码typeTab
		this->ui->QRCodeLineEdit->setText("");
		this->ui->newQRBut->setText(QStringLiteral("新建"));

		//设置DM码typeTab
		this->ui->DMCodeLineEdit->setText("");
		this->ui->newDMBut->setText(QStringLiteral("新建"));
		break;
	case 5:
		this->ui->delBut->setText(QStringLiteral("Empty"));
		this->ui->internalShowTextLab->setText("0");

		//设置文本typeTab
		this->ui->wordLineEdit->setText("");
		this->ui->newTextBut->setText(QStringLiteral("New"));
		this->ui->fontTypeTextComBox->setCurrentIndex(0);

		//设置时间typeTab
		this->ui->PreviewEdit->setText("");
		this->ui->DateTimeEdit->setText("");
		this->ui->newTimeBut->setText(QStringLiteral("New"));

		//设置序列号typeTab
		this->ui->serialLineEdit->setText("");
		this->ui->newSerialBut->setText(QStringLiteral("New"));

		//设置图片typeTab
		this->ui->newBmpBut->setText(QStringLiteral("New"));

		//设置条形码typeTab
		this->ui->barCodeLineEdit->setText("");
		this->ui->typeBarCodeComBox->setCurrentIndex(1);
		this->ui->heightBarCodeShowQRLab->setText("21");
		this->ui->whitespaceLab->setText("9");
		this->ui->showNumCheckBox ->setChecked(1);
		this->ui->newBarCodeBut->setText(QStringLiteral("New"));

		//设置QR码typeTab
		this->ui->QRCodeLineEdit->setText("");
		this->ui->newQRBut->setText(QStringLiteral("New"));

		//设置DM码typeTab
		this->ui->DMCodeLineEdit->setText("");
		this->ui->newDMBut->setText(QStringLiteral("New"));
		break;
	}	
}

void FileEditChild::saveasBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
	string tmpFileName;
	//判断当前编辑的文件是否为本地文件
	if (pFilemanageForm->FormFileManageChild->boolFileSelected == true) //来源于本地
	{
		QString qfileName = pFilemanageForm->FormFileManageChild->ui->filelistWidget->currentItem()->text();
		QFileInfo fi(qfileName);
		qfileName = fi.baseName();
		tmpFileName = qfileName.toStdString();
	}
	else //新建文件
	{
		tmpFileName = "NewLabel_";
		//m_MessagePrint.strMatrix = "1L7M";
		//m_MessagePrint.Pixel = 7;
		m_MessagePrint.Reverse = "GLOBAL";
		m_MessagePrint.Inverse = "GLOBAL";
	}
	pFilemanageForm->FormFileManageChild->boolSaveAsBtn_Clicked = true;
	char* tmpChar = m_MessagePrint.GenerateFileName((tmpFileName));
	char FilePath[256];
	sprintf(FilePath,"%s",tmpChar);
	QString tmpFilePathStr = QString::fromStdString(FilePath);
	QFileInfo fi(tmpFilePathStr);
	QListWidgetItem *tmpItem = new QListWidgetItem(pFilemanageForm->FormFileManageChild->ui->filelistWidget);
	tmpItem->setText(fi.baseName()+".lab");
	pFilemanageForm->FormFileManageChild->ui->filelistWidget->addItem(tmpItem);
	pFilemanageForm->FormFileManageChild->ui->filelistWidget->setCurrentItem(tmpItem);
	pFilemanageForm->FormFileManageChild->SetButtonEnableOn();
	pFilemanageForm->FormFileManageChild->PreviewSaveFile();
	pFilemanageForm->FileManageChildWidgetCall();
}

void FileEditChild::saveBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	//判断文件是新建的，还是来源于本地
	if (pFilemanageForm->FormFileManageChild->boolFileSelected == true) //来源于本地
	{
		QString qfileName = pFilemanageForm->FormFileManageChild->ui->filelistWidget->currentItem()->text();
		string tmpStr = qfileName.toStdString();
		char tmpFilePath[256];
		sprintf(tmpFilePath,"User/Label/%s",tmpStr.c_str());
		m_MessagePrint.SaveObjectsToXml(tmpFilePath);
		pFilemanageForm->FormFileManageChild->PreviewLocalFile();
		//此处应当弹出"保存成功！"对话框，持续一秒
	}
	else //新建文件，与"另存为"相同
	{
		saveasBut_clicked();
	}
}

void FileEditChild::variableTextBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->variableWidgetCall();
}

void FileEditChild::variableBarCodeBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->variableBarCodeWidgetCall();
}

void FileEditChild::variableQRBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->variableQRWidgetCall();
}

void FileEditChild::variableDMBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->variableDMWidgetCall();
}

void FileEditChild::customTimeBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->timeCustomCall();
}

void FileEditChild::ChangeBmpWH(QImage& pImage,double nS)
{
	int nH,nW;
	if (ui->proportionBmpCheckBox->isChecked())
	{
	    if(boolHWchange)
		{
			nH = ui->heightBmpShowBmpLineEdit->text().toInt();
			nW = nH/nS;
			ui->widthShowBmpLineEdit->setText(QString::number(nW));	 
		}
		else
	    {
			nW = ui->widthShowBmpLineEdit->text().toInt();
		    nH = nS*nW;
			ui->heightBmpShowBmpLineEdit->setText(QString::number(nH));	 
		}
	}
    else
	{
       nH = ui->heightBmpShowBmpLineEdit->text().toInt();
	   nW = ui->widthShowBmpLineEdit->text().toInt();
	}
 	pImage = pImage.scaled(nW,nH);  
}

void FileEditChild::ReadBmp(char* strFileName)
{
	QPixmap pLoad;
	pLoad.load(strFileName);
	//int nW = pLoad.width();
	//int nH = pLoad.height();
	QImage pImage;
	pImage = pLoad.toImage();
	int h=pImage.height();
	int	w=pImage.width();
	double nS=(double)h/w;
	ChangeBmpWH(pImage,nS);

	OBJ_Control* bmpObj = new OBJ_Control;
	bmpObj->intLineStart=0;
	bmpObj->intRowStart=0;
	bmpObj->strType1="text";
	bmpObj->strType2="logo";
	bmpObj->strText = strFileName;
	bmpObj->intLineSize=pImage.height();
	bmpObj->intRowSize=pImage.width();
	bmpObj->intSW=1;
	bmpObj->intSS=0;
	bmpObj->booNEG=false;
	bmpObj->booBWDx=false;
	bmpObj->booBWDy=false;

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			if (ui->reverseBmpCheckBox->isChecked())
           { int average = (qRed(line[x]) + qGreen(line[x]) + qBlue(line[x]))/3;  
			 if(average < 200)
				bmpObj->boDotBmp[bmpObj->intRowStart+x][bmpObj->intLineStart+y] = false;
			 else
				bmpObj->boDotBmp[bmpObj->intRowStart+x][bmpObj->intLineStart+y] = true;
           }
			else
			{ int average = (qRed(line[x]) + qGreen(line[x]) + qBlue(line[x]))/3;  
			  if(average < 200)
				bmpObj->boDotBmp[bmpObj->intRowStart+x][bmpObj->intLineStart+y] = true;
			 else
				 bmpObj->boDotBmp[bmpObj->intRowStart+x][bmpObj->intLineStart+y] = false;
		     }
		}  

	}  
	bmpObj->booFocus = true;
	m_MessagePrint.OBJ_Vec.push_back(bmpObj); 

}

//PreviewBmp(bmpFileRelativePath,nW,nH)
void  FileEditChild::PreviewBmp(QString fileName,int pW,int pH)
{
	QImage image,result;
	image.load(fileName); 
	if(pW == 0 || pH == 0) return;
	double pS = pH*1.0/pW;
	if (pS > 291.0/471)
	{ 
		pH = 291;
		pW = 291/pS;
	}
	else
	{
		pW = 471;
		pH = 471*pS;  
	}
	result = image.scaled(pW,pH,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//放缩图片，以固定大小显示
	ui->bmpPreviewLab->setPixmap(QPixmap::fromImage(result));//在Label控件上显示图片
	QFileInfo bmpInfo(fileName);
	bmpFileRelativePath = "User/logo/" + bmpInfo.baseName() + ".bmp";
	 
	ui->heightBmpShowBmpLineEdit->setText(QString::number(image.height()));
	ui->widthShowBmpLineEdit->setText(QString::number(image.width()));	 
}

void FileEditChild::selBmpBut_clicked()
{
	fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "User/logo/", tr("Image Files (*.png *.jpg *.bmp)"));
	QImage image,result;
	image.load(fileName); 
	int pW = image.width();
	int pH = image.height();	 
	PreviewBmp(fileName,pW,pH);	
}

void FileEditChild::PreviewBmpChange()
{
	ui->bmpPreviewLab->clear();
	QImage image1;
	image1.load(fileName);
	ChangeBmpWH(image1,1);//nS暂时设为1
	ui->bmpPreviewLab->setPixmap(QPixmap::fromImage(image1));//在Label控件上显示图片
}

void FileEditChild::delBut_clicked()
{
	vector<OBJ_Control*>::iterator ite;
	for(ite = m_MessagePrint.OBJ_Vec.begin(); ite != m_MessagePrint.OBJ_Vec.end();)
	{
		if((*ite)->booFocus)
		{
			if (m_MessagePrint.OBJ_Vec.back()->counter>=0)//如果为序列号，则计数器-1
			{
				int i;
				i=ui->counterSerialComBox->currentIndex();
				i--;
				if (i>=0)
				{		
					ui->counterSerialComBox->setCurrentIndex(i);
				}
			}
			delete (*ite); //release memmory
			ite = m_MessagePrint.OBJ_Vec.erase(ite);
			/*QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget()); 
			FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
			MainWindow *pMainWindow = qobject_cast<MainWindow*>(pFilemanageForm->parentWidget());
			sysSetting *psysSetting = qobject_cast<sysSetting*>(pMainWindow->m_paramsetting->m_sysSetting);

			switch (psysSetting->m_SelLanguage)
			{
			case 1:
				this->ui->newTextBut->setText(QStringLiteral("修改"));
				this->ui->delBut->setText(QStringLiteral("清空"));
				break;
			case 5:
				this->ui->newTextBut->setText(QStringLiteral("New"));
				this->ui->delBut->setText(QStringLiteral("Empty"));
				break;
			}*/
	    	this->ui->delBut->setText(QStringLiteral("清空"));
			GetObjSettingsFromScreen();
			this->update();
			return;
		}
		else
			++ite;
	}

	m_MessagePrint.OBJ_Vec.clear();

	ui->counterSerialComBox->setCurrentIndex(0);//计数器重置
	serialcount=1;
	QString c=ui->startValSerialLineEdit->text();
	int new_start=c.toInt();
	SerialNumber_number=new_start;
	Serialfirst=1;
	GetObjSettingsFromScreen();
	this->update();
}

void FileEditChild::wordLineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->wordLineEdit);
	ClickChooseLanguage();
}

void FileEditChild::barCodeLineEdit_clicked()
{
 	keyboardWidget->SetLineEdit(ui->barCodeLineEdit);
	ClickChooseLanguage();

}

void FileEditChild::QRCodeLineEdit_clicked()
{
 	keyboardWidget->SetLineEdit(ui->QRCodeLineEdit);
	ClickChooseLanguage();

}

void FileEditChild::DMCodeLineEdit_clicked()
{
  	keyboardWidget->SetLineEdit(ui->DMCodeLineEdit);
	ClickChooseLanguage();
}

void FileEditChild::setText2wordLineEdit()
{
	keyboardWidget->changeLineEdit(ui->wordLineEdit);
}

void FileEditChild::setText2shiftNumShowLineEdit()
{
	if (m_ShiftLineEditType == 1)
	{
		keyboardWidget->changeLineEdit(ui->shiftNumShowLineEdit);
	}
	else if (m_ShiftLineEditType == 2)
	{
		keyboardWidget->changeLineEdit(ui->textLenShowLineEdit);
	}
	else if (m_ShiftLineEditType == 3)
	{
		keyboardWidget->changeLineEdit(ui->startTimeShowSft1LineEdit);
	}
	else if (m_ShiftLineEditType == 4)
	{
		keyboardWidget->changeLineEdit(ui->textIDShowSft1LineEdit);
	}
	else if (m_ShiftLineEditType == 5)
	{
		keyboardWidget->changeLineEdit(ui->startTimeShowSft2LineEdit);
	}
	
	else if (m_ShiftLineEditType == 6)
	{
		keyboardWidget->changeLineEdit(ui->textIDShowSft2LineEdit);
	}
	else if (m_ShiftLineEditType == 7)
	{
		keyboardWidget->changeLineEdit(ui->startTimeShowSft3LineEdit);
	}
	else if (m_ShiftLineEditType == 8)
	{
		keyboardWidget->changeLineEdit(ui->textIDShowSft3LineEdit);
	}
	else if (m_ShiftLineEditType == 9)
	{
		keyboardWidget->changeLineEdit(ui->startTimeShowSft4LineEdit);
	}
	
	else if (m_ShiftLineEditType == 10)
	{
		keyboardWidget->changeLineEdit(ui->textIDShowSft4LineEdit);
	}
}

void FileEditChild::setText2barCodeLineEdit()
{
	keyboardWidget->changeLineEdit(ui->barCodeLineEdit);
}

void FileEditChild::setText2QRCodeLineEdit()
{
	keyboardWidget->changeLineEdit(ui->QRCodeLineEdit);
}

void FileEditChild::setText2DMCodeLineEdit()
{
	keyboardWidget->changeLineEdit(ui->DMCodeLineEdit);
}

void FileEditChild::ChangeTabLineEdit()
{
	int nIndex = ui->typeTab->currentIndex();
	switch(nIndex)
	{
		case 0:	setText2wordLineEdit();break;
		case 4:	setText2shiftNumShowLineEdit();break;
		case 5: setText2barCodeLineEdit();break;
		case 6:	setText2QRCodeLineEdit();break;
		case 7:	setText2DMCodeLineEdit();break;
	}	
}

void FileEditChild::KeyboardConceal_clicked()
{
	keyboardWidget->setVisible(false);
}

string qstr2str(const QString qstr)  
{  
	QByteArray cdata = qstr.toLocal8Bit();  
	return string(cdata);  
} 

void FileEditChild::newTextBut_clicked()
{
	//如果当前有obj被选中，则为更改当选中的obj
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			CTextOBJ* pTextObj = (CTextOBJ*)(&m_MessagePrint.OBJ_Vec[i]);
			string tmpStr = qstr2str(this->ui->wordLineEdit->text());
			m_MessagePrint.OBJ_Vec[i]->strText = tmpStr;
			string tmpFont = this->ui->fontTypeTextComBox->currentText().toStdString();
			m_MessagePrint.OBJ_Vec[i]->strFont = tmpFont;
			switch(this->ui->fontTypeTextComBox->currentIndex())
			{
			case 0:
				m_MessagePrint.OBJ_Vec[i]->intLineSize = 5;
				break;
			case 1:
				m_MessagePrint.OBJ_Vec[i]->intLineSize = 7;
				break;
			case 2:
				m_MessagePrint.OBJ_Vec[i]->intLineSize = 12;
				break;
			case 3:
				m_MessagePrint.OBJ_Vec[i]->intLineSize = 16;
				break;
			}
			this->update();
			return;
		}
	}
	//如果当前没有obj被选中，则为新建
	//wstring txtString = stringToWstring(ui->wordLineEdit->text().toStdString());
	string txtString = qstr2str(ui->wordLineEdit->text());
	string textFont = ui->fontTypeTextComBox->currentText().toStdString();
	//int intTmpSS = ui->internalShowTextLab->text().toInt();
	PushBackTextOBJ(textFont,false,false,false,txtString,0,0,0,1);

	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget()); 
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
	MainWindow *pMainWindow = qobject_cast<MainWindow*>(pFilemanageForm->parentWidget());
	sysSetting *psysSetting = qobject_cast<sysSetting*>(pMainWindow->m_paramsetting->m_sysSetting);

	switch (psysSetting->m_SelLanguage)
	{
	case 0:
		this->ui->newTextBut->setText(QStringLiteral("تعديل"));
		this->ui->delBut->setText(QStringLiteral("حذف"));
		break;

	case 1:
		this->ui->newTextBut->setText(QStringLiteral("修改"));
		this->ui->delBut->setText(QStringLiteral("删除"));
		break;
	case 5:
		this->ui->newTextBut->setText(QStringLiteral("Modify"));
		this->ui->delBut->setText(QStringLiteral("Del"));
		break;
	}
	//this->ui->newTextBut->setText(QStringLiteral("修改"));
	
	this->update();
}

void FileEditChild::GenerateBarCodeBmp()
{
		QMap <QString , int> BarCodeType;
		BarCodeType.insert("EANX",13);
		BarCodeType.insert("CODE39",8);
		BarCodeType.insert("CODE93",25);
		BarCodeType.insert("CODE128",20);
		BarCodeType.insert("UPCA",34);
		BarCodeType.insert("UPCE",37);
		BarCodeType.insert("ITF14",89);
		BarCodeType.insert("PDF417",55);
	
		struct zint_symbol *my_symbol;
		int error_number;
		int rotate_angle;
		int generated;
		int batch_mode;
		int mirror_mode;
		char filetype[4];
		//int i;
		int longth;
		int derta;
		derta=1;
		longth=0;
		error_number = 0;
		rotate_angle = 0;
		generated = 0;
		my_symbol = ZBarcode_Create();
		my_symbol->input_mode = UNICODE_MODE;
		my_symbol->symbology = BarCodeType[this->ui->typeBarCodeComBox->currentText()];
		QString str = getNum(ui->heightBarCodeShowQRLab->text());
		int heightvalue1 = str.toInt();
		if (heightvalue1<28)
		{	
			my_symbol->height =5;	 
		} 
		else
		{
			my_symbol->height=heightvalue1/2-9;
		}
		my_symbol->scale =1;
		batch_mode = 0;
		mirror_mode = 0;
		QString str1 = getNum(ui->whitespaceLab->text());
		my_symbol->whitespace_width = str1.toInt();//改变条形码两边空白区域宽度,空白区域宽度会影响条形码的宽度，只会增加条码左右两侧的空白
		if (ui->typerimComBox->currentIndex()==0)
		{
			my_symbol->output_options= 1;
		} 
		else if(ui->typerimComBox->currentIndex()==1)
		{
			my_symbol->output_options=2;
		}
		else
		{
			my_symbol->output_options=4;
		}
		//有无边框之类的控制;1:无边框，2：上下两条边界线，4：四条边框
		QString str2 = getNum(ui->rimwideLab->text());
		my_symbol->border_width = str2.toInt();//改变边框宽度           

		int show_hrt;            //设置为1 显示文本在条码图片下面 设置为0 则不显示
		if (ui->showNumCheckBox->isChecked())
		{
			my_symbol->show_hrt=1;
		} 
	
		else  {my_symbol->show_hrt=0;}
		strcpy_s(my_symbol->outfile, "User/logo/output.bmp");
		error_number = ZBarcode_Encode(my_symbol, (unsigned char*) this->ui->barCodeLineEdit->text().toStdString().c_str(), 0);
		generated=1;
		
		if (error_number != 0)
			{
				/* some error occurred */
				string errortext = my_symbol->errtxt;
				informationMessage(errortext);
			}
		else
		{
		ZBarcode_Print(my_symbol, 0);
		}
		ZBarcode_Delete(my_symbol);
}

void FileEditChild::newBarCodeBut_clicked()
{
	QMap <QString , int> BarCodeType;
	BarCodeType.insert("EANX",13);
	BarCodeType.insert("CODE39",8);
	BarCodeType.insert("CODE93",25);
	BarCodeType.insert("CODE128",20);
	BarCodeType.insert("UPCA",34);
	BarCodeType.insert("UPCE",37);
	BarCodeType.insert("ITF14",89);
	BarCodeType.insert("PDF417",55);
	
	//修改当前obj
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			CBarcodeOBJ *pBarcodeObj = (CBarcodeOBJ *)(&m_MessagePrint.OBJ_Vec[i]);
			GenerateBarCodeBmp();
			int heightvalue1 = ui->heightBarCodeShowQRLab->text().toInt();
			char* strFileName = "User/logo/output.bmp";
			QPixmap pLoad;
			pLoad.load(strFileName);
			int nW = pLoad.width();
			int nH = pLoad.height();
			QImage pImage;
			pImage = pLoad.toImage();
			pImage = pImage.scaled(pImage.width(),heightvalue1, Qt::IgnoreAspectRatio, Qt::SmoothTransformation); 

			pBarcodeObj->strCodeContent = this->ui->barCodeLineEdit->text().toStdString();
			pBarcodeObj->intBarcodeType = BarCodeType[this->ui->typeBarCodeComBox->currentText()];
			pBarcodeObj->intBarType = this->ui->typeBarCodeComBox->currentIndex();
			pBarcodeObj->intBarWhite = this->ui->whitespaceLab->text().toInt();
			pBarcodeObj->intLineSize = pImage.height();
			pBarcodeObj->intRowSize = pImage.width();

			for(int y = 0; y< pImage.height(); y++)
			{  
				QRgb* line = (QRgb *)pImage.scanLine(y);  
				for(int x = 0; x< pImage.width(); x++)
				{  
					int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
					if(average < 200)
						m_MessagePrint.OBJ_Vec[i]->boDotBmp[x][m_MessagePrint.OBJ_Vec[i]->intLineSize -y-1] = true;
					else
						m_MessagePrint.OBJ_Vec[i]->boDotBmp[x][m_MessagePrint.OBJ_Vec[i]->intLineSize -y-1] = false;
				}

			} 
			if (nW ==0 && nH ==0)
			{
				delBut_clicked();
			}
			QString get = QString(QLatin1String(strFileName)).toUtf8();
			//删除文件
			QFile::remove(get);
			this->update();
			return;
		}
	}
	//如果当前没有obj被选中，则为新建
	QString str = ui->barCodeLineEdit->text();
	Create2Dcode(BarCodeType[this->ui->typeBarCodeComBox->currentText()],str);
	this->ui->newBarCodeBut->setText(QStringLiteral("�޸�"));
	this->update();
}

void FileEditChild::newQRBut_clicked()
{
	QString str;
	str = ui->QRCodeLineEdit->text();
	//修改当前obj
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			CQRcodeOBJ *pQRcodeObj = (CQRcodeOBJ *)(&m_MessagePrint.OBJ_Vec[i]);
			m_MessagePrint.OBJ_Vec[i]->strType1="text";
			m_MessagePrint.OBJ_Vec[i]->strType2="qrcode";
			m_MessagePrint.OBJ_Vec[i]->intLineSize = resetQRCode().bitmap_height;
			m_MessagePrint.OBJ_Vec[i]->intRowSize = resetQRCode().bitmap_width;
			pQRcodeObj->intQRVersion = ui->sideLenQRComBox->currentIndex()+1;

			int r, g, b;
			int intQRbitmap = 0;
			for (int row = 0; row < resetQRCode().bitmap_height; row++)
			{
				for (int col = 0;col < resetQRCode().bitmap_width; col++)
				{
					r = resetQRCode().bitmap[intQRbitmap];
					g = resetQRCode().bitmap[intQRbitmap + 1];
					b = resetQRCode().bitmap[intQRbitmap + 2];
					intQRbitmap += 3;
					if (r == 0 && g == 0 && b == 0)
					{
						//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
						m_MessagePrint.OBJ_Vec[i]->boDotBmp[col][m_MessagePrint.OBJ_Vec[i]->intLineSize-row-1] = true;
					}
					else
					{
						//		bmpObj.boDotBmp[col][row-proportion] = false;
						m_MessagePrint.OBJ_Vec[i]->boDotBmp[col][m_MessagePrint.OBJ_Vec[i]->intLineSize-row-1] = false;
					}
				}
			}
			if (m_MessagePrint.OBJ_Vec[i]->intLineSize ==0 && m_MessagePrint.OBJ_Vec[i]->intRowSize ==0)
			{
				delBut_clicked();
			}
		//	m_MessagePrint.OBJ_Vec[i].booFocus = true;
			this->update();
			return;
		}
	}
	//如果当前没有obj被选中，则为新建
	CreateQrcode(58,str);
	this->ui->newQRBut->setText(QStringLiteral("修改"));
	this->update();
}

zint_symbol FileEditChild::resetQRCode()
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	//int i;
	int v;

	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = 58; 
	my_symbol->scale =0.5;

	v=ui->sideLenQRComBox->currentIndex();
	my_symbol->option_2 = v+1;//option_1为容错等级，option_2为版本大小公式为:(V - 1) * 4 + 21；
	if (ui->reverseCheckBox->isChecked())
	{
		strcpy_s(my_symbol->fgcolour, "ffffff");
		strcpy_s(my_symbol->bgcolour, "000000");
	}
	batch_mode = 0;
	mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) ui->QRCodeLineEdit->text().toStdString().c_str(),ui->QRCodeLineEdit->text().toStdString().length(),rotate_angle);

	if (error_number != 0)
	{
		/* some error occurred */
		string errortext = my_symbol->errtxt;
		informationMessage(errortext);
	}
	else
	{
		generated = 1;
		return *my_symbol;
	}
}

void FileEditChild::newDMBut_clicked()
{	
	QString str;
	str = ui->DMCodeLineEdit->text();
	QMap <QString , int> DMsize;
	DMsize.insert("18x18",5);
	DMsize.insert("20x20",6);
	DMsize.insert("22x22",7);
	DMsize.insert("24x24",8);
	DMsize.insert("32x32",10);
	DMsize.insert("36x36",11);
	DMsize.insert("40x40",12);
	DMsize.insert("8x18",25);
	DMsize.insert("8x32",26);
	DMsize.insert("12x26",27);
	DMsize.insert("12x36",28);
	DMsize.insert("16x36",29);
	DMsize.insert("16x48",30);
	//修改当前obj
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		//m_MessagePrint.OBJ_Vec.clear();
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			CDMcodeOBJ *pDMcodeObj = (CDMcodeOBJ*)(&m_MessagePrint.OBJ_Vec[i]);
			m_MessagePrint.OBJ_Vec[i]->intLineSize=resetDMCode().bitmap_height;
			m_MessagePrint.OBJ_Vec[i]->intRowSize=resetDMCode().bitmap_width;
			pDMcodeObj->strDMContent = str.toStdString();
			pDMcodeObj->intDMsize = DMsize[this->ui->sideLenDMComBox->currentText()];
			pDMcodeObj->intDMrow = this->ui->sideLenDMComBox->currentIndex();
			int j = 0;
			int r, g, b;

			for (int row = 0; row < resetDMCode().bitmap_height; row++)
			{
				for (int col = 0;col < resetDMCode().bitmap_width; col++)
				{
					r = resetDMCode().bitmap[j];
					g = resetDMCode().bitmap[j + 1];
					b = resetDMCode().bitmap[j + 2];
					j += 3;
					if (r == 0 && g == 0 && b == 0)
					{
						//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
						m_MessagePrint.OBJ_Vec[i]->boDotBmp[col][resetDMCode().bitmap_height-row-1] = true;
					}
					else
					{
						//		bmpObj.boDotBmp[col][row-proportion] = false;
						m_MessagePrint.OBJ_Vec[i]->boDotBmp[col][resetDMCode().bitmap_height-row-1] = false;
					}
				}
			}
			this->update();
			return;
		}
	}
	//如果当前没有obj被选中，则为新建
	CreateDMcode(DMsize[this->ui->sideLenDMComBox->currentText()],str);
	this->ui->newDMBut->setText(QStringLiteral("修改"));
	this->update();
}

zint_symbol FileEditChild::resetDMCode()
{
	QMap <QString , int> DMsize;
	DMsize.insert("18x18",5);
	DMsize.insert("20x20",6);
	DMsize.insert("22x22",7);
	DMsize.insert("24x24",8);
	DMsize.insert("32x32",10);
	DMsize.insert("36x36",11);
	DMsize.insert("40x40",12);
	DMsize.insert("8x18",25);
	DMsize.insert("8x32",26);
	DMsize.insert("12x26",27);
	DMsize.insert("12x36",28);
	DMsize.insert("16x36",29);
	DMsize.insert("16x48",30);

	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;

	error_number = 0;

	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = 1;
	my_symbol->symbology = 71;
	my_symbol->scale =0.5;

	my_symbol->option_2 = DMsize[this->ui->sideLenDMComBox->currentText()];
	if (ui->reverseDMCheckBox->isChecked())
	{
		strcpy_s(my_symbol->fgcolour, "ffffff");
		strcpy_s(my_symbol->bgcolour, "000000");
	}
	batch_mode = 0;
	mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) ui->DMCodeLineEdit->text().toStdString().c_str(),ui->DMCodeLineEdit->text().toStdString().length(),rotate_angle);

	if (error_number != 0)
	{
		/* some error occurred */
		string errortext = my_symbol->errtxt;
		informationMessage(errortext);
	}
	generated = 1;

	return *my_symbol;
}

void FileEditChild::newBmpBut_clicked()
{
	//PreviewBmp(bmpFileRelativePath,320,20); return;

	//如果当前有obj被选中，则为修改当选中的obj
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			//在此处根据控件选项重新设置OBJ_Vec[i]的相应参数即可,切记此处不是pushback
			this->update();
			return;
		}
	}
	//如果当前没有obj被选中，则为新建
	char *pic;
	QByteArray ba = bmpFileRelativePath.toLatin1();
	pic=ba.data();
	ReadBmp(pic);
	this->ui->newBmpBut->setText(QStringLiteral("修改"));
	this->update();
}

void FileEditChild::internalTextAddBut_clicked()
{
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			m_MessagePrint.OBJ_Vec[i]->intSS += 1;
			QString tmpStr = QString::number(m_MessagePrint.OBJ_Vec[i]->intSS);
			this->ui->internalShowTextLab->setText(tmpStr);
			return;
		}
	}
	this->ui->internalShowTextLab->setText("0");
}

void FileEditChild::internalTextRedBut_clicked()
{
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus && m_MessagePrint.OBJ_Vec[i]->intSS != 0)
		{
			m_MessagePrint.OBJ_Vec[i]->intSS -= 1;
			QString tmpStr = QString::number(m_MessagePrint.OBJ_Vec[i]->intSS);
			this->ui->internalShowTextLab->setText(tmpStr);
			return;
		}
	}
	this->ui->internalShowTextLab->setText("0");
}

void FileEditChild::moveUpBut_clicked()
{
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			int EndPos = m_MessagePrint.OBJ_Vec[i]->intLineStart + m_MessagePrint.OBJ_Vec[i]->intLineSize;
			int MoveSpeed = this->ui->moveSpeedComBox->currentText().toInt();
			if( (EndPos + MoveSpeed) < 48 )
			{
				m_MessagePrint.OBJ_Vec[i]->intLineStart += MoveSpeed;
			}
			else
			{
				m_MessagePrint.OBJ_Vec[i]->intLineStart = 48 - m_MessagePrint.OBJ_Vec[i]->intLineSize;
			}
		}
	}
	this->update();
}

void FileEditChild::moveDownBut_clicked()
{
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			int MoveSpeed = this->ui->moveSpeedComBox->currentText().toInt();
			if( m_MessagePrint.OBJ_Vec[i]->intLineStart - MoveSpeed > 0 )
			{
				m_MessagePrint.OBJ_Vec[i]->intLineStart -= MoveSpeed;
			}
			else
			{
				m_MessagePrint.OBJ_Vec[i]->intLineStart = 0 ;
			}
		}
	}
	this->update();
}

void FileEditChild::moveLeftBut_clicked()
{
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			int MoveSpeed = this->ui->moveSpeedComBox->currentText().toInt();
			if( m_MessagePrint.OBJ_Vec[i]->intRowStart - MoveSpeed > 0 )
			{
				m_MessagePrint.OBJ_Vec[i]->intRowStart -= MoveSpeed;
			}
			else
			{
				m_MessagePrint.OBJ_Vec[i]->intRowStart = 0;
			}
		}
	}
	this->update();
}

void FileEditChild::moveRightBut_clicked()
{
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			int EndPos = m_MessagePrint.OBJ_Vec[i]->intRowStart + m_MessagePrint.OBJ_Vec[i]->intRowSize;
			int MoveSpeed = this->ui->moveSpeedComBox->currentText().toInt();
			if( EndPos + MoveSpeed < 624 )
			{
				m_MessagePrint.OBJ_Vec[i]->intRowStart += MoveSpeed;
			}
			else
			{
				m_MessagePrint.OBJ_Vec[i]->intRowStart = 624 - m_MessagePrint.OBJ_Vec[i]->intRowSize;
			}
		}
	}
	this->update();
}

void FileEditChild::deleteChar()
{
	ui->wordLineEdit->backspace();
	str1 = ui->wordLineEdit->text();
}

void FileEditChild::showNumCheckBox_clicked()
{
	
}

void FileEditChild::addTimeBut_clicked()
{
	int nSelect=ui->FormatlistWidget->currentRow();
	QString timeFormatStr;
	timeFormatStr=ui->DateTimeEdit->text();
	switch(nSelect)
	{
	case 0:
		if ((timeFormatStr.indexOf("%Y")==-1)&&(timeFormatStr.indexOf("%y")==-1))
			timeFormatStr+=("%Y");
		break;
	case 1:
		if ((timeFormatStr.indexOf("%Y")==-1)&&(timeFormatStr.indexOf("%y")==-1))
			timeFormatStr+=("%y");
		break;
	case 2:
		if (timeFormatStr.indexOf("%m")==-1)
			timeFormatStr+=("%m");
		break;
	case 3:
		if (timeFormatStr.indexOf("%d")==-1)
			timeFormatStr+=("%d");
		break;
	case 4:
		if ((timeFormatStr.indexOf("%H")==-1)&&(timeFormatStr.indexOf("%I")==-1))
			timeFormatStr+=("%H");
		break;
	case 5:
		if ((timeFormatStr.indexOf("%H")==-1)&&(timeFormatStr.indexOf("%I")==-1))
			timeFormatStr+=("%I");
		break;
	case 6:
		if (timeFormatStr.indexOf("%M")==-1)
			timeFormatStr+=("%M");
		break;
	case 7:
		if (timeFormatStr.indexOf("%S")==-1)
			timeFormatStr+=("%S");
		break;
	case 8:
		if ((timeFormatStr.indexOf("%U")==-1)&&(timeFormatStr.indexOf("%W")==-1))
			timeFormatStr+= ("%U");
		break;
	case 9:
		if ((timeFormatStr.indexOf("%U")==-1)&&(timeFormatStr.indexOf("%W")==-1))
			timeFormatStr+= ("%W");
		break;
	case 10:
		if (timeFormatStr.indexOf("%w")==-1)
			timeFormatStr+= ("%w");
		break;
	case 11:
		if (timeFormatStr.indexOf("%j")==-1)
			timeFormatStr+= ("%j");
		break;
	case 12:
		if ((timeFormatStr.indexOf("%a")==-1)&&(timeFormatStr.indexOf("%A")==-1))
			timeFormatStr+= ("%a");
		break;
	case 13:
		if ((timeFormatStr.indexOf("%a")==-1)&&(timeFormatStr.indexOf("%A")==-1))
			timeFormatStr+= ("%A");
		break;
	case 14:
		if ((timeFormatStr.indexOf("%b")==-1)&&(timeFormatStr.indexOf("%B")==-1))
			timeFormatStr+= ("%b");
		break;
	case 15:
		if ((timeFormatStr.indexOf("%b")==-1)&&(timeFormatStr.indexOf("%B")==-1))
			timeFormatStr+= ("%B");
		break;
	case 16:
		if (timeFormatStr.indexOf("%p")==-1)
			timeFormatStr+= ("%p");
		break;
	default:
		break;
	}
	ui->DateTimeEdit->setText(timeFormatStr);
	QString skewvalue1;
	skewvalue1=ui->SkewSkewValueEdit->text();
	int skewvalue2=skewvalue1.toInt();
	QString nowTimeStr=m_TimeShow.string2CString(m_TimeShow.TimeFormatToText(timeFormatStr,ui->SkewComBox->currentIndex(),skewvalue2,ui->SkewUUnitlistWidget->currentRow()));
	ui->PreviewEdit->setText(nowTimeStr);

}

void FileEditChild::concelTimeBut_clicked()
{
	if (ui->DateTimeEdit->text() != "")
	{
		ui->DateTimeEdit->backspace();
		ui->DateTimeEdit->backspace();
	} 
	ChangeTime();
}

void FileEditChild::SkewComBox_clicked()
{	if (ui->SkewComBox->currentIndex()==1)
{ChangeTime();}
}

void FileEditChild::refreshTimeBut_clicked()
{
	ChangeTime();
}

void FileEditChild::ChangeTime()
{
	CString timeFormatStr;
	timeFormatStr=ui->DateTimeEdit->text();
	QString skewvalue1;
	skewvalue1=ui->SkewSkewValueEdit->text();
	int skewvalue2=skewvalue1.toInt();
	QString nowTimeStr=m_TimeShow.string2CString(m_TimeShow.TimeFormatToText(timeFormatStr,ui->SkewComBox->currentIndex(),skewvalue2,ui->SkewUUnitlistWidget->currentRow()));
	//QString nowTimeStr=QString::fromStdString(m_TimeShow.TimeFormatToText(timeFormatStr,ui->SkewComBox->currentIndex(),skewvalue2,ui->SkewUUnitlistWidget->currentRow()));
	ui->PreviewEdit->setText(nowTimeStr);
}

void FileEditChild::newTimeBut_clicked()
{
	int xPos=0;
	int yPos=0;
	//修改当前obj
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			CTimeOBJ *pTimeObj = (CTimeOBJ*) (&m_MessagePrint.OBJ_Vec[i]);
			for(int j=0;j<m_MessagePrint.OBJ_Vec.size();j++)
			{
				if (m_MessagePrint.OBJ_Vec.at(j)->booFocus)
				{
					m_MessagePrint.OBJ_Vec.at(j)->booFocus = true;
					yPos=m_MessagePrint.OBJ_Vec[j]->intLineStart;
					xPos=m_MessagePrint.OBJ_Vec[j]->intRowStart;
				}
			}
			m_MessagePrint.OBJ_Vec[i]->intLineStart=yPos;
			m_MessagePrint.OBJ_Vec[i]->intRowStart=xPos;


			//CEdit* pEdit = (CEdit*)GetDlgItem(IDC_DATE_PREVIEW_EDIT);
			CString strText;
			//pEdit-> GetWindowText(strText);
			strText=ui->PreviewEdit->text();
			m_MessagePrint.OBJ_Vec[i]->strText=strText.toStdString();
			//tempObj.strText=theApp.myModuleMain.UnicodeToUtf8_CSTR(strText);

			CString formatText;
			formatText=ui->DateTimeEdit->text();
			//GetDlgItem(IDC_DATE_DATE_TIME_EDIT)->GetWindowText(formatText);
			pTimeObj->strTime=m_TimeShow.CString2string(formatText);

			CString  fontText;
			int nIndex = ui->fontSizeTimeComBox->currentIndex();
			//int nIndex = m_dateFontCombo.GetCurSel();  
			switch(nIndex)
			{
			case 0:
				m_MessagePrint.OBJ_Vec[i]->intLineSize = 5;
				m_MessagePrint.OBJ_Vec[i]->intRowSize = strText.length()*6;
				break;
			case 1:
				m_MessagePrint.OBJ_Vec[i]->intLineSize = 7;
				m_MessagePrint.OBJ_Vec[i]->intRowSize = strText.length()*6;
				break;
			case 2:
				m_MessagePrint.OBJ_Vec[i]->intLineSize = 12;
				m_MessagePrint.OBJ_Vec[i]->intRowSize = strText.length()*13;
				break;
			case 3:
				m_MessagePrint.OBJ_Vec[i]->intLineSize = 16;
				m_MessagePrint.OBJ_Vec[i]->intRowSize = strText.length()*13;
				break;
			}
			fontText = ui->fontSizeTimeComBox->currentText();
			//m_dateFontCombo.GetLBText(nIndex,fontText);
			m_MessagePrint.OBJ_Vec[i]->strFont = m_TimeShow.CString2string(fontText);

			pTimeObj->booETimeOffSet = ui->SkewComBox->currentIndex();
			CString timeOffText;
			timeOffText = ui->SkewSkewValueEdit->text();
			//GetDlgItem(IDC_DATE_SKEW_VALUE_EDIT)->GetWindowText(timeOffText);
			int timeOffText1 = timeOffText.toInt();
			pTimeObj->intTimeOffSet = timeOffText1;
			pTimeObj->strTimeOffSet = ui->SkewUUnitlistWidget->currentRow();

			//m_MessagePrint.OBJ_Vec[i].booFocus=true;
			this->update();
			return;
		}
	}
	

	//新建TimeObj对象
	for(int i=0; i!=m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec.at(i)->booFocus)
		{
			m_MessagePrint.OBJ_Vec.at(i)->booFocus = true;
			yPos=m_MessagePrint.OBJ_Vec.at(i)->intLineStart;
			xPos=m_MessagePrint.OBJ_Vec.at(i)->intRowSize+m_MessagePrint.OBJ_Vec.at(i)->intRowStart;
		}
	}
	CTimeOBJ* tempObj = new CTimeOBJ;
	tempObj->intLineStart=yPos;
	tempObj->intRowStart=xPos;
	tempObj->strType1="text";
	tempObj->strType2="time";
	tempObj->intSW=1;
	tempObj->intSS=0;
	tempObj->booNEG=false;
	tempObj->booBWDx=false;
	tempObj->booBWDy=false;

	//CEdit* pEdit = (CEdit*)GetDlgItem(IDC_DATE_PREVIEW_EDIT);
	CString strText;
	//pEdit-> GetWindowText(strText);
	strText=ui->PreviewEdit->text();
	tempObj->strText=strText.toStdString();
	//tempObj.strText=theApp.myModuleMain.UnicodeToUtf8_CSTR(strText);

	CString formatText;
	formatText=ui->DateTimeEdit->text();
	//GetDlgItem(IDC_DATE_DATE_TIME_EDIT)->GetWindowText(formatText);
	tempObj->strTime=m_TimeShow.CString2string(formatText);

	CString  fontText;
	int nIndex = ui->fontSizeTimeComBox->currentIndex();
	//int nIndex = m_dateFontCombo.GetCurSel(); 
	switch(nIndex)
	{
	case 0:
		tempObj->intLineSize=5;
		tempObj->intRowSize=strText.length()*6; 
		break;
	case 1:
		tempObj->intLineSize=7;
		tempObj->intRowSize=strText.length()*6; 
		break;
	case 2:
		tempObj->intLineSize=12;
		tempObj->intRowSize=strText.length()*13; 
		break;
	case 3:
		tempObj->intLineSize=16;
		tempObj->intRowSize=strText.length()*13; 
		break;
	}
	fontText=ui->fontSizeTimeComBox->currentText();
	//m_dateFontCombo.GetLBText(nIndex,fontText);
	tempObj->strFont=m_TimeShow.CString2string(fontText);

	tempObj->booETimeOffSet=ui->SkewComBox->currentIndex();
	CString timeOffText;
	timeOffText=ui->SkewSkewValueEdit->text();
	//GetDlgItem(IDC_DATE_SKEW_VALUE_EDIT)->GetWindowText(timeOffText);
	int timeOffText1=timeOffText.toInt();
	tempObj->intTimeOffSet=timeOffText1;
	tempObj->strTimeOffSet=ui->SkewUUnitlistWidget->currentRow();

	tempObj->booFocus = true;
	m_MessagePrint.OBJ_Vec.push_back(tempObj);
	//this->ShowWindow(SW_HIDE);
	this->ui->newTimeBut->setText(QStringLiteral("修改"));
	this->update();
}

void FileEditChild::SkewSkewValueEdit_clicked()
{
	numkeyboardWidget->SetLineEdit(ui->SkewSkewValueEdit);
}

void FileEditChild::initialValSerialLineEdit_clicked()
{
	numkeyboardWidget->SetLineEdit(ui->initialValSerialLineEdit);
}

void FileEditChild::termValSerialLineEdit_clicked()
{
	numkeyboardWidget->SetLineEdit(ui->termValSerialLineEdit);
}

void FileEditChild::startValSerialLineEdit_clicked()
{
	numkeyboardWidget->SetLineEdit(ui->startValSerialLineEdit);
}

void FileEditChild::stepLenSerialLineEdit_clicked()
{
	numkeyboardWidget->SetLineEdit(ui->stepLenSerialLineEdit);
}

void FileEditChild::reptCountSerialLineEdit_clicked()
{
	numkeyboardWidget->SetLineEdit(ui->reptCountSerialLineEdit);
}

void FileEditChild::digitSerialLineEdit_clicked()
{
	numkeyboardWidget->SetLineEdit(ui->digitSerialLineEdit);
}

void FileEditChild::heightBmpShowBmpLineEdit_clicked()
{
	numkeyboardWidget->SetLineEdit(ui->heightBmpShowBmpLineEdit);
	boolHWchange=true;
}

void FileEditChild::widthShowBmpLineEdit_clicked()
{
	numkeyboardWidget->SetLineEdit(ui->widthShowBmpLineEdit);
	boolHWchange=false;
}

void FileEditChild::newSerialNumber_click()
{
	QString a=ui->initialValSerialLineEdit->text();
	QString b=ui->termValSerialLineEdit->text();		
	QString d=ui->stepLenSerialLineEdit->text();
	QString e=ui->digitSerialLineEdit->text();
	QString g=ui->reptCountSerialLineEdit->text();
	QString SerialNumber_basic;
	int start=a.toInt();
	int stop=b.toInt();
	int step=d.toInt();
	int digit=e.toInt();
	int time=g.toInt();

	if (start>=stop)
	{
		return;
	}
	
	if (Serialfirst==1)
	{	
		QString c=ui->startValSerialLineEdit->text();
		int new_start=c.toInt();
		SerialNumber_number=new_start;
		if (SerialNumber_number<start)
		{
			return;
		}
	}
	else
	{
		if (SerialNumber_number<start)
		{
			return;
		}
		SerialNumber_number=SerialNumber_number+step;
	}

	//判断格式
	if (ui->formatSerialComBox->currentIndex()==0)
	{
	SerialNumber_string=QString("%1").arg(SerialNumber_number,digit,10,QChar('0'));
	SerialNumber_basic=QString("%1").arg(SerialNumber_number,digit,10,QChar('0'));//重复的基本单位
	}
	if (ui->formatSerialComBox->currentIndex()==1)
	{
		SerialNumber_string=QString("%1").arg(SerialNumber_number,digit,10,QChar(' '));
		SerialNumber_basic=QString("%1").arg(SerialNumber_number,digit,10,QChar(' '));//重复的基本单位
	}
	if (ui->formatSerialComBox->currentIndex()==2)
	{
		SerialNumber_string=QString("%1").arg(SerialNumber_number,-digit,10,QChar(' '));
		SerialNumber_basic=QString("%1").arg(SerialNumber_number,-digit,10,QChar(' '));//重复的基本单位
	}


	for (int s=1;s<time;s++)
	{
		SerialNumber_string=SerialNumber_string+" "+SerialNumber_basic;
	}

	if (SerialNumber_number>stop)
	{
		return;
	}

	ui->serialLineEdit->setText(SerialNumber_string);
	//如果当前有obj被选中，则为更改当选中的obj
	int m=1;
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			string tmpStr = this->ui->serialLineEdit->text().toStdString();
			m_MessagePrint.OBJ_Vec[i]->strText = tmpStr;
			m=0;
			this->update();
			break;
		}
	}
	//如果当前没有obj被选中，则为新建
	if (m)
	{
		if (serialcount!=1)
		{
			ui->serialLineEdit->clear();
			return;
		}
		if (ui->counterSerialComBox->currentIndex()==2)
		{
			serialcount=0;//关闭计数器
		}
		QString txtQString = ui->serialLineEdit->text();
		string txtString = txtQString.toStdString();
		QString qTextFont = ui->fontTypeSerialComBox->currentText();
		string textFont = qTextFont.toStdString();
		PushBackSerialNumberOBJ(textFont,false,false,false,txtString,0,0,0,1,ui->counterSerialComBox->currentIndex());
		this->ui->newSerialBut->setText(QStringLiteral("修改"));
		this->update();

		//新建图像时改动计数器
		int i=ui->counterSerialComBox->currentIndex();
		if (Serialfirst!=1)
		{
			i++;
		}

		if (i>3)
		{
		ui->counterSerialComBox->setCurrentIndex(3);
		}	

		ui->counterSerialComBox->setCurrentIndex(i);

	}
	Serialfirst=0;


}

void FileEditChild::SerialNumberstartchange()
{
	Serialfirst=1;
}

void FileEditChild::PushBackSerialNumberOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW,int countnumber)
{
	CSerialOBJ* SerialNumber = new CSerialOBJ;
	SerialNumber->strType1 = "text";
	SerialNumber->strType2 = "serial";
	SerialNumber->strFont = txtFont;
	SerialNumber->strText = txtContent;
	int txtLength = txtContent.length();
	SerialNumber->intLineSize = GetCharLenFromFont(txtFont,false);
	SerialNumber->intRowSize = GetCharLenFromFont(txtFont,true) * txtLength;
	SerialNumber->intLineStart = txtLineStart;
	SerialNumber->intRowStart = txtRowStart;
	SerialNumber->intSW = txtSW;
	SerialNumber->intSS = txtSS;
	SerialNumber->booNEG = txtNEG;
	SerialNumber->booBWDx = txtBWDx;
	SerialNumber->booBWDy = txtBWDy;
	SerialNumber->counter = countnumber;

	SerialNumber->booFocus = true;
	m_MessagePrint.OBJ_Vec.push_back(SerialNumber); 
}

void FileEditChild::rimwideAddBut_clicked()
{

	if (degreenum<10)
	{
		degreenum=degreenum+1;
	} 
	else
	{
		degreenum=10;
	}
	ui->rimwideLab->setText(QString::number(degreenum));
}

void FileEditChild::rimwideRedButt_clicked()
{

	if (degreenum>0)
	{
		degreenum=degreenum-1;
	} 
	else
	{
		degreenum=0;
	}
	ui->rimwideLab->setText(QString::number(degreenum));
}

void FileEditChild::heightBarCodeAddBut_clicked()
{
	/*if (Barheight<32)
	{*/
		Barheight = Barheight+1;
	/*}
	else
	{
		Barheight=32;
	}*/
	ui->heightBarCodeShowQRLab->setText(QString::number(Barheight));
}

void FileEditChild::heightBarCodeRedButt_clicked()
{
	if (Barheight>21)
	{
		Barheight = Barheight-1;
	}
	/*else
	{
		Barheight=21;
	}*/
	ui->heightBarCodeShowQRLab->setText(QString::number(Barheight));
}

void FileEditChild::whitespaceAddBut_clicked()
{

	if (degreenumQr<20)
	{

		degreenumQr=degreenumQr+1;
	} 
	else
	{
		degreenumQr=20;
	}
	ui->whitespaceLab->setText(QString::number(degreenumQr));
}

void FileEditChild::whitespaceRedButt_clicked()
{

	if (degreenumQr>0)
	{
		degreenumQr=degreenumQr-1;
	} 
	else
	{
		degreenumQr=0;
	}
	ui->whitespaceLab->setText(QString::number(degreenumQr));
}

QString FileEditChild::getNum(QString str)
{
	//获取数字
	QString str1 = str;
	QString res;
	QChar ch;
	int j = 0;

	for(int i=0;i<str1.size();i++)
	{
		ch = str1.at(i);
		if(ch.toLatin1() <'0'||ch > '9')
		{
			if(j == 0)
			{
				if(ch.toLatin1() == '.')
				{
					res.append(ch);
					j++;
					continue;
				}	
				else
					continue;
			}	
			else
				continue;
		}

		if(((ch.toLatin1()-'0')%2)!=0||((ch.toLatin1()-'0')%2)!=1)
			res.append(ch);

	}

	return res;
}

void FileEditChild::informationMessage(string errortext)
{
	CAutoMessageBox msg;
	msg.AutoSetSize(440,250);
	//msg.setText( QApplication::translate("Error", errortext.c_str(), 0));
	char ctmp[128] = {0};
	sprintf(ctmp,  "<h1><i>Error</i><p align='center'> </font>%s</font></p></h1>",errortext.c_str());
	//msg.setText(tr("<h1><i>Error</i><p align='center'> </font>errortext</font></p></h1>"));
	msg.setText(ctmp);

	msg.setWindowTitle(tr("Warning"));
	msg.setIcon(QMessageBox::Critical);
	msg.addButton(tr("OK"),QMessageBox::ActionRole);
	msg.setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);\
					  QPushButton {background-color: rgb(0,0,0);color: rgb(255, 255, 255);font: bold;font-size:40px;color:rgb(255,255,255)};\
					  ");
	msg.exec();

}

QString FileEditChild::disposeinputtext(QString inputtext)
{
	if ( QString::compare(inputtext,"") == 0 )
	{
		return inputtext;
	}
	QMap<int,QString>textbyte;	
	for (int i = inputtext.length();i > 0;i--)
	{
		QString cstr =inputtext.mid(inputtext.length() - i,1);//字符串分割
		QString tempstr = ConvertWCHARToHex(cstr,1);
		//textbyte[inputtext.GetLength() - i] = tempstr;
		textbyte[i-1] = tempstr;
	}//转为十六进制字符串
	QString outputtext = "";
	QVector<QString>textarray;
	QVector<QString>textunicodearray;
	QVector<QString>arleft;
	QMap<int,QString>textstring1;
	//bool textbytearrayBoolean[textbyte.size()+2];
	QMap<int,bool>textbytearrayBoolean;
	for ( int i =0;i < textbyte.size()+2;i++)
	{
		textbytearrayBoolean[i] = false;
	}


	for ( int j = 0;j < textbyte.size();j++)
	{
		if ( ArabicLan(textbyte[j])=="" )
		{
			textbytearrayBoolean[j + 1] = false;
		} 
		else
		{
			textbytearrayBoolean[j + 1] = true;
		}
		textstring1[j] = ArabicLan(textbyte[j]);
	}

	for ( int n = 0;n < textstring1.size();n++ )
	{
		if ( textstring1[n] == "" )//不在变形列表的文字
		{
			QString valueStr = textbyte[n];
			if ( valueStr.mid(1, 1) == "6" || valueStr.mid(1, 2) == "FE"
				|| valueStr.mid(1, 3) == "FB")//不在变形列表的阿拉伯文字
			{
				if ( n + 3 == textbyte.size()+2 )//在最后一列
				{
					arleft.push_back("0x"+ textbyte[n]);
					for ( int f = 0;f < arleft.size();f++)
					{
						textarray.push_back(arleft.at(f));		
					}
					arleft.clear();
				}
				else//不在最后一列
				{
					if ( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == true )//空格
					{
						arleft.push_back("0x" + textbyte[n]);
						for ( int f= 0;f < arleft.size();f++)
						{
							textarray.push_back(arleft.at(f));	
						}
						arleft.clear();
					}
					else
					{
						textarray.push_back("0x" + textbyte[n]);//其他文字
					}
				}
			}
			else//不在变形列表的其他文字
			{
				if ( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == true )//空格
				{
					arleft.push_back("0x" + textbyte[n]);
					for ( int f= 0;f < arleft.size();f++)
					{
						textarray.push_back(arleft.at(f));	
					}
					arleft.clear();
				} 
				else
				{
					textarray.push_back("0x" + textbyte[n]);//其他文字
				}
			}
		} 
		else//在变形列表
		{
			textunicodearray = Arabicsplit(textstring1[n]);
			if ( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == true )
			{
				arleft.push_back(textunicodearray.at(2));
			} 
			else if( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == false)
			{
				if ( n + 3 == textbyte.size()+2 )
				{
					arleft.push_back(textunicodearray.at(0));
					for ( int f= 0;f < arleft.size();f++)
					{
						textarray.push_back(arleft.at(f));
					}
					arleft.clear();
				} 
				else
				{
					if ( textbytearrayBoolean[n + 3] == true )
					{
						arleft.push_back(textunicodearray.at(0));
						for ( int f= 0;f < arleft.size();f++)
						{
							textarray.push_back(arleft.at(f));	
						}
						arleft.clear();
					}
					else
					{
						arleft.push_back(textunicodearray.at(0));
						for ( int f= 0;f < arleft.size();f++)
						{
							textarray.push_back(arleft.at(f));	
						}
						arleft.clear();
					}
				}
			}
			else if ( textbytearrayBoolean[n] == false && textbytearrayBoolean[n + 2] == true )
			{
				arleft.push_back(textunicodearray.at(1));
			}
			else if ( textbytearrayBoolean[n] == false && textbytearrayBoolean[n + 2] == false )
			{
				textarray.push_back(textunicodearray.at(3));
			}
		}
	}
	QVector<QString>tempVec;
	for (int k = textarray.size(); k > 0;k-- )
	{
		tempVec.push_back(textarray.at(k-1));//倒置
	}
	for ( int m = 0; m < tempVec.size();m++)
	{
		outputtext = outputtext + HexStrToCString(tempVec[m]);
	}
	return outputtext;	
}

QString FileEditChild::ConvertWCHARToHex(QString Data, long nDataLength)
{
	QString sResult("");

	/*int bufSize = MultiByteToWideChar(CP_ACP,0,Data.toStdString().c_str(),-1,NULL,0);  	    
	wchar_t *pwstr = new wchar_t[bufSize];  
	MultiByteToWideChar(CP_ACP,0,Data.toStdString().c_str(),-1,pwstr,bufSize); */

	const wchar_t* wstr = reinterpret_cast<const wchar_t *>(Data.utf16());

	for (long nLoop=0; nLoop<Data.length(); nLoop++)
	{
		wchar_t ch = wstr[nLoop]; 
		char c_cn[2]={'0'};
		W2C(ch,c_cn);
		static const char *hex = "0123456789ABCDEF";
		for(int i=0;i<2;i++)
		{
			unsigned char chHexA = hex[((unsigned char)(c_cn[i]) >> 4) & 0x0f];
			unsigned char chHexB = hex[(unsigned char)(c_cn[i]) & 0x0f];
			sResult += (char)chHexA;
			sResult += (char)chHexB;
		}
	}
	return sResult;
}

void FileEditChild::W2C(wchar_t w_cn , char c_cn[])
{
	c_cn[0] = w_cn >> 8 ;
	c_cn[1] = (char)w_cn ;
}

QVector<QString> FileEditChild::Arabicsplit(QString str)
{
	int length = str.length();
	QVector< QString >SplitOut;
	QString outstr = "";
	for ( int i =0 ;i < length;i++)
	{
		QString temp,first;
		temp = str.mid(i,1);
		first = str.mid(0,1);
		if ( first == "0")
		{
			if ( temp != "," )
			{
				outstr+=str.mid(i,1);
				if (i == length-1)
				{
					SplitOut.push_back(outstr);
				}
			}
			else
			{
				SplitOut.push_back(outstr);
				outstr = "";
			}
		} 
		else
		{
			QString temp2;
			temp2 = str.mid(i,1);
			if ( temp2 != ",")
			{
				SplitOut.push_back(temp2);
			}
		}

	}
	return SplitOut;
}

void FileEditChild::ClickChooseLanguage()
{
	if (keyboardWidget->m_LanType == 0 ||keyboardWidget->m_LantypeReverse == 1)
	{
		languageWidget->LanChinese_KBBut_clicked();
	}
	else if (keyboardWidget->m_LanType == 7 ||keyboardWidget->m_LantypeReverse == 0)
	{
		languageWidget->lanEnglish_KBBut_clicked();
	} 
	else if(keyboardWidget->m_LanType == 5 ||keyboardWidget->m_LanType == 23 ||keyboardWidget->m_LanType == 24 
		||keyboardWidget->m_LanType == 25 ||keyboardWidget->m_LanType == 26 ||keyboardWidget->m_LantypeReverse== 8)
	{
		languageWidget->LanArabic_KBBut_clicked();
	}
	else if (keyboardWidget->m_LanType == 22 ||keyboardWidget->m_LantypeReverse == 2)
	{
		languageWidget->LanKorean_KBBut_clicked();
	
	}
	else if (keyboardWidget->m_LanType == 1 ||keyboardWidget->m_LantypeReverse == 4)
	{
		languageWidget->LanJapanese_KBBut_clicked();
	}
}

QString FileEditChild::HexStrToCString(QString HexStr) 
{
	//HexStr = "0xFEB9";
	HexStr = " " + HexStr;
	wchar_t* buf = new wchar_t[2];
	memset(buf, 0, sizeof(wchar_t)*(2));//memset初始化数组
	
	TCHAR seps[] = _T(" ");

	int bufSize = MultiByteToWideChar(CP_ACP,0,HexStr.toStdString().c_str(),-1,NULL,0);  	    
	wchar_t *pwstr = new wchar_t[bufSize];  
	MultiByteToWideChar(CP_ACP,0,HexStr.toStdString().c_str(),-1,pwstr,bufSize); 

	TCHAR* token = _tcstok(pwstr, seps);
	while(NULL != token)
	{
		buf[0] = _tcstoul(token, NULL, 16);
		token = _tcstok(NULL, seps);
	}	 
	QString outstr = QString::fromWCharArray(buf);

	delete[] buf;
	delete[] pwstr;
	buf = NULL;
	return outstr;
}

QString FileEditChild::ArabicLan(QString inputstring)//Arabic组合规则
{
	QString outputstring = "";
	if (QString::compare(inputstring,"0621") == 0|| QString::compare(inputstring,"FE80") == 0 
		||QString::compare(inputstring,"FE80") == 0 ||QString::compare(inputstring,"FE80") == 0 ||QString::compare(inputstring,"FE80") == 0) 
		outputstring = "0xFE80, 0xFE80, 0xFE80, 0xFE80";

	else if (QString::compare(inputstring,"0622") == 0|| QString::compare(inputstring,"FE82") == 0 
		||QString::compare(inputstring,"FE81") == 0 || QString::compare(inputstring,"FE82") == 0 ||QString::compare(inputstring,"FE81") == 0)
		outputstring = "0xFE82, 0xFE81, 0xFE82, 0xFE81";

	else if (QString::compare(inputstring,"0623") == 0|| QString::compare(inputstring,"FE84") == 0 
		||QString::compare(inputstring,"FE83") == 0 ||QString::compare(inputstring,"FE84") == 0 ||QString::compare(inputstring,"FE83") == 0)
		outputstring = "0xFE84, 0xFE83, 0xFE84, 0xFE83";


	else if (QString::compare(inputstring,"0624") == 0|| QString::compare(inputstring,"FE86") == 0 
		||QString::compare(inputstring,"FE85") == 0 ||QString::compare(inputstring,"FE86") == 0 ||QString::compare(inputstring,"FE85") == 0)
		outputstring = "0xFE86, 0xFE85, 0xFE86, 0xFE85";


	else if (QString::compare(inputstring,"0625") == 0|| QString::compare(inputstring,"FE88") == 0 
		||QString::compare(inputstring,"FE87") == 0 ||QString::compare(inputstring,"FE88") == 0 ||QString::compare(inputstring,"FE87") == 0)
		outputstring = "0xFE88, 0xFE87, 0xFE88, 0xFE87";


	else if (QString::compare(inputstring,"0626") == 0|| QString::compare(inputstring,"FE8A") == 0 
		||QString::compare(inputstring,"FE8B") == 0 ||QString::compare(inputstring,"FE8C") == 0 ||QString::compare(inputstring,"FE89") == 0)
		outputstring = "0xFE8A, 0xFE8B, 0xFE8C, 0xFE89";


	else if (QString::compare(inputstring,"0627") == 0|| QString::compare(inputstring,"FE8E") == 0 
		||QString::compare(inputstring,"FE8D") == 0 ||QString::compare(inputstring,"FE8E") == 0 ||QString::compare(inputstring,"FE8D") == 0)
		outputstring = "0xFE8E, 0xFE8D, 0xFE8E, 0xFE8D";


	else if (QString::compare(inputstring,"0628") == 0|| QString::compare(inputstring,"FE90") == 0 
		||QString::compare(inputstring,"FE91") == 0 ||QString::compare(inputstring,"FE92") == 0 ||QString::compare(inputstring,"FE8F") == 0)
		outputstring = "0xFE90, 0xFE91, 0xFE92, 0xFE8F";


	else if (QString::compare(inputstring,"0629") == 0|| QString::compare(inputstring,"FE94") == 0 
		||QString::compare(inputstring,"FE93") == 0 ||QString::compare(inputstring,"FE94") == 0 ||QString::compare(inputstring,"FE93") == 0)
		outputstring = "0xFE94, 0xFE93, 0xFE94, 0xFE93";


	else if (QString::compare(inputstring,"062A") == 0|| QString::compare(inputstring,"FE96") == 0 
		||QString::compare(inputstring,"FE97") == 0 ||QString::compare(inputstring,"FE98") == 0 ||QString::compare(inputstring,"FE95") == 0)
		outputstring = "0xFE96, 0xFE97, 0xFE98, 0xFE95";

	else if (QString::compare(inputstring,"062B") == 0|| QString::compare(inputstring,"FE9A") == 0 
		||QString::compare(inputstring,"FE9B") == 0 ||QString::compare(inputstring,"FE9C") == 0 ||QString::compare(inputstring,"FE99") == 0)
		outputstring = "0xFE9A, 0xFE9B, 0xFE9C, 0xFE99";


	else if (QString::compare(inputstring,"062C") == 0|| QString::compare(inputstring,"FE9E") == 0 
		||QString::compare(inputstring,"FE9F") == 0 ||QString::compare(inputstring,"FEA0") == 0 ||QString::compare(inputstring,"FE9D") == 0)
		outputstring = "0xFE9E, 0xFE9F, 0xFEA0, 0xFE9D";


	else if (QString::compare(inputstring,"062D") == 0|| QString::compare(inputstring,"FEA2") == 0 
		||QString::compare(inputstring,"FEA3") == 0 ||QString::compare(inputstring,"FEA4") == 0 ||QString::compare(inputstring,"FEA1") == 0)
		outputstring = "0xFEA2, 0xFEA3, 0xFEA4, 0xFEA1";


	else if (QString::compare(inputstring,"062E") == 0|| QString::compare(inputstring,"FEA6") == 0 
		||QString::compare(inputstring,"FEA7") == 0 ||QString::compare(inputstring,"FEA8") == 0 ||QString::compare(inputstring,"FEA5") == 0)
		outputstring = "0xFEA6, 0xFEA7, 0xFEA8, 0xFEA5";


	else if (QString::compare(inputstring,"062F") == 0|| QString::compare(inputstring,"FEAA") == 0 
		||QString::compare(inputstring,"FEA9") == 0 ||QString::compare(inputstring,"FEAA") == 0 ||QString::compare(inputstring,"FEA9") == 0)
		outputstring = "0xFEAA, 0xFEA9, 0xFEAA, 0xFEA9";


	else if (QString::compare(inputstring,"0630") == 0|| QString::compare(inputstring,"FEAC") == 0 
		||QString::compare(inputstring,"FEAB") == 0 ||QString::compare(inputstring,"FEAC") == 0 ||QString::compare(inputstring,"FEAB") == 0)
		outputstring = "0xFEAC, 0xFEAB, 0xFEAC, 0xFEAB";


	else if (QString::compare(inputstring,"0631") == 0|| QString::compare(inputstring,"FEAE") == 0 
		||QString::compare(inputstring,"FEAD") == 0 ||QString::compare(inputstring,"FEAE") == 0 ||QString::compare(inputstring,"FEAD") == 0)
		outputstring = "0xFEAE, 0xFEAD, 0xFEAE, 0xFEAD";


	else if (QString::compare(inputstring,"0632") == 0|| QString::compare(inputstring,"FEB0") == 0 
		||QString::compare(inputstring,"FEAF") == 0 ||QString::compare(inputstring,"FEB0") == 0 ||QString::compare(inputstring,"FEAF") == 0)
		outputstring = "0xFEB0, 0xFEAF, 0xFEB0, 0xFEAF";


	else if (QString::compare(inputstring,"0633") == 0|| QString::compare(inputstring,"FEB2") == 0 
		||QString::compare(inputstring,"FEB3") == 0 ||QString::compare(inputstring,"FEB4") == 0 ||QString::compare(inputstring,"FEB1") == 0 )
		outputstring = "0xFEB2, 0xFEB3, 0xFEB4, 0xFEB1";


	else if (QString::compare(inputstring,"0634") == 0|| QString::compare(inputstring,"FEB6") == 0 
		||QString::compare(inputstring,"FEB7") == 0 ||QString::compare(inputstring,"FEB8") == 0 ||QString::compare(inputstring,"FEB5") == 0 )
		outputstring = "0xFEB6, 0xFEB7, 0xFEB8, 0xFEB5";


	else if (QString::compare(inputstring,"0635") == 0|| QString::compare(inputstring,"FEBA") == 0 
		||QString::compare(inputstring,"FEBB") == 0 ||QString::compare(inputstring,"FEBC") == 0 ||QString::compare(inputstring,"FEB9") == 0)
		outputstring = "0xFEBA, 0xFEBB, 0xFEBC, 0xFEB9";


	else if (QString::compare(inputstring,"0636") == 0|| QString::compare(inputstring,"FEBE") == 0 
		||QString::compare(inputstring,"FEBF") == 0 ||QString::compare(inputstring,"FEC0") == 0 ||QString::compare(inputstring,"FEBD") == 0)
		outputstring = "0xFEBE, 0xFEBF, 0xFEC0, 0xFEBD";


	else if (QString::compare(inputstring,"0637") == 0|| QString::compare(inputstring,"FEC2") == 0 
		||QString::compare(inputstring,"FEC3") == 0 ||QString::compare(inputstring,"FEC4") == 0 ||QString::compare(inputstring,"FEC1") == 0)
		outputstring = "0xFEC2, 0xFEC3, 0xFEC4, 0xFEC1";


	else if (QString::compare(inputstring,"0638") == 0|| QString::compare(inputstring,"FEC6") == 0 
		||QString::compare(inputstring,"FEC7") == 0 ||QString::compare(inputstring,"FEC8") == 0 ||QString::compare(inputstring,"FEC5") == 0)
		outputstring = "0xFEC6, 0xFEC7, 0xFEC8, 0xFEC5";


	else if (QString::compare(inputstring,"0639") == 0|| QString::compare(inputstring,"FECA") == 0 
		||QString::compare(inputstring,"FECB") == 0 ||QString::compare(inputstring,"FECC") == 0 ||QString::compare(inputstring,"FEC9") == 0)
		outputstring = "0xFECA, 0xFECB, 0xFECC, 0xFEC9";


	else if (QString::compare(inputstring,"063A") == 0|| QString::compare(inputstring,"FECE") == 0 
		||QString::compare(inputstring,"FECF") == 0 ||QString::compare(inputstring,"FED0") == 0 ||QString::compare(inputstring,"FECD") == 0)
		outputstring = "0xFECE, 0xFECF, 0xFED0, 0xFECD";


	else if (QString::compare(inputstring,"063B") == 0|| QString::compare(inputstring,"63B") == 0 
		||QString::compare(inputstring,"63B") == 0 ||QString::compare(inputstring,"63B") == 0 ||QString::compare(inputstring,"63B") == 0)
		outputstring = "0x63B, 0x63B, 0x63B, 0x63B";


	else if (QString::compare(inputstring,"063C") == 0|| QString::compare(inputstring,"63C") == 0 
		||QString::compare(inputstring,"63C") == 0 ||QString::compare(inputstring,"63C") == 0 ||QString::compare(inputstring,"63C") == 0)
		outputstring = "0x63C, 0x63C, 0x63C, 0x63C";


	else if (QString::compare(inputstring,"063D") == 0|| QString::compare(inputstring,"63D") == 0 
		||QString::compare(inputstring,"63D") == 0 ||QString::compare(inputstring,"63D") == 0 ||QString::compare(inputstring,"63D") == 0)
		outputstring = "0x63D, 0x63D, 0x63D, 0x63D";


	else if (QString::compare(inputstring,"063E") == 0|| QString::compare(inputstring,"63E") == 0 
		||QString::compare(inputstring,"63E") == 0 ||QString::compare(inputstring,"63E") == 0 ||QString::compare(inputstring,"63E") == 0)
		outputstring = "0x63E, 0x63E, 0x63E, 0x63E";


	else if (QString::compare(inputstring,"063F") == 0|| QString::compare(inputstring,"63F") == 0 
		||QString::compare(inputstring,"63F") == 0 ||QString::compare(inputstring,"63F") == 0 ||QString::compare(inputstring,"63F") == 0)
		outputstring = "0x63F, 0x63F, 0x63F, 0x63F";


	else if (QString::compare(inputstring,"0640") == 0|| QString::compare(inputstring,"640") == 0 
		||QString::compare(inputstring,"640") == 0 ||QString::compare(inputstring,"640") == 0 ||QString::compare(inputstring,"640") == 0)
		outputstring = "0x640, 0x640, 0x640, 0x640";


	else if (QString::compare(inputstring,"0641") == 0|| QString::compare(inputstring,"FED2") == 0 
		||QString::compare(inputstring,"FED3") == 0 ||QString::compare(inputstring,"FED4") == 0 ||QString::compare(inputstring,"FED1") == 0)
		outputstring = "0xFED2, 0xFED3, 0xFED4, 0xFED1";


	else if (QString::compare(inputstring,"0642") == 0|| QString::compare(inputstring,"FED6") == 0 
		||QString::compare(inputstring,"FED7") == 0 ||QString::compare(inputstring,"FED8") == 0 ||QString::compare(inputstring,"FED5") == 0)
		outputstring = "0xFED6, 0xFED7, 0xFED8, 0xFED5";


	else if (QString::compare(inputstring,"0643") == 0|| QString::compare(inputstring,"FEDA") == 0 
		||QString::compare(inputstring,"FEDB") == 0 ||QString::compare(inputstring,"FEDC") == 0 ||QString::compare(inputstring,"FED9") == 0)
		outputstring = "0xFEDA, 0xFEDB, 0xFEDC, 0xFED9";


	else if (QString::compare(inputstring,"0644") == 0|| QString::compare(inputstring,"FEDE") == 0 
		||QString::compare(inputstring,"FEDF") == 0 ||QString::compare(inputstring,"FEE0") == 0 ||QString::compare(inputstring,"FEDD") == 0)
		outputstring = "0xFEDE, 0xFEDF, 0xFEE0, 0xFEDD";


	else if (QString::compare(inputstring,"0645") == 0|| QString::compare(inputstring,"FEE2") == 0 
		||QString::compare(inputstring,"FEE3") == 0 ||QString::compare(inputstring,"FEE4") == 0 ||QString::compare(inputstring,"FEE1") == 0)
		outputstring = "0xFEE2, 0xFEE3, 0xFEE4, 0xFEE1";


	else if (QString::compare(inputstring,"0646") == 0|| QString::compare(inputstring,"FEE6") == 0 
		||QString::compare(inputstring,"FEE7") == 0 ||QString::compare(inputstring,"FEE8") == 0 ||QString::compare(inputstring,"FEE5") == 0)
		outputstring = "0xFEE6, 0xFEE7, 0xFEE8, 0xFEE5";


	else if (QString::compare(inputstring,"0647") == 0|| QString::compare(inputstring,"FEEA") == 0 
		||QString::compare(inputstring,"FEEB") == 0 ||QString::compare(inputstring,"FEEC") == 0 ||QString::compare(inputstring,"FEE9") == 0)
		outputstring = "0xFEEA, 0xFEEB, 0xFEEC, 0xFEE9";


	else if (QString::compare(inputstring,"0648") == 0|| QString::compare(inputstring,"FEEE") == 0 
		||QString::compare(inputstring,"FEED") == 0 ||QString::compare(inputstring,"FEEE") == 0 ||QString::compare(inputstring,"FEED") == 0)
		outputstring = "0xFEEE, 0xFEED, 0xFEEE, 0xFEED";


	else if (QString::compare(inputstring,"0649") == 0 ||QString::compare(inputstring,"FEF0") == 0 ||
		QString::compare(inputstring,"FEF3") == 0 || QString::compare(inputstring,"FEF4") == 0 || QString::compare(inputstring,"FEEF") == 0)
		outputstring = "0xFEF0, 0xFEF3, 0xFEF4, 0xFEEF";


	else if (QString::compare(inputstring,"064A") == 0 || QString::compare(inputstring,"FEF2") == 0 
		||QString::compare(inputstring,"FEF3") == 0 ||QString::compare(inputstring,"FEF4") == 0 ||QString::compare(inputstring,"FEF1") == 0)
		outputstring = "0xFEF2, 0xFEF3, 0xFEF4, 0xFEF1";
	return outputstring;
}

bool FileEditChild::newShiftBut()
{
	for (int i=0; i<m_MessagePrint.OBJ_Vec.size(); i++)
	{
		if (m_MessagePrint.OBJ_Vec[i]->booFocus)
		{
			//班次1
			QString curText1 = ui->startTimeShowSft1LineEdit->text();
			QString leftText1 = curText1.left(2);
			leftInt1 = atoi(leftText1.toStdString().c_str());
			//QString rightText1 = curText1.mid(2,2);
			//rightInt1 = atoi(rightText1.toStdString().c_str());
			showText1 = ui->textIDShowSft1LineEdit->text();
			int showTextLen1 = showText1.length();

			//班次2
			QString curText2 = ui->startTimeShowSft2LineEdit->text();
			QString leftText2 = curText2.left(2);
			leftInt2 = atoi(leftText2.toStdString().c_str());
			//QString rightText1 = curText1.mid(2,2);
			//rightInt1 = atoi(rightText1.toStdString().c_str());
			showText2 = ui->textIDShowSft2LineEdit->text();
			int showTextLen2 = showText2.length();

			//班次3
			QString curText3 = ui->startTimeShowSft3LineEdit->text();
			QString leftText3 = curText3.left(2);
			leftInt3 = atoi(leftText3.toStdString().c_str());
			//QString rightText1 = curText1.mid(2,2);
			//rightInt1 = atoi(rightText1.toStdString().c_str());
			showText3 = ui->textIDShowSft3LineEdit->text();
			int showTextLen3 = showText3.length();

			//班次4
			QString curText4 = ui->startTimeShowSft4LineEdit->text();
			QString leftText4 = curText4.left(2);
			leftInt4 = atoi(leftText4.toStdString().c_str());
			//QString rightText1 = curText1.mid(2,2);
			//rightInt1 = atoi(rightText1.toStdString().c_str());
			showText4 = ui->textIDShowSft4LineEdit->text();
			int showTextLen4 = showText4.length();

			//班次数目
			QString m_num = ui->shiftNumShowLineEdit->text();
			int numInt = atoi(m_num.toStdString().c_str());
			switch(numInt)
			{
			case 0:
				ui->startTimeShowSft2LineEdit->setText("");
				ui->textIDShowSft2LineEdit->setText("");
				ui->startTimeShowSft3LineEdit->setText("");
				ui->textIDShowSft3LineEdit->setText("");
				ui->startTimeShowSft4LineEdit->setText("");
				ui->textIDShowSft4LineEdit->setText("");
				ui->startTimeShowSft2LineEdit->setEnabled(false);
				ui->textIDShowSft2LineEdit->setEnabled(false);
				ui->startTimeShowSft3LineEdit->setEnabled(false);
				ui->textIDShowSft3LineEdit->setEnabled(false);
				ui->startTimeShowSft4LineEdit->setEnabled(false);
				ui->textIDShowSft4LineEdit->setEnabled(false);
				break;

			case 1:
				ui->startTimeShowSft2LineEdit->setText("");
				ui->textIDShowSft2LineEdit->setText("");
				ui->startTimeShowSft3LineEdit->setText("");
				ui->textIDShowSft3LineEdit->setText("");
				ui->startTimeShowSft4LineEdit->setText("");
				ui->textIDShowSft4LineEdit->setText("");
				ui->startTimeShowSft2LineEdit->setEnabled(false);
				ui->textIDShowSft2LineEdit->setEnabled(false);
				ui->startTimeShowSft3LineEdit->setEnabled(false);
				ui->textIDShowSft3LineEdit->setEnabled(false);
				ui->startTimeShowSft4LineEdit->setEnabled(false);
				ui->textIDShowSft4LineEdit->setEnabled(false);
				break;
			case 2:
				ui->startTimeShowSft3LineEdit->setText("");
				ui->textIDShowSft3LineEdit->setText("");
				ui->startTimeShowSft4LineEdit->setText("");
				ui->textIDShowSft4LineEdit->setText("");
				ui->startTimeShowSft3LineEdit->setEnabled(false);
				ui->textIDShowSft3LineEdit->setEnabled(false);
				ui->startTimeShowSft4LineEdit->setEnabled(false);
				ui->textIDShowSft4LineEdit->setEnabled(false);
				break;
			case 3:
				ui->startTimeShowSft4LineEdit->setText("");
				ui->textIDShowSft4LineEdit->setText("");
				ui->startTimeShowSft4LineEdit->setEnabled(false);
				ui->textIDShowSft4LineEdit->setEnabled(false);
				break;
			}

			//文本长度
			QString textLen = ui->textLenShowLineEdit->text();
			int textLenInt = atoi(textLen.toStdString().c_str());
			//ui.textlineEdit1->setMaxLength(textLenInt);
			if (showTextLen1 > textLenInt)
			{
				//QMessageBox::warning(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("班次1超出输入范围"));
				QString warningtext1 = QString::fromLocal8Bit("班次1超出输入范围");
				informationMessage(warningtext1.toStdString());
				ui->textIDShowSft1LineEdit->setText(""); 
				return false;
			}
			if (showTextLen2 > textLenInt)
			{
				//QMessageBox::warning(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("班次1超出输入范围"));
				QString warningtext2 = QString::fromLocal8Bit("班次2超出输入范围");
				informationMessage(warningtext2.toStdString());
				ui->textIDShowSft2LineEdit->setText(""); 
				return false;
			}
			if (showTextLen3 > textLenInt)
			{
				//QMessageBox::warning(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("班次1超出输入范围"));
				QString warningtext3 = QString::fromLocal8Bit("班次3超出输入范围");
				informationMessage(warningtext3.toStdString());
				ui->textIDShowSft3LineEdit->setText(""); 
				return false;
			}
			if (showTextLen4 > textLenInt)
			{
				//QMessageBox::warning(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("班次1超出输入范围"));
				QString warningtext4 = QString::fromLocal8Bit("班次4超出输入范围");
				informationMessage(warningtext4.toStdString());
				ui->textIDShowSft4LineEdit->setText(""); 
				return false;
			}
			QTime timeNow = QTime::currentTime();
			//ui.textlineEdit4->setText(timeNow.toString());
			m_hour = timeNow.hour();
			//m_mint = timeNow.minute();
			string textFont = QString::fromLocal8Bit("5x5").toStdString();
			QString m_num1 = ui->shiftNumShowLineEdit->text();
			int numInt1 = atoi(m_num1.toStdString().c_str());
			switch(numInt1-1)
			{
			case 0:
				PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText1),0,0,0,1);
				break;
			case 1:
				if ( m_hour>= leftInt1 && m_hour< leftInt2)
				{   
					//string txtString = qstr2str(showText1);
					m_MessagePrint.OBJ_Vec[i]->strText = qstr2str(showText1);
				}
				if ( m_hour>= leftInt2 || m_hour< leftInt1)
				{
					m_MessagePrint.OBJ_Vec[i]->strText = qstr2str(showText2);
				}
				break;
			case 2:
				if ( m_hour>= leftInt1 && m_hour< leftInt2)
				{   
					//string txtString = qstr2str(showText1);
					m_MessagePrint.OBJ_Vec[i]->strText = qstr2str(showText1);
				}
				if ( m_hour>= leftInt2 && m_hour< leftInt3)
				{
					m_MessagePrint.OBJ_Vec[i]->strText = qstr2str(showText2);
				}
				if ( m_hour>= leftInt3 || m_hour< leftInt1)
				{
					m_MessagePrint.OBJ_Vec[i]->strText = qstr2str(showText3);
				}
				break;
			case 3:
				if ( m_hour>= leftInt1 && m_hour< leftInt2)
				{   
					//string txtString = qstr2str(showText1);
					m_MessagePrint.OBJ_Vec[i]->strText = qstr2str(showText1);
				}
				if ( m_hour>= leftInt2 && m_hour< leftInt3)
				{
					m_MessagePrint.OBJ_Vec[i]->strText = qstr2str(showText2);
				}
				if ( m_hour>= leftInt3 || m_hour< leftInt1)
				{
					m_MessagePrint.OBJ_Vec[i]->strText = qstr2str(showText3);
				}
				if ( m_hour< leftInt1 || m_hour>= leftInt4)
				{
					m_MessagePrint.OBJ_Vec[i]->strText = qstr2str(showText4);
				}
				break;
			}
			this->update();
			return true;
			//return;
		}
	}
	//班次1
	QString curText1 = ui->startTimeShowSft1LineEdit->text();
	QString leftText1 = curText1.left(2);
	leftInt1 = atoi(leftText1.toStdString().c_str());
	//QString rightText1 = curText1.mid(2,2);
	//rightInt1 = atoi(rightText1.toStdString().c_str());
	showText1 = ui->textIDShowSft1LineEdit->text();
	int showTextLen1 = showText1.length();

	//班次2
	QString curText2 = ui->startTimeShowSft2LineEdit->text();
	QString leftText2 = curText2.left(2);
	leftInt2 = atoi(leftText2.toStdString().c_str());
	//QString rightText1 = curText1.mid(2,2);
	//rightInt1 = atoi(rightText1.toStdString().c_str());
	showText2 = ui->textIDShowSft2LineEdit->text();
	int showTextLen2 = showText2.length();

	//班次3
	QString curText3 = ui->startTimeShowSft3LineEdit->text();
	QString leftText3 = curText3.left(2);
	leftInt3 = atoi(leftText3.toStdString().c_str());
	//QString rightText1 = curText1.mid(2,2);
	//rightInt1 = atoi(rightText1.toStdString().c_str());
	showText3 = ui->textIDShowSft3LineEdit->text();
	int showTextLen3 = showText3.length();

	//班次4
	QString curText4 = ui->startTimeShowSft4LineEdit->text();
	QString leftText4 = curText4.left(2);
	leftInt4 = atoi(leftText4.toStdString().c_str());
	//QString rightText1 = curText1.mid(2,2);
	//rightInt1 = atoi(rightText1.toStdString().c_str());
	showText4 = ui->textIDShowSft4LineEdit->text();
	int showTextLen4 = showText4.length();

	//班次数目
	QString m_num = ui->shiftNumShowLineEdit->text();
	int numInt = atoi(m_num.toStdString().c_str());
	switch(numInt)
	{
	case 0:
		ui->startTimeShowSft2LineEdit->setText("");
		ui->textIDShowSft2LineEdit->setText("");
		ui->startTimeShowSft3LineEdit->setText("");
		ui->textIDShowSft3LineEdit->setText("");
		ui->startTimeShowSft4LineEdit->setText("");
		ui->textIDShowSft4LineEdit->setText("");
		ui->startTimeShowSft2LineEdit->setEnabled(false);
		ui->textIDShowSft2LineEdit->setEnabled(false);
		ui->startTimeShowSft3LineEdit->setEnabled(false);
		ui->textIDShowSft3LineEdit->setEnabled(false);
		ui->startTimeShowSft4LineEdit->setEnabled(false);
		ui->textIDShowSft4LineEdit->setEnabled(false);
		break;

	case 1:
		ui->startTimeShowSft2LineEdit->setText("");
		ui->textIDShowSft2LineEdit->setText("");
		ui->startTimeShowSft3LineEdit->setText("");
		ui->textIDShowSft3LineEdit->setText("");
		ui->startTimeShowSft4LineEdit->setText("");
		ui->textIDShowSft4LineEdit->setText("");
		ui->startTimeShowSft2LineEdit->setEnabled(false);
		ui->textIDShowSft2LineEdit->setEnabled(false);
		ui->startTimeShowSft3LineEdit->setEnabled(false);
		ui->textIDShowSft3LineEdit->setEnabled(false);
		ui->startTimeShowSft4LineEdit->setEnabled(false);
		ui->textIDShowSft4LineEdit->setEnabled(false);
		break;
	case 2:
		ui->startTimeShowSft3LineEdit->setText("");
		ui->textIDShowSft3LineEdit->setText("");
		ui->startTimeShowSft4LineEdit->setText("");
		ui->textIDShowSft4LineEdit->setText("");
		ui->startTimeShowSft3LineEdit->setEnabled(false);
		ui->textIDShowSft3LineEdit->setEnabled(false);
		ui->startTimeShowSft4LineEdit->setEnabled(false);
		ui->textIDShowSft4LineEdit->setEnabled(false);
		break;
	case 3:
		ui->startTimeShowSft4LineEdit->setText("");
		ui->textIDShowSft4LineEdit->setText("");
		ui->startTimeShowSft4LineEdit->setEnabled(false);
		ui->textIDShowSft4LineEdit->setEnabled(false);
		break;
	}

	//文本长度
	QString textLen = ui->textLenShowLineEdit->text();
	int textLenInt = atoi(textLen.toStdString().c_str());
	//ui.textlineEdit1->setMaxLength(textLenInt);
	if (showTextLen1 > textLenInt)
	{
		//QMessageBox::warning(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("班次1超出输入范围"));
		QString warningtext1 = QString::fromLocal8Bit("班次1超出输入范围");
		informationMessage(warningtext1.toStdString());
		ui->textIDShowSft1LineEdit->setText(""); 
		return false;
	}
	if (showTextLen2 > textLenInt)
	{
		//QMessageBox::warning(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("班次1超出输入范围"));
		QString warningtext2 = QString::fromLocal8Bit("班次2超出输入范围");
		informationMessage(warningtext2.toStdString());
		ui->textIDShowSft2LineEdit->setText(""); 
		return false;
	}
	if (showTextLen3 > textLenInt)
	{
		//QMessageBox::warning(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("班次1超出输入范围"));
		QString warningtext3 = QString::fromLocal8Bit("班次3超出输入范围");
		informationMessage(warningtext3.toStdString());
		ui->textIDShowSft3LineEdit->setText(""); 
		return false;
	}
	if (showTextLen4 > textLenInt)
	{
		//QMessageBox::warning(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("班次1超出输入范围"));
		QString warningtext4 = QString::fromLocal8Bit("班次4超出输入范围");
		informationMessage(warningtext4.toStdString());
		ui->textIDShowSft4LineEdit->setText(""); 
		return false;
	}
	getCurTime(leftInt1,leftInt2,leftInt3,leftInt4);
	return true;
}

void FileEditChild::getCurTime(int leftInt1,int leftInt2,int leftInt3,int leftInt4)
{
	QTime timeNow = QTime::currentTime();
	//ui.textlineEdit4->setText(timeNow.toString());
	m_hour = timeNow.hour();
	//m_mint = timeNow.minute();
	string textFont = QString::fromLocal8Bit("5x5").toStdString();
	QString m_num = ui->shiftNumShowLineEdit->text();
	int numInt = atoi(m_num.toStdString().c_str());
	switch(numInt-1)
	{
	case 0:
		PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText1),0,0,0,1);
		break;
	case 1:
		if ( m_hour>= leftInt1 && m_hour< leftInt2)
		{   
			//string txtString = qstr2str(showText1);
			PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText1),0,0,0,1);
		}
		if ( m_hour>= leftInt2 || m_hour< leftInt1)
		{
			PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText2),0,0,0,1);
		}
		break;
	case 2:
		if ( m_hour>= leftInt1 && m_hour< leftInt2)
		{   
			//string txtString = qstr2str(showText1);
			PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText1),0,0,0,1);
		}
		if ( m_hour>= leftInt2 && m_hour< leftInt3)
		{
			PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText2),0,0,0,1);
		}
		if ( m_hour>= leftInt3 || m_hour< leftInt1)
		{
			PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText3),0,0,0,1);
		}
		break;
	case 3:
		if ( m_hour>= leftInt1 && m_hour< leftInt2)
		{   
			//string txtString = qstr2str(showText1);
			PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText1),0,0,0,1);
		}
		if ( m_hour>= leftInt2 && m_hour< leftInt3)
		{
			PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText2),0,0,0,1);
		}
		if ( m_hour>= leftInt3 && m_hour< leftInt4)
		{
			PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText3),0,0,0,1);
		}
		if ( m_hour< leftInt1 || m_hour>= leftInt4)
		{
			PushBackBanCiOBJ(textFont,false,false,false,qstr2str(showText4),0,0,0,1);
		}
		break;
	}
}

void FileEditChild::PushBackBanCiOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW)
{
	OBJ_Control* BanCiObj = new OBJ_Control;
	BanCiObj->strType1 = "text";
	BanCiObj->strType2 = "banci";
	BanCiObj->strFont = txtFont;
	BanCiObj->strText = txtContent;
	int txtLength = txtContent.length();
	BanCiObj->intLineSize = GetCharLenFromFont(txtFont,false);
	BanCiObj->intRowSize = GetCharLenFromFont(txtFont,true) * txtLength;
	BanCiObj->intLineStart = txtLineStart;
	BanCiObj->intRowStart = txtRowStart;
	BanCiObj->intSW = txtSW;
	BanCiObj->intSS = txtSS;
	BanCiObj->booNEG = txtNEG;
	BanCiObj->booBWDx = txtBWDx;
	BanCiObj->booBWDy = txtBWDy;

	BanCiObj->booFocus = true;
	m_MessagePrint.OBJ_Vec.push_back(BanCiObj); 
}
