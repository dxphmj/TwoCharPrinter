#include "language.h"
#include "ui_language.h"
#include "fileeditchild.h"
#include <QtWidgets/QStackedWidget>

language::language(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.OKLanBut,SIGNAL(clicked()),this,SLOT(OKLanBut_clicked()));

}

language::~language()
{
	
}

void language::OKLanBut_clicked()
{
	//暂时用wordLineEdit_clicked调出KB
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->returnKB();
    
}