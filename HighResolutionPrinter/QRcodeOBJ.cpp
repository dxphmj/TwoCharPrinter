#include "QRcodeOBJ.h"
#include "backend\zint.h"

CQRcodeOBJ::CQRcodeOBJ(void)
{
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
	my_symbol->symbology = 58; //临时用一下变量intQRVersion
	my_symbol->scale = 0.5;

	//	v=ui->sideLenQRComBox->currentIndex();
	my_symbol->option_2 = intQRVersion;//option_1为容错等级，option_2为版本大小公式为:(V - 1) * 4 + 21；

	//batch_mode = 0;
	//mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strText.c_str(),strText.size(),rotate_angle);

	generated = 1;
	strType1="text";
	strType2="qrcode";		
	intLineSize=my_symbol->bitmap_height;
	intRowSize=my_symbol->bitmap_width;

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
				boDotBmp[col][my_symbol->bitmap_height-row-1] = true;//由于坐标系的原因，上下必须颠倒
			}
			else
			{
				boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	booFocus = true;
}
