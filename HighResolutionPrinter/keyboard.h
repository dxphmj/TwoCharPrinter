#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include "ui_keyboard.h"
#include <QLineEdit>
#include <QString>

class keyboard : public QWidget
{
	Q_OBJECT

public:
	keyboard(QWidget *parent = 0);
	~keyboard();
	QString returnText();

private:
	Ui::keyboard ui;
	QString value;

public:
	QString A_KBBut_clicked();
};

#endif // KEYBOARD_H
