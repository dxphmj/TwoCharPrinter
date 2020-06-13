#include "PrintShowThread.h"
#include "mainwindow.h"
#include "ClassMessage.h"

PrintShowThread::PrintShowThread(QObject *parent)
	: QThread(parent)
{

}

PrintShowThread::~PrintShowThread()
{
	//char c[20];
	//BYTE d;

	////10�У�20���ֽ�  

	//int nPrintCurCol;
	//for(int i = 0; i < 16; i++)  //0001 0001 ,0x01 = 0000 0001
	//{
	//	if(i < 8)
	//		bool bBit = (c[nPrintCurCol*2] >> i & 0x01);
	//	else
	//		bool bBit = (c[nPrintCurCol*2+1] >> (i-8) & 0x01);
	//}
}

void PrintShowThread::run()
{    
	int strTempCmdLen = 0;
	MainWindow* theApp = (MainWindow*)(this->parent());

	//如动态打印则动态显示，下面的逻辑还需优化

	int pixSize = 4; 
	
	while(theApp->mythreadDynamicBoo)//动态线程开�?
	{
		while(theApp->boDrawMainPic)//主界面动态绘制开�?
		{
			//if(theApp->ForPreQue.size() >= 2)///////以后删掉
			//{
			//	theApp->m_MessagePrint->intMesDis = theApp->ForPreQue.front();;
			//	theApp->ForPreQue.pop();
			//}

			//theApp->m_MessagePrint->DrawAllDynamic(theApp->m_painter);	
			theApp->update();
			msleep(800);
		}
	}
}
 