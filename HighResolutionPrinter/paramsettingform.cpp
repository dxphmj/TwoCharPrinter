#include "paramsettingform.h"
#include "ui_paramsettingform.h"
#include <QFile>
#include <QDebug>
#include <QXmlStreamWriter>
#include "mainwindow.h"

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

void ParamSettingForm::holdConfigurationBut_clicked()
{
	//先给m_ParamSetting中的参数赋值，然后调用CParamSetting中的函数SaveParam2Xml进行保存
	MainWindow* theApp = (MainWindow*)(this->parent());
	theApp->m_ParamSetting.SaveParam2Xml();

	//以下代码放入SaveParam2Xml()函数中

	QFile file("bookindex.xml"); //以只写方式创建一个文件
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		qDebug() << "Error: Cannot write file: "
			<< qPrintable(file.errorString());
		return;
	}

	QXmlStreamWriter xmlWriter(&file);
	xmlWriter.setAutoFormatting(true); //格式输出，也就是会有标签的缩进
	xmlWriter.writeStartDocument();//开始进行 XML 文档的输出,这个函数会写下 <?xml version="1.0" encoding="UTF-8"?>
	xmlWriter.writeStartElement("configuration_information"); //根节点


	xmlWriter.writeStartElement("printsetting"); //写下一个 entry 的开始标签

	xmlWriter.writeStartElement("Print_style"); //写下一个 entry 的开始标签
	//xmlWriter.writeAttribute("term", "sidebearings"); //然后给这个标签一个属性 term，属性值是 of vectors。
	xmlWriter.writeTextElement("Printing_speed",m_printSetting->ui.printSpeedShowLab->text()); //输出一个仅包含文本内容的标签
	xmlWriter.writeTextElement("Print_delay", m_printSetting->ui.printDelayShowLab->text());
	xmlWriter.writeTextElement("synFrequency", m_printSetting->ui.synFrequencyShowLab->text());
	xmlWriter.writeTextElement("Print_Gray", m_printSetting->ui.printGrayShowLab->text());
	xmlWriter.writeTextElement("Trigger_mode", m_printSetting->ui.trigComBox->currentText());
	xmlWriter.writeTextElement("Inkjet_mode", m_printSetting->ui.inkjetComBox->currentText());
	xmlWriter.writeTextElement("Printing_direction", m_printSetting->ui.printDirComBox->currentText());
	xmlWriter.writeEndElement(); //关闭标签

	xmlWriter.writeStartElement("advanced_setting");
	//xmlWriter.writeAttribute("term", "subtraction");
	xmlWriter.writeTextElement("Repetitions", m_printSetting->ui.repeteNumShowLab->text());
	xmlWriter.writeTextElement("Repetitive_delay", m_printSetting->ui.repeteDelayShowLab->text());
	xmlWriter.writeEndElement();

	xmlWriter.writeStartElement("Sprinklerhead_setting");
	//xmlWriter.writeAttribute("term", "subtraction");
	xmlWriter.writeTextElement("Ink_Voltage", m_printSetting->ui.voltShowLab->text());
	xmlWriter.writeTextElement("Ink_Pulse_width", m_printSetting->ui.PWShowLab->text());
	xmlWriter.writeTextElement("Flash_spray_Voltage", m_printSetting->ui.flashSprayVolShowLab->text());
	xmlWriter.writeTextElement("Flash_sprayk_Pulse_width", m_printSetting->ui.flashSprayPWShowLab->text());
	xmlWriter.writeTextElement("Offset", m_printSetting->ui.offsetShowLab->text());
	xmlWriter.writeEndElement();

	//xmlWriter.writeStartElement("UVlamp_setting");
	////xmlWriter.writeAttribute("term", "of vectors");
	//xmlWriter.writeTextElement("page", "9");
	//xmlWriter.writeEndElement();

	xmlWriter.writeEndElement();


	xmlWriter.writeStartElement("system_setting");
	//xmlWriter.writeAttribute("term", "subtraction");
	QString a = m_sysSetting->ui.yearShowBut->text();
	QString b = m_sysSetting->ui.monthShowBut->text();
	QString c = m_sysSetting->ui.dayShowBut->text();
	QString d = m_sysSetting->ui.hourShowBut->text();
	QString e = m_sysSetting->ui.minShowBut->text();
	QString f = m_sysSetting->ui.secondShowBut->text();

	xmlWriter.writeTextElement("system_time",a+b+c+d+e+f);
	xmlWriter.writeEndElement();


	xmlWriter.writeStartElement("count_setting");
	//xmlWriter.writeAttribute("term", "of vectors");
	xmlWriter.writeTextElement("page", "9");
	xmlWriter.writeEndElement();

	xmlWriter.writeEndElement();

	xmlWriter.writeEndDocument(); //这个 XML 文档已经写完。

	file.close();
	if (file.error()) {
		qDebug() << "Error: Cannot write file: "
			<< qPrintable(file.errorString());
		return;
	}
}
