#include "ui_fileeditchild.h"
#include "lineedit_click.h"
#include "fileeditchild.h"
#include "filemanagechild.h"
#include "filemanageform.h"
#include <QTableWidget>
#include <QMouseEvent>
#include "backend\zint.h"
#include <QFileDialog>
#include "keyboard.h"
#include "language.h"

FileEditChild::FileEditChild(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::FileEditChild)
{
	ui->setupUi(this);

	connect(ui->variableTextBut,SIGNAL(clicked()),this,SLOT(variableTextBut_clicked()));
	connect(ui->customTimeBut,SIGNAL(clicked()),this,SLOT(customTimeBut_clicked()));
	connect(ui->selBmpBut,SIGNAL(clicked()),this,SLOT(selBmpBut_clicked()));
	connect(ui->delBut,SIGNAL(clicked()),this,SLOT(delBut_clicked()));
	connect(ui->wordLineEdit,SIGNAL(clicked()),this,SLOT(wordLineEdit_clicked()));
	connect(ui->barCodeLineEdit,SIGNAL(clicked()),this,SLOT(barCodeLineEdit_clicked()));
	connect(ui->QRCodeLineEdit,SIGNAL(clicked()),this,SLOT(QRCodeLineEdit_clicked()));
	connect(ui->DMCodeLineEdit,SIGNAL(clicked()),this,SLOT(DMCodeLineEdit_clicked()));
	connect(ui->newTextBut,SIGNAL(clicked()),this,SLOT(newTextBut_clicked()));
	connect(ui->newBarCodeBut,SIGNAL(clicked()),this,SLOT(newBarCodeBut_clicked()));
	connect(ui->newQRBut,SIGNAL(clicked()),this,SLOT(newQRBut_clicked()));
	connect(ui->newDMBut,SIGNAL(clicked()),this,SLOT(newDMBut_clicked()));

	connect(ui->moveUpBut,SIGNAL(clicked()),this,SLOT(moveUpBut_clicked()));
	connect(ui->moveDownBut,SIGNAL(clicked()),this,SLOT(moveDownBut_clicked()));
	connect(ui->moveLeftBut,SIGNAL(clicked()),this,SLOT(moveLeftBut_clicked()));
	connect(ui->moveRightBut,SIGNAL(clicked()),this,SLOT(moveRightBut_clicked()));
	connect(ui->showNumCheckBox,SIGNAL(stateChanged()),this,SLOT(showNumCheckBox_clicked()));
	connect(ui->degreeBarCodeAddBut,SIGNAL(clicked()),this,SLOT(degreeBarCodeAddBut_clicked()));
	connect(ui->degreeBarCodeRedBut,SIGNAL(clicked()),this,SLOT(degreeBarCodeRedButt_clicked()));
	connect(ui->zoomBarCodeAddBut,SIGNAL(clicked()),this,SLOT(zoomBarCodeAddBut_clicked()));
	connect(ui->heightBarCodeAddBut,SIGNAL(clicked()),this,SLOT(heightBarCodeAddBut_clicked()));
	connect(ui->heightBarCodeRedBut,SIGNAL(clicked()),this,SLOT(heightBarCodeRedButt_clicked()));
	
	connect(ui->degreeQRAddBut,SIGNAL(clicked()),this,SLOT(degreeQRAddBut_clicked()));
	connect(ui->degreeQRRedBut,SIGNAL(clicked()),this,SLOT(degreeQRRedButt_clicked()));
	connect(ui->degreeDMAddBut,SIGNAL(clicked()),this,SLOT(degreeDMAddBut_clicked()));
	connect(ui->degreeDMRedBut,SIGNAL(clicked()),this,SLOT(degreeDMRedButt_clicked()));
	connect(ui->zoomBarCodeRedBut,SIGNAL(clicked()),this,SLOT(zoomBarCodeRedBut_clicked()));
	connect(ui->zoomQRAddBut,SIGNAL(clicked()),this,SLOT(zoomQRAddBut_clicked()));
	connect(ui->zoomQRRedBut,SIGNAL(clicked()),this,SLOT(zoomQRRedBut_clicked()));
	connect(ui->zoomDMAddBut,SIGNAL(clicked()),this,SLOT(zoomDMAddBut_clicked()));
	connect(ui->zoomDMRedBut,SIGNAL(clicked()),this,SLOT(zoomDMRedBut_clicked()));
	connect(ui->degreeQRAddBut,SIGNAL(clicked()),this,SLOT(degreeQRAddBut_clicked()));
	connect(ui->degreeQRRedBut,SIGNAL(clicked()),this,SLOT(degreeQRRedButt_clicked()));
	connect(ui->degreeDMAddBut,SIGNAL(clicked()),this,SLOT(degreeDMAddBut_clicked()));
	connect(ui->degreeDMRedBut,SIGNAL(clicked()),this,SLOT(degreeDMRedButt_clicked()));

	connect(ui->saveasBut,SIGNAL(clicked()),this,SLOT(saveasBut_clicked()));
	connect(ui->saveBut,SIGNAL(clicked()),this,SLOT(saveBut_clicked()));

    ui->wordLineEdit->setFocus();


	keyboardWidget = new keyboard(this);
	languageWidget = new language();
	ui->keyboardStackWid->addWidget(keyboardWidget);
	ui->keyboardStackWid->addWidget(languageWidget);
	
	ui->editPreviewText->installEventFilter(this);
	ui->editPreviewText->viewport()->installEventFilter(this);

	ui->typeTab->setStyleSheet("QTabWidget:pane{ \
							  boder: -2px solid white;top: -2px;background-color:rgb(0, 0, 230);}\
							  QTabBar::tab{font:'楷体' 16pt;color: white;height:50px; width:114px; background-color:rgb(0, 0, 230); margin-right: 2px; margin-bottom:-2px;}\
							  QTabBar::tab:selected{border:1px solid white;border-bottom-color: none;}\
							  QTabBar::tab:!selected{border-bottom: 3px solid white;}\
							  ");
	ui->showNumCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									  QCheckBox{color:rgb(255, 255, 255);}\
									  ");
	ui->reverseCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									  QCheckBox{color:rgb(255, 255, 255);}\
									  ");
	ui->natureNumCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
										QCheckBox{color:rgb(255, 255, 255);}\
									   ");
	ui->reverseBmpCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
		                                  QCheckBox{color:rgb(255, 255, 255);}\
										 ");
	ui->moveUpBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveup.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveup.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->moveDownBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/movedown.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/movedown.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->moveLeftBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveleft.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveleft.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->moveRightBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveright.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveright.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->degreeTextShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->internalShowTextLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->degreeTimeShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->currentValShowTimeLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->degreeSerialShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->currentValShowSerialLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->degreeBmpShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->heightBmpShowBmpLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->widthShowBmpLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->degreeBarCodeShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->zoomShowBarCodeLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->heightBarCodeShowQRLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
    ui->degreeQRShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->zoomShowQRLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->degreeDMShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->zoomShowDMLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 


	ui->typeBarCodeComBox->addItem(QStringLiteral("EANX"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("CODE39"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("CODE93"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("CODE128"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("UPCA"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("UPCE"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("ITF14"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("PDF417"));
	ui->typeBarCodeComBox->setCurrentIndex(3);

	ui->preciseQRComBox->addItem(QStringLiteral("低"));
	ui->preciseQRComBox->addItem(QStringLiteral("中"));
	ui->preciseQRComBox->addItem(QStringLiteral("高"));
	ui->preciseQRComBox->addItem(QStringLiteral("精准"));
	ui->typeBarCodeComBox->setCurrentIndex(1);

	ui->sideLenQRComBox->addItem(QStringLiteral("21 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("25 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("29 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("33 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("37 px"));
	ui->typeBarCodeComBox->setCurrentIndex(1);

	degreenum=0;
	degreenumQr=0;
	degreenumDM=0;
	Zoomfactor=1;
	ZoomfactorQr=1;
	ZoomfactorDM=1;

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
	QString angle1=ui->degreeBarCodeShowLab->text();
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
	if (ui->showNumCheckBox->isChecked())
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
	QString zoomvalue=ui->zoomShowBarCodeLab->text();
	int zoomvalue1=zoomvalue.toInt();
	derta = longth-zoomvalue1;     //将21改为zoomShowBarCodeLab中的值
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
	QString angle1=ui->degreeQRShowLab->text();
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
	QString angle1=ui->degreeDMShowLab->text();
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

void FileEditChild::PushBackTextOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent,
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

void FileEditChild::ShowText()
{
	QString txtQString = ui->wordLineEdit->text();
	string txtString = txtQString.toStdString();
	PushBackTextOBJ("7x5",false,false,false,txtString,20,20,0,0,0,1);
}

void FileEditChild::LoadLocalFile()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(parentWidget()); 
 	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
	m_PrinterMes.ReadObjectsFromXml(pFilemanageForm->FormFileManageChild->GetCurXmlFile());
}

void FileEditChild::paintDot()
{
	QPainter painter(ui->editPreviewText);
	m_PrinterMes.DrawDot(&painter);
}

bool FileEditChild::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui->editPreviewText && event->type() == QEvent::Paint)
	{
		paintDot();
		QWidget *pQWidget(this);
		pQWidget->update();
	}
	else if (watched == ui->editPreviewText->viewport())
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			//qDebug() << __FILE__<<__LINE__<< QString::number(event->type());
			QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
			mousePressEvent(mouseEvent);
			QWidget *pQWidget(this);
			pQWidget->update();
		}
	}
	return QWidget::eventFilter(watched, event);
}

void FileEditChild::mousePressEvent(QMouseEvent *event)
{
	//QPoint p_Global = event->globalPos();
	QPoint p_Relative = event->pos();
	m_PrinterMes.JudgeIfOBJ_Selected(p_Relative);
	paintDot();
}

//鼠标点击一次选中，再点击一次取消选中，可以多选
//获取选中的OBJ对象在OBJ_Vec[]中的位置
void FileEditChild::GetSelObjNum()
{
	//调用int ClassMessage::JudgeIfOBJ_Selected(int MouseXPos, int MouseYPos)
	//m_PrinterMes.JudgeIfOBJ_Selected(int MouseXPos, int MouseYPos);
}

//当用户点击“另存为”按钮时
void FileEditChild::saveasBut_clicked()
{
	/*
	1.调用bool ClassMessage::JudgeXmlNameRepeat(char* strFileName)
	  判断新建xml文件的默认名称:"NewLabel_1"是否重复，若重复，则strFileName = "NewLabel_2".......
	  如果是读取老文件，则默认为老文件名加_1，写一个专门用来配置文件名称的函数，用while循环来实现
	2.调用ClassMessage::SaveObjectsToXml(char* strFileName)，将OBJ对象保存到本地XML中
	3.调用FilemanageForm::FileManageChildWidgetCall()，打开"管理文件"窗口
	*/
}

//当用户点击“保存”按钮时
void FileEditChild::saveBut_clicked()
{
	/*
	  如何判断？？？
	1.判断当前编辑的文件是否是本地已有文件：如果否，则2；如果是，则3
	2.调用FileEditChild::saveasBut_clicked()，与“另存为”的功能相同
	3.调用ClassMessage::SaveObjectsToXml(char* strFileName)，将OBJ对象保存到本地XML中(默认为覆盖）
	4.弹出<保存成功>提示框，持续1秒
	*/
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

void FileEditChild::ReadBmp(char* strFileName)
{
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	QImage pImage;
	pImage = pLoad.toImage();

	OBJ_Control bmpObj;
	bmpObj.intLineStart=0;
	bmpObj.intRowStart=0;
	bmpObj.strType1="text";
	bmpObj.strType2="logo";
	bmpObj.intLineSize=pImage.width();
	bmpObj.intRowSize=pImage.height();
	bmpObj.intSW=1;
	bmpObj.intSS=0;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;

	for(int y = 0; y<pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x<pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
			if(average < 100)
				bmpObj.boDotBmp[bmpObj.intLineSize-x-1][y] = true;
			else
				bmpObj.boDotBmp[bmpObj.intLineSize-x-1][y] = false;
		}  

	}  
	bmpObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(bmpObj); 
}

void FileEditChild::selBmpBut_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
	aaaa=fileName;
	QImage image,result;
	image.load(fileName); 
	result = image.scaled(ui->bmpPreviewLab->width(), ui->bmpPreviewLab->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//放缩图片，以固定大小显示
	ui->bmpPreviewLab->setPixmap(QPixmap::fromImage(result));//在Label控件上显示图片
}

void FileEditChild::delBut_clicked()
{
	vector<OBJ_Control>::iterator itr = m_PrinterMes.OBJ_Vec.begin();
	while (itr != m_PrinterMes.OBJ_Vec.end())
	{
		if (itr->booFocus)
			{
				itr = m_PrinterMes.OBJ_Vec.erase(itr);
				paintDot();
				continue;
			}
	}
}

void FileEditChild::wordLineEdit_clicked()
{
	//ui->keyboardStackWid->setWindowFlags(ui->keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	//ui->keyboardStackWid->show();
	////仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	//ui->keyboardStackWid->raise();
	//ui->keyboardStackWid->setCurrentWidget(keyboardWidget);

	ui->keyboardStackWid->setWindowFlags(ui->keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	keyboardWidget->m_pInputEdit = ui->wordLineEdit;
	ui->keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui->keyboardStackWid->raise();
	ui->keyboardStackWid->setCurrentWidget(keyboardWidget);
}

void FileEditChild::barCodeLineEdit_clicked()
{
	ui->keyboardStackWid->setWindowFlags(ui->keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	keyboardWidget->m_pInputEdit = ui->barCodeLineEdit;
	ui->keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui->keyboardStackWid->raise();
	ui->keyboardStackWid->setCurrentWidget(keyboardWidget);
}

void FileEditChild::QRCodeLineEdit_clicked()
{
	ui->keyboardStackWid->setWindowFlags(ui->keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	keyboardWidget->m_pInputEdit = ui->QRCodeLineEdit;
	ui->keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui->keyboardStackWid->raise();
	ui->keyboardStackWid->setCurrentWidget(keyboardWidget);
}

void FileEditChild::DMCodeLineEdit_clicked()
{
	ui->keyboardStackWid->setWindowFlags(ui->keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	keyboardWidget->m_pInputEdit = ui->DMCodeLineEdit;
	ui->keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui->keyboardStackWid->raise();
	ui->keyboardStackWid->setCurrentWidget(keyboardWidget);
}

void FileEditChild::languageWidgetCall()
{
	ui->keyboardStackWid->setWindowFlags(ui->keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui->keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui->keyboardStackWid->raise();
	ui->keyboardStackWid->setCurrentWidget(languageWidget);
}

void FileEditChild::returnKB()
{
	ui->keyboardStackWid->setWindowFlags(ui->keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui->keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui->keyboardStackWid->raise();
	ui->keyboardStackWid->setCurrentWidget(keyboardWidget);
}

void FileEditChild::newTextBut_clicked()
{

}

void FileEditChild::newBarCodeBut_clicked()
{
	int t;
	QString str;
	str = ui->barCodeLineEdit->text();
	if (ui->typeBarCodeComBox->currentIndex()==0)
	{
		t=13;
	}
	if (ui->typeBarCodeComBox->currentIndex()==1)
	{
		t=8;
	}
	if (ui->typeBarCodeComBox->currentIndex()==2)
	{
		t=25;
	}
	if (ui->typeBarCodeComBox->currentIndex()==3)
	{
		t=20;
	}
	if (ui->typeBarCodeComBox->currentIndex()==4)
	{
		t=34;
	}
	if (ui->typeBarCodeComBox->currentIndex()==5)
	{
		t=37;
	}
	if (ui->typeBarCodeComBox->currentIndex()==6)
	{
		t=89;
	}
	if (ui->typeBarCodeComBox->currentIndex()==7)
	{
		t=55;
	}


	Create2Dcode(t,str);
}

void FileEditChild::newQRBut_clicked()
{
	QString str;
	str = ui->QRCodeLineEdit->text();
	CreateQrcode(58,str);
}

void FileEditChild::newDMBut_clicked()
{
	QString str;
	str = ui->DMCodeLineEdit->text();
	CreateDMcode(71,str);
}

void FileEditChild::newBmpBut_clicked()
{
	 
	char *pic;
	QByteArray ba=aaaa.toLatin1();
	pic=ba.data();
	ReadBmp(pic);

}

void FileEditChild::moveUpBut_clicked()
{
	for (int i=0; i<m_PrinterMes.OBJ_Vec.size(); i++)
	{
		if (m_PrinterMes.OBJ_Vec[i].booFocus)
		{
			int EndPos = m_PrinterMes.OBJ_Vec[i].intLineStart + m_PrinterMes.OBJ_Vec[i].intLineSize ;
			if( EndPos < 241 )
			{
				m_PrinterMes.OBJ_Vec[i].intLineStart += 1;
				paintDot();
			}
		}
	}
}

void FileEditChild::moveDownBut_clicked()
{
	for (int i=0; i<m_PrinterMes.OBJ_Vec.size(); i++)
	{
		if (m_PrinterMes.OBJ_Vec[i].booFocus)
		{
			if( m_PrinterMes.OBJ_Vec[i].intLineStart > 0 )
			{
				m_PrinterMes.OBJ_Vec[i].intLineStart -= 1;
				paintDot();
			}
		}
	}
}

void FileEditChild::moveLeftBut_clicked()
{
	for (int i=0; i<m_PrinterMes.OBJ_Vec.size(); i++)
	{
		if (m_PrinterMes.OBJ_Vec[i].booFocus)
		{
			if( m_PrinterMes.OBJ_Vec[i].intRowStart > 0 )
			{
				m_PrinterMes.OBJ_Vec[i].intRowStart -= 1;
				paintDot();
			}
		}
	}
}

void FileEditChild::moveRightBut_clicked()
{
	for (int i=0; i<m_PrinterMes.OBJ_Vec.size(); i++)
	{
		if (m_PrinterMes.OBJ_Vec[i].booFocus)
		{
			int EndPos = m_PrinterMes.OBJ_Vec[i].intRowStart + m_PrinterMes.OBJ_Vec[i].intRowSize ;
			if( EndPos < 1041 )
			{
				m_PrinterMes.OBJ_Vec[i].intRowStart += 1;
				paintDot();
			}
		}
	}
}

void FileEditChild::hideKB()
{
	ui->keyboardStackWid->setWindowFlags(ui->keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui->keyboardStackWid->close();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui->keyboardStackWid->raise();

}

void FileEditChild::deleteChar()
{
	ui->wordLineEdit->backspace();
	str1 = ui->wordLineEdit->text();
}

//void FileEditChild::getValA(QString str)
//{
//	//ui->wordLineEdit->cursorPosition();
//	//str1 = key->A_KBBut_sendData();
//	//ui->wordLineEdit->insert(str1);
//}

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
	ui->degreeBarCodeShowLab->setText(QString::number(degreenum));
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
	ui->degreeBarCodeShowLab->setText(QString::number(degreenum));
}

void FileEditChild::heightBarCodeAddBut_clicked()
{
	ui->heightBarCodeShowQRLab->setText(QString::number(25));
}

void FileEditChild::heightBarCodeRedButt_clicked()
{
	ui->heightBarCodeShowQRLab->setText(QString::number(21));
	ui->wordLineEdit->backspace();
	str1 = ui->wordLineEdit->text();
}

void FileEditChild::degreeQRAddBut_clicked()
{

	if (degreenumQr<270)
	{
		degreenumQr=degreenumQr+90;
	} 
	else
	{
		degreenumQr=0;
	}
	ui->degreeQRShowLab->setText(QString::number(degreenumQr));
}

void FileEditChild::degreeQRRedButt_clicked()
{

	if (degreenumQr>0)
	{
		degreenumQr=degreenumQr-90;
	} 
	else
	{
		degreenumQr=270;
	}
	ui->degreeQRShowLab->setText(QString::number(degreenumQr));
}

void FileEditChild::degreeDMAddBut_clicked()
{

	if (degreenumDM<270)
	{
		degreenumDM=degreenumDM+90;
	} 
	else
	{
		degreenumDM=0;
	}
	ui->degreeDMShowLab->setText(QString::number(degreenumDM));
}

void FileEditChild::degreeDMRedButt_clicked()
{

	if (degreenumDM>0)
	{
		degreenumDM=degreenumDM-90;
	} 
	else
	{
		degreenumDM=270;
	}
	ui->degreeDMShowLab->setText(QString::number(degreenumDM));
}

void FileEditChild::zoomBarCodeAddBut_clicked()
{

	if (Zoomfactor>=0.5)
	{
		Zoomfactor=Zoomfactor+0.5;
	} 
	else
	{
		Zoomfactor=0.5;
	}
	ui->zoomShowBarCodeLab->setText(QString("%1").arg(Zoomfactor));
	//ui->zoomShowBarCodeLab->setText(QString::number(Zoomfactor,10,1));
}

void FileEditChild::zoomBarCodeRedBut_clicked()
{

	if (Zoomfactor>=1)
	{
		Zoomfactor=Zoomfactor-0.5;
	} 
	else
	{
		Zoomfactor=0.5;
	}
	ui->zoomShowBarCodeLab->setText(QString("%1").arg(Zoomfactor));
}

void FileEditChild::zoomQRAddBut_clicked()
{

	if (ZoomfactorQr>=0.5)
	{
		ZoomfactorQr=ZoomfactorQr+0.5;
	} 
	else
	{
		ZoomfactorQr=0.5;
	}
	ui->zoomShowQRLab->setText(QString("%1").arg(ZoomfactorQr));
	//ui->zoomShowBarCodeLab->setText(QString::number(Zoomfactor,10,1));
}

void FileEditChild::zoomQRRedBut_clicked()
{

	if (ZoomfactorQr>=1)
	{
		ZoomfactorQr=ZoomfactorQr-0.5;
	} 
	else
	{
		ZoomfactorQr=0.5;
	}
	ui->zoomShowQRLab->setText(QString("%1").arg(ZoomfactorQr));
}

void FileEditChild::zoomDMAddBut_clicked()
{

	if (ZoomfactorDM>=0.5)
	{
		ZoomfactorDM=ZoomfactorDM+0.5;
	} 
	else
	{
		ZoomfactorDM=0.5;
	}
	ui->zoomShowDMLab->setText(QString("%1").arg(ZoomfactorDM));
	//ui->zoomShowBarCodeLab->setText(QString::number(Zoomfactor,10,1));
}

void FileEditChild::zoomDMRedBut_clicked()
{

	if (ZoomfactorDM>=1)
	{
		ZoomfactorDM=ZoomfactorDM-0.5;
	} 
	else
	{
		ZoomfactorDM=0.5;
	}
	ui->zoomShowDMLab->setText(QString("%1").arg(ZoomfactorDM));
}

