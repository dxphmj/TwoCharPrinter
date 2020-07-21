#include "NozzleClean.h"
#include "ui_nozzleclean.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QStackedWidget>
//驱动相关头文件
#include <fcntl.h>
#include <unistd.h>

NozzleClean::NozzleClean(QWidget *parent): 
	QWidget(parent),
	ui(new Ui::NozzleClean)
{
	ui->setupUi(this);

	connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(pushButton_1_clicked()));
	connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(pushButton_2_clicked()));
	connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(pushButton_3_clicked()));
	connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(pushButton_4_clicked()));
	connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(pushButton_5_clicked()));
	connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(pushButton_6_clicked()));
	connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(pushButton_7_clicked()));
	connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(pushButton_8_clicked()));
	connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(pushButton_9_clicked()));
	connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(pushButton_10_clicked()));
	connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(pushButton_11_clicked()));
	connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(pushButton_12_clicked()));
	connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(pushButton_13_clicked()));
	connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(pushButton_14_clicked()));
	connect(ui->pushButton_15,SIGNAL(clicked()),this,SLOT(pushButton_15_clicked()));
	connect(ui->pushButton_16,SIGNAL(clicked()),this,SLOT(pushButton_16_clicked()));
	connect(ui->openCleanPushButton,SIGNAL(clicked()),this,SLOT(openCleanPushButton_clicked()));
	connect(ui->singleCleanPushButton,SIGNAL(clicked()),this,SLOT(singleCleanPushButton_clicked()));
	connect(ui->allCleanPushButton,SIGNAL(clicked()),this,SLOT(allCleanPushButton_clicked()));
	connect(ui->exitButton,SIGNAL(clicked()),this,SLOT(exitButton_clicked()));

	isOpenClean = false;
	isSingleClean = false;
	setNumBtnEnabled(isOpenClean);
	setSingleCleanEnabled(isOpenClean);
	setAllCleanEnabled(isOpenClean);
}

NozzleClean::~NozzleClean(){}

void NozzleClean::setNumBtnEnabled(bool trig)
{
	if (trig)
	{
		ui->pushButton_1->setEnabled(true);
		ui->pushButton_2->setEnabled(true);
		ui->pushButton_3->setEnabled(true);
		ui->pushButton_4->setEnabled(true);
		ui->pushButton_5->setEnabled(true);
		ui->pushButton_6->setEnabled(true);
		ui->pushButton_7->setEnabled(true);
		ui->pushButton_8->setEnabled(true);
		ui->pushButton_9->setEnabled(true);
		ui->pushButton_10->setEnabled(true);
		ui->pushButton_11->setEnabled(true);
		ui->pushButton_12->setEnabled(true);
		ui->pushButton_13->setEnabled(true);
		ui->pushButton_14->setEnabled(true);
		ui->pushButton_15->setEnabled(true);
		ui->pushButton_16->setEnabled(true);

		ui->pushButton_1->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_2->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_3->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_4->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_5->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_6->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_7->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_8->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_9->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_10->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_11->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_12->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_13->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_14->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_15->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
		ui->pushButton_16->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(0, 0, 230);font: 18pt '楷体';color: rgb(255, 255, 255);");
	}
	else
	{
		ui->pushButton_1->setEnabled(false);
		ui->pushButton_2->setEnabled(false);
		ui->pushButton_3->setEnabled(false);
		ui->pushButton_4->setEnabled(false);
		ui->pushButton_5->setEnabled(false);
		ui->pushButton_6->setEnabled(false);
		ui->pushButton_7->setEnabled(false);
		ui->pushButton_8->setEnabled(false);
		ui->pushButton_9->setEnabled(false);
		ui->pushButton_10->setEnabled(false);
		ui->pushButton_11->setEnabled(false);
		ui->pushButton_12->setEnabled(false);
		ui->pushButton_13->setEnabled(false);
		ui->pushButton_14->setEnabled(false);
		ui->pushButton_15->setEnabled(false);
		ui->pushButton_16->setEnabled(false);

		ui->pushButton_1->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_2->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_3->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_4->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_5->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_6->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_7->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_8->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_9->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_10->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_11->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_12->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_13->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_14->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_15->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
		ui->pushButton_16->setStyleSheet("border-color: rgb(255, 255, 255);background-color: rgb(125,125,125,80);font: 18pt '楷体';color: rgb(125, 125, 125);");
	}
}

void NozzleClean::setSingleCleanEnabled(bool trig)
{
	ui->singleCleanPushButton->setEnabled(trig);
	if (trig)
	{
		ui->singleCleanPushButton->setStyleSheet("color: rgb(255, 255, 255);font: 18pt '楷体';background-color: rgb(0,0,230);");
	}
	else
	{
		ui->singleCleanPushButton->setStyleSheet("color: rgb(125, 125, 125);font: 18pt '楷体';background-color: rgb(125,125,125,80);");
	}
	
}

void NozzleClean::setAllCleanEnabled(bool trig)
{
	ui->allCleanPushButton->setEnabled(trig);
	if (trig)
	{
		ui->allCleanPushButton->setStyleSheet("color: rgb(255, 255, 255);font: 18pt '楷体';background-color: rgb(0,0,230);");
	}
	else
	{
		ui->allCleanPushButton->setStyleSheet("color: rgb(125, 125, 125);font: 18pt '楷体';background-color: rgb(125,125,125,80);");
	}
}

void NozzleClean::writeNozzleNum(char* strTempCmd)
{
	char iTest[1];
	char *Nozzle_node = "/dev/Nozzle_ctl";

	/*O_RDWR读写打开,O_NDELAY非阻塞方式*/
	if((fd2 = open(Nozzle_node,O_RDWR))<0)
	{
		printf("Nozzle open %s failed",Nozzle_node);
	}
	else
	{
		read_result = read(fd2,iTest,1);
		if(read_result == 0)
		{
			write_result = write(fd2,strTempCmd,8);
			if (write_result)
			{
				free(strTempCmd);
			}

			if(write_result == -1)
			{
				printf("Write is failed!\n");
			}
			else
			{
				printf("Write is success!\n");
			}

			//printf("write_complete!");
		}
		else
		{
			printf("The system is busy now!\n");
		}

		//read_result = read(fd2,buffer,1);
	}
	//::close(fd2);
}

void NozzleClean::pushButton_1_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 0;
	tmpChar[1] = -127;
    writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_2_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 0;
	tmpChar[1] = 64;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_3_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 0;
	tmpChar[1] = 32;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_4_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 0;
	tmpChar[1] = 16;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_5_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 0;
	tmpChar[1] = 8;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_6_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 0;
	tmpChar[1] = 4;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_7_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 0;
	tmpChar[1] = 2;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_8_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 0;
	tmpChar[1] = 1;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_9_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = -127;
	tmpChar[1] = 0;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_10_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 64;
	tmpChar[1] = 0;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_11_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 32;
	tmpChar[1] = 0;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_12_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 16;
	tmpChar[1] = 0;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_13_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 8;
	tmpChar[1] = 0;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_14_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 4;
	tmpChar[1] = 0;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_15_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 2;
	tmpChar[1] = 0;
	writeNozzleNum(tmpChar);
}

void NozzleClean::pushButton_16_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = 1;
	tmpChar[1] = 0;
	writeNozzleNum(tmpChar);
}

void NozzleClean::openCleanPushButton_clicked()
{
	if (isOpenClean && isSingleClean)
	{
		isSingleClean = false;
		//ui->singleCleanPushButton->setDown(false);
		setNumBtnEnabled(false);
	}
	isOpenClean = !isOpenClean;
	setSingleCleanEnabled(isOpenClean);
	setAllCleanEnabled(isOpenClean);
	//ui->openCleanPushButton->setDown(isOpenClean);
}

void NozzleClean::singleCleanPushButton_clicked()
{
	isSingleClean = !isSingleClean;
	//ui->singleCleanPushButton->setDown(isSingleClean);
	setNumBtnEnabled(isSingleClean);
	setAllCleanEnabled(!isSingleClean);
}

void NozzleClean::allCleanPushButton_clicked()
{
	char* tmpChar = (char*)malloc(2);
	tmpChar[0] = -127;
	tmpChar[1] = -127;
	writeNozzleNum(tmpChar);
}

void NozzleClean::exitButton_clicked()
{
	MainWindow* theApp = (MainWindow*)(this->parent());
	theApp->ui->fileManageBut->setEnabled(true);
	theApp->ui->paraManageBut->setEnabled(true);
	theApp->ui->startPrintBut->setEnabled(true);
	this->setVisible(false);
}