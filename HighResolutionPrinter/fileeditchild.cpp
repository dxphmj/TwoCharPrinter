#include "fileeditchild.h"
#include "filemanageform.h"


FileEditChild::FileEditChild(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


//	setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);hide();
//	this->setParent(parent);

	connect(ui.variableBut,SIGNAL(clicked()),this,SLOT(variableBut_clicked()));
}

FileEditChild::~FileEditChild()
{

}

void FileEditChild::variableBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->variableWidgetCall();
	
}