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

QString ParamSettingForm::getNum(QString str)
{
	//获取数字
	QString str1 = str;
	QString res;
	QChar ch;

	for(int i=0;i<str1.size();i++)
	{
		ch = str1.at(i);
		if(ch.toLatin1() <'0'||ch > '9')
			continue;
		if(((ch.toLatin1()-'0')%2)!=0||((ch.toLatin1()-'0')%2)!=1)
			res.append(ch);

	}

	return res;
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

	xmlWriter.writeTextElement("Printing_speed",getNum(m_printSetting->ui.printSpeedShowLab->text())); //输出一个仅包含文本内容的标签
	xmlWriter.writeTextElement("Print_delay", getNum(m_printSetting->ui.printDelayShowLab->text()));
	xmlWriter.writeTextElement("synFrequency", getNum(m_printSetting->ui.synFrequencyShowLab->text()));
	xmlWriter.writeTextElement("Print_Gray", getNum(m_printSetting->ui.printGrayShowLab->text()));
	xmlWriter.writeTextElement("Trigger_mode", m_printSetting->ui.trigComBox->currentText());
	xmlWriter.writeTextElement("Inkjet_mode", m_printSetting->ui.inkjetComBox->currentText());
	xmlWriter.writeTextElement("Printing_direction", m_printSetting->ui.printDirComBox->currentText());
	if (m_printSetting->ui.synWheelCheckBox->isChecked())
	{
		xmlWriter.writeTextElement("Enable_synchro_wheel", "1");
	} 
	else
	{
		xmlWriter.writeTextElement("Enable_synchro_wheel","0");
	}
	if (m_printSetting->ui.voiceCheckBox->isChecked())
	{
		xmlWriter.writeTextElement("voice", "1");
	} 
	else
	{
		xmlWriter.writeTextElement("voice","0");
	}
	xmlWriter.writeEndElement(); //关闭标签

	xmlWriter.writeStartElement("advanced_setting");
	//xmlWriter.writeAttribute("term", "subtraction");

	int t = m_printSetting->DPIradioBG->checkedId();
	QString  T;
	switch(t)
	{
	case 1:
		{
			T=m_printSetting->ui.DPI150RadioBut->text();
			break;
		}
	case 2:
		{
			T=m_printSetting->ui.DPI200RadioBut->text();
			break;
		}
	case 3:
		{
			T=m_printSetting->ui.DPI300RadioBut->text();
			break;
		}
	case 4:
		{
			T=m_printSetting->ui.DPI600RadioBut->text();
			break;
		}
	}
	xmlWriter.writeTextElement("DPI",T);
	
	if (m_printSetting->ui.repetePrintCheckBox->isChecked())
	{
		xmlWriter.writeTextElement("Repeat_printing", "1");
	} 
	else
	{
		xmlWriter.writeTextElement("Repetitions","0");
	}
	
	xmlWriter.writeTextElement("Repeat_times", getNum(m_printSetting->ui.repeteNumShowLab->text()));
	xmlWriter.writeTextElement("Repeat_delay", getNum(m_printSetting->ui.repeteDelayShowLab->text()));
	
	xmlWriter.writeEndElement();

	xmlWriter.writeStartElement("Sprinklerhead_setting");
	//xmlWriter.writeAttribute("term", "subtraction");

	if (m_printSetting->ui.adaptParaCheckBox->isChecked())
	{
		xmlWriter.writeTextElement("adaptPara","1");
	} 
	else
	{
		xmlWriter.writeTextElement("adaptPara","0");
	}

	xmlWriter.writeTextElement("Ink_Voltage", getNum(m_printSetting->ui.voltShowLab->text()));
	xmlWriter.writeTextElement("Ink_Pulse_width", getNum(m_printSetting->ui.PWShowLab->text()));
	xmlWriter.writeTextElement("Offset", getNum(m_printSetting->ui.offsetShowLab->text()));
	xmlWriter.writeTextElement("Flash_spray_interval", getNum(m_printSetting->ui.flashSprayInternalShowLab->text()));
	xmlWriter.writeTextElement("Flash_spray_frequency", getNum(m_printSetting->ui.flashSprayTimesShowLab->text()));
	int n = m_printSetting->NozzleradioBG->checkedId();
	QString  N;
	switch(n)
	{
	case 1:
		{
			N=m_printSetting->ui.nozzleSel1RadioBut->text();
			break;
		}
	case 2:
		{
			N=m_printSetting->ui.nozzleSel2RadioBut->text();
			break;
		}
	}
	xmlWriter.writeTextElement("nozzle_choose",N);

	if (m_printSetting->ui.flashSprayCheckBox->isChecked())
	{
		xmlWriter.writeTextElement("Flash_spray","1");
	} 
	else
	{
		xmlWriter.writeTextElement("Flash_spray","0");
	}
	xmlWriter.writeEndElement();

	//xmlWriter.writeStartElement("UVlamp_setting");
	////xmlWriter.writeAttribute("term", "of vectors");
	//xmlWriter.writeTextElement("page", "9");
	//xmlWriter.writeEndElement();

	xmlWriter.writeEndElement();

	 

	xmlWriter.writeStartElement("system_setting");
	//xmlWriter.writeAttribute("term", "subtraction");
	QString a = getNum(m_sysSetting->ui.yearShowLab->text());
	QString b = getNum(m_sysSetting->ui.monthShowLab->text());
	QString c = getNum(m_sysSetting->ui.dayShowLab->text());
	QString d = getNum(m_sysSetting->ui.hourShowLab->text());
	QString e = getNum(m_sysSetting->ui.minShowLab->text());
	QString f = getNum(m_sysSetting->ui.secondShowLab->text());

	xmlWriter.writeTextElement("system_time",a+b+c+d+e+f);
	xmlWriter.writeEndElement();


	xmlWriter.writeStartElement("count_setting");
	//xmlWriter.writeAttribute("term", "of vectors");

	//xmlWriter.writeTextElement("page","111");
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
