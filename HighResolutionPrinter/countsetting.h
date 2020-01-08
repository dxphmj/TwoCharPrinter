#ifndef COUNTSETTING_H
#define COUNTSETTING_H

#include <QWidget>
#include "ui_countsetting.h"

class countSetting : public QWidget
{
	Q_OBJECT

public:
	countSetting(QWidget *parent = 0);
	~countSetting();

private:
	Ui::countSetting ui;
};

#endif // COUNTSETTING_H
