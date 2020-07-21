#ifndef NOZZLECLEAN_H
#define NOZZLECLEAN_H

#pragma once
#include <QWidget>

namespace Ui {
	class NozzleClean;
}

class NozzleClean : public QWidget
{
	Q_OBJECT

public:
	NozzleClean(QWidget *parent = 0);
	~NozzleClean();

	Ui::NozzleClean *ui;

public://parameters
	bool isOpenClean;
	bool isSingleClean;

public://methods
	void setNumBtnEnabled(bool trig);
	void setSingleCleanEnabled(bool trig);
	void setAllCleanEnabled(bool trig);
	void writeNozzleNum(char* strTempCmd);

public slots:
	void pushButton_1_clicked();
	void pushButton_2_clicked();
	void pushButton_3_clicked();
	void pushButton_4_clicked();
	void pushButton_5_clicked();
	void pushButton_6_clicked();
	void pushButton_7_clicked();
	void pushButton_8_clicked();
	void pushButton_9_clicked();
	void pushButton_10_clicked();
	void pushButton_11_clicked();
	void pushButton_12_clicked();
	void pushButton_13_clicked();
	void pushButton_14_clicked();
	void pushButton_15_clicked();
	void pushButton_16_clicked();
	void openCleanPushButton_clicked();
	void singleCleanPushButton_clicked();
	void allCleanPushButton_clicked();
	void exitButton_clicked();

private://Çý¶¯Ïà¹Ø¾ä±ú
	int fd2; 
	int read_result;
	int write_result;

};

#endif

