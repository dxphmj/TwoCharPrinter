#include "PrintThead.h"

//#define RUN_BY_DEVICE 

//#ifdef RUN_BY_DEVICE
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

//#endif
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

		//读喷头工作的状态
		//忙 - continue

		//变量，若合格（有空间），执行打印程序；否则，循环

		//获得光电开关的状态
		#ifdef RUN_BY_DEVICE
			close(m_SynchronizerHande);
	    #endif
        if (theApp->queCtr.size()>0) //将tempQueVec数据发送给相关控制IO
		{
			vector<BYTE> tempQueVec = theApp->queCtr.front();
			theApp->queCtr.pop();
			strTempCmdLen = tempQueVec.size();
			//strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
		}
		else if (theApp->m_MessagePrint->boPrintNow) //打印第一条数据
		{
			ModuleMain m_ModuleMain;
 			if (theApp->m_MessagePrint->bytPrintDataAllOrder.size() > 11) //将bytPrintDataAllOrder数据发送给喷头驱动IO
			{
			    //strTempCmd = (LPTSTR) m_ModuleMain.VEC2ARRAY(theApp->m_MessagePrint->bytPrintDataAllOrder,theApp->m_MessagePrint->bytPrintDataAllOrder.size());
			    strTempCmdLen = theApp->m_MessagePrint->bytPrintDataAllOrder.size();
				//strTempCmd = new unsigned short[strTempCmdLen];
				strTempCmd = m_ModuleMain.VEC2ARRAY(theApp->m_MessagePrint->bytPrintDataAllOrder,theApp->m_MessagePrint->bytPrintDataAllOrder.size());

				/*
				unsigned char s0 = strTempCmd[0];
				unsigned char s1 = strTempCmd[1];
				unsigned char s2 = strTempCmd[2];
				unsigned char s3 = strTempCmd[3];
				unsigned char s4 = strTempCmd[4];
				unsigned char s5 = strTempCmd[5];
				unsigned char s6 = strTempCmd[6];
				unsigned char s7 = strTempCmd[7];
				unsigned char s8 = strTempCmd[8];
				unsigned char s9 = strTempCmd[9];
				unsigned char s10 = strTempCmd[10];
				unsigned char s11 = strTempCmd[11];
				*/

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
		
    char iTest[1];
    char *Nozzle_node = "/dev/Nozzle_ctl";

    /*O_RDWR读写打开,O_NDELAY非阻塞方式*/
    if((fd2 = open(Nozzle_node,O_RDWR))<0)
    {
        printf("Nozzle open %s failed",Nozzle_node);
    }
    else
    {
        read_result = read(fd2,iTest,1);
        if(read_result == 0)
        {
            while (1)
			{
				write_result = write(fd2,strTempCmd,8);
				if (write_result)
				{
					free(strTempCmd);
					break;
				}
				/*if(write_result == -1)
				{
					printf("Write is failed!\n");
				}
					else
				{
					printf("Write is success!\n");
				}*/
				msleep(1);
			}
			
        }
        else
        {
            printf("The system is busy now!\n");
        }
       
        //read_result = read(fd2,buffer,1);
    }
    ::close(fd2);


		//按照采集的速度进行打印，将每列数据按顺序通过驱动发给IO（或串口输出）
		//为简化控制，每次采用的打印速度不变
		//速度放到主线程MainWindow定时器中进行采集，这里只是采用
			 
	    //将strTempCmd 写入驱动，char， byte，strTempCmdLen, 可能包含 打印速度 V
		//下面的工作在喷头驱动中实现
		//write(fd,strTempCmd,strTempCmdLen);
		
		//如果使用光电开关，并且触发了则打印，触发的条件判断是：当前状态与前一个状态不一样（上升沿或下降沿）
		//1 开光电开关的终端 读取光电开关下降沿 ，用完后重置
		
		//2 按速度开定时中断，在中断中打印每一列
		 

 		msleep(1);  
	}
}

/*
  write() 
  {
	   1） 通过 write() 接受数据
	   2）计算出打印速度定时时间
	   3） 开光电开关中断，监测下降沿
   }

   在光电开关的中断处理函数中 开定时中断；
   在定时中断处理函数中根据当前打印列写端口。
*/
 