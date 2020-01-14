#include "filemanagechild.h"
#include "ui_filemanagechild.h"
#include "QDir"
#include "QFileDialog"
#include "QTextStream"
#include "QFile"
#include <QTextCodec>
#include "ClassMessage.h"

FileManageChild::FileManageChild(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//fileListWidget = this->ui.listWidget;  
	ui.filePrivewtextBro->installEventFilter(this);

	connect(ui.localFileBut,SIGNAL(clicked()),this,SLOT(ShowLocalFilePath()));  
	//connect(ui.loadSeleFileBut, SIGNAL(clicked()),this,SLOT(PreviewLocalFile())); 
	connect(ui.ListWidget1,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this,SLOT(PreviewLocalFile()));
}

void FileManageChild::PreviewLocalFile()
{
	QString QfileName = this->ui.ListWidget1->currentItem()->text();
	QfileName = rootStr + "/" + QfileName;
	string CfileName = QfileName.toStdString();
	char* chr = const_cast<char*>(CfileName.c_str());
	m_PrinterMes2.ReadObjectsFromXml(chr);
	
}

bool FileManageChild::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui.filePrivewtextBro && event->type() == QEvent::Paint)
	{
		paintDot();
	}
	return QWidget::eventFilter(watched,event);
}

void FileManageChild::paintDot()
{
	QPainter painter(ui.filePrivewtextBro);
	m_PrinterMes2.DrawDot(&painter);
}

void FileManageChild::slotShow(QDir dir)  
{  
	QStringList stringList;  
	stringList << "*";
	QFileInfoList InfoList = dir.entryInfoList(stringList, QDir :: AllEntries, QDir :: DirsFirst);  
	showFileInfoList(InfoList);  
}  

void FileManageChild::showFileInfoList(QFileInfoList list) 
{  
	ui.ListWidget1->clear(); 

	for (unsigned int i = 0; i < list.count(); i++)  
	{  
		QFileInfo tmpFileInfo = list.at(i);  
		if (tmpFileInfo.isDir())  
		{  
			QIcon icon("dir.png");  
			QString fileName = tmpFileInfo.fileName();  
			QListWidgetItem * tmpListWidgetItem = new QListWidgetItem(icon, fileName);  
			ui.ListWidget1->addItem(tmpListWidgetItem);  
		}  
		else  
		{  
			QIcon icon("file.png");  
			QString fileName = tmpFileInfo.fileName();  
			QListWidgetItem * tmpListWidgetItem = new QListWidgetItem(icon, fileName);  
			ui.ListWidget1->addItem(tmpListWidgetItem);  
		}  
	}  
}  

void FileManageChild::ShowLocalFilePath()
{
	rootStr = "User/Label";  
	QDir rootDir(rootStr);  
	QStringList stringlist;  
	stringlist << "*";  
	list = rootDir.entryInfoList(stringlist);  
	showFileInfoList(list);  
	setWindowTitle("File View");  
}

FileManageChild::~FileManageChild(){}