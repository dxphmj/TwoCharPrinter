#include "ClassMessage.h"
#include "OBJ_Type.h"
#include "sstream"
#include <fstream>
#include <stdio.h>
#include "xml/tinyxml.h"
#include <QPainter>
#include "QFileInfo"
#include "ModuleMain.h"
#include "wordStock/GetHZinfo.h"
#include <math.h>
#include <QString>
#include <QDir>
 
ClassMessage::ClassMessage(void)
{
	IntMes = NULL;
	labPath = "Storage Card\\User\\Label";
	labName = "Default.lab";
	intRowMax = 0;
	Pixel = 0;
	getdigitaldot();
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
	char s[max_];
	char ss[max_];
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

void ClassMessage::DrawDot(CDC* pDC)
{
	for (int i = 0; i < OBJ_Vec.size(); i++)
	{
		OBJ_Vec[i]->DrawDot(pDC);
	}
}

//控制当前OBJ_Vec[i]中哪一个obj被选中
void ClassMessage::CtrlCurObjChoice(QPoint p_Relative)
{
	//计算鼠标相对于FileManageChild窗口的坐标位置
	int x_pos = p_Relative.x();
	int y_pos = p_Relative.y();

#ifdef BIG_CHAR
	int nLin = ( EDIT_WINDOW_HEIGHT - y_pos ) / 5;
	int nRow = x_pos / 5;

	//判断该位置是否在控件editPreviewText的可视范围内
	if ((x_pos>=0 && x_pos<=EDIT_VIEWPORT_WIDTH) && (y_pos>=0 && y_pos<=EDIT_WINDOW_HEIGHT))
	{
		vector<OBJ_Control*>::iterator itr = this->OBJ_Vec.begin();
		while (itr != this->OBJ_Vec.end())
		{		
			if (nLin>=(*itr)->intLineStart && nLin<=((*itr)->intLineStart+(*itr)->intLineSize)
				&& nRow>=(*itr)->intRowStart && nRow<=((*itr)->intRowStart+(*itr)->intRowSize))
			{
				if ((*itr)->booFocus == true && (*itr)->booBeenDragged == false)
				{
					(*itr)->booFocus = false;
				}
				else if ((*itr)->booFocus == false)
				{
					(*itr)->booFocus = true;
				}
				(*itr)->booBeenDragged = false;
			}
			else
			{
				if ((*itr)->booFocus == true && (*itr)->booBeenDragged == false)
				{
					(*itr)->booFocus = false;
				}
				(*itr)->booBeenDragged = false;
			}
			++itr;
		}
	}

#else
	int nLin = EDIT_WINDOW_HEIGHT - y_pos;
	int nRow = x_pos;
	//判断该位置是否在控件editPreviewText范围内
	if ((x_pos>=0 && x_pos<=EDIT_VIEWPORT_WIDTH) && (y_pos>=0 && y_pos<=EDIT_WINDOW_HEIGHT))
	{
		vector<OBJ_Control*>::iterator itr = this->OBJ_Vec.begin();
		while (itr != this->OBJ_Vec.end())
		{		
			if (nLin>=(*itr)->intLineStart && nLin<=((*itr)->intLineStart+(*itr)->intSideHight)
				&& nRow>=(*itr)->intRowStart && nRow<=((*itr)->intRowStart+(*itr)->intSideWidth))
			{
				if ((*itr)->booFocus == true && (*itr)->booBeenDragged == false)
				{
					(*itr)->booFocus = false;
				}
				else if ((*itr)->booFocus == false)
				{
					(*itr)->booFocus = true;
				}
				(*itr)->booBeenDragged = false;
			}
			else
			{
				if ((*itr)->booFocus == true && (*itr)->booBeenDragged == false)
				{
					(*itr)->booFocus = false;
				}
				(*itr)->booBeenDragged = false;
			}
			++itr;
		}
	}

#endif
}

//判断用户输入的文件名strFileName是否和本地已有的xml文件名重复
string ClassMessage::GenerateFileName(string tmpFileName)
{
	int tmpFileNum = 1;
	char CurFilePath[256];
	QString filePath;
	QDir qtFilePath;
	QString qtFilePathDir = qtFilePath.currentPath();

#ifdef vsPath
	filePath = "User/Label/%s(%d).lab";
#elif defined qtPath
	filePath = qtFilePathDir + "/User/Label/%s(%d).lab";
#else
	filePath = "/home/User/Label/%s(%d).lab";
#endif
	string str = filePath.toStdString();
	const char *s = str.c_str();


#ifdef BIG_CHAR
	sprintf(CurFilePath,s,tmpFileName.c_str(),tmpFileNum);
#else
	sprintf(CurFilePath,"User/Vec-Label/%s(%d).vlab",tmpFileName.c_str(),tmpFileNum);
#endif

	QFileInfo fi(CurFilePath);
	while (fi.exists())
	{
		tmpFileNum++;
#ifdef BIG_CHAR
		sprintf(CurFilePath,s,tmpFileName.c_str(),tmpFileNum);
#else
		sprintf(CurFilePath,"User/Vec-Label/%s(%d).vlab",tmpFileName.c_str(),tmpFileNum);
#endif
		fi.setFile(CurFilePath);
	}

	return CurFilePath;
}

//生成自动保存的条形码的文件名
char* ClassMessage::Generate2DcodeName(string strFileName)
{
	int tmpFileNum = 1;
	bool fileRepeat = true;
	char CurFilePath[256];
	sprintf(CurFilePath,"User/Logo/%s%d.bmp",strFileName.c_str(),tmpFileNum);
	while (fileRepeat == true)
	{
		QFileInfo fi(CurFilePath);
		if (fi.exists())
		{
			tmpFileNum++;
			sprintf(CurFilePath,"User/Logo/%s%d.bmp",strFileName.c_str(),tmpFileNum);
		}
		else
		{
			fileRepeat = false;
			break;
		}
	}
	return CurFilePath;
}

void ClassMessage::SaveObjectsToXml(string strFileName)
{
	TiXmlDocument doc;

	TiXmlElement itemMes( "MES" );

	TiXmlElement itemPro( "PRO" );
	TiXmlElement itemMatrix( "Matrix" );
	TiXmlElement itemPixel("Pixel");
	TiXmlElement itemReverse("Reverse");
	TiXmlElement itemInverse("Inverse");
	TiXmlText textMatrix(strMatrix.c_str());
	TiXmlText textPixel(to_String(Pixel+1).c_str());
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


		TiXmlText textType1(OBJ_Vec[i]->strType1.c_str());
		TiXmlText textType2(OBJ_Vec[i]->strType2.c_str());
		TiXmlText textLinestart(to_String(OBJ_Vec[i]->intLineStart).c_str());
		TiXmlText textRowstart(to_String(OBJ_Vec[i]->intRowStart).c_str());
		TiXmlText textLinesize(to_String(OBJ_Vec[i]->intLineSize).c_str());
		TiXmlText textRowsize(to_String(OBJ_Vec[i]->intRowSize).c_str());
		TiXmlText textSW(to_String(OBJ_Vec[i]->intSW).c_str());
		TiXmlText textSS(to_String(OBJ_Vec[i]->intSS).c_str());
		TiXmlText textNEG(to_String(OBJ_Vec[i]->booNEG).c_str());///这几个bool是个坑
		TiXmlText textBWDx(to_String(OBJ_Vec[i]->booBWDx).c_str());
		TiXmlText textBWDy(to_String(OBJ_Vec[i]->booBWDy).c_str());


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


		if (OBJ_Vec[i]->strType2=="text")
		{
			TiXmlElement itemSetFONT( "setFONT" );
			TiXmlElement itemSetTEXT( "setTEXT" );

			TiXmlText textSetFont(OBJ_Vec[i]->strFont.c_str());
			TiXmlText textSetTEXT(OBJ_Vec[i]->strText.c_str());

			itemSetFONT.InsertEndChild(textSetFont);
			itemSetTEXT.InsertEndChild(textSetTEXT);

			itemObj.InsertEndChild( itemSetFONT );
			itemObj.InsertEndChild( itemSetTEXT );
		}
		else if (OBJ_Vec[i]->strType2=="vtext")
		{
			CVecTextOBJ *pVecTextObj = (CVecTextOBJ*)(OBJ_Vec[i]);

			TiXmlElement itemSetFONT( "setFONT" );
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemFontSize( "FontSize" );

			TiXmlText textSetFont(pVecTextObj->strFont.c_str());
			TiXmlText textSetTEXT(pVecTextObj->strText.c_str());
			TiXmlText textFontSize(to_String(pVecTextObj->intFontSize).c_str());

			itemSetFONT.InsertEndChild(textSetFont);
			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemFontSize.InsertEndChild(textFontSize);

			itemObj.InsertEndChild( itemSetFONT );
			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemFontSize );
		}
		else if (OBJ_Vec[i]->strType2=="serial")
		{
			CSerialOBJ *pSerialObj = (CSerialOBJ*)(OBJ_Vec[i]);

			TiXmlElement itemsetFONT("setFONT");
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemFirstLimit( "FirstLimit" );
			TiXmlElement itemSecondLimit( "SecondLimit" );
			TiXmlElement itemStartValue( "StartValue" );
			TiXmlElement itemStep( "Step" );
			TiXmlElement itemRepeat( "Repeat" );
			TiXmlElement itemDigits( "Digits" );
			TiXmlElement itemFormat( "Format" );
			TiXmlElement itemCounter( "Counter" );
			TiXmlElement itemFontSize( "FontSize" );

			TiXmlText textSetFont(pSerialObj->strFont.c_str());
			TiXmlText textSetTEXT(pSerialObj->strText.c_str());
			TiXmlText textFirstLimit(to_String(pSerialObj->intSerialFirstLimit).c_str());
			TiXmlText textSecondLimit(to_String(pSerialObj->intSerialSecondLimit).c_str());
			TiXmlText textStartValue(to_String(pSerialObj->intSerialStartValue).c_str());
			TiXmlText textStep(to_String(pSerialObj->intSerialStep).c_str());
			TiXmlText textRepeat(to_String(pSerialObj->intSerialRepeat).c_str());
			TiXmlText textDigits(to_String(pSerialObj->intSerialDigits).c_str());
			TiXmlText textFormat(to_String(pSerialObj->bytSerialFormat).c_str());
			TiXmlText textCounter(to_String(pSerialObj->intSerialCounter).c_str());
			TiXmlText textFontSize(to_String(pSerialObj->intFontSize).c_str());

			itemsetFONT.InsertEndChild(textSetFont);
			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemFirstLimit.InsertEndChild(textFirstLimit);
			itemSecondLimit.InsertEndChild(textSecondLimit);
			itemStartValue.InsertEndChild(textStartValue);
			itemStep.InsertEndChild(textStep);
			itemRepeat.InsertEndChild(textRepeat);
			itemDigits.InsertEndChild(textDigits);
			itemFormat.InsertEndChild(textFormat);
			itemCounter.InsertEndChild(textCounter);
			itemFontSize.InsertEndChild(textFontSize);

			itemObj.InsertEndChild( itemsetFONT );
			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemFirstLimit );
			itemObj.InsertEndChild( itemSecondLimit );
			itemObj.InsertEndChild( itemStartValue );
			itemObj.InsertEndChild( itemStep );
			itemObj.InsertEndChild( itemRepeat );
			itemObj.InsertEndChild( itemDigits );
			itemObj.InsertEndChild( itemFormat );
			itemObj.InsertEndChild( itemCounter );
			itemObj.InsertEndChild( itemFontSize );

		} 
		else if(OBJ_Vec[i]->strType2=="time")
		{
			CTimeOBJ *pTimeObj = (CTimeOBJ*)(OBJ_Vec[i]);
			
			TiXmlElement itemsetFONT("setFONT");
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemSetTIME( "setTIME" );
			TiXmlElement itemETimeOffSet( "ETimeOffSet" );
			TiXmlElement itemTimeOffSet( "TimeOffSet" );
			TiXmlElement itemTimeOffSetUint( "TimeOffSetUint" );
			TiXmlElement itemFontSize( "FontSize" );

			TiXmlText textSetFont(OBJ_Vec[i]->strFont.c_str());
			TiXmlText textSetTEXT(OBJ_Vec[i]->strText.c_str());
			TiXmlText textSetTIME(pTimeObj->strTime.c_str());
			TiXmlText textETimeOffSet(to_String(pTimeObj->booETimeOffSet).c_str());
			TiXmlText textTimeOffSet(to_String(pTimeObj->intTimeOffSet).c_str());
			TiXmlText textTimeOffSetUint(to_String(pTimeObj->strTimeOffSet).c_str());
			TiXmlText textFontSize(to_String(pTimeObj->intFontSize).c_str());

			itemsetFONT.InsertEndChild(textSetFont);
			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemSetTIME.InsertEndChild(textSetTIME);
			itemETimeOffSet.InsertEndChild(textETimeOffSet);
			itemTimeOffSet.InsertEndChild(textTimeOffSet);
			itemTimeOffSetUint.InsertEndChild(textTimeOffSetUint);
			itemFontSize.InsertEndChild(textFontSize);

			itemObj.InsertEndChild( itemsetFONT );
			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemSetTIME );
			itemObj.InsertEndChild( itemETimeOffSet );
			itemObj.InsertEndChild( itemTimeOffSet );
			itemObj.InsertEndChild( itemTimeOffSetUint );
			itemObj.InsertEndChild( itemFontSize );

		}
		else if (OBJ_Vec[i]->strType2=="logo")
		{
			TiXmlElement itemSetTEXT( "setTEXT" );

			TiXmlText textSetTEXT(OBJ_Vec[i]->strText.c_str());

			itemSetTEXT.InsertEndChild(textSetTEXT);

			itemObj.InsertEndChild( itemSetTEXT );
		}
		else if (OBJ_Vec[i]->strType2=="2Dcode")
		{
		    CBarcodeOBJ *pBarcodeObj = (CBarcodeOBJ*)(OBJ_Vec[i]);
			
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemBarcodeType( "BarcodeType" );
			TiXmlElement itemBarType( "BarType" );
			TiXmlElement itemBarcodeContent( "BarcodeContent" );
			TiXmlElement itemBarWhite( "BarWhite" );

			TiXmlText textSetTEXT(OBJ_Vec[i]->strText.c_str());
			TiXmlText textBarcodeType(to_String(pBarcodeObj->intBarcodeType).c_str());
			TiXmlText textBarType(to_String(pBarcodeObj->intBarType).c_str());
			TiXmlText textBarcodeContent(pBarcodeObj->strCodeContent.c_str());
			TiXmlText textBarWhite(to_String(pBarcodeObj->intBarWhite).c_str());

			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemBarcodeType.InsertEndChild(textBarcodeType);
			itemBarType.InsertEndChild(textBarType);
			itemBarcodeContent.InsertEndChild(textBarcodeContent);
			itemBarWhite.InsertEndChild(textBarWhite);

			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemBarcodeType );
			itemObj.InsertEndChild( itemBarType );
			itemObj.InsertEndChild( itemBarcodeContent );
			itemObj.InsertEndChild( itemBarWhite );
		}
		else if (OBJ_Vec[i]->strType2=="qrcode")
		{
			CQRcodeOBJ *pQRcodeObj = (CQRcodeOBJ*)(OBJ_Vec[i]);
			
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemVersion( "qrcodeVersion" );
			TiXmlElement itemSideLen( "qrcodeSideLen" );
			//TiXmlElement itemECCLevel( "qrcodeECCLevel" );
			//TiXmlElement itemQuietZone( "qrcodeQuietZone" );

			TiXmlText textSetTEXT(OBJ_Vec[i]->strText.c_str());
			TiXmlText textVersion(to_String(pQRcodeObj->intQRVersion).c_str());
			TiXmlText textSidelen(to_String(pQRcodeObj->SideLength).c_str());
			//TiXmlText textECCLevel(to_String(OBJ_Vec[i].intQRErrLevel).c_str());
			//TiXmlText textQuietZone(to_String(OBJ_Vec[i].intqrcodeQuietZone).c_str());

			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemVersion.InsertEndChild(textVersion);
			itemSideLen.InsertEndChild(textSidelen);
			//itemECCLevel.InsertEndChild(textECCLevel);
			//itemQuietZone.InsertEndChild(textQuietZone);

			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemVersion );
			itemObj.InsertEndChild( itemSideLen );
			//itemObj.InsertEndChild( itemECCLevel );
			//itemObj.InsertEndChild( itemQuietZone );
		}
		else if (OBJ_Vec[i]->strType2=="datamatrix")
		{
			CDMcodeOBJ *pDMcodeObj = (CDMcodeOBJ*)(OBJ_Vec[i]);
			
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemVersion( "DMsize" );
			TiXmlElement itemDMContent("DMContent");
			TiXmlElement itemDMrow( "DMrow" );

			TiXmlText textSetTEXT(OBJ_Vec[i]->strText.c_str());
			TiXmlText textVersion(to_String(pDMcodeObj->intDMsize).c_str());
			TiXmlText textDMContent(pDMcodeObj->strDMContent.c_str());
			TiXmlText textDMrow(to_String(pDMcodeObj->intDMrow).c_str());

			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemVersion.InsertEndChild(textVersion);
			itemDMContent.InsertEndChild(textDMContent);
			itemDMrow.InsertEndChild(textDMrow);

			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemVersion );
			itemObj.InsertEndChild( itemDMContent);
			itemObj.InsertEndChild( itemDMrow );
		}
		itemMes.InsertEndChild( itemObj );
	}	 
	doc.InsertEndChild(itemMes);
	doc.SaveFile(strFileName.c_str());
	//doc.SaveFile(saveFileName);
} 

void ClassMessage::ClearOBJ_Vec()
{
	for(int i = 0; i < OBJ_Vec.size(); i++)
	{
		delete OBJ_Vec[i];
	}
	OBJ_Vec.clear();
}

void ClassMessage::GetMatrix()
{
	if (strMatrix == "1L9M")
	{
		Matrix = 9;
	} 
	else if(strMatrix == "1L12M")
	{
		Matrix = 12;
	}
	else if(strMatrix == "1L14M")
	{
		Matrix = 14;
	}
	else if(strMatrix == "1L19M")
	{
		Matrix = 19;
	}
	else if(strMatrix == "1L25M")
	{
		Matrix = 25;
	}
	//以下为更改后的画布高度配置
	else if(strMatrix == "1L8M")
	{
		Matrix = 8;
	}
	else if(strMatrix == "1L16M")
	{
		Matrix = 16;
	}
	else if(strMatrix == "1L32M")
	{
		Matrix = 32;
	}
	else if(strMatrix == "1L48M")
	{
		Matrix = 48;
	}
	/*else if(strMatrix == "2L7M")
	{
	Matrix = 14;
	}*/
	else
	{
		Matrix = 19;
	}
}

int ClassMessage::GetPixel()
{
	int intTempPixel = 0;
	for( int i = 0; i < OBJ_Vec.size(); i++ )
	{
		if (intTempPixel < (OBJ_Vec[i]->intLineStart + OBJ_Vec[i]->intLineSize))
		{
			intTempPixel = OBJ_Vec[i]->intLineStart + OBJ_Vec[i]->intLineSize;
		}
	}
	return intTempPixel;
}

void ClassMessage::ReadObjectsFromXml(char* strFileName)
{
	//clear OBJ_Vec
	ClearOBJ_Vec();

	memset(CounterEditMes,false,sizeof(bool)*4);
	TiXmlDocument doc(strFileName);
	bool loadOkay = doc.LoadFile();
	if (!loadOkay)
	{
		return;
	}
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
					GetMatrix();
				}
				else if(strcmp(strItem,"Pixel") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					//sprintf_s(obj.m_texts,"%s",strText); 
					Pixel=atoi(strText)-1;
				}
				else if(strcmp(strItem,"Reverse") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					//sprintf_s(obj.m_texts,"%s",strText); 
					Reverse.assign(strText);
				}
				else if(strcmp(strItem,"Inverse") == 0)
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
			CTextOBJ TextObj;
			CSerialOBJ SerialObj;
			CTimeOBJ   TimeObj;
			CBmpObj bmpObj;
			CBarcodeOBJ barcodeObj;
			CQRcodeOBJ QRcodeObj;
			CDMcodeOBJ  DMcodeObj; 
			CVecTextOBJ VecTextObj;

			obj.booFocus = false;
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
				else if(strcmp(strItem,"TYPE2") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.strType2.assign(strText);
				}
				else if(strcmp(strItem,"LineStart") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intLineStart=atoi(strText);
				}
				else if(strcmp(strItem,"RowStart") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intRowStart=atoi(strText);
				}
				else if(strcmp(strItem,"LineSize") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intLineSize=atoi(strText);
				}
				else if(strcmp(strItem,"RowSize") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intRowSize=atoi(strText);
				}
				else if(strcmp(strItem,"SW") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intSW=atoi(strText);
				}
				else if(strcmp(strItem,"SS") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intSS=atoi(strText);
				}
				else if(strcmp(strItem,"NEG") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.booNEG=atoi(strText);
				}
				else if(strcmp(strItem,"BWDx") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.booBWDx=atoi(strText);
				}
				else if(strcmp(strItem,"BWDy") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.booBWDy=atoi(strText);
				}
				else if(strcmp(strItem,"setFONT") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.strFont.assign(strText);
				}


				if (obj.strType1=="text"&&obj.strType2=="text")
				{
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}
				}
				else if (obj.strType1=="text"&&obj.strType2=="vtext")
				{
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}
					else if (strcmp(strItem,"FontSize") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intFontSize = atoi(strText);
						obj.GenerateVecBmp(obj.strFont,obj.strText,obj.intFontSize);
					}
				}
				else if (obj.strType1=="text"&&obj.strType2=="serial")
				{					 
					if(strcmp(strItem,"FirstLimit") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						SerialObj.intSerialFirstLimit = atoi(strText);
					}
					else if(strcmp(strItem,"SecondLimit") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						SerialObj.intSerialSecondLimit=atoi(strText);
					}
					else if(strcmp(strItem,"StartValue") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						SerialObj.intSerialStartValue=atoi(strText);
					}
					else if(strcmp(strItem,"Step") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						SerialObj.intSerialStep=atoi(strText);
					}
					else if(strcmp(strItem,"Repeat") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						SerialObj.intSerialRepeat=atoi(strText);
					}
					else if(strcmp(strItem,"Digits") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						SerialObj.intSerialDigits=atoi(strText);
					}
					else if(strcmp(strItem,"Format") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						SerialObj.bytSerialFormat=atoi(strText);
					}
					else if(strcmp(strItem,"Counter") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						SerialObj.intSerialCounter=atoi(strText);
						CounterEditMes[SerialObj.intSerialCounter]=true;
					}
					else if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}
#ifdef BIG_CHAR
#else
					else if (strcmp(strItem,"FontSize") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intFontSize = atoi(strText);
						obj.GenerateVecBmp(obj.strFont,obj.strText,obj.intFontSize);
					}
#endif
				}
				else if (obj.strType1=="text"&&obj.strType2=="time")
				{
					if(strcmp(strItem,"setTIME") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						TimeObj.strTime.assign(strText);
					}
					else if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}	
#ifdef BIG_CHAR
#else
					else if (strcmp(strItem,"FontSize") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intFontSize = atoi(strText);
						obj.GenerateVecBmp(obj.strFont,obj.strText,obj.intFontSize);
					}
#endif
				}
				else if (obj.strType1=="text"&&obj.strType2=="logo")
				{
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);						 
						bmpObj.ReadBmp(const_cast<char*>(obj.strText.c_str()));
					}	
				}
				else if (obj.strType1=="text"&&obj.strType2=="2Dcode")
				{ 
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}
					if (strcmp(strItem,"BarcodeType") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						barcodeObj.intBarcodeType = atoi(strText);
					}
					if (strcmp(strItem,"BarType") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						barcodeObj.intBarType = atoi(strText);
					}
					//if(strcmp(strItem, "BarWhite" ) == 0)
					//{
					//	//读入信息
					//	const char* strText; 
					//	TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					//	strText = nodeText->ValueTStr().c_str();
					//	//obj.strDMContent.assign(strText);
					//	obj.intBarWhite = atoi(strText);
					//}
					if(strcmp(strItem,"BarcodeContent") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						barcodeObj.strCodeContent.assign(strText);
						barcodeObj.Create2Dcode();
					}
				}				
				else if (obj.strType1=="text"&&obj.strType2=="qrcode")
				{					
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}	
					if(strcmp(strItem,"qrcodeVersion") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						QRcodeObj.strqrcodeVersion.assign(strText);
						QRcodeObj.intQRVersion = atoi(strText);	
					}
					if(strcmp(strItem,"qrcodeSideLen") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						QRcodeObj.SideLength = atoi(strText);
						//读入完所有的信息后要重新生成二位码的点阵信息,因为lab中不包含这些信息，logo及其他类似
						QRcodeObj.CreateQrcode();
					}
				}
				else if (obj.strType1=="text"&&obj.strType2=="datamatrix")
				{ 
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}	
					if(strcmp(strItem,"DMsize") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						//obj.strDMContent.assign(strText);
						DMcodeObj.intDMsize = atoi(strText);
					}
					if(strcmp(strItem,"DMrow") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						//obj.strDMContent.assign(strText);
						DMcodeObj.intDMrow = atoi(strText);
					}
					if(strcmp(strItem,"DMContent") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						DMcodeObj.strDMContent.assign(strText);
					
						//读入完所有的信息后要重新生成二位码的点阵信息,因为lab中不包含这些信息，logo及其他类似
						DMcodeObj.CreateDMcode();
					}
				}
			}
			obj.booFocus = false;

			if(obj.strType2 == "text")
			{
				CTextOBJ* pTextObj = new CTextOBJ(obj,TextObj);
				OBJ_Vec.push_back(pTextObj);
			}
			else if(obj.strType2 == "vtext")
			{
				CVecTextOBJ* pVecTextObj = new CVecTextOBJ(obj,VecTextObj);
				OBJ_Vec.push_back(pVecTextObj);
			}
			else if(obj.strType2 == "serial")
			{
				CSerialOBJ* pSerialObj = new CSerialOBJ(obj,SerialObj);
				OBJ_Vec.push_back(pSerialObj);
			}
			else if(obj.strType2 == "time")
			{
				CTimeOBJ* pTimeObj = new CTimeOBJ(obj,TimeObj);
				OBJ_Vec.push_back(pTimeObj);
			}
			else if(obj.strType2 == "logo")
			{
				CBmpObj* pbmpObj = new CBmpObj(obj,bmpObj);
				OBJ_Vec.push_back(pbmpObj);
			}
			else if(obj.strType2 == "2Dcode")
			{
				CBarcodeOBJ* pbarcodeObj = new CBarcodeOBJ(obj,barcodeObj);
				OBJ_Vec.push_back(pbarcodeObj);
			}
			else if(obj.strType2 == "qrcode")
			{
				CQRcodeOBJ* pQRcodeObj = new CQRcodeOBJ(obj,QRcodeObj);
				OBJ_Vec.push_back(pQRcodeObj);
			}
			else if(obj.strType2 == "datamatrix")
			{
				CDMcodeOBJ* pDMcodeObj = new CDMcodeOBJ(obj,DMcodeObj);
				OBJ_Vec.push_back(pDMcodeObj);
			}			 
		}
	}
	string strPathName=strFileName;
	int lastN=strPathName.find_last_of('\\');
	labName = strPathName.substr(lastN + 1);
	labPath=strPathName.substr(0,lastN);

}

void ClassMessage::getdot()
{
	boDotMes.clear();
	vector<vector<bool> > ivec(32 ,vector<bool>(intRowMax<10?10:intRowMax,false));//为何不能小于10
	boDotMes = ivec;//为获得obj的点阵信息申请空间

	ModuleMain myModuleMain;

    for(int i = 0; i < OBJ_Vec.size(); i++)
	{		 		
		if (OBJ_Vec[i]->strType2=="text")
		{
			OBJ_Vec[i]->DrawTextAll(NULL,boDotMes);
		}
		else if (OBJ_Vec[i]->strType2=="logo")
		{
			OBJ_Vec[i]->DrawLogoQRcodeDM(NULL,boDotMes);
			 
		}
		else if (OBJ_Vec[i]->strType2=="qrcode")//二维码
		{
			OBJ_Vec[i]->DrawLogoQRcodeDM(NULL,boDotMes);
		}
		else if (OBJ_Vec[i]->strType2=="time")
		{
			CTimeOBJ* pTimeObj = (CTimeOBJ*)(OBJ_Vec[i]);
			//OBJ_Vec[i]->strText = myModuleMain.TimeFormatToText(myModuleMain.string2CString(pTimeObj->strTime),
			//	                    pTimeObj->booETimeOffSet,pTimeObj->intTimeOffSet,pTimeObj->strTimeOffSet);
			OBJ_Vec[i]->strText = myModuleMain.TimeFormatToText(QString::fromStdString(pTimeObj->strTime),
				pTimeObj->booETimeOffSet,pTimeObj->intTimeOffSet,pTimeObj->strTimeOffSet);
			OBJ_Vec[i]->DrawTextAll(NULL,boDotMes);
		}
		else if (OBJ_Vec[i]->strType2 == "serial")
		{						 
			CSerialOBJ* pSerialObj = (CSerialOBJ*)(OBJ_Vec[i]);
			OBJ_Vec[i]->strText = myModuleMain.SerialFormatToText(pSerialObj->intSerialStartValue, pSerialObj->intSerialDigits,pSerialObj->bytSerialFormat);
			OBJ_Vec[i]->DrawTextAll(NULL,boDotMes);
		}		 
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
			if(Matrix == 8 | Matrix == 16 | Matrix == 32 | Matrix == 48 /*| Matrix == 25*/)
            {
                bytRowByteMul = 2;
                //if(Pixel == 5 | Pixel == 7)
				if(Pixel < 8)
                {
                    for (int i = tempintDotRowStart; i< tempintDotRowEnd; i++)
                    {
                        bytTempVec.push_back(0);
                        for (int j=0;j< Pixel;j++)
                        {
                            bytTempVec[2*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
                        }
                        bytTempVec.push_back(0);
                        bytTempVec[2*i+1]=0;
                    }
                }
                else //Pixel == 12 | 19
                {
                    for (int i = tempintDotRowStart; i< tempintDotRowEnd; i++)
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
            }
/*
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
								//bytTempVec[3*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
								bytTempVec[3*i+1] = bytTempVec[3*i+1] + getByteFromDot(boDotMes[j][i],j-8);
							}
							bytTempVec.push_back(0);
							for (int j=16;j<Pixel;j++)
							{
								//bytTempVec[3*i+2]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-16);
								bytTempVec[3*i+2] = bytTempVec[3*i+2] + getByteFromDot(boDotMes[j][i],j-16);
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
*/
		}
	}
	return bytTempVec;
}

void ClassMessage::getdigitaldot()
{
	string tempsetTEXT = "0123456789abcdefghijklmnopqrstuvwsyzABCDEFGHIJKLMNOPQRSTUVWSYZ";
	for (int i=0;i<tempsetTEXT.length();i++)//5x5
	{
		wchar_t strTempText=tempsetTEXT[i];
		int bytTextUni=(int)strTempText;
		int lonTextUniSetOff=bytTextUni*7+64;
		char objbytTex5x5LineTemp[7];
		bool objRead = OBJ_Control::readBin("5x5.fnt",lonTextUniSetOff,objbytTex5x5LineTemp,7);
		vector<BYTE> tempVec(objbytTex5x5LineTemp,objbytTex5x5LineTemp+6);
		string tempKey = tempsetTEXT.substr(i,1);
		bytdigital5x5LineMap.insert(make_pair(tempKey,tempVec));
	}
	for (int i=0;i<tempsetTEXT.length();i++)//7x5
	{
		wchar_t strTempText=tempsetTEXT[i];
		int bytTextUni=(int)strTempText;
		int lonTextUniSetOff=bytTextUni*8+64;
		char objbytTex7x5LineTemp[8];
		bool objRead = OBJ_Control::readBin("7x5.fnt",lonTextUniSetOff,objbytTex7x5LineTemp,8);
		vector<BYTE> tempVec(objbytTex7x5LineTemp,objbytTex7x5LineTemp+6);
		string tempKey=tempsetTEXT.substr(i,1);
		bytdigital7x5LineMap.insert(make_pair(tempKey,tempVec));
	}
	for (int i=0;i<tempsetTEXT.length();i++)//12*12
	{
		wchar_t strTempText=tempsetTEXT[i];
		int bytTextUni=(int)strTempText;
		int lonTextUniSetOff=bytTextUni*25+64;
		char objbytTex12x12LineTemp[25];
		bool objRead = OBJ_Control::readBin("12x12.fnt",lonTextUniSetOff,objbytTex12x12LineTemp,25);
		vector<BYTE> tempVec(objbytTex12x12LineTemp,objbytTex12x12LineTemp+24);
		string tempKey = tempsetTEXT.substr(i,1);
		bytdigital12x12LineMap.insert(make_pair(tempKey,tempVec));
	}
	for (int i=0;i<tempsetTEXT.length();i++)//16*12
	{
		wchar_t strTempText=tempsetTEXT[i];
		int bytTextUni=(int)strTempText;
		int lonTextUniSetOff=bytTextUni*29+64;
		char objbytTex16x12LineTemp[25];
		bool objRead = OBJ_Control::readBin("16x12.fnt",lonTextUniSetOff,objbytTex16x12LineTemp,29);
		vector<BYTE> tempVec(objbytTex16x12LineTemp,objbytTex16x12LineTemp+24);
		string tempKey=tempsetTEXT.substr(i,1);
		bytdigital16x12LineMap.insert(make_pair(tempKey,tempVec));
	}
}

void ClassMessage::DrawAllDynamic(CDC* pDC)
{
 	if(intMesDis.size() == 0) return;
	//vector<BYTE> intMesDis1 = intMesDis;//intMesDis他为实时更改的，直接用它会造成混乱吧

	CBrush cbrushB(QColor(0,0,0));//黑笔
	cbrushB.setStyle(Qt::SolidPattern);
	CBrush cbrushW(QColor(255,255,255));//白笔
	cbrushW.setStyle(Qt::NoBrush);
	int pixSize = 4;
	ModuleMain myModuleMain;  
	
	if (Matrix != 14)
	{ 
		for (int k = 0; k < intRowMax; k++)
			for (int i = 0; i <= Pixel; i++)
			{
				bool bDraw = false;
				bDraw = myModuleMain.MesDisIsB(intMesDis[12+2*k]+(intMesDis[12+2*k+1]*pow(2.0,8)),i);
/*
				if (Pixel < 8)
					bDraw = myModuleMain.MesDisIsB(intMesDis[11+k],i);
				else if(Pixel > 7 && Pixel < 16)
					bDraw = myModuleMain.MesDisIsB(intMesDis[11+2*k]+(intMesDis[11+2*k+1]*pow(2.0,8)),i);
				else if(Pixel > 15 && Pixel < 24)
					bDraw = myModuleMain.MesDisIsB(intMesDis[11+3*k]+(intMesDis[11+3*k+1]*pow(2.0,8))+ (intMesDis[11+3*k+2]*pow(2.0,16)),i);
				else if(Pixel > 23)
					bDraw = myModuleMain.MesDisIsB(intMesDis[11+4*k]+(intMesDis[11+4*k+1]*pow(2.0,8))+(intMesDis[11+4*k+2]*pow(2.0,16))+(intMesDis[11+4*k+3]*pow(2.0,24)),i);
*/
				CRect rect(k*pixSize+1,(31-i)*pixSize+1,pixSize,pixSize);
				if(bDraw)
				{
					pDC->setBrush(cbrushB);						 
					pDC->Ellipse(rect);					 
				}
				else
				{
					pDC->setBrush(cbrushW);	
					pDC->Ellipse(rect);					 			 
				}
				//Sleep(1);
			}		 
	} 
	else
	{
		for (int k = 0; k < intRowMax; k++)
		{
			BYTE tempByte1 = intMesDis[k*2+12];
			BYTE tempByte2 = intMesDis[k*2+12+1];

			for(int i = 0; i < 7; i = i+2)
			{	
				bool bDraw = false;
				if (myModuleMain.MesDisIsB(tempByte1,i))
					;//pDC->Rectangle(k*pixSize+1,(31-i/2)*pixSize+1,(k+1)*pixSize,(32-i/2)*pixSize);
				//Sleep(1);
				if (i < 6)
				{
					if (myModuleMain.MesDisIsB(tempByte2,i))
						;//pDC->Rectangle(k*pixSize+1,(31-4-i/2)*pixSize+1,(k+1)*pixSize,(32-4-i/2)*pixSize);
					//Sleep(1);
				}				
			}
		} 
	}	
 }