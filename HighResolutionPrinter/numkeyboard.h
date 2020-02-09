#ifndef NUMKEYBOARD_H
#define NUMKEYBOARD_H

#include <QWidget>
#include <QLineEdit>
#include "ui_numkeyboard.h"

class lineedit_click;

namespace Ui {
	class numkeyboard;
}

class numkeyboard : public QWidget
{
	Q_OBJECT

public:
	numkeyboard(QWidget *parent = 0);
	~numkeyboard();

private:
	Ui::numkeyboard *ui;

public:
	lineedit_click* m_pNumInputEdit;

public:
	void SetPosition();
	void SetLineEdit(lineedit_click* pInputEdit);


private slots:
	void enter_NumKBBut_clicked();
	void Esc_NumKBBut_clicked();
	void num1_NumKBBut_clicked();
	void num2_NumKBBut_clicked();
	void num3_NumKBBut_clicked();
	void num4_NumKBBut_clicked();
	void num5_NumKBBut_clicked();
	void num6_NumKBBut_clicked();
	void num7_NumKBBut_clicked();
	void num8_NumKBBut_clicked();
	void num9_NumKBBut_clicked();
	void num0_NumKBBut_clicked();
	void period_NumKBBut_clicked();
	void devide_NumKBBut_clicked();
	void multiple_NumKBBut_clicked();
	void minus_NumKBBut_clicked();
	void add_NumKBBut_clicked();
	void backspace_NumKBBut_clicked();

};

#endif // NUMKEYBOARD_H
