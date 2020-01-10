#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "filemanageform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



	connect(ui->fileManageBut,SIGNAL(clicked()),this,SLOT(fileManageBut_clicked()));
	connect(ui->paraManageBut,SIGNAL(clicked()),this,SLOT(paraManageBut_clicked()));
 
	ui->fileManageBut->setStyleSheet("text-align:bottom;background-image: url(:/Images/fileManage.bmp);font: bold; font-size:30px;color:rgb(255,255,255)"); 
	ui->paraManageBut->setStyleSheet("text-align:bottom;background-image: url(:/Images/paraManage.bmp);font: bold; font-size:30px;color:rgb(255,255,255)"); 
	ui->startPrintBut->setStyleSheet("text-align:bottom;background-image: url(:/Images/startPrint.bmp);font: bold; font-size:30px;color:rgb(255,255,255)"); 
	ui->closeBut->setStyleSheet("text-align:bottom;background-image: url(:/Images/closeSys.bmp);font: bold; font-size:30px;color:rgb(255,255,255)");  
	ui->roolLab->setStyleSheet("background-color: rgb(67,51, 139);border-radius:10px;color: rgb(255, 255, 255);");  

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileManageBut_clicked()
{
	m_fileManage.show();
}

void MainWindow::paraManageBut_clicked()
{
	m_paramsetting.show();
}
