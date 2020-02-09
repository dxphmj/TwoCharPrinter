#ifndef VARIBLEWIDGET_H
#define VARIBLEWIDGET_H

#include <QWidget>
#include "ui_variblewidget.h"

class varibleWidget : public QWidget
{
	Q_OBJECT

public:
	varibleWidget(QWidget *parent = 0);
	~varibleWidget();

public:
	Ui::varibleWidget ui;

private slots:
	void returnVarTextBut_clicked();

};

#endif // VARIBLEWIDGET_H
