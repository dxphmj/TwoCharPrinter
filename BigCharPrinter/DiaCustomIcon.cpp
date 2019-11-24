// DiaCustomIcon.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaCustomIcon.h"
#include "afxdialogex.h"


// CDiaCustomIcon 对话框

IMPLEMENT_DYNAMIC(CDiaCustomIcon, CDialogEx)

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
	DDX_Control(pDX, IDC_ICON_EDIT, m_IconEdit);
}


BEGIN_MESSAGE_MAP(CDiaCustomIcon, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDiaCustomIcon 消息处理程序


BOOL CDiaCustomIcon::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDiaCustomIcon::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码

	CDC* pDC = m_IconEdit.GetDC();
	for(int i = 0; i < 100; i=i+3)
		pDC->SetPixel(10,10+i,COLORREF(RGB(0,0,0)));

	//pDC->MoveTo(0,0);
	//pDC->LineTo(10,10);


	// 不为绘图消息调用 CDialogEx::OnPaint()
}
