#ifndef FILEEDITCHILD_H
#define FILEEDITCHILD_H

#include <QWidget>
#include "ui_fileeditchild.h"
#include "ClassMessage.h"
#include "keyboard.h"
#include "lineedit_click.h"
#include <QLineEdit>
#include "language.h"

using namespace MyNameSpace;

class FileEditChild : public QWidget
{
	Q_OBJECT

public:
	FileEditChild(QWidget *parent = 0);
	~FileEditChild();
	ClassMessage m_PrinterMes;
	int QrecodeMatrix[25][25];
	void Create2Dcode(int nType,QString strContent);
	void ReadBmp(char* strFileName);
	void ShowText(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent,
		int txtRowSize, int txtLineSize, int txtLineStart, int txtRowStart, int txtSS, int txtSW);

private:
	Ui::FileEditChild ui;
	keyboard  *keyboardWidget;
	language  *languageWidget;
	keyboard key;
	QString str1;

private slots:
	void variableTextBut_clicked();
	void customTimeBut_clicked();
	void selBmpBut_clicked();
	void delBut_clicked();
	void wordLineEdit_clicked();
	void barCodeLineEdit_clicked();
	void QRCodeLineEdit_clicked();
	void DMCodeLineEdit_clicked();
	void newTextBut_clicked();
	void newBarCodeBut_clicked();
	void newQRBut_clicked();
	void newDMBut_clicked();
	void moveUpBut_clicked();
	void moveDownBut_clicked();
	void moveLeftBut_clicked();
	void moveRightBut_clicked();


protected:
	//void paintEvent(QPaintEvent *event);
	void paintDot();
	bool eventFilter(QObject *watched, QEvent *event);

public:
	void hideKB();
	void languageWidgetCall();
	void returnKB();
	void deleteChar();

	void getValA(QString str);
	void getValB(QString str);
	void getValC(QString str);
	void getValD(QString str);
	void getValE(QString str);
	void getValF(QString str);
	void getValG(QString str);
	void getValH(QString str);
	void getValI(QString str);
	void getValJ(QString str);
	void getValK(QString str);
	void getValL(QString str);
	void getValM(QString str);
	void getValN(QString str);
	void getValO(QString str);
	void getValP(QString str);
	void getValQ(QString str);
	void getValR(QString str);
	void getValS(QString str);
	void getValT(QString str);
	void getValU(QString str);
	void getValV(QString str);
	void getValW(QString str);
	void getValX(QString str);
	void getValY(QString str);
	void getValZ(QString str);
	void getValnum1(QString str);
	void getValnum2(QString str);
	void getValnum3(QString str);
	void getValnum4(QString str);
	void getValnum5(QString str);
	void getValnum6(QString str);
	void getValnum7(QString str);
	void getValnum8(QString str);
	void getValnum9(QString str);
	void getValnum0(QString str);
	void getValspace(QString str);
	void getValcomma(QString str);
	void getValperiod(QString str);


};

#endif // FILEEDITCHILD_H
