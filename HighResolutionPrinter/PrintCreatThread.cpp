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

	while(1)
	{
		if (theApp->ForPreQue.size()<2)
		{
			/*
			if (theApp.myclassMessage.bytSerialConCoun>0)
			{
				string StrSerialText="";
				string strTemp="";
				for (int i=0;i<theApp.myclassMessage.bytSerialConCoun;i++)
				{
					switch(theApp.myclassMessage.bytQserialCounter[i])
					{
					case 0:
						if (theApp.myclassMessage.CountNumRep0<theApp.myclassMessage.intQSerialRepeat[i])
						{
							theApp.myclassMessage.CountNumRep0=theApp.myclassMessage.CountNumRep0+1;
						} 
						else
						{
							theApp.myclassMessage.CountNumRep0=1;
							if (theApp.myclassMessage.intQSerialFirstLimit[i]<theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum0+theApp.myclassMessage.intQSerialStep[i];
								if (tempValue>theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum0 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] - 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum0 = tempValue;
								}
							}
							else if (theApp.myclassMessage.intQSerialFirstLimit[i]>theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum0-theApp.myclassMessage.intQSerialStep[i];
								if (tempValue<theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum0 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] + 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum0 = tempValue;
								}
							}
						}

						switch(theApp.myclassMessage.bytQSerialFormat[i])
						{
						case 0:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+"0";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum0);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum0);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum0);
							int n = theApp.myclassMessage.bytQSerialDigits[i]-strTemp.length();
							for (int a=0;a<n;a++)
							{
								strTemp=strTemp+" ";
							}
							StrSerialText=strTemp;
							break;
						}
						break;
					case 1:
						if (theApp.myclassMessage.CountNumRep1<theApp.myclassMessage.intQSerialRepeat[i])
						{
							theApp.myclassMessage.CountNumRep1=theApp.myclassMessage.CountNumRep1+1;
						} 
						else
						{
							theApp.myclassMessage.CountNumRep1=1;
							if (theApp.myclassMessage.intQSerialFirstLimit[i]<theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum1+theApp.myclassMessage.intQSerialStep[i];
								if (tempValue>theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum1 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] - 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum1 = tempValue;
								}
							}
							else if (theApp.myclassMessage.intQSerialFirstLimit[i]>theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum1-theApp.myclassMessage.intQSerialStep[i];
								if (tempValue<theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum1 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] + 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum1 = tempValue;
								}
							}
						}

						switch(theApp.myclassMessage.bytQSerialFormat[i])
						{
						case 0:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+"0";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum1);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum1);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum1);
							int n = theApp.myclassMessage.bytQSerialDigits[i]-strTemp.length();
							for (int a=0;a<n;a++)
							{
								strTemp=strTemp+" ";
							}
							StrSerialText=strTemp;
							break;
						}
						break;
					case 2:
						if (theApp.myclassMessage.CountNumRep2<theApp.myclassMessage.intQSerialRepeat[i])
						{
							theApp.myclassMessage.CountNumRep2=theApp.myclassMessage.CountNumRep2+1;
						} 
						else
						{
							theApp.myclassMessage.CountNumRep2=1;
							if (theApp.myclassMessage.intQSerialFirstLimit[i]<theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum2+theApp.myclassMessage.intQSerialStep[i];
								if (tempValue>theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum2 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] - 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum2 = tempValue;
								}
							}
							else if (theApp.myclassMessage.intQSerialFirstLimit[i]>theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum2-theApp.myclassMessage.intQSerialStep[i];
								if (tempValue<theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum2 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] + 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum2 = tempValue;
								}
							}
						}

						switch(theApp.myclassMessage.bytQSerialFormat[i])
						{
						case 0:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+"0";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum2);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum2);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum2);
							int n = theApp.myclassMessage.bytQSerialDigits[i]-strTemp.length();
							for (int a=0;a<n;a++)
							{
								strTemp=strTemp+" ";
							}
							StrSerialText=strTemp;
							break;
						}
						break;
					case 3:
						if (theApp.myclassMessage.CountNumRep3<theApp.myclassMessage.intQSerialRepeat[i])
						{
							theApp.myclassMessage.CountNumRep3=theApp.myclassMessage.CountNumRep3+1;
						} 
						else
						{
							theApp.myclassMessage.CountNumRep3=1;
							if (theApp.myclassMessage.intQSerialFirstLimit[i]<theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum3+theApp.myclassMessage.intQSerialStep[i];
								if (tempValue>theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum3 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] - 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum3 = tempValue;
								}
							}
							else if (theApp.myclassMessage.intQSerialFirstLimit[i]>theApp.myclassMessage.intQSerialSecondLimit[i])
							{
								int tempValue=theApp.myclassMessage.CountNum3-theApp.myclassMessage.intQSerialStep[i];
								if (tempValue<theApp.myclassMessage.intQSerialSecondLimit[i])
								{
									theApp.myclassMessage.CountNum3 = tempValue - theApp.myclassMessage.intQSerialSecondLimit[i] + theApp.myclassMessage.intQSerialFirstLimit[i] + 1; //'超第二象限的计算公式
								} 
								else
								{
									theApp.myclassMessage.CountNum3 = tempValue;
								}
							}
						}

						switch(theApp.myclassMessage.bytQSerialFormat[i])
						{
						case 0:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+"0";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum3);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 1:
							for (int a=0;a<theApp.myclassMessage.bytQSerialDigits[i];a++)
							{
								strTemp=strTemp+" ";//123456789
							}
							strTemp = strTemp +theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum3);
							StrSerialText=strTemp.substr(strTemp.length()-theApp.myclassMessage.bytQSerialDigits[i],theApp.myclassMessage.bytQSerialDigits[i]);
							break;
						case 2:
							strTemp = theApp.myclassMessage.to_String(theApp.myclassMessage.CountNum3);
							int n = theApp.myclassMessage.bytQSerialDigits[i]-strTemp.length();
							for (int a=0;a<n;a++)
							{
								strTemp=strTemp+" ";
							}
							StrSerialText=strTemp;
							break;
						}
						break;
					}
					int intRowEnd=theApp.myclassMessage.intQSerialRowStart[i] + theApp.myclassMessage.intQSerialRowSize[i];
					vector<BYTE> ttVec;
					ttVec=theApp.myclassMessage.DotToByte1(theApp.myclassMessage.intQSerialRowStart[i], intRowEnd, theApp.myclassMessage.bytPrintDataAll, theApp.myclassMessage.strQSerialFont[i], 
						theApp.myclassMessage.boQSerialBWDy[i], theApp.myclassMessage.boQSerialBWDx[i], theApp.myclassMessage.boQSerialNEG[i], StrSerialText, theApp.myclassMessage.intQSerialRowSize[i], 
						theApp.myclassMessage.bytQSerialLineSize[i],theApp.myclassMessage.bytQSerialLineStart[i], theApp.myclassMessage.intQSerialRowStart[i], theApp.myclassMessage.bytQSerialSS[i], theApp.myclassMessage.bytQSerialSW[i]);
					theApp.myclassMessage.bytPrintDataAll.clear();
					theApp.myclassMessage.bytPrintDataAll=ttVec;
				}
			}

			if (theApp.myclassMessage.bytTimeConCoun>0)
			{
				string *strETimetext1=new string[theApp.myclassMessage.bytTimeConCoun];
				theApp.boETimetextLock.Lock();
					//copy(begin(theApp.myclassMessage.strETimetext),end(theApp.myclassMessage.strETimetext),begin(strETimetext1));
					for(int strI=0;strI<theApp.myclassMessage.bytTimeConCoun;strI++)
					{
						strETimetext1[strI]=theApp.myclassMessage.strETimetext[strI];
					}
				theApp.boETimetextLock.Unlock();
				for (int j=0;j<theApp.myclassMessage.bytTimeConCoun;j++)
				{
					int intRowEnd=theApp.myclassMessage.intTimeRowStart[j] + theApp.myclassMessage.intTimeRowSize[j];
					vector<BYTE> ttVec;
					if (strETimetext1[j].length()!=0)
					{
						ttVec = theApp.myclassMessage.DotToByte1(theApp.myclassMessage.intTimeRowStart[j], intRowEnd, theApp.myclassMessage.bytPrintDataAll, 
							theApp.myclassMessage.strTimeFont[j], theApp.myclassMessage.boTimeBWDy[j], theApp.myclassMessage.boTimeBWDx[j], theApp.myclassMessage.boTimeNEG[j], 
							strETimetext1[j], theApp.myclassMessage.intTimeRowSize[j], theApp.myclassMessage.bytTimeLineSize[j], theApp.myclassMessage.bytTimeLineStart[j], 
							theApp.myclassMessage.intTimeRowStart[j], theApp.myclassMessage.bytTimeSS[j], theApp.myclassMessage.bytTimeSW[j]);
						theApp.myclassMessage.bytPrintDataAll.clear();
						theApp.myclassMessage.bytPrintDataAll=ttVec;
					}
				}
				delete []strETimetext1;
			}
			vector<BYTE> bytPrintDataAll1=theApp.myclassMessage.bytPrintDataAll;
			theApp.boPrintNowLock.Lock();
			theApp.ForPreQue.push(bytPrintDataAll1);
			
			vector<int> tempCounNum;
			tempCounNum.push_back(theApp.myclassMessage.CountNum0);
			tempCounNum.push_back(theApp.myclassMessage.CountNum1);
			tempCounNum.push_back(theApp.myclassMessage.CountNum2);
			tempCounNum.push_back(theApp.myclassMessage.CountNum3);
			theApp.intCounNumForPreQue.push(tempCounNum);
			theApp.boPrintNowLock.Unlock();

			*/
		}		
	} 
}
 