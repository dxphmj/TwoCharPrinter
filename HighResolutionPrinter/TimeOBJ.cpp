#include "TimeOBJ.h"
#include "ModuleMain.h"


CTimeOBJ::CTimeOBJ(void)
{
	this->booETimeOffSet=0;
	this->intTimeOffSet=1;
}

CTimeOBJ::CTimeOBJ(OBJ_Control obj,CTimeOBJ TimeObj)
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

	strTime = TimeObj.strTime;
	booETimeOffSet = TimeObj.booETimeOffSet;
	intTimeOffSet = TimeObj.intTimeOffSet;
	strTimeOffSet = TimeObj.strTimeOffSet;

}

CTimeOBJ::~CTimeOBJ(void)
{
}

void CTimeOBJ::CreateTimeDynamic(vector<BYTE>& bytPrintDataAll,bool boReverse, bool boInverse,int matrixMesdis,int pixelMesdis,
									map<string,vector<BYTE> > bytdigital5x5LineMap,map<string,vector<BYTE> > bytdigital7x5LineMap,
									map<string,vector<BYTE> > bytdigital12x12LineMap,map<string,vector<BYTE> > bytdigital16x12LineMap,UINT32 *IntMes,int intRowMax)
{ 
	ModuleMain myModuleMain;
	//strText = myModuleMain.TimeFormatToText(myModuleMain.string2CString(strTime),booETimeOffSet,intTimeOffSet,strTimeOffSet);
	strText = myModuleMain.TimeFormatToText(QString::fromStdString(strTime),booETimeOffSet,intTimeOffSet,strTimeOffSet);
	int intRowEnd = intRowStart+intRowSize;
	vector<BYTE> ttVec;
	if (strText.length() != 0)
	{
		ttVec = DotToByte1(intRowStart, intRowEnd, bytPrintDataAll,strFont, booBWDy, booBWDx, booNEG,strText, 
						   intRowSize, intLineSize, intLineStart,intRowStart, intSS,intSW,boReverse, boInverse,matrixMesdis,pixelMesdis,
						   bytdigital5x5LineMap,bytdigital7x5LineMap,bytdigital12x12LineMap,bytdigital16x12LineMap,IntMes,intRowMax);

		bytPrintDataAll.clear();
		bytPrintDataAll = ttVec;
	}	  	 
}