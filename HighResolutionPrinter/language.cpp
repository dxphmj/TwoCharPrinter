#include "language.h"
#include "ui_language.h"
#include <QtWidgets/QStackedWidget>
#include "fileeditchild.h"
#include "keyboard.h"

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
	
}

language::~language()
{
	
}

void language::OKLanBut_clicked()
{
	//暂时用wordLineEdit_clicked调出KB
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->returnKB();    
}

void language::lanEnglish_KBBut_clicked()
{
	//用于English切换回原键盘
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->keyboardWidget->m_Upper = true;
	pFileEditChild->keyboardWidget->m_LanType = 7;
	pFileEditChild->keyboardWidget->caps1_kBBut_clicked();
	pFileEditChild->returnKB(); 
}

void language::LanChinese_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->keyboardWidget->m_Upper = false;
	pFileEditChild->keyboardWidget->m_LanType = 0;
	pFileEditChild->keyboardWidget->caps1_kBBut_clicked();
	pFileEditChild->returnKB(); 
}

void language::LanKorean_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->keyboardWidget->m_Upper = true;
	pFileEditChild->keyboardWidget->m_LanType = 22;
	pFileEditChild->keyboardWidget->caps1_kBBut_clicked();
	pFileEditChild->returnKB(); 
}

void language::LanCzech_KBBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->keyboardWidget->m_Upper = false;
	pFileEditChild->keyboardWidget->m_LanType = 8;
	pFileEditChild->keyboardWidget->caps1_kBBut_clicked();
	pFileEditChild->returnKB(); 
}
