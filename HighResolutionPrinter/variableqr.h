#ifndef VARIABLEQR_H
#define VARIABLEQR_H

#include <QWidget>
#include "ui_variableqr.h"

class variableQR : public QWidget
{
	Q_OBJECT

public:
	variableQR(QWidget *parent = 0);
	~variableQR();

private:
	Ui::variableQR ui;

private slots:
	void returnVarQRBut_clicked();

};

#endif // VARIABLEQR_H
