#ifndef FILEEDITCHILD_H
#define FILEEDITCHILD_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QFontComboBox>
#include "ClassMessage.h"
#include "OBJ_Type.h"
#include "backend/zint.h"
//#include <QLabel>
//#include <QPushButton>
#include <QTextCharFormat>
#include <QTextEdit>
#include <QLabel>
#include <stdlib.h>


class keyboard;
class numkeyboard;
class language;
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
	ClassMessage m_MessagePrint;
	
	FileManageChild *m_FileMangeChild;
	ModuleMain m_TimeShow;
	ModuleMain* pModuleMain;
	/*enum LineeditChangeEnum{ WordLineedit = 0,barLineEdit = 1,QRLineEdit = 2,DMLineEdit = 3};
	int m_LineeditChange;
	void lineeditChange();*/

	void DrawBackFrame(QPainter *qFramePainter);
	void MouseBeenPressed(QMouseEvent *event);
	void MouseBeenReleased(QMouseEvent *event);
	void MouseMoved(QMouseEvent *event);
	void GetObjSettingsFromScreen();
	void setButtonText(QString strEmpty, QString strNew);
	void Create2Dcode(int nType,QString strContent);
	void CreateQrcode(int nType,QString strContent);
	void CreateDMcode(int nType,QString strContent);
	void ReadBmp(char* strFileName);
	void LoadLocalFile();
	int  GetCharLenFromFont(string txtFont, bool LineOrRow); 
	void PushBackTextOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW);
	void PushBackVecTextOBJ(QString txtFont, QString txtContent, int intFontSize);
	void PushBackBanCiOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW);

	QString getChinese(QString &str);
	void PushBackSerialNumberOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW,int countnumber);
	void ShowText();
	void ChangeTime();
	string TimeFormatToText(QString InPutTimeFormat,int tempstrETimeOffSet, int tempintTimeOffSet, int tempstrTimeOffSetUint);
	
	zint_symbol resetQRCode();
	zint_symbol resetDMCode();
	void GenerateBarCodeBmp();
	
	QString getNum(QString str);//鑾峰彇label鎺т欢鏁板瓧

	void ChangeBmpWH(QImage& pImage,double nS);//鏇存敼鍥剧墖鐨勯暱搴﹀拰瀹藉害
	
	void informationMessage(string errortext);//zint閿欒寮圭獥

	QString bmpFileRelativePath;//璇诲彇bmp鍥剧墖鐨勭浉瀵硅矾寰?
	int degreenum;
	int degreenumQr;
	int degreenumDM;
	float Zoomfactor; 
	float ZoomfactorQr;
	float ZoomfactorDM;
	//bool boolObjBnSel;
 	keyboard  *keyboardWidget;
	language *languageWidget;
	numkeyboard *numkeyboardWidget;
	QString SerialNumber_string;
	int SerialNumber_number;
	int SerialNumber_length;
	int Serialfirst;
	int serialcount;
	int Barheight;
	int nW;
	int nH;
	QPoint pointMousePressed;//璁板綍榧犳爣鐐?
	bool boolMousePressed;//鍒ゆ柇榧犳爣鏄惁琚寜涓?
	bool boolHWchange;//鍒ゆ柇鏀瑰彉鐨勬槸楂樺害杩樻槸瀹藉害

	//Arabic绯诲垪
	QString disposeinputtext( QString inputtext );//闃挎媺浼繛浣?
	QString ConvertWCHARToHex(QString Data, long nDataLength);//QString杞?6杩涘埗
	void W2C(wchar_t w_cn , char c_cn[]);
	QString HexStrToCString(QString HexStr);//16杩涘埗杞琎String
	QString ArabicLan(QString inputstring);
	QVector<QString> Arabicsplit(QString str);
	void ClickChooseLanguage();

	//鐝绯诲垪
	int m_ShiftLineEditType;//褰撳墠鐝鐨勭紪杈戞閫夋嫨

	QString fileName;

	QFontComboBox* FontComboBoxChoose;///高解析环境下[文本]字体下拉框
	QFontComboBox* qTimeFontComboBox;//高解析环境下[时间]字体下拉框
	QFontComboBox* qSerialFontComboBox;//高解析环境下[序列号]字体下拉框
	QFontComboBox* qBanciFontComboBox;//高解析环境下[班次]字体下拉框

	QTextEdit* text;//杩樻湭瀹氫箟鎵�闇�瑕佹敼鍙樼殑瀛椾綋锛屾墍浠ョ偣鍑诲瓧浣撲細鎶ラ敊
	
	QSpinBox* spinBox;//高解析环境下[文本]字号框
	QSpinBox* qTimeSpinBox;//高解析环境下[时间]字号框
	QSpinBox* qSerialSpinBox;//高解析环境下[序列号]字号框
	QSpinBox* qBanciSpinBox;//高解析环境下[班次]字号框
	
	QLabel* qrLabel;
	QSpinBox* qrSpinBox;
	
	//测试：2020-05-16 张玮珺
	QFont m_curVecFont;//当前矢量字体
	//QPixmap pix;//字体位图
	void paintPixMap();

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

	//void ChangeBmpWH(QImage& pImage,double nS);//鏇存敼鍥剧墖鐨勯暱搴﹀拰瀹藉害
	void PreviewBmpChange();
	void OnEnChangeEditInput_clicked();//arabic杩炵瑪

	//void textButton();
	//void changedIndex(int idx);
	void changedFont(const QString &arg1);
	void spinBoxSlot(int FontSize);
	void qrSpinBoxSlot(int spinValue);
	//void ShowSizeSpinBox(QString spinValue);

private slots:
	void variableTextBut_clicked();
	void variableBarCodeBut_clicked();
	void variableQRBut_clicked();
	void variableDMBut_clicked();
	void customTimeBut_clicked();
	void selBmpBut_clicked();
	void delBut_clicked();

	void newTextBut_clicked();
	void newVecTxtBut_clicked();//新建矢量字

	void newBarCodeBut_clicked();
	void newQRBut_clicked();
	void newDMBut_clicked();
	void newSerialNumber_click();
	void SerialNumberstartchange();
	void saveasBut_clicked();
	void saveBut_clicked();
	void internalTextAddBut_clicked();
	void internalTextRedBut_clicked();
	void moveUpBut_clicked();
	void moveDownBut_clicked();
	void moveLeftBut_clicked();
	void moveRightBut_clicked();
	void showNumCheckBox_clicked();
	void heightBarCodeAddBut_clicked();
	void heightBarCodeRedButt_clicked();
	void newBmpBut_clicked();
	void addTimeBut_clicked();
	void concelTimeBut_clicked();
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
	void heightBmpShowBmpLineEdit_clicked();
	void widthShowBmpLineEdit_clicked();

	void ScrollBarChanged(int);
	void tempScrollBarChanged(int);

	void rimwideAddBut_clicked();
	void rimwideRedButt_clicked();
	void whitespaceAddBut_clicked();
	void whitespaceRedButt_clicked();

	void ChangePixel();

	void shiftNumShowLineEdit_clicked();
	void textLenShowLineEdit_clicked();
	void startTimeShowSft1LineEdit_clicked();
	void textIDShowSft1LineEdit_clicked();
	void startTimeShowSft2LineEdit_clicked();
	void textIDShowSft2LineEdit_clicked();
	void startTimeShowSft3LineEdit_clicked();
	void textIDShowSft3LineEdit_clicked();
	void startTimeShowSft4LineEdit_clicked();
	void textIDShowSft4LineEdit_clicked();

	void getCurTime(int leftInt1,int leftInt2,int leftInt3,int leftInt4);
	bool newShiftBut();

protected:
	//void paintEvent(QPaintEvent *event);
	QLabel* viewAreaLabel;
	QScrollBar* tempScrollBar;
	void paintDot();
	void paintFrame();
	bool eventFilter(QObject *watched, QEvent *event);

public:
	void deleteChar();
	void setText2wordLineEdit();
	void setText2shiftNumShowLineEdit();
	void setText2barCodeLineEdit();
	void setText2QRCodeLineEdit();
	void setText2DMCodeLineEdit();

	void PreviewBmp(QString fileNameAAA,int nW,int nH);


	void mergeFormat(QTextCharFormat format);

	//QTimer *m_time;
	int m_hour;
	int m_mint;
	int leftInt1;
	int leftInt2;
	int leftInt3;
	int leftInt4;
	//int rightInt1;
	QString showText1;
	QString showText2;
	QString showText3;
	QString showText4;

public://参数
	double horizon_pos;//滚动条当前位置水平坐标
	double vertical_pos;//滚动条当前位置垂直坐标

};

#endif // FILEEDITCHILD_H
