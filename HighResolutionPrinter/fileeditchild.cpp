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
	connect(ui.editBut,SIGNAL(clicked()),this,SLOT(editBut_clicked()));
	connect(ui.selBmpBut,SIGNAL(clicked()),this,SLOT(selBmpBut_clicked()));
	connect(ui.delBut,SIGNAL(clicked()),this,SLOT(delBut_clicked()));
	connect(ui.wordLineEdit,SIGNAL(clicked()),this,SLOT(wordLineEdit_clicked()));
	connect(ui.barCodeLineEdit,SIGNAL(clicked()),this,SLOT(barCodeLineEdit_clicked()));
	connect(ui.QRCodeLineEdit,SIGNAL(clicked()),this,SLOT(QRCodeLineEdit_clicked()));
	connect(ui.DMCodeLineEdit,SIGNAL(clicked()),this,SLOT(DMCodeLineEdit_clicked()));

	keyboardWidget = new keyboard(this);
	ui.keyboardStackWid->addWidget(keyboardWidget);
		
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
 //	m_PrinterMes.ReadObjectsFromXml("User\\Label\\qr.lab");
	//m_PrinterMes.ReadBmp("D:\\1.bmp");
	Create2Dcode(58,"hmj");

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

	error_number = 0;
	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = nType;
	if(nType == 20 || nType == 8)
		my_symbol->height = 12;	 

	my_symbol->scale = 0.5;
	batch_mode = 0;
	mirror_mode = 0;

	/* 
	char * QRTEXT = W2A(str.GetBuffer(0));	
	std::string strTmp = ASCToUTF8(QRTEXT);*/
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
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

	bmpObj.intLineSize=my_symbol->width;
	bmpObj.intRowSize=my_symbol->width;

	//以下先写死
	bmpObj.intSW=1;
	bmpObj.intSS=0;
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
				bmpObj.boDotBmp[row][col] = true;
			}
			else
			{
				bmpObj.boDotBmp[row][col] = false;
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
	m_PrinterMes.getdot(txtFont, txtBWDy, txtBWDx, txtNEG, txtContent, 
		txtRowSize, txtLineSize, txtLineStart, txtRowStart, txtSS, txtSW);
	
	textObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(textObj); 
}

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

void FileEditChild::editBut_clicked()
{
	ui.keyboardStackWid->setWindowFlags(ui.keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.keyboardStackWid->show();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui.keyboardStackWid->raise();
	ui.keyboardStackWid->setCurrentWidget(keyboardWidget);
	QString txtQString = ui.QRCodeLineEdit->text();
	string txtString = txtQString.toStdString();
	ShowText("7x5",false,false,false,txtString,20,20,0,0,0,1);
}

void FileEditChild::delBut_clicked()
{
	ui.keyboardStackWid->setWindowFlags(ui.keyboardStackWid->windowFlags() | Qt::WindowStaysOnTopHint);
	ui.keyboardStackWid->hide();
	//仅仅显示在最前1次(点击主窗体时主窗体回到最前)
	ui.keyboardStackWid->raise();

}

void FileEditChild::wordLineEdit_clicked()
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

//void FileEditChild::test_clicked()
//{
//	QString str = key.returnText();
//	ui.wordLineEdit->setText(str);
//}