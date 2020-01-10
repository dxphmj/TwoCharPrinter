#ifndef FILEEDITCHILD_H
#define FILEEDITCHILD_H

#include <QWidget>
#include "ui_fileeditchild.h"

class FileEditChild : public QWidget
{
	Q_OBJECT

public:
	FileEditChild(QWidget *parent = 0);
	~FileEditChild();

private:
	Ui::FileEditChild ui;

private slots:
	void variableTextBut_clicked();

};

#endif // FILEEDITCHILD_H
