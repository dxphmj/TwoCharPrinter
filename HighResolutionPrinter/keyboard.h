#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QMap>
#include <QVector>

class lineedit_click;
class language;

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
	void btnLanguageSel(int m_LanType);
	void btnSymbolSel(int m_LantypeReverse);
	void SetPosition();
	void SetLineEdit(lineedit_click* pInputEdit);
	void setText2KBLineedit();
	void changeCurrentlineedit();

	void LanArabic1();
	void LanArabic2();
	void LanArabic3();
	void LanArabic4();
	void LanArabic5();

	void LanEnglishSmall();
	void LanEnglishBig();
	void LanChineseSmall();
	void LanChineseBig();
	void LanKoreanSmall();
	void LanKoreanBig();
	void LanCzechSmall();
	void LanCzechBig();
	void LanJapaneseSmall();
	void LanJapaneseBig();
	void LanDutchSmall();
	void LanDutchBig();
	void LanGermanSmall();
	void LanGermanBig();
	void LanFarsiSmall();
	void LanFarsiBig();
	void LanHindiSmall();
	void LanHindiBig();

    void SymbolToEnglish();
	void SymbolToChinese();
	void SymbolToKore();
	void SymbolToCzech();
	void SymbolToJapanese();
	void SymbolToDutch();
	void SymbolToGerman();
	void SymbolToFarsi();
	void SymbolToHindi();

	void SymbolToArabic();
	void SymbolToArabic2();
	void SymbolToArabic3();
	void SymbolToArabic4();
	void SymbolToArabic5();
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

public:
	bool m_Upper;
	bool m_symbol;
	lineedit_click* m_pInputEdit;
	language  *languageWidget;
	int i1,j1;
	QMap< QString,QString >ChineseLanMap;//定义map对象
	QMap< QString,QString >JapaneseLanMap;
	QMap< QString,QString >KoreanLanMap;
	QString key;

	enum LanTypeEnum{ Chinese = 0,Japanese=1,Korean=2,Chinese_others=3,
		Others=4,Arabic=5,Farsi=6,English=7,
		Czech=8,Dutch=9,German=10,Finnish=11,
		Hindi=12,Hungarian=13,Italian=14,Portuguese=15,
		Russian=16,Spanish=17,Swedish=18,
		Thai=19,Turkish=20,Japanese_others = 21,Korean_others = 22,Arabic2 = 23,Arabic3 = 24,Arabic4 = 25,Arabic5 = 26};

	enum LantypeReverseEnum{ EnglishSymbol = 0,ChineseSymbol = 1,KoreSymbol = 2,CzechSynbol = 3,JapaneseSymbol = 4,
	                         DutchSymbol = 5,GermanSymbol = 6,FarsiSymbol = 7,ArabicSymbol = 8,Arabic2Symbol = 9,
	                         Arabic3Symbol = 10,Arabic4Symbol = 11,Arabic5Symbol = 12};
	
	int m_LanType;//当前语言种类
	int m_LanTurn;//英语与其他语言转换
	int m_LantypeReverse;//符号种类
	Ui::keyboard* ui;

private:
	//Ui::keyboard* ui;
	QString value;
	QString str;
	QString val;
	//FileEditChild  *showText;

public:
	//QString A_KBBut_sendData();
	void btnhide();
	void btnArabicARhide();
	void CreateChineseMapLan();
	void CreateJapaneseMapLan();
	void CreateKoreanMapLan();
	void FontSelect();
	QVector<QString>splitOut;

public slots:
	void caps1_kBBut_clicked();
	void languagespell();//不是clicked
	void wordComLineEdit_clicked();

private slots:
	void enter_KBBut_clicked();
	void Esc_KBBut_clicked();

	void backspace_KBBut_clicked();
	void language_KBBut_clicked();


	void symbol_KBBut_clicked();


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
	void fontBox1_KBBut_clicked();
	void fontBox2_KBBut_clicked();
	void fontBox3_KBBut_clicked();
	void fontBox4_KBBut_clicked();
	void fontBox5_KBBut_clicked();
	void fontBox6_KBBut_clicked();
	void fontBox7_KBBut_clicked();
	void fontBox8_KBBut_clicked();
	void fontBox9_KBBut_clicked();
	void fontBox10_KBBut_clicked();

	void fontBoxRedu_KBBut_clicked();
	void fontBoxAdd_KBBut_clicked();

	void space_KBBut_clicked();
	void comma_KBBut_clicked();
	void period_KBBut_clicked();
	void lanArabicAdd_KBBut_clicked();
	void lanArabicRedu_KBBut_clicked();
	
public slots:
	void btnshow();
	void btnArabicARshow();
};

#endif // KEYBOARD_H
