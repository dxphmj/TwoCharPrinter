#include "SerialOBJ.h"
#include "ModuleMain.h"

CSerialOBJ::CSerialOBJ(void)
{
	this->intSerialFirstLimit=1;
	this->intSerialSecondLimit=999999999;
    this->intSerialStartValue=1;
	this->intSerialStep=1;
	this->intSerialRepeat=1;
	this->intSerialDigits=9;
	this->intSerialCounter=0;
	this->bytSerialFormat=0;	
	this->CountNum=0;
}

CSerialOBJ::CSerialOBJ(OBJ_Control obj,CSerialOBJ SerialObj)
{
	strType1 = obj.strType1;
	strType2 = obj.strType2;
	intX = obj.intX;
	intY = obj.intY;
	intSW = obj.intSW;
	intSS = obj.intSS;

	booNEG = obj.booNEG;
	booBWDx = obj.booBWDx;
	booBWDy = obj.booBWDy;
	strFont = obj.strFont;
	strText = obj.strText;
	intLineSize = obj.intLineSize;
	intRowSize = obj.intRowSize;
	intLineStart = obj.intLineStart;
	intRowStart = obj.intRowStart;
	booFocus = obj.booFocus;

	intSerialFirstLimit = SerialObj.intSerialFirstLimit;
	intSerialSecondLimit = SerialObj.intSerialSecondLimit;
	intSerialStartValue = SerialObj.intSerialStartValue;
	intSerialStep = SerialObj.intSerialStep;
	intSerialRepeat = SerialObj.intSerialRepeat;
	intSerialDigits = SerialObj.intSerialDigits;
	intSerialCounter = SerialObj.intSerialCounter;
	bytSerialFormat = SerialObj.bytSerialFormat;
	CountNum = SerialObj.CountNum;
	CountNumRep = SerialObj.CountNumRep;
}

CSerialOBJ::~CSerialOBJ(void)
{
}

void CSerialOBJ::CreateSerialDynamic(vector<BYTE>& bytPrintDataAll,bool boReverse, bool boInverse,int matrixMesdis,int pixelMesdis,
									map<string,vector<BYTE>> bytdigital5x5LineMap,map<string,vector<BYTE>> bytdigital7x5LineMap,
									map<string,vector<BYTE>> bytdigital12x12LineMap,map<string,vector<BYTE>> bytdigital16x12LineMap,UINT32 *IntMes,int intRowMax)
{	 

	if (CountNumRep < intSerialRepeat)
		CountNumRep++; 
	else
	{
		CountNumRep = 1;
		if (intSerialFirstLimit < intSerialSecondLimit)
		{
			int tempValue = CountNum+intSerialStep;
			if (tempValue > intSerialSecondLimit)
			{
				CountNum = tempValue - intSerialSecondLimit + intSerialFirstLimit - 1; //'超第二象限的计算公式
			} 
			else
			{
				CountNum = tempValue;
			}
		}
		else if (intSerialFirstLimit > intSerialSecondLimit)
		{
			int tempValue = CountNum-intSerialStep;
			if (tempValue < intSerialSecondLimit)
			{
				CountNum = tempValue - intSerialSecondLimit + intSerialFirstLimit + 1; //'超第二象限的计算公式
			} 
			else
			{
				CountNum = tempValue;
			}
		}
	}	

	string StrSerialText = "";
	string strTemp = "";
	switch(bytSerialFormat)
	{
		case 0:
			for (int a = 0; a < intSerialDigits; a++)
			{
				strTemp = strTemp+"0";//123456789
			}
			strTemp = strTemp+to_String(CountNum);
			StrSerialText = strTemp.substr(strTemp.length()-intSerialDigits,intSerialDigits);
			break;
		case 1:
			for (int a = 0; a < intSerialDigits; a++)
			{
				strTemp = strTemp+" ";//123456789
			}
			strTemp = strTemp +OBJ_Control::to_String(CountNum);
			StrSerialText = strTemp.substr(strTemp.length()-intSerialDigits,intSerialDigits);
			break;
		case 2:
			strTemp = OBJ_Control::to_String(CountNum);
			int n = intSerialDigits-strTemp.length();
			for (int a = 0; a < n; a++)
			{
				strTemp = strTemp+" ";
			}
			StrSerialText = strTemp;
			break;
	}		 

	int intRowEnd = intRowStart+intRowSize;
	vector<BYTE> ttVec;
	if (StrSerialText.length() != 0)
	{
		ttVec = DotToByte1(intRowStart, intRowEnd, bytPrintDataAll,strFont, booBWDy, booBWDx, booNEG,StrSerialText, 
			               intRowSize, intLineSize, intLineStart,intRowStart, intSS,intSW,boReverse, boInverse,matrixMesdis,pixelMesdis,
						   bytdigital5x5LineMap,bytdigital7x5LineMap,bytdigital12x12LineMap,bytdigital16x12LineMap,IntMes,intRowMax);

		bytPrintDataAll.clear();
		bytPrintDataAll = ttVec;
	}	  
}