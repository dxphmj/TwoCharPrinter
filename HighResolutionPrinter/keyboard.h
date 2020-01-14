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

private:
	Ui::keyboard ui;
	QString value;
	QString str;
	QString val;
	//FileEditChild  *showText;

public:
	QString A_KBBut_sendData();
    QString B_KBBut_sendData();

private slots:
	void enter_KBBut_clicked();
	void A_KBBut_clicked();
	void B_KBBut_clicked();
	void backspace_KBBut_clicked();

};

#endif // KEYBOARD_H
