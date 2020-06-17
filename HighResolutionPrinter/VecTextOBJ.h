#pragma once

#include "ClassMessage.h"
#include "ModuleMain.h"

class CVecTextOBJ : public OBJ_Control
{
public:
	CVecTextOBJ(void);
	CVecTextOBJ(OBJ_Control obj,CVecTextOBJ VecTextObj);
	~CVecTextOBJ(void);

public://参数
	//wstring wStrFont;//字段的字体（有的类型有，有的类型没有�?
	//wstring wStrText;//字段的text属性，即内�?
	int intFontSize;//字号

public://方法
	void GenerateVecBmp(string strFont, string strText, int intFontSize);
};

