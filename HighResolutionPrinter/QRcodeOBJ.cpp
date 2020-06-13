#include "QRcodeOBJ.h"
#include "backend/zint.h"

CQRcodeOBJ::CQRcodeOBJ(void)
{	
	this->intqrcodeQuietZone=0;
}

CQRcodeOBJ::CQRcodeOBJ(OBJ_Control obj,CQRcodeOBJ QRcodeObj)
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

	strqrcodeVersion = QRcodeObj.strqrcodeVersion;
	strqrcodeECCLevel = QRcodeObj.strqrcodeECCLevel;
	intqrcodeQuietZone = QRcodeObj.intqrcodeQuietZone;
	boQRBig = QRcodeObj.boQRBig;
	intQRVersion = QRcodeObj.intQRVersion;
	intQRErrLevel = QRcodeObj.intQRErrLevel;
	intQREncodingMode = QRcodeObj.intQREncodingMode;

	SideLength = QRcodeObj.SideLength;
	intSideHight = SideLength * intLineSize;
	intSideWidth = SideLength * intRowSize;
	
	memcpy(boDotBmp,QRcodeObj.boDotBmp,sizeof(bool)*500*100);
}

CQRcodeOBJ::~CQRcodeOBJ(void)
{
}

void CQRcodeOBJ::CreateQrcode()
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	//int batch_mode;
	//int mirror_mode;
	//char filetype[4];
	int i;
	int v;

	error_number = 0;

	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = 58; //ä¸´æ—¶ç”¨ä¸€ä¸‹å˜é‡intQRVersion
	my_symbol->scale = 0.5;

	//	v=ui->sideLenQRComBox->currentIndex();
	my_symbol->option_2 = intQRVersion;//option_1ä¸ºå®¹é”™ç­‰çº§ï¼Œoption_2ä¸ºç‰ˆæœ¬å¤§å°å…¬å¼ä¸º:(V - 1) * 4 + 21ï¼?

	//batch_mode = 0;
	//mirror_mode = 0;
	//¶¯Ì¬Éú³É strText = ¾²Ì¬ + Ê±¼ä + ÐòÁÐºÅ
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strText.c_str(),strText.size(),rotate_angle);

	generated = 1;
	strType1 = "text";
	strType2 = "qrcode";		
	intLineSize = my_symbol->bitmap_height;
	intRowSize = my_symbol->bitmap_width;
	intSideHight = intLineSize * SideLength;
	intSideWidth = intRowSize * SideLength;

	i = 0;
	int r, g, b;

	for (int row = 0; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	booFocus = true;
}
