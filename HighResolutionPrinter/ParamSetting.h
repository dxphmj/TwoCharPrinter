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


	QString m_PrintingSpeed;//打印速度
	QString m_PrintDelay;//打印延时
	QString m_SynFrequency;//同步倍频
	QString m_PrintGray;//打印灰度
	QString m_TriggerMode;//触发方式
	QString m_InkjetMode;//喷墨方式
	QString m_PrintingDirection;//打印方向
	bool m_SynWheelCheck;//启用同步轮
	bool m_VoiceCheck;//声音

	int DPIradioBGcheckedId;//DPI按钮
	bool m_RepetePrintCheck;//重复打印
	QString m_RepeatTimes;//重复次数
	QString m_RepeatDelay;//重复延时

	bool m_AdaptParaCheck;//自适应参数
	QString m_InkVoltage;//电压
	QString m_InkPulseWidth;//脉宽
	bool m_SplicingCheck;//拼接
	int NozzleradioBGcheckedId;//喷头选择按钮
	QString m_Offset;//偏移量
	bool m_FlashSprayCheck;//闪喷
	QString m_FlashSprayInterval;//间隔
	QString m_FlashSprayFrequency;//次数

	bool m_UsingUVLightCheck;//启用UV灯
	QString m_TimeExpand;//延长时间
	QString m_StartTime;//开始时长
		 
	QString m_YearShow;//年
	QString m_MonthShow;//月
	QString m_DayShow;//日
	QString m_HourShow;//时
	QString m_MinShow;//分
	QString m_SecondShow;//秒
	QString m_SysLanguage;//系统语言

public:
	QXmlStreamReader xmlReader;

	void SaveParam2Xml();
	void OpenParamFromXml(ParamSettingForm* pParamSettingForm);

	void ReadOneParam(QWidget* pWidge);

};


