#include "syssetting.h"
#include "UILanguage.h"
#include "mainwindow.h"
#include "roll.h"

sysSetting::sysSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.sysLanguageListWid,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(seleSysLanguage()));

	connect(ui.addYearBut,SIGNAL(clicked()),this,SLOT(addYearBut()));
	connect(ui.reduceYearBut,SIGNAL(clicked()),this,SLOT(reduceYearBut()));
	connect(ui.addMonthBut,SIGNAL(clicked()),this,SLOT(addMonthBut()));
	connect(ui.reduceMonthBut,SIGNAL(clicked()),this,SLOT(reduceMonthBut()));
	connect(ui.addDayBut,SIGNAL(clicked()),this,SLOT(addDayBut()));
	connect(ui.reduceDayBut,SIGNAL(clicked()),this,SLOT(reduceDayBut()));
	connect(ui.addHourBut,SIGNAL(clicked()),this,SLOT(addHourBut()));
	connect(ui.reduceHourBut,SIGNAL(clicked()),this,SLOT(reduceHourBut()));
	connect(ui.addMinBut,SIGNAL(clicked()),this,SLOT(addMinBut()));
	connect(ui.reduceMinBut,SIGNAL(clicked()),this,SLOT(reduceMinBut()));
	connect(ui.addSecondBut,SIGNAL(clicked()),this,SLOT(addSecondBut()));
	connect(ui.reduceSecondBut,SIGNAL(clicked()),this,SLOT(reduceSecondBut()));

	ui.sysLanguageListWid->addItem(QStringLiteral("ARABIC"));  
	ui.sysLanguageListWid->addItem(QStringLiteral("CHINESE_SIMPLIFIED")); 
	ui.sysLanguageListWid->addItem(QStringLiteral("CHINESE_TRADITIONAL"));  
	ui.sysLanguageListWid->addItem(QStringLiteral("CZECH"));  
	ui.sysLanguageListWid->addItem(QStringLiteral("DUTCH")); 
	ui.sysLanguageListWid->addItem(QStringLiteral("ENGLISH"));  
	ui.sysLanguageListWid->addItem(QStringLiteral("ESTONIAN"));  
	ui.sysLanguageListWid->addItem(QStringLiteral("FARSI")); 
	ui.sysLanguageListWid->addItem(QStringLiteral("FINNISH"));  
	ui.sysLanguageListWid->setCurrentRow(1);
	m_SelLanguage = 1;

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
	m_pMainWindow = (MainWindow*)(this->parent()->parent());
	 
}

void sysSetting::seleSysLanguage()
{
 	CUILanguage languageTool(m_pMainWindow);
	languageTool.ChangeLanguage(ui.sysLanguageListWid->currentRow());
	m_SelLanguage = ui.sysLanguageListWid->currentRow();
}


void sysSetting::addYearBut()
{
	QString str = ui.yearShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int yearFactor = str2.toInt();
	if (yearFactor>=1 && yearFactor <= 9999)
	{
		yearFactor+=1;
	} 
	else
	{
		yearFactor=2020;
	}
	ui.yearShowLab->setText(QString("%1").arg(yearFactor));

}

void sysSetting::reduceYearBut()
{
	QString str = ui.yearShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int yearFactor = str2.toInt();
	if (yearFactor>=1 && yearFactor <= 9999)
	{
		yearFactor-=1;
	} 
	else
	{
		yearFactor=2020;
	}
	ui.yearShowLab->setText(QString("%1").arg(yearFactor));

}

void sysSetting::addMonthBut()
{
	QString str = ui.monthShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int monthFactor = str2.toInt();
	if (monthFactor>=1 && monthFactor < 12)
	{
		monthFactor+=1;
	} 
	else
	{
		monthFactor=1;
	}
	ui.monthShowLab->setText(QString("%1").arg(monthFactor));

}

void sysSetting::reduceMonthBut()
{
	QString str = ui.monthShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int monthFactor = str2.toInt();
	if (monthFactor>1 && monthFactor <= 12)
	{
		monthFactor-=1;
	} 
	else
	{
		monthFactor=12;
	}
	ui.monthShowLab->setText(QString("%1").arg(monthFactor));

}

void sysSetting::addDayBut()
{
	QString str3 = ui.yearShowLab->text();
	QString str4 = m_printSetting->getNum(str3);
	int yearFactor = str4.toInt();

	QString str5 = ui.monthShowLab->text();
	QString str6 = m_printSetting->getNum(str5);
	int monthFactor = str6.toInt();

	QString str = ui.dayShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int dayFactor = str2.toInt();
	int ifAddDay;
	if (monthFactor == 1 || monthFactor == 3 || monthFactor == 5 || monthFactor == 7 || monthFactor == 8 || monthFactor == 10 || monthFactor == 12)
	{
		ifAddDay = 31;
	} 
	else if(monthFactor == 2)
	{
		if (yearFactor%4 == 0)
		{
			ifAddDay = 29;
		} 
		else
		{
			ifAddDay = 28;
		}
	}
	else
	{
		ifAddDay = 30;

	}
	if (dayFactor>=1 && dayFactor < ifAddDay)
	{
		dayFactor+=1;
	} 
	else
	{
		dayFactor=1;
	}
	ui.dayShowLab->setText(QString("%1").arg(dayFactor));

}

void sysSetting::reduceDayBut()
{
	QString str3 = ui.yearShowLab->text();
	QString str4 = m_printSetting->getNum(str3);
	int yearFactor = str4.toInt();

	QString str5 = ui.monthShowLab->text();
	QString str6 = m_printSetting->getNum(str5);
	int monthFactor = str6.toInt();

	QString str = ui.dayShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int dayFactor = str2.toInt();
	int ifAddDay;
	if (monthFactor == 1 || monthFactor == 3 || monthFactor == 5 || monthFactor == 7 || monthFactor == 8 || monthFactor == 10 || monthFactor == 12)
	{
		ifAddDay = 31;
	} 
	else if(monthFactor == 2)
	{
		if (yearFactor%4 == 0)
		{
			ifAddDay = 29;
		} 
		else
		{
			ifAddDay = 28;
		}
	}
	else
	{
		ifAddDay = 30;

	}
	if (dayFactor>1 && dayFactor <= ifAddDay)
	{
		dayFactor-=1;
	} 
	else
	{
		dayFactor=ifAddDay;
	}
	ui.dayShowLab->setText(QString("%1").arg(dayFactor));

}

void sysSetting::addHourBut()
{
	QString str = ui.hourShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int hourFactor = str2.toInt();
	if (hourFactor>=0 && hourFactor < 23)
	{
		hourFactor+=1;
	} 
	else
	{
		hourFactor=0;
	}
	ui.hourShowLab->setText(QString("%1").arg(hourFactor));

}

void sysSetting::reduceHourBut()
{
	QString str = ui.hourShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int hourFactor = str2.toInt();
	if (hourFactor>0 && hourFactor <= 23)
	{
		hourFactor-=1;
	} 
	else
	{
		hourFactor=23;
	}
	ui.hourShowLab->setText(QString("%1").arg(hourFactor));

}

void sysSetting::addMinBut()
{
	QString str = ui.minShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int minFactor = str2.toInt();
	if (minFactor>=0 && minFactor < 59)
	{
		minFactor+=1;
	} 
	else
	{
		minFactor=0;
	}
	ui.minShowLab->setText(QString("%1").arg(minFactor));

}

void sysSetting::reduceMinBut()
{
	QString str = ui.minShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int minFactor = str2.toInt();
	if (minFactor>0 && minFactor <= 59)
	{
		minFactor-=1;
	} 
	else
	{
		minFactor=59;
	}
	ui.minShowLab->setText(QString("%1").arg(minFactor));

}

void sysSetting::addSecondBut()
{
	QString str = ui.secondShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int secondFactor = str2.toInt();
	if (secondFactor>=0 && secondFactor < 59)
	{
		secondFactor+=1;
	} 
	else
	{
		secondFactor=0;
	}
	ui.secondShowLab->setText(QString("%1").arg(secondFactor));

}

void sysSetting::reduceSecondBut()
{
	QString str = ui.secondShowLab->text();
	QString str2 = m_printSetting->getNum(str);
	int secondFactor = str2.toInt();
	if (secondFactor>0 && secondFactor <= 59)
	{
		secondFactor-=1;
	} 
	else
	{
		secondFactor=59;
	}
	ui.secondShowLab->setText(QString("%1").arg(secondFactor));

}

sysSetting::~sysSetting()
{

}
