#ifndef ABOUTMAC_H
#define ABOUTMAC_H

#include <QWidget>
#include "ui_aboutmac.h"

class aboutMac : public QWidget
{
	Q_OBJECT

public:
	aboutMac(QWidget *parent = 0);
	~aboutMac();

public:
	Ui::aboutMac ui;
};

#endif // ABOUTMAC_H
