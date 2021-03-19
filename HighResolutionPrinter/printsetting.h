#ifndef PRINTSETTING_H
#define PRINTSETTING_H

#include <QWidget>
#include "ui_printsetting.h"
#include "mainwindow.h"
#include <QButtonGroup>

class numkeyboard;

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
	double calCurProSpeed(int pulsePerRound); //计算当前的产线速度，并显示在proLineSpeedShowLab上
	QButtonGroup* XDPIradioBG;
	QButtonGroup* YDPIradioBG;
	QButtonGroup* NozzleradioBG;
	numkeyboard *pNumKeyboard;

public slots:
	void synWheelCheckBox_valueChanged(int);
	void trigComBox_ValueChanged(int);

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
	void encoderResLineEdit_clicked();
	void wheelDiameterLineEdit_clicked();
	void pulseWidthLineEdit_clicked();
	void colWidthLineEdit_clicked();

};

#endif // PRINTSETTING_H
