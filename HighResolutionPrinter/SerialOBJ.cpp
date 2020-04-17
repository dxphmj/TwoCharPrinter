#include "SerialOBJ.h"


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
}

CSerialOBJ::~CSerialOBJ(void)
{
}
