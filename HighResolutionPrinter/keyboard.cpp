#include "keyboard.h"
#include "ui_keyboard.h"
#include <QAction>
#include <QtWidgets/QStackedWidget>
#include "lineedit_click.h"
#include "language.h"
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
	connect(ui->languageAdd_KBBut,SIGNAL(clicked()),this,SLOT(languageAdd_KBBut_clicked()));
	connect(ui->languageRedu_KBBut,SIGNAL(clicked()),this,SLOT(languageRedu_KBBut_clicked()));

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

	//connect(languageWidget,SIGNAL(languageEvent()),this,SLOT(esc_kBBut_clicked()));//父窗口执行槽函数


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
	m_pInputEdit->backspace();
	QString str1 = m_pInputEdit->text();
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


void keyboard::languagespell()   //获取中文编辑框内的拼音 将对应的汉字置入备选框中
{
	QString key = m_pInputEdit->text();
	CreateChineseMapLan();
	QString value = ChineseLanMap[key];
	if ( value == "" )          
	{	
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
		QStringList temp = value.split(",");//以逗号分割字符串，将备选的每个汉字单独分割成一个字符串
		int length = temp.length();//读取分割后的字符串个数

		for ( int i =0 ;i < length;i++)//遍历，将每一个字符串置入到vector对应的位置
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
		splitOut.clear();
		//break;
	}
}

void keyboard::CreateChineseMapLan()
{
	ChineseLanMap[QStringLiteral("an")] = QStringLiteral("安,氨,鞍,俺,岸,按,案,胺,暗, , , , , , ");
	ChineseLanMap[QStringLiteral("ai")] = QStringLiteral("哎,哀,唉,埃,挨,皑,癌,矮,蔼,艾,爱,隘,碍, , ");
	ChineseLanMap[QStringLiteral("a")] = QStringLiteral("阿,啊, , , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("yi")] = QStringLiteral("一,伊,衣,医,依,铱,壹,揖,仪,夷,沂,宜,姨,胰,移,遗,颐,疑,彝,乙,已,以,矣,蚁,倚,椅,义,亿,忆,艺,议,亦,屹,异,役,抑,译,邑,易,绎,诣,疫,益,谊,翌,逸,意,溢,肄,裔,毅,翼,臆, , , , , , , , , ");
	ChineseLanMap[QStringLiteral("ang")] = QStringLiteral("肮,昂,盎, , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("ao")] = QStringLiteral("凹,敖,熬,翱,袄,傲,奥,澳,懊, , , , , , ");
	ChineseLanMap[QStringLiteral("ba")] = QStringLiteral("八,巴,叭,扒,吧,疤,捌,笆,拔,跋,把,靶,坝,爸,罢,霸, , , , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bai")] = QStringLiteral("白,百,佰,柏,摆,败,拜,稗, , , , , , , ");
	ChineseLanMap[QStringLiteral("ban")] = QStringLiteral("扳,班,般,颁,斑,搬,板,版,办,半,伴,扮,拌,绊,瓣");
	ChineseLanMap[QStringLiteral("bang")] = QStringLiteral("邦,帮,梆,绑,榜,膀,蚌,傍,棒,谤,磅,镑, , , ");
	ChineseLanMap[QStringLiteral("bao")] = QStringLiteral("包,苞,胞,褒,雹,宝,饱,保,堡,报,抱,豹,鲍,暴,爆,剥,薄,瀑, , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bei")] = QStringLiteral("卑,杯,悲,碑,北,贝,狈,备,背,钡,倍,被,惫,焙,辈");
	ChineseLanMap[QStringLiteral("ben")] = QStringLiteral("奔,本,苯,笨,夯, , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("beng")] = QStringLiteral("崩,绷,甭,泵,迸,蹦, , , , , , , , ,");

	ChineseLanMap[QStringLiteral("bi")] = QStringLiteral("逼,鼻,比,彼,笔,鄙,币,必,毕,闭,庇,毖,陛,毙,敝,痹,蓖,弊,碧,蔽,壁,避,臂, , , , , , , ");
	ChineseLanMap[QStringLiteral("bian")] = QStringLiteral("边,编,鞭,贬,扁,卞,便,变,遍,辨,辩,辫, , , ");
	ChineseLanMap[QStringLiteral("biao")] = QStringLiteral("彪,标,膘,表, , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bie")] = QStringLiteral("憋,鳖,别,瘪, , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bin")] = QStringLiteral("宾,彬,斌,滨,濒,摈, , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bing")] = QStringLiteral("冰,兵,丙,秉,柄,炳,饼,并,病, , , , , , ");
	ChineseLanMap[QStringLiteral("bo")] = QStringLiteral("拨,波,玻,钵,脖,菠,播,伯,驳,帛,泊,勃,铂,舶,博,渤,搏,箔,膊,卜, , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bu")] = QStringLiteral("补,哺,捕,不,布,步,怖,部,埠,簿, , , , , ");
	ChineseLanMap[QStringLiteral("ca")] = QStringLiteral("擦, , , , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("cai")] = QStringLiteral("猜,才,材,财,裁,采,彩,睬,踩,菜,蔡, , , , ");
	ChineseLanMap[QStringLiteral("can")] = QStringLiteral("参,餐,残,蚕,惭,惨,灿, , , , , , , , ");
	ChineseLanMap[QStringLiteral("cang")] = QStringLiteral("仓,沧,苍,舱,藏, , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("cao")] = QStringLiteral("操,糙,曹,槽,草, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ce")] = QStringLiteral("册,侧,厕,测,策, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ceng")] = QStringLiteral("层,蹭,曾, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cha")] = QStringLiteral("叉,插,查,茬,茶,搽,察,碴,岔,诧,差,刹, , , ");


	ChineseLanMap[QStringLiteral("chai")] = QStringLiteral("拆,柴,豺, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chan")] = QStringLiteral("掺,搀,谗,馋,缠,蝉,产,铲,阐,颤, , , , , ");


	ChineseLanMap[QStringLiteral("chang")] = QStringLiteral("昌,猖,肠,尝,偿,常,厂,场,敞,畅,倡,唱, , , ");


	ChineseLanMap[QStringLiteral("chao")] = QStringLiteral("抄,钞,超,巢,朝,嘲,潮,吵,炒,绰, , , , , ");


	ChineseLanMap[QStringLiteral("che")] = QStringLiteral("车,扯,彻,掣,撤,澈, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chen")] = QStringLiteral("郴,尘,臣,忱,沉,辰,陈,晨,衬,趁, , , , , ");


	ChineseLanMap[QStringLiteral("cheng")] = QStringLiteral("称,撑,成,呈,承,诚,城,乘,惩,程,澄,橙,逞,骋,秤");


	ChineseLanMap[QStringLiteral("chi")] = QStringLiteral("吃,痴,弛,池,驰,迟,持,尺,侈,齿,耻,斥,赤,炽,翅");


	ChineseLanMap[QStringLiteral("chong")] = QStringLiteral("充,冲,虫,崇,宠, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chou")] = QStringLiteral("抽,仇,绸,畴,愁,稠,筹,酬,踌,丑,瞅,臭, , , ");


	ChineseLanMap[QStringLiteral("chu")] = QStringLiteral("出,初,除,厨,滁,锄,雏,橱,躇,础,储,楚,处,搐,触,矗,畜, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuai")] = QStringLiteral("揣, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuan")] = QStringLiteral("川,穿,传,船,椽,喘,串, , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuang")] = QStringLiteral("闯,疮,窗,床,创, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chun")] = QStringLiteral("春,椿,纯,唇,淳,醇,蠢, , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuo")] = QStringLiteral("戳, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ci")] = QStringLiteral("疵,词,茨,瓷,慈,辞,磁,雌,此,次,刺,赐, , , ");


	ChineseLanMap[QStringLiteral("cong")] = QStringLiteral("囱,从,匆,葱,聪,丛, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cou")] = QStringLiteral("凑, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cu")] = QStringLiteral("粗,促,醋,簇, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cuan")] = QStringLiteral("蹿,窜,篡, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cui")] = QStringLiteral("崔,催,摧,脆,淬,瘁,粹,翠, , , , , , , ");


	ChineseLanMap[QStringLiteral("cun")] = QStringLiteral("村,存,寸, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cuo")] = QStringLiteral("搓,磋,撮,挫,措,错, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("da")] = QStringLiteral("搭,达,答,瘩,打,大, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dai")] = QStringLiteral("呆,歹,傣,代,带,待,怠,殆,贷,袋,逮,戴, , , ");


	ChineseLanMap[QStringLiteral("dan")] = QStringLiteral("丹,单,担,耽,郸,胆,掸,旦,但,诞,弹,惮,淡,蛋,氮");


	ChineseLanMap[QStringLiteral("dang")] = QStringLiteral("当,挡,党,荡,档, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dao")] = QStringLiteral("刀,导,岛,倒,捣,祷,蹈,到,悼,盗,道,稻, , , ");


	ChineseLanMap[QStringLiteral("de")] = QStringLiteral("得,德,的, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("deng")] = QStringLiteral("灯,登,蹬,等,邓,凳,瞪, , , , , , , , ");


	ChineseLanMap[QStringLiteral("di")] = QStringLiteral("低,堤,滴,狄,迪,敌,涤,笛,嫡,底,抵,地,弟,帝,递,第,缔,蒂, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dian")] = QStringLiteral("掂,滇,颠,典,点,碘,电,佃,甸,店,垫,惦,淀,奠,殿,靛, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("diao")] = QStringLiteral("刁,叼,凋,碉,雕,吊,钓,掉, , , , , , , ");


	ChineseLanMap[QStringLiteral("die")] = QStringLiteral("爹,跌,迭,谍,叠,碟,蝶, , , , , , , , ");


	ChineseLanMap[QStringLiteral("ding")] = QStringLiteral("丁,叮,盯,钉,顶,鼎,订,定,锭, , , , , , ");


	ChineseLanMap[QStringLiteral("diu")] = QStringLiteral("丢, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dong")] = QStringLiteral("东,冬,董,懂,动,冻,侗,恫,栋,洞, , , , , ");


	ChineseLanMap[QStringLiteral("dou")] = QStringLiteral("都,兜 ,斗,抖,陡,豆,逗,痘, , , , , , , ");


	ChineseLanMap[QStringLiteral("du")] = QStringLiteral("督,毒,读,犊,独,堵,赌,睹,妒,杜,肚,度,渡,镀, ");


	ChineseLanMap[QStringLiteral("duan")] = QStringLiteral("端,短,段,断,缎,锻, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dui")] = QStringLiteral("堆,队,对,兑, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dun")] = QStringLiteral("吨,敦,墩,蹲,盾,钝,顿,遁, , , , , , , ");


	ChineseLanMap[QStringLiteral("duo")] = QStringLiteral("多,哆,夺,掇,朵,垛,躲,剁,堕,舵,惰,跺, , , ");


	ChineseLanMap[QStringLiteral("e")] = QStringLiteral("讹,俄,娥,峨,鹅,蛾,额,厄,扼,恶,饿,鄂,遏, , ");


	ChineseLanMap[QStringLiteral("en")] = QStringLiteral("恩, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("er")] = QStringLiteral("儿,而,尔,耳,洱,饵,二,贰, , , , , , , ");


	ChineseLanMap[QStringLiteral("fa")] = QStringLiteral("发,乏,伐,罚,阀,筏,法,珐, , , , , , , ");



	ChineseLanMap[QStringLiteral("fan")] = QStringLiteral("帆,番,翻,藩,凡,矾,钒,烦,樊,繁,反,返,犯,泛,饭,范,贩, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("fang")] = QStringLiteral("方,坊,芳,防,妨,房,肪,仿,访,纺,放, , , , ");


	ChineseLanMap[QStringLiteral("fei")] = QStringLiteral("飞,非,啡,菲,肥,匪,诽,吠,废,沸,肺,费, , , ");


	ChineseLanMap[QStringLiteral("fen")] = QStringLiteral("分,吩,纷,芬,氛,酚,坟,汾,焚,粉,份,奋,忿,愤,粪");


	ChineseLanMap[QStringLiteral("feng")] = QStringLiteral("丰,风,枫,封,疯,峰,烽,锋,蜂,冯,逢,缝,讽,凤,奉");


	ChineseLanMap[QStringLiteral("fo")] = QStringLiteral("佛, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("fou")] = QStringLiteral("否, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("fu")] = QStringLiteral("夫,肤,孵,敷,弗,伏,扶,拂,服,俘,氟,浮,涪,符,袱,幅,福,辐,抚,甫,府,斧,俯,釜,辅,腑,腐,父,讣,付,妇,负,附,咐,阜,复,赴,副,傅,富,赋,缚,腹,覆, ");


	ChineseLanMap[QStringLiteral("ga")] = QStringLiteral("嘎,噶, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gai")] = QStringLiteral("该,改,钙,盖,溉,概, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gan")] = QStringLiteral("干,甘,杆,肝,柑,竿,秆,赶,敢,感,赣, , , , ");


	ChineseLanMap[QStringLiteral("gang")] = QStringLiteral("冈,刚,岗,纲,肛,缸,钢,港,杠, , , , , , ");


	ChineseLanMap[QStringLiteral("gao")] = QStringLiteral("皋,羔,高,膏,篙,糕,搞,稿,镐,告, , , , , ");


	ChineseLanMap[QStringLiteral("ge")] = QStringLiteral("戈,疙,哥,胳,鸽,割,搁,歌,阁,革,格,葛,隔,个,各,铬,咯, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gei")] = QStringLiteral("给, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gen")] = QStringLiteral("根,跟, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("geng")] = QStringLiteral("更,庚,耕,羹,埂,耿,梗, , , , , , , , ");


	ChineseLanMap[QStringLiteral("gong")] = QStringLiteral("工,弓,公,功,攻,供,宫,恭,躬,龚,巩,汞,拱,共,贡");


	ChineseLanMap[QStringLiteral("gou")] = QStringLiteral("勾,沟,钩,狗,苟,构,购,垢,够, , , , , , ");


	ChineseLanMap[QStringLiteral("gu")] = QStringLiteral("估,咕,姑,孤,沽,菇,辜,箍,古,谷,股,骨,蛊,鼓,固,故,顾,雇, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gua")] = QStringLiteral("瓜,刮,剐,寡,挂,褂, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("guai")] = QStringLiteral("乖,拐,怪, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("guan")] = QStringLiteral("关,观,官,冠,棺,馆,管,贯,惯,灌,罐, , , , ");


	ChineseLanMap[QStringLiteral("guang")] = QStringLiteral("光,广,逛, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gui")] = QStringLiteral("归,圭,龟,规,闺,硅,瑰,轨,诡,癸,鬼,刽,柜,贵,桂,跪, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gun")] = QStringLiteral("辊,滚,棍, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("guo")] = QStringLiteral("郭,锅,国,果,裹,过, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ha")] = QStringLiteral("蛤,哈, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hai")] = QStringLiteral("孩,骸,海,亥,骇,害,氦, , , , , , , , ");


	ChineseLanMap[QStringLiteral("han")] = QStringLiteral("酣,憨,含,邯,函,涵,寒,韩,罕,喊,汉,汗,旱,悍,捍,焊,憾,撼,翰, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hang")] = QStringLiteral("杭,航,行, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hao")] = QStringLiteral("毫,豪,嚎,壕,好,郝,号,浩,耗, , , , , , ");


	ChineseLanMap[QStringLiteral("he")] = QStringLiteral("呵,喝,禾,合,何,和,河,阂,核,荷,涸,盒,菏,贺,褐,赫,鹤, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hei")] = QStringLiteral("黑,嘿, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hen")] = QStringLiteral("痕,很,狠,恨, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("heng")] = QStringLiteral("亨,哼,恒,横,衡, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hong")] = QStringLiteral("轰,哄,烘,弘,红,宏,洪,虹,鸿, , , , , , ");


	ChineseLanMap[QStringLiteral("hou")] = QStringLiteral("侯,喉,猴,吼,后,厚,候, , , , , , , , ");


	ChineseLanMap[QStringLiteral("hu")] = QStringLiteral("乎,呼,忽,弧,狐,胡,壶,湖,葫,瑚,糊,蝴,虎,唬,互,户,护,沪, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hua")] = QStringLiteral("花,华,哗,滑,猾,化,划,画,话, , , , , , ");


	ChineseLanMap[QStringLiteral("huai")] = QStringLiteral("怀,徊,淮,槐,坏, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("huan")] = QStringLiteral("欢,还,环,桓,缓,幻,宦,唤,换,涣,患,焕,痪,豢, ");


	ChineseLanMap[QStringLiteral("huang")] = QStringLiteral("荒,慌,皇,凰,黄,惶,煌,蝗,磺,簧,恍,晃,谎,幌, ");


	ChineseLanMap[QStringLiteral("hui")] = QStringLiteral("灰,恢,挥,辉,徽,回,蛔,悔,卉,汇,会,讳,绘,诲,烩,贿,晦,秽,惠,毁,慧, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hun")] = QStringLiteral("昏,荤,婚,浑,魂,混, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("huo")] = QStringLiteral("豁,活,火,伙,或,货,获,祸,惑,霍, , , , , ");


	ChineseLanMap[QStringLiteral("ji")] = QStringLiteral("讥,击,饥,圾,机,肌,鸡,迹,姬,积,基,绩,缉,畸,箕,稽,激,及,吉,汲,级,即,极,急,疾,棘,集,嫉,辑,籍,几,己,挤,脊,计,记,伎,纪,妓,忌,技,际,剂,季,既,济,继,寂,寄,悸,祭,蓟,冀,藉, , , , , , ");


	ChineseLanMap[QStringLiteral("jia")] = QStringLiteral("加,夹,佳,枷,家,嘉,荚,颊,甲,贾,钾,价,驾,架,假,嫁,稼,挟, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("jian")] = QStringLiteral("奸,尖,坚,歼,间,肩,艰,兼,监,笺,缄,煎,拣,俭,柬,茧,捡,减,剪,检,硷,简,碱,见,件,建,饯,剑,荐,贱,健,涧,舰,渐,溅,践,鉴,键,箭, , , , , , ");


	ChineseLanMap[QStringLiteral("jiang")] = QStringLiteral("江,姜,将,浆,僵,疆,讲,奖,桨,蒋,匠,降,酱, , ");


	ChineseLanMap[QStringLiteral("jiao")] = QStringLiteral("交,郊,娇,浇,骄,胶,椒,焦,蕉,礁,角,狡,绞,饺,矫,脚,铰,搅,剿,缴,叫,轿,较,教,窖,酵,觉,嚼, , ");


	ChineseLanMap[QStringLiteral("jie")] = QStringLiteral("阶,皆,接,秸,揭,街,节,劫,杰,洁,结,捷,睫,截,竭,姐,解,介,戒,芥,届,界,疥,诫,借, , , , , ");


	ChineseLanMap[QStringLiteral("jin")] = QStringLiteral("巾,今,斤,金,津,筋,襟,仅,紧,谨,锦,尽,劲,近,进,晋,浸,烬,禁,靳, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("jing")] = QStringLiteral("京,经,茎,荆,惊,晶,睛,粳,兢,精,鲸,井,颈,景,警,净,径,痉,竞,竟,敬,靖,境,静,镜, , , , , ");


	ChineseLanMap[QStringLiteral("jiong")] = QStringLiteral("炯,窘, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("jiu")] = QStringLiteral("纠,究,揪,九,久,灸,玖,韭,酒,旧,臼,咎,疚,厩,救,就,舅, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ju")] = QStringLiteral("居,拘,狙,驹,疽,鞠,局,桔,菊,咀,沮,举,矩,句,巨,拒,具,炬,俱,剧,惧,据,距,锯,聚,踞, , , , ");


	ChineseLanMap[QStringLiteral("juan")] = QStringLiteral("娟,捐,鹃,卷,倦,绢,眷, , , , , , , , ");


	ChineseLanMap[QStringLiteral("jue")] = QStringLiteral("撅,决,诀,抉,绝,倔,掘,爵,攫, , , , , , ");


	ChineseLanMap[QStringLiteral("jun")] = QStringLiteral("军,君,均,钧,菌,俊,郡,峻,浚,骏,竣, , , , ");


	ChineseLanMap[QStringLiteral("ka")] = QStringLiteral("咖,喀,卡, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kai")] = QStringLiteral("开,揩,凯,慨,楷, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kan")] = QStringLiteral("槛,刊,勘,堪,坎,砍,看, , , , , , , , ");


	ChineseLanMap[QStringLiteral("kang")] = QStringLiteral("康,慷,糠,扛,亢,抗,炕, , , , , , , , ");


	ChineseLanMap[QStringLiteral("kao")] = QStringLiteral("考,拷,烤,靠, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ke")] = QStringLiteral("坷,苛,柯,科,棵,颗,磕,壳,咳,可,渴,克,刻,客,课");


	ChineseLanMap[QStringLiteral("ken")] = QStringLiteral("肯,垦,恳,啃, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("keng")] = QStringLiteral("吭,坑, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kong")] = QStringLiteral("空,孔,恐,控, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kou")] = QStringLiteral("抠,口,扣,寇, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ku")] = QStringLiteral("枯,哭,窟,苦,库,裤,酷, , , , , , , , ");


	ChineseLanMap[QStringLiteral("kua")] = QStringLiteral("夸,垮,挎,胯,跨, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuai")] = QStringLiteral("块,快,侩,筷, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuan")] = QStringLiteral("宽,款, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuang")] = QStringLiteral("匡,筐,狂,况,旷,矿,框,眶, , , , , , , ");


	ChineseLanMap[QStringLiteral("kui")] = QStringLiteral("亏,岿,盔,窥,奎,葵,魁,傀,愧,溃,馈, , , , ");


	ChineseLanMap[QStringLiteral("kun")] = QStringLiteral("坤,昆,捆,困, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuo")] = QStringLiteral("扩,括,阔,廓, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("la")] = QStringLiteral("垃,拉,啦,喇,腊,蜡,辣, , , , , , , , ");


	ChineseLanMap[QStringLiteral("lai")] = QStringLiteral("来,莱,赖, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lan")] = QStringLiteral("兰,拦,栏,婪,阑,蓝,谰,澜,篮,览,揽,缆,懒,烂,滥");


	ChineseLanMap[QStringLiteral("lang")] = QStringLiteral("郎,狼,廊,琅,榔,朗,浪, , , , , , , , ");


	ChineseLanMap[QStringLiteral("lao")] = QStringLiteral("捞,劳,牢,老,佬,姥,涝,烙,酪, , , , , , ");


	ChineseLanMap[QStringLiteral("le")] = QStringLiteral("乐,勒,了, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lei")] = QStringLiteral("雷,镭,垒,磊,蕾,儡,肋,泪,类,累,擂, , , , ");


	ChineseLanMap[QStringLiteral("leng")] = QStringLiteral("棱,楞,冷, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("li")] = QStringLiteral("厘,梨,狸,离,莉,犁,漓,璃,黎,篱,礼,李,里,哩,理,鲤,力,历,厉,立,吏,丽,利,励,沥,例,隶,俐,荔,栗,砾,粒,傈,痢, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lian")] = QStringLiteral("连,帘,怜,涟,莲,联,廉,镰,敛,脸,练,炼,恋,链, ");


	ChineseLanMap[QStringLiteral("liang")] = QStringLiteral("俩,良,凉,梁,粮,粱,两,亮,谅,辆,晾,量, , , ");


	ChineseLanMap[QStringLiteral("liao")] = QStringLiteral("潦,辽,疗,聊,僚,寥,廖,撩,燎,镣,料,撂, , , ");


	ChineseLanMap[QStringLiteral("lie")] = QStringLiteral("列,劣,烈,猎,裂, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lin")] = QStringLiteral("邻,林,临,淋,琳,霖,磷,鳞,凛,吝,赁,拎, , , ");


	ChineseLanMap[QStringLiteral("ling")] = QStringLiteral("伶,灵,岭,玲,凌,铃,陵,羚,菱,零,龄,领,令,另, ");


	ChineseLanMap[QStringLiteral("liu")] = QStringLiteral("溜,刘,流,留,琉,硫,馏,榴,瘤,柳,六, , , , ");


	ChineseLanMap[QStringLiteral("long")] = QStringLiteral("龙,咙,笼,聋,隆,窿,陇,垄,拢, , , , , , ");


	ChineseLanMap[QStringLiteral("lou")] = QStringLiteral("娄,楼,搂,篓,陋,漏, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lu")] = QStringLiteral("露,卢,庐,芦,炉,颅,卤,虏,掳,鲁,陆,录,赂,鹿,禄,碌,路,戮,潞,麓, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("luan")] = QStringLiteral("孪,峦,挛,滦,卵,乱, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lue")] = QStringLiteral("掠,略 , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lun")] = QStringLiteral("抡,仑,伦,沦,纶,轮,论, , , , , , , , ");


	ChineseLanMap[QStringLiteral("luo")] = QStringLiteral("罗,萝,逻,锣,箩,骡,螺,裸,洛,络,骆,落, , , ");


	ChineseLanMap[QStringLiteral("lv")] = QStringLiteral("滤,驴,吕,侣,旅,铝,屡,缕,履,律,虑,率,绿,氯, ");


	ChineseLanMap[QStringLiteral("ma")] = QStringLiteral("妈,麻,马,玛,码,蚂,骂,吗,嘛, , , , , , ");


	ChineseLanMap[QStringLiteral("mai")] = QStringLiteral("埋,买,迈,麦,卖,脉, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("man")] = QStringLiteral("蛮,馒,瞒,满,曼,谩,慢,漫,蔓, , , , , , ");


	ChineseLanMap[QStringLiteral("mang")] = QStringLiteral("忙,芒,盲,茫,莽,氓, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mao")] = QStringLiteral("猫,毛,矛,茅,锚,卯,铆,茂,冒,贸,帽,貌, , , ");


	ChineseLanMap[QStringLiteral("me")] = QStringLiteral("么, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mei")] = QStringLiteral("没,枚,玫,眉,梅,媒,煤,酶,霉,每,美,镁,妹,昧,媚,寐, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("men")] = QStringLiteral("门,闷,们, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("meng")] = QStringLiteral("萌,盟,檬,猛,蒙,锰,孟,梦, , , , , , , ");


	ChineseLanMap[QStringLiteral("mi")] = QStringLiteral("弥,迷,谜,醚,糜,靡,米,眯,泌,觅,秘,密,幂,蜜, ");


	ChineseLanMap[QStringLiteral("mian")] = QStringLiteral("眠,绵,棉,免,勉,娩,冕,缅,面, , , , , , ");


	ChineseLanMap[QStringLiteral("miao")] = QStringLiteral("苗,瞄,秒,渺,藐,妙,庙, , , , , , , , ");


	ChineseLanMap[QStringLiteral("mie")] = QStringLiteral("灭,蔑, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("min")] = QStringLiteral("民,皿,抿,闽,悯,敏, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ming")] = QStringLiteral("名,明,鸣,铭,螟,命, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("miu")] = QStringLiteral("谬, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mo")] = QStringLiteral("貉,摸,摹,模,膜,摩,磨,蘑,魔,抹,末,沫,陌,莫,寞,漠,墨,默, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mou")] = QStringLiteral("牟,谋,某, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mu")] = QStringLiteral("母,亩,牡,姆,拇,木,目,牧,募,墓,幕,睦,慕,暮,穆");


	ChineseLanMap[QStringLiteral("na")] = QStringLiteral("拿,哪,那,纳,娜,钠,呐, , , , , , , , ");


	ChineseLanMap[QStringLiteral("nai")] = QStringLiteral("乃,奶,氖,奈,耐, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nan")] = QStringLiteral("男,难,南, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nang")] = QStringLiteral("囊, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ne")] = QStringLiteral("呢, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nao")] = QStringLiteral("挠,恼,脑,闹,淖, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nei")] = QStringLiteral("内,馁, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nen")] = QStringLiteral("嫩, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("neng")] = QStringLiteral("能, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ni")] = QStringLiteral("妮,尼,泥,倪,霓,你,拟,逆,匿,溺,腻, , , , ");


	ChineseLanMap[QStringLiteral("nian")] = QStringLiteral("拈,年,捻,撵,碾,念,蔫, , , , , , , , ");


	ChineseLanMap[QStringLiteral("niang")] = QStringLiteral("娘,酿, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("niao")] = QStringLiteral("鸟,尿, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nie")] = QStringLiteral("捏,涅,聂,啮,镊,镍,孽, , , , , , , , ");


	ChineseLanMap[QStringLiteral("nin")] = QStringLiteral("您, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nuan")] = QStringLiteral("暖, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ning")] = QStringLiteral("宁,拧,狞,柠,凝,泞, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("niu")] = QStringLiteral("牛,扭,纽,钮, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nong")] = QStringLiteral("农,浓,脓,弄, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nu")] = QStringLiteral("奴,努,怒, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nue")] = QStringLiteral("疟,虐, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nuo")] = QStringLiteral("挪,诺,懦,糯, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nv")] = QStringLiteral("女, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("o")] = QStringLiteral("哦, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ou")] = QStringLiteral("欧,殴,鸥,呕,偶,藕,沤, , , , , , , , ");


	ChineseLanMap[QStringLiteral("pa")] = QStringLiteral("趴,啪,爬,耙,琶,帕,怕, , , , , , , , ");


	ChineseLanMap[QStringLiteral("pai")] = QStringLiteral("拍,徘,排,牌,派,湃, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pan")] = QStringLiteral("潘,攀,盘,磐,判,叛,盼,畔, , , , , , , ");


	ChineseLanMap[QStringLiteral("pang")] = QStringLiteral("乓,庞,旁,耪,胖, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pao")] = QStringLiteral("抛,刨,咆,炮,袍,跑,泡, , , , , , , , ");


	ChineseLanMap[QStringLiteral("pei")] = QStringLiteral("呸,陪,培,赔,裴,沛,佩,配, , , , , , , ");


	ChineseLanMap[QStringLiteral("pen")] = QStringLiteral("喷,盆, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("peng")] = QStringLiteral("抨,砰,烹,朋,彭,棚,硼,蓬,鹏,澎,篷,膨,捧,碰, ");


	ChineseLanMap[QStringLiteral("pi")] = QStringLiteral("辟,批,坯,披,砒,劈,霹,皮,毗,疲,啤,琵,脾,匹,痞,屁,僻,譬, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pian")] = QStringLiteral("片,偏,篇,骗, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("piao")] = QStringLiteral("漂,飘,瓢,票, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pie")] = QStringLiteral("撇,瞥, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pin")] = QStringLiteral("拼,贫,频,品,聘, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ping")] = QStringLiteral("乒,平,评,凭,坪,苹,屏,瓶,萍, , , , , , ");


	ChineseLanMap[QStringLiteral("po")] = QStringLiteral("坡,泼,颇,婆,迫,破,粕,魄, , , , , , , ");


	ChineseLanMap[QStringLiteral("pou")] = QStringLiteral("剖, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pu")] = QStringLiteral("脯,仆,扑,铺,莆,菩,葡,蒲,朴,圃,埔,浦,普,谱,曝");


	ChineseLanMap[QStringLiteral("qi")] = QStringLiteral("七,沏,妻,柒,凄,栖,戚,期,欺,漆,祁,齐,其,奇,歧,祈,脐,崎,畦,骑,棋,旗,乞,企,岂,启,起,气,讫,迄,弃,汽,泣,契,砌,器, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qia")] = QStringLiteral("掐,恰,洽, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qian")] = QStringLiteral("千,仟,扦,迁,钎,牵,铅,谦,签,前,钱,钳,乾,潜,黔,浅,遣,谴,欠,堑,嵌,歉, , , , , , , , ");


	ChineseLanMap[QStringLiteral("qiang")] = QStringLiteral("呛,羌,枪,腔,强,墙,蔷,抢, , , , , , , ");


	ChineseLanMap[QStringLiteral("qiao")] = QStringLiteral("悄,敲,锹,橇,乔,侨,桥,瞧,巧,俏,峭,窍,翘,撬,鞘");


	ChineseLanMap[QStringLiteral("qie")] = QStringLiteral("切,茄,且,怯,窃, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qin")] = QStringLiteral("亲,侵,钦,芹,秦,琴,禽,勤,擒,寝,沁, , , , ");


	ChineseLanMap[QStringLiteral("qing")] = QStringLiteral("青,氢,轻,倾,卿,清,情,晴,氰,擎,顷,请,庆, , ");


	ChineseLanMap[QStringLiteral("qiong")] = QStringLiteral("穷,琼, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qiu")] = QStringLiteral("丘,邱,秋,囚,求,泅,酋,球, , , , , , , ");


	ChineseLanMap[QStringLiteral("qu")] = QStringLiteral("区,曲,驱,屈,蛆,躯,趋,渠,取,娶,龋,去,趣, , ");


	ChineseLanMap[QStringLiteral("quan")] = QStringLiteral("圈,全,权,泉,拳,痊,醛,颧,犬,劝,券, , , , ");


	ChineseLanMap[QStringLiteral("que")] = QStringLiteral("炔,缺,瘸,却,雀,确,鹊,榷, , , , , , , ");


	ChineseLanMap[QStringLiteral("qun")] = QStringLiteral("裙,群, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ran")] = QStringLiteral("然,燃,冉,染, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rang")] = QStringLiteral("瓤,嚷,壤,攘,让, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rao")] = QStringLiteral("饶,扰,绕, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("re")] = QStringLiteral("惹,热, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ren")] = QStringLiteral("人,仁,壬,忍,刃,认,任,纫,妊,韧, , , , , ");


	ChineseLanMap[QStringLiteral("reng")] = QStringLiteral("扔,仍, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ri")] = QStringLiteral("日, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rong")] = QStringLiteral("戎,绒,茸,荣,容,溶,蓉,熔,融,冗, , , , , ");


	ChineseLanMap[QStringLiteral("rou")] = QStringLiteral("柔,揉,肉, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ru")] = QStringLiteral("如,茹,儒,孺,蠕,汝,乳,辱,入,褥, , , , , ");


	ChineseLanMap[QStringLiteral("ruan")] = QStringLiteral("阮,软, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rui")] = QStringLiteral("蕊,锐,瑞, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("run")] = QStringLiteral("闰,润, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ruo")] = QStringLiteral("若,弱, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sa")] = QStringLiteral("撒,洒,萨, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sai")] = QStringLiteral("塞,腮,鳃,赛, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("san")] = QStringLiteral("三,叁,伞,散, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sang")] = QStringLiteral("桑,嗓,丧, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sao")] = QStringLiteral("搔,骚,扫,嫂, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("se")] = QStringLiteral("色,涩,瑟, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sen")] = QStringLiteral("森, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("seng")] = QStringLiteral("僧, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sha")] = QStringLiteral("杀,沙,纱,砂,莎,傻,啥,煞,厦, , , , , , ");


	ChineseLanMap[QStringLiteral("shai")] = QStringLiteral("筛,晒, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shan")] = QStringLiteral("山,删,杉,衫,珊,煽,闪,陕,汕,苫,扇,善,缮,擅,膳,赡,栅, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shang")] = QStringLiteral("伤,商,墒,裳,晌,赏,上,尚, , , , , , , ");


	ChineseLanMap[QStringLiteral("shao")] = QStringLiteral("捎,梢,烧,稍,勺,芍,韶,少,邵,绍,哨, , , , ");


	ChineseLanMap[QStringLiteral("she")] = QStringLiteral("奢,赊,舌,蛇,舍,设,社,射,涉,赦,慑,摄, , , ");


	ChineseLanMap[QStringLiteral("shen")] = QStringLiteral("申,伸,身,呻,绅,娠,砷,深,神,沈,审,婶,肾,甚,渗,慎,什, , , , , , , , , , , , , ");



	ChineseLanMap[QStringLiteral("sheng")] = QStringLiteral("升,生,声,牲,胜,甥,绳,省,圣,盛,剩, , , , ");


	ChineseLanMap[QStringLiteral("shi")] = QStringLiteral("匙,尸,失,师,虱,诗,施,狮,湿,十,石,时,识,实,拾,蚀,食,史,矢,使,始,驶,屎,士,氏,世,仕,市,示,式,事,侍,势,视,试,饰,室,恃,拭,是,柿,适,逝,释,嗜,誓,噬,似, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shou")] = QStringLiteral("收,手,守,首,寿,受,兽,售,授,瘦, , , , , ");


	ChineseLanMap[QStringLiteral("shu")] = QStringLiteral("书,抒,叔,枢,殊,梳,淑,疏,舒,输,蔬,孰,赎,熟,暑,黍,署,鼠,蜀,薯,曙,术,戍,束,述,树,竖,恕,庶,数,墅,漱,属, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shua")] = QStringLiteral("刷,耍, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuai")] = QStringLiteral("衰,摔,甩,帅, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuan")] = QStringLiteral("拴,栓, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuang")] = QStringLiteral("双,霜,爽, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shui")] = QStringLiteral("谁,水,税,睡, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shun")] = QStringLiteral("吮,顺,舜,瞬, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuo")] = QStringLiteral("说,烁,朔,硕, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("si")] = QStringLiteral("丝,司,私,思,斯,嘶,撕,死,巳,四,寺,伺,饲,嗣,肆");


	ChineseLanMap[QStringLiteral("song")] = QStringLiteral("松,怂,耸,讼,宋,诵,送,颂, , , , , , , ");


	ChineseLanMap[QStringLiteral("sou")] = QStringLiteral("嗽,搜,艘,擞, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("su")] = QStringLiteral("苏,酥,俗,诉,肃,素,速,粟,塑,溯,僳, , , , ");


	ChineseLanMap[QStringLiteral("suan")] = QStringLiteral("酸,蒜,算, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sui")] = QStringLiteral("虽,绥,隋,随,髓,岁,祟,遂,碎,隧,穗, , , , ");


	ChineseLanMap[QStringLiteral("sun")] = QStringLiteral("孙,损,笋, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("suo")] = QStringLiteral("唆,梭,蓑,缩,所,索,琐,锁, , , , , , , ");


	ChineseLanMap[QStringLiteral("ta")] = QStringLiteral("她,他,它,塌,塔,獭,挞,踏,蹋, , , , , , ");


	ChineseLanMap[QStringLiteral("tai")] = QStringLiteral("胎,台,抬,苔,太,汰,态,泰,酞, , , , , , ");


	ChineseLanMap[QStringLiteral("tan")] = QStringLiteral("坍,贪,摊,滩,瘫,坛,谈,痰,谭,潭,檀,坦,袒,毯,叹,炭,探,碳, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tang")] = QStringLiteral("汤,唐,堂,棠,塘,搪,膛,糖,倘,淌,躺,烫,趟, , ");


	ChineseLanMap[QStringLiteral("tao")] = QStringLiteral("涛,绦,掏,滔,逃,桃,陶,淘,萄,讨,套, , , , ");


	ChineseLanMap[QStringLiteral("te")] = QStringLiteral("特, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("teng")] = QStringLiteral("疼,腾,誊,藤, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ti")] = QStringLiteral("剔,梯,锑,踢,啼,提,题,蹄,体,屉,剃,涕,惕,替,嚏");


	ChineseLanMap[QStringLiteral("tian")] = QStringLiteral("天,添,田,恬,甜,填,腆,舔, , , , , , , ");


	ChineseLanMap[QStringLiteral("tiao")] = QStringLiteral("调,挑,条,迢,眺,跳, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tie")] = QStringLiteral("贴,铁,帖, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ting")] = QStringLiteral("厅,汀,听,烃,廷,亭,庭,停,挺,艇, , , , , ");


	ChineseLanMap[QStringLiteral("tong")] = QStringLiteral("通,同,彤,桐,铜,童,酮,瞳,统,捅,桶,筒,痛, , ");


	ChineseLanMap[QStringLiteral("tou")] = QStringLiteral("偷,头,投,透, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tu")] = QStringLiteral("凸,秃,突,图,徒,涂,途,屠,土,吐,兔, , , , ");


	ChineseLanMap[QStringLiteral("tuan")] = QStringLiteral("湍,团, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tui")] = QStringLiteral("推,颓,腿,退,蜕,褪, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tun")] = QStringLiteral("囤,吞,屯,臀, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tuo")] = QStringLiteral("托,拖,脱,驮,陀,驼,鸵,妥,椭,拓,唾, , , , ");


	ChineseLanMap[QStringLiteral("wa")] = QStringLiteral("哇,娃,挖,洼,蛙,瓦,袜, , , , , , , , ");


	ChineseLanMap[QStringLiteral("wai")] = QStringLiteral("歪,外, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("wan")] = QStringLiteral("弯,湾,豌,丸,完,玩,顽,烷,宛,挽,晚,婉,惋,皖,碗,万,腕, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("wang")] = QStringLiteral("汪,亡,王,网,往,枉,妄,忘,旺,望, , , , , ");


	ChineseLanMap[QStringLiteral("wei")] = QStringLiteral("危,威,微,巍,为,韦,围,违,桅,唯,惟,维,潍,伟,伪,尾,纬,苇,委,萎,卫,未,位,味,畏,胃,尉,谓,喂,渭,蔚,慰,魏, , , , , , , , , , , , ");



	ChineseLanMap[QStringLiteral("wen")] = QStringLiteral("温,瘟,文,纹,闻,蚊,吻,紊,稳,问, , , , , ");


	ChineseLanMap[QStringLiteral("weng")] = QStringLiteral("翁,嗡,瓮, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("wo")] = QStringLiteral("挝,涡,窝,蜗,我,沃,卧,握,斡, , , , , , ");


	ChineseLanMap[QStringLiteral("wu")] = QStringLiteral("乌,污,呜,巫,屋,诬,钨,无,毋,吴,吾,芜,梧,五,午,伍,坞,武,侮,捂,舞,勿,务,戊,物,误,悟,晤,雾, ");


	ChineseLanMap[QStringLiteral("xi")] = QStringLiteral("夕,汐,西,吸,希,昔,析,矽,息,牺,悉,惜,烯,硒,晰,犀,稀,溪,锡,熄,熙,嘻,膝,习,席,袭,媳,檄,洗,喜,戏,系,细,隙, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xia")] = QStringLiteral("虾,瞎,匣,侠,峡,狭,暇,辖,霞,下,吓,夏, , , ");


	ChineseLanMap[QStringLiteral("xian")] = QStringLiteral("铣,仙,先,纤,掀,锨,鲜,闲,弦,贤,咸,涎,舷,衔,嫌,显,险,县,现,线,限,宪,陷,馅,羡,献,腺, , , ");


	ChineseLanMap[QStringLiteral("xiang")] = QStringLiteral("乡,相,香,厢,湘,箱,襄,镶,详,祥,翔,享,响,想,向,巷,项,象,像,橡, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xiao")] = QStringLiteral("宵,消,萧,硝,销,霄,嚣,淆,小,晓,孝,肖,哮,效,校,笑,啸, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xie")] = QStringLiteral("些,楔,歇,蝎,协,邪,胁,斜,谐,携,鞋,写,泄,泻,卸,屑,械,谢,懈,蟹, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xin")] = QStringLiteral("心,忻,芯,辛,欣,锌,新,薪,信,衅,鑫, , , , ");


	ChineseLanMap[QStringLiteral("xing")] = QStringLiteral("兴,星,惺,猩,腥,刑,邢,形,型,醒,杏,姓,幸,性, ");


	ChineseLanMap[QStringLiteral("xiong")] = QStringLiteral("凶,兄,匈,汹,胸,雄,熊, , , , , , , , ");


	ChineseLanMap[QStringLiteral("xiu")] = QStringLiteral("宿,休,修,羞,朽,秀,绣,袖,锈,嗅, , , , , ");


	ChineseLanMap[QStringLiteral("xu")] = QStringLiteral("戌,须,虚,嘘,需,墟,徐,许,旭,序,叙,恤,绪,续,酗,婿,絮,蓄,吁, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xuan")] = QStringLiteral("轩,宣,喧,玄,悬,旋,选,癣,绚,眩, , , , , ");


	ChineseLanMap[QStringLiteral("xue")] = QStringLiteral("削,靴,薛,穴,学,雪,血, , , , , , , , ");


	ChineseLanMap[QStringLiteral("xun")] = QStringLiteral("勋,熏,寻,巡,旬,驯,询,循,训,讯,汛,迅,逊,殉, ");


	ChineseLanMap[QStringLiteral("ya")] = QStringLiteral("丫,压,呀,押,鸦,鸭,牙,芽,蚜,崖,涯,衙,哑,雅,亚,讶, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yan")] = QStringLiteral("咽,烟,淹,焉,阉,延,严,言,岩,沿,炎,研,盐,阎,蜒,颜,奄,衍,掩,眼,演,厌,彦,砚,唁,宴,艳,验,谚,堰,焰,雁,燕, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yang")] = QStringLiteral("央,殃,秧,鸯,扬,羊,阳,杨,佯,疡,洋,仰,养,氧,痒,样,漾, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yao")] = QStringLiteral("侥,妖,腰,邀,尧,姚,窑,谣,摇,遥,瑶,咬,舀,药,要,耀,钥, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ye")] = QStringLiteral("椰,噎,爷,耶,也,冶,野,业,叶,曳,页,夜,掖,液,腋, , , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yin")] = QStringLiteral("因,阴,姻,茵,荫,音,殷,吟,寅,淫,银,尹,引,饮,隐,印, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ying")] = QStringLiteral("应,英,婴,缨,樱,鹰,迎,盈,荧,莹,萤,营,蝇,赢,颖,影,映,硬, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yo")] = QStringLiteral("哟, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yong")] = QStringLiteral("佣,拥,痈,庸,雍,臃,永,咏,泳,勇,涌,恿,蛹,踊,用");


	ChineseLanMap[QStringLiteral("you")] = QStringLiteral("优,忧,幽,悠,尤,由,犹,邮,油,铀,游,友,有,酉,又,右,幼,佑,诱,釉, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yu")] = QStringLiteral("迂,淤,渝,于,予,余,盂,鱼,俞,娱,渔,隅,愉,逾,愚,榆,虞,舆,与,宇,屿,羽,雨,禹,语,玉,驭,芋,育,郁,狱,峪,浴,预,域,欲,喻,寓,御,裕,遇,愈,誉,豫, ");


	ChineseLanMap[QStringLiteral("yuan")] = QStringLiteral("冤,鸳,渊,元,员,园,垣,原,圆,袁,援,缘,源,猿,辕,远,苑,怨,院,愿, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yue")] = QStringLiteral("曰,约,月,岳,悦,阅,跃,粤,越, , , , , , ");


	ChineseLanMap[QStringLiteral("yun")] = QStringLiteral("云,匀,郧,耘,允,陨,孕,运,晕,酝,韵,蕴, , , ");


	ChineseLanMap[QStringLiteral("za")] = QStringLiteral("匝,杂,砸,咋, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zai")] = QStringLiteral("灾,哉,栽,宰,载,再,在,仔, , , , , , , ");


	ChineseLanMap[QStringLiteral("zan")] = QStringLiteral("咱,攒,暂,赞, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zang")] = QStringLiteral("赃,脏,葬, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zao")] = QStringLiteral("遭,糟,凿,早,枣,蚤,澡,藻,灶,皂,造,噪,燥,躁, ");


	ChineseLanMap[QStringLiteral("ze")] = QStringLiteral("则,择,泽,责, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zei")] = QStringLiteral("贼, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zen")] = QStringLiteral("怎, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zeng")] = QStringLiteral("增,憎,赠, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zha")] = QStringLiteral("喳,渣,扎,札,轧,闸,铡,眨,乍,诈,炸,榨,柞, , ");


	ChineseLanMap[QStringLiteral("zhai")] = QStringLiteral("斋,摘,宅,翟,窄,债,寨, , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhan")] = QStringLiteral("沾,毡,粘,詹,瞻,斩,展,盏,崭,辗,占,战,栈,站,绽,湛,蘸, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhang")] = QStringLiteral("长,张,章,彰,漳,樟,涨,掌,丈,仗,帐,杖,胀,账,障,瘴, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhao")] = QStringLiteral("招,昭,找,沼,召,兆,赵,照,罩,肇,爪, , , , ");


	ChineseLanMap[QStringLiteral("zhe")] = QStringLiteral("遮,折,哲,蛰,辙,者,锗,这,浙,蔗,着, , , , ");


	ChineseLanMap[QStringLiteral("zhen")] = QStringLiteral("贞,针,侦,珍,真,砧,斟,甄,臻,诊,枕,疹,阵,振,镇,震,帧, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zheng")] = QStringLiteral("争,征,怔,挣,狰,睁,蒸,拯,整,正,证,郑,政,症, ");


	ChineseLanMap[QStringLiteral("zhi")] = QStringLiteral("之,支,汁,芝,吱,枝,知,织,肢,脂,蜘,执,侄,直,值,职,植,殖,止,只,旨,址,纸,指,趾,至,志,制,帜,治,炙,质,峙,挚,秩,致,掷,痔,窒,智,滞,稚,置, , ");


	ChineseLanMap[QStringLiteral("zhong")] = QStringLiteral("中,忠,终,盅,钟,衷,肿,种,仲,众,重, , , , ");


	ChineseLanMap[QStringLiteral("zhou")] = QStringLiteral("州,舟,诌,周,洲,粥,轴,肘,帚,咒,宙,昼,皱,骤, ");


	ChineseLanMap[QStringLiteral("zhu")] = QStringLiteral("朱,诛,株,珠,诸,猪,蛛,竹,烛,逐,主,拄,煮,嘱,瞩,住,助,注,贮,驻,柱,祝,著,蛀,筑,铸, , , , ");


	ChineseLanMap[QStringLiteral("zhua")] = QStringLiteral("抓, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuai")] = QStringLiteral("拽, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuan")] = QStringLiteral("专,砖,转,撰,篆, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuang")] = QStringLiteral("妆,庄,桩,装,壮,状,幢,撞, , , , , , ,");


	ChineseLanMap[QStringLiteral("zhui")] = QStringLiteral("追,椎,锥,坠,缀,赘, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhun")] = QStringLiteral("谆,准, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuo")] = QStringLiteral("卓,拙,捉,桌,灼,茁,浊,酌,啄,琢, , , , , ");


	ChineseLanMap[QStringLiteral("zi")] = QStringLiteral("孜,兹,咨,姿,资,淄,滋,籽,子,紫,滓,字,自,渍, ");


	ChineseLanMap[QStringLiteral("zong")] = QStringLiteral("宗,综,棕,踪,鬃,总,纵, , , , , , , , ");


	ChineseLanMap[QStringLiteral("zou")] = QStringLiteral("邹,走,奏,揍, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zu")] = QStringLiteral("租,足,卒,族,诅,阻,组,祖, , , , , , , ");


	ChineseLanMap[QStringLiteral("zuan")] = QStringLiteral("赚,纂,钻, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zui")] = QStringLiteral("嘴,最,罪,醉, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zun")] = QStringLiteral("尊,遵, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zuo")] = QStringLiteral("昨,左,佐,作,坐,座,做, , , , , , , , ");
}//中文字库

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
	if ( m_Upper == true )//如果当前为小写
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
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ů"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ú"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ˇ"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("É"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("Í"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("Á"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("Ý"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("Ž"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("Ř"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("Č"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("Š"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("Ě"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("°"));
		//		break;
		//	}
		//case 9:  //Dutch
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("`"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("±"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T(">"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("|"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("~"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
		//		break;
		//	}
		//case 10: //German
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ú"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("§"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("^"));
		//		break;
		//	}
		//case 11:  //Finnish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("´"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Å"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("`"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("¤"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("½"));
		//		break;
		//	}
		//case 12:  //Hindi
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("य़"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("।"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ष"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("श"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ळ"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ऴ"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ऩ"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ण"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ँ"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ऎ"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ठ"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("छ"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("थ"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ख"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ऱ"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("फ"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("उ"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("इ"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("अ"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ए"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ओ"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ऑ"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ञ"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ढ"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("झ"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ध"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("घ"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ङ"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("भ"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ऊ"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ई"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("आ"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ऐ"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("औ"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ऋ"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ः"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("श्र"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("क्ष"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("त्र"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ज्ञ"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("र्"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("्र"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ॅ"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("ऍ"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ऒ"));
		//		break;
		//	}
		//case 13:  //Hungarian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Á"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("É"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("Ű"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("Ú"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ő"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("Ó"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("Ü"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("Ö"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("+"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
		//		break;
		//	}
		//case 14:  //Italian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("°"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ç"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("§"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("é"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("£"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("|"));
		//		break;
		//	}
		//case 15:  //Portuguese
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(">"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("<"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ç"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("}"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("{"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("`"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("——"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("）"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("（"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("@"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("\""));
		//		break;
		//	}
		//case 16:  //Russian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("."));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("Ю"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("Б"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("Ь"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("Т"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("И"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("М"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("С"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("Ч"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Я"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Э"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ж"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("Д"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("Л"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("О"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("Р"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("П"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("А"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("В"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("Ы"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("Ф"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("Ъ"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Х"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("З"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("Щ"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("Ш"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("Г"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Н"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("Е"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("К"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("У"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("Ц"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Й"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("）"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("№"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("Ё"));
		//		break;
		//	}
		//case 17:  //Spanish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("¨"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ñ"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("Ç"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("¿"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("·"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ª"));
		//		break;
		//	}
		//case 18:  //Swedish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Å"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("`"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("¤"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("½"));
		//		break;
		//	}
		//case 19:  //Thai
		//	{

		//	}
		//case 20:  //Turkish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T(","));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("Ç"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("Ö"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ş"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("Ü"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("İ"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("Ğ"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
//		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("*"));
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
	else //当前为大写
	{
		btnLanguageSel(m_LanType);
		m_Upper = true;
		m_symbol = true;
	}

}

void keyboard::symbol_KBBut_clicked()
{
	if ( m_symbol == true )//如果当前为字母
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
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
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
				ui->D_KBBut->setText(QStringLiteral("："));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral("；"));
				ui->G_KBBut->setText(QStringLiteral("“"));
				ui->H_KBBut->setText(QStringLiteral("”"));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("！"));
				ui->R_KBBut->setText(QStringLiteral("￥"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("？"));
				break;
			}
		case 2://Kore
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral("："));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral("；"));
				ui->G_KBBut->setText(QStringLiteral("“"));
				ui->H_KBBut->setText(QStringLiteral("”"));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("！"));
				ui->R_KBBut->setText(QStringLiteral("￥"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("？"));
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
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
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
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
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
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
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
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
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
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
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
		case 8://Hindi
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
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
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
	else //当前为符号
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

void keyboard::languageAdd_KBBut_clicked()
{
	if (m_LanType == 5)
	{
		m_LanType = 23;
		LanArabic2();
	}
	else if (m_LanType == 23)
	{
		m_LanType = 24;
		LanArabic3();
	} 
	else if (m_LanType == 24)
	{
		m_LanType = 25;
		LanArabic4();
	} 
	else if (m_LanType  == 25)
	{
		m_LanType =5;
		LanArabic1();
	} 
}

void keyboard::languageRedu_KBBut_clicked()
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
		case 0: //当前为EnglishSymbol
		{
			SymbolToEnglish();
			btnhide();

			//	pWnd->btnShow();
			//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 1: //当前为ChineseSymbol
		{
			SymbolToChinese();
			//	pWnd->btnShow();
			//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 2: //当前为KoreSymbol
		{
			SymbolToKore();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 3: //当前为KoreSymbol
		{
			SymbolToCzech();
			btnhide();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 4: //当前为KoreSymbol
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
		case 8:
		{
			SymbolToHindi();
			btnhide();
			break;
		}
		
	}

}

void keyboard::LanArabic1()
{
	ui->A_KBBut->setText(QStringLiteral("ﮓ"));
	ui->B_KBBut->setText(QStringLiteral("ﺈ"));
	ui->C_KBBut->setText(QStringLiteral("ﺆ"));
	ui->D_KBBut->setText(QStringLiteral("ﮕ"));
	ui->E_KBBut->setText(QStringLiteral("ﭺ"));
	ui->F_KBBut->setText(QStringLiteral("ﯼ"));
	ui->G_KBBut->setText(QStringLiteral("ﯽ"));
	ui->H_KBBut->setText(QStringLiteral("ﯾ"));
	ui->I_KBBut->setText(QStringLiteral("ﮋ"));
	ui->J_KBBut->setText(QStringLiteral("ﯿ"));
	ui->K_KBBut->setText(QStringLiteral("ﺀ"));
	ui->L_KBBut->setText(QStringLiteral("ﺁ"));
	ui->M_KBBut->setText(QStringLiteral("ﺊ"));
	ui->N_KBBut->setText(QStringLiteral("ﺉ"));
	ui->O_KBBut->setText(QStringLiteral("ﮎ"));
	ui->P_KBBut->setText(QStringLiteral("ﮏ"));
	ui->Q_KBBut->setText(QStringLiteral("ﭘ"));
	ui->R_KBBut->setText(QStringLiteral("ﭻ"));
	ui->S_KBBut->setText(QStringLiteral("ﮔ"));
	ui->T_KBBut->setText(QStringLiteral("ﭼ"));
	ui->U_KBBut->setText(QStringLiteral("ﮊ"));
	ui->V_KBBut->setText(QStringLiteral("ﺇ"));
	ui->W_KBBut->setText(QStringLiteral("ﭙ"));
	ui->X_KBBut->setText(QStringLiteral("ﺅ"));
	ui->Y_KBBut->setText(QStringLiteral("ﺋ"));
	ui->Z_KBBut->setText(QStringLiteral("ﺄ"));
	ui->comma_KBBut->setText(QStringLiteral("ﺋ"));
	ui->period_KBBut->setText(QStringLiteral("ﺌ"));
	ui->one_KBBut->setText(QStringLiteral("۱"));
	ui->two_KBBut->setText(QStringLiteral("۲"));
	ui->three_KBBut->setText(QStringLiteral("۳"));
	ui->four_KBBut->setText(QStringLiteral("۴"));
	ui->five_KBBut->setText(QStringLiteral("۵"));
	ui->six_KBBut->setText(QStringLiteral("۶"));
	ui->seven_KBBut->setText(QStringLiteral("۷"));
	ui->eight_KBBut->setText(QStringLiteral("۸"));
	ui->nine_KBBut->setText(QStringLiteral("۹"));
	ui->zero_KBBut->setText(QStringLiteral("۰"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("ﺍ"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("ﺌ"));//已用
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ﺋ"));//已用
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ﺊ"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ﺉ"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ﺈ"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ﺇ"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ﺆ"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ﺅ"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ﺄ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ﺃ"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ﺂ"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("ﺁ"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ﺀ"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ﯿ"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("ﯾ"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ﯽ"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ﯼ"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("ﮕ"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ﮔ"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ﮓ"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ﮒ"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ﮑ"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ﮐ"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ﮏ"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ﮎ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ﮋ"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ﮊ"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ﭽ"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ﭼ"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ﭻ"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ﭺ"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ﭙ"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ﭘ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ﭗ"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ﭖ"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("۰"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("۹"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("۸"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("۷"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("۶"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("۵"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("۴"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("۳"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("۲"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("۱"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("؟"));*/
}

void keyboard::LanArabic2()
{
	ui->A_KBBut->setText(QStringLiteral("ﺞ"));
	ui->B_KBBut->setText(QStringLiteral("ﺭ"));
	ui->C_KBBut->setText(QStringLiteral("ﺫ"));
	ui->D_KBBut->setText(QStringLiteral("ﺠ"));
	ui->E_KBBut->setText(QStringLiteral("ﺓ"));
	ui->F_KBBut->setText(QStringLiteral("ﺡ"));
	ui->G_KBBut->setText(QStringLiteral("ﺢ"));
	ui->H_KBBut->setText(QStringLiteral("ﺣ"));
	ui->I_KBBut->setText(QStringLiteral("ﺘ"));
	ui->J_KBBut->setText(QStringLiteral("ﺤ"));
	ui->K_KBBut->setText(QStringLiteral("ﺥ"));
	ui->L_KBBut->setText(QStringLiteral("ﺦ"));
	ui->M_KBBut->setText(QStringLiteral("ﺯ"));
	ui->N_KBBut->setText(QStringLiteral("ﺮ"));
	ui->O_KBBut->setText(QStringLiteral("ﺙ"));
	ui->P_KBBut->setText(QStringLiteral("ﺚ"));
	ui->Q_KBBut->setText(QStringLiteral("ﺑ"));
	ui->R_KBBut->setText(QStringLiteral("ﺔ"));
	ui->S_KBBut->setText(QStringLiteral("ﺟ"));
	ui->T_KBBut->setText(QStringLiteral("ﺕ"));
	ui->U_KBBut->setText(QStringLiteral("ﺗ"));
	ui->V_KBBut->setText(QStringLiteral("ﺬ"));
	ui->W_KBBut->setText(QStringLiteral("ﺒ"));
	ui->X_KBBut->setText(QStringLiteral("ﺪ"));
	ui->Y_KBBut->setText(QStringLiteral("ﺖ"));
	ui->Z_KBBut->setText(QStringLiteral("ﺩ"));
	ui->comma_KBBut->setText(QStringLiteral("ﺰ"));
	ui->period_KBBut->setText(QStringLiteral("ﺱ"));
	ui->one_KBBut->setText(QStringLiteral("۱"));
	ui->two_KBBut->setText(QStringLiteral("۲"));
	ui->three_KBBut->setText(QStringLiteral("۳"));
	ui->four_KBBut->setText(QStringLiteral("۴"));
	ui->five_KBBut->setText(QStringLiteral("۵"));
	ui->six_KBBut->setText(QStringLiteral("۶"));
	ui->seven_KBBut->setText(QStringLiteral("۷"));
	ui->eight_KBBut->setText(QStringLiteral("۸"));
	ui->nine_KBBut->setText(QStringLiteral("۹"));
	ui->zero_KBBut->setText(QStringLiteral("۰"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("ﺲ"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("ﺱ"));//已用
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ﺰ"));//已用
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ﺯ"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ﺮ"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ﺭ"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ﺬ"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ﺫ"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ﺪ"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ﺩ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ﺨ"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ﺧ"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("ﺦ"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ﺥ"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ﺤ"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("ﺣ"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ﺢ"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ﺡ"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("ﺠ"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ﺟ"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ﺞ"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ﺝ"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ﺜ"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ﺛ"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ﺚ"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ﺙ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ﺘ"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ﺗ"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ﺖ"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ﺕ"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ﺔ"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ﺓ"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ﺒ"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ﺑ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ﺐ"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ﺏ"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("۰"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("۹"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("۸"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("۷"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("۶"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("۵"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("۴"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("۳"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("۲"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("۱"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ﺎ"));*/
}

void keyboard::LanArabic3()
{
	ui->A_KBBut->setText(QStringLiteral("ﻍ"));
	ui->B_KBBut->setText(QStringLiteral("ﻜ"));
	ui->C_KBBut->setText(QStringLiteral("ﻚ"));
	ui->D_KBBut->setText(QStringLiteral("ﻏ"));
	ui->E_KBBut->setText(QStringLiteral("ﻂ"));
	ui->F_KBBut->setText(QStringLiteral("ﻐ"));
	ui->G_KBBut->setText(QStringLiteral("ﻑ"));
	ui->H_KBBut->setText(QStringLiteral("ﻒ"));
	ui->I_KBBut->setText(QStringLiteral("ﻇ"));
	ui->J_KBBut->setText(QStringLiteral("ﻓ"));
	ui->K_KBBut->setText(QStringLiteral("ﻔ"));
	ui->L_KBBut->setText(QStringLiteral("ﻕ"));
	ui->M_KBBut->setText(QStringLiteral("ﻞ"));
	ui->N_KBBut->setText(QStringLiteral("ﻝ"));
	ui->O_KBBut->setText(QStringLiteral("ﻈ"));
	ui->P_KBBut->setText(QStringLiteral("ﻉ"));
	ui->Q_KBBut->setText(QStringLiteral("ﻀ"));
	ui->R_KBBut->setText(QStringLiteral("ﻃ"));
	ui->S_KBBut->setText(QStringLiteral("ﻎ"));
	ui->T_KBBut->setText(QStringLiteral("ﺕ"));
	ui->U_KBBut->setText(QStringLiteral("ﺗ"));
	ui->V_KBBut->setText(QStringLiteral("ﻛ"));
	ui->W_KBBut->setText(QStringLiteral("ﻁ"));
	ui->X_KBBut->setText(QStringLiteral("ﻙ"));
	ui->Y_KBBut->setText(QStringLiteral("ﺖ"));
	ui->Z_KBBut->setText(QStringLiteral("ﻘ"));
	ui->comma_KBBut->setText(QStringLiteral("ﻟ"));
	ui->period_KBBut->setText(QStringLiteral("ﻟ"));
	ui->one_KBBut->setText(QStringLiteral("ﺴ"));
	ui->two_KBBut->setText(QStringLiteral("ﺵ"));
	ui->three_KBBut->setText(QStringLiteral("ﺶ"));
	ui->four_KBBut->setText(QStringLiteral("ﺷ"));
	ui->five_KBBut->setText(QStringLiteral("ﺸ"));
	ui->six_KBBut->setText(QStringLiteral("ﺹ"));
	ui->seven_KBBut->setText(QStringLiteral("ﺺ"));
	ui->eight_KBBut->setText(QStringLiteral("ﺻ"));
	ui->nine_KBBut->setText(QStringLiteral("ﺼ"));
	ui->zero_KBBut->setText(QStringLiteral("ﺽ"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("ﻡ"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("ﻟ"));//已用
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ﻟ"));//已用
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ﻞ"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ﻝ"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ﻜ"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ﻛ"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ﻚ"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ﻙ"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ﻘ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ﻗ"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ﻖ"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("ﻕ"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ﻔ"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ﻓ"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("ﻒ"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ﻑ"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ﻐ"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("ﻏ"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ﻎ"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ﻍ"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ﻌ"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ﻋ"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ﻊ"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ﻉ"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ﻈ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ﻇ"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ﻆ"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ﻅ"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ﻄ"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ﻃ"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ﻂ"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ﻁ"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ﻀ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ﺿ"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ﺾ"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("ﺽ"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("ﺼ"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("ﺻ"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("ﺺ"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("ﺹ"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ﺸ"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("ﺷ"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("ﺶ"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ﺵ"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("ﺴ"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ﺳ"));*/
}

void keyboard::LanArabic4()
{
	ui->A_KBBut->setText(QStringLiteral("ﻼ"));
	ui->B_KBBut->setText(QStringLiteral(""));
	ui->C_KBBut->setText(QStringLiteral(""));
	ui->D_KBBut->setText(QStringLiteral(""));
	ui->E_KBBut->setText(QStringLiteral("ﻱ"));
	ui->F_KBBut->setText(QStringLiteral(""));
	ui->G_KBBut->setText(QStringLiteral(""));
	ui->H_KBBut->setText(QStringLiteral(""));
	ui->I_KBBut->setText(QStringLiteral("ﻶ"));
	ui->J_KBBut->setText(QStringLiteral(""));
	ui->K_KBBut->setText(QStringLiteral(""));
	ui->L_KBBut->setText(QStringLiteral(""));
	ui->M_KBBut->setText(QStringLiteral(""));
	ui->N_KBBut->setText(QStringLiteral(""));
	ui->O_KBBut->setText(QStringLiteral("ﻷ"));
	ui->P_KBBut->setText(QStringLiteral("ﻸ"));
	ui->Q_KBBut->setText(QStringLiteral("ﻯ"));
	ui->R_KBBut->setText(QStringLiteral("ﻲ"));
	ui->S_KBBut->setText(QStringLiteral(""));
	ui->T_KBBut->setText(QStringLiteral("ﻳ"));
	ui->U_KBBut->setText(QStringLiteral("ﻵ"));
	ui->V_KBBut->setText(QStringLiteral(""));
	ui->W_KBBut->setText(QStringLiteral("ﻰ"));
	ui->X_KBBut->setText(QStringLiteral(""));
	ui->Y_KBBut->setText(QStringLiteral("ﻴ"));
	ui->Z_KBBut->setText(QStringLiteral(""));
	ui->comma_KBBut->setText(QStringLiteral(""));
	ui->period_KBBut->setText(QStringLiteral(""));
	ui->one_KBBut->setText(QStringLiteral("ﻣ"));
	ui->two_KBBut->setText(QStringLiteral("ﻤ"));
	ui->three_KBBut->setText(QStringLiteral("ﻥ"));
	ui->four_KBBut->setText(QStringLiteral("ﻦ"));
	ui->five_KBBut->setText(QStringLiteral("ﻧ"));
	ui->six_KBBut->setText(QStringLiteral("ﻨ"));
	ui->seven_KBBut->setText(QStringLiteral("ﻩ"));
	ui->eight_KBBut->setText(QStringLiteral("ﻪ"));
	ui->nine_KBBut->setText(QStringLiteral("ﻫ"));
	ui->zero_KBBut->setText(QStringLiteral("ﻬ"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T(""));

	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ﻼ"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ﻻ"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ﻺ"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ﻹ"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ﻸ"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ﻷ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ﻶ"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ﻵ"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ﻴ"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ﻳ"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ﻲ"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ﻱ"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ﻰ"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ﻯ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ﻮ"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ﻭ"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("ﻬ"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("ﻫ"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("ﻪ"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("ﻩ"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("ﻨ"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ﻧ"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("ﻦ"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("ﻥ"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ﻤ"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("ﻣ"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ﻢ"));*/
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

void keyboard::LanKoreanSmall()//韩语小写
{
	ui->A_KBBut->setText(QStringLiteral("ㅁ"));
	ui->B_KBBut->setText(QStringLiteral("ㅠ"));
	ui->C_KBBut->setText(QStringLiteral("ㅊ"));
	ui->D_KBBut->setText(QStringLiteral("ㅇ"));
	ui->E_KBBut->setText(QStringLiteral("ㄷ"));
	ui->F_KBBut->setText(QStringLiteral("ㄹ"));
	ui->G_KBBut->setText(QStringLiteral("ㅎ"));
	ui->H_KBBut->setText(QStringLiteral("ㅗ"));
	ui->I_KBBut->setText(QStringLiteral("ㅑ"));
	ui->J_KBBut->setText(QStringLiteral("ㅓ"));
	ui->K_KBBut->setText(QStringLiteral("ㅏ"));
	ui->L_KBBut->setText(QStringLiteral("ㅣ"));
	ui->M_KBBut->setText(QStringLiteral("ㅡ"));
	ui->N_KBBut->setText(QStringLiteral("ㅜ"));
	ui->O_KBBut->setText(QStringLiteral("ㅐ"));
	ui->P_KBBut->setText(QStringLiteral("ㅔ"));
	ui->Q_KBBut->setText(QStringLiteral("ㅂ"));
	ui->R_KBBut->setText(QStringLiteral("ㄱ"));
	ui->S_KBBut->setText(QStringLiteral("ㄴ"));
	ui->T_KBBut->setText(QStringLiteral("ㅅ"));
	ui->U_KBBut->setText(QStringLiteral("ㅕ"));
	ui->V_KBBut->setText(QStringLiteral("ㅍ"));
	ui->W_KBBut->setText(QStringLiteral("ㅈ"));
	ui->X_KBBut->setText(QStringLiteral("ㅌ"));
	ui->Y_KBBut->setText(QStringLiteral("ㅛ"));
	ui->Z_KBBut->setText(QStringLiteral("ㅋ"));
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
//	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
//	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
//	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
//	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ㅡ"));
//	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ㅜ"));
//	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ㅠ"));
//	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ㅍ"));
//	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ㅊ"));
//	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ㅌ"));
//	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ㅋ"));
//	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("'"));
//	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(";"));
//	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("ㅣ"));
//	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ㅏ"));
//	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ㅓ"));
//	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("ㅗ"));
//	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ㅎ"));
//	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ㄹ"));
//	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("ㅇ"));
//	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ㄴ"));
//	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ㅁ"));
//	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
//	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("]"));
//	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("["));
//	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ㅔ"));
//	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ㅐ"));
//	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ㅑ"));
//	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ㅕ"));
//	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ㅛ"));
//	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ㅅ"));
//	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ㄱ"));
//	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ㄷ"));
//	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ㅈ"));
//	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ㅂ"));
//	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("="));
//	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
//	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
//	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
//	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
//	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
//	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
//	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
//	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
//	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
//	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
//	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
//	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("`"));*/
//}
}

void keyboard::LanKoreanBig()
{
	ui->A_KBBut->setText(QStringLiteral("ㅁ"));
	ui->B_KBBut->setText(QStringLiteral("파"));
	ui->C_KBBut->setText(QStringLiteral("카"));
	ui->D_KBBut->setText(QStringLiteral("나"));
	ui->E_KBBut->setText(QStringLiteral("ㄸ"));
	ui->F_KBBut->setText(QStringLiteral("다"));
	ui->G_KBBut->setText(QStringLiteral("라"));
	ui->H_KBBut->setText(QStringLiteral("마"));
	ui->I_KBBut->setText(QStringLiteral(""));
	ui->J_KBBut->setText(QStringLiteral("바"));
	ui->K_KBBut->setText(QStringLiteral("사"));
	ui->L_KBBut->setText(QStringLiteral("아"));
	ui->M_KBBut->setText(QStringLiteral(""));
	ui->N_KBBut->setText(QStringLiteral("하"));
	ui->O_KBBut->setText(QStringLiteral("ㅒ"));
	ui->P_KBBut->setText(QStringLiteral("ㅖ"));
	ui->Q_KBBut->setText(QStringLiteral("ㅃ"));
	ui->R_KBBut->setText(QStringLiteral("ㄲ"));
	ui->S_KBBut->setText(QStringLiteral("가"));
	ui->T_KBBut->setText(QStringLiteral("ㅆ"));
	ui->U_KBBut->setText(QStringLiteral(""));
	ui->V_KBBut->setText(QStringLiteral("타"));
	ui->W_KBBut->setText(QStringLiteral("ㅉ"));
	ui->X_KBBut->setText(QStringLiteral("차"));
	ui->Y_KBBut->setText(QStringLiteral(""));
	ui->Z_KBBut->setText(QStringLiteral("자"));
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
	ui->one_KBBut->setText(QStringLiteral("ů"));
	ui->two_KBBut->setText(QStringLiteral("ě"));
	ui->three_KBBut->setText(QStringLiteral("š"));
	ui->four_KBBut->setText(QStringLiteral("č"));
	ui->five_KBBut->setText(QStringLiteral("ř"));
	ui->six_KBBut->setText(QStringLiteral("ž"));
	ui->seven_KBBut->setText(QStringLiteral("ý"));
	ui->eight_KBBut->setText(QStringLiteral("á"));
	ui->nine_KBBut->setText(QStringLiteral("í"));
	ui->zero_KBBut->setText(QStringLiteral("é"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("§"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ů"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("¨"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T(")"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ú"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("´"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("é"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("í"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("á"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("ý"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("ž"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ř"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("č"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("š"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ě"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("+"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T(";"));*/
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
	ui->one_KBBut->setText(QStringLiteral("Ú"));
	ui->two_KBBut->setText(QStringLiteral("Ě"));
	ui->three_KBBut->setText(QStringLiteral("Š"));
	ui->four_KBBut->setText(QStringLiteral("Č"));
	ui->five_KBBut->setText(QStringLiteral("Ř"));
	ui->six_KBBut->setText(QStringLiteral("Ž"));
	ui->seven_KBBut->setText(QStringLiteral("Ý"));
	ui->eight_KBBut->setText(QStringLiteral("Á"));
	ui->nine_KBBut->setText(QStringLiteral("Í"));
	ui->zero_KBBut->setText(QStringLiteral("É"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
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
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("°"));*/
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
	//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("="));
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("`"));
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("±"));
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T(">"));
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("|"));
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("^"));
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
	//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("~"));
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("'"));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("_"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
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
	ui->comma_KBBut->setText(QStringLiteral("ä"));
	ui->period_KBBut->setText(QStringLiteral("ö"));
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
	ui->comma_KBBut->setText(QStringLiteral("Ä"));//德语这里没有逗号
	ui->period_KBBut->setText(QStringLiteral("Ö"));//德语的专属符号
	ui->one_KBBut->setText(QStringLiteral("!"));
	ui->two_KBBut->setText(QStringLiteral("\\"));
	ui->three_KBBut->setText(QStringLiteral("§"));
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
	ui->one_KBBut->setText(QStringLiteral("½"));
	ui->two_KBBut->setText(QStringLiteral("¤"));
	ui->three_KBBut->setText(QStringLiteral("`"));
	ui->four_KBBut->setText(QStringLiteral("å"));
	ui->five_KBBut->setText(QStringLiteral("´"));
	ui->six_KBBut->setText(QStringLiteral("'"));
	ui->seven_KBBut->setText(QStringLiteral("ä"));
	ui->eight_KBBut->setText(QStringLiteral("ö"));
	ui->nine_KBBut->setText(QStringLiteral("§"));
	ui->zero_KBBut->setText(QStringLiteral("¨"));
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
	ui->one_KBBut->setText(QStringLiteral("½"));
	ui->two_KBBut->setText(QStringLiteral("¤"));
	ui->three_KBBut->setText(QStringLiteral("`"));
	ui->four_KBBut->setText(QStringLiteral("Å"));
	ui->five_KBBut->setText(QStringLiteral("´"));
	ui->six_KBBut->setText(QStringLiteral("'"));
	ui->seven_KBBut->setText(QStringLiteral("Ä"));
	ui->eight_KBBut->setText(QStringLiteral("Ö"));
	ui->nine_KBBut->setText(QStringLiteral("§"));
	ui->zero_KBBut->setText(QStringLiteral("¨"));
	//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("´"));
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Å"));
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
	//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("`"));
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("¤"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("½"));
	//		break;
	//	}
}

void keyboard::LanHindiSmall()
{
	ui->A_KBBut->setText(QStringLiteral("ो"));
	ui->B_KBBut->setText(QStringLiteral("व"));
	ui->C_KBBut->setText(QStringLiteral("म"));
	ui->D_KBBut->setText(QStringLiteral("्"));
	ui->E_KBBut->setText(QStringLiteral("ा"));
	ui->F_KBBut->setText(QStringLiteral("ि"));
	ui->G_KBBut->setText(QStringLiteral("ु"));
	ui->H_KBBut->setText(QStringLiteral("प"));
	ui->I_KBBut->setText(QStringLiteral("ग"));
	ui->J_KBBut->setText(QStringLiteral("र"));
	ui->K_KBBut->setText(QStringLiteral("क"));
	ui->L_KBBut->setText(QStringLiteral("त"));
	ui->M_KBBut->setText(QStringLiteral("स"));
	ui->N_KBBut->setText(QStringLiteral("ल"));
	ui->O_KBBut->setText(QStringLiteral("द"));
	ui->P_KBBut->setText(QStringLiteral("ज"));
	ui->Q_KBBut->setText(QStringLiteral("ौ"));
	ui->R_KBBut->setText(QStringLiteral("ी"));
	ui->S_KBBut->setText(QStringLiteral("े"));
	ui->T_KBBut->setText(QStringLiteral("ू"));
	ui->U_KBBut->setText(QStringLiteral("ह"));
	ui->V_KBBut->setText(QStringLiteral("न"));
	ui->W_KBBut->setText(QStringLiteral("ै"));
	ui->X_KBBut->setText(QStringLiteral("ं"));
	ui->Y_KBBut->setText(QStringLiteral("ब"));
	ui->Z_KBBut->setText(QStringLiteral("ॆ"));
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("ऍ"));
	ui->two_KBBut->setText(QStringLiteral("ॅ"));
	ui->three_KBBut->setText(QStringLiteral("्य"));
	ui->four_KBBut->setText(QStringLiteral("ट"));
	ui->five_KBBut->setText(QStringLiteral("च"));
	ui->six_KBBut->setText(QStringLiteral("ॉ"));
	ui->seven_KBBut->setText(QStringLiteral("़"));
	ui->eight_KBBut->setText(QStringLiteral("ड"));
	ui->nine_KBBut->setText(QStringLiteral("ृ"));
	ui->zero_KBBut->setText(QStringLiteral("ॊ"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("य"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("स"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ल"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("व"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("न"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("म"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ं"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ॆ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ट"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("च"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("त"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("क"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("र"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("प"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ु"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ि"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("्"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("े"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ो"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ॉ"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("़"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ड"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ज"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("द"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ग"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ह"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ब"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ू"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ी"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ा"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ै"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ौ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ृ"));
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
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ॊ"));*/
}

void keyboard::LanHindiBig()
{                                                //很多符号没有放上
	ui->A_KBBut->setText(QStringLiteral("ओ"));
	ui->B_KBBut->setText(QStringLiteral("ऴ"));
	ui->C_KBBut->setText(QStringLiteral("ण"));
	ui->D_KBBut->setText(QStringLiteral("अ"));
	ui->E_KBBut->setText(QStringLiteral("आ"));
	ui->F_KBBut->setText(QStringLiteral("इ"));
	ui->G_KBBut->setText(QStringLiteral("उ"));
	ui->H_KBBut->setText(QStringLiteral("फ"));
	ui->I_KBBut->setText(QStringLiteral("ँ"));
	ui->J_KBBut->setText(QStringLiteral("ऱ"));
	ui->K_KBBut->setText(QStringLiteral("ख"));
	ui->L_KBBut->setText(QStringLiteral("थ"));
	ui->M_KBBut->setText(QStringLiteral("श"));
	ui->N_KBBut->setText(QStringLiteral("ळ"));
	ui->O_KBBut->setText(QStringLiteral("ध"));
	ui->P_KBBut->setText(QStringLiteral("झ"));
	ui->Q_KBBut->setText(QStringLiteral("औ"));
	ui->R_KBBut->setText(QStringLiteral("ई"));
	ui->S_KBBut->setText(QStringLiteral("ए"));
	ui->T_KBBut->setText(QStringLiteral("घ"));
	ui->U_KBBut->setText(QStringLiteral("ङ"));
	ui->V_KBBut->setText(QStringLiteral("ऩ"));
	ui->W_KBBut->setText(QStringLiteral("ऐ"));
	ui->X_KBBut->setText(QStringLiteral("ँ"));
	ui->Y_KBBut->setText(QStringLiteral("भ"));
	ui->Z_KBBut->setText(QStringLiteral("ऎ"));
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("ऒ"));
	ui->two_KBBut->setText(QStringLiteral("ः"));
	ui->three_KBBut->setText(QStringLiteral("्र"));
	ui->four_KBBut->setText(QStringLiteral("र्"));
	ui->five_KBBut->setText(QStringLiteral("ज्ञ"));
	ui->six_KBBut->setText(QStringLiteral("त्र"));
	ui->seven_KBBut->setText(QStringLiteral("क्ष"));
	ui->eight_KBBut->setText(QStringLiteral("श्र"));
	ui->nine_KBBut->setText(QStringLiteral("("));
	ui->zero_KBBut->setText(QStringLiteral(")"));
	//      GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("य़"));  没放上
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("।"));   没放上
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ष"));   没放上
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("श"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ळ"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ऴ"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ऩ"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ण"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ँ"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ऎ"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ठ"));   没放上
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("छ"));    没放上
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("थ"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ख"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ऱ"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("फ"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("उ"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("इ"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("अ"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ए"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ओ"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ऑ"));   没放上
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ञ"));    没放上
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ढ"));     没放上
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("झ"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ध"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("घ"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ङ"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("भ"));
	//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ऊ"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ई"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("आ"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ऐ"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("औ"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ऋ"));    没放上
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ः"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T(")"));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("श्र"));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("क्ष"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("त्र"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ज्ञ"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("र्"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("्र"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ॅ"));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("ऍ"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ऒ"));
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
