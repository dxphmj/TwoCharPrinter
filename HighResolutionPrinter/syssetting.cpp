#include "syssetting.h"
#include "UILanguage.h"
#include "mainwindow.h"

sysSetting::sysSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.addYearBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveup.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveup.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui.addMonthBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveup.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								 QPushButton:pressed{border-image: url(:/Images/moveup.bmp);border: 1px solid rgb(12 , 138 , 235);\
								 padding-left:7px;padding-top:7px;}\
								 "); 
	ui.addDayBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveup.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								 QPushButton:pressed{border-image: url(:/Images/moveup.bmp);border: 1px solid rgb(12 , 138 , 235);\
								 padding-left:7px;padding-top:7px;}\
								 "); 
	ui.addHourBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveup.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								 QPushButton:pressed{border-image: url(:/Images/moveup.bmp);border: 1px solid rgb(12 , 138 , 235);\
								 padding-left:7px;padding-top:7px;}\
								 "); 
	ui.addMinBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveup.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								 QPushButton:pressed{border-image: url(:/Images/moveup.bmp);border: 1px solid rgb(12 , 138 , 235);\
								 padding-left:7px;padding-top:7px;}\
								 "); 
	ui.addSecondBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveup.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								 QPushButton:pressed{border-image: url(:/Images/moveup.bmp);border: 1px solid rgb(12 , 138 , 235);\
								 padding-left:7px;padding-top:7px;}\
								 "); 
	ui.reduceYearBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/movedown.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								  QPushButton:pressed{border-image: url(:/Images/movedown.bmp);border: 1px solid rgb(12 , 138 , 235);\
								  padding-left:7px;padding-top:7px;}\
								  "); 
	ui.reduceMonthBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/movedown.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								  QPushButton:pressed{border-image: url(:/Images/movedown.bmp);border: 1px solid rgb(12 , 138 , 235);\
								  padding-left:7px;padding-top:7px;}\
								  "); 
	ui.reduceDayBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/movedown.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								  QPushButton:pressed{border-image: url(:/Images/movedown.bmp);border: 1px solid rgb(12 , 138 , 235);\
								  padding-left:7px;padding-top:7px;}\
								  "); 
	ui.reduceHourBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/movedown.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								  QPushButton:pressed{border-image: url(:/Images/movedown.bmp);border: 1px solid rgb(12 , 138 , 235);\
								  padding-left:7px;padding-top:7px;}\
								  "); 
	ui.reduceMinBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/movedown.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								  QPushButton:pressed{border-image: url(:/Images/movedown.bmp);border: 1px solid rgb(12 , 138 , 235);\
								  padding-left:7px;padding-top:7px;}\
								  "); 
	ui.reduceSecondBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/movedown.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								  QPushButton:pressed{border-image: url(:/Images/movedown.bmp);border: 1px solid rgb(12 , 138 , 235);\
								  padding-left:7px;padding-top:7px;}\
								  "); 


	//QLabel * label = new QLabel(this);
	//int      number = 10;
	//label->setText(tr("<font style = 'font-size:14px; color:red;'> num </font>") 
	//	+ tr("<font style = 'font-family:MicrosoftYaHei; font-size:20px; color:#F13232;'>%1</font>").arg(number));
	////label动态调整为文本大小
	//label->adjustSize();

	MainWindow* theApp = (MainWindow*)(this->parent()->parent());
	CUILanguage languageTool(theApp);
	languageTool.ChangeLanguage(ENGLISH);
 
}

sysSetting::~sysSetting()
{

}
