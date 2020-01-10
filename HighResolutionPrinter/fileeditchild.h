#ifndef FILEEDITCHILD_H
#define FILEEDITCHILD_H

#include <QWidget>
#include "ui_fileeditchild.h"
#include "ClassMessage.h"

using namespace MyNameSpace;

class FileEditChild : public QWidget
{
	Q_OBJECT

public:
	FileEditChild(QWidget *parent = 0);
	~FileEditChild();
	ClassMessage m_PrinterMes;
	int QrecodeMatrix[25][25];

private:
	Ui::FileEditChild ui;

private slots:
	void variableTextBut_clicked();

protected:
	void paintEvent(QPaintEvent *event);
	void paintDot();
	bool eventFilter(QObject *watched, QEvent *event);
};

#endif // FILEEDITCHILD_H
