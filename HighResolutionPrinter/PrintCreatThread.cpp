#include "PrintCreatThread.h"
#include "mainwindow.h"
#include "ClassMessage.h"

PrintCreatThread::PrintCreatThread(QObject *parent)
	: QThread(parent)
{

}

PrintCreatThread::~PrintCreatThread()
{

} 
void PrintCreatThread::run() //提前生产两个欲打印的内容放入ForPreQue队列中
{    
	int strTempCmdLen = 0;
	MainWindow* theApp = (MainWindow*)(this->parent());

	while(theApp->mythreadDynamicBoo)	 
	{
		if(theApp->ForPreQue.size() >= 2)
		{
			sleep(100);
			continue;
		}
		//getSerialTimeDotBuf();//修改bytPrintDataAll中相应的字节数据

		theApp->boPrintNowLock.lock();
			theApp->ForPreQue.push(theApp->m_MessagePrint->bytPrintDataAll);				
		theApp->boPrintNowLock.unlock();	
	} 
}
 