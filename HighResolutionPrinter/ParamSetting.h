#pragma once

#include <QString>
#include <QXmlStreamReader>

typedef unsigned char BYTE;

class ParamSettingForm;

class CParamSetting
{
public:
	CParamSetting(void);
	virtual ~CParamSetting(void);

	//pcf控制0X00
	//BYTE pcf0X00bit1_bit0 ;// 列触发方式：0为编码器1相，1为编码器2相，2为内部一列点数（即等于64K/划速率）
	//BYTE pcf0X00bit2 ; //同步器反相，0：A->B，1:B->A
	//BYTE pcf0X00bit4 ; //故障运行，正在打印遇到故障时的处理，0打印停止，1 打印继续，但墨点没有喷出来
	//BYTE pcf0X00bit5; //产品计数器重置，0 不重置，1 重置到设定值
	//BYTE pcf0X00bit6 ; //打印计数器重置，0 不重置，1 重置到设定值

	////pcf控制0X01
	//BYTE pcf0X01bit0 ; //是否启用电眼，0为关闭，1为启用
	//BYTE pcf0X01bit2 ; //电眼有效电平，0为低电平，1为高电平
	//BYTE pcf0X01bit3 ; //喷印模式为单次还是连续，0为单次，1为连续

	QString m_PrintingSpeed;
	QString m_PrintDelay;
	QString m_SynFrequency;
	QString m_PrintGray;
	QString m_TriggerMode;
	QString m_InkjetMode;
	QString m_PrintingDirection;
	bool m_SynWheelCheck;
	bool m_VoiceCheck;

	int DPIradioBGcheckedId;
	QString m_DPI150RadioBut;
	QString m_DPI200RadioBut;
	QString m_DPI300RadioBut;
	QString m_DPI600RadioBut;
	bool m_RepetePrintCheck;
	QString m_RepeatTimes;
	QString m_RepeatDelay;

	bool m_AdaptParaCheck;
	QString m_InkVoltage;
	QString m_InkPulseWidth;
	int NozzleradioBGcheckedId;
	QString m_NozzleSel1RadioBut;
	QString m_NozzleSel2RadioBut;
	QString m_Offset;
	bool m_FlashSprayCheck;
	QString m_FlashSprayInterval;
	QString m_FlashSprayFrequency;

	QString m_YearShow;
	QString m_MonthShow;
	QString m_DayShow;
	QString m_HourShow;
	QString m_MinShow;
	QString m_SecondShow;
	QString m_DateTimeShow;
	QString m_SysLanguage;

public:
	QXmlStreamReader xmlReader;

	void SaveParam2Xml();
	void OpenParamFromXml(ParamSettingForm* pParamSettingForm);

	void ReadOneParam(QWidget* pWidge);

};


