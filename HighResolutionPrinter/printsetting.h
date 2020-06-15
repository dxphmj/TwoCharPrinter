#ifndef PRINTSETTING_H
#define PRINTSETTING_H

#include <QWidget>
#include "ui_printsetting.h"
#include "mainwindow.h"
#include <QButtonGroup>

class printSetting : public QWidget
{
	Q_OBJECT

public:
	printSetting(QWidget *parent = 0);
	~printSetting();

public:
	Ui::printSetting ui;

public:
	QString getNum(QString str);
	QButtonGroup* XDPIradioBG;
	QButtonGroup* YDPIradioBG;
	QButtonGroup* NozzleradioBG;

private slots:
	void printSpeedRedBut();
	void printSpeedAddBut();
	void printDelayRedBut();
	void printDelayAddBut();
	void synFrequencyRedBut();
	void synFrequencyAddBut();
	void printGrayRedBut();
	void printGrayAddBut();
	void repeteNumRedBut();
	void repeteNumAddBut();
	void repeteDelayRedBut();
	void repeteDelayAddBut();
	void voltRedBut();
	void voltAddBut();
	void PWRedBut();
	void PWAddBut();
	void offsetRedBut();
	void offsetAddBut();
	void flashSprayInternalRedBut();
	void flashSprayInternalAddBut();
	void flashSprayTimesRedBut();
	void flashSprayTimesAddBut();

};

#endif // PRINTSETTING_H
