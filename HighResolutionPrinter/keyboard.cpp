#include "keyboard.h"
#include "fileeditchild.h"
#include <QAction>

keyboard::keyboard(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//showText= new FileEditChild;

	connect(ui.A_KBBut,SIGNAL(clicked()),this,SLOT(A_KBBut_clicked()));
	connect(ui.B_KBBut,SIGNAL(clicked()),this,SLOT(B_KBBut_clicked()));
	connect(ui.enter_KBBut,SIGNAL(clicked()),this,SLOT(enter_KBBut_clicked()));
	connect(ui.backspace_KBBut,SIGNAL(clicked()),this,SLOT(backspace_KBBut_clicked()));

}

keyboard::~keyboard()
{

}

void keyboard::A_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValA(val);
}

QString keyboard::A_KBBut_sendData()
{
	value = ui.A_KBBut->text();
	return this->value;
}

void keyboard::enter_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->hideKB();

}

void keyboard::B_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValB(val);
}

void keyboard::backspace_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->deleteChar();
}

QString keyboard::B_KBBut_sendData()
{
	value = ui.B_KBBut->text();
	return this->value;
}

