#pragma once
#include "ClassMessage.h"

class CSerialOBJ : public OBJ_Control
{
public:
	CSerialOBJ(void);
	CSerialOBJ(OBJ_Control obj,CSerialOBJ SerialObj);
	~CSerialOBJ(void);

public: 
	int intSerialFirstLimit;//字段的FirstLimit属性，即序列号第一象限
	int intSerialSecondLimit;//字段的SecondLimit属性，即序列号第二象限
	int intSerialStartValue;//字段的StartValue属性，即序列号起始值
	int intSerialStep;//字段的StepSize属性，即序列号步长值
	int intSerialRepeat;//字段的RepeatCount属性，即序列号重复值
	BYTE intSerialDigits;//字段的Digital属性，即序列号位数值
	int intSerialCounter;//第几个序列号
	BYTE bytSerialFormat;//字段的SerialFormat属性，即序列号格式

	int CountNum; //序列号当前值的大小
	int CountNumRep; //序列号当前重复的大小


public://Functions
	void CreateSerialDynamic(vector<BYTE>& bytPrintDataAll,bool boReverse, bool boInverse,int matrixMesdis,int pixelMesdis,map<string,
							vector<BYTE> > bytdigital5x5LineMap,map<string,vector<BYTE> > bytdigital7x5LineMap,
							map<string,vector<BYTE> > bytdigital12x12LineMap,map<string,vector<BYTE> > bytdigital16x12LineMap,UINT32 *IntMes,int intRowMax);

};

