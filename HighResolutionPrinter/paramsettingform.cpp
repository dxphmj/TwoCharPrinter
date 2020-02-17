#include "paramsettingform.h"
#include "ui_paramsettingform.h"
#include "mainwindow.h"
#include "ParamSetting.h"

ParamSettingForm::ParamSettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParamSettingForm)
{
    ui->setupUi(this);
	connect(ui->paraExitBut,SIGNAL(clicked()),this,SLOT(paraExitBut_clicked()));

	connect(ui->printSettingBut,SIGNAL(clicked()),this,SLOT(printSettingBut_clicked()));
	connect(ui->sysSettingBut,SIGNAL(clicked()),this,SLOT(sysSettingBut_clicked()));
	connect(ui->countSettingBut,SIGNAL(clicked()),this,SLOT(countSettingBut_clicked()));
	connect(ui->aboutMacBut,SIGNAL(clicked()),this,SLOT(aboutMacBut_clicked()));

	connect(ui->savePrintSetBut,SIGNAL(clicked()),this,SLOT(holdConfigurationBut_clicked()));
	connect(ui->resetBut,SIGNAL(clicked()),this,SLOT(readConfigurationBut_clicked()));

	ui->printSettingBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/printSetting.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
									   QPushButton:pressed{border-image: url(:/Images/printSetting.bmp);border: 1px solid rgb(12 , 138 , 235);\
									   padding-left:7px;padding-top:7px;}\
									   "); 
	ui->sysSettingBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/sysSetting.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/sysSetting.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 "); 
	ui->countSettingBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/countSetting.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
									   QPushButton:pressed{border-image: url(:/Images/countSetting.bmp);border: 1px solid rgb(12 , 138 , 235);\
									   padding-left:7px;padding-top:7px;}\
									   "); 
	ui->aboutMacBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/aboutMac.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								   QPushButton:pressed{border-image: url(:/Images/aboutMac.bmp);border: 1px solid rgb(12 , 138 , 235);\
								   padding-left:7px;padding-top:7px;}\
								   "); 
	ui->paraExitBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/exit.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								   QPushButton:pressed{border-image: url(:/Images/exit.bmp);border: 1px solid rgb(12 , 138 , 235);\
								   padding-left:7px;padding-top:7px;}\
								   "); 
	
	m_printSetting = new printSetting(this);//实例化窗口页面
	m_sysSetting = new sysSetting(this);
	m_countSetting = new countSetting(this);
	m_aboutMac = new aboutMac(this);

	ui->paraManageStacWid->addWidget(m_printSetting);
	ui->paraManageStacWid->addWidget(m_sysSetting);
	ui->paraManageStacWid->addWidget(m_countSetting);
	ui->paraManageStacWid->addWidget(m_aboutMac);
	ui->paraManageStacWid->setCurrentWidget(m_printSetting);
}

ParamSettingForm::~ParamSettingForm()
{
    delete ui;
}

void ParamSettingForm::paraExitBut_clicked()
{
	this->close();
}

void ParamSettingForm::printSettingBut_clicked()
{
	ui->paraManageStacWid->setCurrentWidget(m_printSetting);
}

void ParamSettingForm::sysSettingBut_clicked()
{
	ui->paraManageStacWid->setCurrentWidget(m_sysSetting);
}

void ParamSettingForm::countSettingBut_clicked()
{
	ui->paraManageStacWid->setCurrentWidget(m_countSetting);
}

void ParamSettingForm::aboutMacBut_clicked()
{
	ui->paraManageStacWid->setCurrentWidget(m_aboutMac);
}

QString ParamSettingForm::getNum(QString str)
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

void ParamSettingForm::holdConfigurationBut_clicked()
{
	//先给m_ParamSetting中的参数赋值，然后调用CParamSetting中的函数SaveParam2Xml进行保存
	MainWindow* theApp = (MainWindow*)(this->parent());
	
	//打印风格参数
	theApp->m_ParamSetting.m_PrintingSpeed = getNum(m_printSetting->ui.printSpeedShowLab->text());
	theApp->m_ParamSetting.m_PrintDelay = getNum(m_printSetting->ui.printDelayShowLab->text());
	theApp->m_ParamSetting.m_SynFrequency = getNum(m_printSetting->ui.synFrequencyShowLab->text());
	theApp->m_ParamSetting.m_PrintGray = getNum(m_printSetting->ui.printGrayShowLab->text());
	theApp->m_ParamSetting.m_TriggerMode = QVariant(m_printSetting->ui.trigComBox->currentIndex()).toString();
	theApp->m_ParamSetting.m_InkjetMode = QVariant(m_printSetting->ui.inkjetComBox->currentIndex()).toString();
	theApp->m_ParamSetting.m_PrintingDirection = QVariant(m_printSetting->ui.printDirComBox->currentIndex()).toString();
	theApp->m_ParamSetting.m_SynWheelCheck = m_printSetting->ui.synWheelCheckBox->isChecked();
	theApp->m_ParamSetting.m_VoiceCheck = m_printSetting->ui.voiceCheckBox->isChecked();


	//高级设置参数
	theApp->m_ParamSetting.DPIradioBGcheckedId = m_printSetting->DPIradioBG->checkedId();
	theApp->m_ParamSetting.m_RepetePrintCheck = m_printSetting->ui.repetePrintCheckBox->isChecked();
	theApp->m_ParamSetting.m_RepeatTimes = getNum(m_printSetting->ui.repeteNumShowLab->text());
	theApp->m_ParamSetting.m_RepeatDelay = getNum(m_printSetting->ui.repeteDelayShowLab->text());
	 

	//喷头设置参数
	theApp->m_ParamSetting.m_AdaptParaCheck = m_printSetting->ui.adaptParaCheckBox->isChecked();	 
	theApp->m_ParamSetting.m_InkVoltage = getNum(m_printSetting->ui.voltShowLab->text());
	theApp->m_ParamSetting.m_InkPulseWidth = getNum(m_printSetting->ui.PWShowLab->text());
	theApp->m_ParamSetting.m_SplicingCheck = m_printSetting->ui.isCombineCheckBox->isChecked();
	theApp->m_ParamSetting.NozzleradioBGcheckedId = m_printSetting->NozzleradioBG->checkedId();
	theApp->m_ParamSetting.m_Offset = getNum(m_printSetting->ui.offsetShowLab->text());
	theApp->m_ParamSetting.m_FlashSprayCheck = m_printSetting->ui.flashSprayCheckBox->isChecked();
	theApp->m_ParamSetting.m_FlashSprayInterval = getNum(m_printSetting->ui.flashSprayInternalShowLab->text());
	theApp->m_ParamSetting.m_FlashSprayFrequency = getNum(m_printSetting->ui.flashSprayTimesShowLab->text());


	//UV灯设置参数
	theApp->m_ParamSetting.m_UsingUVLightCheck = m_printSetting->ui.isUVCheckBox->isChecked();
	theApp->m_ParamSetting.m_TimeExpand = getNum(m_printSetting->ui.delayTimeShowLab->text());
	theApp->m_ParamSetting.m_StartTime = getNum(m_printSetting->ui.startTimeShowLab->text());


	//系统设置参数
	theApp->m_ParamSetting.m_YearShow = getNum(m_sysSetting->ui.yearShowLab->text());
	theApp->m_ParamSetting.m_MonthShow = getNum(m_sysSetting->ui.monthShowLab->text());
	theApp->m_ParamSetting.m_DayShow = getNum(m_sysSetting->ui.dayShowLab->text());
	theApp->m_ParamSetting.m_HourShow = getNum(m_sysSetting->ui.hourShowLab->text());
	theApp->m_ParamSetting.m_MinShow = getNum(m_sysSetting->ui.minShowLab->text());
	theApp->m_ParamSetting.m_SecondShow = getNum(m_sysSetting->ui.secondShowLab->text());

	if (m_sysSetting->ui.sysLanguageListWid->currentRow() != -1)//等语言全部填入后再完善
	{	
		theApp->m_ParamSetting.m_SysLanguage = m_sysSetting->ui.sysLanguageListWid->currentItem()->text();
	}

	theApp->m_ParamSetting.SaveParam2Xml();
}

void ParamSettingForm::readConfigurationBut_clicked()
{
	MainWindow* theApp = (MainWindow*)(this->parent());
	theApp->m_ParamSetting.OpenParamFromXml(this);
}


