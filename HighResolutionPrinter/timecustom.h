#ifndef TIMECUSTOM_H
#define TIMECUSTOM_H

#include <QWidget>
#include "ui_timecustom.h"

class timeCustom : public QWidget
{
	Q_OBJECT

public:
	timeCustom(QWidget *parent = 0);
	~timeCustom();

private:
	Ui::timeCustom ui;
};

#endif // TIMECUSTOM_H
