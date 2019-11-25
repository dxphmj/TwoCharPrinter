// DiaPrintEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaPrintEdit.h"
#include "afxdialogex.h"


// CDiaPrintEdit 对话框

IMPLEMENT_DYNAMIC(CDiaPrintEdit, CDialogEx)

CDiaPrintEdit::CDiaPrintEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaPrintEdit::IDD, pParent)
{
	m_bDesign = true; 
	m_nStepPixels = 5;
}

CDiaPrintEdit::~CDiaPrintEdit()
{
}

void CDiaPrintEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COM_PARAM, m_ComParam);
	DDX_Control(pDX, IDC_COM_DATA, m_ComData);
	DDX_Control(pDX, IDC_STATIC_DESIGN_AREA, m_designArea);
}


BEGIN_MESSAGE_MAP(CDiaPrintEdit, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUT_DESIGN_VIEW, &CDiaPrintEdit::OnBnClickedButDesignView)
	ON_BN_CLICKED(IDC_BUT_PRINT_VIEW, &CDiaPrintEdit::OnBnClickedButPrintView)
	ON_BN_CLICKED(IDC_BUT_DESIGN_CLEAN, &CDiaPrintEdit::OnBnClickedButDesignClean)
	ON_BN_CLICKED(IDC_BUT_DESIGN_SAVE, &CDiaPrintEdit::OnBnClickedButDesignSave)
	ON_BN_CLICKED(IDC_BUT_OPEN_DESIGN, &CDiaPrintEdit::OnBnClickedButOpenDesign)
	ON_BN_CLICKED(IDC_BUT_INSERT_PARAM, &CDiaPrintEdit::OnBnClickedButInsertParam)
	ON_BN_CLICKED(IDC_BUT_INSERT_DADA, &CDiaPrintEdit::OnBnClickedButInsertDada)
END_MESSAGE_MAP()


// CDiaPrintEdit 消息处理程序


BOOL CDiaPrintEdit::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_ComParam.SendMessage(CB_SETITEMHEIGHT,-1,43); //改变组合框的高度
	m_ComData.SendMessage(CB_SETITEMHEIGHT,-1,43);

	m_ComParam.SendMessage(CB_SETITEMHEIGHT,0,20);
	m_ComData.SendMessage(CB_SETITEMHEIGHT,0,20);

	for (int i = 1; i <= 10; i++)
	{
		CString str;
		str.Format("%d",i);
		m_ComParam.InsertString(i-1,str);
	}
	m_ComParam.SetCurSel(0);

	m_ComData.InsertString(0,"系统日期");
	m_ComData.InsertString(1,"有效日期");
	m_ComData.InsertString(2,"系统时间");
	m_ComData.InsertString(3,"计数1");
	m_ComData.InsertString(4,"计数2");
	m_ComData.InsertString(5,"计数3");
	m_ComData.InsertString(6,"字母计数");
	m_ComData.InsertString(7,"班次码");

	m_ComData.SetCurSel(0);	 
	m_designArea.SetWindowPos(NULL,-1,-1,195*5,16*5, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDiaPrintEdit::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	CDC* pDC = m_designArea.GetDC();
	if(m_bDesign)
	{
		//先清除打印预览内容
		CBrush cbrush;
		CBrush* pBrush; //旧笔刷
		CRect rect;
		m_designArea.GetClientRect(&rect);
		cbrush.CreateSolidBrush(RGB(255,255,255)); 
		pBrush=pDC->SelectObject(&cbrush); //载入笔刷
		pDC->Rectangle(&rect); //绘制矩形		
		pDC->SelectObject(pBrush); //恢复笔刷
		cbrush.DeleteObject();
		pBrush->DeleteObject();

		//绘制设计结果

	}
	else
	{
		 
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(252,157,154)); 
		CPen* pOldPen; 
		pOldPen = pDC->SelectObject(&cPen); //载入笔刷
		
		for(int i = 0; i < m_nRowSum; i++)
		{
			pDC->MoveTo(0,i*m_nStepPixels);
			pDC->LineTo(m_nStepPixels*m_nColSum,i*m_nStepPixels);
		}
		for(int i = 0; i < m_nColSum; i++)
		{
			pDC->MoveTo(i*m_nStepPixels,0);
			pDC->LineTo(i*m_nStepPixels,m_nStepPixels*m_nRowSum);
		}
		pDC->SelectObject(pOldPen);
		cPen.DeleteObject();
		pOldPen->DeleteObject();

		CBrush cbrush;
		CBrush* pBrush; //旧笔刷
		CRect rect;
		m_designArea.GetClientRect(&rect);
		cbrush.CreateSolidBrush(RGB(0,0,0)); 
		pBrush=pDC->SelectObject(&cbrush); //载入笔刷

	   //pDC->Rectangle(&rect); //绘制矩形
		for(int i = 0; i < m_nRowSum; i++)
			for(int j = 0; j < m_nColSum; j++)
				DrawOnePoint(pDC,i,j);

		pDC->SelectObject(pBrush); //恢复笔刷
		cbrush.DeleteObject();
		pBrush->DeleteObject();
	}

	ReleaseDC(pDC); 
}

void CDiaPrintEdit::OnBnClickedButDesignView()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bDesign = true; 
	OnPaint();
}

void CDiaPrintEdit::OnBnClickedButPrintView()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bDesign = false;
 	OnPaint();
}

void CDiaPrintEdit::DrawOnePoint(CDC* pDC ,int row,int col)
{
	// TODO: 在此添加控件通知处理程序代码

	CRect rect(col*m_nStepPixels,row*m_nStepPixels,(col+1)*m_nStepPixels,(row+1)*m_nStepPixels);

	pDC->Ellipse(&rect); 
}


void CDiaPrintEdit::OnBnClickedButDesignClean()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDiaPrintEdit::OnBnClickedButDesignSave()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDiaPrintEdit::OnBnClickedButOpenDesign()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDiaPrintEdit::OnBnClickedButInsertParam()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDiaPrintEdit::OnBnClickedButInsertDada()
{
	// TODO: 在此添加控件通知处理程序代码
}
