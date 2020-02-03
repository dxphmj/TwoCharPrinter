#include "PrintShowThread.h"
#include "mainwindow.h"
#include "ClassMessage.h"

PrintShowThread::PrintShowThread(QObject *parent)
	: QThread(parent)
{

}

PrintShowThread::~PrintShowThread()
{

}

void PrintShowThread::run()
{    
	int strTempCmdLen = 0;
	MainWindow* theApp = (MainWindow*)(this->parent());

	//如动态打印则动态显示，下面的逻辑还需优化
	/*
	while(theApp.mythreadDynamicBoo)
	{
		while(theApp.boDrawMainPic)
		{
			vector<BYTE> intMesDis1=theApp.myclassMessage.intMesDis;
			for (int j=0;j<theApp.myclassMessage.bytSerialConCoundis;j++)
			{
				int intDynamicRowEnd = theApp.myclassMessage.intQSerialRowStartdis[j] + theApp.myclassMessage.intQSerialRowSizedis[j] - 1;
				if (theApp.myclassMessage.matrixMesdis!=14)
				{
					if (theApp.myclassMessage.pixelMesdis<8)
					{
						if (theApp.myclassMessage.boReversedis)
						{
							if (theApp.myclassMessage.boInversedis)
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + theApp.myclassMessage.intDotMesRowdis - tmptInt],i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 + i - theApp.myclassMessage.pixelMesdis) * pixSize+1,
											(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32 + i - theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							} 
							else
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + theApp.myclassMessage.intDotMesRowdis - tmptInt],i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 - i) * pixSize+1,(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							}
						} 
						else
						{
							if (theApp.myclassMessage.boInversedis)
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11+k],i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31+i-theApp.myclassMessage.pixelMesdis)*pixSize+1,(k+1)*pixSize,(32+i-theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							} 
							else
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11+k],i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							}
						}
					} 
					else if (theApp.myclassMessage.pixelMesdis>7&&theApp.myclassMessage.pixelMesdis<16)
					{
						if (theApp.myclassMessage.boReversedis)
						{
							if (theApp.myclassMessage.boInversedis)
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 2 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + intMesDis1[11 + 2 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 + i - theApp.myclassMessage.pixelMesdis) * pixSize+1,
											(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32 + i - theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							} 
							else
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 2 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + intMesDis1[11 + 2 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 - i) * pixSize+1,(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							}
						} 
						else
						{
							if (theApp.myclassMessage.boInversedis)
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 2 * k] + (intMesDis1[11 + 2 * k + 1] * pow(2 , 8)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31+i-theApp.myclassMessage.pixelMesdis)*pixSize+1,(k+1)*pixSize,(32+i-theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							} 
							else
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 2 * k] + (intMesDis1[11 + 2 * k + 1] * pow(2 , 8)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							}
						}
					}
					else if (theApp.myclassMessage.pixelMesdis>15&&theApp.myclassMessage.pixelMesdis<24)
					{
						if (theApp.myclassMessage.boReversedis)
						{
							if (theApp.myclassMessage.boInversedis)
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB((intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + (intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8)) + (intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 2] * pow(2 , 16))),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 + i - theApp.myclassMessage.pixelMesdis) * pixSize+1,
											(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32 + i - theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							} 
							else
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB((intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + (intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8)) + (intMesDis1[11 + 3 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 2] * pow(2 , 16))),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 - i) * pixSize+1,(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							}
						} 
						else
						{
							if (theApp.myclassMessage.boInversedis)
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 3 * k] + (intMesDis1[11 + 3 * k + 1] * pow(2 , 8))+ (intMesDis1[11 + 3 * k + 2] * pow(2 , 16)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31+i-theApp.myclassMessage.pixelMesdis)*pixSize+1,(k+1)*pixSize,(32+i-theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							} 
							else
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 3 * k] + (intMesDis1[11 + 3 * k + 1] * pow(2 , 8))+ (intMesDis1[11 + 3 * k + 2] * pow(2 , 16)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							}
						}
					}
					else if (theApp.myclassMessage.pixelMesdis>23)
					{
						if (theApp.myclassMessage.boReversedis)
						{
							if (theApp.myclassMessage.boInversedis)
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB((intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8)) + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 2] * pow(2 , 16)) + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 3] *pow (2 , 24))),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 + i - theApp.myclassMessage.pixelMesdis) * pixSize+1,
											(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32 + i - theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							} 
							else
							{
								int tmptInt=intDynamicRowEnd;
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB((intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt)] + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 1] * pow(2 , 8)) + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 2] * pow(2 , 16)) + (intMesDis1[11 + 4 * (theApp.myclassMessage.intDotMesRowdis - tmptInt) + 3] *pow (2 , 24))),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle((intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]) * pixSize+1,(31 - i) * pixSize+1,(intDynamicRowEnd - k + theApp.myclassMessage.intQSerialRowStartdis[j]+1) * pixSize,(32-i)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
									tmptInt = tmptInt - 1;
								}
							}
						} 
						else
						{
							if (theApp.myclassMessage.boInversedis)
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 4 * k] + (intMesDis1[11 + 4 * k + 1] * pow(2 , 8))+ (intMesDis1[11 + 4 * k + 2] * pow(2 , 16))+ (intMesDis1[11 + 4 * k + 3] * pow(2 , 24)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31+i-theApp.myclassMessage.pixelMesdis)*pixSize+1,(k+1)*pixSize,(32+i-theApp.myclassMessage.pixelMesdis)*pixSize);
										//AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							} 
							else
							{
								for (int k=theApp.myclassMessage.intQSerialRowStartdis[j];k<=intDynamicRowEnd;k++)
								{
									for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
									{
										if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 4 * k] + (intMesDis1[11 + 4 * k + 1] * pow(2 , 8))+ (intMesDis1[11 + 4 * k + 2] * pow(2 , 16))+ (intMesDis1[11 + 4 * k + 3] * pow(2 , 24)),i))
										{
											pBrush=pDC->SelectObject(&cbrushB);
										} 
										else
										{
											pDC->SelectStockObject(WHITE_BRUSH);
										}
										pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
										////AfxGetApp()->PumpMessage();
										Sleep(1);
									}
								}
							}
						}
					}

				} 
				else
				{
					int tmptInt=intDynamicRowEnd;
					for (int k=theApp.myclassMessage.intQSerialStartValue[j];k<=intDynamicRowEnd;k++)
					{
						BYTE tempByte1= intMesDis1[k * 2 + 11];
						BYTE tempByte2 = intMesDis1[k * 2 + 11 + 1];

						if (theApp.myModuleMain.MesDisIsB(tempByte1,0))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,31*pixSize+1,(k+1)*pixSize,(32)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,1))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-8)*pixSize+1,(k+1)*pixSize,(32-8)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,2))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-1)*pixSize+1,(k+1)*pixSize,(32-1)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,3))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-9)*pixSize+1,(k+1)*pixSize,(32-9)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,4))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-2)*pixSize+1,(k+1)*pixSize,(32-2)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,5))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-10)*pixSize+1,(k+1)*pixSize,(32-11)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,6))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-3)*pixSize+1,(k+1)*pixSize,(32-3)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,7))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-11)*pixSize+1,(k+1)*pixSize,(32-11)*pixSize);
						Sleep(1);


						if (theApp.myModuleMain.MesDisIsB(tempByte2,0))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-4)*pixSize+1,(k+1)*pixSize,(32-4)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,1))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-12)*pixSize+1,(k+1)*pixSize,(32-12)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,2))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-5)*pixSize+1,(k+1)*pixSize,(32-5)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,3))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-13)*pixSize+1,(k+1)*pixSize,(32-13)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,4))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-6)*pixSize+1,(k+1)*pixSize,(32-6)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,5))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-14)*pixSize+1,(k+1)*pixSize,(32-14)*pixSize);
						Sleep(1);

					}

				}
			}

			for (int j=0;j<theApp.myclassMessage.bytTimeConCoundis;j++)
			{
				int intDynamicRowEnd = theApp.myclassMessage.intTimeRowStartdis[j] + theApp.myclassMessage.intTimeRowSizedis[j] - 1;
				if (theApp.myclassMessage.matrixMesdis!=14)
				{
					if (theApp.myclassMessage.pixelMesdis<8)
					{
						for (int k=theApp.myclassMessage.intTimeRowStartdis[j];k<=intDynamicRowEnd;k++)
						{
							for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
							{
								if (theApp.myModuleMain.MesDisIsB(intMesDis1[11+k],i))
								{
									pBrush=pDC->SelectObject(&cbrushB);
								} 
								else
								{
									pDC->SelectStockObject(WHITE_BRUSH);
								}
								pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
								//AfxGetApp()->PumpMessage();
								Sleep(1);
							}
						}
					} 
					else if (theApp.myclassMessage.pixelMesdis>7&&theApp.myclassMessage.pixelMesdis<16)
					{

						for (int k=theApp.myclassMessage.intTimeRowStartdis[j];k<=intDynamicRowEnd;k++)
						{
							for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
							{
								if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 2 * k] + (intMesDis1[11 + 2 * k + 1] * pow(2 , 8)),i))
								{
									pBrush=pDC->SelectObject(&cbrushB);
								} 
								else
								{
									pDC->SelectStockObject(WHITE_BRUSH);
								}
								pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
								//AfxGetApp()->PumpMessage();
								Sleep(1);
							}
						}

					}
					else if (theApp.myclassMessage.pixelMesdis>15&&theApp.myclassMessage.pixelMesdis<24)
					{

						for (int k=theApp.myclassMessage.intTimeRowStartdis[j];k<=intDynamicRowEnd;k++)
						{
							for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
							{
								if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 3 * k] + (intMesDis1[11 + 3 * k + 1] * pow(2 , 8))+ (intMesDis1[11 + 3 * k + 2] * pow(2 , 16)),i))
								{
									pBrush=pDC->SelectObject(&cbrushB);
								} 
								else
								{
									pDC->SelectStockObject(WHITE_BRUSH);
								}
								pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
								//AfxGetApp()->PumpMessage();
								Sleep(1);
							}
						}
					}
					else if (theApp.myclassMessage.pixelMesdis>23)
					{
						for (int k=theApp.myclassMessage.intTimeRowStartdis[j];k<=intDynamicRowEnd;k++)
						{
							for (int i=0;i<=theApp.myclassMessage.pixelMesdis;i++)
							{
								if (theApp.myModuleMain.MesDisIsB(intMesDis1[11 + 4 * k] + (intMesDis1[11 + 4 * k + 1] * pow(2 , 8))+ (intMesDis1[11 + 4 * k + 2] * pow(2 , 16))+ (intMesDis1[11 + 4 * k + 3] * pow(2 , 24)),i))
								{
									pBrush=pDC->SelectObject(&cbrushB);
								} 
								else
								{
									pDC->SelectStockObject(WHITE_BRUSH);
								}
								pDC->Rectangle(k*pixSize+1,(31 - i)*pixSize+1,(k+1)*pixSize,(32-i)*pixSize);
								////AfxGetApp()->PumpMessage();
								Sleep(1);
							}
						}
					}
				} 
				else
				{
					int tmptInt=intDynamicRowEnd;
					for (int k=theApp.myclassMessage.intTimeRowStartdis[j];k<=intDynamicRowEnd;k++)
					{
						BYTE tempByte1= intMesDis1[k * 2 + 11];
						BYTE tempByte2 = intMesDis1[k * 2 + 11 + 1];

						if (theApp.myModuleMain.MesDisIsB(tempByte1,0))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,31*pixSize+1,(k+1)*pixSize,(32)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,1))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-8)*pixSize+1,(k+1)*pixSize,(32-8)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,2))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-1)*pixSize+1,(k+1)*pixSize,(32-1)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,3))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-9)*pixSize+1,(k+1)*pixSize,(32-9)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,4))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-2)*pixSize+1,(k+1)*pixSize,(32-2)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,5))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-10)*pixSize+1,(k+1)*pixSize,(32-11)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,6))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-3)*pixSize+1,(k+1)*pixSize,(32-3)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte1,7))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-11)*pixSize+1,(k+1)*pixSize,(32-11)*pixSize);
						Sleep(1);


						if (theApp.myModuleMain.MesDisIsB(tempByte2,0))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-4)*pixSize+1,(k+1)*pixSize,(32-4)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,1))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-12)*pixSize+1,(k+1)*pixSize,(32-12)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,2))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-5)*pixSize+1,(k+1)*pixSize,(32-5)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,3))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-13)*pixSize+1,(k+1)*pixSize,(32-13)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,4))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-6)*pixSize+1,(k+1)*pixSize,(32-6)*pixSize);
						Sleep(1);

						if (theApp.myModuleMain.MesDisIsB(tempByte2,5))
						{
							pBrush=pDC->SelectObject(&cbrushB);
						} 
						else
						{
							pDC->SelectStockObject(WHITE_BRUSH);
						}
						pDC->Rectangle(k*pixSize+1,(31-14)*pixSize+1,(k+1)*pixSize,(32-14)*pixSize);
						Sleep(1);

					}

				}
			}//
		}
		Sleep(50);
	}
	*/
}
 