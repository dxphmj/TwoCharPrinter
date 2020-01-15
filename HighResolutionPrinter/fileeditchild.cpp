#include "fileeditchild.h"
#include "filemanageform.h"
#include <QTableWidget>
#include "ClassMessage.h"
#include "backend\zint.h"

FileEditChild::FileEditChild(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.variableTextBut,SIGNAL(clicked()),this,SLOT(variableTextBut_clicked()));
	connect(ui.customTimeBut,SIGNAL(clicked()),this,SLOT(customTimeBut_clicked()));
	connect(ui.selBmpBut,SIGNAL(clicked()),this,SLOT(selBmpBut_clicked()));
	connect(ui.delBut,SIGNAL(clicked()),this,SLOT(delBut_clicked()));
	connect(ui.wordLineEdit,SIGNAL(clicked()),this,SLOT(wordLineEdit_clicked()));
	connect(ui.barCodeLineEdit,SIGNAL(clicked()),this,SLOT(barCodeLineEdit_clicked()));
	connect(ui.QRCodeLineEdit,SIGNAL(clicked()),this,SLOT(QRCodeLineEdit_clicked()));
	connect(ui.DMCodeLineEdit,SIGNAL(clicked()),this,SLOT(DMCodeLineEdit_clicked()));
	connect(ui.newTextBut,SIGNAL(clicked()),this,SLOT(newTextBut_clicked()));
	connect(ui.newBarCodeBut,SIGNAL(clicked()),this,SLOT(newBarCodeBut_clicked()));
	connect(ui.newQRBut,SIGNAL(clicked()),this,SLOT(newQRBut_clicked()));
	connect(ui.newDMBut,SIGNAL(clicked()),this,SLOT(newDMBut_clicked()));

	connect(ui.moveUpBut,SIGNAL(clicked()),this,SLOT(moveUpBut_clicked()));
	connect(ui.moveDownBut,SIGNAL(clicked()),this,SLOT(moveDownBut_clicked()));
	connect(ui.moveLeftBut,SIGNAL(clicked()),this,SLOT(moveLeftBut_clicked()));
	connect(ui.moveRightBut,SIGNAL(clicked()),this,SLOT(moveRightBut_clicked()));
	connect(ui.showNumCheckBox,SIGNAL(stateChanged()),this,SLOT(showNumCheckBox_clicked()));
	connect(ui.degreeBarCodeAddBut,SIGNAL(clicked()),this,SLOT(degreeBarCodeAddBut_clicked()));
	connect(ui.degreeBarCodeRedBut,SIGNAL(clicked()),this,SLOT(degreeBarCodeRedButt_clicked()));
	connect(ui.zoomBarCodeAddBut,SIGNAL(clicked()),this,SLOT(zoomBarCodeAddBut_clicked()));
	connect(ui.heightBarCodeAddBut,SIGNAL(clicked()),this,SLOT(heightBarCodeAddBut_clicked()));
	connect(ui.heightBarCodeRedBut,SIGNAL(clicked()),this,SLOT(heightBarCodeRedButt_clicked()));
	
	connect(ui.degreeQRAddBut,SIGNAL(clicked()),this,SLOT(degreeQRAddBut_clicked()));
	connect(ui.degreeQRRedBut,SIGNAL(clicked()),this,SLOT(degreeQRRedButt_clicked()));
	connect(ui.degreeDMAddBut,SIGNAL(clicked()),this,SLOT(degreeDMAddBut_clicked()));
	connect(ui.degreeDMRedBut,SIGNAL(clicked()),this,SLOT(degreeDMRedButt_clicked()));

    ui.wordLineEdit->setFocus();

	keyboardWidget = new keyboard(this);
	languageWidget = new language();
	ui.keyboardStackWid->addWidget(keyboardWidget);
	ui.keyboardStackWid->addWidget(languageWidget);
	
	ui.editPreviewText->installEventFilter(this);
	ui.typeTab->setStyleSheet("QTabWidget:pane{ \
							  boder: -2px solid white;top: -2px;background-color:rgb(0, 0, 230);}\
							  QTabBar::tab{font:'楷体' 16pt;color: white;height:50px; width:114px; background-color:rgb(0, 0, 230); margin-right: 2px; margin-bottom:-2px;}\
							  QTabBar::tab:selected{border:1px solid white;border-bottom-color: none;}\
							  QTabBar::tab:!selected{border-bottom: 3px solid white;}\
							  ");
	ui.showNumCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									  QCheckBox{color:rgb(255, 255, 255);}\
									  ");
	ui.reverseCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									  QCheckBox{color:rgb(255, 255, 255);}\
									  ");
	ui.natureNumCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
										QCheckBox{color:rgb(255, 255, 255);}\
									   ");
	ui.reverseBmpCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
		                                  QCheckBox{color:rgb(255, 255, 255);}\
										 ");
	ui.moveUpBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveup.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveup.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui.moveDownBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/movedown.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/movedown.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui.moveLeftBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveleft.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveleft.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui.moveRightBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveright.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveright.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui.degreeTextShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.internalShowTextLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.degreeTimeShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.currentValShowTimeLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.degreeSerialShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.currentValShowSerialLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.degreeBmpShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.heightBmpShowBmpLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.widthShowBmpLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.degreeBarCodeShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.zoomShowBarCodeLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.heightBarCodeShowQRLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
    ui.degreeQRShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.zoomShowQRLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.degreeDMShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui.zoomShowDMLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 


	ui.typeBarCodeComBox->addItem(QStringLiteral("EANX"));
	ui.typeBarCodeComBox->addItem(QStringLiteral("CODE39"));
	ui.typeBarCodeComBox->addItem(QStringLiteral("CODE93"));
	ui.typeBarCodeComBox->addItem(QStringLiteral("CODE128"));
	ui.typeBarCodeComBox->addItem(QStringLiteral("UPCA"));
	ui.typeBarCodeComBox->addItem(QStringLiteral("UPCE"));
	ui.typeBarCodeComBox->addItem(QStringLiteral("ITF14"));
	ui.typeBarCodeComBox->addItem(QStringLiteral("PDF417"));
	ui.typeBarCodeComBox->setCurrentIndex(3);

	degreenum=0;
 //	m_PrinterMes.ReadObjectsFromXml("User\\Label\\qr.lab");
    //m_PrinterMes.ReadObjectsFromXml("User\\Label\\qr.lab");
	//m_PrinterMes.ReadBmp("D:\\1.bmp");
	//Create2Dcode(8,"1");

}

FileEditChild::~FileEditChild()
{
}

void FileEditChild::Create2Dcode(int nType,QString strContent)
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;
	int longth;
	int derta;
	derta=1;
	longth=0;
	error_number = 0;
	QString angle1=ui.degreeBarCodeShowLab->text();
	int angle2=angle1.toInt();
	rotate_angle = angle2;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = nType;
//	if(nType == 20 || nType == 8)
//		my_symbol->height = 12;	 

	my_symbol->scale =0.5;
	batch_mode = 0;
	mirror_mode = 0;

	//int show_hrt;            //设置为1 显示文本在条码图片下面 设置为0 则不显示
	if (ui.showNumCheckBox->isChecked())
	{
		my_symbol->show_hrt=1;
	} 

	else  my_symbol->show_hrt=0;


	/* 
	char * QRTEXT = W2A(str.GetBuffer(0));	
	std::string strTmp = ASCToUTF8(QRTEXT);*/
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
	longth = my_symbol->bitmap_height;
	//longth = my_symbol->width;
	derta = longth-100;     //将21改为zoomShowBarCodeLab中的值
	//my_symbol->scale =proportion ;
	//error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);

	generated = 1;
  
	int xPos=0;
	int yPos=0;
	for(int i=0;i<m_PrinterMes.OBJ_Vec.size();i++)
	{
		if (m_PrinterMes.OBJ_Vec.at(i).booFocus)
		{
			m_PrinterMes.OBJ_Vec.at(i).booFocus=false;
			yPos = m_PrinterMes.OBJ_Vec.at(i).intLineStart;
			xPos = m_PrinterMes.OBJ_Vec.at(i).intRowSize+m_PrinterMes.OBJ_Vec.at(i).intRowStart;
		}
	}

	OBJ_Control bmpObj;
	bmpObj.intLineStart=yPos;
	bmpObj.intRowStart=xPos;
	bmpObj.strType1="text";
	bmpObj.strType2="qrcode";

//	bmpObj.intQRVersion=VersionBox.GetCurSel()+1;
//	bmpObj.intQRErrLevel=ErrLevelBox.GetCurSel();
//	bmpObj.intQREncodingMode=EncodingModeBox.GetCurSel();
//	bmpObj.boQRBig = true;	 
//	int version = bmpObj.intQRVersion;//设置版本号，这里设为2，对应尺寸：25 * 25
//	int casesensitive = bmpObj.boQRBig;//是否区分大小写，true/false

	bmpObj.intLineSize=my_symbol->bitmap_height-derta;
	bmpObj.intRowSize=my_symbol->bitmap_width;

	//以下先写死
	bmpObj.intSW=1;
	bmpObj.intSS=1;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;
	i = derta*my_symbol->bitmap_width*3;
	int r, g, b;

	for (int row = derta; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
		//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
				bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
		//		bmpObj.boDotBmp[col][row-proportion] = false;
		  		bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	bmpObj.strText = strContent.toStdString();
	bmpObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(bmpObj); 
}

void FileEditChild::CreateQrcode(int nType,QString strContent)
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;

	error_number = 0;
	QString angle1=ui.degreeQRShowLab->text();
	int angle2=angle1.toInt();
	rotate_angle = angle2;
	//rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = nType;
	my_symbol->scale =1;
	batch_mode = 0;
	mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
	/*float barlongth;
	barlongth=my_symbol->bitmap_height;
	float barwidth;
	barwidth=my_symbol->bitmap_width;
	float p;
	p=25/barlongth;
	my_symbol->scale =1;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
*/
	generated = 1;

	int xPos=0;
	int yPos=0;
	for(int i=0;i<m_PrinterMes.OBJ_Vec.size();i++)
	{
		if (m_PrinterMes.OBJ_Vec.at(i).booFocus)
		{
			m_PrinterMes.OBJ_Vec.at(i).booFocus=false;
			yPos = m_PrinterMes.OBJ_Vec.at(i).intLineStart;
			xPos = m_PrinterMes.OBJ_Vec.at(i).intRowSize+m_PrinterMes.OBJ_Vec.at(i).intRowStart;
		}
	}

	OBJ_Control bmpObj;
	bmpObj.intLineStart=yPos;
	bmpObj.intRowStart=xPos;
	bmpObj.strType1="text";
	bmpObj.strType2="qrcode";
	bmpObj.intLineSize=my_symbol->bitmap_height;
	bmpObj.intRowSize=my_symbol->bitmap_width;

	//以下先写死
	bmpObj.intSW=1;
	bmpObj.intSS=1;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;
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
				//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
				bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				//		bmpObj.boDotBmp[col][row-proportion] = false;
				bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	bmpObj.strText = strContent.toStdString();
	bmpObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(bmpObj); 

}

void FileEditChild::CreateDMcode(int nType,QString strContent)
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;

	error_number = 0;
	QString angle1=ui.degreeDMShowLab->text();
	int angle2=angle1.toInt();
	rotate_angle = angle2;

	//rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = nType;
	my_symbol->scale =0.5;
	batch_mode = 0;
	mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
	/*float barlongth;
	barlongth=my_symbol->bitmap_height;
	float barwidth;
	barwidth=my_symbol->bitmap_width;
	float p;
	p=25/barlongth;
	my_symbol->scale =1;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
	*/
	generated = 1;

	int xPos=0;
	int yPos=0;
	for(int i=0;i<m_PrinterMes.OBJ_Vec.size();i++)
	{
		if (m_PrinterMes.OBJ_Vec.at(i).booFocus)
		{
			m_PrinterMes.OBJ_Vec.at(i).booFocus=false;
			yPos = m_PrinterMes.OBJ_Vec.at(i).intLineStart;
			xPos = m_PrinterMes.OBJ_Vec.at(i).intRowSize+m_PrinterMes.OBJ_Vec.at(i).intRowStart;
		}
	}

	OBJ_Control bmpObj;
	bmpObj.intLineStart=yPos;
	bmpObj.intRowStart=xPos;
	bmpObj.strType1="text";
	bmpObj.strType2="qrcode";
	bmpObj.intLineSize=my_symbol->bitmap_height;
	bmpObj.intRowSize=my_symbol->bitmap_width;

	//以下先写死
	bmpObj.intSW=1;
	bmpObj.intSS=1;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;
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
				//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
				bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				//		bmpObj.boDotBmp[col][row-proportion] = false;
				bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	bmpObj.strText = strContent.toStdString();
	bmpObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(bmpObj); 

}
void FileEditChild::ShowText(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent,
	int txtRowSize, int txtLineSize, int txtLineStart, int txtRowStart, int txtSS, int txtSW)
{
	OBJ_Control textObj;
	textObj.intLineStart = 0;
	textObj.intRowStart = 0;
	textObj.strType1 = "text";
	textObj.strType2 = "text";
	textObj.strText = txtContent;
	int txtLength = txtContent.length();

	map<string,int> fntMap2;
	fntMap2.clear();
	fntMap2.insert(make_pair("5x5",0));
	fntMap2.insert(make_pair("7x5",1));
	fntMap2.insert(make_pair("12x12",2));
	fntMap2.insert(make_pair("16x12",3));
	int RowLength;
	int LineLength;

	switch(fntMap2[txtFont])
	{
		case 0:
			LineLength = 5;
			RowLength = 6;
		case 1:
			LineLength = 7;
			RowLength = 6;
		case 2:
			LineLength = 12;
			RowLength = 13;
		case 3:
			LineLength = 16;
			RowLength = 13;
	}

	textObj.intLineSize = LineLength/2;
	textObj.intRowSize = RowLength/2 * txtLength;
	textObj.intSW = txtSW;
	textObj.intSS = txtSS;
	textObj.booNEG = txtNEG;
	textObj.booBWDx = txtBWDx;
	textObj.booBWDy = txtBWDy;
	
	//ClassMessage textClassMessage;
	//m_PrinterMes.getdot(txtFont, txtBWDy, txtBWDx, txtNEG, txtContent, txtRowSize, txtLineSize, txtLineStart, txtRowStart, txtSS, txtSW);
	
	textObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(textObj); 
}

//QString txtQString = ui.QRCodeLineEdit->text();
//string txtString = txtQString.toStdString();
//ShowText("7x5",false,false,false,txtString,20,20,0,0,0,1);

 void FileEditChild::paintDot()
{
	QPainter painter(ui.editPreviewText);
	m_PrinterMes.DrawDot(&painter);
}

bool FileEditChild::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui.editPreviewText && event->type() == QEvent::Paint)
	{
		paintDot();
	}
	return QWidget::eventFilter(watched,event);
}
 
void FileEditChild::variableTextBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->variableWidgetCall();
}

void FileEditChild::customTimeBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->timeCustomCall();
}

void FileEditChild::selBmpBut_clicked()
{

}

void FileEditChild::delBut_clicked()
{

}

void FileEditChild::wordLineEdit_clicked()
{
	ui.keyboardStackWid->setWindowFlags(ui.keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui.keyboardStackWid->raise();
	ui.keyboardStackWid->setCurrentWidget(keyboardWidget);
}

void FileEditChild::languageWidgetCall()
{
	ui.keyboardStackWid->setWindowFlags(ui.keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui.keyboardStackWid->raise();
	ui.keyboardStackWid->setCurrentWidget(languageWidget);
}

void FileEditChild::returnKB()
{
	ui.keyboardStackWid->setWindowFlags(ui.keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui.keyboardStackWid->raise();
	ui.keyboardStackWid->setCurrentWidget(keyboardWidget);
}

void FileEditChild::barCodeLineEdit_clicked()
{
	ui.keyboardStackWid->setWindowFlags(ui.keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui.keyboardStackWid->raise();
	ui.keyboardStackWid->setCurrentWidget(keyboardWidget);

}

void FileEditChild::QRCodeLineEdit_clicked()
{
	ui.keyboardStackWid->setWindowFlags(ui.keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui.keyboardStackWid->raise();
	ui.keyboardStackWid->setCurrentWidget(keyboardWidget);

}

void FileEditChild::DMCodeLineEdit_clicked()
{
	ui.keyboardStackWid->setWindowFlags(ui.keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui.keyboardStackWid->raise();
	ui.keyboardStackWid->setCurrentWidget(keyboardWidget);

}

void FileEditChild::newTextBut_clicked()
{

}

void FileEditChild::newBarCodeBut_clicked()
{
	int t;
	QString str;
	str = ui.barCodeLineEdit->text();
	if (ui.typeBarCodeComBox->currentIndex()==0)
	{
		t=13;
	}
	if (ui.typeBarCodeComBox->currentIndex()==1)
	{
		t=8;
	}
	if (ui.typeBarCodeComBox->currentIndex()==2)
	{
		t=25;
	}
	if (ui.typeBarCodeComBox->currentIndex()==3)
	{
		t=20;
	}
	if (ui.typeBarCodeComBox->currentIndex()==4)
	{
		t=34;
	}
	if (ui.typeBarCodeComBox->currentIndex()==5)
	{
		t=37;
	}
	if (ui.typeBarCodeComBox->currentIndex()==6)
	{
		t=89;
	}
	if (ui.typeBarCodeComBox->currentIndex()==7)
	{
		t=55;
	}


	Create2Dcode(t,str);
}

void FileEditChild::newQRBut_clicked()
{
	QString str;
	str = ui.QRCodeLineEdit->text();
	CreateQrcode(58,str);
}

void FileEditChild::newDMBut_clicked()
{
	QString str;
	str = ui.DMCodeLineEdit->text();
	CreateDMcode(71,str);
}

void FileEditChild::moveUpBut_clicked()
{
	
}

void FileEditChild::moveDownBut_clicked()
{

}

void FileEditChild::moveLeftBut_clicked()
{

}

void FileEditChild::moveRightBut_clicked()
{

}

void FileEditChild::hideKB()
{
	ui.keyboardStackWid->setWindowFlags(ui.keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.keyboardStackWid->close();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui.keyboardStackWid->raise();

}

void FileEditChild::deleteChar()
{
	ui.wordLineEdit->backspace();
	str1 = ui.wordLineEdit->text();
}

void FileEditChild::getValA(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.A_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValB(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.B_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValC(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.C_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValD(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.D_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValE(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.E_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValF(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.F_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValG(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.G_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValH(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.H_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValI(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.I_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValJ(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.J_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValK(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.K_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValL(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.L_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValM(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.M_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValN(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.N_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValO(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.O_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValP(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.P_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValQ(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.Q_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValR(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.R_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValS(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.S_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValT(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.T_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValU(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.U_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValV(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.V_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValW(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.W_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValX(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.X_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValY(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.Y_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValZ(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.Z_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValnum1(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.num1_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValnum2(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.num2_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValnum3(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.num3_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValnum4(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.num4_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValnum5(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.num5_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValnum6(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.num6_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValnum7(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.num7_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValnum8(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.num8_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValnum9(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.num9_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValnum0(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.num0_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValspace(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.space_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValcomma(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.comma_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::getValperiod(QString str)
{
	ui.wordLineEdit->cursorPosition();
	str1 = key.period_KBBut_sendData();
	ui.wordLineEdit->insert(str1);
}

void FileEditChild::showNumCheckBox_clicked()
{
	
}

void FileEditChild::degreeBarCodeAddBut_clicked()
{
	
	if (degreenum<270)
	{
		degreenum=degreenum+90;
	} 
	else
	{
		degreenum=0;
	}
	ui.degreeBarCodeShowLab->setText(QString::number(degreenum));
}

void FileEditChild::degreeBarCodeRedButt_clicked()
{

	if (degreenum>0)
	{
		degreenum=degreenum-90;
	} 
	else
	{
		degreenum=270;
	}
	ui.degreeBarCodeShowLab->setText(QString::number(degreenum));
}

void FileEditChild::zoomBarCodeAddBut_clicked()
{

}

void FileEditChild::heightBarCodeAddBut_clicked()
{
	ui.heightBarCodeShowQRLab->setText(QString::number(25));
}

void FileEditChild::heightBarCodeRedButt_clicked()
{
	ui.heightBarCodeShowQRLab->setText(QString::number(21));
	ui.wordLineEdit->backspace();
	str1 = ui.wordLineEdit->text();
}

void FileEditChild::degreeQRAddBut_clicked()
{

	if (degreenum<270)
	{
		degreenum=degreenum+90;
	} 
	else
	{
		degreenum=0;
	}
	ui.degreeQRShowLab->setText(QString::number(degreenum));
}

void FileEditChild::degreeQRRedButt_clicked()
{

	if (degreenum>0)
	{
		degreenum=degreenum-90;
	} 
	else
	{
		degreenum=270;
	}
	ui.degreeQRShowLab->setText(QString::number(degreenum));
}

void FileEditChild::degreeDMAddBut_clicked()
{

	if (degreenum<270)
	{
		degreenum=degreenum+90;
	} 
	else
	{
		degreenum=0;
	}
	ui.degreeDMShowLab->setText(QString::number(degreenum));
}

void FileEditChild::degreeDMRedButt_clicked()
{

	if (degreenum>0)
	{
		degreenum=degreenum-90;
	} 
	else
	{
		degreenum=270;
	}
	ui.degreeDMShowLab->setText(QString::number(degreenum));
}
