#include "keyboard.h"
#include "fileeditchild.h"
#include <QAction>
#include <QtWidgets/QStackedWidget>
#include "lineedit_click.h"

keyboard::keyboard(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//showText= new FileEditChild;

	connect(ui.A_KBBut,SIGNAL(clicked()),this,SLOT(A_KBBut_clicked()));
	connect(ui.B_KBBut,SIGNAL(clicked()),this,SLOT(B_KBBut_clicked()));
	connect(ui.C_KBBut,SIGNAL(clicked()),this,SLOT(C_KBBut_clicked()));
	connect(ui.D_KBBut,SIGNAL(clicked()),this,SLOT(D_KBBut_clicked()));
	connect(ui.E_KBBut,SIGNAL(clicked()),this,SLOT(E_KBBut_clicked()));
	connect(ui.F_KBBut,SIGNAL(clicked()),this,SLOT(F_KBBut_clicked()));
	connect(ui.G_KBBut,SIGNAL(clicked()),this,SLOT(G_KBBut_clicked()));
	connect(ui.H_KBBut,SIGNAL(clicked()),this,SLOT(H_KBBut_clicked()));
	connect(ui.I_KBBut,SIGNAL(clicked()),this,SLOT(I_KBBut_clicked()));
	connect(ui.J_KBBut,SIGNAL(clicked()),this,SLOT(J_KBBut_clicked()));
	connect(ui.K_KBBut,SIGNAL(clicked()),this,SLOT(K_KBBut_clicked()));
	connect(ui.L_KBBut,SIGNAL(clicked()),this,SLOT(L_KBBut_clicked()));
	connect(ui.M_KBBut,SIGNAL(clicked()),this,SLOT(M_KBBut_clicked()));
	connect(ui.N_KBBut,SIGNAL(clicked()),this,SLOT(N_KBBut_clicked()));
	connect(ui.O_KBBut,SIGNAL(clicked()),this,SLOT(O_KBBut_clicked()));
	connect(ui.P_KBBut,SIGNAL(clicked()),this,SLOT(P_KBBut_clicked()));
	connect(ui.Q_KBBut,SIGNAL(clicked()),this,SLOT(Q_KBBut_clicked()));
	connect(ui.R_KBBut,SIGNAL(clicked()),this,SLOT(R_KBBut_clicked()));
	connect(ui.S_KBBut,SIGNAL(clicked()),this,SLOT(S_KBBut_clicked()));
	connect(ui.T_KBBut,SIGNAL(clicked()),this,SLOT(T_KBBut_clicked()));
	connect(ui.U_KBBut,SIGNAL(clicked()),this,SLOT(U_KBBut_clicked()));
	connect(ui.V_KBBut,SIGNAL(clicked()),this,SLOT(V_KBBut_clicked()));
	connect(ui.W_KBBut,SIGNAL(clicked()),this,SLOT(W_KBBut_clicked()));
	connect(ui.X_KBBut,SIGNAL(clicked()),this,SLOT(X_KBBut_clicked()));
	connect(ui.Y_KBBut,SIGNAL(clicked()),this,SLOT(Y_KBBut_clicked()));
	connect(ui.Z_KBBut,SIGNAL(clicked()),this,SLOT(Z_KBBut_clicked()));
	connect(ui.one_KBBut,SIGNAL(clicked()),this,SLOT(num1_KBBut_clicked()));
	connect(ui.two_KBBut,SIGNAL(clicked()),this,SLOT(num2_KBBut_clicked()));
	connect(ui.three_KBBut,SIGNAL(clicked()),this,SLOT(num3_KBBut_clicked()));
	connect(ui.four_KBBut,SIGNAL(clicked()),this,SLOT(num4_KBBut_clicked()));
	connect(ui.five_KBBut,SIGNAL(clicked()),this,SLOT(num5_KBBut_clicked()));
	connect(ui.six_KBBut,SIGNAL(clicked()),this,SLOT(num6_KBBut_clicked()));
	connect(ui.seven_KBBut,SIGNAL(clicked()),this,SLOT(num7_KBBut_clicked()));
	connect(ui.eight_KBBut,SIGNAL(clicked()),this,SLOT(num8_KBBut_clicked()));
	connect(ui.nine_KBBut,SIGNAL(clicked()),this,SLOT(num9_KBBut_clicked()));
	connect(ui.zero_KBBut,SIGNAL(clicked()),this,SLOT(num0_KBBut_clicked()));
	connect(ui.space_KBBut,SIGNAL(clicked()),this,SLOT(space_KBBut_clicked()));
	connect(ui.comma_KBBut,SIGNAL(clicked()),this,SLOT(comma_KBBut_clicked()));
	connect(ui.period_KBBut,SIGNAL(clicked()),this,SLOT(period_KBBut_clicked()));

	connect(ui.enter_KBBut,SIGNAL(clicked()),this,SLOT(enter_KBBut_clicked()));
	connect(ui.backspace_KBBut,SIGNAL(clicked()),this,SLOT(backspace_KBBut_clicked()));
	connect(ui.language_KBBut,SIGNAL(clicked()),this,SLOT(language_KBBut_clicked()));
	connect(ui.shift_KBBut,SIGNAL(clicked()),this,SLOT(on_caps_Bt_clicked()));

}

keyboard::~keyboard()
{
	
}

void keyboard::enter_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->hideKB();
	pFileEditChild->ShowText();
}

void keyboard::backspace_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->backspace();
	QString str1 = m_pInputEdit->text();
}

void keyboard::language_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->languageWidgetCall();

}

void keyboard::A_KBBut_clicked()
{
	//QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	//FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	//pFileEditChild->getValA(val);

	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.A_KBBut->text());
}
//QString keyboard::A_KBBut_sendData()
//{
//	value = ui.A_KBBut->text();
//	return this->value;
//}

void keyboard::B_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.B_KBBut->text());
}

void keyboard::C_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.C_KBBut->text());
}

void keyboard::D_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.D_KBBut->text());
}

void keyboard::E_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.E_KBBut->text());
}

void keyboard::F_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.F_KBBut->text());
}

void keyboard::G_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.G_KBBut->text());
}

void keyboard::H_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.H_KBBut->text());
}

void keyboard::I_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.I_KBBut->text());
}

void keyboard::J_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.J_KBBut->text());
}

void keyboard::K_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.K_KBBut->text());
}

void keyboard::L_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.L_KBBut->text());
}

void keyboard::M_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.M_KBBut->text());
}

void keyboard::N_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.N_KBBut->text());
}

void keyboard::O_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.O_KBBut->text());
}

void keyboard::P_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.P_KBBut->text());
}

void keyboard::Q_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.Q_KBBut->text());
}

void keyboard::R_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.R_KBBut->text());
}

void keyboard::S_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.S_KBBut->text());
}

void keyboard::T_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.T_KBBut->text());
}

void keyboard::U_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.U_KBBut->text());
}

void keyboard::V_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.V_KBBut->text());
}

void keyboard::W_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.W_KBBut->text());
}

void keyboard::X_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.X_KBBut->text());
}

void keyboard::Y_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.Y_KBBut->text());
}

void keyboard::Z_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.Z_KBBut->text());
}

void keyboard::num1_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.one_KBBut->text());
}

void keyboard::num2_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.two_KBBut->text());
}

void keyboard::num3_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.three_KBBut->text());
}

void keyboard::num4_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.four_KBBut->text());
}

void keyboard::num5_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.five_KBBut->text());
}

void keyboard::num6_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.six_KBBut->text());
}

void keyboard::num7_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.seven_KBBut->text());
}

void keyboard::num8_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.eight_KBBut->text());
}

void keyboard::num9_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.nine_KBBut->text());
}

void keyboard::num0_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.zero_KBBut->text());
}

void keyboard::space_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(" ");
}

void keyboard::comma_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.comma_KBBut->text());
}

void keyboard::period_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui.period_KBBut->text());
}

//ÇÐ»»´óÐ¡Ð´
void keyboard::on_caps_Bt_clicked()
{
	if (isCap == false) // Ð¡Ð´×´Ì¬
	{
		QString upper = ui.A_KBBut->text().toUpper();
		ui.A_KBBut->setText(upper);
		isCap = true;
	}
	else // ´óÐ´×´Ì¬
	{
		QString lower = ui.A_KBBut->text().toLower();
		ui.A_KBBut->setText(lower);
		isCap = false;
	}
}
