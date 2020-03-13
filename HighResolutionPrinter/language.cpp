#include "language.h"
#include "ui_language.h"
#include <QtWidgets/QStackedWidget>
#include "keyboard.h"
#include <QPushButton>
#include <QHBoxLayout>
#include "fileeditchild.h"
#include <QTabWidget>

//extern int m_LineeditChange;

language::language(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::language)
{
	ui->setupUi(this);
	

	connect(ui->OKLanBut,SIGNAL(clicked()),this,SLOT(OKLanBut_clicked()));
	connect(ui->LanEnglish,SIGNAL(clicked()),this,SLOT(lanEnglish_KBBut_clicked()));
	connect(ui->LanChinese,SIGNAL(clicked()),this,SLOT(LanChinese_KBBut_clicked()));
	connect(ui->LanKorean,SIGNAL(clicked()),this,SLOT(LanKorean_KBBut_clicked()));
	connect(ui->LanCzech,SIGNAL(clicked()),this,SLOT(LanCzech_KBBut_clicked()));
	connect(ui->LanJapanese,SIGNAL(clicked()),this,SLOT(LanJapanese_KBBut_clicked()));
	connect(ui->LanDutch,SIGNAL(clicked()),this,SLOT(LanDutch_KBBut_clicked()));
	connect(ui->LanGerman,SIGNAL(clicked()),this,SLOT(LanGerman_KBBut_clicked()));
	connect(ui->LanFarsi,SIGNAL(clicked()),this,SLOT(LanFarsi_KBBut_clicked()));
	connect(ui->LanHindi,SIGNAL(clicked()),this,SLOT(LanHindi_KBBut_clicked()));
	connect(ui->LanArabic,SIGNAL(clicked()),this,SLOT(LanArabic_KBBut_clicked()));

	//connect(ui->LanChinese,SIGNAL(clicked()),this,SLOT(sendslot()));//将信号传给父窗口

}

language::~language()
{
	
}

void language::OKLanBut_clicked()
{
	//暂时用wordLineEdit_clicked调出KB
	setVisible(false);   
}

void language::lanEnglish_KBBut_clicked()
{
	//用于English切换回原键盘
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 7;
	pKeyboard->caps1_kBBut_clicked();
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(pKeyboard->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->ChangeTabLineEdit();
	setVisible(false); 
}

void language::LanChinese_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 0;
	pKeyboard->m_LantypeReverse = 1;//Chinese
	pKeyboard->caps1_kBBut_clicked();
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(pKeyboard->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
    pFileEditChild->ChangeTabLineEdit();
	pKeyboard->setText2KBLineedit();//走中文编辑框

	setVisible(false);  
}

void language::LanKorean_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 22;
	pKeyboard->m_LantypeReverse = 2;//Kore 
	pKeyboard->caps1_kBBut_clicked();
	pKeyboard->setText2KBLineedit();
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(pKeyboard->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->ChangeTabLineEdit();
	setVisible(false);   
}

void language::LanJapanese_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 1;
	pKeyboard->m_LantypeReverse = 4;//Japanese 
	pKeyboard->caps1_kBBut_clicked();
	pKeyboard->setText2KBLineedit();
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(pKeyboard->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->ChangeTabLineEdit();
	setVisible(false); 
}

void language::LanCzech_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 8;
	pKeyboard->m_LantypeReverse = 3;//Czech 
	pKeyboard->caps1_kBBut_clicked();
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(pKeyboard->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->ChangeTabLineEdit();
	setVisible(false); 
}

void language::LanDutch_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 9;
	pKeyboard->m_LantypeReverse = 5;//Dutch
	pKeyboard->caps1_kBBut_clicked();
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(pKeyboard->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->ChangeTabLineEdit();
	setVisible(false); 
}

void language::LanGerman_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 10;
	pKeyboard->m_LantypeReverse = 6;//German
	pKeyboard->caps1_kBBut_clicked();
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(pKeyboard->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->ChangeTabLineEdit();
	setVisible(false); 
}

void language::LanFarsi_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 11;
	pKeyboard->m_LantypeReverse = 7;//Farsi
	pKeyboard->caps1_kBBut_clicked();
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(pKeyboard->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->ChangeTabLineEdit();
	setVisible(false); 
}

void language::LanHindi_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 12;
	pKeyboard->m_LantypeReverse = 8;//Hindi
	pKeyboard->caps1_kBBut_clicked();
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(pKeyboard->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->ChangeTabLineEdit();
	setVisible(false); 
}

void language::LanArabic_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 5;
	pKeyboard->m_LantypeReverse = 8;////Arabic
	pKeyboard->caps1_kBBut_clicked();
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(pKeyboard->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->ChangeTabLineEdit();
	setVisible(false);
}

//void language::sendslot()
//{
//	emit languageEvent();//中间量，将子窗口的槽函数转化为父窗口的信号
//}

