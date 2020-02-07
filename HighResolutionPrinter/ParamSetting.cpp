#include "ParamSetting.h"
#include <QFile>
#include <QDebug>
#include <QXmlStreamWriter>


CParamSetting::CParamSetting(void)
{
}


CParamSetting::~CParamSetting(void)
{
}

void CParamSetting::SaveParam2Xml()
{
	QFile file("System\\Configuration.xml"); //以只写方式创建一个文件
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		qDebug() << "Error: Cannot write file: "
			<< qPrintable(file.errorString());
		return;
	}

	QXmlStreamWriter xmlWriter(&file);
	xmlWriter.setAutoFormatting(true); //格式输出，也就是会有标签的缩进
	xmlWriter.writeStartDocument();//开始进行 XML 文档的输出,这个函数会写下 <?xml version="1.0" encoding="UTF-8"?>
	xmlWriter.writeStartElement("configuration_information"); //根节点
	xmlWriter.setCodec("gb18030");  // XML显示中文所用编码

	xmlWriter.writeStartElement("printsetting"); //一级节点

	xmlWriter.writeStartElement("Print_style"); //二级节点
	xmlWriter.writeTextElement("m_PrintingSpeed",m_PrintingSpeed); //输出一个仅包含文本内容的标签
	xmlWriter.writeTextElement("m_PrintDelay", m_PrintDelay);
	xmlWriter.writeTextElement("m_SynFrequency", m_SynFrequency);
	xmlWriter.writeTextElement("m_PrintGray", m_PrintGray);
	xmlWriter.writeTextElement("m_TriggerMode", m_TriggerMode);
	xmlWriter.writeTextElement("m_InkjetMode", m_InkjetMode);
	xmlWriter.writeTextElement("m_PrintingDirection", m_PrintingDirection);
	xmlWriter.writeTextElement("m_SynWheelCheck",QString::number(m_SynWheelCheck));
	xmlWriter.writeTextElement("m_VoiceCheck",QString::number(m_VoiceCheck));
	xmlWriter.writeEndElement(); //关闭标签


	xmlWriter.writeStartElement("advanced_setting"); //二级节点
	switch(DPIradioBGcheckedId)//判断点击DPI中哪个radio
	{
	case 1:
		{
			xmlWriter.writeTextElement("m_DPI150RadioBut",m_DPI150RadioBut);
			break;
		}
	case 2:
		{
			xmlWriter.writeTextElement("m_DPI200RadioBut",m_DPI200RadioBut);
			break;
		}
	case 3:
		{
			xmlWriter.writeTextElement("m_DPI300RadioBut",m_DPI300RadioBut);
			break;
		}
	case 4:
		{
			xmlWriter.writeTextElement("m_DPI600RadioBut",m_DPI600RadioBut);
			break;
		}
	}
	xmlWriter.writeTextElement("m_RepetePrintCheck",QString::number(m_RepetePrintCheck));
	xmlWriter.writeTextElement("m_RepeatTimes", m_RepeatTimes);
	xmlWriter.writeTextElement("m_RepeatDelay", m_RepeatDelay);
	xmlWriter.writeEndElement();

	xmlWriter.writeStartElement("Sprinklerhead_setting"); //二级节点
	xmlWriter.writeTextElement("m_AdaptParaCheck",QString::number(m_AdaptParaCheck));
	xmlWriter.writeTextElement("m_InkVoltage", m_InkVoltage);
	xmlWriter.writeTextElement("m_InkPulseWidth", m_InkPulseWidth);
	switch(NozzleradioBGcheckedId)//判断点击喷头选择中哪个radio
	{
	case 1:
		{
			xmlWriter.writeTextElement("m_NozzleSel1RadioBut",m_NozzleSel1RadioBut);
			break;
		}
	case 2:
		{
			xmlWriter.writeTextElement("m_NozzleSel2RadioBut",m_NozzleSel2RadioBut);
			break;
		}
	}		
	xmlWriter.writeTextElement("m_Offset", m_Offset);
	xmlWriter.writeTextElement("m_FlashSprayCheck",QString::number(m_FlashSprayCheck));
	xmlWriter.writeTextElement("m_FlashSprayInterval", m_FlashSprayInterval);
	xmlWriter.writeTextElement("m_FlashSprayFrequency", m_FlashSprayFrequency);
	xmlWriter.writeEndElement();

	xmlWriter.writeStartElement("UVlamp_setting"); //二级节点
	////xmlWriter.writeTextElement("page", "9");
	xmlWriter.writeEndElement();

	xmlWriter.writeEndElement();



	xmlWriter.writeStartElement("system_setting"); //一级节点
	xmlWriter.writeTextElement("m_DateTimeShow",m_DateTimeShow);
	xmlWriter.writeTextElement("m_SysLanguage",m_SysLanguage);
	xmlWriter.writeEndElement();


	xmlWriter.writeStartElement("count_setting"); //一级节点
	////xmlWriter.writeTextElement("page","111");
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

void CParamSetting::OpenParamFromXml()
{

}
