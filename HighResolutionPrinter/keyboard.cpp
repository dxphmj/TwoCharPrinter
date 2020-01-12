#include "keyboard.h"
#include <QString>

keyboard::keyboard(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.A_KBBut,SIGNAL(clicked()),this,SLOT(A_KBBut_clicked()));

}

keyboard::~keyboard()
{

}

void keyboard::A_KBBut_clicked()
{
	//QString value = ui.A_KBBut->text();
	//ui.currentLineEdit->insert(value);
}
