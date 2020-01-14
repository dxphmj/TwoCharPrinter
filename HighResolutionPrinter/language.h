#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QWidget>
#include "ui_language.h"

class language : public QWidget
{
	Q_OBJECT

public:
	language(QWidget *parent = 0);
	~language();

private:
	Ui::language ui;

private slots:
	void OKLanBut_clicked();

};

#endif // LANGUAGE_H
