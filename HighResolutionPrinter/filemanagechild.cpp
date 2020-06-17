#include "filemanagechild.h"
#include "ui_filemanagechild.h"
#include "QDir"
#include "QFileDialog"
#include "QTextStream"
#include "QFile"
#include "QFileInfo"
#include <QTextCodec>
#include <QDebug>
#include <QPushButton>
#include "mainwindow.h"
#include "filemanageform.h"
#include "fileeditchild.h"
#include "ui_fileeditchild.h"
#include "keyboard.h"
#include "ClassMessage.h"
#include "automessagebox.h"

FileManageChild::FileManageChild(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::FileManageChild)
{
	ui->setupUi(this);
	
	ui->filePrivewtextEdit->installEventFilter(this);

	connect(ui->localFileBut,SIGNAL(clicked()),this,SLOT(ShowLocalFilePath()));
	connect(ui->UdiskFileBut,SIGNAL(clicked()),this,SLOT(UdiskFileBut_clicked()));
	connect(ui->loadSeleFileBut, SIGNAL(clicked()),this,SLOT(loadSeleFileBut_clicked())); 
	connect(ui->editSeleFileBut,SIGNAL(clicked()),this,SLOT(editSeleFileBut_clicked()));
	connect(ui->filelistWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(SetButtonEnableOn()));
	connect(ui->filelistWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(PreviewLocalFile()));
	connect(ui->fileNmaeLineEdit,SIGNAL(clicked()),this,SLOT(fileNmaeLineEdit_click())); 
	connect(ui->OKFileNameBut,SIGNAL(clicked()),this,SLOT(OKFileNameBut_clicked()));
	connect(ui->delSeleFileBut,SIGNAL(clicked()),this,SLOT(delSeleFileBut_clicked()));
	connect(ui->copyFile2localBut,SIGNAL(clicked()),this,SLOT(copyFile2localBut_clicked()));
	connect(ui->filePreHorScrollBar,SIGNAL(valueChanged(int)),this,SLOT(ScrollBarChanged(int)));

	SetButtonEnableOff();
	boolSaveAsBtn_Clicked = false;
	m_pPrinterMes = new ClassMessage;
	ShowLocalFilePath(); 
	keyboardWidget = new keyboard(this);
	keyboardWidget->setVisible(false);

	ui->filePreHorScrollBar->setRange(0,100);
	ui->filePrivewtextEdit->setGeometry(240, 10, 3121, 241);
	
}

void FileManageChild::ScrollBarChanged(int value)
{
	double p = static_cast<double>(value)/static_cast<double>(ui->filePreHorScrollBar->maximum());
	ui->filePrivewtextEdit->move(-2080*p,10);
}

void FileManageChild::SetButtonEnableOn()
{
	ui->editSeleFileBut->setEnabled(true);
	ui->loadSeleFileBut->setEnabled(true);
	ui->delSeleFileBut->setEnabled(true);
	ui->OKFileNameBut->setEnabled(true);
	ui->copyFile2localBut->setEnabled(true);
	this->boolFileSelected = true;
}

void FileManageChild::SetButtonEnableOff()
{
	ui->editSeleFileBut->setEnabled(false);
	ui->loadSeleFileBut->setEnabled(false);
	ui->delSeleFileBut->setEnabled(false);
	ui->OKFileNameBut->setEnabled(false);
	ui->copyFile2localBut->setEnabled(false);
	this->boolFileSelected = false;
}

void FileManageChild::loadSeleFileBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget()); 
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
	MainWindow *pMainWindow = qobject_cast<MainWindow*>(pFilemanageForm->parentWidget()); 
	pFilemanageForm->hide();
	pMainWindow->m_MessagePrint->ReadObjectsFromXml(this->GetCurXmlFile());
	pMainWindow->DownloadPrintData();
	pMainWindow->RefreshWindow();
}

void FileManageChild::editSeleFileBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());
	pFilemanageForm->FileEditChildWidgetCall();
	pFilemanageForm->FormFileEditChild->LoadLocalFile();

	QMap <QString,int> MatrixMap;
	MatrixMap.insert("1L9M",0);
	MatrixMap.insert("1L12M",1);
	MatrixMap.insert("1L14M",2);
	MatrixMap.insert("1L19M",3);
	MatrixMap.insert("1L25M",4);
	MatrixMap.insert("1L32M",5);
	QString qStrMatrix = QString::fromStdString(m_pPrinterMes->strMatrix);

	pFilemanageForm->FormFileEditChild->ui->pixelComBox->setCurrentIndex(MatrixMap[qStrMatrix]);
}

void FileManageChild::delSeleFileBut_clicked()
{
	QString qFileName = this->ui->filelistWidget->currentItem()->text();

#ifdef BIG_CHAR
	QString qFilePath = "User/label/" + qFileName;
#else
	QString qFilePath = "User/Vec-label/" + qFileName;
#endif

	QFile qSelFile(qFilePath);
	qSelFile.remove();
	if (!qSelFile.remove())
	{
		this->m_pPrinterMes->OBJ_Vec.clear();
		this->ui->fileNmaeLineEdit->setText("");
	}
	this->ShowLocalFilePath();
}

void FileManageChild::copyFile2localBut_clicked()
{
	QString qFileName = this->ui->fileNmaeLineEdit->text();
	QString qFilePath = "User/Label/" + qFileName + ".lab";
	QString qNewName = qFileName + "_copy";
	QString qNewPath = "User/Label/" + qNewName + ".lab";
	QFile qFile(qFilePath);
	QFileInfo qNewFile(qNewPath);
	if (!qNewFile.exists())
	{
		qFile.copy(qFilePath,qNewPath);
		this->ui->fileNmaeLineEdit->setText(qNewName);
	}
	else
	{
		//弹出文件名重复
		informationMessage();
	}
	this->ShowLocalFilePath();
}

void FileManageChild::PreviewLocalFile()
{
	m_pPrinterMes->OBJ_Vec.clear();
	m_pPrinterMes->ReadObjectsFromXml(GetCurXmlFile());	
	QString qfileName = this->ui->filelistWidget->currentItem()->text();
	QFileInfo fi(qfileName);
	qfileName = fi.baseName();
	this->ui->fileNmaeLineEdit->setText(qfileName);
	this->update();
}

void FileManageChild::PreviewSaveFile(QString tempStr)
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	m_pPrinterMes->ClearOBJ_Vec();

	QFileInfo file(tempStr);
	tempStr = file.baseName();

#ifdef BIG_CHAR
	QString tempStr1 = tempStr + ".lab";
	QList<QListWidgetItem*> tmpList = pFilemanageForm->FormFileManageChild->ui->filelistWidget->findItems(tempStr1,Qt::MatchExactly);
#else
	QString tempStr1 = tempStr + ".vlab";
	QList<QListWidgetItem*> tmpList = pFilemanageForm->FormFileManageChild->ui->filelistWidget->findItems(tempStr1,Qt::MatchExactly);
#endif
	
	//默认可以且只能找到一个目标，存放在tmpList[0]中
	QListWidgetItem *tmpItem = tmpList.at(0);
	ui->filelistWidget->setCurrentItem(tmpItem);

	//取消选中状态
	m_pPrinterMes->OBJ_Vec.assign(pFilemanageForm->FormFileEditChild->m_MessagePrint.OBJ_Vec.begin(),pFilemanageForm->FormFileEditChild->m_MessagePrint.OBJ_Vec.end());
	for (int i=0; i<m_pPrinterMes->OBJ_Vec.size(); i++)
	{
		if (m_pPrinterMes->OBJ_Vec[i]->booFocus)
		{
			m_pPrinterMes->OBJ_Vec[i]->booFocus = false;
		}
	}

	ui->fileNmaeLineEdit->setText(tempStr);
}

char* FileManageChild::GetCurXmlFile()
{
	if (this->boolFileSelected == true)
	{
		QString qfileName = this->ui->filelistWidget->currentItem()->text();
		qfileName = rootStr + "/" + qfileName;
		string fileName = qfileName.toStdString();
		char strTemp[256];
		sprintf(strTemp,"%s",fileName.c_str());
		return strTemp;
	}
	else
	{
		//弹出对话框“请选择一个文件”
        return NULL;
	}
}

bool FileManageChild::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui->filePrivewtextEdit && event->type() == QEvent::Paint)
	{
		paintFrame();
		paintDot();
	}
	return QWidget::eventFilter(watched,event);
}

void FileManageChild::paintDot()
{
	QPainter painter(ui->filePrivewtextEdit);
	m_pPrinterMes->DrawDot(&painter);
}

void FileManageChild::paintFrame()
{
	QPainter qFramePainter(this->ui->filePrivewtextEdit);
	DrawBackFrame(&qFramePainter);
}

void FileManageChild::DrawBackFrame(QPainter *qFramePainter)
{
#ifdef BIG_CHAR
	QPen qGrayPen(Qt::lightGray,1,Qt::SolidLine,Qt::SquareCap,Qt::MiterJoin);
	QPen qRedPen(Qt::red,2,Qt::SolidLine,Qt::RoundCap,Qt::BevelJoin);

	QMap <QString,int> MatrixMap;
	MatrixMap.insert("1L9M",45);
	MatrixMap.insert("1L12M",60);
	MatrixMap.insert("1L14M",70);
	MatrixMap.insert("1L19M",95);
	MatrixMap.insert("1L25M",125);
	MatrixMap.insert("1L32M",160);
	
	QString qStrMatrix = QString::fromStdString(m_pPrinterMes->strMatrix);
	int i,j;
	for (i=1; i<=3121; i+=5)
	{
		//画列
		qFramePainter->setPen(qGrayPen);
		qFramePainter->drawLine(i,241-MatrixMap[qStrMatrix],i,241);
	}
	for (j=241; j>=241-MatrixMap[qStrMatrix]; j-=5)
	{
		//画行
		qFramePainter->setPen(qGrayPen);
		qFramePainter->drawLine(0,j,3121,j);
	}
	qFramePainter->setPen(qRedPen);
	qFramePainter->drawLine(1,241,1,241-MatrixMap[qStrMatrix]);//left
	qFramePainter->drawLine(0,239,3121,239);//down
	qFramePainter->drawLine(0,241-MatrixMap[qStrMatrix],3121,241-MatrixMap[qStrMatrix]);//up
	qFramePainter->drawLine(3120,241,3120,241-MatrixMap[qStrMatrix]);//right

#else
	QPen qGrayPen(Qt::lightGray,1,Qt::DotLine,Qt::SquareCap,Qt::MiterJoin);
	QPen qRedPen(Qt::red,2,Qt::SolidLine,Qt::RoundCap,Qt::BevelJoin);

	int i,j;
	for (i = 1; i <= 3121; i += 50)//先写死
	{
		//画列
		qFramePainter->setPen(qGrayPen);
		qFramePainter->drawLine(i,90,i,241);
	}
	for (j = 90; j <= 240; j += 50)//先写死
	{
		//画行
		qFramePainter->setPen(qGrayPen);
		qFramePainter->drawLine(0,j,3121,j);
	}

	qFramePainter->setPen(qRedPen);
	qFramePainter->drawLine(0,241,0,89);//left
	qFramePainter->drawLine(3121,241,3121,89);//right
	qFramePainter->drawLine(0,89,3121,89);//up
	qFramePainter->drawLine(0,241,3121,241);//down

	//获得Matrix 及 Pixel的值
	//m_MessagePrint.Matrix = PixelMap[CurPixelItem]/5;
	//m_MessagePrint.strMatrix = "1L"+ m_MessagePrint.to_String(m_MessagePrint.Matrix)+"M";

#endif
}

void FileManageChild::slotShow(QDir dir)  
{  
	QFileInfoList InfoList = dir.entryInfoList(QDir :: Files, QDir :: Name);  
	showFileInfoList(InfoList);  
}  

void FileManageChild::showFileInfoList(QFileInfoList list) 
{  
	ui->filelistWidget->clear(); 

	for (unsigned int i = 0; i < list.count(); i++)  
	{  
		QFileInfo tmpFileInfo = list.at(i);  
		QString fileName = tmpFileInfo.fileName();  
		QListWidgetItem * tmpListWidgetItem = new QListWidgetItem(fileName);  
		tmpListWidgetItem->setSizeHint(QSize(150,50));
		ui->filelistWidget->addItem(tmpListWidgetItem);  
	}  
}  

void FileManageChild::UdiskFileBut_clicked()
{
	this->ui->filelistWidget->clear();
	QString udiskLabelPath = "/mnt/udisk/";
	QDir rootDir(udiskLabelPath);
	slotShow(rootDir);
	SetButtonEnableOff();
	QWidget *pQWidget(this);
	pQWidget->update();
}

void FileManageChild::ShowLocalFilePath()
{
	this->ui->filelistWidget->clear();
#ifdef BIG_CHAR
	rootStr = "User/Label"; 
#else
	rootStr = "User/Vec-Label"; 
#endif
	QDir rootDir(rootStr); 
	slotShow(rootDir); 
	SetButtonEnableOff();
	QWidget *pQWidget(this);
	pQWidget->update();
}

void FileManageChild::fileNmaeLineEdit_click()
{
	keyboardWidget->SetLineEditFM(ui->fileNmaeLineEdit);
}

void FileManageChild::OKFileNameBut_clicked()
{
	QString qFileName1 = this->ui->filelistWidget->currentItem()->text();
	QString qFileName2 = this->ui->fileNmaeLineEdit->text();

#ifdef BIG_CHAR
	QString tmpPath1 = "User/Label/" + qFileName1;
	QString tmpPath2 = "User/Label/" + qFileName2 + ".lab";
#else
	QString tmpPath1 = "User/Vec-Label/" + qFileName1;
	QString tmpPath2 = "User/Vec-Label/" + qFileName2 + ".vlab";
#endif

	QFileInfo fi(tmpPath2);
	if (!fi.exists())
	{
		QFile::rename(tmpPath1,tmpPath2);
		this->ShowLocalFilePath();
		keyboardWidget->setVisible(false);
	}
	else
	{
		//弹出文件名重复
		informationMessage();
	}
}

void FileManageChild::informationMessage()
{
	CAutoMessageBox msg;
	msg.AutoSetSize(440,200);

	msg.setText(tr("<h1><i>Filename</i><p align='center'> </font>Repetition</font></p></h1>"));
	msg.setWindowTitle(tr("Warning"));
	msg.setIcon(QMessageBox::Critical);
	msg.addButton(tr("OK"),QMessageBox::ActionRole);
	msg.setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);\
					   QPushButton {background-color: rgb(0,0,0);color: rgb(255, 255, 255);font: bold;font-size:40px;color:rgb(255,255,255)};\
					   ");
    msg.exec();
}

FileManageChild::~FileManageChild()
{
	delete m_pPrinterMes;
}
