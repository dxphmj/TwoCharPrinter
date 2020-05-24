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

	booNEG = obj.booNEG;
	booBWDx = obj.booBWDx;
	booBWDy = obj.booBWDy;
	
	intLineSize = obj.intLineSize;
	intRowSize = obj.intRowSize;
	intLineStart = obj.intLineStart;
	intRowStart = obj.intRowStart;
	booFocus = obj.booFocus;
}

CVecTextOBJ::~CVecTextOBJ(void)
{
}
