#pragma once
#include "classmessage.h"
#include <vector>

class CTextOBJ : public OBJ_Control
{
public:
	CTextOBJ(void);
	CTextOBJ(OBJ_Control obj,CTextOBJ TextObj);
	~CTextOBJ(void);

public://参数
	bool m_bVecotrWord;//是否矢量字库
	string m_WordStockFileName; //字库文件名
	vector<vector<bool>> m_dots;//其中dots的行和列的大小就是字符串的外包围盒
 
public://方法
	 
	void GetVectorWordDots();
	void ReadOneVectorWord(FILE *pFile,char* strText,vector<vector<bool>>& dots,int& nWidth);//其中dots的行和列的大小就是字符串的外包围盒
	
	//void PushBackTextOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW);
};

