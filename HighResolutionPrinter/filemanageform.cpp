#include "filemanageform.h"
#include "ui_filemanageform.h"
#include <QPushButton>
#include <QStackedWidget>
//#include "mainwindow.h"

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

	ui->editFileBut->setStyleSheet("text-align:bottom;background-image: url(:/Images/editFile.bmp);font: bold; font-size:30px;color:rgb(255,255,255)"); 
	ui->manageFileBut->setStyleSheet("text-align:bottom;background-image: url(:/Images/manageFile.bmp);font: bold; font-size:30px;color:rgb(255,255,255)"); 
	ui->exitBut->setStyleSheet("text-align:bottom;background-image: url(:/Images/exit.bmp);font: bold; font-size:30px;color:rgb(255,255,255)"); 


 	FormFileManageChild = new FileManageChild(this);//实例化窗口页面
 	FormFileEditChild = new FileEditChild(this);
	fontVarWidget = new varibleWidget(this);

 	ui->stackedWidget->addWidget(FormFileManageChild);
	ui->stackedWidget->addWidget(FormFileEditChild);
	ui->stackedWidget->addWidget(fontVarWidget);
 	ui->stackedWidget->setCurrentWidget(FormFileEditChild);
}

FilemanageForm::~FilemanageForm()
{
    delete ui;
}


void FilemanageForm::exitBut_clicked()
{
	this->hide();
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
