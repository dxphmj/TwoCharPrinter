#include "filemanagechild.h"
#include "ui_filemanagechild.h"
#include "QDir"
#include "QFileDialog"
#include "QTextStream"
#include "QFile"
#include "QFileInfo"
#include <QTextCodec>
#include "mainwindow.h"
#include "filemanageform.h"
#include "fileeditchild.h"
#include "keyboard.h"
#include "ClassMessage.h"

FileManageChild::FileManageChild(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::FileManageChild)
{
	ui->setupUi(this);

	ui->filePrivewtextEdit->installEventFilter(this);
	ui->editSeleFileBut->setEnabled(false);
	ui->loadSeleFileBut->setEnabled(false);
	this->booFileSelected = false;

	connect(ui->localFileBut,SIGNAL(clicked()),this,SLOT(ShowLocalFilePath()));  
	connect(ui->loadSeleFileBut, SIGNAL(clicked()),this,SLOT(loadSeleFileBut_clicked())); 
	connect(ui->editSeleFileBut,SIGNAL(clicked()),this,SLOT(editSeleFileBut_clicked()));
	connect(ui->filelistWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(PreviewLocalFile()));
	connect(ui->filelistWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(SetButtonEnabled()));
	connect(ui->fileNmaeLineEdit,SIGNAL(clicked()),this,SLOT(fileNmaeLineEdit_click())); 
	//用于实现更改文件名的信号-槽，用户点击EditLine控件旁边的"√"时触发
	//connect(ui->OKFileNameBut,SIGNAL(clicked()),this,SLOT(ChangeFileName()));
	m_pPrinterMes = new ClassMessage;
	ShowLocalFilePath(); 
	keyboardWidget = new keyboard(this);
	keyboardWidget->setVisible(false);
}

/*
void FileManageChild::ChangeFileName()
{
	1.调用bool ClassMessage::JudgeXmlNameRepeat(char* strFileName)，判断xml名称是否重复
	  strFileName = 用户在EditLine中输入的字符串
	2.获取当前选中的文件路径，将其名称赋值为strFileName，即改名
	3.刷新页面 QWidget * pQWidget(this);pQWidget->update();
}
*/

void FileManageChild::SetButtonEnabled()
{
	ui->editSeleFileBut->setEnabled(true);
	ui->loadSeleFileBut->setEnabled(true);
}

void FileManageChild::loadSeleFileBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget()); 
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
	MainWindow *pMainWindow = qobject_cast<MainWindow*>(pFilemanageForm->parentWidget()); 
	this->booFileSelected = true;
	pFilemanageForm->hide();
	pMainWindow->m_PrinterMes->ReadObjectsFromXml(this->GetCurXmlFile());
	pMainWindow->RefreshWindow();
}

void FileManageChild::editSeleFileBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());
	this->booFileSelected = true;
	pFilemanageForm->FileEditChildWidgetCall();
	pFilemanageForm->FormFileEditChild->LoadLocalFile();
}

void FileManageChild::PreviewLocalFile()
{
	/*QString QfileName = this->ui->filelistWidget->currentItem()->text();
	QfileName = rootStr + "/" + QfileName;
	string CfileName = QfileName.toStdString();*/
	m_pPrinterMes->OBJ_Vec.clear();
	m_pPrinterMes->ReadObjectsFromXml(GetCurXmlFile());	
}

char* FileManageChild::GetCurXmlFile()
{
	QString qfileName = this->ui->filelistWidget->currentItem()->text();
	qfileName = rootStr + "/" + qfileName;
	string fileName = qfileName.toStdString();
	char strTemp[256];
	sprintf(strTemp,"%s",fileName.c_str());
	return 	strTemp;
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
	QFileInfoList InfoList = dir.entryInfoList(QDir :: AllEntries, QDir :: DirsFirst);  
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
	QWidget *pQWidget(this);
	pQWidget->update();
}

void FileManageChild::fileNmaeLineEdit_click()
{
	keyboardWidget->SetLineEdit(ui->fileNmaeLineEdit);
}

FileManageChild::~FileManageChild()
{
	delete m_pPrinterMes;
}