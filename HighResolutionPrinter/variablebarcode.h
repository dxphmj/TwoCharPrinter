#ifndef VARIABLEBARCODE_H
#define VARIABLEBARCODE_H

#include <QWidget>
#include "ui_variablebarcode.h"

class variableBarCode : public QWidget
{
	Q_OBJECT

public:
	variableBarCode(QWidget *parent = 0);
	~variableBarCode();

private:
	Ui::variableBarCode ui;

private slots:
	void returnVarBarCodeBut_clicked();

};

#endif // VARIABLEBARCODE_H
