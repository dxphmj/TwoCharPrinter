#include "ParamSetting.h"
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QXmlStreamWriter>
#include "mainwindow.h"
#include "paramsettingform.h"


CParamSetting::CParamSetting(void)
{
}


CParamSetting::~CParamSetting(void)
{
}

void CParamSetting::SaveParam2Xml()
{
	QDir configurationDir;
	QString currentDir = configurationDir.currentPath();

#ifdef BIG_CHAR
	QString configurationPath = currentDir + "/System/Configuration-BigChar.xml";
#else
	QString configurationPath = currentDir + "/System/Configuration-HighRes.xml";
#endif
	
	QFile file(configurationPath); //以只写方式创建一个文件
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		qDebug() << "Error: Cannot write file: "
			<< qPrintable(file.errorString());
		return;
	}

	QXmlStreamWriter xmlWriter(&file);
	xmlWriter.setAutoFormatting(true); //格式输出，也就是会有标签的缩进
	xmlWriter.writeStartDocument();//开始进行 XML 文档的输出,这个函数会写下 <?xml version="1.0" encoding="UTF-8"?>
	xmlWriter.writeStartElement("configuration_information"); //根节点

	xmlWriter.writeStartElement("printsetting"); //一级节点

	//打印风格参数
	xmlWriter.writeTextElement("m_PrintingSpeed",m_PrintingSpeed); //输出一个仅包含文本内容的标签
	xmlWriter.writeTextElement("m_PrintDelay", m_PrintDelay);
	xmlWriter.writeTextElement("m_SynFrequency", m_SynFrequency);
	xmlWriter.writeTextElement("m_PrintGray", m_PrintGray);
	xmlWriter.writeTextElement("m_TriggerMode", m_TriggerMode);
#ifdef BIG_CHAR
#else
	xmlWriter.writeTextElement("m_InkjetMode", m_InkjetMode);
#endif
	xmlWriter.writeTextElement("m_PrintingDirection", m_PrintingDirection);
	xmlWriter.writeTextElement("m_SynWheelCheck",QString::number(m_SynWheelCheck));
	xmlWriter.writeTextElement("m_VoiceCheck",QString::number(m_VoiceCheck));

	//高级设置参数
#ifdef BIG_CHAR
#else
	xmlWriter.writeTextElement("XDPIradioBGcheckedId",QVariant(XDPIradioBGcheckedId).toString());
	xmlWriter.writeTextElement("YDPIradioBGcheckedId",QVariant(YDPIradioBGcheckedId).toString());
#endif
	xmlWriter.writeTextElement("m_RepetePrintCheck",QString::number(m_RepetePrintCheck));
	xmlWriter.writeTextElement("m_RepeatTimes", m_RepeatTimes);
	xmlWriter.writeTextElement("m_RepeatDelay", m_RepeatDelay);

	//喷头设置参数
#ifdef BIG_CHAR
#else
	xmlWriter.writeTextElement("m_AdaptParaCheck",QString::number(m_AdaptParaCheck));
	xmlWriter.writeTextElement("m_InkVoltage", m_InkVoltage);
	xmlWriter.writeTextElement("m_InkPulseWidth", m_InkPulseWidth);
#endif
	xmlWriter.writeTextElement("m_SplicingCheck",QString::number(m_SplicingCheck));
	xmlWriter.writeTextElement("NozzleradioBGcheckedId",QVariant(NozzleradioBGcheckedId).toString());	
	xmlWriter.writeTextElement("m_Offset", m_Offset);
	xmlWriter.writeTextElement("m_FlashSprayCheck",QString::number(m_FlashSprayCheck));
	xmlWriter.writeTextElement("m_FlashSprayInterval", m_FlashSprayInterval);
	xmlWriter.writeTextElement("m_FlashSprayFrequency", m_FlashSprayFrequency);

	//UV灯设置参数
	xmlWriter.writeTextElement("m_UsingUVLightCheck",QString::number(m_UsingUVLightCheck));
	xmlWriter.writeTextElement("m_TimeExpand", m_TimeExpand);
	xmlWriter.writeTextElement("m_StartTime", m_StartTime);
	xmlWriter.writeEndElement();


	//系统设置参数
	xmlWriter.writeStartElement("system_setting"); //一级节点
	xmlWriter.writeTextElement("m_YearShow",m_YearShow);
	xmlWriter.writeTextElement("m_MonthShow",m_MonthShow);
	xmlWriter.writeTextElement("m_DayShow",m_DayShow);
	xmlWriter.writeTextElement("m_HourShow",m_HourShow);
	xmlWriter.writeTextElement("m_MinShow",m_MinShow);
    xmlWriter.writeTextElement("m_SecondShow",m_SecondShow);

	xmlWriter.writeTextElement("m_SysLanguage",m_SysLanguage);
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

void CParamSetting::ReadOneParam(QWidget* pWidge)
{
	while(!xmlReader.atEnd())
	{        
		if(xmlReader.isEndElement()) 
		{ 
			xmlReader.readNext();
			break;       
		} 
		QString strTmp = xmlReader.name().toString();
		if(!xmlReader.isStartElement())
		{
			xmlReader.readNext();
			continue;
		}
		QString ItemValue = xmlReader.readElementText();
		printSetting *pPrintSetting = qobject_cast<printSetting*>(pWidge);  
		sysSetting *pSysSetting = qobject_cast<sysSetting*>(pWidge);  
		if(pPrintSetting)		//printsetting
		{
			if(xmlReader.name().toString() == "m_PrintingSpeed")
			{
				m_PrintingSpeed = ItemValue;   
			    pPrintSetting->ui.printSpeedShowLab->setText(m_PrintingSpeed);
			}
			else if(xmlReader.name().toString() == "m_PrintDelay")
			{
				m_PrintDelay = ItemValue;
				pPrintSetting->ui.printDelayShowLab->setText(m_PrintDelay);
			}
			else if(xmlReader.name().toString() == "m_SynFrequency")
			{
				m_SynFrequency = ItemValue;
				pPrintSetting->ui.synFrequencyShowLab->setText(m_SynFrequency);
			}
			else if(xmlReader.name().toString() == "m_PrintGray")
			{
				m_PrintGray = ItemValue;
				pPrintSetting->ui.printGrayShowLab->setText(m_PrintGray);
			}			
			else if(xmlReader.name().toString() == "m_TriggerMode")
			{
				m_TriggerMode = ItemValue;
				pPrintSetting->ui.trigComBox->setCurrentIndex(QVariant(m_TriggerMode).toInt());
			}

			else if(xmlReader.name().toString() == "m_InkjetMode")
			{
				m_InkjetMode = ItemValue;
				pPrintSetting->ui.inkjetComBox->setCurrentIndex(QVariant(m_InkjetMode).toInt());
			}
			else if(xmlReader.name().toString() == "m_PrintingDirection")
			{
				m_PrintingDirection = ItemValue;
				pPrintSetting->ui.printDirComBox->setCurrentIndex(QVariant(m_PrintingDirection).toInt());
			}
			else if(xmlReader.name().toString() == "m_SynWheelCheck")
			{
				m_SynWheelCheck = QVariant(ItemValue).toBool();
				pPrintSetting->ui.synWheelCheckBox->setChecked(m_SynWheelCheck);
				pPrintSetting->synWheelCheckBox_valueChanged(m_SynWheelCheck);
			}
			else if(xmlReader.name().toString() == "m_VoiceCheck")
			{
				m_VoiceCheck = QVariant(ItemValue).toBool();
				pPrintSetting->ui.voiceCheckBox->setChecked(m_VoiceCheck);
			}

#ifdef BIG_CHAR
#else
			else if(xmlReader.name().toString() == "XDPIradioBGcheckedId")
			{
				XDPIradioBGcheckedId = QVariant(ItemValue).toInt();
				pPrintSetting->XDPIradioBG->button(XDPIradioBGcheckedId)->setChecked(1);
			}
			else if(xmlReader.name().toString() == "YDPIradioBGcheckedId")
			{
				YDPIradioBGcheckedId = QVariant(ItemValue).toInt();
				pPrintSetting->YDPIradioBG->button(YDPIradioBGcheckedId)->setChecked(1);
			}
#endif
			
			else if(xmlReader.name().toString() == "m_RepetePrintCheck")
			{
				m_RepetePrintCheck = QVariant(ItemValue).toBool();
				pPrintSetting->ui.repetePrintCheckBox->setChecked(m_RepetePrintCheck);
			}
			else if(xmlReader.name().toString() == "m_RepeatTimes")
			{
				m_RepeatTimes = ItemValue;
				pPrintSetting->ui.repeteNumShowLab->setText(m_RepeatTimes);
			}
			else if(xmlReader.name().toString() == "m_RepeatDelay")
			{
				m_RepeatDelay = ItemValue;
				pPrintSetting->ui.repeteDelayShowLab->setText(m_RepeatDelay);
			}
			else if(xmlReader.name().toString() == "m_AdaptParaCheck")
			{
				m_AdaptParaCheck = QVariant(ItemValue).toBool();
				pPrintSetting->ui.adaptParaCheckBox->setChecked(m_AdaptParaCheck);
			}
			else if(xmlReader.name().toString() == "m_InkVoltage")
			{
				m_InkVoltage = ItemValue;
				pPrintSetting->ui.voltShowLab->setText(m_InkVoltage);
			}
			else if(xmlReader.name().toString() == "m_InkPulseWidth")
			{
				m_InkPulseWidth = ItemValue;
				pPrintSetting->ui.PWShowLab->setText(m_InkPulseWidth);
			}
			else if(xmlReader.name().toString() == "m_SplicingCheck")
			{
				m_SplicingCheck = QVariant(ItemValue).toBool();
				pPrintSetting->ui.isCombineCheckBox->setChecked(m_SplicingCheck);
			}
			else if(xmlReader.name().toString() == "NozzleradioBGcheckedId")
			{
				NozzleradioBGcheckedId = QVariant(ItemValue).toInt();
				pPrintSetting->NozzleradioBG->button(NozzleradioBGcheckedId)->setChecked(1);
			}			
			else if(xmlReader.name().toString() == "m_Offset")
			{
				m_Offset = ItemValue;
				pPrintSetting->ui.offsetShowLab->setText(m_Offset);
			}
			else if(xmlReader.name().toString() == "m_FlashSprayCheck")
			{
				m_FlashSprayCheck = QVariant(ItemValue).toBool();
				pPrintSetting->ui.flashSprayCheckBox->setChecked(m_FlashSprayCheck);
			}
			else if(xmlReader.name().toString() == "m_FlashSprayInterval")
			{
				m_FlashSprayInterval = ItemValue;
				pPrintSetting->ui.flashSprayInternalShowLab->setText(m_FlashSprayInterval);
			}
			else if(xmlReader.name().toString() == "m_UsingUVLightCheck")
			{
				m_UsingUVLightCheck = QVariant(ItemValue).toBool();
				pPrintSetting->ui.isUVCheckBox->setChecked(m_UsingUVLightCheck);
			}
			else if(xmlReader.name().toString() == "m_TimeExpand")
			{
				m_TimeExpand = ItemValue;
				pPrintSetting->ui.delayTimeShowLab->setText(m_TimeExpand);
			}
			else if(xmlReader.name().toString() == "m_StartTime")
			{
				m_StartTime = ItemValue;
				pPrintSetting->ui.startTimeShowLab->setText(m_StartTime);
			}
		}
		else if(pSysSetting)//system_setting
		{		
			if(xmlReader.name() == "m_YearShow")
			{
				m_YearShow = ItemValue;
				pSysSetting->ui.yearShowLab->setText(m_YearShow);
			}
			else if(xmlReader.name() == "m_MonthShow")
			{
				m_MonthShow = ItemValue;
				pSysSetting->ui.monthShowLab->setText(m_MonthShow);
			}
			else if(xmlReader.name() == "m_DayShow")
			{
				m_DayShow = ItemValue;
				pSysSetting->ui.dayShowLab->setText(m_DayShow);
			}
			else if(xmlReader.name() == "m_HourShow")
			{
				m_HourShow = ItemValue;
				pSysSetting->ui.hourShowLab->setText(m_HourShow);
			}
			else if(xmlReader.name() == "m_MinShow")
			{
				m_MinShow = ItemValue;
				pSysSetting->ui.minShowLab->setText(m_MinShow);
			}
			else if(xmlReader.name() == "m_SecondShow")
			{
				m_SecondShow = ItemValue;
				pSysSetting->ui.secondShowLab->setText(m_SecondShow);
			}
			else if(xmlReader.name() == "m_SysLanguage")//等语言全部填入后再完善
				m_SysLanguage = ItemValue;
		}

		xmlReader.readNext(); 
	}
}

void CParamSetting::OpenParamFromXml(ParamSettingForm* pParamSettingForm)
{
	QDir configurationDir;
	QString currentDir = configurationDir.currentPath();

#ifdef BIG_CHAR
	QString configurationPath = currentDir + "/System/Configuration-BigChar.xml";
#else
	QString configurationPath = currentDir + "/System/Configuration-HighRes.xml";
#endif
	
	QFile file(configurationPath);
	if(!file.open(QFile::ReadOnly | QFile::Text)) return;
	 
	//构建QXmlStreamReader对象
	xmlReader.setDevice(&file);
	while(!xmlReader.atEnd())
	{
		QString strTmp = xmlReader.name().toString();
		//判断是否是节点的开始
		if(xmlReader.isStartElement() && xmlReader.name().toString() == "printsetting")
		{		
			xmlReader.readNext(); 
			while(!xmlReader.atEnd())
			{        
				if(xmlReader.isEndElement()) 
				{           
					xmlReader.readNext(); 
					break;       
				}        
				if(xmlReader.isStartElement())	
				{
					ReadOneParam(pParamSettingForm->m_printSetting);	
					break;
				}
				xmlReader.readNext();
			 }							 
		}
		else if(xmlReader.isStartElement() && xmlReader.name().toString() == "system_setting")
		{		
			xmlReader.readNext(); 
			while(!xmlReader.atEnd())
			{        
				if(xmlReader.isEndElement()) 
				{           
					xmlReader.readNext(); 
					break;       
				}        
				if(xmlReader.isStartElement())
				{
					ReadOneParam(pParamSettingForm->m_sysSetting);	
					break;
				}
				xmlReader.readNext();					 
			 }							 
		}
		else
		{
			xmlReader.readNext();
			strTmp = xmlReader.name().toString();
		}
	}
}     
 
