#pragma once
#include "classmessage.h"

class CBarcodeOBJ : public OBJ_Control
{
public:
	CBarcodeOBJ(void);
	~CBarcodeOBJ(void);

public://Parameters
	int intBarcodeType;//保存条形码的类型
	int intBarType;//保存条码类型
	string strCodeContent;//保存条形码的内容
	int intBarWhite;//保存条形码空白宽度

public://Functions
	void Create2Dcode();

};

