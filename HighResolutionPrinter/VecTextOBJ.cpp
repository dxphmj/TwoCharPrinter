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
}

CVecTextOBJ::~CVecTextOBJ(void)
{
}

void CVecTextOBJ::GenerateVecBmp(string strFont, string strText, int intFontSize)
{
	QFont curFont;
	curFont.setFamily(QString::fromStdString(strFont));
	curFont.setPointSize(intFontSize);
	
	QFontMetrics fm(curFont);
	int metrics_width = fm.width(QString::fromStdString(strText));
	int metrics_height = fm.height();
	
	QPixmap pix(metrics_width, metrics_height);
	pix.fill(Qt::white);
	QRect rect1(0, 0, metrics_width, metrics_height);

	QPainter painter(&pix);
	painter.setFont(curFont);
	painter.setPen(Qt::black);
	painter.drawText(rect1,QString::fromStdString(strText));

	QImage pImage;
	pImage = pix.toImage();

	//测试：2020-05-16 张玮珺
	bool s = pix.isNull();

	ModuleMain* pModuleMain = new ModuleMain;

	strType1 = "text";
	strType2 = "vtext";

	//此处将wchar_t*转换为char*赋值给strfont和strtext，以便pushback
	wStrFont = QString::fromStdString(strFont).toStdWString();
	wStrText = QString::fromStdString(strText).toStdWString();

	strFont = pModuleMain->WstringToString(wStrFont);
	strText = pModuleMain->WstringToString(wStrText);

	intLineSize = metrics_height;
	intRowSize = metrics_width;
	intLineStart = 0;
	intRowStart = 0;
	intSW = 0;
	intSS = 0;
	booNEG = false;
	booBWDx = false;
	booBWDy = false;

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
