#include "BmpObj.h"
#include <QPainter>

CBmpObj::CBmpObj(void)
{
}

CBmpObj::CBmpObj(OBJ_Control obj,CBmpObj bmpObj)
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

	memcpy(boDotBmp,bmpObj.boDotBmp,sizeof(bool)*500*100);
}

CBmpObj::~CBmpObj(void)
{
}

void CBmpObj::ReadBmp(char* strFileName)
{
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	QImage pImage;
	pImage = pLoad.toImage();

	int intLineSize = pImage.width();
	int intRowSize = pImage.height();

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qBlue(line[x]))/3;
			if(average < 200)
				boDotBmp[x][intRowSize-y-1] = true;
			else
				boDotBmp[x][intRowSize-y-1] = false;
		}  
	}  
}
 