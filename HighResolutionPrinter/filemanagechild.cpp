#include "filemanagechild.h"
#include "ui_filemanagechild.h"
#include "QDir"
#include "QFileDialog"
#include "QTextStream"
#include "QFile"
#include <QTextCodec>
#include "filemanageform.h"
#include "fileeditchild.h"

FileManageChild::FileManageChild(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::FileManageChild)
{
	ui->setupUi(this);

	ui->filePrivewtextEdit->installEventFilter(this);

	connect(ui->localFileBut,SIGNAL(clicked()),this,SLOT(ShowLocalFilePath()));  
	connect(ui->loadSeleFileBut, SIGNAL(clicked()),this,SLOT(loadSeleFileBut_clicked())); 
	connect(ui->editSeleFileBut,SIGNAL(clicked()),this,SLOT(editSeleFileBut_clicked()));
	connect(ui->filelistWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this,SLOT(PreviewLocalFile()));
}
void FileManageChild::loadSeleFileBut_clicked()
{

}

void FileManageChild::editSeleFileBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->FileEditWidgetCall();
	pFilemanageForm->FormFileEditChild->LoadLocalFile();
}

void FileManageChild::PreviewLocalFile()
{
	/*QString QfileName = this->ui->filelistWidget->currentItem()->text();
	QfileName = rootStr + "/" + QfileName;
	string CfileName = QfileName.toStdString();*/
	m_PrinterMes2.ReadObjectsFromXml(GetCurXmlFile());	
}

char* FileManageChild::GetCurXmlFile()
{
	QString QfileName = this->ui->filelistWidget->currentItem()->text();
	QfileName = rootStr + "/" + QfileName;
	string fileName = QfileName.toStdString();
	char strTemp[256];
	sprintf(strTemp,"%s",fileName.c_str());
	return 	strTemp;
}

bool FileManageChild::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui->filePrivewtextEdit && event->type() == QEvent::Paint)
	{
		paintDot();
	}
	return QWidget::eventFilter(watched,event);
}

void FileManageChild::paintDot()
{
	QPainter painter(ui->filePrivewtextEdit);
	m_PrinterMes2.DrawDot(&painter);
	QWidget *m_QWidget(this);
	m_QWidget->update();
}

void FileManageChild::slotShow(QDir dir)  
{  
	//QStringList stringList;  
	//stringList << "*";
	//QFileInfoList InfoList = dir.entryInfoList(QDir :: AllEntries, QDir :: DirsFirst);  
	//showFileInfoList(InfoList);  
}  

void FileManageChild::showFileInfoList(QFileInfoList list) 
{  
	ui->filelistWidget->clear(); 

	for (unsigned int i = 0; i < list.count(); i++)  
	{  
		QFileInfo tmpFileInfo = list.at(i);  
		if (tmpFileInfo.isDir())  
		{  
			QIcon icon("dir.png");  
			QString fileName = tmpFileInfo.fileName();  
			QListWidgetItem * tmpListWidgetItem = new QListWidgetItem(icon, fileName);  
			ui->filelistWidget->addItem(tmpListWidgetItem);  
		}  
		else  
		{  
			QIcon icon("file.png");  
			QString fileName = tmpFileInfo.fileName();  
			QListWidgetItem * tmpListWidgetItem = new QListWidgetItem(icon, fileName);  
			ui->filelistWidget->addItem(tmpListWidgetItem);  
		}  
	}  
}  

void FileManageChild::ShowLocalFilePath()
{
	rootStr = "User/Label";  
	QDir rootDir(rootStr);  
	//QStringList stringlist;  
	//stringlist << "*";  
	list = rootDir.entryInfoList();
	showFileInfoList(list);  
	//setWindowTitle("File View");  
}

FileManageChild::~FileManageChild(){}