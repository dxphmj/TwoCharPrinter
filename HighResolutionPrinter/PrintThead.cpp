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


PrintThead::PrintThead(QObject *parent)	: QThread(parent)
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

	//打开驱动


	while (1) 
	{
		if(m_isStop) 
			continue; 

		if(!theApp->m_bPrintNow) 
			continue; 

		//获得光电开关的状态
		#ifdef RUN_BY_DEVICE
			close(m_SynchronizerHande);
	    #endif
		//如果使用光电开关，并且触发了则打印，触发的条件判断是：当前状态与前一个状态不一样（上升沿或下降沿）
        if (theApp->queCtr.size()>0) //将tempQueVec数据发送给相关控制IO
		{
			vector<BYTE> tempQueVec = theApp->queCtr.front();
			theApp->queCtr.pop();
			strTempCmdLen = tempQueVec.size();
			//strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
		}
		else if (theApp->m_MessagePrint->boPrintNow) //打印第一条数据
		{
 			if (theApp->m_MessagePrint->bytPrintDataAllOrder.size() > 11) //将bytPrintDataAllOrder数据发送给喷头驱动IO
			{
			//	strTempCmd=(LPTSTR)VEC2ARRAY(theApp.myclassMessage.bytPrintDataAllOrder,theApp.myclassMessage.bytPrintDataAllOrder.size());
			    strTempCmdLen = theApp->m_MessagePrint->bytPrintDataAllOrder.size();
				theApp->m_MessagePrint->boPrintNow = false;
			}			 
		}
		else if(!theApp->m_MessagePrint->boPrintNow) //打印第二条及后续的数据
		{
			if (theApp->m_MessagePrint->boDynamic) //如果有动态数据，则打印动态数据
			{
				if (theApp->ForPreQue.size()>0)
				{
					vector<BYTE> tempQueVec = theApp->ForPreQue.front();
					theApp->ForPreQue.pop();
					strTempCmdLen = tempQueVec.size();
					//strTempCmd = (LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
					if (strTempCmdLen > 11)
					{
						//动态显示相关										
						theApp->m_MessagePrint->intMesDis = tempQueVec;										 
					} 
					else //发送默认的指令数据
					{
						//strTempCmd=(LPTSTR)readArr;
						//strTempCmdLen=8;
					}
				} 
				else //发送默认的指令数据
				{
					//strTempCmd=(LPTSTR)readArr;
					//strTempCmdLen=8;
				}
			} 
			else //如果没有动态数据则打印静态数据
			{
				if (theApp->m_MessagePrint->bytPrintDataAll.size()>11)
				{
					//strTempCmd = (LPTSTR)VEC2ARRAY(theApp.m_MessageEdit.bytPrintDataAll,theApp.m_MessagePrint.bytPrintDataAll.size());
					strTempCmdLen = theApp->m_MessagePrint->bytPrintDataAll.size();
					if (strTempCmdLen < 12) //发送默认的指令数据
					{
						//strTempCmd=(LPTSTR)readArr;
						//strTempCmdLen=8;
						
					}
					theApp->m_MessagePrint->intMesDis = theApp->m_MessagePrint->bytPrintDataAll;
					theApp->update();
				}
			}
		}
		

		//按照采集的速度进行打印，将每列数据按顺序通过驱动发给IO（或串口输出）
		//为简化控制，每次采用的打印速度不变
		//速度放到主线程MainWindow定时器中进行采集，这里只是采用
			 
	    //将strTempCmd 写入驱动 目前已知：unsigned char可以传字节 0x11 == 00010001  bool a[8]
		//下面的工作在喷头驱动中实现

		//1 开光电开关的终端 读取光电开关下降沿 ，用完后重置
		
		//2 按速度开定时中断，在中断中打印每一列
		 

 		msleep(1);  
	}
}
 