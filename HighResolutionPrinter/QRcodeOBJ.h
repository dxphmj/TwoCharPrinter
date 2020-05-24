#pragma once
#include "ClassMessage.h"

class CQRcodeOBJ : public OBJ_Control
{
public:
	CQRcodeOBJ(void);
	CQRcodeOBJ(OBJ_Control obj,CQRcodeOBJ QRcodeObj);
	~CQRcodeOBJ(void);

public://Parameters
	string strqrcodeVersion;//äºŒç»´ç çš„ç‰ˆæœ¬ç±»å‹
	string strqrcodeECCLevel;//äºŒç»´ç çš„å®¹é”™ç‡ç­‰çº§
	int intqrcodeQuietZone;//äºŒç»´ç ç©ºç™½

	bool boQRBig;
	int intQRVersion;
	int intQRErrLevel;
	int intQREncodingMode;


	//Ê±¼ä£¬¾²Ì¬ÎÄ±¾£¬ĞòÁĞºÅ ÒÔ³ÉÔ±±äÁ¿µÄĞÎÊ½
	//CTextOBJ m_StaticTextOBJ;
	//CSerialOBJ m_SerialOBJ;
	//CTimeOBJ   m_TimeOBJ;

	vector<OBJ_Control*> OBJ_Vec;


public://Functions
	void CreateQrcode();

};

