#pragma once

#include <QWidget>

#define ARABIC					0 
#define CHINESE_SIMPLIFIED		1
#define CHINESE_TRADITIONAL		2
#define CZECH					3
#define DUTCH					4
#define ENGLISH					5 
#define ESTONIAN				6 
#define FARSI					7 
#define FINNISH					8 
#define FRENCH					9 
#define GERMAN					10 
#define HINDI					11 
#define HUNGARIAN				12 
#define ITALIAN					13 
#define JAPANESE				14 
#define KANNADA					15 
#define KOREAN					16 
#define POLISH					17 
#define PORTUGUESE				18 
#define ROMANIAN				19 
#define RUSSIAN					20 
#define SERBIAN					21 
#define SPANISH					22 
#define SWEDISH					23 
#define TAMIL					24 
#define THAI					25 
#define TURKISH					26 
#define VIETNAMESE				27 

class TiXmlNode;


class CUILanguage
{
public:
	CUILanguage(QObject* pMainwindow);
	virtual ~CUILanguage(void);

public:
	QObject* m_pMainwindow;
	bool m_codemode;

public:
	void ChangeLanguage(int nLanguageType);
	void ChangeLanguageForItem(QObject* pWidge,TiXmlNode* node);
};

