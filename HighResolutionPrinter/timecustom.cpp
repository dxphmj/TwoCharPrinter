#include "ui_timecustom.h"
#include "timecustom.h"
#include "filemanageform.h"

timeCustom::timeCustom(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::timeCustom)

{
	ui->setupUi(this);

	connect(ui->OKDateBut,SIGNAL(clicked()),this,SLOT(OKDateBut_clicked()));
	connect(ui->cancelDateBut,SIGNAL(clicked()),this,SLOT(cancelDateBut_clicked()));

}

timeCustom::~timeCustom()
{

}

void timeCustom::OKDateBut_clicked()
{
	//将时间日期label中的内容生成点阵
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->FileEditChildWidgetCall();
}

void timeCustom::cancelDateBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->FileEditChildWidgetCall();
}