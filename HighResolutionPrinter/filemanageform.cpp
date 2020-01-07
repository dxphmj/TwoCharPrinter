#include "filemanageform.h"
#include "ui_filemanageform.h"
#include <QPushButton>
#include <QStackedWidget>
#include "mainwindow.h"

FilemanageForm::FilemanageForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilemanageForm)
{
    ui->setupUi(this);

	connect(ui->exitBut,SIGNAL(clicked()),this,SLOT(exitBut_clicked()));
	connect(ui->editFileBut,SIGNAL(clicked()),this,SLOT(editFileBut_clicked()));
	connect(ui->manageFileBut,SIGNAL(clicked()),this,SLOT(manageFileBut_clicked()));

 	FormFileManageChild = new FileManageChild(this);//实例化窗口页面
 	FormFileEditChild = new FileEditChild(this);

 	ui->stackedWidget->addWidget(FormFileManageChild);
	ui->stackedWidget->addWidget(FormFileEditChild);
 	ui->stackedWidget->setCurrentWidget(FormFileEditChild);
 /*	ui->stackedWidget->addWidget(FormFileManageChild);*/
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