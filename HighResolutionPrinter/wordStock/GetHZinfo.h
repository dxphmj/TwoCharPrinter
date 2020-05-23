#pragma once

#include <stdio.h> 

typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef int                 BOOL;
typedef char CHAR;
typedef short SHORT;
typedef long LONG;

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif


#define x_con   100       //固定的汉字外接矩形宽度
#define y_con   100       //固定的汉字外接矩形高度

struct hzPoint
{ 	
	short x;
	short y;

	hzPoint(short initX,short initY)
	{
		x = initX;
		y = initY;
	}
};

typedef struct tagRECT2
{
	LONG    left;
	LONG    top;
	LONG    right;
	LONG    bottom;
} RECT2, *PRECT2;

#ifndef HZTOOL
#define DllExport   __declspec( dllexport )
#else
#define DllExport   __declspec( dllimport )

#endif

class CGetHZinfo
{
public:
	CGetHZinfo(void);
	CGetHZinfo(FILE* pFile,unsigned char* hzChar,hzPoint& topleft);

	~CGetHZinfo(void);

public:
	RECT2 m_position;
	hzPoint* 	pointsall;      //所有文字轮廓绝对坐标
	hzPoint* 	pointsv;        //所有文字轮廓相对坐标
	int numofcontour;    //文字轮廓数量（都是封闭轮廓数）
	int* numpercontour;  //每个轮廓的点数量

public:

	hzPoint FindRect(WORD* hzdata,int numofpoint);
	BOOL  Convert(WORD* hzdata,int numofpoint); 
	int   decode(BYTE* sourceBuf, WORD* denstBuf,int num);


};

