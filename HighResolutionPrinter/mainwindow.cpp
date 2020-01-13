#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "filemanageform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	ui->previewLab->installEventFilter(this);


	connect(ui->fileManageBut,SIGNAL(clicked()),this,SLOT(fileManageBut_clicked()));
	connect(ui->paraManageBut,SIGNAL(clicked()),this,SLOT(paraManageBut_clicked()));
 
	ui->fileManageBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/fileManage.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/fileManage.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 ");
		
	ui->paraManageBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/paraManage.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/paraManage.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 "); 
	ui->startPrintBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/startPrint.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/startPrint.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 "); 
	ui->closeBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/closeSys.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/closeSys.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								");  
	ui->roolLab->setStyleSheet("background-color: rgb(67,51, 139);border-radius:10px;color: rgb(255, 255, 255);");  
 
	ui->previewLab->setStyleSheet("background-color: rgb(255,255,255);"); 

	m_PrinterMes.ReadBmp("D:\\1.bmp");
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui->previewLab && event->type() == QEvent::Paint)
	{
		QPainter painter(ui->previewLab);
		m_PrinterMes.DrawDot(&painter);
	}
	return QWidget::eventFilter(watched,event);
}

void MainWindow::fileManageBut_clicked()
{
	m_fileManage.show();
}

void MainWindow::paraManageBut_clicked()
{
	m_paramsetting.show();
}
