#include "numkeyboard.h"
#include <QAction>
#include <QtWidgets/QStackedWidget>
#include "lineedit_click.h"

numkeyboard::numkeyboard(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::numkeyboard)
{
    ui->setupUi(this);

	connect(ui->one_NumKBBut,SIGNAL(clicked()),this,SLOT(num1_NumKBBut_clicked()));
	connect(ui->two_NumKBBut,SIGNAL(clicked()),this,SLOT(num2_NumKBBut_clicked()));
	connect(ui->three_NumKBBut,SIGNAL(clicked()),this,SLOT(num3_NumKBBut_clicked()));
	connect(ui->four_NumKBBut,SIGNAL(clicked()),this,SLOT(num4_NumKBBut_clicked()));
	connect(ui->five_NumKBBut,SIGNAL(clicked()),this,SLOT(num5_NumKBBut_clicked()));
	connect(ui->six_NumKBBut,SIGNAL(clicked()),this,SLOT(num6_NumKBBut_clicked()));
	connect(ui->seven_NumKBBut,SIGNAL(clicked()),this,SLOT(num7_NumKBBut_clicked()));
	connect(ui->eight_NumKBBut,SIGNAL(clicked()),this,SLOT(num8_NumKBBut_clicked()));
	connect(ui->nine_NumKBBut,SIGNAL(clicked()),this,SLOT(num9_NumKBBut_clicked()));
	connect(ui->zero_NumKBBut,SIGNAL(clicked()),this,SLOT(num0_NumKBBut_clicked()));
	connect(ui->period_NumKBBut,SIGNAL(clicked()),this,SLOT(period_NumKBBut_clicked()));
	connect(ui->enter_NumKBBut,SIGNAL(clicked()),this,SLOT(enter_NumKBBut_clicked()));
	connect(ui->Esc_NumKBBut,SIGNAL(clicked()),this,SLOT(Esc_NumKBBut_clicked()));
	connect(ui->devide_NumKBBut,SIGNAL(clicked()),this,SLOT(devide_NumKBBut_clicked()));
	connect(ui->multiple_NumKBBut,SIGNAL(clicked()),this,SLOT(multiple_NumKBBut_clicked()));
	connect(ui->minus_NumKBBut,SIGNAL(clicked()),this,SLOT(minus_NumKBBut_clicked()));
	connect(ui->add_NumKBBut,SIGNAL(clicked()),this,SLOT(add_NumKBBut_clicked()));
	connect(ui->backspace_NumKBBut,SIGNAL(clicked()),this,SLOT(backspace_NumKBBut_clicked()));

}

numkeyboard::~numkeyboard()
{

}

void numkeyboard::SetLineEdit(lineedit_click* pInputEdit)
{
	m_pNumInputEdit = pInputEdit;
	SetPosition();
	setVisible(true);
}

void numkeyboard::SetPosition()
{
	//QRect rectLineEdit;
	//rectLineEdit = m_pNumInputEdit->geometry();
	QRect rectKeyboard;
	rectKeyboard = geometry();
	QRect rect(280,158,rectKeyboard.width(),rectKeyboard.height());
	setGeometry(rect);
}

void numkeyboard::enter_NumKBBut_clicked()
{
	this->setVisible(false);
}

void numkeyboard::Esc_NumKBBut_clicked()
{
	this->setVisible(false);
}

void numkeyboard::num1_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->one_NumKBBut->text());
}

void numkeyboard::num2_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->two_NumKBBut->text());

}

void numkeyboard::num3_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->three_NumKBBut->text());

}

void numkeyboard::num4_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->four_NumKBBut->text());

}

void numkeyboard::num5_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->five_NumKBBut->text());

}

void numkeyboard::num6_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->six_NumKBBut->text());

}

void numkeyboard::num7_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->seven_NumKBBut->text());

}

void numkeyboard::num8_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->eight_NumKBBut->text());

}

void numkeyboard::num9_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->nine_NumKBBut->text());

}

void numkeyboard::num0_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->zero_NumKBBut->text());

}

void numkeyboard::period_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->period_NumKBBut->text());

}

void numkeyboard::devide_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->devide_NumKBBut->text());

}

void numkeyboard::multiple_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->multiple_NumKBBut->text());

}

void numkeyboard::minus_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->minus_NumKBBut->text());

}

void numkeyboard::add_NumKBBut_clicked()
{
	m_pNumInputEdit->cursorPosition();
	m_pNumInputEdit->insert(ui->add_NumKBBut->text());

}

void numkeyboard::backspace_NumKBBut_clicked()
{
	m_pNumInputEdit->backspace();
}
