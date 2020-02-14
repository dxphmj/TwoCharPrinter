#ifndef FILEEDITCHILD_H
#define FILEEDITCHILD_H

#include <QWidget>
#include <QLineEdit>
#include "ClassMessage.h"

class keyboard;
class numkeyboard;
class FileManageChild;
#include "ModuleMain.h"
namespace Ui {
	class FileEditChild;
}

class FileEditChild : public QWidget
{
	Q_OBJECT

public:
	FileEditChild(QWidget *parent = 0);
	~FileEditChild();
	ClassMessage m_PrinterMes;
	FileManageChild *m_FileMangeChild;
	ModuleMain m_TimeShow;

	/*enum LineeditChangeEnum{ WordLineedit = 0,barLineEdit = 1,QRLineEdit = 2,DMLineEdit = 3};
	int m_LineeditChange;
	void lineeditChange();*/

	void DrawBackFrame(QPainter *qFramePainter);
	void MouseBeenReleased(QMouseEvent *event);
	void MouseMoved(QMouseEvent *event);
	void GetObjSettingsFromScreen();
	void Create2Dcode(int nType,QString strContent);
	void CreateQrcode(int nType,QString strContent);
	void CreateDMcode(int nType,QString strContent);
	void ReadBmp(char* strFileName);
	void LoadLocalFile();
	int  GetCharLenFromFont(string txtFont, bool LineOrRow); //根据字体，计算得到每个字符的显示长度
	void PushBackTextOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW);
	void ShowText();
	void ChangeTime();
	string TimeFormatToText(QString InPutTimeFormat,int tempstrETimeOffSet, int tempintTimeOffSet, int tempstrTimeOffSetUint);
	
	QString bmpFileRelativePath;//读取bmp图片的相对路径
	int degreenum;
	int degreenumQr;
	int degreenumDM;
	float Zoomfactor; 
	float ZoomfactorQr;
	float ZoomfactorDM;
	//bool boolObjBnSel;
 	keyboard  *keyboardWidget;
	numkeyboard *numkeyboardWidget;
	QString SerialNumber_2;
	int SerialNumber;
	int SerialNumber_length;
	int drawback;//首次撤回的判定
	int drawback_time;
	int Barheight;
	QPoint pointMousePressed;//记录鼠标点
	bool boolMousePressed;//判断鼠标是否被按下

public:
	Ui::FileEditChild* ui;
	
	QString str1;
public slots:
	void wordLineEdit_clicked();
	void barCodeLineEdit_clicked();
	void QRCodeLineEdit_clicked();
	void DMCodeLineEdit_clicked();
	void ChangeTabLineEdit();
	/*void ChineseTabLineEdit();*/
	void KeyboardConceal_clicked();
private slots:
	void variableTextBut_clicked();
	void variableBarCodeBut_clicked();
	void variableQRBut_clicked();
	void variableDMBut_clicked();
	void customTimeBut_clicked();
	void selBmpBut_clicked();
	void delBut_clicked();

	void newTextBut_clicked();
	void newBarCodeBut_clicked();
	void newQRBut_clicked();
	void newDMBut_clicked();
	void newSerialNumber_click();
	void saveasBut_clicked();
	void saveBut_clicked();
	void internalTextAddBut_clicked();
	void internalTextRedBut_clicked();
	void moveUpBut_clicked();
	void moveDownBut_clicked();
	void moveLeftBut_clicked();
	void moveRightBut_clicked();
	void showNumCheckBox_clicked();
	//void degreeBarCodeAddBut_clicked();
	//void degreeBarCodeRedButt_clicked();
	void heightBarCodeAddBut_clicked();
	void heightBarCodeRedButt_clicked();
	//void degreeQRAddBut_clicked();
	//void degreeQRRedButt_clicked();
	//void degreeDMAddBut_clicked();
	//void degreeDMRedButt_clicked();

	void newBmpBut_clicked();

	//void zoomBarCodeAddBut_clicked();
	//void zoomBarCodeRedBut_clicked();
	//void zoomQRAddBut_clicked();
	//void zoomQRRedBut_clicked();
	//void zoomDMAddBut_clicked();
	//void zoomDMRedBut_clicked();
	void addTimeBut_clicked();
	void SkewComBox_clicked();
	void refreshTimeBut_clicked();
	void newTimeBut_clicked();

	void SkewSkewValueEdit_clicked();
	void initialValSerialLineEdit_clicked();
	void termValSerialLineEdit_clicked();
	void startValSerialLineEdit_clicked();
	void stepLenSerialLineEdit_clicked();
	void reptCountSerialLineEdit_clicked();
	void digitSerialLineEdit_clicked();
	void ScrollBarChanged(int);
	void rimwideAddBut_clicked();
	void rimwideRedButt_clicked();
	void whitespaceAddBut_clicked();
	void whitespaceRedButt_clicked();
	void initialSerialBut_clicked();
	void withdrawSerialBut_clciked();

	void ChangePixel();

protected:
	//void paintEvent(QPaintEvent *event);
	void paintDot();
	bool eventFilter(QObject *watched, QEvent *event);

public:
	void deleteChar();
	void setText2wordLineEdit();
	void setText2barCodeLineEdit();
	void setText2QRCodeLineEdit();
	void setText2DMCodeLineEdit();

};

#endif // FILEEDITCHILD_H
