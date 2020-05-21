#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QQueue>
 
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <QMutex>

#include "ParamSetting.h"

#define BIG_CHAR
#define vsPath     //vs上的点阵字库、多语言字库路径
//#define qtPath   //ubuntu上的点阵字库、多语言字库路径

using namespace std;
typedef unsigned char BYTE;

class FilemanageForm;
class FileEditChild;
class ParamSettingForm;
class ClassMessage;
class PrintThead;
class PrintShowThread;
class PrintCreatThread;
class roll;

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
 	ClassMessage* m_MessagePrint; //打印监控用
    queue<vector<BYTE> > queCtr;//命令队列 
	queue<vector<BYTE> > ForPreQue;//欲打印队列
	CParamSetting m_ParamSetting;
	bool mythreadDynamicBoo;//动态线程开关
	bool boDrawMainPic;//主界面动态绘制开关
	bool m_bPrintNow;
	bool m_bDynamicPrint;

	QMutex boPrintNowLock;

	void RefreshWindow();
	void getSerialTimeDotBuf();
public:
    Ui::MainWindow *ui;
	FilemanageForm *m_fileManage;
	ParamSettingForm *m_paramsetting;

	void DownloadPrintData();
	void CreatePrintData();
	void getMessageDot();

private slots:
	void fileManageBut_clicked();
	void paraManageBut_clicked();
	void closeBut_clicked();
	void PrintBut_clicked();

	bool eventFilter(QObject *watched, QEvent *event);

	void GetDateTime();
public:
	QTimer  *myTimer;
	PrintThead *m_pPrintThread;
	PrintCreatThread *m_pPrintCreateThread;
	PrintShowThread *m_pPrintShowThread;
};

#endif // MAINWINDOW_H
