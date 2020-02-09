#include "variablebarcode.h"
#include <QTableWidget>
#include "filemanageform.h"

variableBarCode::variableBarCode(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.returnVarBarCodeBut,SIGNAL(clicked()),this,SLOT(returnVarBarCodeBut_clicked()));
}

variableBarCode::~variableBarCode()
{

}

void variableBarCode::returnVarBarCodeBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->FileEditChildWidgetCall();

}
