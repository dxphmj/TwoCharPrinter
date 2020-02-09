#include "variabledm.h"
#include <QTableWidget>
#include "filemanageform.h"

variableDM::variableDM(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.returnVarDMBut,SIGNAL(clicked()),this,SLOT(returnVarDMBut_clicked()));

}

variableDM::~variableDM()
{

}

void variableDM::returnVarDMBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->FileEditChildWidgetCall();

}
