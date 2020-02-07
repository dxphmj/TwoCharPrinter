#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTime>
#include "filemanageform.h"
#include "paramsettingform.h"
#include "ClassMessage.h"
#include "PrintThead.h"
#include "PrintCreatThread.h"
#include "PrintShowThread.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	m_bPrintNow = false;
	m_bDynamicPrint = false;

	ui->previewLab->installEventFilter(this);
 
	m_fileManage = new FilemanageForm(this);
	m_paramsetting = new ParamSettingForm(this);
	m_paramsetting->hide();
	m_fileManage->hide();

	m_PrinterMes = new ClassMessage();
	
	connect(ui->fileManageBut,SIGNAL(clicked()),this,SLOT(fileManageBut_clicked()));
	connect(ui->paraManageBut,SIGNAL(clicked()),this,SLOT(paraManageBut_clicked()));
	connect(ui->closeBut,SIGNAL(clicked()),this,SLOT(closeBut_clicked()));
	connect(ui->startPrintBut,SIGNAL(clicked()),this,SLOT(PrintBut_clicked()));

	ui->fileManageBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/fileManage.bmp);border-radius:15px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/fileManage.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 ");
		
	ui->paraManageBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/paraManage.bmp);border-radius:15px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/paraManage.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 "); 
	ui->startPrintBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/startPrint.bmp);border-radius:15px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/startPrint.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 "); 
	ui->closeBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/closeSys.bmp);border-radius:15px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/closeSys.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								");  
	ui->roolLab->setStyleSheet("background-color: rgb(67,51, 139);border-radius:10px;color: rgb(255, 255, 255);");  
 
	ui->previewLab->setStyleSheet("background-color: rgb(255,255,255);"); 

//	m_PrinterMes->ReadBmp("D:\\1.bmp");
	myTimer = new QTimer(this);
	myTimer->start(0);
	connect(myTimer,SIGNAL(timeout()),this,SLOT(GetDateTime()));
	ui->timeShowLab->setStyleSheet("qproperty-alignment: 'AlignVCenter | AlignRight';color:rgb(255,255,255);font-size:40px;");
	 
	m_pPrintThread = new PrintThead(this);//启动打印线程
	m_pPrintThread->start();
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
	 	m_PrinterMes->DrawDot(&painter);
	}
	return QWidget::eventFilter(watched,event);
}

void MainWindow::RefreshWindow()
{
	//m_PrinterMes->ReadBmp(this->FilemanageForm->FormFileManageChild->GetCurXmlFile());
	QWidget *pQWidget(this);
	pQWidget->update();
}

void MainWindow::fileManageBut_clicked()
{
	m_paramsetting->hide();
	m_fileManage->show();
}

void MainWindow::paraManageBut_clicked()
{
	m_fileManage->hide();
	m_paramsetting->show();
}

void MainWindow::closeBut_clicked()
{

}

void MainWindow::PrintBut_clicked()
{
	m_bPrintNow = !m_bPrintNow;

	m_pPrintCreateThread = new PrintCreatThread(this);//启动打印内容生成线程
	m_pPrintCreateThread->start();
	m_pPrintShowThread = new PrintShowThread(this);//启动主界面打印显示线程
	m_pPrintShowThread->start();
}

void MainWindow::GetDateTime()
{
	 QTime timeNow=QTime::currentTime();
	 ui->timeShowLab->setText((QDate::currentDate().toString(tr("yyyy-MM-dd   ")))+tr("%1").arg(timeNow.toString())+tr("  "));
}

