#include "TimeOBJ.h"


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
