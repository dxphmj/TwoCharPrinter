#ifndef SYMBOLWIDGET_H
#define SYMBOLWIDGET_H

#include <QWidget>
#include "ui_symbolwidget.h"

class symbolWidget : public QWidget
{
	Q_OBJECT

public:
	symbolWidget(QWidget *parent = 0);
	~symbolWidget();

private:
	Ui::symbolWidget ui;
};

#endif // SYMBOLWIDGET_H
