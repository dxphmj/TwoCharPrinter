#include "keyboard.h"
#include "fileeditchild.h"
#include <QAction>
#include <QtWidgets/QStackedWidget>

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
	pFileEditChild->deleteChar();
}

void keyboard::language_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->languageWidgetCall();

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

void keyboard::B_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValB(val);
}
QString keyboard::B_KBBut_sendData()
{
	value = ui.B_KBBut->text();
	return this->value;
}

void keyboard::C_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValC(val);
}
QString keyboard::C_KBBut_sendData()
{
	value = ui.C_KBBut->text();
	return this->value;
}

void keyboard::D_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValD(val);
}
QString keyboard::D_KBBut_sendData()
{
	value = ui.D_KBBut->text();
	return this->value;
}

void keyboard::E_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValE(val);
}
QString keyboard::E_KBBut_sendData()
{
	value = ui.E_KBBut->text();
	return this->value;
}

void keyboard::F_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValF(val);
}
QString keyboard::F_KBBut_sendData()
{
	value = ui.F_KBBut->text();
	return this->value;
}

void keyboard::G_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValG(val);
}
QString keyboard::G_KBBut_sendData()
{
	value = ui.G_KBBut->text();
	return this->value;
}

void keyboard::H_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValH(val);
}
QString keyboard::H_KBBut_sendData()
{
	value = ui.H_KBBut->text();
	return this->value;
}

void keyboard::I_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValI(val);
}
QString keyboard::I_KBBut_sendData()
{
	value = ui.I_KBBut->text();
	return this->value;
}

void keyboard::J_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValJ(val);
}
QString keyboard::J_KBBut_sendData()
{
	value = ui.J_KBBut->text();
	return this->value;
}

void keyboard::K_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValK(val);
}
QString keyboard::K_KBBut_sendData()
{
	value = ui.K_KBBut->text();
	return this->value;
}

void keyboard::L_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValL(val);
}
QString keyboard::L_KBBut_sendData()
{
	value = ui.L_KBBut->text();
	return this->value;
}

void keyboard::M_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValM(val);
}
QString keyboard::M_KBBut_sendData()
{
	value = ui.M_KBBut->text();
	return this->value;
}

void keyboard::N_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValN(val);
}
QString keyboard::N_KBBut_sendData()
{
	value = ui.N_KBBut->text();
	return this->value;
}

void keyboard::O_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValO(val);
}
QString keyboard::O_KBBut_sendData()
{
	value = ui.O_KBBut->text();
	return this->value;
}

void keyboard::P_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValP(val);
}
QString keyboard::P_KBBut_sendData()
{
	value = ui.P_KBBut->text();
	return this->value;
}

void keyboard::Q_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValQ(val);
}
QString keyboard::Q_KBBut_sendData()
{
	value = ui.Q_KBBut->text();
	return this->value;
}

void keyboard::R_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValR(val);
}
QString keyboard::R_KBBut_sendData()
{
	value = ui.R_KBBut->text();
	return this->value;
}

void keyboard::S_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValS(val);
}
QString keyboard::S_KBBut_sendData()
{
	value = ui.S_KBBut->text();
	return this->value;
}

void keyboard::T_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValT(val);
}
QString keyboard::T_KBBut_sendData()
{
	value = ui.T_KBBut->text();
	return this->value;
}

void keyboard::U_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValU(val);
}
QString keyboard::U_KBBut_sendData()
{
	value = ui.U_KBBut->text();
	return this->value;
}

void keyboard::V_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValV(val);
}
QString keyboard::V_KBBut_sendData()
{
	value = ui.V_KBBut->text();
	return this->value;
}

void keyboard::W_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValW(val);
}
QString keyboard::W_KBBut_sendData()
{
	value = ui.W_KBBut->text();
	return this->value;
}

void keyboard::X_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValX(val);
}
QString keyboard::X_KBBut_sendData()
{
	value = ui.X_KBBut->text();
	return this->value;
}

void keyboard::Y_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValY(val);
}
QString keyboard::Y_KBBut_sendData()
{
	value = ui.Y_KBBut->text();
	return this->value;
}

void keyboard::Z_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValZ(val);
}
QString keyboard::Z_KBBut_sendData()
{
	value = ui.Z_KBBut->text();
	return this->value;
}

void keyboard::num1_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValnum1(val);
}
QString keyboard::num1_KBBut_sendData()
{
	value = ui.one_KBBut->text();
	return this->value;
}

void keyboard::num2_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValnum2(val);
}
QString keyboard::num2_KBBut_sendData()
{
	value = ui.two_KBBut->text();
	return this->value;
}

void keyboard::num3_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValnum3(val);
}
QString keyboard::num3_KBBut_sendData()
{
	value = ui.three_KBBut->text();
	return this->value;
}

void keyboard::num4_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValnum4(val);
}
QString keyboard::num4_KBBut_sendData()
{
	value = ui.four_KBBut->text();
	return this->value;
}

void keyboard::num5_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValnum5(val);
}
QString keyboard::num5_KBBut_sendData()
{
	value = ui.five_KBBut->text();
	return this->value;
}

void keyboard::num6_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValnum6(val);
}
QString keyboard::num6_KBBut_sendData()
{
	value = ui.six_KBBut->text();
	return this->value;
}

void keyboard::num7_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValnum7(val);
}
QString keyboard::num7_KBBut_sendData()
{
	value = ui.seven_KBBut->text();
	return this->value;
}

void keyboard::num8_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValnum8(val);
}
QString keyboard::num8_KBBut_sendData()
{
	value = ui.eight_KBBut->text();
	return this->value;
}

void keyboard::num9_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValnum9(val);
}
QString keyboard::num9_KBBut_sendData()
{
	value = ui.nine_KBBut->text();
	return this->value;
}

void keyboard::num0_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValnum0(val);
}
QString keyboard::num0_KBBut_sendData()
{
	value = ui.zero_KBBut->text();
	return this->value;
}

void keyboard::space_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValspace(val);
}
QString keyboard::space_KBBut_sendData()
{
	value = tr(" ");
	return this->value;
}

void keyboard::comma_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValcomma(val);
}
QString keyboard::comma_KBBut_sendData()
{
	value = ui.comma_KBBut->text();
	return this->value;
}

void keyboard::period_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->getValperiod(val);
}
QString keyboard::period_KBBut_sendData()
{
	value = ui.period_KBBut->text();
	return this->value;
}
