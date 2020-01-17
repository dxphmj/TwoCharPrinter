#include "language.h"
#include "fileeditchild.h"
#include <QtWidgets/QStackedWidget>

language::language(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.OKLanBut,SIGNAL(clicked()),this,SLOT(OKLanBut_clicked()));
	connect(ui.LanEnglish,SIGNAL(clicked()),this,SLOT(lanEnglish_KBBut_clicked()));
	connect(ui.LanChinese,SIGNAL(clicked()),this,SLOT(LanChinese_KBBut_clicked()));
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

void language::lanEnglish_KBBut_clicked()
{
	//用于English切换回原键盘
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->returnKB();   
}

void language::LanChinese_KBBut_clicked()
{

}
