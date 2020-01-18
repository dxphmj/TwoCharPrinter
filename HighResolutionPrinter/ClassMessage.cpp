#include "ClassMessage.h"
#include "sstream"
#include <fstream>
#include <stdio.h>
#include "xml\tinyxml.h"
#include <QPainter>
//#include <qwidget.h>


ClassMessage::ClassMessage(void)
{
}

ClassMessage::~ClassMessage(void)
{
}

BYTE ClassMessage::getByteFromDot(bool boDot,int moveNum)
{
	if (boDot)
	{
		return 1<<moveNum;
	} 
	else
	{
		return 0;
	}
}
	
string ClassMessage::to_String(int n)
{
	int m = n;
	char s[max];
	char ss[max];
	int i=0,j=0;
	if (n < 0)// 处理负数
	{
		m = 0 - m;
		j = 1;
		ss[0] = '-';
	}    
	while (m>0)
	{
		s[i++] = m % 10 + '0';
		m /= 10;
	}
	s[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		ss[j++] = s[i--];
	}
	if (n==0)
	{
            ss[j++] = '0';
	}
	ss[j] = '\0';    
	return ss;
}

string ClassMessage::DEC_to_BIN(long long Dec)
{
	string DecToBin;
	while (Dec>0)
	{
		if (Dec %2>0)
		{
			DecToBin=this->to_String(Dec %2)+DecToBin;
		}
		else
		{
			DecToBin=this->to_String(0)+DecToBin;
		}
		Dec=Dec/2;
	}
	return DecToBin;
}

long long ClassMessage::BIN_to_DEC(string Bin)
{
	long long BinToDec=0;
	for (int i=0;i<Bin.length();i++)
	{
		std::stringstream ss;
		ss<<Bin.substr(i,1);
		int intss;
		ss>>intss;
		BinToDec=BinToDec*2+intss;
	}
	return  BinToDec;
}

bool ClassMessage::readBin(string FontName,int offset,char *arr, int DataLen )
{
	ifstream file;
	string path="\\Storage Card\\User\\Font\\";    //E:\\

	path = FontName;
	file.open(path.c_str(),ios::binary);
	file.seekg(offset,ios::beg);
	file.read(arr,DataLen);
	return true;
}

void ClassMessage::DrawDot(CDC* pDC)
{
	for (int i = 0; i < OBJ_Vec.size(); i++)
	{
		OBJ_Vec[i].DrawDot(pDC);
	}
}

//判断是否有OBJ被选中
void ClassMessage::JudgeIfOBJ_Selected(int MouseXPos, int MouseYPos)
{
	/*
	1.接收鼠标相对于FileManageChild窗口控件的坐标位置
	2.判断鼠标位置是否在控件范围内，如果是则进行3
	3.遍历OBJ.Vec[]里的所有对象，判断鼠标位置是否在obj的范围内（找到一个对象后break）
	4.booFocus->true(用于改变边框颜色）
	5.SelObjNum = i;
	*/
}

//判断用户输入的文件名strFileName是否和本地已有的xml文件名重复
bool ClassMessage::JudgeXmlNameRepeat(char* strFileName)
{
	/*
	1.遍历文件夹里的xml文件名，逐个和strFileName进行字符串对比
	  可以调用函数，直接判断一个文件夹中是否有名叫strFileName的文件，查！
	2.如果重复，则返回1，不重复，则返回0
	if()
	{
		return ture;
	}
	else
	{
		return false;
	}
	*/
	return true;
}

void ClassMessage::SaveObjectsToXml(char* strFileName)
{
	TiXmlDocument doc(strFileName);

	//从本类中取数据（如m_arrObjects），然后保存
	//OBJ_Control obj;
	//sprintf_s(obj.m_texts,"afds");
	//m_arrObjects.push_back(obj);
	//m_arrObjects.push_back(obj);

	TiXmlElement itemMes( "MES" );

	TiXmlElement itemPro( "PRO" );
	TiXmlElement itemMatrix( "Matrix" );
    TiXmlElement itemPixel("Pixel");
	TiXmlElement itemReverse("Reverse");
	TiXmlElement itemInverse("Inverse");
    TiXmlText textMatrix(strMatrix.c_str());
	TiXmlText textPixel(to_String(Pixel).c_str());
	TiXmlText textReverse(Reverse.c_str());
	TiXmlText textInverse(Inverse.c_str());
		
	itemMatrix.InsertEndChild(textMatrix);
	itemPixel.InsertEndChild(textPixel);
	itemReverse.InsertEndChild(textReverse);
	itemInverse.InsertEndChild(textInverse);
	itemPro.InsertEndChild( itemMatrix );
	itemPro.InsertEndChild( itemPixel );
	itemPro.InsertEndChild( itemReverse );
	itemPro.InsertEndChild( itemInverse );
	itemMes.InsertEndChild( itemPro );
		
	for(int i = 0; i < OBJ_Vec.size(); i++)
	{
		TiXmlElement itemObj( "OBJ" ); 
		TiXmlElement itemTYPE1("TYPE1");
		TiXmlElement itemTYPE2("TYPE2");
		TiXmlElement itemLineStart("LineStart");
		TiXmlElement itemRowStart("RowStart");
		TiXmlElement itemLineSize("LineSize");
		TiXmlElement itemRowSize("RowSize");
		TiXmlElement itemSW("SW");
		TiXmlElement itemSS("SS");
		TiXmlElement itemNEG("NEG");
		TiXmlElement itemBWDx("BWDx");
		TiXmlElement itemBWDy("BWDy");
		TiXmlElement itemsetFONT("setFONT");
		TiXmlElement itemSetTEXT( "setTEXT" );

		TiXmlText textType1(OBJ_Vec[i].strType1.c_str());
		TiXmlText textType2(OBJ_Vec[i].strType2.c_str());
		TiXmlText textLinestart(to_String(OBJ_Vec[i].intLineStart).c_str());
		TiXmlText textRowstart(to_String(OBJ_Vec[i].intRowStart).c_str());
		TiXmlText textLinesize(to_String(OBJ_Vec[i].intLineSize).c_str());
		TiXmlText textRowsize(to_String(OBJ_Vec[i].intRowSize).c_str());
		TiXmlText textSW(to_String(OBJ_Vec[i].intSW).c_str());
		TiXmlText textSS(to_String(OBJ_Vec[i].intSS).c_str());
		TiXmlText textNEG(to_String(OBJ_Vec[i].booNEG).c_str());///这几个bool是个坑
		TiXmlText textBWDx(to_String(OBJ_Vec[i].booBWDx).c_str());
		TiXmlText textBWDy(to_String(OBJ_Vec[i].booBWDy).c_str());
		TiXmlText textSetFont(OBJ_Vec[i].strFont.c_str());
		TiXmlText textSetTEXT(OBJ_Vec[i].strText.c_str());

		itemTYPE1.InsertEndChild(textType1);
		itemTYPE2.InsertEndChild(textType2);
		itemLineStart.InsertEndChild(textLinestart);
		itemRowStart.InsertEndChild(textRowstart);
		itemLineSize.InsertEndChild(textLinesize);
		itemRowSize.InsertEndChild(textRowsize);
		itemSW.InsertEndChild(textSW);
		itemSS.InsertEndChild(textSS);
		itemNEG.InsertEndChild(textNEG);
		itemBWDx.InsertEndChild(textBWDx);
		itemBWDy.InsertEndChild(textBWDy);
		itemsetFONT.InsertEndChild(textSetFont);
		itemSetTEXT.InsertEndChild(textSetTEXT);

		if (OBJ_Vec[i].strType2=="serial")
		{
		} 
		else if(OBJ_Vec[i].strType2=="time")
		{
		}

		itemObj.InsertEndChild( itemTYPE1 );
		itemObj.InsertEndChild( itemTYPE2 );
		itemObj.InsertEndChild( itemLineStart );
		itemObj.InsertEndChild( itemRowStart );
		itemObj.InsertEndChild( itemLineSize );
		itemObj.InsertEndChild( itemRowSize );
		itemObj.InsertEndChild( itemSW );
		itemObj.InsertEndChild( itemSS );
		itemObj.InsertEndChild( itemNEG );
		itemObj.InsertEndChild( itemBWDx );
		itemObj.InsertEndChild( itemBWDy );
		itemObj.InsertEndChild( itemsetFONT );
		itemObj.InsertEndChild( itemSetTEXT );
		itemMes.InsertEndChild( itemObj ); 
	}	 
	doc.InsertEndChild(itemMes);

	doc.SaveFile(strFileName);

}

void ClassMessage::ReadBmp(char* strFileName)
{
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	QImage pImage;
	pImage = pLoad.toImage();

	OBJ_Control bmpObj;
	bmpObj.intX=100;
	bmpObj.intY=0;
	bmpObj.intLineStart=0;
	bmpObj.intRowStart=0;
	bmpObj.strType1="text";
	bmpObj.strType2="logo";
	bmpObj.intLineSize=pImage.height();
	bmpObj.intRowSize=pImage.width();
	bmpObj.intSW=1;
	bmpObj.intSS=0;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
			if(average < 100)
				bmpObj.boDotBmp[x][pImage.height()-y-1] = true;//由于坐标系的原因，上下必须颠倒
			else
				bmpObj.boDotBmp[x][pImage.height()-y-1] = false;
		}  
	}  
	bmpObj.booFocus = true;
	OBJ_Vec.push_back(bmpObj); 
}

void ClassMessage::ReadObjectsFromXml(char* strFileName)
{
	OBJ_Vec.clear();
	TiXmlDocument doc(strFileName);
	bool loadOkay = doc.LoadFile();

	TiXmlNode* node = 0;
	TiXmlElement* todoElement = 0;
	TiXmlElement* itemElement = 0;
	node = doc.FirstChild( "MES" );
	assert( node );
	todoElement = node->ToElement();
	assert( todoElement  );

	node = todoElement->FirstChildElement();	 
	assert( node );
	itemElement = node->ToElement();
	assert( itemElement  );

	int count = 0;
	//itemElement = itemElement->NextSiblingElement();
	for( node = todoElement->FirstChildElement();node;node = node->NextSibling() )
	//for( node = todoElement->FirstChildElement();todoElement;node = node->NextSibling() )
	{
		const char* str ;
		str = node->ValueTStr().c_str();
		count++;
		if(strcmp(str,"PRO") == 0)
		{
			//读入信息
			TiXmlNode* nodeTmp = 0;
			for( nodeTmp = node->IterateChildren(0);nodeTmp;nodeTmp = node->IterateChildren( nodeTmp ) )
			{
				const char* strItem = nodeTmp->ValueTStr().c_str();
				if(strcmp(strItem,"Matrix") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					//sprintf_s(obj.m_texts,"%s",strText); 
					strMatrix.assign(strText);
				}
				if(strcmp(strItem,"Pixel") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					//sprintf_s(obj.m_texts,"%s",strText); 
					Pixel=atoi(strText);
				}
				if(strcmp(strItem,"Reverse") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					//sprintf_s(obj.m_texts,"%s",strText); 
					Reverse.assign(strText);
				}
				if(strcmp(strItem,"Inverse") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					//sprintf_s(obj.m_texts,"%s",strText); 
					Inverse.assign(strText);
				}
			}
		}
		else if(strcmp(str,"OBJ") == 0)
		{
			//读入属性信息
			OBJ_Control obj;
			obj.booFocus=false;
			TiXmlNode* nodeTmp = 0;
			for( nodeTmp = node->IterateChildren(0);nodeTmp;nodeTmp = node->IterateChildren( nodeTmp ) )
			{
				const char* strItem = nodeTmp->ValueTStr().c_str();
				if(strcmp(strItem,"TYPE1") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.strType1.assign(strText);
				}
				if(strcmp(strItem,"TYPE2") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.strType2.assign(strText);
				}
				if(strcmp(strItem,"LineStart") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intLineStart=atoi(strText);
				}
				if(strcmp(strItem,"RowStart") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intRowStart=atoi(strText);
				}
				if(strcmp(strItem,"LineSize") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intLineSize=atoi(strText);
				}
				if(strcmp(strItem,"RowSize") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intRowSize=atoi(strText);
				}
				if(strcmp(strItem,"SW") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intSW=atoi(strText);
				}
				if(strcmp(strItem,"SS") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intSS=atoi(strText);
				}
				if(strcmp(strItem,"NEG") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.booNEG=atoi(strText);
				}
				if(strcmp(strItem,"BWDx") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.booBWDx=atoi(strText);
				}
				if(strcmp(strItem,"BWDy") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.booBWDy=atoi(strText);
				}
				if(strcmp(strItem,"setFONT") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.strFont.assign(strText);
				}
				if(strcmp(strItem,"setTEXT") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.strText.assign(strText);
				}
			}
			OBJ_Vec.push_back(obj);
		}
	}	
}

void ClassMessage::getdot(string tempfont, bool tempBWDy, bool tempBWDx , bool tempNEG, string tempsetTEXT ,
	int tempRowSize, int tempLineSize, int tempLineStart , int tempRowStart , int tempSS , int tempSW )
{
	//memset(boDotMes,false,sizeof(boDotMes));
	map<string,int> gfntMap;
	gfntMap.clear();
	gfntMap.insert(make_pair("5x5",0));
	gfntMap.insert(make_pair("7x5",1));
	gfntMap.insert(make_pair("12x12",2));
	gfntMap.insert(make_pair("16x12",3));
	int theDog;
	int bytTextUni,lonTextUniSetOff;
	string binLineTemp;
	char Dot;///////////////////////////////////////////////////小心，这可能是个坑。。
	int bx,by;
	ClassMessage objClassMessage;
	//map<string,int>::iterator iterTemp=fntMap.begin();
	//iterTemp=fntMap.find(strFont);
	//int caseN=iterTemp->second;
	switch(gfntMap[tempfont])
	{
		case 0://5x5.fnt
			theDog=0;//标记位
			if (tempBWDy)
			{
			} 
			else
			{
				for (int i=0;i<tempsetTEXT.length();i++)
				{
					wchar_t strTempText=tempsetTEXT[i];
					bytTextUni=(int)strTempText;
					lonTextUniSetOff=bytTextUni*7+64;
					bool objRead=objClassMessage.readBin("Font\\5x5.fnt",lonTextUniSetOff,objbytTex5x5Line,7);
					if (!objRead)
					{
						for (int r=0;r<7;r++)
						{
							if (r==6)
							{
								objbytTex5x5Line[r]=6;
							} 
							else
							{
								objbytTex5x5Line[r]=0;
							}

						}
					}
					switch(objbytTex5x5Line[6])
					{
					case 6:
						for (int k=0;k<6;k++)
						{
							binLineTemp="0000000"+objClassMessage.DEC_to_BIN(objbytTex5x5Line[k]);
							binLineTemp=binLineTemp.substr(binLineTemp.length()-5,5);
							for (int p =0;p<5;p++)
							{
								Dot=binLineTemp[p];
								bx=theDog+tempRowStart+k*tempSW;

								if (tempBWDx)
								{
									by=tempLineStart+p;
								} 
								else
								{
									by=5-p+tempLineStart-1;
								}
								switch(Dot)
								{
								case '0':
									if(tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;
										}
									}
									break;
								case '1':
									if(!tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;
										}
									}
									break;
								default:
									if(!tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;
										}
									}
								}	
							}
						}//画列结束；

						if(intSS>0&&tempNEG)
						{
							for (int m=0;m<tempSS;m++)
							{
								for(int p=0;p<5;p++)
								{
									bx=theDog+tempRowStart+6*tempSW+m;
									if (tempBWDx)
									{
										by=5-p+tempLineStart-1;
									} 
									else
									{
										by=tempLineStart+p;
									}
										boDotMes[by][bx]=true;
								}
							}
						}
						theDog=theDog+6*tempSW+tempSS;
						break;
					case 5:
						break;
					case 4:
						break;
					case 3:
						break;
						//default:

					}
				}
			}
			break;
		case 1:
			theDog=0;//标记位
			if (tempBWDy)
			{
			} 
			else
			{
				for (int i=0;i<tempsetTEXT.length();i++)
				{
					wchar_t strTempText=tempsetTEXT[i];
					bytTextUni=(int)strTempText;
					lonTextUniSetOff=bytTextUni*8+64;

					bool objRead=objClassMessage.readBin("Font\\7x5.fnt",lonTextUniSetOff,objbytTex7x5Line,8);
					if (!objRead)
					{
						for (int r=0;r<8;r++)
						{
							if (r==7)
							{
								objbytTex7x5Line[r]=6;
							} 
							else
							{
								objbytTex7x5Line[r]=0;
							}

						}
					}
					switch(objbytTex7x5Line[7])
					{
					case 7:
						break;
					case 6:
						for (int k=0;k<6;k++)
						{
							binLineTemp="0000000"+objClassMessage.DEC_to_BIN(objbytTex7x5Line[k]);
							binLineTemp=binLineTemp.substr(binLineTemp.length()-7,7);
							for (int p =0;p<7;p++)
							{
								Dot=binLineTemp[p];
								bx=(theDog+tempRowStart)+k*tempSW;
									
								if (tempBWDx)
								{
									
									by=(tempLineStart+p);
								} 
								else
								{
										
									by=(7-p+tempLineStart-1);

								}
								switch(Dot)
								{
								case '0':
									if(tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;
										}
									}
									break;
								case '1':
									if(!tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;
										}
									}
									break;
								default:
									if(!tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;

										}
									}
								}	
							}
						}//画列结束；

						if(intSS>0&&tempNEG)
						{
							for (int m=0;m<tempSS;m++)
							{
								for(int p=0;p<7;p++)
								{
									bx=(theDog+tempRowStart)+6*tempSW+m;
									
									if (tempBWDx)
									{
											
										by=7-p+tempLineStart-1;
									} 
									else
									{
											
										by=tempLineStart+p;
									}
									boDotMes[by][bx]=true;
								}
							}
						}
						theDog=theDog+6*tempSW+tempSS;
						break;
					case 5:
						break;
					case 4:
						break;
					case 3:
						break;
						//default:

					}
				}
			}
			break;
	}
}

vector<BYTE> ClassMessage::DotToByte(int tempintDotRowStart, int tempintDotRowEnd)
{
	vector<BYTE> bytTempVec;
	if (boReverse)
	{
	} 
	else
	{
		if (boInverse)
		{
		} 
		else
		{
			switch(Matrix)
			{
				case 9:
					if (Pixel<8)
					{
						bytRowByteMul=1;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<Pixel;j++)
							{
								bytTempVec[i]=bytTempVec[i]+getByteFromDot(boDotMes[j][i],j);
							}
						}
					}
					else if(Pixel>7)
					{
						bytRowByteMul=2;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[2*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<Pixel;j++)
							{
								bytTempVec[2*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
						}
					}
					break;
				case 12:
					if (Pixel<8)
					{
						bytRowByteMul=1;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<Pixel;j++)
							{
								bytTempVec[i]=bytTempVec[i]+getByteFromDot(boDotMes[j][i],j);
							}
						}
					}
					else if(Pixel>7)
					{
						bytRowByteMul=2;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[2*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<Pixel;j++)
							{
								bytTempVec[2*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
						}
					}
					break;
				case 14:
					if (Pixel<8)
					{
						bytRowByteMul=2;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							bytTempVec[2*i]=getByteFromDot(boDotMes[0][i],0)+getByteFromDot(boDotMes[8][i],1)+getByteFromDot(boDotMes[1][i],2)+getByteFromDot(boDotMes[9][i],3)
								+getByteFromDot(boDotMes[2][i],4)+getByteFromDot(boDotMes[10][i],5)+getByteFromDot(boDotMes[3][i],6)+getByteFromDot(boDotMes[11][i],7);

							bytTempVec.push_back(0);
							bytTempVec[2*i+1]=getByteFromDot(boDotMes[4][i],0)+getByteFromDot(boDotMes[12][i],1)+getByteFromDot(boDotMes[5][i],2)+getByteFromDot(boDotMes[13][i],3)
								+getByteFromDot(boDotMes[6][i],4)+getByteFromDot(boDotMes[14][i],5);
						}
					}
					break;
				case 19:
					if (Pixel<8)
					{
						bytRowByteMul=1;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<Pixel;j++)
							{
								bytTempVec[i]=bytTempVec[i]+getByteFromDot(boDotMes[j][i],j);
							}
						}
					}
					else if(Pixel>7&&Pixel<16)
					{
						bytRowByteMul=2;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[2*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<Pixel;j++)
							{
								bytTempVec[2*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
						}
					}
					else if(Pixel>15)
					{
						bytRowByteMul=3;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[3*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<16;j++)
							{
								bytTempVec[3*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
							bytTempVec.push_back(0);
							for (int j=16;j<Pixel;j++)
							{
								bytTempVec[3*i+2]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-16);
							}
						}
					}
					break;
				case 25:
					if (Pixel<8)
					{
						bytRowByteMul=1;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<Pixel;j++)
							{
								bytTempVec[i]=bytTempVec[i]+getByteFromDot(boDotMes[j][i],j);
							}
						}
					}
					else if(Pixel>7&&Pixel<16)
					{
						bytRowByteMul=2;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[2*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<Pixel;j++)
							{
								bytTempVec[2*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
						}
					}
					else if(Pixel>15&&Pixel<24)
					{
						bytRowByteMul=3;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[3*i]=bytTempVec[3*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<16;j++)
							{
								bytTempVec[3*i+1]=bytTempVec[3*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
							bytTempVec.push_back(0);
							for (int j=16;j<Pixel;j++)
							{
								bytTempVec[3*i+2]=bytTempVec[3*i+2]+getByteFromDot(boDotMes[j][i],j-16);
							}
						}
					}
					else if(Pixel>24)
					{
						bytRowByteMul=4;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[4*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<16;j++)
							{
								bytTempVec[4*i+1]=bytTempVec[4*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
							bytTempVec.push_back(0);
							for (int j=16;j<Pixel;j++)
							{
								bytTempVec[4*i+2]=bytTempVec[4*i+2]+getByteFromDot(boDotMes[j][i],j-16);
							}
							bytTempVec.push_back(0);
							for (int j=24;j<Pixel;j++)
							{
								bytTempVec[4*i+3]=bytTempVec[4*i+3]+getByteFromDot(boDotMes[j][i],j-24);
							}
						}
					}
					break;
			}
		}
	}
	return bytTempVec;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
OBJ_Control::OBJ_Control(void)
{
	this->strDuan="OBJ";
	this->intSW=1;
	this->intSS=0;
	this->intX=0;
	this->intY=0;
	this->booNEG=false;
	this->booBWDx=false;
	this->booBWDy=false;
	this->strFont="7x5";
	this->strText="Text";
	this->strETimeOffSet="OFF";
	this->intTimeOffSet=1;
	this->intSerialFirstLimit=1;
	this->intSerialSecondLimit=999999999;
    this->intSerialStartValue=1;
	this->intSerialStep=1;
	this->intSerialRepeat=1;
	this->intSerialDigits=9;
	this->strSerialCounter=0;
	this->bytSerialFormat=0;
	this->intLineSize=0;
	this->intRowSize=0;
	this->intLineStart=0;
    this->intRowStart=0;
	this->intqrcodeQuietZone=0;
	this->booFocus=true;

}

OBJ_Control::~OBJ_Control(void){}

void OBJ_Control::DrawFrame(CDC * pDC)
{
	QPen cPen;//QPainter painter();
	if (this->booFocus)
	{
		cPen.setStyle(Qt::SolidLine);
		cPen.setWidth(2);
		cPen.setColor(Qt::green);
		cPen.setCapStyle(Qt::SquareCap);
		cPen.setJoinStyle(Qt::BevelJoin);
	}
	else
	{
		cPen.setStyle(Qt::SolidLine);
		cPen.setWidth(1);
		cPen.setColor(Qt::blue);
		cPen.setCapStyle(Qt::SquareCap);
		cPen.setJoinStyle(Qt::BevelJoin);
	}
	pDC->setPen(cPen);
		
	//下
	pDC->drawLine(intRowStart*5,161-intLineStart*5-1,(intRowStart+intRowSize)*5,161-intLineStart*5-1);
	//上
	pDC->drawLine(intRowStart*5,161-(intLineSize+intLineStart)*5-1,(intRowStart+intRowSize)*5,161-(intLineSize+intLineStart)*5-1);
	//左
	pDC->drawLine(intRowStart*5,161-intLineStart*5-1,intRowStart*5,161-(intLineSize+intLineStart)*5-1);
	//右
	pDC->drawLine((intRowStart+intRowSize)*5,161-intLineStart*5-1,(intRowStart+intRowSize)*5,161-(intLineSize+intLineStart)*5-1);
}

void OBJ_Control::DrawDot(CDC* pDC)
{
 	CBrush cbrushB(QColor(0,0,0));//黑笔
	cbrushB.setStyle(Qt::SolidPattern);
	CBrush cbrushW(QColor(255,255,255));//白笔
	cbrushW.setStyle(Qt::SolidPattern);
		 
	if (strType2=="logo"||strType2=="qrcode"||strType2=="datamatrix")
	{
		int bmpWidth,bmpHeight;
		bmpWidth=intRowSize;
		bmpHeight=intLineSize;
		if (booBWDy)
		{
			for (int i=0;i<bmpWidth;i++)
			{
				for(int j=0;j<bmpHeight;j++)
				{
					if (booBWDx)
					{
						if (booNEG)
						{	
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushW);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,161-(bmpHeight-j)*5-1,5,5); //width和height先写死
									//CRect rect((bmpWidth-i-1)*5,161-(bmpHeight-j)*5-1,(bmpWidth-i)*5,161-(bmpHeight-j-1)*5-1);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushB);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,161-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						} 
						else
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushB);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,161-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushW);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,161-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						}
					} 
					else
					{
						if (booNEG)
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushW);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,161-(j+1)*5-1,5,5);
									//CRect rect((bmpWidth-i-1)*5,161-(j+1)*5-1,(bmpWidth-i)*5,161-j*5-1);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushB);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,161-(j+1)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						} 
						else
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushB);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,161-(j+1)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushW);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,161-(j+1)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						}
					}
				}
			}
		} 
		else
		{
			for (int i=0;i<bmpWidth;i++)
			{
				for(int j=0;j<bmpHeight;j++)
				{
					if (booBWDx)
					{
						if (booNEG)
						{

							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushW);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,161-(bmpHeight-j)*5-1,5,5);
									//CRect rect(i*5,161-(bmpHeight-j)*5-1,(i+1)*5,161-(bmpHeight-j-1)*5-1);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushB);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,161-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						} 
						else
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushB);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,161-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushW);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,161-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						}
					} 
					else
					{
						if (booNEG)
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushW);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,161-(j+1)*5-1,5,5);
								    //CRect rect(i*5,161-(j+1)*5-1,(i+1)*5,161-j*5-1);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushB);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,161-(j+1)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						} 
						else
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushB);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((intRowStart+i)*5,161-(intLineStart+j+1)*5-1,5,5);
									//CRect rect((intRowStart+i)*5,161-(intLineStart+j+1)*5-1,(intRowStart+i+1)*5,161-(intLineStart+j)*5-1);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushW);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,161-(j+1)*5-1,5,5);
									//CRect rect(i*5,161-(j+1)*5-1,(i+1)*5,161-j*5-1);
									pDC->Ellipse(rect);
								}
							}
						}
					}
				}
			}
		}
	} 
	else
	{
		fntMap.clear();
		fntMap.insert(make_pair("5x5",0));
		fntMap.insert(make_pair("7x5",1));
		fntMap.insert(make_pair("12x12",2));
		fntMap.insert(make_pair("16x12",3));
		int theDog;
		int bytTextUni,lonTextUniSetOff;
		string binLineTemp;
		char Dot;///////////////////////////////////////////////////小心，这可能是个坑。。
		int x1,y1,x2,y2;
		ClassMessage objClassMessage;
		//map<string,int>::iterator iterTemp=fntMap.begin();
		//iterTemp=fntMap.find(strFont);
		//int caseN=iterTemp->second;
		switch(fntMap[strFont])
		{
		case 0://5x5.fnt
			theDog=0;//标记位
			if (booBWDy)
			{
			} 
			else
			{
				for (int i=0;i<strText.length();i++)
				{
					wchar_t strTempText=strText[i];
					bytTextUni=(int)strTempText;
					lonTextUniSetOff=bytTextUni*7+64;
					bool objRead=objClassMessage.readBin("Font\\5x5.fnt",lonTextUniSetOff,objbytTex5x5Line,7);
					if (!objRead)
					{
						for (int r=0;r<7;r++)
						{
							if (r==6)
							{
								objbytTex5x5Line[r]=6;
							} 
							else
							{
								objbytTex5x5Line[r]=0;
							}
								
						}
					}
					switch(objbytTex5x5Line[6])
					{
					case 6:
						for (int k=0;k<6;k++)
						{
							binLineTemp="0000000"+objClassMessage.DEC_to_BIN(objbytTex5x5Line[k]);
							binLineTemp=binLineTemp.substr(binLineTemp.length()-5,5);
							for (int p =0;p<5;p++)
							{
								Dot=binLineTemp[p];
								x1=5*(theDog+intRowStart)+5*k*intSW;
								x2=5*(theDog+intRowStart+1)+5*k*intSW;
								if (booBWDx)
								{
									y1=161-5*(intLineStart+p+1)-1;
									y2=161-5*(intLineStart+p)-1;
								} 
								else
								{
									y1=161-5*(5-p+intLineStart)-1;
									y2=161-5*(5-p+intLineStart-1)-1;

								}
								switch(Dot)
								{
								case '0':
									if(booNEG)
									{
										for (int s=0;s<intSW;s++)
										{
											pDC->setBrush(cbrushB);
											CRect rect(x1,y1,x2-x1,y2-y1);
											pDC->Ellipse(rect);
												
										}
									}
									break;
								case '1':
									if(!booNEG)
									{
										for (int s=0;s<intSW;s++)
										{
											pDC->setBrush(cbrushB);

											CRect rect(x1,y1,x2-x1,y2-y1);
											pDC->Ellipse(rect);

										}
									}
									break;
								default:
									if(!booNEG)
									{
										for (int s=0;s<intSW;s++)
										{
											pDC->setBrush(cbrushB);

											CRect rect(x1,y1,x2-x1,y2-y1);
											pDC->Ellipse(rect);

										}
									}
								}	
							}
						}//画列结束；

						if(intSS>0&&booNEG)
						{
							for (int m=0;m<intSS;m++)
							{
								for(int p=0;p<5;p++)
								{
									x1=5*(theDog+intRowStart)+5*6*intSW+5*m;
									x2=5*(theDog+intRowStart+1)+5*6*intSW+5*m;
									if (booBWDx)
									{
										y1=161-5*(5-p+intLineStart)-1;
										y2=161-5*(5-p+intLineStart-1)-1;
									} 
									else
									{
										y1=161-5*(intLineStart+p+1)-1;
										y2=161-5*(intLineStart+p)-1;
									}
									pDC->setBrush(cbrushB);
									CRect rect(x1,y1,x2-x1,y2-y1);
									pDC->Ellipse(rect);
								}
							}
						}
						theDog=theDog+6*intSW+intSS;
						break;
					case 5:
						break;
					case 4:
						break;
					case 3:
						break;
					//default:
							
					}
				}
			}
			break;
		case 1:
			theDog=0;//标记位
			if (booBWDy)
			{
			} 
			else
			{
				for (int i=0;i<strText.length();i++)
				{
					wchar_t strTempText=strText[i];
					bytTextUni=(int)strTempText;
					lonTextUniSetOff=bytTextUni*8+64;

					bool objRead=objClassMessage.readBin("Font\\7x5.fnt",lonTextUniSetOff,objbytTex7x5Line,8);
					if (!objRead)
					{
						for (int r=0;r<8;r++)
						{
							if (r==7)
							{
								objbytTex7x5Line[r]=6;
							} 
							else
							{
								objbytTex7x5Line[r]=0;
							}

						}
					}
					switch(objbytTex7x5Line[7])
					{
					case 7:
						break;
					case 6:
						for (int k=0;k<6;k++)
						{
							binLineTemp="0000000"+objClassMessage.DEC_to_BIN(objbytTex7x5Line[k]);
							binLineTemp=binLineTemp.substr(binLineTemp.length()-7,7);
							for (int p =0;p<7;p++)
							{
								Dot=binLineTemp[p];
								x1=5*(theDog+intRowStart)+5*k*intSW;
								x2=5*(theDog+intRowStart+1)+5*k*intSW;
								if (booBWDx)
								{
									y1=161-5*(intLineStart+p+1)-1;
									y2=161-5*(intLineStart+p)-1;
								} 
								else
								{
									y1=161-5*(7-p+intLineStart)-1;
									y2=161-5*(7-p+intLineStart-1)-1;

								}
								switch(Dot)
								{
								case '0':
									if(booNEG)
									{
										for (int s=0;s<intSW;s++)
										{
											pDC->setBrush(cbrushB);

											CRect rect(x1,y1,x2-x1,y2-y1);
											pDC->Ellipse(rect);

										}
									}
									break;
								case '1':
									if(!booNEG)
									{
										for (int s=0;s<intSW;s++)
										{
											pDC->setBrush(cbrushB);

											CRect rect(x1,y1,x2-x1,y2-y1);
											pDC->Ellipse(rect);

										}
									}
									break;
								default:
									if(!booNEG)
									{
										for (int s=0;s<intSW;s++)
										{
											pDC->setBrush(cbrushB);

											CRect rect(x1,y1,x2-x1,y2-y1);
											pDC->Ellipse(rect);

										}
									}
								}	
							}
						}//画列结束；

						if(intSS>0&&booNEG)
						{
							for (int m=0;m<intSS;m++)
							{
								for(int p=0;p<7;p++)
								{
									x1=5*(theDog+intRowStart)+5*6*intSW+5*m;
									x2=5*(theDog+intRowStart+1)+5*6*intSW+5*m;
									if (booBWDx)
									{
										y1=161-5*(5-p+intLineStart)-1;
										y2=161-5*(5-p+intLineStart-1)-1;
									} 
									else
									{
										y1=161-5*(intLineStart+p+1)-1;
										y2=161-5*(intLineStart+p)-1;
									}
									pDC->setBrush(cbrushB);
									CRect rect(x1,y1,x2-x1,y2-y1);
									pDC->Ellipse(rect);
								}
							}
						}
						theDog=theDog+6*intSW+intSS;
						break;
					case 5:
						break;
					case 4:
						break;
					case 3:
						break;
						//default:

					}
				}
			}
			break;
		}
	}




	pDC->setBrush(cbrushB); //载入笔刷
	//CRect rect(col*nStepPixels,row*nStepPixels,(col+1)*nStepPixels,(row+1)*nStepPixels);
	//pDC->Ellipse(&rect); 

	//pDC->SelectObject(pBrush); //恢复笔刷
//	cbrushB.DeleteObject();
//	pBrush->DeleteObject();*/
	DrawFrame(pDC);
		
}
	
void OBJ_Control::ReadBmp(char* strFileName)
{
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
		 
	/*
	QString csInfo("");//Storage Card\\User\\Logo\\1.bmp
	//csInfo.Format(_T("%s", strFileName));
	csInfo = QString(strFileName);
	HBITMAP hBitmap = (HBITMAP)::SHLoadDIBitmap(csInfo);

	BITMAP bmpObj = {0};
	if (   ::GetObject(hBitmap, sizeof(bmpObj), &bmpObj) == 0|| bmpObj.bmWidth <= 0|| bmpObj.bmHeight <= 0)
	{
		return ;
	}
		
	CDC memDC ;
	memDC.CreateCompatibleDC(NULL) ;//创建内存DC 
	CBitmap bitmap ;
	bitmap.Attach(hBitmap) ;
	memDC.SelectObject(&bitmap) ;
	//	pDC->BitBlt(0,0,25,25,&memDC,0,0,SRCCOPY);//显示

	intRowSize=bmpObj.bmWidth;
	intLineSize=bmpObj.bmHeight;
	//	CSize myCSize=memDC.GetViewportExt();

	for (int x=0;x<intRowSize;x++)
	{
		for (int y=0;y<intLineSize;y++)
		{
			COLORREF pixColor=memDC.GetPixel(x,y);
			BYTE red = GetRValue(pixColor);
			BYTE green = GetGValue(pixColor);
			BYTE blue = GetBValue(pixColor);
			if (red==255&&green==255&&blue==255)
			{
				boDotBmp[x][intLineSize-y-1]=false;
			}
			else
			{
				boDotBmp[x][intLineSize-y-1]=true;
			}
		}
	}*/
		 
}


