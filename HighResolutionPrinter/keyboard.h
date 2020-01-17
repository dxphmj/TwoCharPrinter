#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QLineEdit>
#include <QString>

class lineedit_click;

namespace Ui {
	class keyboard;
}

class keyboard : public QWidget
{
	Q_OBJECT

public:
	keyboard(QWidget *parent = 0);
	~keyboard();

public:
	void btnTextSel(int inputLanguage);

	//void LanArabic1();
	//void LanArabic2();
	//void LanArabic3();
	//void LanArabic4();

	void LanEnglish();
	void LanKorean();
	
	//void LanGerman();
	//void LanCzech();
	//void LanDutch();
	//void LanFinnish();
	//void LanHindi();
	//void LanHungarian();
	//void LanItalian();
	//void LanPortuguese();
	//void LanRussian();
	//void LanSpanish();
	//void LanSwedish();
	//void LanThai();
	//void LanTurkish();
	void SymbolR();
public:
	bool m_Upper;
	lineedit_click* m_pInputEdit;
	enum LanTypeEnum{ Chinese = 0,Japanese=1,Korean=2,Chinese_others=3,
		Others=4,Arabic=5,Farsi=6,English=7,
		Czech=8,Dutch=9,German=10,Finnish=11,
		Hindi=12,Hungarian=13,Italian=14,Portuguese=15,
		Russian=16,Spanish=17,Swedish=18,
		Thai=19,Turkish=20,Japanese_others = 21,Korean_others = 22,Symbol = 23};
	
	int m_LanType;//当前语言种类
	int m_LanTurn;//英语与其他语言转换
	int m_LantypeReverse;//语言与符号转换

private:
	Ui::keyboard* ui;
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
	void caps_KBBut_clicked();


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
