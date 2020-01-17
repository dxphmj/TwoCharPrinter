#include "keyboard.h"
#include "ui_keyboard.h"
#include <QAction>
#include <QtWidgets/QStackedWidget>
#include "lineedit_click.h"
#include "fileeditchild.h"

keyboard::keyboard(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::keyboard)

{
	ui->setupUi(this);

	connect(ui->A_KBBut,SIGNAL(clicked()),this,SLOT(A_KBBut_clicked()));
	connect(ui->B_KBBut,SIGNAL(clicked()),this,SLOT(B_KBBut_clicked()));
	connect(ui->C_KBBut,SIGNAL(clicked()),this,SLOT(C_KBBut_clicked()));
	connect(ui->D_KBBut,SIGNAL(clicked()),this,SLOT(D_KBBut_clicked()));
	connect(ui->E_KBBut,SIGNAL(clicked()),this,SLOT(E_KBBut_clicked()));
	connect(ui->F_KBBut,SIGNAL(clicked()),this,SLOT(F_KBBut_clicked()));
	connect(ui->G_KBBut,SIGNAL(clicked()),this,SLOT(G_KBBut_clicked()));
	connect(ui->H_KBBut,SIGNAL(clicked()),this,SLOT(H_KBBut_clicked()));
	connect(ui->I_KBBut,SIGNAL(clicked()),this,SLOT(I_KBBut_clicked()));
	connect(ui->J_KBBut,SIGNAL(clicked()),this,SLOT(J_KBBut_clicked()));
	connect(ui->K_KBBut,SIGNAL(clicked()),this,SLOT(K_KBBut_clicked()));
	connect(ui->L_KBBut,SIGNAL(clicked()),this,SLOT(L_KBBut_clicked()));
	connect(ui->M_KBBut,SIGNAL(clicked()),this,SLOT(M_KBBut_clicked()));
	connect(ui->N_KBBut,SIGNAL(clicked()),this,SLOT(N_KBBut_clicked()));
	connect(ui->O_KBBut,SIGNAL(clicked()),this,SLOT(O_KBBut_clicked()));
	connect(ui->P_KBBut,SIGNAL(clicked()),this,SLOT(P_KBBut_clicked()));
	connect(ui->Q_KBBut,SIGNAL(clicked()),this,SLOT(Q_KBBut_clicked()));
	connect(ui->R_KBBut,SIGNAL(clicked()),this,SLOT(R_KBBut_clicked()));
	connect(ui->S_KBBut,SIGNAL(clicked()),this,SLOT(S_KBBut_clicked()));
	connect(ui->T_KBBut,SIGNAL(clicked()),this,SLOT(T_KBBut_clicked()));
	connect(ui->U_KBBut,SIGNAL(clicked()),this,SLOT(U_KBBut_clicked()));
	connect(ui->V_KBBut,SIGNAL(clicked()),this,SLOT(V_KBBut_clicked()));
	connect(ui->W_KBBut,SIGNAL(clicked()),this,SLOT(W_KBBut_clicked()));
	connect(ui->X_KBBut,SIGNAL(clicked()),this,SLOT(X_KBBut_clicked()));
	connect(ui->Y_KBBut,SIGNAL(clicked()),this,SLOT(Y_KBBut_clicked()));
	connect(ui->Z_KBBut,SIGNAL(clicked()),this,SLOT(Z_KBBut_clicked()));
	connect(ui->one_KBBut,SIGNAL(clicked()),this,SLOT(num1_KBBut_clicked()));
	connect(ui->two_KBBut,SIGNAL(clicked()),this,SLOT(num2_KBBut_clicked()));
	connect(ui->three_KBBut,SIGNAL(clicked()),this,SLOT(num3_KBBut_clicked()));
	connect(ui->four_KBBut,SIGNAL(clicked()),this,SLOT(num4_KBBut_clicked()));
	connect(ui->five_KBBut,SIGNAL(clicked()),this,SLOT(num5_KBBut_clicked()));
	connect(ui->six_KBBut,SIGNAL(clicked()),this,SLOT(num6_KBBut_clicked()));
	connect(ui->seven_KBBut,SIGNAL(clicked()),this,SLOT(num7_KBBut_clicked()));
	connect(ui->eight_KBBut,SIGNAL(clicked()),this,SLOT(num8_KBBut_clicked()));
	connect(ui->nine_KBBut,SIGNAL(clicked()),this,SLOT(num9_KBBut_clicked()));
	connect(ui->zero_KBBut,SIGNAL(clicked()),this,SLOT(num0_KBBut_clicked()));
	connect(ui->space_KBBut,SIGNAL(clicked()),this,SLOT(space_KBBut_clicked()));
	connect(ui->comma_KBBut,SIGNAL(clicked()),this,SLOT(comma_KBBut_clicked()));
	connect(ui->period_KBBut,SIGNAL(clicked()),this,SLOT(period_KBBut_clicked()));

	connect(ui->enter_KBBut,SIGNAL(clicked()),this,SLOT(enter_KBBut_clicked()));
	connect(ui->backspace_KBBut,SIGNAL(clicked()),this,SLOT(backspace_KBBut_clicked()));
	connect(ui->language_KBBut,SIGNAL(clicked()),this,SLOT(language_KBBut_clicked()));
	connect(ui->shift_KBBut,SIGNAL(clicked()),this,SLOT(on_caps_Bt_clicked()));

	m_LanType = Korean;//English;
	m_Upper = false;
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
	m_pInputEdit->insert(ui->A_KBBut->text());
}
//QString keyboard::A_KBBut_sendData()
//{
//	value = ui->A_KBBut->text();
//	return this->value;
//}

void keyboard::B_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->B_KBBut->text());
}

void keyboard::C_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->C_KBBut->text());
}

void keyboard::D_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->D_KBBut->text());
}

void keyboard::E_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->E_KBBut->text());
}

void keyboard::F_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->F_KBBut->text());
}

void keyboard::G_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->G_KBBut->text());
}

void keyboard::H_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->H_KBBut->text());
}

void keyboard::I_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->I_KBBut->text());
}

void keyboard::J_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->J_KBBut->text());
}

void keyboard::K_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->K_KBBut->text());
}

void keyboard::L_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->L_KBBut->text());
}

void keyboard::M_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->M_KBBut->text());
}

void keyboard::N_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->N_KBBut->text());
}

void keyboard::O_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->O_KBBut->text());
}

void keyboard::P_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->P_KBBut->text());
}

void keyboard::Q_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->Q_KBBut->text());
}

void keyboard::R_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->R_KBBut->text());
}

void keyboard::S_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->S_KBBut->text());
}

void keyboard::T_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->T_KBBut->text());
}

void keyboard::U_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->U_KBBut->text());
}

void keyboard::V_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->V_KBBut->text());
}

void keyboard::W_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->W_KBBut->text());
}

void keyboard::X_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->X_KBBut->text());
}

void keyboard::Y_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->Y_KBBut->text());
}

void keyboard::Z_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->Z_KBBut->text());
}

void keyboard::num1_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->one_KBBut->text());
}

void keyboard::num2_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->two_KBBut->text());
}

void keyboard::num3_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->three_KBBut->text());
}

void keyboard::num4_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->four_KBBut->text());
}

void keyboard::num5_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->five_KBBut->text());
}

void keyboard::num6_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->six_KBBut->text());
}

void keyboard::num7_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->seven_KBBut->text());
}

void keyboard::num8_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->eight_KBBut->text());
}

void keyboard::num9_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->nine_KBBut->text());
}

void keyboard::num0_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->zero_KBBut->text());
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
	m_pInputEdit->insert(ui->comma_KBBut->text());
}

void keyboard::period_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget()); 
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->period_KBBut->text());
}

//切换大小写
void keyboard::on_caps_Bt_clicked()
{
	if ( m_Upper == false )
	{
		switch (m_LanType)
		{

		case 0:  //chinese
		case 7:  //English
		case 1:  //Japanese
		case 3: //Chinese_others
		case 21://Japanese_others

			ui->A_KBBut->setText("A");
			ui->B_KBBut->setText("B");
			ui->C_KBBut->setText("C");
			ui->D_KBBut->setText("D");
			ui->E_KBBut->setText("E");
			ui->F_KBBut->setText("F");
			ui->H_KBBut->setText("H");

			break;
			/*
		case 2:  //Korean
		case 22: //Korean_others
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(">"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("<"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T(""));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("하"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("파"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("타"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("카"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("차"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("자"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("아"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("사"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("바"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("마"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("라"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("다"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("나"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("가"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ㅁ"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("|"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("}"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("{"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ㅖ"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ㅒ"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T(""));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T(""));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T(""));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ㅆ"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ㄲ"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ㄸ"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ㅉ"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ㅃ"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("#"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("@"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("~"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("/"));
				break;
			}
		case 5:  //Arabic
			{
				break;
			}
		case 6:  //Farsi
			{
				break;
			}
		case 8:  //Czech
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ů"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ú"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ˇ"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("É"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("Í"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("Á"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("Ý"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("Ž"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("Ř"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("Č"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("Š"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("Ě"));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("°"));
				break;
			}
		case 9:  //Dutch
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("`"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("±"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T(">"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("|"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("~"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
				break;
			}
		case 10: //German
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ú"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("§"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("^"));
				break;
			}
		case 11:  //Finnish
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("´"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Å"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("`"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("¤"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("½"));
				break;
			}
		case 12:  //Hindi
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("य़"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("।"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ष"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("श"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ळ"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ऴ"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ऩ"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ण"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ँ"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ऎ"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ठ"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("छ"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("थ"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ख"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ऱ"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("फ"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("उ"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("इ"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("अ"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ए"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ओ"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ऑ"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ञ"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ढ"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("झ"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ध"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("घ"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ङ"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("भ"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ऊ"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ई"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("आ"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ऐ"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("औ"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ऋ"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ः"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("श्र"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("क्ष"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("त्र"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ज्ञ"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("र्"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("्र"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ॅ"));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("ऍ"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ऒ"));
				break;
			}
		case 13:  //Hungarian
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Á"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("É"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("Ű"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("Ú"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ő"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("Ó"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("Ü"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("Ö"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
				break;
			}
		case 14:  //Italian
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("°"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ç"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("§"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("é"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("£"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("|"));
				break;
			}
		case 15:  //Portuguese
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(">"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("<"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ç"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("}"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("{"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("`"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("——"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("）"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("（"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("@"));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("\""));
				break;
			}
		case 16:  //Russian
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("."));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("Ю"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("Б"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("Ь"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("Т"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("И"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("М"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("С"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("Ч"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Я"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Э"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ж"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("Д"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("Л"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("О"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("Р"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("П"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("А"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("В"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("Ы"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("Ф"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("Ъ"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Х"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("З"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("Щ"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("Ш"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("Г"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Н"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("Е"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("К"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("У"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("Ц"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Й"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("）"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("№"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("Ё"));
				break;
			}
		case 17:  //Spanish
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("¨"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ñ"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("Ç"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("¿"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("·"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ª"));
				break;
			}
		case 18:  //Swedish
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Å"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("`"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("¤"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("½"));
				break;
			}
		case 19:  //Thai
			{

			}
		case 20:  //Turkish
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T(","));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("Ç"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("Ö"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ş"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("Ü"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("İ"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("Ğ"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("*"));
			}*/

		}
		m_Upper = true;
	}
	else
	{
		btnTextSel(m_LanType);
		m_Upper = false;
	}
	
}

void keyboard::btnTextSel(int inputLanguage)
{
	switch (inputLanguage)
	{

	case 0:  //chinese
	case 1:  //Japanese
	case 3:  //Chinese_others
	case 21: //Japanese_others
		{
			LanEnglish();
		//	pWnd->btnShow();
		//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
	case 2:  //Korean
	case 22: //Korean_others
		{
			LanKorean();
		//	pWnd->btnShow();
		//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
	case 5:  //Arabic
		{
		//	LanArabic1();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 6:  //Farsi
		{
		//	LanArabic1();
	//		pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 7:  //English
		{
			LanEnglish();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 8:  //Czech
		{
		//	LanCzech();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 9:  //Dutch
		{
		//	LanDutch();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 10: //German
		{
		//	LanGerman();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 11:  //Finnish
		{
		//	LanFinnish();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 12:  //Hindi
		{
		//	LanHindi();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 13:  //Hungarian
		{
		//	LanHungarian();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 14:  //Italian
		{
		//	LanItalian();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 15:  //Portuguese
		{
		//	LanPortuguese();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 16:  //Russian
		{
		//	LanRussian();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 17:  //Spanish
		{
		//	LanSpanish();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 18:  //Swedish
		{
		//	LanSwedish();
	//		pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 19:  //Thai
		{
		//	LanThai();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 20:  //Turkish
		{
		//	LanTurkish();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}

	}
}

void keyboard::LanEnglish()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->H_KBBut->setText("h");
	/*
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(";"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("]"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("["));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("`"));
	*/
}

void keyboard::LanKorean()
{
	ui->A_KBBut->setText("ㅁ");
	ui->B_KBBut->setText("ㅠ");
	ui->C_KBBut->setText("ㅊ");
	ui->D_KBBut->setText("ㅇ");
//	ui->E_KBBut->setText("e");
//	ui->F_KBBut->setText("f");
//	ui->H_KBBut->setText("h");


	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ㅡ"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ㅜ"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ㅠ"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ㅍ"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ㅊ"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ㅌ"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ㅋ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(";"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("ㅣ"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ㅏ"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ㅓ"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("ㅗ"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ㅎ"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ㄹ"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("ㅇ"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ㄴ"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ㅁ"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("]"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("["));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ㅔ"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ㅐ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ㅑ"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ㅕ"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ㅛ"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ㅅ"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ㄱ"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ㄷ"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ㅈ"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ㅂ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("`"));*/
}
