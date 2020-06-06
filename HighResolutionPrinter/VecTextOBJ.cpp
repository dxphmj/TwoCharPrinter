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

	booDotVecText.clear();
	booDotVecText = VecTextObj.booDotVecText; 

}

CVecTextOBJ::~CVecTextOBJ(void)
{
}

void CVecTextOBJ::GenerateVecBmp(string strFont, string strText, int intFontSize)
{
	ModuleMain* pModuleMain = new ModuleMain;

	QFont curFont;
	wstring wStrFont = pModuleMain->stringToWstring(strFont);
	QString qStrFont = QString::fromStdWString(wStrFont);
	curFont.setFamily(qStrFont);
	curFont.setPointSize(intFontSize);
	
	QFontMetrics fm(curFont);
	wstring wStrText = pModuleMain->stringToWstring(strText);
	QString qStrText = QString::fromStdWString(wStrText);
	int metrics_width = fm.width(qStrText);
	int metrics_height = fm.height();
	
	QPixmap pix(metrics_width, metrics_height);
	pix.fill(Qt::white);
	QRect rect1(0, 0, metrics_width, metrics_height);

	QPainter painter(&pix);
	painter.setFont(curFont);
	painter.setPen(Qt::black);
	painter.drawText(rect1,qStrText);

	QImage pImage;
	pImage = pix.toImage();

	//≤‚ ‘£∫2020-05-16 ’≈Á‚¨B
	bool s = pix.isNull();

	booDotVecText.clear();
	vector< vector<bool> > vbuffer(metrics_width, vector<bool>(metrics_height, false));
	booDotVecText = vbuffer;

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qBlue(line[x]))/3;  
			if(average < 200)
				booDotVecText[x][y] = true;
			else
				booDotVecText[x][y] = false;
		}  
	}  
 
}
