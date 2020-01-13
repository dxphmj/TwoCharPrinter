#ifndef FILEEDITCHILD_H
#define FILEEDITCHILD_H

#include <QWidget>
#include "ui_fileeditchild.h"
#include "ClassMessage.h"
#include "keyboard.h"
#include "lineedit_click.h"

using namespace MyNameSpace;

class FileEditChild : public QWidget
{
	Q_OBJECT

public:
	FileEditChild(QWidget *parent = 0);
	~FileEditChild();
	ClassMessage m_PrinterMes;
	int QrecodeMatrix[25][25];
	void ReadBmp(char* strFileName);
	void ShowText(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent,
		int txtRowSize, int txtLineSize, int txtLineStart, int txtRowStart, int txtSS, int txtSW);

private:
	Ui::FileEditChild ui;
	keyboard  *keyboardWidget;
	//keyboard key;

private slots:
	void variableTextBut_clicked();
	void customTimeBut_clicked();
	void selBmpBut_clicked();
	void editBut_clicked();
	void delBut_clicked();
	void wordLineEdit_clicked();
	void barCodeLineEdit_clicked();
	void QRCodeLineEdit_clicked();
	void DMCodeLineEdit_clicked();


protected:
	//void paintEvent(QPaintEvent *event);
	void paintDot();
	bool eventFilter(QObject *watched, QEvent *event);

public:
	//void test_clicked();

};

#endif // FILEEDITCHILD_H
