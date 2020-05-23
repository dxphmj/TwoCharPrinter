#include "filemanageform.h"
#include "ui_filemanageform.h"
#include <QPushButton>
#include <QStackedWidget>
#include "fileeditchild.h"
#include "variblewidget.h"
#include "variablebarcode.h"
#include "variableqr.h"
#include "variabledm.h"

#include "timecustom.h"
#include "filemanagechild.h"

FilemanageForm::FilemanageForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilemanageForm)
{
    ui->setupUi(this);

	setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);hide();
	this->setParent(parent);

	connect(ui->exitBut,SIGNAL(clicked()),this,SLOT(exitBut_clicked()));
	connect(ui->editFileBut,SIGNAL(clicked()),this,SLOT(editFileBut_clicked()));
	connect(ui->manageFileBut,SIGNAL(clicked()),this,SLOT(manageFileBut_clicked()));

	ui->editFileBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/editFile.bmp);border-radius:15px;color:rgb(255,255,255)}\
								   QPushButton:pressed{border-image: url(:/Images/editFile.bmp);border: 1px solid rgb(12 , 138 , 235);\
								   padding-left:7px;padding-top:7px;}\
								   "); 
	ui->manageFileBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/manageFile.bmp);border-radius:15px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/manageFile.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 "); 
	ui->exitBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/exit.bmp);border-radius:15px;color:rgb(255,255,255)}\
							   QPushButton:pressed{border-image: url(:/Images/exit.bmp);border: 1px solid rgb(12 , 138 , 235);\
							   padding-left:7px;padding-top:7px;}\
							   "); 
	
 	FormFileManageChild = new FileManageChild(this);//实例化窗口页面
 	FormFileEditChild = new FileEditChild(this);
	fontVarWidget = new varibleWidget(this);
	BarCodeWidget = new variableBarCode(this);
	QRWidget = new variableQR(this);
	DMWidget = new variableDM(this);
	timeCustomWidget = new timeCustom(this);

 	ui->stackedWidget->addWidget(FormFileManageChild);
	ui->stackedWidget->addWidget(FormFileEditChild);
	ui->stackedWidget->addWidget(fontVarWidget);
	ui->stackedWidget->addWidget(BarCodeWidget);
	ui->stackedWidget->addWidget(QRWidget);
	ui->stackedWidget->addWidget(DMWidget);
	ui->stackedWidget->addWidget(timeCustomWidget);
 	ui->stackedWidget->setCurrentWidget(FormFileEditChild);
}

FilemanageForm::~FilemanageForm()
{
    delete ui;
}


void FilemanageForm::exitBut_clicked()
{
	this->close();
}

void FilemanageForm::editFileBut_clicked()
{	
	ui->stackedWidget->setCurrentWidget(FormFileEditChild);
}

void FilemanageForm::manageFileBut_clicked()
{
	ui->stackedWidget->setCurrentWidget(FormFileManageChild);
}

void FilemanageForm::variableWidgetCall()
{
	ui->stackedWidget->setCurrentWidget(fontVarWidget);
}

void FilemanageForm::variableBarCodeWidgetCall()
{
	ui->stackedWidget->setCurrentWidget(BarCodeWidget);
}

void FilemanageForm::variableQRWidgetCall()
{
	ui->stackedWidget->setCurrentWidget(QRWidget);
}

void FilemanageForm::variableDMWidgetCall()
{
	ui->stackedWidget->setCurrentWidget(DMWidget);
}

void FilemanageForm::timeCustomCall()
{
	ui->stackedWidget->setCurrentWidget(timeCustomWidget);
}

void FilemanageForm::FileEditChildWidgetCall()
{
	ui->stackedWidget->setCurrentWidget(FormFileEditChild);
}

void FilemanageForm::FileManageChildWidgetCall()
{
	ui->stackedWidget->setCurrentWidget(FormFileManageChild);
}