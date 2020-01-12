#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include "ui_keyboard.h"
#include <QLineEdit>


class keyboard : public QWidget
{
	Q_OBJECT

public:
	keyboard(QWidget *parent = 0);
	~keyboard();

private:
	Ui::keyboard ui;

private slots:
	void A_KBBut_clicked();
};

#endif // KEYBOARD_H
