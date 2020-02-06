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
	connect(ui->loadSeleFileBut, SIGNAL(clicked()),this,SLOT(loadSeleFileBut_clicked())); 
	connect(ui->editSeleFileBut,SIGNAL(clicked()),this,SLOT(editSeleFileBut_clicked()));
	connect(ui->filelistWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(SetButtonEnableOn()));
	connect(ui->filelistWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(PreviewLocalFile()));
	connect(ui->fileNmaeLineEdit,SIGNAL(clicked()),this,SLOT(fileNmaeLineEdit_click())); 
	connect(ui->OKFileNameBut,SIGNAL(clicked()),this,SLOT(OKFileNameBut_clicked()));
	connect(ui->delSeleFileBut,SIGNAL(clicked()),this,SLOT(delSeleFileBut_clicked()));

	SetButtonEnableOff();
	boolSaveAsBtn_Clicked = false;
	m_pPrinterMes = new ClassMessage;
	ShowLocalFilePath(); 
	keyboardWidget = new keyboard(this);
	keyboardWidget->setVisible(false);
}

void FileManageChild::SetButtonEnableOn()
{
	ui->editSeleFileBut->setEnabled(true);
	ui->loadSeleFileBut->setEnabled(true);
	ui->delSeleFileBut->setEnabled(true);
	ui->OKFileNameBut->setEnabled(true);
	this->boolFileSelected = true;
}

void FileManageChild::SetButtonEnableOff()
{
	ui->editSeleFileBut->setEnabled(false);
	ui->loadSeleFileBut->setEnabled(false);
	ui->delSeleFileBut->setEnabled(false);
	ui->OKFileNameBut->setEnabled(false);
	this->boolFileSelected = false;
}

void FileManageChild::loadSeleFileBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget()); 
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
	MainWindow *pMainWindow = qobject_cast<MainWindow*>(pFilemanageForm->parentWidget()); 
	pFilemanageForm->hide();
	pMainWindow->m_PrinterMes->ReadObjectsFromXml(this->GetCurXmlFile());
	pMainWindow->RefreshWindow();
}

void FileManageChild::editSeleFileBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());
	pFilemanageForm->FileEditChildWidgetCall();
	pFilemanageForm->FormFileEditChild->LoadLocalFile();
}

void FileManageChild::delSeleFileBut_clicked()
{
	QString qFileName = this->ui->filelistWidget->currentItem()->text();
	QString qFilePath = "User/label/" + qFileName;
	QFile qSelFile(qFilePath);
	qSelFile.remove();
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
}

void FileManageChild::PreviewSaveFile()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());
	m_pPrinterMes->OBJ_Vec.clear();
	m_pPrinterMes->OBJ_Vec.assign(pFilemanageForm->FormFileEditChild->m_PrinterMes.OBJ_Vec.begin(),pFilemanageForm->FormFileEditChild->m_PrinterMes.OBJ_Vec.end());
	QString qfileName = this->ui->filelistWidget->currentItem()->text();
	QFileInfo fi(qfileName);
	qfileName = fi.baseName();
	this->ui->fileNmaeLineEdit->setText(qfileName);
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
		return "";
	}
}

bool FileManageChild::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui->filePrivewtextEdit && event->type() == QEvent::Paint)
	{
		paintDot();
		QWidget *m_QWidget(this);
		m_QWidget->update();
	}
	return QWidget::eventFilter(watched,event);
}

void FileManageChild::paintDot()
{
	QPainter painter(ui->filePrivewtextEdit);
	m_pPrinterMes->DrawDot(&painter);
	QWidget *m_QWidget(this);
	m_QWidget->update();
}

void FileManageChild::slotShow(QDir dir)  
{  
	QStringList stringList;  
	stringList << "*";
	QFileInfoList InfoList = dir.entryInfoList(QDir :: Files, QDir :: Name);  
	showFileInfoList(InfoList);  
}  

void FileManageChild::showFileInfoList(QFileInfoList list) 
{  
	ui->filelistWidget->clear(); 

	for (unsigned int i = 0; i < list.count(); i++)  
	{  
		QFileInfo tmpFileInfo = list.at(i);  
		QIcon icon("file.png");  
		QString fileName = tmpFileInfo.fileName();  
		QListWidgetItem * tmpListWidgetItem = new QListWidgetItem(icon, fileName);  
		ui->filelistWidget->addItem(tmpListWidgetItem);  
	}  
}  

void FileManageChild::ShowLocalFilePath()
{
	rootStr = "User/Label"; 
	QDir rootDir(rootStr); 
	slotShow(rootDir); 
	SetButtonEnableOff();
	QWidget *pQWidget(this);
	pQWidget->update();
}

void FileManageChild::fileNmaeLineEdit_click()
{
	keyboardWidget->SetLineEdit(ui->fileNmaeLineEdit);
}

void FileManageChild::OKFileNameBut_clicked()
{
	if (this->boolSaveAsBtn_Clicked == true)
	{
		QString qFileName = this->ui->fileNmaeLineEdit->text();
		QString qFilePath = "User/Label/" + qFileName + ".lab";
		char charFilePath[256];
		QFileInfo fi(qFilePath);
		if (!fi.exists())
		{
			sprintf(charFilePath,"%s",qFilePath.toStdString().c_str());
			QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
			FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
			pFilemanageForm->FormFileEditChild->m_PrinterMes.SaveObjectsToXml(charFilePath);
			this->ShowLocalFilePath();
			keyboardWidget->setVisible(false);
			this->boolSaveAsBtn_Clicked = false;
		}
		else
		{
			//弹出文件名重复
			informationMessage();
		}
	}
	else
	{
		QString qFileName1 = this->ui->filelistWidget->currentItem()->text();
		QString tmpPath1 = "User/Label/" + qFileName1;
		QString qFileName2 = this->ui->fileNmaeLineEdit->text();
		QString tmpPath2 = "User/Label/" + qFileName2 + ".lab";
		QFileInfo fi(tmpPath2);
		if (fi.exists()==0)
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