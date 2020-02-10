#include "keyboard.h"
#include "ui_keyboard.h"
#include <QAction>
#include <QtWidgets/QStackedWidget>
#include "lineedit_click.h"
#include "language.h"
#include "fileeditchild.h"
#include <QTabWidget>
#include <QHBoxLayout>

keyboard::keyboard(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::keyboard)

{
	ui->setupUi(this);
	languageWidget = new language(this);
	languageWidget->setVisible(false);
	btnhide();
	btnArabicARhide();

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
	connect(ui->languageAdd_KBBut,SIGNAL(clicked()),this,SLOT(lanArabicAdd_KBBut_clicked()));
	connect(ui->languageRedu_KBBut,SIGNAL(clicked()),this,SLOT(lanArabicRedu_KBBut_clicked()));
	connect(ui->fontBox1_KBBut,SIGNAL(clicked()),this,SLOT(fontBox1_KBBut_clicked()));
	connect(ui->fontBox2_KBBut,SIGNAL(clicked()),this,SLOT(fontBox2_KBBut_clicked()));
	connect(ui->fontBox3_KBBut,SIGNAL(clicked()),this,SLOT(fontBox3_KBBut_clicked()));
	connect(ui->fontBox4_KBBut,SIGNAL(clicked()),this,SLOT(fontBox4_KBBut_clicked()));
	connect(ui->fontBox5_KBBut,SIGNAL(clicked()),this,SLOT(fontBox5_KBBut_clicked()));
	connect(ui->fontBox6_KBBut,SIGNAL(clicked()),this,SLOT(fontBox6_KBBut_clicked()));
	connect(ui->fontBox7_KBBut,SIGNAL(clicked()),this,SLOT(fontBox7_KBBut_clicked()));
	connect(ui->fontBox8_KBBut,SIGNAL(clicked()),this,SLOT(fontBox8_KBBut_clicked()));
	connect(ui->fontBox9_KBBut,SIGNAL(clicked()),this,SLOT(fontBox9_KBBut_clicked()));
	connect(ui->fontBox10_KBBut,SIGNAL(clicked()),this,SLOT(fontBox10_KBBut_clicked()));
	connect(ui->fontBoxRedu_KBBut,SIGNAL(clicked()),this,SLOT(fontBoxRedu_KBBut_clicked()));
	connect(ui->fontBoxAdd_KBBut,SIGNAL(clicked()),this,SLOT(fontBoxAdd_KBBut_clicked()));


	connect(ui->enter_KBBut,SIGNAL(clicked()),this,SLOT(enter_KBBut_clicked()));
	connect(ui->Esc_KBBut,SIGNAL(clicked()),this,SLOT(Esc_KBBut_clicked()));
	connect(ui->backspace_KBBut,SIGNAL(clicked()),this,SLOT(backspace_KBBut_clicked()));
	connect(ui->language_KBBut,SIGNAL(clicked()),this,SLOT(language_KBBut_clicked()));
	//connect(ui->shift_KBBut,SIGNAL(clicked()),this,SLOT(caps_KBBut_clicked()));
	connect(ui->shift_KBBut,SIGNAL(clicked()),this,SLOT(caps1_kBBut_clicked()));
	connect(ui->symbol_KBBut,SIGNAL(clicked()),this,SLOT(symbol_KBBut_clicked()));
	//connect(ui->wordCombLineEdit,SIGNAL(textChanged()),this,SLOT(languagespell()));
	//connect(ui->wordCombLineEdit,SIGNAL(textChanged()),this,SLOT(languagespell()));
	connect(ui->wordCombLineEdit,SIGNAL(textChanged(QString)),this,SLOT(languagespell()));
	

	m_LanType = English;
	m_Upper = false;
	m_LantypeReverse = EnglishSymbol;
	m_symbol = true;
}

keyboard::~keyboard()
{
	
}

void keyboard::SetLineEdit(lineedit_click* pInputEdit)
{
	m_pInputEdit = pInputEdit;
	SetPosition();
	setVisible(true);
}

void keyboard::SetPosition()
{
	QRect rectLineEdit;
	rectLineEdit = m_pInputEdit->geometry();
	QRect rectKeyboard;
	rectKeyboard = geometry();
	QRect rect(rectLineEdit.left(),rectLineEdit.bottom()+50,rectKeyboard.width(),rectKeyboard.height());
	setGeometry(rect);
}

void keyboard::enter_KBBut_clicked()
{
	this->setVisible(false);
}

void keyboard::Esc_KBBut_clicked()
{
	this->setVisible(false);
}

void keyboard::backspace_KBBut_clicked()
{
	setText2KBLineedit();
	if (m_pInputEdit->text() != "")
	{
		m_pInputEdit->backspace();
	} 
	else
	{
		changeCurrentlineedit();
	    m_pInputEdit->backspace();
	}
	setText2KBLineedit();
}

void keyboard::language_KBBut_clicked()
{
	languageWidget->setVisible(true);
}

void keyboard::btnhide()
{
	ui->fontBox1_KBBut->hide();
	ui->fontBox2_KBBut->hide();
	ui->fontBox3_KBBut->hide();
	ui->fontBox4_KBBut->hide();
	ui->fontBox5_KBBut->hide();
	ui->fontBox6_KBBut->hide();
	ui->fontBox7_KBBut->hide();
	ui->fontBox8_KBBut->hide();
	ui->fontBox9_KBBut->hide();
	ui->fontBox10_KBBut->hide();
	ui->fontBoxRedu_KBBut->hide();
	ui->fontBoxAdd_KBBut->hide();
	ui->wordCombLineEdit->hide();
}

void keyboard::btnArabicARhide()
{
	ui->languageAdd_KBBut->hide();
	ui->languageRedu_KBBut->hide();
}

void keyboard::setText2KBLineedit()
{
	m_pInputEdit = ui->wordCombLineEdit;
}


void keyboard::changeCurrentlineedit()
{
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(this->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->wordLineEdit_clicked();
}

void keyboard::languagespell()   //»ñÈ¡ÖÐÎÄ±à¼­¿òÄÚµÄÆ´Òô ½«¶ÔÓ¦µÄºº×ÖÖÃÈë±¸Ñ¡¿òÖÐ
{
	switch (m_LanType)
	{
	case 0: //chinese
		{	
			QString key = m_pInputEdit->text();
			CreateChineseMapLan();
			QString value = ChineseLanMap[key];
			if ( value == "" )          
			{	
                        splitOut.clear();
              		i1 = 0;
				j1 = 0;
				QString Delstr = (QStringLiteral(" , , , , , , , , , , , , , , ,"));
				QStringList temp = Delstr.split(",");
				int length = temp.length();

				for ( int i =0 ;i < length;i++)
				{
					splitOut.push_back(temp.at(i));
				} 
				FontSelect();
				splitOut.clear();
			}
			else
			{
				j1 = 0;
				//value +=QStringLiteral(",");
				//splitOut = split(value);
				QStringList temp = value.split(",");//ÒÔ¶ººÅ·Ö¸î×Ö·û´®£¬½«±¸Ñ¡µÄÃ¿¸öºº×Öµ¥¶À·Ö¸î³ÉÒ»¸ö×Ö·û´®
				int length = temp.length();//¶ÁÈ¡·Ö¸îºóµÄ×Ö·û´®¸öÊý

				for ( int i =0 ;i < length;i++)//±éÀú£¬½«Ã¿Ò»¸ö×Ö·û´®ÖÃÈëµ½vector¶ÔÓ¦µÄÎ»ÖÃ
				{
					splitOut.push_back(temp.at(i));
				} 
				if ( splitOut.size() < 11 )
				{
					i1 = 1;
				} 
				else if( splitOut.size() <21)
				{
					i1 = 11;
				}
				else if( splitOut.size() < 31)
				{
					i1 = 21;
				}
				else
				{
					i1 = 31;
				}
				FontSelect();
				//break;
			}
			break;
		}
	case 1: //Japanese
		{	
			QString key = m_pInputEdit->text();
			CreateJapaneseMapLan();
			QString value = JapaneseLanMap[key];
			if ( value == "" )          
			{	
                        splitOut.clear();
              		i1 = 0;
				j1 = 0;
				QString Delstr = (QStringLiteral(" , , , , , , , , , , , , , , ,"));
				QStringList temp = Delstr.split(",");
				int length = temp.length();

				for ( int i =0 ;i < length;i++)
				{
					splitOut.push_back(temp.at(i));
				} 
				FontSelect();
				splitOut.clear();
			}
			else
			{
				j1 = 0;
				//value +=QStringLiteral(",");
				//splitOut = split(value);
				QStringList temp = value.split(",");//ÒÔ¶ººÅ·Ö¸î×Ö·û´®£¬½«±¸Ñ¡µÄÃ¿¸öºº×Öµ¥¶À·Ö¸î³ÉÒ»¸ö×Ö·û´®
				int length = temp.length();//¶ÁÈ¡·Ö¸îºóµÄ×Ö·û´®¸öÊý

				for ( int i =0 ;i < length;i++)//±éÀú£¬½«Ã¿Ò»¸ö×Ö·û´®ÖÃÈëµ½vector¶ÔÓ¦µÄÎ»ÖÃ
				{
					splitOut.push_back(temp.at(i));
				} 
				if ( splitOut.size() < 11 )
				{
					i1 = 1;
				} 
				else if( splitOut.size() <21)
				{
					i1 = 11;
				}
				else if( splitOut.size() < 31)
				{
					i1 = 21;
				}
				else
				{
					i1 = 31;
				}
				FontSelect();
				//break;
			}
			break;
		}
	case 22: //Korean
		{	
			QString key = m_pInputEdit->text();
			CreateKoreanMapLan();
			QString value = KoreanLanMap[key];
			if ( value == "" )          
			{	
                        splitOut.clear();
              		i1 = 0;
				j1 = 0;
				QString Delstr = (QStringLiteral(" , , , , , , , , , , , , , , ,"));
				QStringList temp = Delstr.split(",");
				int length = temp.length();

				for ( int i =0 ;i < length;i++)
				{
					splitOut.push_back(temp.at(i));
				} 
				FontSelect();
				splitOut.clear();
			}
			else
			{
				j1 = 0;
				//value +=QStringLiteral(",");
				//splitOut = split(value);
				QStringList temp = value.split(",");//ÒÔ¶ººÅ·Ö¸î×Ö·û´®£¬½«±¸Ñ¡µÄÃ¿¸öºº×Öµ¥¶À·Ö¸î³ÉÒ»¸ö×Ö·û´®
				int length = temp.length();//¶ÁÈ¡·Ö¸îºóµÄ×Ö·û´®¸öÊý

				for ( int i =0 ;i < length;i++)//±éÀú£¬½«Ã¿Ò»¸ö×Ö·û´®ÖÃÈëµ½vector¶ÔÓ¦µÄÎ»ÖÃ
				{
					splitOut.push_back(temp.at(i));
				} 
				if ( splitOut.size() < 11 )
				{
					i1 = 1;
				} 
				else if( splitOut.size() <21)
				{
					i1 = 11;
				}
				else if( splitOut.size() < 31)
				{
					i1 = 21;
				}
				else
				{
					i1 = 31;
				}
				FontSelect();
				//break;
			}
			break;
		}

	}
}

void keyboard::CreateChineseMapLan()//ÖÐÎÄ×Ö¿â

{
	ChineseLanMap[QStringLiteral("an")] = QStringLiteral("°²,°±,°°,°³,°¶,°´,°¸,°·,°µ, , , , , , ");
	ChineseLanMap[QStringLiteral("ai")] = QStringLiteral("°¥,°§,°¦,°£,°¤,°¨,°©,°«,°ª,°¬,°®,°¯,°­, , ");
	ChineseLanMap[QStringLiteral("a")] = QStringLiteral("°¢,°¡, , , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("yi")] = QStringLiteral("Ò»,ÒÁ,ÒÂ,Ò½,ÒÀ,Ò¿,Ò¼,Ò¾,ÒÇ,ÒÄ,ÒÊ,ÒË,ÒÌ,ÒÈ,ÒÆ,ÒÅ,ÒÃ,ÒÉ,ÒÍ,ÒÒ,ÒÑ,ÒÔ,ÒÓ,ÒÏ,ÒÐ,ÒÎ,Òå,ÒÚ,Òä,ÒÕ,Òé,Òà,ÒÙ,Òì,ÒÛ,ÒÖ,Òë,ÒØ,Ò×,Òï,Òè,Òß,Òæ,Òê,Òî,ÒÝ,Òâ,Òç,ÒÞ,Òá,Òã,Òí,ÒÜ, , , , , , , , , ");
	ChineseLanMap[QStringLiteral("ang")] = QStringLiteral("°¹,°º,°», , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("ao")] = QStringLiteral("°¼,°½,°¾,°¿,°À,°Á,°Â,°Ä,°Ã, , , , , , ");
	ChineseLanMap[QStringLiteral("ba")] = QStringLiteral("°Ë,°Í,°È,°Ç,°É,°Ì,°Æ,°Ê,°Î,°Ï,°Ñ,°Ð,°Ó,°Ö,°Õ,°Ô, , , , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bai")] = QStringLiteral("°×,°Ù,°Û,°Ø,°Ú,°Ü,°Ý,°Þ, , , , , , , ");
	ChineseLanMap[QStringLiteral("ban")] = QStringLiteral("°â,°à,°ã,°ä,°ß,°á,°å,°æ,°ì,°ë,°é,°ç,°è,°í,°ê");
	ChineseLanMap[QStringLiteral("bang")] = QStringLiteral("°î,°ï,°ð,°ó,°ñ,°ò,°ö,°ø,°ô,°ù,°õ,°÷, , , ");
	ChineseLanMap[QStringLiteral("bao")] = QStringLiteral("°ü,°ú,°û,°ý,±¢,±¦,±¥,±£,±¤,±¨,±§,±ª,±«,±©,±¬,°þ,±¡,ÆÙ, , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bei")] = QStringLiteral("±°,±­,±¯,±®,±±,±´,±·,±¸,±³,±µ,±¶,±»,±¹,±º,±²");
	ChineseLanMap[QStringLiteral("ben")] = QStringLiteral("±¼,±¾,±½,±¿,º», , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("beng")] = QStringLiteral("±À,±Á,±Â,±Ã,±Å,±Ä, , , , , , , , ,");

	ChineseLanMap[QStringLiteral("bi")] = QStringLiteral("±Æ,±Ç,±È,±Ë,±Ê,±É,±Ò,±Ø,±Ï,±Õ,±Ó,±Ñ,±Ý,±Ð,±Ö,±Ô,±Í,±×,±Ì,±Î,±Ú,±Ü,±Û, , , , , , , ");
	ChineseLanMap[QStringLiteral("bian")] = QStringLiteral("±ß,±à,±Þ,±á,±â,±å,±ã,±ä,±é,±æ,±ç,±è, , , ");
	ChineseLanMap[QStringLiteral("biao")] = QStringLiteral("±ë,±ê,±ì,±í, , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bie")] = QStringLiteral("±ï,±î,±ð,±ñ, , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bin")] = QStringLiteral("±ö,±ò,±ó,±õ,±ô,±÷, , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bing")] = QStringLiteral("±ù,±ø,±û,±ü,±ú,±þ,±ý,²¢,²¡, , , , , , ");
	ChineseLanMap[QStringLiteral("bo")] = QStringLiteral("²¦,²¨,²£,²§,²±,²¤,²¥,²®,²µ,²¯,²´,²ª,²¬,²°,²©,²³,²«,²­,²²,²·, , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bu")] = QStringLiteral("²¹,²¸,²¶,²»,²¼,²½,²À,²¿,²º,²¾, , , , , ");
	ChineseLanMap[QStringLiteral("ca")] = QStringLiteral("²Á, , , , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("cai")] = QStringLiteral("²Â,²Å,²Ä,²Æ,²Ã,²É,²Ê,²Ç,²È,²Ë,²Ì, , , , ");
	ChineseLanMap[QStringLiteral("can")] = QStringLiteral("²Î,²Í,²Ð,²Ï,²Ñ,²Ò,²Ó, , , , , , , , ");
	ChineseLanMap[QStringLiteral("cang")] = QStringLiteral("²Ö,²×,²Ô,²Õ,²Ø, , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("cao")] = QStringLiteral("²Ù,²Ú,²Ü,²Û,²Ý, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ce")] = QStringLiteral("²á,²à,²Þ,²â,²ß, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ceng")] = QStringLiteral("²ã,²ä,Ôø, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cha")] = QStringLiteral("²æ,²å,²é,²ç,²è,²ë,²ì,²ê,²í,²ï,²î,É², , , ");


	ChineseLanMap[QStringLiteral("chai")] = QStringLiteral("²ð,²ñ,²ò, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chan")] = QStringLiteral("²ô,²ó,²÷,²ö,²ø,²õ,²ú,²ù,²û,²ü, , , , , ");


	ChineseLanMap[QStringLiteral("chang")] = QStringLiteral("²ý,²þ,³¦,³¢,³¥,³£,³§,³¡,³¨,³©,³«,³ª, , , ");


	ChineseLanMap[QStringLiteral("chao")] = QStringLiteral("³­,³®,³¬,³²,³¯,³°,³±,³³,³´,´Â, , , , , ");


	ChineseLanMap[QStringLiteral("che")] = QStringLiteral("³µ,³¶,³¹,³¸,³·,³º, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chen")] = QStringLiteral("³»,³¾,³¼,³À,³Á,³½,³Â,³¿,³Ä,³Ã, , , , , ");


	ChineseLanMap[QStringLiteral("cheng")] = QStringLiteral("³Æ,³Å,³É,³Ê,³Ð,³Ï,³Ç,³Ë,³Í,³Ì,³Î,³È,³Ñ,³Ò,³Ó");


	ChineseLanMap[QStringLiteral("chi")] = QStringLiteral("³Ô,³Õ,³Ú,³Ø,³Û,³Ù,³Ö,³ß,³Þ,³Ý,³Ü,³â,³à,³ã,³á");


	ChineseLanMap[QStringLiteral("chong")] = QStringLiteral("³ä,³å,³æ,³ç,³è, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chou")] = QStringLiteral("³é,³ð,³ñ,³ë,³î,³í,³ï,³ê,³ì,³ó,³ò,³ô, , , ");


	ChineseLanMap[QStringLiteral("chu")] = QStringLiteral("³ö,³õ,³ý,³ø,³ü,³ú,³û,³÷,³ù,´¡,´¢,³þ,´¦,´¤,´¥,´£,Ðó, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuai")] = QStringLiteral("´§, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuan")] = QStringLiteral("´¨,´©,´«,´¬,´ª,´­,´®, , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuang")] = QStringLiteral("´³,´¯,´°,´²,´´, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chun")] = QStringLiteral("´º,´»,´¿,´½,´¾,´¼,´À, , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuo")] = QStringLiteral("´Á, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ci")] = QStringLiteral("´Ã,´Ê,´Ä,´É,´È,´Ç,´Å,´Æ,´Ë,´Î,´Ì,´Í, , , ");


	ChineseLanMap[QStringLiteral("cong")] = QStringLiteral("´Ñ,´Ó,´Ò,´Ð,´Ï,´Ô, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cou")] = QStringLiteral("´Õ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cu")] = QStringLiteral("´Ö,´Ù,´×,´Ø, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cuan")] = QStringLiteral("´Ú,´Ü,´Û, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cui")] = QStringLiteral("´Þ,´ß,´Ý,´à,´ã,´á,´â,´ä, , , , , , , ");


	ChineseLanMap[QStringLiteral("cun")] = QStringLiteral("´å,´æ,´ç, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cuo")] = QStringLiteral("´ê,´è,´é,´ì,´ë,´í, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("da")] = QStringLiteral("´î,´ï,´ð,´ñ,´ò,´ó, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dai")] = QStringLiteral("´ô,´õ,´ö,´ú,´ø,´ý,µ¡,´ù,´û,´ü,´þ,´÷, , , ");


	ChineseLanMap[QStringLiteral("dan")] = QStringLiteral("µ¤,µ¥,µ£,µ¢,µ¦,µ¨,µ§,µ©,µ«,µ®,µ¯,µ¬,µ­,µ°,µª");


	ChineseLanMap[QStringLiteral("dang")] = QStringLiteral("µ±,µ²,µ³,µ´,µµ, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dao")] = QStringLiteral("µ¶,µ¼,µº,µ¹,µ·,µ»,µ¸,µ½,µ¿,µÁ,µÀ,µ¾, , , ");


	ChineseLanMap[QStringLiteral("de")] = QStringLiteral("µÃ,µÂ,µÄ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("deng")] = QStringLiteral("µÆ,µÇ,µÅ,µÈ,µË,µÊ,µÉ, , , , , , , , ");


	ChineseLanMap[QStringLiteral("di")] = QStringLiteral("µÍ,µÌ,µÎ,µÒ,µÏ,µÐ,µÓ,µÑ,µÕ,µ×,µÖ,µØ,µÜ,µÛ,µÝ,µÚ,µÞ,µÙ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dian")] = QStringLiteral("µà,µá,µß,µä,µã,µâ,µç,µè,µé,µê,µæ,µë,µí,µì,µî,µå, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("diao")] = QStringLiteral("µó,µð,µò,µï,µñ,µõ,µö,µô, , , , , , , ");


	ChineseLanMap[QStringLiteral("die")] = QStringLiteral("µù,µø,µü,µý,µþ,µú,µû, , , , , , , , ");


	ChineseLanMap[QStringLiteral("ding")] = QStringLiteral("¶¡,¶£,¶¢,¶¤,¶¥,¶¦,¶©,¶¨,¶§, , , , , , ");


	ChineseLanMap[QStringLiteral("diu")] = QStringLiteral("¶ª, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dong")] = QStringLiteral("¶«,¶¬,¶­,¶®,¶¯,¶³,¶±,¶²,¶°,¶´, , , , , ");


	ChineseLanMap[QStringLiteral("dou")] = QStringLiteral("¶¼,¶µ ,¶·,¶¶,¶¸,¶¹,¶º,¶», , , , , , , ");


	ChineseLanMap[QStringLiteral("du")] = QStringLiteral("¶½,¶¾,¶Á,¶¿,¶À,¶Â,¶Ä,¶Ã,¶Ê,¶Å,¶Ç,¶È,¶É,¶Æ, ");


	ChineseLanMap[QStringLiteral("duan")] = QStringLiteral("¶Ë,¶Ì,¶Î,¶Ï,¶Ð,¶Í, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dui")] = QStringLiteral("¶Ñ,¶Ó,¶Ô,¶Ò, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dun")] = QStringLiteral("¶Ö,¶Ø,¶Õ,¶×,¶Ü,¶Û,¶Ù,¶Ý, , , , , , , ");


	ChineseLanMap[QStringLiteral("duo")] = QStringLiteral("¶à,¶ß,¶á,¶Þ,¶ä,¶â,¶ã,¶ç,¶é,¶æ,¶è,¶å, , , ");


	ChineseLanMap[QStringLiteral("e")] = QStringLiteral("¶ï,¶í,¶ð,¶ë,¶ì,¶ê,¶î,¶ò,¶ó,¶ñ,¶ö,¶õ,¶ô, , ");


	ChineseLanMap[QStringLiteral("en")] = QStringLiteral("¶÷, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("er")] = QStringLiteral("¶ù,¶ø,¶û,¶ú,¶ý,¶ü,¶þ,·¡, , , , , , , ");


	ChineseLanMap[QStringLiteral("fa")] = QStringLiteral("·¢,·¦,·¥,·£,·§,·¤,·¨,·©, , , , , , , ");



	ChineseLanMap[QStringLiteral("fan")] = QStringLiteral("·«,·¬,·­,·ª,·²,·¯,·°,·³,·®,·±,·´,·µ,·¸,·º,·¹,·¶,··, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("fang")] = QStringLiteral("·½,·»,·¼,·À,·Á,·¿,·¾,·Â,·Ã,·Ä,·Å, , , , ");


	ChineseLanMap[QStringLiteral("fei")] = QStringLiteral("·É,·Ç,·È,·Æ,·Ê,·Ë,·Ì,·Í,·Ï,·Ð,·Î,·Ñ, , , ");


	ChineseLanMap[QStringLiteral("fen")] = QStringLiteral("·Ö,·Ô,·×,·Ò,·Õ,·Ó,·Ø,·Ú,·Ù,·Û,·Ý,·Ü,·Þ,·ß,·à");


	ChineseLanMap[QStringLiteral("feng")] = QStringLiteral("·á,·ç,·ã,·â,·è,·å,·é,·æ,·ä,·ë,·ê,·ì,·í,·ï,·î");


	ChineseLanMap[QStringLiteral("fo")] = QStringLiteral("·ð, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("fou")] = QStringLiteral("·ñ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("fu")] = QStringLiteral("·ò,·ô,·õ,·ó,¸¥,·ü,·ö,·÷,·þ,·ý,·ú,¸¡,¸¢,·û,¸¤,·ù,¸£,·ø,¸§,¸¦,¸®,¸«,¸©,¸ª,¸¨,¸­,¸¯,¸¸,¸¼,¸¶,¸¾,¸º,¸½,¸À,¸·,¸´,¸°,¸±,¸µ,¸»,¸³,¸¿,¸¹,¸², ");


	ChineseLanMap[QStringLiteral("ga")] = QStringLiteral("¸Â,¸Á, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gai")] = QStringLiteral("¸Ã,¸Ä,¸Æ,¸Ç,¸È,¸Å, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gan")] = QStringLiteral("¸É,¸Ê,¸Ë,¸Î,¸Ì,¸Í,¸Ñ,¸Ï,¸Ò,¸Ð,¸Ó, , , , ");


	ChineseLanMap[QStringLiteral("gang")] = QStringLiteral("¸Ô,¸Õ,¸Ú,¸Ù,¸Ø,¸×,¸Ö,¸Û,¸Ü, , , , , , ");


	ChineseLanMap[QStringLiteral("gao")] = QStringLiteral("¸Þ,¸á,¸ß,¸à,¸Ý,¸â,¸ã,¸å,¸ä,¸æ, , , , , ");


	ChineseLanMap[QStringLiteral("ge")] = QStringLiteral("¸ê,¸í,¸ç,¸ì,¸ë,¸î,¸é,¸è,¸ó,¸ï,¸ñ,¸ð,¸ô,¸ö,¸÷,¸õ,¿©, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gei")] = QStringLiteral("¸ø, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gen")] = QStringLiteral("¸ù,¸ú, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("geng")] = QStringLiteral("¸ü,¸ý,¸û,¸þ,¹¡,¹¢,¹£, , , , , , , , ");


	ChineseLanMap[QStringLiteral("gong")] = QStringLiteral("¹¤,¹­,¹«,¹¦,¹¥,¹©,¹¬,¹§,¹ª,¹¨,¹®,¹¯,¹°,¹²,¹±");


	ChineseLanMap[QStringLiteral("gou")] = QStringLiteral("¹´,¹µ,¹³,¹·,¹¶,¹¹,¹º,¹¸,¹», , , , , , ");


	ChineseLanMap[QStringLiteral("gu")] = QStringLiteral("¹À,¹¾,¹Ã,¹Â,¹Á,¹½,¹¼,¹¿,¹Å,¹È,¹É,¹Ç,¹Æ,¹Ä,¹Ì,¹Ê,¹Ë,¹Í, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gua")] = QStringLiteral("¹Ï,¹Î,¹Ð,¹Ñ,¹Ò,¹Ó, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("guai")] = QStringLiteral("¹Ô,¹Õ,¹Ö, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("guan")] = QStringLiteral("¹Ø,¹Û,¹Ù,¹Ú,¹×,¹Ý,¹Ü,¹á,¹ß,¹à,¹Þ, , , , ");


	ChineseLanMap[QStringLiteral("guang")] = QStringLiteral("¹â,¹ã,¹ä, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gui")] = QStringLiteral("¹é,¹ç,¹ê,¹æ,¹ë,¹è,¹å,¹ì,¹î,¹ï,¹í,¹ô,¹ñ,¹ó,¹ð,¹ò, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gun")] = QStringLiteral("¹õ,¹ö,¹÷, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("guo")] = QStringLiteral("¹ù,¹ø,¹ú,¹û,¹ü,¹ý, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ha")] = QStringLiteral("¸ò,¹þ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hai")] = QStringLiteral("º¢,º¡,º£,º¥,º§,º¦,º¤, , , , , , , , ");


	ChineseLanMap[QStringLiteral("han")] = QStringLiteral("º¨,º©,º¬,ºª,º¯,º­,º®,º«,º±,º°,ºº,º¹,ºµ,º·,º´,º¸,º¶,º³,º², , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hang")] = QStringLiteral("º¼,º½,ÐÐ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hao")] = QStringLiteral("ºÁ,ºÀ,º¿,º¾,ºÃ,ºÂ,ºÅ,ºÆ,ºÄ, , , , , , ");


	ChineseLanMap[QStringLiteral("he")] = QStringLiteral("ºÇ,ºÈ,ºÌ,ºÏ,ºÎ,ºÍ,ºÓ,ºÒ,ºË,ºÉ,ºÔ,ºÐ,ºÊ,ºØ,ºÖ,ºÕ,º×, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hei")] = QStringLiteral("ºÚ,ºÙ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hen")] = QStringLiteral("ºÛ,ºÜ,ºÝ,ºÞ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("heng")] = QStringLiteral("ºà,ºß,ºã,ºá,ºâ, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hong")] = QStringLiteral("ºä,ºå,ºæ,ºë,ºì,ºê,ºé,ºç,ºè, , , , , , ");


	ChineseLanMap[QStringLiteral("hou")] = QStringLiteral("ºî,ºí,ºï,ºð,ºó,ºñ,ºò, , , , , , , , ");


	ChineseLanMap[QStringLiteral("hu")] = QStringLiteral("ºõ,ºô,ºö,»¡,ºü,ºú,ºø,ºþ,ºù,º÷,ºý,ºû,»¢,»£,»¥,»§,»¤,»¦, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hua")] = QStringLiteral("»¨,»ª,»©,»¬,»«,»¯,»®,»­,»°, , , , , , ");


	ChineseLanMap[QStringLiteral("huai")] = QStringLiteral("»³,»²,»´,»±,»µ, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("huan")] = QStringLiteral("»¶,»¹,»·,»¸,»º,»Ã,»Â,»½,»»,»Á,»¼,»À,»¾,»¿, ");


	ChineseLanMap[QStringLiteral("huang")] = QStringLiteral("»Ä,»Å,»Ê,»Ë,»Æ,»Ì,»Í,»È,»Ç,»É,»Ð,»Î,»Ñ,»Ï, ");


	ChineseLanMap[QStringLiteral("hui")] = QStringLiteral("»Ò,»Ö,»Ó,»Ô,»Õ,»Ø,»×,»Ú,»Ü,»ã,»á,»ä,»æ,»å,»â,»ß,»Þ,»à,»Ý,»Ù,»Û, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hun")] = QStringLiteral("»è,»ç,»é,»ë,»ê,»ì, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("huo")] = QStringLiteral("»í,»î,»ð,»ï,»ò,»õ,»ñ,»ö,»ó,»ô, , , , , ");


	ChineseLanMap[QStringLiteral("ji")] = QStringLiteral("¼¥,»÷,¼¢,»ø,»ú,¼¡,¼¦,¼£,¼§,»ý,»ù,¼¨,¼©,»û,»þ,»ü,¼¤,¼°,¼ª,¼³,¼¶,¼´,¼«,¼±,¼²,¼¬,¼¯,¼µ,¼­,¼®,¼¸,¼º,¼·,¼¹,¼Æ,¼Ç,¼¿,¼Í,¼Ë,¼É,¼¼,¼Ê,¼Á,¼¾,¼È,¼Ã,¼Ì,¼Å,¼Ä,¼Â,¼À,¼»,¼½,½å, , , , , , ");


	ChineseLanMap[QStringLiteral("jia")] = QStringLiteral("¼Ó,¼Ð,¼Ñ,¼Ï,¼Ò,¼Î,¼Ô,¼Õ,¼×,¼Ö,¼Ø,¼Û,¼Ý,¼Ü,¼Ù,¼Þ,¼Ú,Ð®, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("jian")] = QStringLiteral("¼é,¼â,¼á,¼ß,¼ä,¼ç,¼è,¼æ,¼à,¼ã,¼ê,¼å,¼ð,¼ó,¼í,¼ë,¼ñ,¼õ,¼ô,¼ì,¼ï,¼ò,¼î,¼û,¼þ,½¨,½¤,½£,¼ö,¼ú,½¡,½§,½¢,½¥,½¦,¼ù,¼ø,¼ü,¼ý, , , , , , ");


	ChineseLanMap[QStringLiteral("jiang")] = QStringLiteral("½­,½ª,½«,½¬,½©,½®,½²,½±,½°,½¯,½³,½µ,½´, , ");


	ChineseLanMap[QStringLiteral("jiao")] = QStringLiteral("½»,½¼,½¿,½½,½¾,½º,½·,½¹,½¶,½¸,½Ç,½Æ,½Ê,½È,½Ã,½Å,½Â,½Á,½Ë,½É,½Ð,½Î,½Ï,½Ì,½Ñ,½Í,¾õ,½À, , ");


	ChineseLanMap[QStringLiteral("jie")] = QStringLiteral("½×,½Ô,½Ó,½Õ,½Ò,½Ö,½Ú,½Ù,½Ü,½à,½á,½Ý,½Þ,½Ø,½ß,½ã,½â,½é,½ä,½æ,½ì,½ç,½ê,½ë,½è, , , , , ");


	ChineseLanMap[QStringLiteral("jin")] = QStringLiteral("½í,½ñ,½ï,½ð,½ò,½î,½ó,½ö,½ô,½÷,½õ,¾¡,¾¢,½ü,½ø,½ú,½þ,½ý,½û,½ù, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("jing")] = QStringLiteral("¾©,¾­,¾¥,¾£,¾ª,¾§,¾¦,¾¬,¾¤,¾«,¾¨,¾®,¾±,¾°,¾¯,¾»,¾¶,¾·,¾º,¾¹,¾´,¾¸,¾³,¾²,¾µ, , , , , ");


	ChineseLanMap[QStringLiteral("jiong")] = QStringLiteral("¾¼,¾½, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("jiu")] = QStringLiteral("¾À,¾¿,¾¾,¾Å,¾Ã,¾Ä,¾Á,¾Â,¾Æ,¾É,¾Ê,¾Ì,¾Î,¾Ç,¾È,¾Í,¾Ë, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ju")] = QStringLiteral("¾Ó,¾Ð,¾Ñ,¾Ô,¾Ò,¾Ï,¾Ö,½Û,¾Õ,¾×,¾Ú,¾Ù,¾Ø,¾ä,¾Þ,¾Ü,¾ß,¾æ,¾ã,¾ç,¾å,¾Ý,¾à,¾â,¾Û,¾á, , , , ");


	ChineseLanMap[QStringLiteral("juan")] = QStringLiteral("¾ê,¾è,¾é,¾í,¾ë,¾î,¾ì, , , , , , , , ");


	ChineseLanMap[QStringLiteral("jue")] = QStringLiteral("¾ï,¾ö,¾÷,¾ñ,¾ø,¾ó,¾ò,¾ô,¾ð, , , , , , ");


	ChineseLanMap[QStringLiteral("jun")] = QStringLiteral("¾ü,¾ý,¾ù,¾û,¾ú,¿¡,¿¤,¾þ,¿£,¿¥,¿¢, , , , ");


	ChineseLanMap[QStringLiteral("ka")] = QStringLiteral("¿§,¿¦,¿¨, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kai")] = QStringLiteral("¿ª,¿«,¿­,¿®,¿¬, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kan")] = QStringLiteral("¼÷,¿¯,¿±,¿°,¿²,¿³,¿´, , , , , , , , ");


	ChineseLanMap[QStringLiteral("kang")] = QStringLiteral("¿µ,¿¶,¿·,¿¸,¿º,¿¹,¿», , , , , , , , ");


	ChineseLanMap[QStringLiteral("kao")] = QStringLiteral("¿¼,¿½,¿¾,¿¿, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ke")] = QStringLiteral("¿À,¿Á,¿Â,¿Æ,¿Ã,¿Å,¿Ä,¿Ç,¿È,¿É,¿Ê,¿Ë,¿Ì,¿Í,¿Î");


	ChineseLanMap[QStringLiteral("ken")] = QStringLiteral("¿Ï,¿Ñ,¿Ò,¿Ð, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("keng")] = QStringLiteral("¿Ô,¿Ó, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kong")] = QStringLiteral("¿Õ,¿×,¿Ö,¿Ø, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kou")] = QStringLiteral("¿Ù,¿Ú,¿Û,¿Ü, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ku")] = QStringLiteral("¿Ý,¿Þ,¿ß,¿à,¿â,¿ã,¿á, , , , , , , , ");


	ChineseLanMap[QStringLiteral("kua")] = QStringLiteral("¿ä,¿å,¿æ,¿è,¿ç, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuai")] = QStringLiteral("¿é,¿ì,¿ë,¿ê, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuan")] = QStringLiteral("¿í,¿î, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuang")] = QStringLiteral("¿ï,¿ð,¿ñ,¿ö,¿õ,¿ó,¿ò,¿ô, , , , , , , ");


	ChineseLanMap[QStringLiteral("kui")] = QStringLiteral("¿÷,¿ù,¿ø,¿ú,¿ü,¿û,¿ý,¿þ,À¢,À£,À¡, , , , ");


	ChineseLanMap[QStringLiteral("kun")] = QStringLiteral("À¤,À¥,À¦,À§, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuo")] = QStringLiteral("À©,À¨,À«,Àª, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("la")] = QStringLiteral("À¬,À­,À²,À®,À°,À¯,À±, , , , , , , , ");


	ChineseLanMap[QStringLiteral("lai")] = QStringLiteral("À´,À³,Àµ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lan")] = QStringLiteral("À¼,À¹,À¸,À·,À»,À¶,À¾,À½,Àº,ÀÀ,À¿,ÀÂ,ÀÁ,ÀÃ,ÀÄ");


	ChineseLanMap[QStringLiteral("lang")] = QStringLiteral("ÀÉ,ÀÇ,ÀÈ,ÀÅ,ÀÆ,ÀÊ,ÀË, , , , , , , , ");


	ChineseLanMap[QStringLiteral("lao")] = QStringLiteral("ÀÌ,ÀÍ,ÀÎ,ÀÏ,ÀÐ,ÀÑ,ÀÔ,ÀÓ,ÀÒ, , , , , , ");


	ChineseLanMap[QStringLiteral("le")] = QStringLiteral("ÀÖ,ÀÕ,ÁË, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lei")] = QStringLiteral("À×,ÀØ,ÀÝ,ÀÚ,ÀÙ,ÀÜ,Àß,Àá,Àà,ÀÛ,ÀÞ, , , , ");


	ChineseLanMap[QStringLiteral("leng")] = QStringLiteral("Àâ,Àã,Àä, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("li")] = QStringLiteral("Àå,Àæ,Àê,Àë,Àò,Àç,Àì,Á§,Àè,Àé,Àñ,Àî,Àï,Á¨,Àí,Àð,Á¦,Àú,À÷,Á¢,Àô,Àö,Àû,Àø,Á¤,Àý,Á¥,Àþ,Àó,Àõ,Àù,Á£,Àü,Á¡, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lian")] = QStringLiteral("Á¬,Á±,Á¯,Á°,Á«,Áª,Á®,Á­,Á²,Á³,Á·,Á¶,Áµ,Á´, ");


	ChineseLanMap[QStringLiteral("liang")] = QStringLiteral("Á©,Á¼,Á¹,Áº,Á¸,Á»,Á½,ÁÁ,ÁÂ,Á¾,ÁÀ,Á¿, , , ");


	ChineseLanMap[QStringLiteral("liao")] = QStringLiteral("ÁÊ,ÁÉ,ÁÆ,ÁÄ,ÁÅ,ÁÈ,ÁÎ,ÁÃ,ÁÇ,ÁÍ,ÁÏ,ÁÌ, , , ");


	ChineseLanMap[QStringLiteral("lie")] = QStringLiteral("ÁÐ,ÁÓ,ÁÒ,ÁÔ,ÁÑ, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lin")] = QStringLiteral("ÁÚ,ÁÖ,ÁÙ,ÁÜ,ÁÕ,ÁØ,Á×,ÁÛ,ÁÝ,Áß,ÁÞ,Áà, , , ");


	ChineseLanMap[QStringLiteral("ling")] = QStringLiteral("Áæ,Áé,Áë,Áá,Áè,Áå,Áê,Áç,Áâ,Áã,Áä,Áì,Áî,Áí, ");


	ChineseLanMap[QStringLiteral("liu")] = QStringLiteral("Áï,Áõ,Á÷,Áô,Áð,Áò,Áó,Áñ,Áö,Áø,Áù, , , , ");


	ChineseLanMap[QStringLiteral("long")] = QStringLiteral("Áú,Áü,Áý,Áû,Â¡,Áþ,Â¤,Â¢,Â£, , , , , , ");


	ChineseLanMap[QStringLiteral("lou")] = QStringLiteral("Â¦,Â¥,Â§,Â¨,Âª,Â©, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lu")] = QStringLiteral("Â¶,Â¬,Â®,Â«,Â¯,Â­,Â±,Â²,Â°,Â³,Â½,Â¼,Â¸,Â¹,Â»,Âµ,Â·,Â¾,Âº,Â´, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("luan")] = QStringLiteral("ÂÏ,ÂÍ,ÂÎ,ÂÐ,ÂÑ,ÂÒ, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lue")] = QStringLiteral("ÂÓ,ÂÔ , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lun")] = QStringLiteral("ÂÕ,ÂØ,Â×,ÂÙ,ÂÚ,ÂÖ,ÂÛ, , , , , , , , ");


	ChineseLanMap[QStringLiteral("luo")] = QStringLiteral("ÂÞ,ÂÜ,Âß,Âà,Âá,Ââ,ÂÝ,Âã,Âå,Âç,Âæ,Âä, , , ");


	ChineseLanMap[QStringLiteral("lv")] = QStringLiteral("ÂË,Â¿,ÂÀ,ÂÂ,ÂÃ,ÂÁ,ÂÅ,ÂÆ,ÂÄ,ÂÉ,ÂÇ,ÂÊ,ÂÌ,ÂÈ, ");


	ChineseLanMap[QStringLiteral("ma")] = QStringLiteral("Âè,Âé,Âí,Âê,Âë,Âì,Âî,Âð,Âï, , , , , , ");


	ChineseLanMap[QStringLiteral("mai")] = QStringLiteral("Âñ,Âò,Âõ,Âó,Âô,Âö, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("man")] = QStringLiteral("Âù,Âø,Â÷,Âú,Âü,Ã¡,Âý,Âþ,Âû, , , , , , ");


	ChineseLanMap[QStringLiteral("mang")] = QStringLiteral("Ã¦,Ã¢,Ã¤,Ã£,Ã§,Ã¥, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mao")] = QStringLiteral("Ã¨,Ã«,Ã¬,Ã©,Ãª,Ã®,Ã­,Ã¯,Ã°,Ã³,Ã±,Ã², , , ");


	ChineseLanMap[QStringLiteral("me")] = QStringLiteral("Ã´, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mei")] = QStringLiteral("Ã»,Ã¶,Ãµ,Ã¼,Ã·,Ã½,Ãº,Ã¸,Ã¹,Ã¿,ÃÀ,Ã¾,ÃÃ,ÃÁ,ÃÄ,ÃÂ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("men")] = QStringLiteral("ÃÅ,ÃÆ,ÃÇ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("meng")] = QStringLiteral("ÃÈ,ÃË,ÃÊ,ÃÍ,ÃÉ,ÃÌ,ÃÏ,ÃÎ, , , , , , , ");


	ChineseLanMap[QStringLiteral("mi")] = QStringLiteral("ÃÖ,ÃÔ,ÃÕ,ÃÑ,ÃÓ,ÃÒ,Ã×,ÃÐ,ÃÚ,ÃÙ,ÃØ,ÃÜ,ÃÝ,ÃÛ, ");


	ChineseLanMap[QStringLiteral("mian")] = QStringLiteral("Ãß,Ãà,ÃÞ,Ãâ,Ãã,Ãä,Ãá,Ãå,Ãæ, , , , , , ");


	ChineseLanMap[QStringLiteral("miao")] = QStringLiteral("Ãç,Ãé,Ãë,Ãì,Ãê,Ãî,Ãí, , , , , , , , ");


	ChineseLanMap[QStringLiteral("mie")] = QStringLiteral("Ãð,Ãï, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("min")] = QStringLiteral("Ãñ,Ãó,Ãò,Ãö,Ãõ,Ãô, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ming")] = QStringLiteral("Ãû,Ã÷,Ãù,Ãú,Ãø,Ãü, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("miu")] = QStringLiteral("Ãý, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mo")] = QStringLiteral("ºÑ,Ãþ,Ä¡,Ä£,Ä¤,Ä¦,Ä¥,Ä¢,Ä§,Ä¨,Ä©,Ä­,Ä°,Äª,Ä¯,Ä®,Ä«,Ä¬, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mou")] = QStringLiteral("Ä²,Ä±,Ä³, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mu")] = QStringLiteral("Ä¸,Ä¶,Äµ,Ä·,Ä´,Ä¾,Ä¿,ÄÁ,Ä¼,Ä¹,Ä»,ÄÀ,Ä½,Äº,ÄÂ");


	ChineseLanMap[QStringLiteral("na")] = QStringLiteral("ÄÃ,ÄÄ,ÄÇ,ÄÉ,ÄÈ,ÄÆ,ÄÅ, , , , , , , , ");


	ChineseLanMap[QStringLiteral("nai")] = QStringLiteral("ÄË,ÄÌ,ÄÊ,ÄÎ,ÄÍ, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nan")] = QStringLiteral("ÄÐ,ÄÑ,ÄÏ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nang")] = QStringLiteral("ÄÒ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ne")] = QStringLiteral("ÄØ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nao")] = QStringLiteral("ÄÓ,ÄÕ,ÄÔ,ÄÖ,Ä×, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nei")] = QStringLiteral("ÄÚ,ÄÙ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nen")] = QStringLiteral("ÄÛ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("neng")] = QStringLiteral("ÄÜ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ni")] = QStringLiteral("ÄÝ,Äá,Äà,Äß,ÄÞ,Äã,Äâ,Äæ,Ää,Äç,Äå, , , , ");


	ChineseLanMap[QStringLiteral("nian")] = QStringLiteral("Äé,Äê,Äí,Äì,Äë,Äî,Äè, , , , , , , , ");


	ChineseLanMap[QStringLiteral("niang")] = QStringLiteral("Äï,Äð, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("niao")] = QStringLiteral("Äñ,Äò, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nie")] = QStringLiteral("Äó,Äù,Äô,Äö,Ä÷,Äø,Äõ, , , , , , , , ");


	ChineseLanMap[QStringLiteral("nin")] = QStringLiteral("Äú, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nuan")] = QStringLiteral("Å¯, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ning")] = QStringLiteral("Äþ,Å¡,Äü,Äû,Äý,Å¢, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("niu")] = QStringLiteral("Å£,Å¤,Å¦,Å¥, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nong")] = QStringLiteral("Å©,Å¨,Å§,Åª, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nu")] = QStringLiteral("Å«,Å¬,Å­, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nue")] = QStringLiteral("Å±,Å°, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nuo")] = QStringLiteral("Å²,Åµ,Å³,Å´, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nv")] = QStringLiteral("Å®, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("o")] = QStringLiteral("Å¶, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ou")] = QStringLiteral("Å·,Å¹,Å¸,Å»,Å¼,Åº,Å½, , , , , , , , ");


	ChineseLanMap[QStringLiteral("pa")] = QStringLiteral("Å¿,Å¾,ÅÀ,°Ò,ÅÃ,ÅÁ,ÅÂ, , , , , , , , ");


	ChineseLanMap[QStringLiteral("pai")] = QStringLiteral("ÅÄ,ÅÇ,ÅÅ,ÅÆ,ÅÉ,ÅÈ, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pan")] = QStringLiteral("ÅË,ÅÊ,ÅÌ,ÅÍ,ÅÐ,ÅÑ,ÅÎ,ÅÏ, , , , , , , ");


	ChineseLanMap[QStringLiteral("pang")] = QStringLiteral("ÅÒ,ÅÓ,ÅÔ,ÅÕ,ÅÖ, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pao")] = QStringLiteral("Å×,ÅÙ,ÅØ,ÅÚ,ÅÛ,ÅÜ,ÅÝ, , , , , , , , ");


	ChineseLanMap[QStringLiteral("pei")] = QStringLiteral("ÅÞ,Åã,Åà,Åâ,Åá,Åæ,Åå,Åä, , , , , , , ");


	ChineseLanMap[QStringLiteral("pen")] = QStringLiteral("Åç,Åè, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("peng")] = QStringLiteral("Åê,Åé,Åë,Åó,Åí,Åï,Åð,Åî,Åô,Åì,Åñ,Åò,Åõ,Åö, ");


	ChineseLanMap[QStringLiteral("pi")] = QStringLiteral("±Ù,Åú,Å÷,Åû,Åø,Åü,Åù,Æ¤,Åþ,Æ£,Æ¡,Åý,Æ¢,Æ¥,Æ¦,Æ¨,Æ§,Æ©, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pian")] = QStringLiteral("Æ¬,Æ«,Æª,Æ­, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("piao")] = QStringLiteral("Æ¯,Æ®,Æ°,Æ±, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pie")] = QStringLiteral("Æ²,Æ³, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pin")] = QStringLiteral("Æ´,Æ¶,Æµ,Æ·,Æ¸, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ping")] = QStringLiteral("Æ¹,Æ½,ÆÀ,Æ¾,Æº,Æ»,ÆÁ,Æ¿,Æ¼, , , , , , ");


	ChineseLanMap[QStringLiteral("po")] = QStringLiteral("ÆÂ,ÆÃ,ÆÄ,ÆÅ,ÆÈ,ÆÆ,ÆÉ,ÆÇ, , , , , , , ");


	ChineseLanMap[QStringLiteral("pou")] = QStringLiteral("ÆÊ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pu")] = QStringLiteral("¸¬,ÆÍ,ÆË,ÆÌ,ÆÎ,ÆÐ,ÆÏ,ÆÑ,ÆÓ,ÆÔ,ÆÒ,ÆÖ,ÆÕ,Æ×,ÆØ");


	ChineseLanMap[QStringLiteral("qi")] = QStringLiteral("Æß,Æã,ÆÞ,Æâ,Æà,ÆÜ,ÆÝ,ÆÚ,ÆÛ,Æá,Æî,Æë,Æä,Ææ,Æç,Æí,Æê,Æé,Æè,Æï,Æå,Æì,Æò,Æó,Æñ,Æô,Æð,Æø,Æý,Æù,Æú,Æû,Æü,Æõ,Æö,Æ÷, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qia")] = QStringLiteral("Æþ,Ç¡,Ç¢, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qian")] = QStringLiteral("Ç§,Çª,Ç¤,Ç¨,Ç¥,Ç£,Ç¦,Ç«,Ç©,Ç°,Ç®,Ç¯,Ç¬,Ç±,Ç­,Ç³,Ç²,Ç´,Ç·,Çµ,Ç¶,Ç¸, , , , , , , , ");


	ChineseLanMap[QStringLiteral("qiang")] = QStringLiteral("Çº,Ç¼,Ç¹,Ç»,Ç¿,Ç½,Ç¾,ÇÀ, , , , , , , ");


	ChineseLanMap[QStringLiteral("qiao")] = QStringLiteral("ÇÄ,ÇÃ,ÇÂ,ÇÁ,ÇÇ,ÇÈ,ÇÅ,ÇÆ,ÇÉ,ÇÎ,ÇÍ,ÇÏ,ÇÌ,ÇË,ÇÊ");


	ChineseLanMap[QStringLiteral("qie")] = QStringLiteral("ÇÐ,ÇÑ,ÇÒ,ÇÓ,ÇÔ, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qin")] = QStringLiteral("Ç×,ÇÖ,ÇÕ,ÇÛ,ÇØ,ÇÙ,ÇÝ,ÇÚ,ÇÜ,ÇÞ,Çß, , , , ");


	ChineseLanMap[QStringLiteral("qing")] = QStringLiteral("Çà,Çâ,Çá,Çã,Çä,Çå,Çé,Çç,Çè,Çæ,Çê,Çë,Çì, , ");


	ChineseLanMap[QStringLiteral("qiong")] = QStringLiteral("Çî,Çí, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qiu")] = QStringLiteral("Çð,Çñ,Çï,Çô,Çó,Çö,Çõ,Çò, , , , , , , ");


	ChineseLanMap[QStringLiteral("qu")] = QStringLiteral("Çø,Çú,Çý,Çü,Çù,Çû,Ç÷,Çþ,È¡,È¢,È£,È¥,È¤, , ");


	ChineseLanMap[QStringLiteral("quan")] = QStringLiteral("È¦,È«,È¨,Èª,È­,È¬,È©,È§,È®,È°,È¯, , , , ");


	ChineseLanMap[QStringLiteral("que")] = QStringLiteral("È²,È±,È³,È´,È¸,È·,Èµ,È¶, , , , , , , ");


	ChineseLanMap[QStringLiteral("qun")] = QStringLiteral("È¹,Èº, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ran")] = QStringLiteral("È»,È¼,È½,È¾, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rang")] = QStringLiteral("È¿,ÈÂ,ÈÀ,ÈÁ,ÈÃ, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rao")] = QStringLiteral("ÈÄ,ÈÅ,ÈÆ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("re")] = QStringLiteral("ÈÇ,ÈÈ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ren")] = QStringLiteral("ÈË,ÈÊ,ÈÉ,ÈÌ,ÈÐ,ÈÏ,ÈÎ,ÈÒ,ÈÑ,ÈÍ, , , , , ");


	ChineseLanMap[QStringLiteral("reng")] = QStringLiteral("ÈÓ,ÈÔ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ri")] = QStringLiteral("ÈÕ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rong")] = QStringLiteral("ÈÖ,ÈÞ,È×,ÈÙ,ÈÝ,ÈÜ,ÈØ,ÈÛ,ÈÚ,Èß, , , , , ");


	ChineseLanMap[QStringLiteral("rou")] = QStringLiteral("Èá,Èà,Èâ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ru")] = QStringLiteral("Èç,Èã,Èå,Èæ,Èä,Èê,Èé,Èè,Èë,Èì, , , , , ");


	ChineseLanMap[QStringLiteral("ruan")] = QStringLiteral("Èî,Èí, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rui")] = QStringLiteral("Èï,Èñ,Èð, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("run")] = QStringLiteral("Èò,Èó, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ruo")] = QStringLiteral("Èô,Èõ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sa")] = QStringLiteral("Èö,È÷,Èø, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sai")] = QStringLiteral("Èû,Èù,Èú,Èü, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("san")] = QStringLiteral("Èý,Èþ,É¡,É¢, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sang")] = QStringLiteral("É£,É¤,É¥, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sao")] = QStringLiteral("É¦,É§,É¨,É©, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("se")] = QStringLiteral("É«,É¬,Éª, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sen")] = QStringLiteral("É­, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("seng")] = QStringLiteral("É®, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sha")] = QStringLiteral("É±,É³,É´,É°,É¯,Éµ,É¶,É·,ÏÃ, , , , , , ");


	ChineseLanMap[QStringLiteral("shai")] = QStringLiteral("É¸,É¹, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shan")] = QStringLiteral("É½,É¾,É¼,ÉÀ,Éº,É¿,ÉÁ,ÉÂ,ÉÇ,É»,ÉÈ,ÉÆ,ÉÉ,ÉÃ,ÉÅ,ÉÄ,Õ¤, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shang")] = QStringLiteral("ÉË,ÉÌ,ÉÊ,ÉÑ,ÉÎ,ÉÍ,ÉÏ,ÉÐ, , , , , , , ");


	ChineseLanMap[QStringLiteral("shao")] = QStringLiteral("ÉÓ,ÉÒ,ÉÕ,ÉÔ,É×,ÉÖ,ÉØ,ÉÙ,ÉÛ,ÉÜ,ÉÚ, , , , ");


	ChineseLanMap[QStringLiteral("she")] = QStringLiteral("ÉÝ,ÉÞ,Éà,Éß,Éá,Éè,Éç,Éä,Éæ,Éâ,Éå,Éã, , , ");


	ChineseLanMap[QStringLiteral("shen")] = QStringLiteral("Éê,Éì,Éí,Éë,Éð,Éï,Éé,Éî,Éñ,Éò,Éó,Éô,Éö,Éõ,Éø,É÷,Ê², , , , , , , , , , , , , ");



	ChineseLanMap[QStringLiteral("sheng")] = QStringLiteral("Éý,Éú,Éù,Éü,Ê¤,Éû,Éþ,Ê¡,Ê¥,Ê¢,Ê£, , , , ");


	ChineseLanMap[QStringLiteral("shi")] = QStringLiteral("³×,Ê¬,Ê§,Ê¦,Ê­,Ê«,Ê©,Ê¨,Êª,Ê®,Ê¯,Ê±,Ê¶,Êµ,Ê°,Ê´,Ê³,Ê·,Ê¸,Ê¹,Ê¼,Ê»,Êº,Ê¿,ÊÏ,ÊÀ,ÊË,ÊÐ,Ê¾,Ê½,ÊÂ,ÊÌ,ÊÆ,ÊÓ,ÊÔ,ÊÎ,ÊÒ,ÊÑ,ÊÃ,ÊÇ,ÊÁ,ÊÊ,ÊÅ,ÊÍ,ÊÈ,ÊÄ,ÊÉ,ËÆ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shou")] = QStringLiteral("ÊÕ,ÊÖ,ÊØ,Ê×,ÊÙ,ÊÜ,ÊÞ,ÊÛ,ÊÚ,ÊÝ, , , , , ");


	ChineseLanMap[QStringLiteral("shu")] = QStringLiteral("Êé,Êã,Êå,Êà,Êâ,Êá,Êç,Êè,Êæ,Êä,Êß,Êë,Êê,Êì,Êî,Êò,Êð,Êó,Êñ,Êí,Êï,Êõ,Êù,Êø,Êö,Ê÷,Êú,Ë¡,Êü,Êý,Êû,Êþ,Êô, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shua")] = QStringLiteral("Ë¢,Ë£, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuai")] = QStringLiteral("Ë¥,Ë¤,Ë¦,Ë§, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuan")] = QStringLiteral("Ë©,Ë¨, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuang")] = QStringLiteral("Ë«,Ëª,Ë¬, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shui")] = QStringLiteral("Ë­,Ë®,Ë°,Ë¯, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shun")] = QStringLiteral("Ë±,Ë³,Ë´,Ë², , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuo")] = QStringLiteral("Ëµ,Ë¸,Ë·,Ë¶, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("si")] = QStringLiteral("Ë¿,Ë¾,Ë½,Ë¼,Ë¹,Ë»,Ëº,ËÀ,ËÈ,ËÄ,ËÂ,ËÅ,ËÇ,ËÃ,ËÁ");


	ChineseLanMap[QStringLiteral("song")] = QStringLiteral("ËÉ,ËË,ËÊ,ËÏ,ËÎ,ËÐ,ËÍ,ËÌ, , , , , , , ");


	ChineseLanMap[QStringLiteral("sou")] = QStringLiteral("ËÔ,ËÑ,ËÒ,ËÓ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("su")] = QStringLiteral("ËÕ,ËÖ,Ë×,Ëß,Ëà,ËØ,ËÙ,ËÚ,ËÜ,ËÝ,ËÛ, , , , ");


	ChineseLanMap[QStringLiteral("suan")] = QStringLiteral("Ëá,Ëâ,Ëã, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sui")] = QStringLiteral("Ëä,Ëç,Ëå,Ëæ,Ëè,Ëê,Ëî,Ëì,Ëé,Ëí,Ëë, , , , ");


	ChineseLanMap[QStringLiteral("sun")] = QStringLiteral("Ëï,Ëð,Ëñ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("suo")] = QStringLiteral("Ëô,Ëó,Ëò,Ëõ,Ëù,Ë÷,Ëö,Ëø, , , , , , , ");


	ChineseLanMap[QStringLiteral("ta")] = QStringLiteral("Ëý,Ëû,Ëü,Ëú,Ëþ,Ì¡,Ì¢,Ì¤,Ì£, , , , , , ");


	ChineseLanMap[QStringLiteral("tai")] = QStringLiteral("Ì¥,Ì¨,Ì§,Ì¦,Ì«,Ì­,Ì¬,Ì©,Ìª, , , , , , ");


	ChineseLanMap[QStringLiteral("tan")] = QStringLiteral("Ì®,Ì°,Ì¯,Ì²,Ì±,Ì³,Ì¸,Ìµ,Ì·,Ì¶,Ì´,Ì¹,Ì»,Ìº,Ì¾,Ì¿,Ì½,Ì¼, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tang")] = QStringLiteral("ÌÀ,ÌÆ,ÌÃ,ÌÄ,ÌÁ,ÌÂ,ÌÅ,ÌÇ,ÌÈ,ÌÊ,ÌÉ,ÌÌ,ÌË, , ");


	ChineseLanMap[QStringLiteral("tao")] = QStringLiteral("ÌÎ,ÌÐ,ÌÍ,ÌÏ,ÌÓ,ÌÒ,ÌÕ,ÌÔ,ÌÑ,ÌÖ,Ì×, , , , ");


	ChineseLanMap[QStringLiteral("te")] = QStringLiteral("ÌØ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("teng")] = QStringLiteral("ÌÛ,ÌÚ,ÌÜ,ÌÙ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ti")] = QStringLiteral("ÌÞ,ÌÝ,Ìà,Ìß,Ìä,Ìá,Ìâ,Ìã,Ìå,Ìë,Ìê,Ìé,Ìè,Ìæ,Ìç");


	ChineseLanMap[QStringLiteral("tian")] = QStringLiteral("Ìì,Ìí,Ìï,Ìñ,Ìð,Ìî,Ìó,Ìò, , , , , , , ");


	ChineseLanMap[QStringLiteral("tiao")] = QStringLiteral("µ÷,Ìô,Ìõ,Ìö,Ì÷,Ìø, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tie")] = QStringLiteral("Ìù,Ìú,Ìû, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ting")] = QStringLiteral("Ìü,Í¡,Ìý,Ìþ,Í¢,Í¤,Í¥,Í£,Í¦,Í§, , , , , ");


	ChineseLanMap[QStringLiteral("tong")] = QStringLiteral("Í¨,Í¬,Í®,Í©,Í­,Í¯,Íª,Í«,Í³,Í±,Í°,Í²,Í´, , ");


	ChineseLanMap[QStringLiteral("tou")] = QStringLiteral("Íµ,Í·,Í¶,Í¸, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tu")] = QStringLiteral("Í¹,Íº,Í»,Í¼,Í½,Í¿,Í¾,ÍÀ,ÍÁ,ÍÂ,ÍÃ, , , , ");


	ChineseLanMap[QStringLiteral("tuan")] = QStringLiteral("ÍÄ,ÍÅ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tui")] = QStringLiteral("ÍÆ,ÍÇ,ÍÈ,ÍË,ÍÉ,ÍÊ, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tun")] = QStringLiteral("¶Ú,ÍÌ,ÍÍ,ÍÎ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tuo")] = QStringLiteral("ÍÐ,ÍÏ,ÍÑ,ÍÔ,ÍÓ,ÍÕ,ÍÒ,Í×,ÍÖ,ÍØ,ÍÙ, , , , ");


	ChineseLanMap[QStringLiteral("wa")] = QStringLiteral("ÍÛ,ÍÞ,ÍÚ,ÍÝ,ÍÜ,Íß,Íà, , , , , , , , ");


	ChineseLanMap[QStringLiteral("wai")] = QStringLiteral("Íá,Íâ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("wan")] = QStringLiteral("Íä,Íå,Íã,Íè,Íê,Íæ,Íç,Íé,Íð,Íì,Íí,Íñ,Íï,Íî,Íë,Íò,Íó, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("wang")] = QStringLiteral("Íô,Íö,Íõ,Íø,Íù,Í÷,Íý,Íü,Íú,Íû, , , , , ");


	ChineseLanMap[QStringLiteral("wei")] = QStringLiteral("Î£,Íþ,Î¢,Î¡,Îª,Î¤,Î§,Î¥,Î¦,Î¨,Î©,Î¬,Î«,Î°,Î±,Î²,Î³,Î­,Î¯,Î®,ÎÀ,Î´,Î»,Î¶,Î·,Î¸,Î¾,Î½,Î¹,Î¼,Îµ,Î¿,Îº, , , , , , , , , , , , ");



	ChineseLanMap[QStringLiteral("wen")] = QStringLiteral("ÎÂ,ÎÁ,ÎÄ,ÎÆ,ÎÅ,ÎÃ,ÎÇ,ÎÉ,ÎÈ,ÎÊ, , , , , ");


	ChineseLanMap[QStringLiteral("weng")] = QStringLiteral("ÎÌ,ÎË,ÎÍ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("wo")] = QStringLiteral("ÎÎ,ÎÐ,ÎÑ,ÎÏ,ÎÒ,ÎÖ,ÎÔ,ÎÕ,ÎÓ, , , , , , ");


	ChineseLanMap[QStringLiteral("wu")] = QStringLiteral("ÎÚ,ÎÛ,ÎØ,Î×,ÎÝ,ÎÜ,ÎÙ,ÎÞ,Îã,Îâ,Îá,Îß,Îà,Îå,Îç,Îé,Îë,Îä,Îê,Îæ,Îè,Îð,Îñ,Îì,Îï,Îó,Îò,Îî,Îí, ");


	ChineseLanMap[QStringLiteral("xi")] = QStringLiteral("Ï¦,Ï«,Î÷,Îü,Ï£,Îô,Îö,Îù,Ï¢,Îþ,Ï¤,Ï§,Ï©,Îø,Îú,Ï¬,Ï¡,Ïª,Îý,Ï¨,Îõ,Îû,Ï¥,Ï°,Ï¯,Ï®,Ï±,Ï­,Ï´,Ï²,Ï·,Ïµ,Ï¸,Ï¶, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xia")] = QStringLiteral("Ïº,Ï¹,Ï»,ÏÀ,Ï¿,ÏÁ,Ï¾,Ï½,Ï¼,ÏÂ,ÏÅ,ÏÄ, , , ");


	ChineseLanMap[QStringLiteral("xian")] = QStringLiteral("Ï³,ÏÉ,ÏÈ,ÏË,ÏÆ,ÏÇ,ÏÊ,ÏÐ,ÏÒ,ÏÍ,ÏÌ,ÏÑ,ÏÏ,ÏÎ,ÏÓ,ÏÔ,ÏÕ,ÏØ,ÏÖ,Ïß,ÏÞ,ÏÜ,ÏÝ,ÏÚ,ÏÛ,Ï×,ÏÙ, , , ");


	ChineseLanMap[QStringLiteral("xiang")] = QStringLiteral("Ïç,Ïà,Ïã,Ïá,Ïæ,Ïä,Ïå,Ïâ,Ïê,Ïé,Ïè,Ïí,Ïì,Ïë,Ïò,Ïï,Ïî,Ïó,Ïñ,Ïð, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xiao")] = QStringLiteral("Ïü,Ïû,Ïô,Ïõ,Ïú,Ïö,Ïù,Ïý,Ð¡,Ïþ,Ð¢,Ð¤,Ïø,Ð§,Ð£,Ð¦,Ð¥, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xie")] = QStringLiteral("Ð©,Ð¨,Ðª,Ð«,Ð­,Ð°,Ð²,Ð±,Ð³,Ð¯,Ð¬,Ð´,Ð¹,Ðº,Ð¶,Ð¼,Ðµ,Ð»,Ð¸,Ð·, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xin")] = QStringLiteral("ÐÄ,ÐÃ,Ð¾,ÐÁ,ÐÀ,Ð¿,ÐÂ,Ð½,ÐÅ,ÐÆ,öÎ, , , , ");


	ChineseLanMap[QStringLiteral("xing")] = QStringLiteral("ÐË,ÐÇ,ÐÊ,ÐÉ,ÐÈ,ÐÌ,ÐÏ,ÐÎ,ÐÍ,ÐÑ,ÐÓ,ÐÕ,ÐÒ,ÐÔ, ");


	ChineseLanMap[QStringLiteral("xiong")] = QStringLiteral("Ð×,ÐÖ,ÐÙ,ÐÚ,ÐØ,ÐÛ,ÐÜ, , , , , , , , ");


	ChineseLanMap[QStringLiteral("xiu")] = QStringLiteral("ËÞ,ÐÝ,ÐÞ,Ðß,Ðà,Ðã,Ðå,Ðä,Ðâ,Ðá, , , , , ");


	ChineseLanMap[QStringLiteral("xu")] = QStringLiteral("Ðç,Ðë,Ðé,Ðê,Ðè,Ðæ,Ðì,Ðí,Ðñ,Ðò,Ðð,Ðô,Ð÷,Ðø,Ðï,Ðö,Ðõ,Ðî,Óõ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xuan")] = QStringLiteral("Ðù,Ðû,Ðú,Ðþ,Ðü,Ðý,Ñ¡,Ñ¢,Ñ¤,Ñ£, , , , , ");


	ChineseLanMap[QStringLiteral("xue")] = QStringLiteral("Ï÷,Ñ¥,Ñ¦,Ñ¨,Ñ§,Ñ©,Ñª, , , , , , , , ");


	ChineseLanMap[QStringLiteral("xun")] = QStringLiteral("Ñ«,Ñ¬,Ñ°,Ñ²,Ñ®,Ñ±,Ñ¯,Ñ­,Ñµ,Ñ¶,Ñ´,Ñ¸,Ñ·,Ñ³, ");


	ChineseLanMap[QStringLiteral("ya")] = QStringLiteral("Ñ¾,Ñ¹,Ñ½,Ñº,Ñ»,Ñ¼,ÑÀ,Ñ¿,ÑÁ,ÑÂ,ÑÄ,ÑÃ,ÑÆ,ÑÅ,ÑÇ,ÑÈ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yan")] = QStringLiteral("ÑÊ,ÑÌ,ÑÍ,ÑÉ,ÑË,ÑÓ,ÑÏ,ÑÔ,ÑÒ,ÑØ,Ñ×,ÑÐ,ÑÎ,ÑÖ,ÑÑ,ÑÕ,ÑÙ,ÑÜ,ÑÚ,ÑÛ,ÑÝ,Ñá,Ñå,Ñâ,Ñä,Ñç,ÑÞ,Ñé,Ñè,Ñß,Ñæ,Ñã,Ñà, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yang")] = QStringLiteral("Ñë,Ñê,Ñí,Ñì,Ñï,Ñò,Ñô,Ñî,Ñð,Ññ,Ñó,Ñö,Ñø,Ñõ,Ñ÷,Ñù,Ñú, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yao")] = QStringLiteral("½Ä,Ñý,Ñü,Ñû,Ò¢,Ò¦,Ò¤,Ò¥,Ò¡,Ò£,Ñþ,Ò§,Ò¨,Ò©,Òª,Ò«,Ô¿, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ye")] = QStringLiteral("Ò¬,Ò­,Ò¯,Ò®,Ò²,Ò±,Ò°,Òµ,Ò¶,Ò·,Ò³,Ò¹,Ò´,Òº,Ò¸, , , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yin")] = QStringLiteral("Òò,Òõ,Òö,Òð,Òñ,Òô,Òó,Ò÷,Òú,Òù,Òø,Òü,Òý,Òû,Òþ,Ó¡, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ying")] = QStringLiteral("Ó¦,Ó¢,Ó¤,Ó§,Ó£,Ó¥,Ó­,Ó¯,Ó«,Ó¨,Ó©,Óª,Ó¬,Ó®,Ó±,Ó°,Ó³,Ó², , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yo")] = QStringLiteral("Ó´, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yong")] = QStringLiteral("Ó¶,Óµ,Ó¸,Ó¹,Óº,Ó·,ÓÀ,Ó½,Ó¾,ÓÂ,Ó¿,ÓÁ,Ó¼,Ó»,ÓÃ");


	ChineseLanMap[QStringLiteral("you")] = QStringLiteral("ÓÅ,ÓÇ,ÓÄ,ÓÆ,ÓÈ,ÓÉ,ÓÌ,ÓÊ,ÓÍ,ÓË,ÓÎ,ÓÑ,ÓÐ,ÓÏ,ÓÖ,ÓÒ,Ó×,ÓÓ,ÓÕ,ÓÔ, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yu")] = QStringLiteral("ÓØ,ÓÙ,Óå,ÓÚ,Óè,Óà,ÓÛ,Óã,Óá,Óé,Óæ,Óç,Óä,Óâ,ÓÞ,ÓÜ,ÓÝ,Óß,Óë,Óî,Óì,Óð,Óê,Óí,Óï,Óñ,Ô¦,Óó,Óý,Óô,Óü,Óø,Ô¡,Ô¤,Óò,Óû,Ó÷,Ô¢,Óù,Ô£,Óö,Óú,Óþ,Ô¥, ");


	ChineseLanMap[QStringLiteral("yuan")] = QStringLiteral("Ô©,Ô§,Ô¨,Ôª,Ô±,Ô°,Ô«,Ô­,Ô²,Ô¬,Ô®,Ôµ,Ô´,Ô³,Ô¯,Ô¶,Ô·,Ô¹,Ôº,Ô¸, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yue")] = QStringLiteral("Ô»,Ô¼,ÔÂ,ÔÀ,ÔÃ,ÔÄ,Ô¾,ÔÁ,Ô½, , , , , , ");


	ChineseLanMap[QStringLiteral("yun")] = QStringLiteral("ÔÆ,ÔÈ,ÔÇ,ÔÅ,ÔÊ,ÔÉ,ÔÐ,ÔË,ÔÎ,ÔÍ,ÔÏ,ÔÌ, , , ");


	ChineseLanMap[QStringLiteral("za")] = QStringLiteral("ÔÑ,ÔÓ,ÔÒ,Õ¦, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zai")] = QStringLiteral("ÔÖ,ÔÕ,ÔÔ,Ô×,ÔØ,ÔÙ,ÔÚ,×Ð, , , , , , , ");


	ChineseLanMap[QStringLiteral("zan")] = QStringLiteral("ÔÛ,ÔÜ,ÔÝ,ÔÞ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zang")] = QStringLiteral("Ôß,Ôà,Ôá, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zao")] = QStringLiteral("Ôâ,Ôã,Ôä,Ôç,Ôæ,Ôé,Ôè,Ôå,Ôî,Ôí,Ôì,Ôë,Ôï,Ôê, ");


	ChineseLanMap[QStringLiteral("ze")] = QStringLiteral("Ôò,Ôñ,Ôó,Ôð, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zei")] = QStringLiteral("Ôô, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zen")] = QStringLiteral("Ôõ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zeng")] = QStringLiteral("Ôö,Ô÷,Ôù, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zha")] = QStringLiteral("Ôû,Ôü,Ôú,Ôý,Ôþ,Õ¢,Õ¡,Õ£,Õ§,Õ©,Õ¨,Õ¥,×õ, , ");


	ChineseLanMap[QStringLiteral("zhai")] = QStringLiteral("Õ«,Õª,Õ¬,µÔ,Õ­,Õ®,Õ¯, , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhan")] = QStringLiteral("Õ´,Õ±,Õ³,Õ²,Õ°,Õ¶,Õ¹,Õµ,Õ¸,Õ·,Õ¼,Õ½,Õ»,Õ¾,ÕÀ,Õ¿,Õº, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhang")] = QStringLiteral("³¤,ÕÅ,ÕÂ,ÕÃ,ÕÄ,ÕÁ,ÕÇ,ÕÆ,ÕÉ,ÕÌ,ÕÊ,ÕÈ,ÕÍ,ÕË,ÕÏ,ÕÎ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhao")] = QStringLiteral("ÕÐ,ÕÑ,ÕÒ,ÕÓ,ÕÙ,Õ×,ÕÔ,ÕÕ,ÕÖ,ÕØ,×¦, , , , ");


	ChineseLanMap[QStringLiteral("zhe")] = QStringLiteral("ÕÚ,ÕÛ,ÕÜ,ÕÝ,ÕÞ,Õß,Õà,Õâ,Õã,Õá,×Å, , , , ");


	ChineseLanMap[QStringLiteral("zhen")] = QStringLiteral("Õê,Õë,Õì,Õä,Õæ,Õè,Õå,Õç,Õé,Õï,Õí,Õî,Õó,Õñ,Õò,Õð,Ö¡, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zheng")] = QStringLiteral("Õù,Õ÷,Õú,Õõ,Õø,Õö,Õô,Õü,Õû,Õý,Ö¤,Ö£,Õþ,Ö¢, ");


	ChineseLanMap[QStringLiteral("zhi")] = QStringLiteral("Ö®,Ö§,Ö­,Ö¥,Ö¨,Ö¦,Öª,Ö¯,Ö«,Ö¬,Ö©,Ö´,Ö¶,Ö±,Öµ,Ö°,Ö²,Ö³,Ö¹,Ö»,Ö¼,Ö·,Ö½,Ö¸,Öº,ÖÁ,Ö¾,ÖÆ,ÖÄ,ÖÎ,ÖË,ÖÊ,ÖÅ,Ö¿,ÖÈ,ÖÂ,ÖÀ,ÖÌ,ÖÏ,ÖÇ,ÖÍ,ÖÉ,ÖÃ, , ");


	ChineseLanMap[QStringLiteral("zhong")] = QStringLiteral("ÖÐ,ÖÒ,ÖÕ,ÖÑ,ÖÓ,ÖÔ,Ö×,ÖÖ,ÖÙ,ÖÚ,ÖØ, , , , ");


	ChineseLanMap[QStringLiteral("zhou")] = QStringLiteral("ÖÝ,ÖÛ,Öß,ÖÜ,ÖÞ,Öà,Öá,Öâ,Öã,Öä,Öæ,Öç,Öå,Öè, ");


	ChineseLanMap[QStringLiteral("zhu")] = QStringLiteral("Öì,Öï,Öê,Öé,Öî,Öí,Öë,Öñ,Öò,Öð,Ö÷,Öô,Öó,Öö,Öõ,×¡,Öú,×¢,Öü,×¤,Öù,×£,Öø,Öû,Öþ,Öý, , , , ");


	ChineseLanMap[QStringLiteral("zhua")] = QStringLiteral("×¥, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuai")] = QStringLiteral("×§, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuan")] = QStringLiteral("×¨,×©,×ª,×«,×­, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuang")] = QStringLiteral("×±,×¯,×®,×°,×³,×´,´±,×², , , , , , ,");


	ChineseLanMap[QStringLiteral("zhui")] = QStringLiteral("×·,×µ,×¶,×¹,×º,×¸, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhun")] = QStringLiteral("×»,×¼, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuo")] = QStringLiteral("×¿,×¾,×½,×À,×Æ,×Â,×Ç,×Ã,×Ä,×Á, , , , , ");


	ChineseLanMap[QStringLiteral("zi")] = QStringLiteral("×Î,×È,×É,×Ë,×Ê,×Í,×Ì,×Ñ,×Ó,×Ï,×Ò,×Ö,×Ô,×Õ, ");


	ChineseLanMap[QStringLiteral("zong")] = QStringLiteral("×Ú,×Û,×Ø,×Ù,××,×Ü,×Ý, , , , , , , , ");


	ChineseLanMap[QStringLiteral("zou")] = QStringLiteral("×Þ,×ß,×à,×á, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zu")] = QStringLiteral("×â,×ã,×ä,×å,×ç,×è,×é,×æ, , , , , , , ");


	ChineseLanMap[QStringLiteral("zuan")] = QStringLiteral("×¬,×ë,×ê, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zui")] = QStringLiteral("×ì,×î,×ï,×í, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zun")] = QStringLiteral("×ð,×ñ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zuo")] = QStringLiteral("×ò,×ó,×ô,×÷,×ø,×ù,×ö, , , , , , , , ");
}//ÖÐÎÄ×Ö¿â

void keyboard::CreateJapaneseMapLan()
{
	JapaneseLanMap[QStringLiteral("a")] = QStringLiteral("¤¢,¥¢, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ka")] = QStringLiteral("¤«,¥«, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("sa")] = QStringLiteral("¤µ,¥µ, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ta")] = QStringLiteral("¤¿,¥¿, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("na")] = QStringLiteral("¤Ê,¥Ê, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ha")] = QStringLiteral("¤Ï,¥Ï, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ma")] = QStringLiteral("¤Þ,¥Þ, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ya")] = QStringLiteral("¤ä,¥ä, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ra")] = QStringLiteral("¤é,¥é, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("wa")] = QStringLiteral("¤ï,¥ï, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("n")] = QStringLiteral("¤ó,¥ó, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("i")] = QStringLiteral("¤¤,¥¤, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ki")] = QStringLiteral("¤­,¥­, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("shi")] = QStringLiteral("¤·,¥·, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("chi")] = QStringLiteral("¤Á,¥Á, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ni")] = QStringLiteral("¤Ë,¥Ë, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("hi")] = QStringLiteral("¤Ò,¥Ò, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("mi")] = QStringLiteral("¤ß,¥ß, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ri")] = QStringLiteral("¤ê,¥ê, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("u")] = QStringLiteral("¤¦,¥¦, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ku")] = QStringLiteral("¤¯,¥¯, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("su")] = QStringLiteral("¤¹,¥¹, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("tsu")] = QStringLiteral("¤Ä,¥Ä, , , , , , , , , , , , , ");

	JapaneseLanMap[QStringLiteral("nu")] = QStringLiteral("¤Ì,¥Ì, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("fu")] = QStringLiteral("¤Õ,¥Õ, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("mu")] = QStringLiteral("¤à,¥à, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("yu")] = QStringLiteral("¤æ,¥æ, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ru")] = QStringLiteral("¤ë,¥ë, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("e")] = QStringLiteral("¤¨,¥¨, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ke")] = QStringLiteral("¤±,¥±, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("se")] = QStringLiteral("¤»,¥», , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("te")] = QStringLiteral("¤Æ,¥Æ, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ne")] = QStringLiteral("¤Í,¥Í, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("he")] = QStringLiteral("¤Ø,¥Ø, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("me")] = QStringLiteral("¤á,¥á, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("re")] = QStringLiteral("¤ì,¥ì, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("o")] = QStringLiteral("¤ª,¥ª, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ko")] = QStringLiteral("¤³,¥³, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("so")] = QStringLiteral("¤½,¥½, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("to")] = QStringLiteral("¤È,¥È, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("no")] = QStringLiteral("¤Î,¥Î, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ho")] = QStringLiteral("¤Û,¥Û, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("mo")] = QStringLiteral("¤â,¥â, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("yo")] = QStringLiteral("¤è,¥è, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ro")] = QStringLiteral("¤í,¥í, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("wo")] = QStringLiteral("¤ò,¥ò, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ga")] = QStringLiteral("¤¬,¥¬, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("za")] = QStringLiteral("¤¶,¥¶, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("da")] = QStringLiteral("¤À,¥À, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ba")] = QStringLiteral("¤Ð,¥Ð, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("gi")] = QStringLiteral("¤®,¥®, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ji")] = QStringLiteral("¤¸,¥¸, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("zi")] = QStringLiteral("¤¸,¥¸, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("di")] = QStringLiteral("¤Â,¥Â, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("bi")] = QStringLiteral("¤Ó,¥Ó, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("gu")] = QStringLiteral("¤°,¥°, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("zu")] = QStringLiteral("¤º,¥º, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("du")] = QStringLiteral("¤Å,¥Å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("bu")] = QStringLiteral("¤Ö,¥Ö, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ge")] = QStringLiteral("¤²,¥², , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ze")] = QStringLiteral("¤¼,¥¼, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("de")] = QStringLiteral("¤Ç,¥Ç, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("be")] = QStringLiteral("¤Ù,¥Ù, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("go")] = QStringLiteral("¤´,¥´, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("zo")] = QStringLiteral("¤¾,¥¾, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("do")] = QStringLiteral("¤É,¥É, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("bo")] = QStringLiteral("¤Ü,¥Ü, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pa")] = QStringLiteral("¤Ñ,¥Ñ, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pi")] = QStringLiteral("¤Ô,¥Ô, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pu")] = QStringLiteral("¥×,¥Ô, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pe")] = QStringLiteral("¤Ú,¥Ú, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("po")] = QStringLiteral("¤Ý,¥Ý, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("kya")] = QStringLiteral("¤­¤ã,¥­¥ã, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("gya")] = QStringLiteral("¤®¤ã,¥®¥ã, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("sha")] = QStringLiteral("¤·¤ã,¥·¥ã, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ja")] = QStringLiteral("¤¸¤ã,¥¸¥ã,¥Â¥ã, , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("cha")] = QStringLiteral("¤Á¤ã,¥Á¥ã, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("nya")] = QStringLiteral("¤Ë¤ã,¥Ë¥ã, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("dya")] = QStringLiteral("¤Â¤ã, , , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("hya")] = QStringLiteral("¤Ò¤ã,¥Ò¥ã, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("bya")] = QStringLiteral("¤Ó¤ã,¥Ó¥ã, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pya")] = QStringLiteral("¤Ô¤ã,¥Ô¥ã, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("mya")] = QStringLiteral("¤ß¤ã,¥ß¥ã, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("rya")] = QStringLiteral("¤ê¤ã,¥ê¥ã, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("kyu")] = QStringLiteral("¥­¥å,¤­¤å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("gyu")] = QStringLiteral("¤®¤å,¥®¥å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("shu")] = QStringLiteral("¤·¤å,¥·¥å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ju")] = QStringLiteral("¤¸¤å,¥¸¥å,¥Â¥å, , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("chu")] = QStringLiteral("¤Á¤å,¥Á¥å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("nyu")] = QStringLiteral("¤Ë¤å,¥Ë¥å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("hyu")] = QStringLiteral("¤Ò¤å,¥Ò¥å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("byu")] = QStringLiteral("¤Ó¤å,¥Ó¥å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pyu")] = QStringLiteral("¤Ô¤å,¥Ô¥å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("myu")] = QStringLiteral("¤ß¤å,¥ß¥å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ryu")] = QStringLiteral("¤ê¤å,¥ê¥å, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("kyo")] = QStringLiteral("¤­¤ç,¥­¥ç, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("gyo")] = QStringLiteral("¤®¤ç,¥®¥ç, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("sho")] = QStringLiteral("¤·¤ç,¥·¥ç, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("jo")] = QStringLiteral("¤¸¤ç,¥¸¥ç,¥¸¥ç, , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("cho")] = QStringLiteral("¤Á¤ç,¥·¥ç, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("dyo")] = QStringLiteral("¤Â¤ç, , , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("nyo")] = QStringLiteral("¤Ë¤ç,¥Ë¥ç, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("hyo")] = QStringLiteral("¤Ò¤ç,¥Ò¥ç, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("byo")] = QStringLiteral("¤Ó¤ç,¥Ó¥ç, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pyo")] = QStringLiteral("¤Ô¤ç,¥Ô¥ç, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("myo")] = QStringLiteral("¤ß¤ç,¥ß¥ç, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ryo")] = QStringLiteral("¤ê¤ç,¥ê¥ç, , , , , , , , , , , , , ");
}

void keyboard::CreateKoreanMapLan()
{
	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");
}

void keyboard::FontSelect()
{
	ui->fontBox1_KBBut->setText(splitOut[j1]);
	ui->fontBox2_KBBut->setText(splitOut[j1+1]);
	ui->fontBox3_KBBut->setText(splitOut[j1+2]);
	ui->fontBox4_KBBut->setText(splitOut[j1+3]);
	ui->fontBox5_KBBut->setText(splitOut[j1+4]);
	ui->fontBox6_KBBut->setText(splitOut[j1+5]);
	ui->fontBox7_KBBut->setText(splitOut[j1+6]);
	ui->fontBox8_KBBut->setText(splitOut[j1+7]);
	ui->fontBox9_KBBut->setText(splitOut[j1+8]);
	ui->fontBox10_KBBut->setText(splitOut[j1+9]);
}


void keyboard::caps1_kBBut_clicked()
{
	if ( m_Upper == true )//Èç¹ûµ±Ç°ÎªÐ¡Ð´
	{
		switch (m_LanType)
		{

		case 0:  //chinese
			{
				LanChineseSmall();
				btnshow();
				btnArabicARhide();
				break;
			}
		case 1:  //Japanese
			{
				LanJapaneseSmall();
				btnshow();
				btnArabicARhide();
				break;
			}
		case 5:  //Arabic
			{
				LanArabic1();
				btnhide();
				btnArabicARshow();
				break;

			}
		case 3: //Chinese_others
		case 7:  //English
		case 21://Japanese_others
			{
				LanEnglishBig();
				btnArabicARhide();
				btnhide();
				break;
			}
		case 22: //Korean_others
			{
				LanKoreanSmall();
				btnshow();
				btnArabicARhide();
				break;
			}
		case 8:  //Czech
			{
				LanCzechBig();
				btnhide();
				btnArabicARhide();
				break;

			}
		case 9:  //Dutch
			{
				LanDutchBig();
				btnhide();
				btnArabicARhide();
				break;
			}
		case 10:  //German
			{
				LanGermanBig();
				btnArabicARhide();
				btnhide();
				break;
			}
		case 11:  //Finnish
			{
				LanFarsiBig();
				btnArabicARhide();
				btnhide();
				break;
			}
		case 12:  //Hindi
			{
				LanHindiBig();
				btnArabicARhide();
				btnhide();
				break;
			}
		}

		//case 5:  //Arabic
		//	{
		//		break;
		//	}
		//case 6:  //Farsi
		//	{
		//		break;
		//	}
		//case 8:  //Czech
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("¡¦"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("1"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("¡ã"));
		//		break;
		//	}
		//case 9:  //Dutch
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("`"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("¡À"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral(">"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("|"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("~"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("¡ì"));
		//		break;
		//	}
		//case 10: //German
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("-"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("¡ì"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("^"));
		//		break;
		//	}
		//case 11:  //Finnish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("`"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("¡è"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
		//		break;
		//	}
		//case 12:  //Hindi
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("???"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("???"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("???"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("???"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("??"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("??"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
		//		break;
		//	}
		//case 13:  //Hungarian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("+"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("¡ì"));
		//		break;
		//	}
		//case 14:  //Italian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("¡ã"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("¡ì"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("¨¦"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("|"));
		//		break;
		//	}
		//case 15:  //Portuguese
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(">"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("<"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("}"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("{"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("`"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("¡ª¡ª"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("£©"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("£¨"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("@"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("\""));
		//		break;
		//	}
		//case 16:  //Russian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("."));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("§À"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("§¢"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("§¾"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("§´"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("§ª"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("§®"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("§³"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("§¹"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("§Á"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("§¿"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("§¨"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("§¥"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("§­"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("§°"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("§²"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("§±"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("§¡"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("§£"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("§½"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("§¶"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("\\"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("§¼"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("§·"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("§©"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("§»"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("§º"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("§¤"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("§¯"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("§¦"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("§¬"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("§µ"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("§¸"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("§«"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("£©"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("¡í"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("§§"));
		//		break;
		//	}
		//case 17:  //Spanish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("¡§"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("¡¤"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
		//		break;
		//	}
		//case 18:  //Swedish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("`"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("¡è"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
		//		break;
		//	}
		//case 19:  //Thai
		//	{

		//	}
		//case 20:  //Turkish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral(","));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("."));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
//		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("*"));
//		//	}*/
//		m_Upper = true;
//	}
//	else
//	{
//		btnTextSel(m_LanType);
//		m_Upper = false;
//	}
//	
//}


//void keyboard::symbol_KBBut_clicked()
//{
//
//	if ( m_LantypeReverse == false )
//	{
//		switch (m_LantypeReverse)
//		{
//
//		case 24://SymbolR_others
//
//			ui->A_KBBut->setText("]");
//			/*ui->B_KBBut->setText("~");
//			ui->C_KBBut->setText("\");
//			ui->D_KBBut->setText("");
//			ui->E_KBBut->setText("#");
//			ui->F_KBBut->setText("");
//			ui->G_KBBut->setText(""");
//			ui->H_KBBut->setText(""");
//			ui->I_KBBut->setText("+");
//			ui->J_KBBut->setText("<");
//			ui->K_KBBut->setText(">");
//			ui->L_KBBut->setText("");
//			ui->M_KBBut->setText("M");
//			ui->N_KBBut->setText("N");
//			ui->O_KBBut->setText("O");
//			ui->P_KBBut->setText("P");
//			ui->Q_KBBut->setText("Q");
//			ui->R_KBBut->setText("R");
//			ui->S_KBBut->setText("S");
//			ui->T_KBBut->setText("T");
//			ui->U_KBBut->setText("U");
//			ui->V_KBBut->setText("V");
//			ui->W_KBBut->setText("W");
//			ui->X_KBBut->setText("X");
//			ui->Y_KBBut->setText("Y");
//			ui->Z_KBBut->setText("Z");*/
//			break;
		m_Upper = false;
		m_symbol = true;
	}
	else //µ±Ç°Îª´óÐ´
	{
		btnLanguageSel(m_LanType);
		m_Upper = true;
		m_symbol = true;
	}

}

void keyboard::symbol_KBBut_clicked()
{
	if ( m_symbol == true )//Èç¹ûµ±Ç°Îª×ÖÄ¸
	{
		switch (m_LantypeReverse)
		{
		case 0://English
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				break;
			}
		case 1://Chinese
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral("£º"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral("£»"));
				ui->G_KBBut->setText(QStringLiteral("¡°"));
				ui->H_KBBut->setText(QStringLiteral("¡±"));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("£¡"));
				ui->R_KBBut->setText(QStringLiteral("£¤"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("£¿"));
				break;
			}
		case 2://Kore
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral("£º"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral("£»"));
				ui->G_KBBut->setText(QStringLiteral("¡°"));
				ui->H_KBBut->setText(QStringLiteral("¡±"));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("£¡"));
				ui->R_KBBut->setText(QStringLiteral("£¤"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("£¿"));
				break;
			}
		case 3://Czech
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 4://Japanese
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				break;
			}
		case 5://Dutch
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 6://German
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 7://Farsi
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 8://Arabic
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 9://Arabic2
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 10://Arabic3
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 11://Arabic4
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("¡¶"));
				ui->K_KBBut->setText(QStringLiteral("¡·"));
				ui->L_KBBut->setText(QStringLiteral("¡¢"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("¡­"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		}
		m_symbol = false;
		btnhide();
	}
	else //µ±Ç°Îª·ûºÅ
	{
		btnSymbolSel(m_LantypeReverse);
		m_symbol = true;
	}
}

void keyboard::A_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->A_KBBut->text());
}

void keyboard::B_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->B_KBBut->text());
}

void keyboard::C_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->C_KBBut->text());
}

void keyboard::D_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->D_KBBut->text());
}

void keyboard::E_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->E_KBBut->text());
}

void keyboard::F_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->F_KBBut->text());
}

void keyboard::G_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->G_KBBut->text());
}

void keyboard::H_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->H_KBBut->text());
}

void keyboard::I_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->I_KBBut->text());
}

void keyboard::J_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->J_KBBut->text());
}

void keyboard::K_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->K_KBBut->text());
}

void keyboard::L_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->L_KBBut->text());
}

void keyboard::M_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->M_KBBut->text());
}

void keyboard::N_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->N_KBBut->text());
}

void keyboard::O_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->O_KBBut->text());
}

void keyboard::P_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->P_KBBut->text());
}

void keyboard::Q_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->Q_KBBut->text());
}

void keyboard::R_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->R_KBBut->text());
}

void keyboard::S_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->S_KBBut->text());
}

void keyboard::T_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->T_KBBut->text());
}

void keyboard::U_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->U_KBBut->text());
}

void keyboard::V_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->V_KBBut->text());
}

void keyboard::W_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->W_KBBut->text());
}

void keyboard::X_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->X_KBBut->text());
}

void keyboard::Y_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->Y_KBBut->text());
}

void keyboard::Z_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->Z_KBBut->text());
}

void keyboard::num1_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->one_KBBut->text());
}

void keyboard::num2_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->two_KBBut->text());
}

void keyboard::num3_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->three_KBBut->text());
}

void keyboard::num4_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->four_KBBut->text());
}

void keyboard::num5_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->five_KBBut->text());
}

void keyboard::num6_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->six_KBBut->text());
}

void keyboard::num7_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->seven_KBBut->text());
}

void keyboard::num8_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->eight_KBBut->text());
}

void keyboard::num9_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->nine_KBBut->text());
}

void keyboard::num0_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->zero_KBBut->text());
}

void keyboard::fontBox1_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox1_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox2_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox2_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox3_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox3_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox4_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox4_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox5_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox5_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox6_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox6_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox7_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox7_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox8_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox8_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox9_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox9_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox10_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox10_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBoxRedu_KBBut_clicked()
{
	if(i1 != 0)
	{
		j1 = j1 - 10;
		if ( j1 >= 0 )
		{
			FontSelect();
		} 
		else if( j1 < 1 )
		{
			j1 = 0;
	    }
	}
}

void keyboard::fontBoxAdd_KBBut_clicked()
{
	if(i1 != 0)
	{
		j1 = j1 + 10;
		if ( j1 < i1  )
		{
			FontSelect();
		} 
		else if( j1 > i1 )
		{
			j1 = i1 - 1;
			j1 = j1 - 10;
		}
	}
}

void keyboard::space_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(" ");
}

void keyboard::comma_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->comma_KBBut->text());
}

void keyboard::period_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->period_KBBut->text());
}

void keyboard::lanArabicAdd_KBBut_clicked()
{
	if (m_LanType == 5)
	{
		m_LanType = 23;
		m_LantypeReverse = 9;
		LanArabic2();
	}
	else if (m_LanType == 23)
	{
		m_LanType = 24;
		m_LantypeReverse = 10;
		LanArabic3();
	} 
	else if (m_LanType == 24)
	{
		m_LanType = 25;
		m_LantypeReverse= 11;
		LanArabic4();
	} 
	else if (m_LanType  == 25)
	{
		m_LanType =5;
		m_LantypeReverse = 8;
		LanArabic1();
	} 
}

void keyboard::lanArabicRedu_KBBut_clicked()
{

	if (m_LanType == 5)
	{
		m_LanType = 25;
		LanArabic4();
	}
	else if (m_LanType == 25)
	{
		m_LanType = 24;
		LanArabic3();
	} 
	else if (m_LanType == 24)
	{
		m_LanType = 23;
		LanArabic2();
	} 
	else if (m_LanType  == 23)
	{
		m_LanType =5;
		LanArabic1();
	} 
}

void keyboard::btnshow()
{
	//QWidget *qw=new QWidget(this);
	//qw->setGeometry(20,10,750,30);
	//QHBoxLayout *qb=new QHBoxLayout(qw);
	//QPushButton *pb2=new QPushButton("first");
	//qb->addWidget(pb2);
	ui->fontBox1_KBBut->show();
	ui->fontBox2_KBBut->show();
	ui->fontBox3_KBBut->show();
	ui->fontBox4_KBBut->show();
	ui->fontBox5_KBBut->show();
	ui->fontBox6_KBBut->show();
	ui->fontBox7_KBBut->show();
	ui->fontBox8_KBBut->show();
	ui->fontBox9_KBBut->show();
	ui->fontBox10_KBBut->show();
	ui->fontBoxRedu_KBBut->show();
	ui->fontBoxAdd_KBBut->show();
	ui->wordCombLineEdit->show();

}

void keyboard::btnArabicARshow()
{
	ui->languageAdd_KBBut->show();
	ui->languageRedu_KBBut->show();
}

void keyboard::btnLanguageSel(int m_LanType)
{
	switch (m_LanType)
	{

	case 0:  //chinese
	case 1:  //Japanese
		{
			LanJapaneseBig();
			btnhide();
			break;
		}
	case 3:  //Chinese_others
	case 21: //Japanese_others
		{
			LanChineseBig();
			btnhide();
		//	pWnd->btnShow();
		//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
	case 2:  //Korean
	case 22: //Korean_others
		{
			LanKoreanBig();
			btnhide();
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
			LanEnglishSmall();
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 8:  //Czech
		{
			LanCzechSmall();
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 9:  //Dutch
		{
		    LanDutchSmall();
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 10: //German
		{
			LanGermanSmall();
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 11:  //FarsiSmall
		{
		    LanFarsiSmall();
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 12:  //Hindi
		{
		    LanHindiSmall();
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 13:  //Hungarian
		{
		    //LanHindiBig();
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

void keyboard::btnSymbolSel(int m_LantypeReverse)
{
	switch (m_LantypeReverse)
	{
		case 0: //µ±Ç°ÎªEnglishSymbol
		{
			SymbolToEnglish();
			btnhide();

			//	pWnd->btnShow();
			//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 1: //µ±Ç°ÎªChineseSymbol
		{
			SymbolToChinese();
			//	pWnd->btnShow();
			//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 2: //µ±Ç°ÎªKoreSymbol
		{
			SymbolToKore();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 3: //µ±Ç°ÎªKoreSymbol
		{
			SymbolToCzech();
			btnhide();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 4: //µ±Ç°ÎªKoreSymbol
		{
			SymbolToJapanese();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 5:
		{
			SymbolToDutch();
			btnhide();
			break;
		}
		case 6:
		{
			SymbolToGerman();
			btnhide();
			break;
		}
		case 7:
		{
			SymbolToFarsi();
			btnhide();
			break;
		}
		case 8://µ±Ç°ÎªArabicSymbol
		{
			SymbolToArabic();
			btnhide();
			break;
		}
		case 9://µ±Ç°ÎªArabic2Symbol
			{
				SymbolToArabic2();
				btnhide();
				break;
			}
		case 10://µ±Ç°ÎªArabic3Symbol
			{
				SymbolToArabic3();
				btnhide();
				break;
			}
		case 11://µ±Ç°ÎªArabic4Symbol
			{
				SymbolToArabic4();
				btnhide();
				break;
			}
	}

}

void keyboard::LanArabic1()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->comma_KBBut->setText(QStringLiteral("?"));
	ui->period_KBBut->setText(QStringLiteral("?"));
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("?"));//ÒÑÓÃ
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));//ÒÑÓÃ
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));*/
}

void keyboard::LanArabic2()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->comma_KBBut->setText(QStringLiteral("?"));
	ui->period_KBBut->setText(QStringLiteral("?"));
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("?"));//ÒÑÓÃ
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));//ÒÑÓÃ
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));*/
}

void keyboard::LanArabic3()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->comma_KBBut->setText(QStringLiteral("?"));
	ui->period_KBBut->setText(QStringLiteral("?"));
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("?"));//ÒÑÓÃ
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));//ÒÑÓÃ
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));*/
}

void keyboard::LanArabic4()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral(""));
	ui->C_KBBut->setText(QStringLiteral(""));
	ui->D_KBBut->setText(QStringLiteral(""));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral(""));
	ui->G_KBBut->setText(QStringLiteral(""));
	ui->H_KBBut->setText(QStringLiteral(""));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral(""));
	ui->K_KBBut->setText(QStringLiteral(""));
	ui->L_KBBut->setText(QStringLiteral(""));
	ui->M_KBBut->setText(QStringLiteral(""));
	ui->N_KBBut->setText(QStringLiteral(""));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral(""));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral(""));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral(""));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral(""));
	ui->comma_KBBut->setText(QStringLiteral(""));
	ui->period_KBBut->setText(QStringLiteral(""));
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral(""));

	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));*/
}


void keyboard::LanEnglishSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("y");
	ui->Z_KBBut->setText("z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
	/*
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("'"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral(";"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("\\"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("]"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("["));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("y"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("="));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("`"));
	*/
}

void keyboard::LanEnglishBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Y");
	ui->Z_KBBut->setText("Z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanChineseSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("y");
	ui->Z_KBBut->setText("z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
	btnshow();
}

void keyboard::LanChineseBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Y");
	ui->Z_KBBut->setText("Z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanKoreanSmall()//º«ÓïÐ¡Ð´
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
	btnshow();

//
//
//
//	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("/"));
//	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("."));
//	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(","));
//	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("'"));
//	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral(";"));
//	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("\\"));
//	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("]"));
//	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("["));
//	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("="));
//	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("-"));
//	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("0"));
//	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("9"));
//	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("8"));
//	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("7"));
//	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("6"));
//	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("5"));
//	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("4"));
//	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("3"));
//	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("2"));
//	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("1"));
//	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("`"));*/
//}
}

void keyboard::LanKoreanBig()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral(""));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral(""));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral(""));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral(""));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanCzechSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("z");
	ui->Z_KBBut->setText("y");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("¨§"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("¨¢"));
	ui->nine_KBBut->setText(QStringLiteral("¨ª"));
	ui->zero_KBBut->setText(QStringLiteral("¨¦"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("y"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("¡ì"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("¡§"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral(")"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("¨²"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("z"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("="));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("¨¦"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("¨ª"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("¨¢"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("¨§"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("+"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral(";"));*/
}

void keyboard::LanCzechBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Z");
	ui->Z_KBBut->setText("Y");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Y"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("!"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("'"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("("));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("¡¦"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("%"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("¡ã"));*/
}

void keyboard::LanJapaneseSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("y");
	ui->Z_KBBut->setText("z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
	btnshow();
}

void keyboard::LanJapaneseBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Y");
	ui->Z_KBBut->setText("Z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanDutchSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("y");
	ui->Z_KBBut->setText("z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanDutchBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Y");
	ui->Z_KBBut->setText("Z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("!"));
	ui->two_KBBut->setText(QStringLiteral("\\"));
	ui->three_KBBut->setText(QStringLiteral("#"));
	ui->four_KBBut->setText(QStringLiteral("$"));
	ui->five_KBBut->setText(QStringLiteral("%"));
	ui->six_KBBut->setText(QStringLiteral("&&"));
	ui->seven_KBBut->setText(QStringLiteral("_"));
	ui->eight_KBBut->setText(QStringLiteral("("));
	ui->nine_KBBut->setText(QStringLiteral(")"));
	ui->zero_KBBut->setText(QStringLiteral("'"));
	//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("="));
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("`"));
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("¡À"));
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral(">"));
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("|"));
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("^"));
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
	//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("~"));
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("'"));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("_"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("¡ì"));
	//		break;
}

void keyboard::LanGermanSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("z");
	ui->Z_KBBut->setText("y");
	ui->comma_KBBut->setText(QStringLiteral("?"));
	ui->period_KBBut->setText(QStringLiteral("?"));
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanGermanBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Z");
	ui->Z_KBBut->setText("Y");
	ui->comma_KBBut->setText(QStringLiteral("?"));//µÂÓïÕâÀïÃ»ÓÐ¶ººÅ
	ui->period_KBBut->setText(QStringLiteral("?"));//µÂÓïµÄ×¨Êô·ûºÅ
	ui->one_KBBut->setText(QStringLiteral("!"));
	ui->two_KBBut->setText(QStringLiteral("\\"));
	ui->three_KBBut->setText(QStringLiteral("¡ì"));
	ui->four_KBBut->setText(QStringLiteral("$"));
	ui->five_KBBut->setText(QStringLiteral("%"));
	ui->six_KBBut->setText(QStringLiteral("&&"));
	ui->seven_KBBut->setText(QStringLiteral("_"));
	ui->eight_KBBut->setText(QStringLiteral("("));
	ui->nine_KBBut->setText(QStringLiteral(")"));
	ui->zero_KBBut->setText(QStringLiteral("'"));
}

void keyboard::LanFarsiSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("y");
	ui->Z_KBBut->setText("z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("¡è"));
	ui->three_KBBut->setText(QStringLiteral("`"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("'"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("¡ì"));
	ui->zero_KBBut->setText(QStringLiteral("¡§"));
}

void keyboard::LanFarsiBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Y");
	ui->Z_KBBut->setText("Z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("¡è"));
	ui->three_KBBut->setText(QStringLiteral("`"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("'"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("¡ì"));
	ui->zero_KBBut->setText(QStringLiteral("¡§"));
	//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("'"));
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
	//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("`"));
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("¡è"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
	//		break;
	//	}
}

void keyboard::LanHindiSmall()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("??"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));*/
}

void keyboard::LanHindiBig()
{                                                //ºÜ¶à·ûºÅÃ»ÓÐ·ÅÉÏ
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("??"));
	ui->four_KBBut->setText(QStringLiteral("??"));
	ui->five_KBBut->setText(QStringLiteral("???"));
	ui->six_KBBut->setText(QStringLiteral("???"));
	ui->seven_KBBut->setText(QStringLiteral("???"));
	ui->eight_KBBut->setText(QStringLiteral("???"));
	ui->nine_KBBut->setText(QStringLiteral("("));
	ui->zero_KBBut->setText(QStringLiteral(")"));
	//      GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));  Ã»·ÅÉÏ
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("?"));   Ã»·ÅÉÏ
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));   Ã»·ÅÉÏ
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));   Ã»·ÅÉÏ
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));    Ã»·ÅÉÏ
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));   Ã»·ÅÉÏ
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));    Ã»·ÅÉÏ
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));     Ã»·ÅÉÏ
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));    Ã»·ÅÉÏ
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral(")"));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("("));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("???"));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("???"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("???"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("???"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("??"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("??"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
	//		break;
}

void keyboard::SymbolToEnglish()
{
	LanEnglishBig();
	m_Upper = false;
}

void keyboard::SymbolToChinese()
{
	LanChineseSmall();
	m_Upper = false;
}

void keyboard::SymbolToKore()
{
	LanKoreanSmall();
	m_Upper = false;
}

void keyboard::SymbolToCzech()
{
	LanCzechBig();
	m_Upper = false;
}

void keyboard::SymbolToJapanese()
{
	LanJapaneseSmall();
	m_Upper = false;
}

void keyboard::SymbolToDutch()
{
	LanDutchBig();
	m_Upper = false;
}

void keyboard::SymbolToGerman()
{
	LanGermanBig();
	m_Upper = false;
}

void keyboard::SymbolToFarsi()
{
	LanFarsiBig();
	m_Upper = false;
}

void keyboard::SymbolToHindi()
{
	LanHindiBig();
	m_Upper = false;
}

void keyboard::SymbolToArabic()
{
	LanArabic1();
	m_Upper = false;
}

void keyboard::SymbolToArabic2()
{
	LanArabic2();
	m_Upper = false;
}

void keyboard::SymbolToArabic3()
{
	LanArabic3();
	m_Upper = false;
}

void keyboard::SymbolToArabic4()
{
	LanArabic4();
	m_Upper = false;
}
