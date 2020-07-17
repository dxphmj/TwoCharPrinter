#include "NozzleClean.h"
#include "ui_nozzleclean.h"
#include <QtWidgets/QStackedWidget>

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

void NozzleClean::pushButton_1_clicked()
{

}

void NozzleClean::pushButton_2_clicked()
{

}

void NozzleClean::pushButton_3_clicked()
{

}

void NozzleClean::pushButton_4_clicked()
{

}

void NozzleClean::pushButton_5_clicked()
{

}

void NozzleClean::pushButton_6_clicked()
{

}

void NozzleClean::pushButton_7_clicked()
{

}

void NozzleClean::pushButton_8_clicked()
{

}

void NozzleClean::pushButton_9_clicked()
{

}

void NozzleClean::pushButton_10_clicked()
{

}

void NozzleClean::pushButton_11_clicked()
{

}

void NozzleClean::pushButton_12_clicked()
{

}

void NozzleClean::pushButton_13_clicked()
{

}

void NozzleClean::pushButton_14_clicked()
{

}

void NozzleClean::pushButton_15_clicked()
{

}

void NozzleClean::pushButton_16_clicked()
{

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

}

void NozzleClean::exitButton_clicked()
{
	this->setVisible(false);
}