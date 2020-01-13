#include "fileeditchild.h"
#include "filemanageform.h"
#include <QTableWidget>
#include "ClassMessage.h"

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
//	m_PrinterMes.ReadObjectsFromXml("User\\Label\\qr.lab");
//  ReadBmp("D:\\1.bmp");
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
			int average = (qRed(line[x]) + qGreen(line[x]) + qBlue(line[x]))/3;  
			if(average < 100)
				bmpObj.boDotBmp[bmpObj.intLineSize-x-1][y] = true;
			else
				bmpObj.boDotBmp[bmpObj.intLineSize-x-1][y] = false;
		}  

	}  
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

FileEditChild::~FileEditChild()
{

}

bool FileEditChild::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui.editPreviewText && event->type() == QEvent::Paint)
	{
		paintDot();
	}
	return QWidget::eventFilter(watched,event);
}

void FileEditChild::paintDot()
{
	QPainter painter(ui.editPreviewText);
	m_PrinterMes.DrawDot(&painter);
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

}
