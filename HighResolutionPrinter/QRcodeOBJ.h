#pragma once
#include "classmessage.h"

class CQRcodeOBJ : public OBJ_Control
{
public:
	CQRcodeOBJ(void);
	CQRcodeOBJ(OBJ_Control obj,CQRcodeOBJ QRcodeObj);
	~CQRcodeOBJ(void);

public://Parameters
	string strqrcodeVersion;//二维码的版本类型
	string strqrcodeECCLevel;//二维码的容错率等级
	int intqrcodeQuietZone;//二维码空白

	bool boQRBig;
	int intQRVersion;
	int intQRErrLevel;
	int intQREncodingMode;

public://Functions
	void CreateQrcode();

};

