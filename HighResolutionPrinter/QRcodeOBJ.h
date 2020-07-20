#pragma once
#include "ClassMessage.h"

class CQRcodeOBJ : public OBJ_Control
{
public:
	CQRcodeOBJ(void);
	CQRcodeOBJ(OBJ_Control obj,CQRcodeOBJ QRcodeObj);
	~CQRcodeOBJ(void);

public://Parameters
	string strqrcodeVersion;//浜岀淮鐮佺殑鐗堟湰绫诲瀷
	string strqrcodeECCLevel;//浜岀淮鐮佺殑瀹归敊鐜囩瓑绾?
	int intqrcodeQuietZone;//浜岀淮鐮佺┖鐧?

	bool boQRBig;
	int intQRVersion;
	int intQRErrLevel;
	int intQREncodingMode;


	//时间，静态文本，序列号 以成员变量的形式
	//CTextOBJ m_StaticTextOBJ;
	//CSerialOBJ m_SerialOBJ;
	//CTimeOBJ   m_TimeOBJ;

	vector<OBJ_Control*> OBJ_Vec;


public://Functions
	void CreateQrcode();

};

