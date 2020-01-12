#include "paramsettingform.h"
#include "ui_paramsettingform.h"

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

	ui->printSettingBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/printSetting.bmp);font: bold;font-size:30px;color:rgb(255,255,255)}\
									   QPushButton:pressed{border-image: url(:/Images/printSetting.bmp);border: 1px solid rgb(12 , 138 , 235);\
									   padding-left:7px;padding-top:7px;}\
									   "); 
	ui->sysSettingBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/sysSetting.bmp);font: bold;font-size:30px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/sysSetting.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 "); 
	ui->countSettingBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/countSetting.bmp);font: bold;font-size:30px;color:rgb(255,255,255)}\
									   QPushButton:pressed{border-image: url(:/Images/countSetting.bmp);border: 1px solid rgb(12 , 138 , 235);\
									   padding-left:7px;padding-top:7px;}\
									   "); 
	ui->aboutMacBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/aboutMac.bmp);font: bold;font-size:30px;color:rgb(255,255,255)}\
								   QPushButton:pressed{border-image: url(:/Images/aboutMac.bmp);border: 1px solid rgb(12 , 138 , 235);\
								   padding-left:7px;padding-top:7px;}\
								   "); 
	ui->paraExitBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/exit.bmp);font: bold;font-size:30px;color:rgb(255,255,255)}\
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
	this->hide();
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