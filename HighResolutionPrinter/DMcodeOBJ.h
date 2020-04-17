#pragma once
#include "classmessage.h"

class CDMcodeOBJ :	public OBJ_Control
{
public:
	CDMcodeOBJ(void);
	CDMcodeOBJ(OBJ_Control obj,CDMcodeOBJ DMcodeObj);
	~CDMcodeOBJ(void);

public://Parameters
	int intDMsize;//保存DM码大小
	int intDMrow;//保存DM码大小当前行
	string strDMContent;//保存DM码的内容

public://Functions
	void CreateDMcode();

};

