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

	initPrinter();
	//打开串口
//	OpenCom();
    //连接信号和槽
 //   QObject::connect(&serial, &QSerialPort::readyRead, this, &PrintThead::serialPort_readyRead);
}

PrintThead::~PrintThead()
{
	#ifdef RUN_BY_DEVICE
		close(m_SynchronizerHande);
	#endif

}

void PrintThead::initPrinter()
{ 
    m_StructRowCol[1].m_nCOl = 1; m_StructRowCol[1].m_nRow = 1;
	m_StructRowCol[2].m_nCOl = 2; m_StructRowCol[2].m_nRow = 9;
	m_StructRowCol[3].m_nCOl = 1; m_StructRowCol[3].m_nRow = 16;
	m_StructRowCol[4].m_nCOl = 2; m_StructRowCol[4].m_nRow = 2;
	m_StructRowCol[5].m_nCOl = 1; m_StructRowCol[5].m_nRow = 9;
	m_StructRowCol[6].m_nCOl = 2; m_StructRowCol[6].m_nRow = 17;
	m_StructRowCol[7].m_nCOl = 1; m_StructRowCol[7].m_nRow = 2;
	m_StructRowCol[8].m_nCOl = 2; m_StructRowCol[8].m_nRow = 10;
	m_StructRowCol[9].m_nCOl = 1; m_StructRowCol[9].m_nRow = 17;
	m_StructRowCol[10].m_nCOl = 2; m_StructRowCol[10].m_nRow = 3;
	m_StructRowCol[11].m_nCOl = 1; m_StructRowCol[11].m_nRow = 10;
	m_StructRowCol[12].m_nCOl = 2; m_StructRowCol[12].m_nRow = 18;
	m_StructRowCol[13].m_nCOl = 1; m_StructRowCol[13].m_nRow = 3;
	m_StructRowCol[14].m_nCOl = 2; m_StructRowCol[14].m_nRow = 11;
	m_StructRowCol[15].m_nCOl = 1; m_StructRowCol[15].m_nRow = 18;
	m_StructRowCol[16].m_nCOl = 2; m_StructRowCol[16].m_nRow = 4;
	m_StructRowCol[17].m_nCOl = 1; m_StructRowCol[17].m_nRow = 11;
	m_StructRowCol[18].m_nCOl = 2; m_StructRowCol[18].m_nRow = 19;
	m_StructRowCol[19].m_nCOl = 1; m_StructRowCol[19].m_nRow = 4;
	m_StructRowCol[20].m_nCOl = 2; m_StructRowCol[20].m_nRow = 12;
	m_StructRowCol[21].m_nCOl = 1; m_StructRowCol[21].m_nRow = 19;
	m_StructRowCol[22].m_nCOl = 2; m_StructRowCol[22].m_nRow = 5;
	m_StructRowCol[23].m_nCOl = 1; m_StructRowCol[23].m_nRow = 12;
	m_StructRowCol[24].m_nCOl = 2; m_StructRowCol[24].m_nRow = 20;
	m_StructRowCol[25].m_nCOl = 1; m_StructRowCol[25].m_nRow = 5;
	m_StructRowCol[26].m_nCOl = 2; m_StructRowCol[26].m_nRow = 13;
	m_StructRowCol[27].m_nCOl = 1; m_StructRowCol[27].m_nRow = 20;
	m_StructRowCol[28].m_nCOl = 2; m_StructRowCol[28].m_nRow = 6;
	m_StructRowCol[29].m_nCOl = 1; m_StructRowCol[29].m_nRow = 13;
	m_StructRowCol[30].m_nCOl = 2; m_StructRowCol[30].m_nRow = 21;
	m_StructRowCol[31].m_nCOl = 1; m_StructRowCol[31].m_nRow = 6;
	m_StructRowCol[32].m_nCOl = 2; m_StructRowCol[32].m_nRow = 14;
	m_StructRowCol[33].m_nCOl = 1; m_StructRowCol[33].m_nRow = 21;
	m_StructRowCol[34].m_nCOl = 2; m_StructRowCol[34].m_nRow = 7;
	m_StructRowCol[35].m_nCOl = 1; m_StructRowCol[35].m_nRow = 14;
	m_StructRowCol[36].m_nCOl = 2; m_StructRowCol[36].m_nRow = 22;
	m_StructRowCol[37].m_nCOl = 1; m_StructRowCol[37].m_nRow = 7;
	m_StructRowCol[38].m_nCOl = 2; m_StructRowCol[38].m_nRow = 15;
	m_StructRowCol[39].m_nCOl = 1; m_StructRowCol[39].m_nRow = 22;
	m_StructRowCol[40].m_nCOl = 2; m_StructRowCol[40].m_nRow = 8;
	m_StructRowCol[41].m_nCOl = 3; m_StructRowCol[41].m_nRow = 15;
	m_StructRowCol[42].m_nCOl = 4; m_StructRowCol[42].m_nRow = 1;
	m_StructRowCol[43].m_nCOl = 3; m_StructRowCol[43].m_nRow = 8;
	m_StructRowCol[44].m_nCOl = 4; m_StructRowCol[44].m_nRow = 16;
	m_StructRowCol[45].m_nCOl = 3; m_StructRowCol[45].m_nRow = 1;
	m_StructRowCol[46].m_nCOl = 4; m_StructRowCol[46].m_nRow = 9;
	m_StructRowCol[47].m_nCOl = 3; m_StructRowCol[47].m_nRow = 16;
	m_StructRowCol[48].m_nCOl = 4; m_StructRowCol[48].m_nRow = 2;
	m_StructRowCol[49].m_nCOl = 3; m_StructRowCol[49].m_nRow = 9;
	m_StructRowCol[50].m_nCOl = 4; m_StructRowCol[50].m_nRow = 17;
	m_StructRowCol[51].m_nCOl = 3; m_StructRowCol[51].m_nRow = 2;
	m_StructRowCol[52].m_nCOl = 4; m_StructRowCol[52].m_nRow = 10;
	m_StructRowCol[53].m_nCOl = 3; m_StructRowCol[53].m_nRow = 17;
	m_StructRowCol[54].m_nCOl = 4; m_StructRowCol[54].m_nRow = 3;
	m_StructRowCol[55].m_nCOl = 3; m_StructRowCol[55].m_nRow = 10;
	m_StructRowCol[56].m_nCOl = 4; m_StructRowCol[56].m_nRow = 18;
	m_StructRowCol[57].m_nCOl = 3; m_StructRowCol[57].m_nRow = 3;
	m_StructRowCol[58].m_nCOl = 4; m_StructRowCol[58].m_nRow = 11;
	m_StructRowCol[59].m_nCOl = 3; m_StructRowCol[59].m_nRow = 18;
	m_StructRowCol[60].m_nCOl = 4; m_StructRowCol[60].m_nRow = 4;
	m_StructRowCol[61].m_nCOl = 3; m_StructRowCol[61].m_nRow = 11;
	m_StructRowCol[62].m_nCOl = 4; m_StructRowCol[62].m_nRow = 19;
	m_StructRowCol[63].m_nCOl = 3; m_StructRowCol[63].m_nRow = 4;
	m_StructRowCol[64].m_nCOl = 4; m_StructRowCol[64].m_nRow = 12;
	m_StructRowCol[65].m_nCOl = 3; m_StructRowCol[65].m_nRow = 19;
	m_StructRowCol[66].m_nCOl = 4; m_StructRowCol[66].m_nRow = 5;
	m_StructRowCol[67].m_nCOl = 3; m_StructRowCol[67].m_nRow = 12;
	m_StructRowCol[68].m_nCOl = 4; m_StructRowCol[68].m_nRow = 20;
	m_StructRowCol[69].m_nCOl = 3; m_StructRowCol[69].m_nRow = 5;
	m_StructRowCol[70].m_nCOl = 4; m_StructRowCol[70].m_nRow = 13;
	m_StructRowCol[71].m_nCOl = 3; m_StructRowCol[71].m_nRow = 20;
	m_StructRowCol[72].m_nCOl = 4; m_StructRowCol[72].m_nRow = 6;
	m_StructRowCol[73].m_nCOl = 3; m_StructRowCol[73].m_nRow = 13;
	m_StructRowCol[74].m_nCOl = 4; m_StructRowCol[74].m_nRow = 21;
	m_StructRowCol[75].m_nCOl = 3; m_StructRowCol[75].m_nRow = 6;
	m_StructRowCol[76].m_nCOl = 4; m_StructRowCol[76].m_nRow = 14;
	m_StructRowCol[77].m_nCOl = 3; m_StructRowCol[77].m_nRow = 21;
	m_StructRowCol[78].m_nCOl = 4; m_StructRowCol[78].m_nRow = 7;
	m_StructRowCol[79].m_nCOl = 3; m_StructRowCol[79].m_nRow = 14;
	m_StructRowCol[80].m_nCOl = 4; m_StructRowCol[80].m_nRow = 22;
	m_StructRowCol[81].m_nCOl = 3; m_StructRowCol[81].m_nRow = 7;
	m_StructRowCol[82].m_nCOl = 4; m_StructRowCol[82].m_nRow = 15;
	m_StructRowCol[83].m_nCOl = 3; m_StructRowCol[83].m_nRow = 22;
	m_StructRowCol[84].m_nCOl = 4; m_StructRowCol[84].m_nRow = 8;
	m_StructRowCol[85].m_nCOl = 5; m_StructRowCol[85].m_nRow = 15;
	m_StructRowCol[86].m_nCOl = 6; m_StructRowCol[86].m_nRow = 1;
	m_StructRowCol[87].m_nCOl = 5; m_StructRowCol[87].m_nRow = 8;
	m_StructRowCol[88].m_nCOl = 6; m_StructRowCol[88].m_nRow = 16;
	m_StructRowCol[89].m_nCOl = 5; m_StructRowCol[89].m_nRow = 1;
	m_StructRowCol[90].m_nCOl = 6; m_StructRowCol[90].m_nRow = 9;
	m_StructRowCol[91].m_nCOl = 5; m_StructRowCol[91].m_nRow = 16;
	m_StructRowCol[92].m_nCOl = 6; m_StructRowCol[92].m_nRow = 2;
	m_StructRowCol[93].m_nCOl = 5; m_StructRowCol[93].m_nRow = 9;
	m_StructRowCol[94].m_nCOl = 6; m_StructRowCol[94].m_nRow = 17;
	m_StructRowCol[95].m_nCOl = 5; m_StructRowCol[95].m_nRow = 2;
	m_StructRowCol[96].m_nCOl = 6; m_StructRowCol[96].m_nRow = 10;
	m_StructRowCol[97].m_nCOl = 5; m_StructRowCol[97].m_nRow = 17;
	m_StructRowCol[98].m_nCOl = 6; m_StructRowCol[98].m_nRow = 3;
	m_StructRowCol[99].m_nCOl = 5; m_StructRowCol[99].m_nRow = 10;
	m_StructRowCol[100].m_nCOl = 6; m_StructRowCol[100].m_nRow = 18;
	m_StructRowCol[101].m_nCOl = 5; m_StructRowCol[101].m_nRow = 3;
	m_StructRowCol[102].m_nCOl = 6; m_StructRowCol[102].m_nRow = 11;
	m_StructRowCol[103].m_nCOl = 5; m_StructRowCol[103].m_nRow = 18;
	m_StructRowCol[104].m_nCOl = 6; m_StructRowCol[104].m_nRow = 4;
	m_StructRowCol[105].m_nCOl = 5; m_StructRowCol[105].m_nRow = 11;
	m_StructRowCol[106].m_nCOl = 6; m_StructRowCol[106].m_nRow = 19;
	m_StructRowCol[107].m_nCOl = 5; m_StructRowCol[107].m_nRow = 4;
	m_StructRowCol[108].m_nCOl = 6; m_StructRowCol[108].m_nRow = 12;
	m_StructRowCol[109].m_nCOl = 5; m_StructRowCol[109].m_nRow = 19;
	m_StructRowCol[110].m_nCOl = 6; m_StructRowCol[110].m_nRow = 5;
	m_StructRowCol[111].m_nCOl = 5; m_StructRowCol[111].m_nRow = 12;
	m_StructRowCol[112].m_nCOl = 6; m_StructRowCol[112].m_nRow = 20;
	m_StructRowCol[113].m_nCOl = 5; m_StructRowCol[113].m_nRow = 5;
	m_StructRowCol[114].m_nCOl = 6; m_StructRowCol[114].m_nRow = 13;
	m_StructRowCol[115].m_nCOl = 5; m_StructRowCol[115].m_nRow = 20;
	m_StructRowCol[116].m_nCOl = 6; m_StructRowCol[116].m_nRow = 6;
	m_StructRowCol[117].m_nCOl = 5; m_StructRowCol[117].m_nRow = 13;
	m_StructRowCol[118].m_nCOl = 6; m_StructRowCol[118].m_nRow = 21;
	m_StructRowCol[119].m_nCOl = 5; m_StructRowCol[119].m_nRow = 6;
	m_StructRowCol[120].m_nCOl = 6; m_StructRowCol[120].m_nRow = 14;
	m_StructRowCol[121].m_nCOl = 5; m_StructRowCol[121].m_nRow = 21;
	m_StructRowCol[122].m_nCOl = 6; m_StructRowCol[122].m_nRow = 7;
	m_StructRowCol[123].m_nCOl = 5; m_StructRowCol[123].m_nRow = 14;
	m_StructRowCol[124].m_nCOl = 6; m_StructRowCol[124].m_nRow = 22;
	m_StructRowCol[125].m_nCOl = 5; m_StructRowCol[125].m_nRow = 7;
	m_StructRowCol[126].m_nCOl = 6; m_StructRowCol[126].m_nRow = 15;
	m_StructRowCol[127].m_nCOl = 5; m_StructRowCol[127].m_nRow = 22;
	m_StructRowCol[128].m_nCOl = 6; m_StructRowCol[128].m_nRow = 8;
	m_StructRowCol[129].m_nCOl = 7; m_StructRowCol[129].m_nRow = 15;
	m_StructRowCol[130].m_nCOl = 8; m_StructRowCol[130].m_nRow = 1;
	m_StructRowCol[131].m_nCOl = 7; m_StructRowCol[131].m_nRow = 8;
	m_StructRowCol[132].m_nCOl = 8; m_StructRowCol[132].m_nRow = 16;
	m_StructRowCol[133].m_nCOl = 7; m_StructRowCol[133].m_nRow = 1;
	m_StructRowCol[134].m_nCOl = 8; m_StructRowCol[134].m_nRow = 9;
	m_StructRowCol[135].m_nCOl = 7; m_StructRowCol[135].m_nRow = 16;
	m_StructRowCol[136].m_nCOl = 8; m_StructRowCol[136].m_nRow = 2;
	m_StructRowCol[137].m_nCOl = 7; m_StructRowCol[137].m_nRow = 9;
	m_StructRowCol[138].m_nCOl = 8; m_StructRowCol[138].m_nRow = 17;
	m_StructRowCol[139].m_nCOl = 7; m_StructRowCol[139].m_nRow = 2;
	m_StructRowCol[140].m_nCOl = 8; m_StructRowCol[140].m_nRow = 10;
	m_StructRowCol[141].m_nCOl = 7; m_StructRowCol[141].m_nRow = 17;
	m_StructRowCol[142].m_nCOl = 8; m_StructRowCol[142].m_nRow = 3;
	m_StructRowCol[143].m_nCOl = 7; m_StructRowCol[143].m_nRow = 10;
	m_StructRowCol[144].m_nCOl = 8; m_StructRowCol[144].m_nRow = 18;
	m_StructRowCol[145].m_nCOl = 7; m_StructRowCol[145].m_nRow = 3;
	m_StructRowCol[146].m_nCOl = 8; m_StructRowCol[146].m_nRow = 11;
	m_StructRowCol[147].m_nCOl = 7; m_StructRowCol[147].m_nRow = 18;
	m_StructRowCol[148].m_nCOl = 8; m_StructRowCol[148].m_nRow = 4;
	m_StructRowCol[149].m_nCOl = 7; m_StructRowCol[149].m_nRow = 11;
	m_StructRowCol[150].m_nCOl = 8; m_StructRowCol[150].m_nRow = 19;
	m_StructRowCol[151].m_nCOl = 7; m_StructRowCol[151].m_nRow = 4;
	m_StructRowCol[152].m_nCOl = 8; m_StructRowCol[152].m_nRow = 12;
	m_StructRowCol[153].m_nCOl = 7; m_StructRowCol[153].m_nRow = 19;
	m_StructRowCol[154].m_nCOl = 8; m_StructRowCol[154].m_nRow = 5;
	m_StructRowCol[155].m_nCOl = 7; m_StructRowCol[155].m_nRow = 12;
	m_StructRowCol[156].m_nCOl = 8; m_StructRowCol[156].m_nRow = 20;
	m_StructRowCol[157].m_nCOl = 7; m_StructRowCol[157].m_nRow = 5;
	m_StructRowCol[158].m_nCOl = 8; m_StructRowCol[158].m_nRow = 13;
	m_StructRowCol[159].m_nCOl = 7; m_StructRowCol[159].m_nRow = 20;
	m_StructRowCol[160].m_nCOl = 8; m_StructRowCol[160].m_nRow = 6;
	m_StructRowCol[161].m_nCOl = 7; m_StructRowCol[161].m_nRow = 13;
	m_StructRowCol[162].m_nCOl = 8; m_StructRowCol[162].m_nRow = 21;
	m_StructRowCol[163].m_nCOl = 7; m_StructRowCol[163].m_nRow = 6;
	m_StructRowCol[164].m_nCOl = 8; m_StructRowCol[164].m_nRow = 14;
	m_StructRowCol[165].m_nCOl = 7; m_StructRowCol[165].m_nRow = 21;
	m_StructRowCol[166].m_nCOl = 8; m_StructRowCol[166].m_nRow = 7;
	m_StructRowCol[167].m_nCOl = 7; m_StructRowCol[167].m_nRow = 14;
	m_StructRowCol[168].m_nCOl = 8; m_StructRowCol[168].m_nRow = 22;
	m_StructRowCol[169].m_nCOl = 7; m_StructRowCol[169].m_nRow = 7;
	m_StructRowCol[170].m_nCOl = 8; m_StructRowCol[170].m_nRow = 15;
	m_StructRowCol[171].m_nCOl = 7; m_StructRowCol[171].m_nRow = 22;
	m_StructRowCol[172].m_nCOl = 8; m_StructRowCol[172].m_nRow = 8;
	m_StructRowCol[173].m_nCOl = 9 ; m_StructRowCol[173].m_nRow = 15;
	m_StructRowCol[174].m_nCOl = 10; m_StructRowCol[174].m_nRow = 1;
	m_StructRowCol[175].m_nCOl = 9 ; m_StructRowCol[175].m_nRow = 8;
	m_StructRowCol[176].m_nCOl = 10; m_StructRowCol[176].m_nRow = 16;
	m_StructRowCol[177].m_nCOl = 9 ; m_StructRowCol[177].m_nRow = 9;
	m_StructRowCol[178].m_nCOl = 10; m_StructRowCol[178].m_nRow = 16;
	m_StructRowCol[179].m_nCOl = 9 ; m_StructRowCol[179].m_nRow = 2;
	m_StructRowCol[180].m_nCOl = 10; m_StructRowCol[180].m_nRow = 9;
	m_StructRowCol[181].m_nCOl = 9 ; m_StructRowCol[181].m_nRow = 9;
	m_StructRowCol[182].m_nCOl = 10; m_StructRowCol[182].m_nRow = 17;
	m_StructRowCol[183].m_nCOl = 9 ; m_StructRowCol[183].m_nRow = 2;
	m_StructRowCol[184].m_nCOl = 10; m_StructRowCol[184].m_nRow = 10;
	m_StructRowCol[185].m_nCOl = 9 ; m_StructRowCol[185].m_nRow = 17;
	m_StructRowCol[186].m_nCOl = 10; m_StructRowCol[186].m_nRow = 3;
	m_StructRowCol[187].m_nCOl = 9 ; m_StructRowCol[187].m_nRow = 10;
	m_StructRowCol[188].m_nCOl = 10; m_StructRowCol[188].m_nRow = 18;
	m_StructRowCol[189].m_nCOl = 9 ; m_StructRowCol[189].m_nRow = 3;
	m_StructRowCol[190].m_nCOl = 10; m_StructRowCol[190].m_nRow = 11;
	m_StructRowCol[191].m_nCOl = 9 ; m_StructRowCol[191].m_nRow = 18;
	m_StructRowCol[192].m_nCOl = 10; m_StructRowCol[192].m_nRow = 4;
	m_StructRowCol[193].m_nCOl = 9 ; m_StructRowCol[193].m_nRow = 11;
	m_StructRowCol[194].m_nCOl = 10; m_StructRowCol[194].m_nRow = 19;
	m_StructRowCol[195].m_nCOl = 9 ; m_StructRowCol[195].m_nRow = 4;
	m_StructRowCol[196].m_nCOl = 10; m_StructRowCol[196].m_nRow = 12;
	m_StructRowCol[197].m_nCOl = 9 ; m_StructRowCol[197].m_nRow = 19;
	m_StructRowCol[198].m_nCOl = 10; m_StructRowCol[198].m_nRow = 5;
	m_StructRowCol[199].m_nCOl = 9 ; m_StructRowCol[199].m_nRow = 12;
	m_StructRowCol[200].m_nCOl = 10; m_StructRowCol[200].m_nRow = 20;
	m_StructRowCol[201].m_nCOl = 9 ; m_StructRowCol[201].m_nRow = 5;
	m_StructRowCol[202].m_nCOl = 10; m_StructRowCol[202].m_nRow = 13;
	m_StructRowCol[203].m_nCOl = 9 ; m_StructRowCol[203].m_nRow = 20;
	m_StructRowCol[204].m_nCOl = 10; m_StructRowCol[204].m_nRow = 6;
	m_StructRowCol[205].m_nCOl = 9 ; m_StructRowCol[205].m_nRow = 13;
	m_StructRowCol[206].m_nCOl = 10; m_StructRowCol[206].m_nRow = 21;
	m_StructRowCol[207].m_nCOl = 9 ; m_StructRowCol[207].m_nRow = 6;
	m_StructRowCol[208].m_nCOl = 10; m_StructRowCol[208].m_nRow = 14;
	m_StructRowCol[209].m_nCOl = 9 ; m_StructRowCol[209].m_nRow = 21;
	m_StructRowCol[210].m_nCOl = 10; m_StructRowCol[210].m_nRow = 7;
	m_StructRowCol[211].m_nCOl = 9 ; m_StructRowCol[211].m_nRow = 14;
	m_StructRowCol[212].m_nCOl = 10; m_StructRowCol[212].m_nRow = 22;
	m_StructRowCol[213].m_nCOl = 9 ; m_StructRowCol[213].m_nRow = 7;
	m_StructRowCol[214].m_nCOl = 10; m_StructRowCol[214].m_nRow = 15;
	m_StructRowCol[215].m_nCOl = 9 ; m_StructRowCol[215].m_nRow = 22;
	m_StructRowCol[216].m_nCOl = 10; m_StructRowCol[216].m_nRow = 8;
	m_StructRowCol[217].m_nCOl = 11; m_StructRowCol[217].m_nRow = 15;
	m_StructRowCol[218].m_nCOl = 12; m_StructRowCol[218].m_nRow = 1;
	m_StructRowCol[219].m_nCOl = 11; m_StructRowCol[219].m_nRow = 8;
	m_StructRowCol[220].m_nCOl = 12; m_StructRowCol[220].m_nRow = 16;
	m_StructRowCol[221].m_nCOl = 11; m_StructRowCol[221].m_nRow = 1;
	m_StructRowCol[222].m_nCOl = 12; m_StructRowCol[222].m_nRow = 9;
	m_StructRowCol[223].m_nCOl = 11; m_StructRowCol[223].m_nRow = 16;
	m_StructRowCol[224].m_nCOl = 12; m_StructRowCol[224].m_nRow = 2;
	m_StructRowCol[225].m_nCOl = 11; m_StructRowCol[225].m_nRow = 9;
	m_StructRowCol[226].m_nCOl = 12; m_StructRowCol[226].m_nRow = 17;
	m_StructRowCol[227].m_nCOl = 11; m_StructRowCol[227].m_nRow = 2;
	m_StructRowCol[228].m_nCOl = 12; m_StructRowCol[228].m_nRow = 10;
	m_StructRowCol[229].m_nCOl = 11; m_StructRowCol[229].m_nRow = 17;
	m_StructRowCol[230].m_nCOl = 12; m_StructRowCol[230].m_nRow = 3;
	m_StructRowCol[231].m_nCOl = 11; m_StructRowCol[231].m_nRow = 10;
	m_StructRowCol[232].m_nCOl = 12; m_StructRowCol[232].m_nRow = 18;
	m_StructRowCol[233].m_nCOl = 11; m_StructRowCol[233].m_nRow = 3;
	m_StructRowCol[234].m_nCOl = 12; m_StructRowCol[234].m_nRow = 11;
	m_StructRowCol[235].m_nCOl = 11; m_StructRowCol[235].m_nRow = 18;
	m_StructRowCol[236].m_nCOl = 12; m_StructRowCol[236].m_nRow = 4;
	m_StructRowCol[237].m_nCOl = 11; m_StructRowCol[237].m_nRow = 11;
	m_StructRowCol[238].m_nCOl = 12; m_StructRowCol[238].m_nRow = 19;
	m_StructRowCol[239].m_nCOl = 11; m_StructRowCol[239].m_nRow = 4;
	m_StructRowCol[240].m_nCOl = 12; m_StructRowCol[240].m_nRow = 12;
	m_StructRowCol[241].m_nCOl = 11; m_StructRowCol[241].m_nRow = 19;
	m_StructRowCol[242].m_nCOl = 12; m_StructRowCol[242].m_nRow = 5;
	m_StructRowCol[243].m_nCOl = 11; m_StructRowCol[243].m_nRow = 12;
	m_StructRowCol[244].m_nCOl = 12; m_StructRowCol[244].m_nRow = 20;
	m_StructRowCol[245].m_nCOl = 11; m_StructRowCol[245].m_nRow = 5;
	m_StructRowCol[246].m_nCOl = 12; m_StructRowCol[246].m_nRow = 13;
	m_StructRowCol[247].m_nCOl = 11; m_StructRowCol[247].m_nRow = 20;
	m_StructRowCol[248].m_nCOl = 12; m_StructRowCol[248].m_nRow = 6;
	m_StructRowCol[249].m_nCOl = 11; m_StructRowCol[249].m_nRow = 13;
	m_StructRowCol[250].m_nCOl = 12; m_StructRowCol[250].m_nRow = 21;
	m_StructRowCol[251].m_nCOl = 11; m_StructRowCol[251].m_nRow = 6;
	m_StructRowCol[252].m_nCOl = 12; m_StructRowCol[252].m_nRow = 14;
	m_StructRowCol[253].m_nCOl = 11; m_StructRowCol[253].m_nRow = 21;
	m_StructRowCol[254].m_nCOl = 12; m_StructRowCol[254].m_nRow = 7;
	m_StructRowCol[255].m_nCOl = 11; m_StructRowCol[255].m_nRow = 14;
	m_StructRowCol[256].m_nCOl = 12; m_StructRowCol[256].m_nRow = 22;
	m_StructRowCol[257].m_nCOl = 11; m_StructRowCol[257].m_nRow = 7;
	m_StructRowCol[258].m_nCOl = 12; m_StructRowCol[258].m_nRow = 15;
	m_StructRowCol[259].m_nCOl = 11; m_StructRowCol[259].m_nRow = 22;
	m_StructRowCol[260].m_nCOl = 12; m_StructRowCol[260].m_nRow = 8;
	m_StructRowCol[261].m_nCOl = 13; m_StructRowCol[261].m_nRow = 15;
	m_StructRowCol[262].m_nCOl = 14; m_StructRowCol[262].m_nRow = 1;
	m_StructRowCol[263].m_nCOl = 13; m_StructRowCol[263].m_nRow = 8;
	m_StructRowCol[264].m_nCOl = 14; m_StructRowCol[264].m_nRow = 16;
	m_StructRowCol[265].m_nCOl = 13; m_StructRowCol[265].m_nRow = 1;
	m_StructRowCol[266].m_nCOl = 14; m_StructRowCol[266].m_nRow = 9;
	m_StructRowCol[267].m_nCOl = 13; m_StructRowCol[267].m_nRow = 16;
	m_StructRowCol[268].m_nCOl = 14; m_StructRowCol[268].m_nRow = 2;
	m_StructRowCol[269].m_nCOl = 13; m_StructRowCol[269].m_nRow = 9;
	m_StructRowCol[270].m_nCOl = 14; m_StructRowCol[270].m_nRow = 17;
	m_StructRowCol[271].m_nCOl = 13; m_StructRowCol[271].m_nRow = 2;
	m_StructRowCol[272].m_nCOl = 14; m_StructRowCol[272].m_nRow = 10;
	m_StructRowCol[273].m_nCOl = 13; m_StructRowCol[273].m_nRow = 17;
	m_StructRowCol[274].m_nCOl = 14; m_StructRowCol[274].m_nRow = 3;
	m_StructRowCol[275].m_nCOl = 13; m_StructRowCol[275].m_nRow = 10;
	m_StructRowCol[276].m_nCOl = 14; m_StructRowCol[276].m_nRow = 18;
	m_StructRowCol[277].m_nCOl = 13; m_StructRowCol[277].m_nRow = 3;
	m_StructRowCol[278].m_nCOl = 14; m_StructRowCol[278].m_nRow = 11;
	m_StructRowCol[279].m_nCOl = 13; m_StructRowCol[279].m_nRow = 18;
	m_StructRowCol[280].m_nCOl = 14; m_StructRowCol[280].m_nRow = 4;
	m_StructRowCol[281].m_nCOl = 13; m_StructRowCol[281].m_nRow = 11;
	m_StructRowCol[282].m_nCOl = 14; m_StructRowCol[282].m_nRow = 19;
	m_StructRowCol[283].m_nCOl = 13; m_StructRowCol[283].m_nRow = 4;
	m_StructRowCol[284].m_nCOl = 14; m_StructRowCol[284].m_nRow = 12;
	m_StructRowCol[285].m_nCOl = 13; m_StructRowCol[285].m_nRow = 19;
	m_StructRowCol[286].m_nCOl = 14; m_StructRowCol[286].m_nRow = 5;
	m_StructRowCol[287].m_nCOl = 13; m_StructRowCol[287].m_nRow = 12;
	m_StructRowCol[288].m_nCOl = 14; m_StructRowCol[288].m_nRow = 20;
	m_StructRowCol[289].m_nCOl = 13; m_StructRowCol[289].m_nRow = 5;
	m_StructRowCol[290].m_nCOl = 14; m_StructRowCol[290].m_nRow = 13;
	m_StructRowCol[291].m_nCOl = 13; m_StructRowCol[291].m_nRow = 20;
	m_StructRowCol[292].m_nCOl = 14; m_StructRowCol[292].m_nRow = 6;
	m_StructRowCol[293].m_nCOl = 13; m_StructRowCol[293].m_nRow = 13;
	m_StructRowCol[294].m_nCOl = 14; m_StructRowCol[294].m_nRow = 21;
	m_StructRowCol[295].m_nCOl = 13; m_StructRowCol[295].m_nRow = 6;
	m_StructRowCol[296].m_nCOl = 14; m_StructRowCol[296].m_nRow = 14;
	m_StructRowCol[297].m_nCOl = 13; m_StructRowCol[297].m_nRow = 21;
	m_StructRowCol[298].m_nCOl = 14; m_StructRowCol[298].m_nRow = 7;
	m_StructRowCol[299].m_nCOl = 13; m_StructRowCol[299].m_nRow = 14;
	m_StructRowCol[300].m_nCOl = 14; m_StructRowCol[300].m_nRow = 22;
	 
}

void PrintThead::OpenCom()
{
	//serial.setPortName("COM4");   //串口名
	//if (serial.open(QIODevice::ReadWrite))
	//{
	//	bool b;
	//	qint32 baudrate = 115200;
	//	b = serial.setBaudRate(baudrate);//波特率
	//	b = serial.setDataBits(QSerialPort::Data8); //数据位
	//	b = serial.setParity(QSerialPort::NoParity); //校验位
	//	b = serial.setStopBits(QSerialPort::OneStop);//停止位
	//	b = serial.setFlowControl(QSerialPort::NoFlowControl);
	//	serial.setDataTerminalReady(true);
	//}
}
 
//void PrintThead::SendData()
//{
//	QString sendstr = ui.plainTextEdit_send->toPlainText();
//	QByteArray bytes;
//	bytes = QByteArray::fromHex(sendstr.toLatin1());
//	QSerialPort.write(bytes);//数据发送
//	QSerialPort.waitForReadyRead(100);//延迟一定要有,不然接收不到数据
//	QByteArray  byteArray = serialIo->readAll().toHex();
//	QString temp = QString(byteArray);
//	bool ok;
//	int dec = temp.toInt(&ok, 16);//十六进制转十进制
//}
 
void PrintThead::serialPort_readyRead()
{
    //从接收缓冲区中读取数据
  //  QByteArray buffer = serial.readAll();

	//QString recv  = QString(buffer);

    //从界面中读取以前收到的数据
//    QString recv += QString(buffer);
    //清空以前的显示
 //   ui->recvTextEdit->clear();
    //重新显示
 //   ui->recvTextEdit->append(recv);
}

void PrintThead::closeThread()
{    
	m_isStop = true;
} 

void PrintThead::run()
{    
	int strTempCmdLen = 0;
	MainWindow* theApp = (MainWindow*)(this->parent());

	serial = new QSerialPort();
	serial->setPortName("COM4");   //串口名
	if (serial->open(QIODevice::ReadWrite))
	{
		bool b;
		qint32 baudrate = 115200;
		b = serial->setBaudRate(baudrate);//波特率
		b = serial->setDataBits(QSerialPort::Data8); //数据位
		b = serial->setParity(QSerialPort::NoParity); //校验位
		b = serial->setStopBits(QSerialPort::OneStop);//停止位
		b = serial->setFlowControl(QSerialPort::NoFlowControl);
		serial->setDataTerminalReady(true);
	}



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
		int nPixel = theApp->m_MessagePrint->bytPrintDataAll[6];
		int nBytesPcol = nPixel%8==0?nPixel/8:(nPixel/8+1);
		int nColMax = (theApp->m_MessagePrint->bytPrintDataAll[7]+theApp->m_MessagePrint->bytPrintDataAll[8]*256)/nBytesPcol;

		for(int nColIndex = 0; nColIndex < nColMax; nColIndex++)
		{
			char readArr[46]={0x81,0x02, //控制指令
							  0x02,0x00, //row = 1 ， col = 1，16bit，分成两个字节传输，高字节在后，低字节在前
							  0x00,0x00,
							  0x02,0x00,
							  0x00,0x00,
							  0x02,0x00,
							  0x00,0x00,
							  0x02,0x00,
							  0x00,0x00, 
							  0x02,0x00,
							  0x00,0x00,
							  0x02,0x00,
							  0x00,0x00,
							  0x02,0x00,
							  0x00,0x00, 
							  0x02,0x00,
							  0x00,0x00,
							  0x02,0x00,
							  0x00,0x00,
							  0x02,0x00,
							  0x00,0x00,
							  0x02,0x00,
							  0x00,0x00 
						   };
	 
			 //1列150个喷嘴，150/8 = 19个字节，每个字节的位存储打印点阵中的1列黑白（0，1）信息
			//将19个字节中的bit数据转化成喷头的喷嘴行列驱动信息，然后传给FPGA
			//如果只用喷头的其中1列喷嘴打印，取奇数或偶数喷嘴序号
			BYTE  bytesData[19];
			for(int i = 0; i < 19; i++)
			{
				bytesData[i] = 0;
			}
			for(int m = 0; m < nBytesPcol; m++)
			{
				bytesData[m] = theApp->m_MessagePrint->bytPrintDataAll[11+nColIndex*nBytesPcol+m];
			}
		 

			for(int i = 0; i < 19; i++)
			{
				BYTE oneBype = bytesData[i];
				for(int j = 0; j < 8; j++)
				{
					if(2*i*8+j*2+1 > 300) break;
					bool bit = ((oneBype >> j) & 1); //取某一位的值
					int row = m_StructRowCol[2*i*8+j*2+1].m_nRow;
					int col = m_StructRowCol[2*i*8+j*2+1].m_nCOl;
					if(col <= 6 && bit)
						readArr[row*2] = readArr[row*2] | (1 << (col+1)); //给某一位赋值
					else if(col > 6 && bit)
						readArr[row*2+1] = readArr[row*2+1] | (1 << (col-7)); //给某一位赋值
				}
			}
		 
		
			serial->waitForReadyRead(1);
 	 		qint64 n = serial->write(readArr,46);//数据发送

			msleep(5);

		}
 		msleep(5); 
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
 /*
 	BYTE  bytesData[19];
			for(int i = 0; i < 19; i++)
			{
				bytesData[i] = 0;
			}
			bytesData[0] = 0xFF;
			//bytesData[1] = 0xFF;
			bytesData[2] = 0xFF;
			//bytesData[3] = 0xFF;
			bytesData[4] = 0xFF;
			//bytesData[5] = 0xFF;
			bytesData[6] = 0xFF;
			//bytesData[7] = 0xFF;
			bytesData[8] = 0xFF;
		//	bytesData[9] = 0xFF;
			bytesData[10] = 0xFF;
		//	bytesData[11] = 0xFF;
			bytesData[12] = 0xFF;
		//	bytesData[13] = 0xFF;
			bytesData[14] = 0xFF;
		//	bytesData[15] = 0xFF; 
			bytesData[16] = 0xFF;
		//	bytesData[17] = 0xFF;
			bytesData[18] = 0xFF;	

			for(int i = 0; i < 19; i++)
			{
				BYTE oneBype = bytesData[i];
				for(int j = 0; j < 8; j++)
				{
					if(2*i*8+j*2+1 > 300) break;
					bool bit = ((oneBype >> j) & 1); //取某一位的值
					int row = m_StructRowCol[2*i*8+j*2+1].m_nRow;
					int col = m_StructRowCol[2*i*8+j*2+1].m_nCOl;
					if(col <= 6 && bit)
						readArr[row*2] = readArr[row*2] | (1 << (col+1)); //给某一位赋值
					else if(col > 6 && bit)
						readArr[row*2+1] = readArr[row*2+1] | (1 << (col-7)); //给某一位赋值
				}
			}
 */