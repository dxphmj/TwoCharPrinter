#ifndef VARIABLEDM_H
#define VARIABLEDM_H

#include <QWidget>
#include "ui_variabledm.h"

class variableDM : public QWidget
{
	Q_OBJECT

public:
	variableDM(QWidget *parent = 0);
	~variableDM();

private:
	Ui::variableDM ui;

private slots:
	void returnVarDMBut_clicked();

};

#endif // VARIABLEDM_H
