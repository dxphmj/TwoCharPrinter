// DiaCustomIcon.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaCustomIcon.h"
#include "afxdialogex.h"



// CDiaCustomIcon 对话框

IMPLEMENT_DYNAMIC(CDiaCustomIcon, CDialogEx)

	
int nStep = 10;

CDiaCustomIcon::CDiaCustomIcon(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaCustomIcon::IDD, pParent)
{
	
}

CDiaCustomIcon::~CDiaCustomIcon()
{
}

void CDiaCustomIcon::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_drawPic);
}


BEGIN_MESSAGE_MAP(CDiaCustomIcon, CDialogEx)
	
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	
END_MESSAGE_MAP()


// CDiaCustomIcon 消息处理程序





BOOL CDiaCustomIcon::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for(int i = 0; i < 16; i++)
		for(int j = 0; j < 16; j++)
			m_arrData[i][j] = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDiaCustomIcon::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	CDC *pDC = m_drawPic.GetDC();
	//pDC->SetPixel(10,10,RGB(0,0,0));
	int i;
	//int nStep = 10;
	
		for (i = 0; i <= 16; i++)
		{		 
			pDC->MoveTo(0,i*nStep);
			pDC->LineTo(16*nStep,i*nStep);			 
		}

		for (i = 0; i <= 16; i++)
		{		 
			pDC->MoveTo(i*nStep,0);
			pDC->LineTo(i*nStep,16*nStep);			 
		}

		//根据m_arrData画点

		for(int nRow = 0; nRow < 16; nRow++)
			for(int nCol = 0; nCol < 16; nCol++)
			{
				if(m_arrData[nRow][nCol])
				{
					//画点,找画椭圆的调用函数
					//pDC->SetPixel(i*nStep+nStep/2,j*nStep+nStep/2,RGB(255,0,0));
					CBrush *pOldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);

					//选入画笔
					CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
					CPen *pOldPen = pDC->SelectObject(&pen);

					pDC->Ellipse(nRow*nStep,nCol*nStep,(nRow+1)*nStep,(nCol+1)*nStep);

					//恢复画笔
					pDC->SelectObject(pOldPen);

					//恢复画刷
					pDC->SelectObject(pOldBrush);
					
				}
			}
		
		
	
	
	// 不为绘图消息调用 CDialogEx::OnPaint()
}



void CDiaCustomIcon::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//////////////////////////////////////////////////////////////////////////
	/*CDC *pDC = m_drawPic.GetDC();
	CString str;
	str.Format(TEXT("%d,%d"),point.x,point.y);
	pDC->FillSolidRect(0,0,100,100,GetSysColor(COLOR_WINDOW));
	pDC->TextOut(0,0,str);
	ReleaseDC(pDC);*/
	//////////////////////////////////////////////////////////////////////////
	GetCursorPos(&point);
	//然后得到static控件的rect坐标
	CRect pRect;
	CWnd *pWnd = GetDlgItem(IDC_PIC);
	pWnd->GetClientRect(&pRect);
	//最后把当前鼠标的坐标转化为相对于rect的坐标
	pWnd->ScreenToClient(&point);
	CDialogEx::OnLButtonDown(nFlags, point);
	int nRow;
	int nCol;
	//GetPosition(point,&nRow,&nCol)
	//bool bIn = GetPosition(point,&nRow,&nCol);
	//给数组赋值
	
	if (point.x <= 16*nStep && point.y <= 16*nStep )
	{
		nRow = point.x / nStep;
		nCol = point.y / nStep;
		m_arrData[nRow][nCol] = 1; //给数组赋值
	}
		
}