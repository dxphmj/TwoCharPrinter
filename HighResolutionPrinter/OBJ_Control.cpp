
#include "ClassMessage.h"
#include "sstream"
#include <fstream>
#include <stdio.h>
#include "xml\tinyxml.h"
#include <QPainter>
#include <io.h>
#include "QFileInfo"
#include <Windows.h>
#include "backend\zint.h"
#include "wordStock\\GetHZinfo.h"

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
	this->booETimeOffSet=0;
	this->intTimeOffSet=1;
	this->intSerialFirstLimit=1;
	this->intSerialSecondLimit=999999999;
    this->intSerialStartValue=1;
	this->intSerialStep=1;
	this->intSerialRepeat=1;
	this->intSerialDigits=9;
	this->intSerialCounter=0;
	this->bytSerialFormat=0;
	this->intLineSize=0;
	this->intRowSize=0;
	this->intLineStart=0;
    this->intRowStart=0;
	this->intqrcodeQuietZone=0;
	this->booFocus = true;

	m_nPicWidth = 241;
}

OBJ_Control::~OBJ_Control(void){}

void OBJ_Control::DrawFrame(CDC * pDC)
{
	QPen cPen;//QPainter painter();
	if (this->booFocus)
	{
		cPen.setStyle(Qt::SolidLine);
		cPen.setWidth(3);
		cPen.setColor(Qt::green);
		cPen.setCapStyle(Qt::SquareCap);
		cPen.setJoinStyle(Qt::BevelJoin);
	}
	else
	{
		cPen.setStyle(Qt::SolidLine);
		cPen.setWidth(3);
		cPen.setColor(Qt::blue);
		cPen.setCapStyle(Qt::SquareCap);
		cPen.setJoinStyle(Qt::BevelJoin);
	}
	pDC->setPen(cPen);
		
	//下
	pDC->drawLine(intRowStart*5,241-intLineStart*5-1,(intRowStart+intRowSize)*5,241-intLineStart*5-1);
	//上
	pDC->drawLine(intRowStart*5,241-(intLineSize+intLineStart)*5-1,(intRowStart+intRowSize)*5,241-(intLineSize+intLineStart)*5-1);
	//左
	pDC->drawLine(intRowStart*5,241-intLineStart*5-1,intRowStart*5,241-(intLineSize+intLineStart)*5-1);
	//右
	pDC->drawLine((intRowStart+intRowSize)*5,241-intLineStart*5-1,(intRowStart+intRowSize)*5,241-(intLineSize+intLineStart)*5-1);
}

wstring stringToWstring(const string& str)
{
	setlocale(LC_ALL, "chs"); 

	const char* _Source = str.c_str();
	size_t _Dsize = str.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest,_Source,_Dsize);
	wstring result = _Dest;
	delete []_Dest;

	setlocale(LC_ALL, "C");

	return result;
}

bool OBJ_Control::readBin(string FontName,int offset,char *arr, int DataLen)
{
	ifstream file;
	string path="Font\\";   
	path += FontName;
	file.open(path.c_str(),ios::binary);
	file.seekg(offset,ios::beg);
	bool bFlag = file.read(arr,DataLen);
	return bFlag;
}

string OBJ_Control::to_String(int n)
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

string OBJ_Control::DEC_to_BIN(long long Dec)
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

long long OBJ_Control::BIN_to_DEC(string Bin)
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

void OBJ_Control::DrawLogoQRcodeDM(CDC* pDC,vector<vector<bool>>& boDotMes)
{
	CBrush cbrushB(QColor(0,0,0));//黑笔
	cbrushB.setStyle(Qt::SolidPattern);

	int bmpWidth,bmpHeight;
	bmpWidth = intRowSize;	 
	bmpHeight = intLineSize;
	CRect rect;
	if(pDC)	 
		pDC->setBrush(cbrushB);		

	for(int i = 0;i < bmpWidth; i++)
	{
		for(int j = 0; j < bmpHeight; j++)
		{
			if(!boDotBmp[j][i]) continue;			 
				 
			for(int sw = 0; sw < intSW; sw++)
			{
				if (booNEG)
				{
					if (booBWDx)
					{
						if(booBWDy)
							rect = CRect((intRowStart+bmpWidth-i-1)*5+1,m_nPicWidth-(intLineStart+bmpHeight-j)*5-1+1,5,5);
						else
							rect = CRect((intRowStart+i)*5+1,m_nPicWidth-(intLineStart+bmpHeight-j)*5-1+1,5,5);
					}
					else{
						if(booBWDy)
							rect = CRect((intRowStart+bmpWidth-i-1)*5+1,m_nPicWidth-(intLineStart+j+1)*5-1+1,5,5);
						else
							rect = CRect((intRowStart+i)*5+1,m_nPicWidth-(intLineStart+j+1)*5-1+1,5,5);
					}
				}
				else
				{
					if (booBWDx)
					{
						if(booBWDy)
							rect = CRect((intRowStart+bmpWidth-i-1)*5+1,m_nPicWidth-(intLineStart+bmpHeight-j)*5+1-1,5,5);
						else
							rect = CRect((intRowStart+i)*5+1,m_nPicWidth-(intLineStart+bmpHeight-j)*5-1+1,5,5);
					}
					else
					{
						if(booBWDy)
							rect = CRect((intRowStart+bmpWidth-i-1)*5+1,m_nPicWidth-(intLineStart+j+1)*5-1+1,5,5);
						else
							rect = CRect((intRowStart+i)*5+1,m_nPicWidth-(intLineStart+j+1)*5-1+1,5,5);
					}
				}
				if(pDC)
					pDC->Ellipse(rect);
				else
				{
					boDotMes[(m_nPicWidth-1-rect.bottom())/5][(rect.left()-1)/5] = true;
				}
			}
		}		 		
	}
	//if(pDC)
	//	pDC->SelectObject(pBrush); //恢复笔刷
	//cbrushB.DeleteObject();
}

void OBJ_Control::Draw5x5_7x5Text(CDC* pDC,int nFontRow,int nFontCol,int nBytesOneWord,vector<vector<bool>>& boDotMes)
{
	char objbytTex5x5Line[29];
	 
	CBrush cbrushB(QColor(0,0,0));//黑笔
	cbrushB.setStyle(Qt::SolidPattern);
	if(pDC)	 
		pDC->setBrush(cbrushB);		 

	int theDog;
	int bytTextUni,lonTextUniSetOff;
	string binLineTemp;
	char Dot;
	int x1,y1,x2,y2;
	theDog=0;//标记位	

	wstring strWText=stringToWstring(strText);
	for (int i=0;i<strWText.length();i++)
	{
		wchar_t strTempText;
		if (booBWDy)
			strTempText=strWText[strWText.length()-i-1];
		else
			strTempText=strWText[i];
		bytTextUni=(int)strTempText;
		lonTextUniSetOff=bytTextUni*nBytesOneWord+64;
		string strFileName;
		char tmp[256]={0};
		sprintf(tmp, "%dx%d.fnt", nFontRow,nFontCol);
		strFileName.append(tmp);

		bool objRead = readBin(strFileName,lonTextUniSetOff,objbytTex5x5Line,nBytesOneWord);
		if (!objRead)
		{
			for (int r=0;r<nBytesOneWord;r++)
			{
				if (r==nBytesOneWord-1)
					objbytTex5x5Line[r]=6;
				else
					objbytTex5x5Line[r]=0;
			}
		}
		if(intSS > 0 && booNEG)
		{
			for (int m=0;m<intSS;m++)
			{
				for(int p=0;p<nFontRow;p++)
				{

					if (booBWDy){
						x1=5*(theDog+intRowStart)+5*m;
						x2=5*(theDog+intRowStart+1)+5*m;
					} 
					else{
						x1=5*(theDog+intRowStart)+5*objbytTex5x5Line[nBytesOneWord-1]*intSW+5*m;
						x2=5*(theDog+intRowStart+1)+5*objbytTex5x5Line[nBytesOneWord-1]*intSW+5*m;
					}
					
					if (booBWDx)
					{
						y1=m_nPicWidth-5*(nFontRow-p+intLineStart)-1;
						y2=m_nPicWidth-5*(nFontRow-p+intLineStart-1)-1;
					} 
					else
					{
						y1=m_nPicWidth-5*(intLineStart+p+1)-1;
						y2=m_nPicWidth-5*(intLineStart+p)-1;
					}
					
					CRect rect(x1+1,y1+1,5,5);
					if(pDC)
						pDC->Ellipse(rect);
					else
						boDotMes[(m_nPicWidth-1-y2)/5][x1/5]=true;
				}
			}
		}

		for (int k=0;k<objbytTex5x5Line[nBytesOneWord-1];k++)
		{
			if (booBWDy)
				binLineTemp = "0000000"+ DEC_to_BIN((byte)objbytTex5x5Line[objbytTex5x5Line[nBytesOneWord-1]-1-k]);
			else
				binLineTemp = "0000000" + DEC_to_BIN((byte)objbytTex5x5Line[k]);

			binLineTemp=binLineTemp.substr(binLineTemp.length()-nFontRow,nFontRow);
			for (int p =0;p<nFontRow;p++)
			{
				Dot=binLineTemp[p];
				if (booBWDy){
					x1=5*(theDog+intRowStart)+5*k*intSW+5*intSS;
					x2=5*(theDog+intRowStart+1)+5*k*intSW+5*intSS;
				}
				else{
					x1=5*(theDog+intRowStart)+5*k*intSW;
					x2=5*(theDog+intRowStart+1)+5*k*intSW;
				}
				if (booBWDx)
				{
					y1=m_nPicWidth-5*(intLineStart+p+1)-1;
					y2=m_nPicWidth-5*(intLineStart+p)-1;
				} 
				else
				{
					y1=m_nPicWidth-5*(nFontRow-p+intLineStart)-1;
					y2=m_nPicWidth-5*(nFontRow-p+intLineStart-1)-1;

				}
				switch(Dot)
				{
				case '0':
					if(booNEG)
					{
						for (int s=0;s<intSW;s++)
						{							 
							CRect rect(x1+5*s+1,y1+1,5,5);
							if(pDC)
								pDC->Ellipse(rect);
							else
								boDotMes[(m_nPicWidth-1-y2)/5][x1/5+s]=true;
						}
					}
					break;
				case '1':
					if(!booNEG)
					{
						for (int s=0;s<intSW;s++)
						{
							CRect rect(x1+5*s+1,y1+1,5,5);
							if(pDC)
								pDC->Ellipse(rect);
							else
								boDotMes[(m_nPicWidth-1-y2)/5][x1/5+s]=true;
						}
					}
					break;
				default:
					if(!booNEG)
					{
						for (int s=0;s<intSW;s++)
						{
							CRect rect(x1+5*s+1,y1+1,5,5);
							if(pDC)
								pDC->Ellipse(rect);
							else
								boDotMes[(m_nPicWidth-1-y2)/5][x1/5+s]=true;
						}
					}
				}	
			}
		}//画列结束；

		theDog = theDog+objbytTex5x5Line[nBytesOneWord-1]*intSW+intSS;
	}
	
	intRowSize = theDog;	
	/*if(pDC)
		pDC->SelectObject(&pBrush);  		 
	cbrushB.DeleteObject();	*/ 	 
}

void OBJ_Control::Draw12x12Text(CDC* pDC,vector<vector<bool>>& boDotMes)
{
 	char objbytTex12x12Line[25];

	CBrush cbrushB(QColor(0,0,0));//黑笔
	cbrushB.setStyle(Qt::SolidPattern);

	int theDog;
	int bytTextUni,lonTextUniSetOff;
	string binLineTemp;
	char Dot;
	int x1,y1,x2,y2;
	theDog=0;
	if(pDC)	 
		pDC->setBrush(cbrushB);		 
	 
	wstring strWText=stringToWstring(strText);
	for (int i=0;i<strWText.length();i++)
	{
		wchar_t strTempText;
		if(booBWDy)
		{
			strTempText=strWText[strWText.length()-i-1];
		}
		else{
			strTempText=strWText[i];
		}
		bytTextUni=(int)strTempText;
		lonTextUniSetOff=bytTextUni*25+64;
		bool objRead = readBin("12x12.fnt",lonTextUniSetOff,objbytTex12x12Line,25);
		if (!objRead)
		{
			for (int r=0;r<25;r++)
			{
				if (r==24)
					objbytTex12x12Line[r]=12;
				else
					objbytTex12x12Line[r]=0;
			}
		}

		if(intSS>0&&booNEG)
		{
			for (int m=0;m<intSS;m++)
			{
				for(int p=0;p<12;p++)
				{

					if (booBWDy)
					{
						x1=5*(theDog+intRowStart)+5*m;
						x2=5*(theDog+intRowStart+1)+5*m;
					}
					else
					{
						x1=5*(theDog+intRowStart)+5*objbytTex12x12Line[24]*intSW+5*m;
						x2=5*(theDog+intRowStart+1)+5*objbytTex12x12Line[24]*intSW+5*m;
					}
					if (booBWDx)
					{
						y1=m_nPicWidth-5*(12-p+intLineStart)-1;
						y2=m_nPicWidth-5*(12-p+intLineStart-1)-1;
					} 
					else
					{
						y1=m_nPicWidth-5*(intLineStart+p+1)-1;
						y2=m_nPicWidth-5*(intLineStart+p)-1;
					}
					CRect rect(x1+1,y1+1,5,5);
					if(pDC)
						pDC->Ellipse(rect);
					else
						boDotMes[(m_nPicWidth-1-y2)/5][x1/5]=true;
				}
			}
		}

		for (int k=0;k<objbytTex12x12Line[24];k++)
		{

			string binLineTemp1,binLineTemp0;
			if (booBWDy)
			{
				binLineTemp1 = "0000" + DEC_to_BIN((byte)objbytTex12x12Line[(objbytTex12x12Line[24]*2)-1-k*2]);
				binLineTemp1 = binLineTemp1.substr(binLineTemp1.length()-4,4);
				binLineTemp0 = "00000000" + DEC_to_BIN((byte)objbytTex12x12Line[(objbytTex12x12Line[24]*2)-1-k*2-1]);
				binLineTemp0 = binLineTemp0.substr(binLineTemp0.length()-8,8);
			}
			else{
				binLineTemp1 = "0000" + DEC_to_BIN((byte)objbytTex12x12Line[k*2+1]);
				binLineTemp1 = binLineTemp1.substr(binLineTemp1.length()-4,4);
				binLineTemp0 = "00000000" + DEC_to_BIN((byte)objbytTex12x12Line[k*2]);
				binLineTemp0 = binLineTemp0.substr(binLineTemp0.length()-8,8);
			}
			binLineTemp = binLineTemp1+binLineTemp0;
			for (int p =0;p<12;p++)
			{
				Dot=binLineTemp[p];
				if (booBWDy)
				{
					x1=5*(theDog+intRowStart)+5*k*intSW+5*intSS;
					x2=5*(theDog+intRowStart+1)+5*k*intSW+5*intSS;
				}
				else{
					x1=5*(theDog+intRowStart)+5*k*intSW;
					x2=5*(theDog+intRowStart+1)+5*k*intSW;
				}
				if (booBWDx)
				{
					y1=m_nPicWidth-5*(intLineStart+p+1)-1;
					y2=m_nPicWidth-5*(intLineStart+p)-1;
				} 
				else
				{
					y1=m_nPicWidth-5*(12-p+intLineStart)-1;
					y2=m_nPicWidth-5*(12-p+intLineStart-1)-1;

				}
				switch(Dot)
				{
				case '0':
					if(booNEG)
					{
						for (int s=0;s<intSW;s++)
						{
							CRect rect(x1+5*s+1,y1+1,5,5);
							if(pDC)
								pDC->Ellipse(rect);
							else
								boDotMes[(m_nPicWidth-1-y2)/5][x1/5+s]=true;								 
						}
					}
					break;
				case '1':
					if(!booNEG)
					{
						for (int s=0;s<intSW;s++)
						{
							CRect rect(x1+5*s+1,y1+1,5,5);
							if(pDC)
								pDC->Ellipse(rect);
							else
								boDotMes[(m_nPicWidth-1-y2)/5][x1/5+s]=true;	
						}
					}
					break;
				default:
					if(!booNEG)
					{
						for (int s=0;s<intSW;s++)
						{							
							CRect rect(x1+5*s+1,y1+1,5,5);
							if(pDC)
								pDC->Ellipse(rect);
							else
								boDotMes[(m_nPicWidth-1-y2)/5][x1/5+s]=true;	
						}
					}
				}	
			}
		}//画列结束；

		theDog = theDog+objbytTex12x12Line[24]*intSW+intSS;	 
	}

	intRowSize = theDog;	
	//if(pDC)
	//	pDC->SelectObject(pBrush); //恢复笔刷
	//cbrushB.DeleteObject();
}

void OBJ_Control::Draw16x12Text(CDC* pDC,vector<vector<bool>>& boDotMes)
{ 
	char objbytTex16x12Line[29];

	CBrush* pBrush; //旧笔刷
	CBrush cbrushB(QColor(0,0,0));//黑笔
	cbrushB.setStyle(Qt::SolidPattern);
	CBrush cbrushW(QColor(255,255,255));//白笔
	cbrushW.setStyle(Qt::NoBrush);
 	CPen cPenInvisible(Qt::NoPen);

	int theDog;
	int bytTextUni,lonTextUniSetOff;
	string binLineTemp;
	char Dot;
	int x1,y1,x2,y2;

	if(pDC)	 
		pDC->setBrush(cbrushB);		 

	theDog=0;
	 		 
	wstring strWText=stringToWstring(strText);
	for (int i=0;i<strWText.length();i++)
	{
		wchar_t strTempText;
		if (booBWDy)
			strTempText=strWText[strWText.length()-i-1];
		else
			strTempText = strWText[i];
		bytTextUni=(int)strTempText;
		lonTextUniSetOff=bytTextUni*29+64;
		bool objRead = readBin("16x12.fnt",lonTextUniSetOff,objbytTex16x12Line,29);
		if (!objRead)
		{
			for (int r=0;r<29;r++)
			{
				if (r==28)
					objbytTex16x12Line[r]=14;
				else
					objbytTex16x12Line[r]=0;
			}
		}

		if(intSS>0&&booNEG)
		{
			for (int m=0;m<intSS;m++)
			{
				for(int p=0;p<16;p++)
				{
					if (booBWDy)
					{
						x1=5*(theDog+intRowStart)+5*m;
						x2=5*(theDog+intRowStart+1)+5*m;
					}
					else{
						x1=5*(theDog+intRowStart)+5*objbytTex16x12Line[28]*intSW+5*m;
						x2=5*(theDog+intRowStart+1)+5*objbytTex16x12Line[28]*intSW+5*m;
					}
					if (booBWDx)
					{
						y1=m_nPicWidth-5*(16-p+intLineStart)-1;
						y2=m_nPicWidth-5*(16-p+intLineStart-1)-1;
					} 
					else
					{
						y1=m_nPicWidth-5*(intLineStart+p+1)-1;
						y2=m_nPicWidth-5*(intLineStart+p)-1;
					}
 					CRect rect(x1+1,y1+1,5,5);
					if(pDC)
						pDC->Ellipse(rect);
					else
						boDotMes[(m_nPicWidth-1-y2)/5][x1/5]=true;
				}
			}
		}

		for (int k=0;k<objbytTex16x12Line[28];k++)
		{
			string binLineTemp1,binLineTemp0;
			if (booBWDy)
			{
				binLineTemp1= "00000000" + DEC_to_BIN((byte)objbytTex16x12Line[(objbytTex16x12Line[28]*2)-1-k*2]);
				binLineTemp1=binLineTemp1.substr(binLineTemp1.length()-8,8);
				binLineTemp0= "00000000" + DEC_to_BIN((byte)objbytTex16x12Line[(objbytTex16x12Line[28]*2)-1-k*2-1]);
			}
			else{
				binLineTemp1= "00000000"+ DEC_to_BIN((byte)objbytTex16x12Line[k*2+1]);
				binLineTemp1=binLineTemp1.substr(binLineTemp1.length()-8,8);
				binLineTemp0= "00000000" + DEC_to_BIN((byte)objbytTex16x12Line[k*2]);
			}
			binLineTemp0=binLineTemp0.substr(binLineTemp0.length()-8,8);
			binLineTemp=binLineTemp1+binLineTemp0;
			for (int p =0;p<16;p++)
			{
				Dot=binLineTemp[p];
				if (booBWDy)
				{
					x1=5*(theDog+intRowStart)+5*k*intSW+5*intSS;
					x2=5*(theDog+intRowStart+1)+5*k*intSW+5*intSS;
				}
				else{
					x1=5*(theDog+intRowStart)+5*k*intSW;
					x2=5*(theDog+intRowStart+1)+5*k*intSW;
				}
				if (booBWDx)
				{
					y1=161-5*(intLineStart+p+1)-1;
					y2=161-5*(intLineStart+p)-1;
				} 
				else
				{
					y1=m_nPicWidth-5*(16-p+intLineStart)-1;
					y2=m_nPicWidth-5*(16-p+intLineStart-1)-1;
				}
				switch(Dot)
				{
				case '0':
					if(booNEG)
					{
						for (int s=0;s<intSW;s++)
						{
							CRect rect(x1+5*s+1,y1+1,5,5);
							if(pDC)
								pDC->Ellipse(rect);
							else
								boDotMes[(m_nPicWidth-1-y2)/5][x1/5+s]=true;
						}
					}
					break;
				case '1':
					if(!booNEG)
					{
						for (int s=0;s<intSW;s++)
						{
							CRect rect(x1+5*s+1,y1+1,5,5);
							if(pDC)
								pDC->Ellipse(rect);
							else
								boDotMes[(m_nPicWidth-1-y2)/5][x1/5+s]=true;
						}
					}
					break;
				default:
					if(!booNEG)
					{
						for (int s=0;s<intSW;s++)
						{
							CRect rect(x1+5*s+1,y1+1,5,5);
							if(pDC)
								pDC->Ellipse(rect);
							else
								boDotMes[(m_nPicWidth-1-y2)/5][x1/5+s]=true;
						}
					}
				}	
			}
		}//画列结束；

		theDog = theDog+objbytTex16x12Line[28]*intSW+intSS;
	}
	 
	intRowSize = theDog;	
 //	if(pDC)
	//	pDC->SelectObject(pBrush); //恢复笔刷
	//cbrushB.DeleteObject();
}

void OBJ_Control::DrawTextAll(CDC* pDC,vector<vector<bool>>& boDotMes)
{	
	if(strFont == "5x5")
		Draw5x5_7x5Text(pDC,5,5,7,boDotMes);
	else if(strFont == "7x5")		 
		Draw5x5_7x5Text(pDC,7,5,8,boDotMes);
	else if(strFont == "12x12")		 
		Draw12x12Text(pDC,boDotMes);
	else if(strFont == "16x12")			 
		Draw16x12Text(pDC,boDotMes);		
}

void OBJ_Control::DrawDot(CDC* pDC)
{
	vector<vector<bool>> TempboDotMes; //临时用，没有任何意义
	if (strType2 == "logo" || strType2 == "qrcode" ||strType2 == "2Dcode" || strType2 == "datamatrix")
		DrawLogoQRcodeDM(pDC,TempboDotMes);
	else
		DrawTextAll(pDC,TempboDotMes);

	DrawFrame(pDC);
}
	
void OBJ_Control::ReadBmp(char* strFileName)
{
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	QImage pImage;
	pImage = pLoad.toImage();

	int intLineSize = pImage.width();
	int intRowSize = pImage.height();

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
			if(average < 200)
				boDotBmp[intLineSize-x-1][y] = true;
			else
				boDotBmp[intLineSize-x-1][y] = false;
		}  
	}  
}

void OBJ_Control::CreateQrcode()
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	//int batch_mode;
	//int mirror_mode;
	//char filetype[4];
	int i;
	int v;

	error_number = 0;
	
	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = 58; //临时用一下变量intQRVersion
	my_symbol->scale = 0.5;

//	v=ui->sideLenQRComBox->currentIndex();
	my_symbol->option_2 = intQRVersion;//option_1为容错等级，option_2为版本大小公式为:(V - 1) * 4 + 21；

	//batch_mode = 0;
	//mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strText.c_str(),strText.size(),rotate_angle);
	
	generated = 1;
	strType1="text";
	strType2="qrcode";		
	intLineSize=my_symbol->bitmap_height;
	intRowSize=my_symbol->bitmap_width;

	i = 0;
	int r, g, b;

	for (int row = 0; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				boDotBmp[col][my_symbol->bitmap_height-row-1] = true;//由于坐标系的原因，上下必须颠倒
			}
			else
			{
				boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	booFocus = true;
}

void OBJ_Control::Create2Dcode()
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;
	int longth;
	int derta;
	derta=1;
	longth=0;
	error_number = 0;
	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = intBarcodeType;
	int heightvalue1 = intLineSize;
	if (heightvalue1<28)
	{	
		my_symbol->height =5;	 
	} 
	else
	{
		my_symbol->height=heightvalue1-23;
	}
	/*QString zoomvalue=ui->zoomShowBarCodeLab->text();
	float zoomvalue1=zoomvalue.toFloat();*/
	my_symbol->scale =1;
	batch_mode = 0;
	mirror_mode = 0;
	
	my_symbol->whitespace_width = 9;//改变条形码两边空白区域宽度,空白区域宽度会影响条形码的宽度，只会增加条码左右两侧的空白
	//if (ui->typerimComBox->currentIndex()==0)
	//{
	//	my_symbol->output_options= 1;
	//} 
	//else if(ui->typerimComBox->currentIndex()==1)
	//{
	//	my_symbol->output_options=2;
	//}
	//else
	//{
	//	my_symbol->output_options=4;
	//}
	//有无边框之类的控制;1:无边框，2：上下两条边界线，4：四条边框
	//QString rimwide=ui->rimwideLab->text();
	//int rimwide1=rimwide.toInt();
	//my_symbol->border_width=rimwide1;//改变边框宽度           

	//int show_hrt;            //设置为1 显示文本在条码图片下面 设置为0 则不显示
	//if (ui->showNumCheckBox->isChecked())
	//{
	//	my_symbol->show_hrt=1;
	//} 

	//else  {my_symbol->show_hrt=0;}

	strcpy_s(my_symbol->outfile, "User/logo/output.bmp");
	ZBarcode_Encode(my_symbol, (unsigned char*) strCodeContent.c_str(), 0);
	generated=1;
	int error_num = ZBarcode_Print(my_symbol, 0);

	if (error_num != 0)
	//{
	//	/* some error occurred */
	//	//printf("%s\n", my_symbol->errtxt);
	//}

	ZBarcode_Delete(my_symbol);
		
	char* strFileName = "User/logo/output.bmp";
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	int nH = pLoad.height();
	QImage pImage;
	pImage = pLoad.toImage();
	pImage = pImage.scaled(pImage.width(),heightvalue1, Qt::IgnoreAspectRatio, Qt::SmoothTransformation); 

	//intLineStart = 0;
	//intRowStart = 0;
	strType1 = "text";
	strType2 = "2Dcode";
	//strText = strFileName;
	intLineSize = pImage.height();
	intRowSize = pImage.width(); 
	//intSW=1;
	//intSS=0;
	//booNEG=false;
	//booBWDx=false;
	//booBWDy=false;

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
			if(average < 200)
				boDotBmp[intRowStart +x][intLineStart+intLineSize -y-1] = true;
			else
				boDotBmp[intRowStart +x][intLineStart+intLineSize -y-1] = false;
		}  

	}  
	booFocus = true;
	QString get = QString(QLatin1String(strFileName)).toUtf8();
	//删除文件
	QFile::remove(get);
}

void OBJ_Control::CreateDMcode()
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;

	error_number = 0;

	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = 1;
	my_symbol->symbology = 71;
	my_symbol->scale =0.5;

	my_symbol->option_2 = intDMsize;

	batch_mode = 0;
	mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strDMContent.c_str(),strDMContent.length(),rotate_angle);

	generated = 1;

	int xPos=0;
	int yPos=0;
	/*for(int i=0;i<OBJ_Vec.size();i++)
	{
		if (booFocus)
		{
			booFocus=false;
			yPos = intLineStart;
			xPos = intRowSize+intRowStart;
		}
	}*/

	
	intLineStart=yPos;
	intRowStart=xPos;
	strType1="text";
	strType2="datamatrix";
	intLineSize=my_symbol->bitmap_height;
	intRowSize=my_symbol->bitmap_width;
	//intDMsize = nType;
	//bmpObj.strDMContent = strContent.toStdString();
	//bmpObj.strText = strContent.toStdString();
	//以下先写死
	/*bmpObj.intSW=1;
	bmpObj.intSS=1;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;*/
	i = 0;
	int r, g, b;

	for (int row = 0; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
				boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				//		bmpObj.boDotBmp[col][row-proportion] = false;
				boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	booFocus = true;
}