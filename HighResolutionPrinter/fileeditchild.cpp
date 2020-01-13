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

	m_PrinterMes.ReadObjectsFromXml("User\\Label\\qr.lab");

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