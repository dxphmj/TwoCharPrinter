#ifndef PRINTSETTING_H
#define PRINTSETTING_H

#include <QWidget>
#include "ui_printsetting.h"

class printSetting : public QWidget
{
	Q_OBJECT

public:
	printSetting(QWidget *parent = 0);
	~printSetting();
	Ui::printSetting ui;
};

#endif // PRINTSETTING_H
