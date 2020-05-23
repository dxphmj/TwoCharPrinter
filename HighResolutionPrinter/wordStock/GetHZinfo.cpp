#include "GetHZinfo.h"
#include "Dom.h"
#include <memory.h>
//#include <windows.h>
//#include <windowsx.h>
//
//typedef struct tagRECT
//{
//	LONG    left;
//	LONG    top;
//	LONG    right;
//	LONG    bottom;
//} RECT, *PRECT;
//

struct index
{
	unsigned long offset;
	unsigned short length;
};


CGetHZinfo::CGetHZinfo(void)
{
}

CGetHZinfo::~CGetHZinfo(void)
{
}

CGetHZinfo::CGetHZinfo(FILE* fp,unsigned char* hzChar,hzPoint& topleft)
{
/*	unsigned char qmv;
	unsigned char wmv;

 	//qmv = 4; //HZKSLE字体中 行1-5列20都是 数字 4
 	//wmv = 20;
 	qmv = (unsigned char)hzChar[0]-0xa0;//国际码-0xa0等于区位码，汉子库中的数字和字母是全角的
 	wmv = hzChar[1]-0xa0;
	
	int numofpoint = 0;            //the tatal points num
	int numofcontour = 0;          //the tatal contour num
	short* numpercontour = NULL;      //ptr:the points num array of single contour 

	//h_data = NULL;
	//h_hzdata = NULL;
	//h_pointsall = NULL;
	//h_pointsv = NULL;

	//hzdata=NULL;
	//pointsall=NULL;          //ptr:points array for the contour
	//pointsv=NULL;
	 
	 
	//WORD* hzdata = new WORD(64*1016);//(WORD*)::GlobalLock(temphz);
	//BYTE* buf = new BYTE(2000*sizeof(WORD));
    //临时分配 
    HGLOBAL 	h_data;         //包括:hzdata,pointsall,pointsv
	HGLOBAL 	h_hzdata;       //handle:汉字的原始字形数据,x,y,flag,字形坐标系
	WORD*   	hzdata;         //ptr
	HANDLE temphz,tempbuf;
	temphz=::GlobalAlloc(GHND,(long)64*1016);    //解压后数据,由DOM处理的数据
	hzdata=(WORD*)::GlobalLock(temphz);
	tempbuf=::LocalAlloc(LHND,2000*sizeof(WORD)); //需解压的字库数据
	BYTE* buf=(BYTE*)::LocalLock(tempbuf);
	if(hzdata==NULL) return;
	//CFile fp;
	if(buf==NULL) return;
	int num;
	long offset;
	index slindex;
	//临时分配
		 
	if(qmv>=16)
	{
		//使用汉字通道
		offset = ((unsigned long)(qmv-16)*94+wmv-1)*6;
	}
	else 
	{ 			
		offset = ((unsigned long)(qmv-1)*94+wmv-1)*6;
	}

   //offset = ((unsigned long)(qmv-32))*6;

	fseek(fp,offset,SEEK_SET);         
	fread(&slindex,sizeof(index),1,fp); //文件中低字节在前，高字节在后
	fseek(fp,slindex.offset,SEEK_SET);
	fread(buf,slindex.length,1,fp);
	 
		
	num = decode(buf,hzdata,slindex.length); 
	//保存dom后的点数  
	numofpoint = DM_Dom((char*)hzdata,(short)num,2);

 
	//hzdata此时有效
	FindRect(hzdata,numofpoint);              //计算外接矩形，并调整字形数据填充m_position,constrect
	//hzdata此时有效
	Convert(hzdata,numofpoint);//转换数据为cpoints数组形式，填充数组pointsall,pointsv
*/
	/*delete  buf;
	delete  hzdata;  */
/*
	::LocalUnlock(tempbuf);
	::LocalFree(tempbuf);
	::GlobalUnlock(temphz);
	::GlobalFree(temphz);
	hzdata=NULL;                //恢复hzdata,此时只有h_data有效
    fp=NULL;
*/
}

hzPoint CGetHZinfo::FindRect(WORD* hzdata,int numofpoint)
{
	WORD x_max,y_max,x_min,y_min;
	int i;

	x_max=hzdata[0];         //initial the max and min
	y_max=hzdata[1];
	x_min=hzdata[0];
	y_min=hzdata[1];

	for(i=1;i<numofpoint;i++)   //get the relative max,min (x,y)
	{
		if(hzdata[3*i]>x_max)   x_max=hzdata[3*i];
		if(hzdata[3*i+1]>y_max) y_max=hzdata[3*i+1];
		if(hzdata[3*i]<x_min)   x_min=hzdata[3*i];
		if(hzdata[3*i+1]<y_min) y_min=hzdata[3*i+1];
	}
	//set the m_position (around rect) use the local and max,min

	if(x_max>=x_con)
	{
		m_position.right = m_position.left+x_max-x_min+20;     //x_max 超出预设矩形，汉字偏右调整取对称 矩形
		for(i=0;i<numofpoint;i++) hzdata[3*i]=hzdata[3*i]-(x_min-10); //修改原数据，使汉字处于外接矩形的中间
	}
	else if(x_min+x_max>x_con&&x_max<x_con)               //x_max 没超出预设矩形，取但原数据偏右，对称取 矩形
	{ 
		m_position.right=m_position.left+2*x_con-x_min-x_max; //修改原数据，使汉字处于外接矩形的中间
		for(i=0;i<numofpoint;i++) hzdata[3*i]=hzdata[3*i]-(x_min+x_max-x_con);
		 
	}
	else if(x_min+x_max<=x_con)                           //汉字偏左 ，不调整
	{
		m_position.right=m_position.left+x_min+x_max;
	}
	//decide the bottom:m_position.bottom
	if(y_max>=y_con)                                     //y_max 超出，延伸10个单位
	{
		m_position.bottom=m_position.top-y_max-10;
	}
	else if(y_min+y_max>y_con&&y_max<y_con)              //同上
	{ 
		m_position.bottom=m_position.top-y_max-10;
	}
	else if(y_min+y_max<=y_con)                          //汉字偏上 ，不调整
	{
		m_position.bottom=m_position.top-y_min-y_max;
	}
	//constrect = m_position;                    //保存固定外接矩形尺寸

	return hzPoint(m_position.right+2,m_position.top);  ///返回右上点 b并右移2单位
}

BOOL  CGetHZinfo::Convert(WORD* hzdata,int numofpoint)           //填充pointsall,pointv
{
	int num,pointofcontour,flag; //the num of contour:local ver

	numofcontour = 0;
	num = 0;
	pointofcontour=0;
	//计算单轮廓数:设置numofcontour       
	int i;
	for(i=0;i<numofpoint;i++)
	{
		if((flag=hzdata[3*i+2]&0x0002)==0x0002) num++;
	} 
	if(num==0) return FALSE;
	numofcontour = num;

	//用new操作符分配
	numpercontour = new int[numofcontour];

	////分配存放数据的内存
	//h_data=::GlobalAlloc(GHND,2000*sizeof(WORD)+2*(numofcontour+numofpoint)*sizeof(CPoint));
	//if(h_data==NULL) return FALSE;


	BYTE* ptr = new BYTE(2000*sizeof(WORD)+2*(numofcontour+numofpoint)*sizeof(hzPoint));

	 pointsall = (hzPoint*)(ptr+2000*sizeof(WORD));
	 pointsv = (hzPoint*)(ptr+2000*sizeof(WORD)+(numofcontour+numofpoint)*sizeof(hzPoint));

	num=0;
	int beginend,polyall,polyv;
	beginend=0;                 //存放单轮廓起点索引
	polyall=0;                  //index of pointsall
	polyv=0;                    //index of pointsv

	for(i=0;i<numofpoint;i++)
	{ 
		if((flag=hzdata[3*i+2])==0x0001) 
		{
			//work out the 相对坐标：pointsall   原点为topleft,坐标系为x轴向右，y轴向下
			pointsall[polyall].x=hzdata[3*i];
			pointsall[polyall++].y=hzdata[3*i+1];
			// work out the 绝对坐标：pointv
			pointsv[polyv].x=m_position.left+hzdata[3*i];   // 正向向右
			pointsv[polyv++].y=m_position.top-hzdata[3*i+1];  // 正向向上??

			pointofcontour++;
		}  
		if((flag=hzdata[3*i+2]&0x0002)==0x0002)
		{
			//work out the 相对坐标：pointsall
			pointsall[polyall].x=hzdata[3*i];
			pointsall[polyall++].y=hzdata[3*i+1];
			// work out the 绝对坐标：pointv
			pointsv[polyv].x=m_position.left+hzdata[3*i];
			pointsv[polyv++].y=m_position.top-hzdata[3*i+1];

			pointofcontour++;
			//为了使用polypolygon，补加一个起始点，使轮廓闭合,其在hzdata中的序号为begin
			pointsall[polyall].x=hzdata[3*beginend];                //
			pointsall[polyall++].y=hzdata[3*beginend+1];
			//the index of the contour
			pointsv[polyv].x=m_position.left+hzdata[3*beginend];
			pointsv[polyv++].y=m_position.top-hzdata[3*beginend+1];

			numpercontour[num++]=pointofcontour+1;
			//开始下一轮廓点的计数
			beginend=i+1;         //下一轮廓的起始点
			pointofcontour=0;     //下一轮廓点数计数
		}
	}	 
	return TRUE;
}

int  CGetHZinfo::decode(BYTE* sourceBuf, WORD* denstBuf,int num)
{
	BYTE ch1,ch2,loopNum,subMode,x,y,dx,dy;
	int sourcePtr, denstPtr, saveDenstPtr, denstPointNum,totalPoint;
	int j,k;
	sourcePtr=0;
	denstPtr=0;
	saveDenstPtr=denstPtr;
	denstPointNum=0;
	totalPoint=0;
	//AfxMessageBox("decode init is finished");
	for(;;)
	{
		ch1=sourceBuf[sourcePtr++];
		if((ch1&0xc0)==0xc0)                         //11 00 0000 mode
		{                                            //0xc0=11 00 00 00
			//AfxMessageBox("outline begin"); 
			//denstBuf[saveDenstPtr]=denstPointNum%256;
			//denstBuf[saveDenstPtr+1]=denstPointNum/256;
			//denstPointNum=0;
			//saveDenstPtr=denstPtr;
			//denstPtr+=2;
			if(denstPtr>0) denstBuf[denstPtr-1]=0x0003;
			ch2=sourceBuf[sourcePtr++];
			//totalPoint++;
			x=((ch1&0x3f)<<1)|(ch2>>7);                //
			y=ch2&0x7f;                                //0x7f=0111 1111,0x3f=0011 1111
			denstBuf[denstPtr++]=(WORD)x;               //0<x,y<128
			denstBuf[denstPtr++]=(WORD)y;               
			denstBuf[denstPtr++]=0x0001;               //online point
			denstPointNum++;
			totalPoint++;
			if(sourcePtr==num)
			{
				//denstBuf[saveDenstPtr]=denstPointNum%256;
				//denstBuf[saveDenstPtr+1]=denstPointNum/256;
				denstBuf[denstPtr-1]=0x0003;
				return(totalPoint);
			}
			continue;
		}

		if((ch1&0xc0)==0x40)               //  01 00 0000 mode
		{     
			subMode=ch1&0x30;                 //child mode 0x30=0011 0000
			loopNum=ch1&0x0f;                 //loop number point 0x0f=0000 1111
			denstPointNum+=loopNum;
			totalPoint+=loopNum;
			for(j=0;j<loopNum;j++)
			{
				ch1=sourceBuf[sourcePtr++];
				dx=ch1>>4;                       //前四位 0<dx,dy<16
				dy=ch1&0x0f;                     //后四围
				switch(subMode)
				{                                  //x,y的增量方向
				case 0x00:
					x+=dx; y+=dy;
					break;
				case 0x10:
					x-=dx; y+=dy;
					break;
				case 0x20:
					x-=dx; y-=dy;
					break;
				case 0x30:
					x+=dx;
					y-=dy;
					break;
				}
				denstBuf[denstPtr++]=(WORD)x;     //x,y不一定在0～128
				denstBuf[denstPtr++]=(WORD)y;
				denstBuf[denstPtr++]=0x0001;
			}
			if(sourcePtr==num)
			{
				//denstBuf[saveDenstPtr]=denstPointNum%256;
				//denstBuf[saveDenstPtr+1]=denstPointNum/256;
				denstBuf[denstPtr-1]=0x0003;
				return(totalPoint);
			}	
			continue;
		}

		if((ch1&0xc0)==0x00)                     //00 00 0000 mode
		{
			loopNum=ch1&0x3f;                     //后六位为循环次数
			denstPointNum+=loopNum;
			totalPoint+=loopNum;
			for(k=0;k<loopNum;k++)
			{
				ch1=sourceBuf[sourcePtr++];
				dx=ch1>>4;
				dy=ch1&0x0f;
				if((dx&0x08)==0x00)                  //0x08=0000 1000
					x+=dx;
				if((dx&0x08)==0x08)
					x-=(dx&0x07);                   //后三位为x增量
				if((dy&0x08)==0x00)
					y+=dy;
				if((dy&0x08)==0x08)
					y-=(dy&0x07);
				denstBuf[denstPtr++]=(WORD)x;      //x,y may not 0~128
				denstBuf[denstPtr++]=(WORD)y;
				denstBuf[denstPtr++]=0x0001;
			} 
			if(sourcePtr==num)
			{
				//denstBuf[saveDenstPtr]=denstPointNum%256;
				//denstBuf[saveDenstPtr+1]=denstPointNum/256;
				denstBuf[denstPtr-1]=0x0003;
				return (totalPoint);
			}
			continue;
		}

		if((ch1&0xc0)==0x80)	                 //10 00,0000 mode
		{
			subMode=ch1&0x30;
			switch(subMode)
			{
			case 0x00:                         //
				dx=ch1&0x0f;
				dy=sourceBuf[sourcePtr++];
				if((dx&0x08)==0x00)
					x+=dx;                     //0>dx>16
				if((dx&0x08)==0x08)
					x-=(dx&0x07);
				if((dy&0x80)==0x00)
					y+=dy;                     //0>dy>128
				if((dy&0x80)==0x80)
					y-=(dy&0x7f);              //x,y may not 0~128
				denstBuf[denstPtr++]=x;
				denstBuf[denstPtr++]=y;
				denstBuf[denstPtr++]=0x0001;
				denstPointNum++;
				totalPoint++;
				if(sourcePtr==num)
				{
					//denstBuf[saveDenstPtr]=denstPointNum%256;
					//denstBuf[saveDenstPtr+1]=denstPointNum/256;
					denstBuf[denstPtr-1]=0x0003;
					return(totalPoint);
				} 
				break;
			case 0x10:
				dy=ch1&0x0f;
				dx=sourceBuf[sourcePtr++];
				if((dx&0x80)==0x00)            //0<dx>128
					x+=dx;
				if((dx&0x80)==0x80)
					x-=(dx&0x7f);
				if((dy&0x08)==0x00)            //0>dy>16
					y+=dy;
				if((dy&0x08)==0x08)
					y-=(dy&0x07);
				denstBuf[denstPtr++]=(WORD)x;
				denstBuf[denstPtr++]=(WORD)y;
				denstBuf[denstPtr++]=0x0001;
				denstPointNum++;
				totalPoint++ ;
				if(sourcePtr==num)
				{
					//denstBuf[saveDenstPtr]=denstPointNum%256;
					//denstBuf[saveDenstPtr+1]=denstPointNum/256;
					denstBuf[denstPtr-1]=0x0003;
					return(totalPoint);
				}
				break;
			default:
				dx=sourceBuf[sourcePtr++];
				dy=sourceBuf[sourcePtr++];
				if((dx&0x80)==0x00)                  //0>dx>128
					x+=dx;                         //0>dy>128
				if((dx&0x80)==0x80)
					x-=(dx&0x7f);
				if((dy&0x80)==0x00)
					y+=dy;
				if((dy&0x80)==0x80)
					y-=(dy&0x7f);
				denstBuf[denstPtr++]=(WORD)x;
				denstBuf[denstPtr++]=(WORD)y;
				denstBuf[denstPtr++]=0x0001;
				denstPointNum++;
				totalPoint++;
				if(sourcePtr==num)
				{
					//denstBuf[saveDenstPtr]=denstPointNum%256;
					//denstBuf[saveDenstPtr+1]=denstPointNum/256;
					denstBuf[denstPtr-1]=0x0003;
					return(totalPoint);
				}
				break;
			}
			continue;
		}
	}
}
