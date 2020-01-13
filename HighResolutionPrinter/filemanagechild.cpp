#include "filemanagechild.h"
#include "QDir"
#include "QFileDialog"
#include "QTextStream"
#include "QFile"

FileManageChild::FileManageChild(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.localFileBut,SIGNAL(clicked()),this,SLOT(localFileBut_clicked()));
}

FileManageChild::~FileManageChild()
{

}

void FileManageChild::localFileBut_clicked()
{
		
	//QString path = QDir::toNativeSeparators(QFileDialog::getOpenFileName(this,tr("Save path"),QDir::currentPath())); 
	//if(!path.isEmpty())
	//{
	//	if(ui->comboBox->findText(path)==-1)
	//		ui->comboBox->addItem(path);    //在comboBox中显示文件路径

	//	QFile *file=new QFile;   //申请一个文件指针
	//	file->setFileName(path);   //设置文件路径
	//	bool ok=file->open(QIODevice::ReadOnly);
	//	if(ok)
	//	{
	//		QTextStream in(file);
	//		ui->textBrowser->setText(in.readAll());    //在textBrowser中显示文件内容
	//		file->close();
	//	}

	//}
	
}