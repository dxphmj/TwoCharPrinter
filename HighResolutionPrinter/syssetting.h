#ifndef SYSSETTING_H
#define SYSSETTING_H

#include <QWidget>
#include "ui_syssetting.h"

class sysSetting : public QWidget
{
	Q_OBJECT

public:
	sysSetting(QWidget *parent = 0);
	~sysSetting();

private:
	Ui::sysSetting ui;
};

#endif // SYSSETTING_H
