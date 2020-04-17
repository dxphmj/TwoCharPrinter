#pragma once
#include "classmessage.h"

class CTimeOBJ : public OBJ_Control
{
public:
	CTimeOBJ(void);
	CTimeOBJ(OBJ_Control obj,CTimeOBJ TimeObj);
	~CTimeOBJ(void);

public: 
	string strTime;//字段的time属性，即时间格式
	int booETimeOffSet;//字段的时间偏移开关（false为关闭，true为开启）
	int intTimeOffSet;//字段的时间偏移值
	int strTimeOffSet;//字段的时间偏移类型
	

public://Functions

};

