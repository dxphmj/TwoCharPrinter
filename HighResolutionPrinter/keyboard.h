#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include "ui_keyboard.h"
#include <QLineEdit>
#include <QString>

class lineedit_click;

class keyboard : public QWidget
{
	Q_OBJECT

public:
	keyboard(QWidget *parent = 0);
	~keyboard();

public:
	bool isCap;
	lineedit_click* m_pInputEdit;

private:
	Ui::keyboard ui;
	QString value;
	QString str;
	QString val;
	//FileEditChild  *showText;

public:
	//QString A_KBBut_sendData();

private slots:
	void enter_KBBut_clicked();
	void backspace_KBBut_clicked();
	void language_KBBut_clicked();
	void on_caps_Bt_clicked();

	void A_KBBut_clicked();
	void B_KBBut_clicked();
	void C_KBBut_clicked();
	void D_KBBut_clicked();
	void E_KBBut_clicked();
	void F_KBBut_clicked();
	void G_KBBut_clicked();
	void H_KBBut_clicked();
	void I_KBBut_clicked();
	void J_KBBut_clicked();
	void K_KBBut_clicked();
	void L_KBBut_clicked();
	void M_KBBut_clicked();
	void N_KBBut_clicked();
	void O_KBBut_clicked();
	void P_KBBut_clicked();
	void Q_KBBut_clicked();
	void R_KBBut_clicked();
	void S_KBBut_clicked();
	void T_KBBut_clicked();
	void U_KBBut_clicked();
	void V_KBBut_clicked();
	void W_KBBut_clicked();
	void X_KBBut_clicked();
	void Y_KBBut_clicked();
	void Z_KBBut_clicked();
	void num1_KBBut_clicked();
	void num2_KBBut_clicked();
	void num3_KBBut_clicked();
	void num4_KBBut_clicked();
	void num5_KBBut_clicked();
	void num6_KBBut_clicked();
	void num7_KBBut_clicked();
	void num8_KBBut_clicked();
	void num9_KBBut_clicked();
	void num0_KBBut_clicked();
	void space_KBBut_clicked();
	void comma_KBBut_clicked();
	void period_KBBut_clicked();
	

};

#endif // KEYBOARD_H
