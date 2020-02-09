#include "variableqr.h"
#include <QTableWidget>
#include "filemanageform.h"

variableQR::variableQR(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.returnVarQRBut,SIGNAL(clicked()),this,SLOT(returnVarQRBut_clicked()));
}

variableQR::~variableQR()
{

}

void variableQR::returnVarQRBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->FileEditChildWidgetCall();
}
