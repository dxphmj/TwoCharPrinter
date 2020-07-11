#include "VecTextOBJ.h"


CVecTextOBJ::CVecTextOBJ(void)
{
}

CVecTextOBJ::CVecTextOBJ(OBJ_Control obj,CVecTextOBJ VecTextObj)
{
	strType1 = obj.strType1;
	strType2 = obj.strType2;
	intX = obj.intX;
	intY = obj.intY;
	intSW = obj.intSW;
	intSS = obj.intSS;

	strFont = obj.strFont;
	strText = obj.strText;

	booNEG = obj.booNEG;
	booBWDx = obj.booBWDx;
	booBWDy = obj.booBWDy;
	
	intLineSize = obj.intLineSize;
	intRowSize = obj.intRowSize;
	intLineStart = obj.intLineStart;
	intRowStart = obj.intRowStart;
	booFocus = obj.booFocus;

	intFontSize = VecTextObj.intFontSize;
	SideLength = 1;
	intSideHight = intLineSize;
	intSideWidth = intRowSize;

	booDotVecText.clear();
	booDotVecText = obj.booDotVecText; 

}

CVecTextOBJ::~CVecTextOBJ(void)
{
}


