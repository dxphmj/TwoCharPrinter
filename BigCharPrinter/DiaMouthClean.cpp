// DiaMouthClean.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaMouthClean.h"
#include "afxdialogex.h"


// CDiaMouthClean 对话框

IMPLEMENT_DYNAMIC(CDiaMouthClean, CDialogEx)

CDiaMouthClean::CDiaMouthClean(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaMouthClean::IDD, pParent)
{
	int a = 5;
	int c = 3;
}

CDiaMouthClean::~CDiaMouthClean()
{
	int b = 6;
	int d = 9;
	int e = 10;

}


void CDiaMouthClean::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaMouthClean, CDialogEx)
END_MESSAGE_MAP()


// CDiaMouthClean 消息处理程序
