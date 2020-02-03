#include "PrintThead.h"

//#define RUN_BY_DEVICE 

#ifdef RUN_BY_DEVICE
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#endif
#include "mainwindow.h"
#include "ClassMessage.h"


PrintThead::PrintThead(QObject *parent)
	: QThread(parent)
{
 	m_isStop = false;

	m_bUsingPhotoESwitch = true;
	m_bTriggerByHigh = false;
	m_bPhotoESwitchState = false;
	m_bPhotoESwitchStatePre = false;
	m_bTrigger = false;
	m_bUsingSynchronizer = true;

	#ifdef RUN_BY_DEVICE
		//如果使用光电开关则打开相应的设备
		//如果使用同步器则打开相应的设备
	    //硬件设备集中做成一个驱动程序，包括压力控制器，光电开关，同步器及喷头驱动IO等

		char gpio[MAX],cmd[MAX];
		char *leds = "/dev/leds";
		LedOnOffTimes = MAX;
		 
		if((m_SynchronizerHande = open(leds, O_RDWR|O_NOCTTY|O_NDELAY))<0)
			printf("open %s failed\n",leds);   
		else
    		printf("open %s success\r\n",leds);	

	#endif



}

PrintThead::~PrintThead()
{
	#ifdef RUN_BY_DEVICE
		close(m_SynchronizerHande);
	#endif

}

void PrintThead::closeThread()
{    
	m_isStop = true;
} 

void PrintThead::run()
{    
	int strTempCmdLen = 0;
	MainWindow* theApp = (MainWindow*)(this->parent());

	while (1) 
	{       
		if(m_isStop) 
			return; 
		//获得光电开关的状态
		#ifdef RUN_BY_DEVICE
			close(m_SynchronizerHande);
	    #endif
		//如果使用光电开关，并且触发了则打印，触发的条件判断是：当前状态与前一个状态不一样
        if (theApp->queCtr.size()>0) //将tempQueVec数据发送给相关控制IO
		{
			vector<BYTE> tempQueVec = theApp->queCtr.front();
			theApp->queCtr.pop();
			strTempCmdLen = tempQueVec.size();
			//strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
		}
		else if (theApp->m_bPrintNow)
		{
			//theApp.boPrintNowLock.Lock();
			if (theApp->m_PrinterMes->bytPrintDataAllOrder.size() > 11) //将bytPrintDataAllOrder数据发送给喷头驱动IO
			{
			//	strTempCmd=(LPTSTR)VEC2ARRAY(theApp.myclassMessage.bytPrintDataAllOrder,theApp.myclassMessage.bytPrintDataAllOrder.size());
			    strTempCmdLen = theApp->m_PrinterMes->bytPrintDataAllOrder.size();
			 	theApp->m_bPrintNow = false;
			} 
			 
			//theApp.boPrintNowLock.Unlock();
		}
		//else if (!theApp->m_bPrintNow) //
		//{					 
		//	if (theApp->m_bDynamicPrint)
		//	{
		//		if (theApp->ForPreQue.size()>0)
		//		{
		//			vector<BYTE> tempQueVec = theApp->ForPreQue.front();
		//			theApp->ForPreQue.pop();
		//			strTempCmdLen = tempQueVec.size();
		//		}
		//	}
		//}

 		sleep(1);  
	}
}
 