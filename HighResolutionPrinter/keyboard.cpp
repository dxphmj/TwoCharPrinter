#include "keyboard.h"
#include "fileeditchild.h"

keyboard::keyboard(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.A_KBBut,SIGNAL(clicked()),this,SLOT(A_KBBut_clicked()));

}

keyboard::~keyboard()
{

}

//QString keyboard::returnText()
//{
//	return this->value;
//}

//void keyboard::A_KBBut_clicked()
//{
//	/*	QStackedWidget *pkeyboardQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
//	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pFileEditChild->parentWidget()); */ 
//	value = ui.A_KBBut->text();
	//pFileEditChild->
//}