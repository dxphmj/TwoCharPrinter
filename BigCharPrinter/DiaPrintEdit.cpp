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

}

CDiaPrintEdit::~CDiaPrintEdit()
{
}

void CDiaPrintEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaPrintEdit, CDialogEx)
<<<<<<< Updated upstream
=======
	ON_LBN_SELCHANGE(IDC_LIST10, &CDiaPrintEdit::OnLbnSelchangeList10)
>>>>>>> Stashed changes
END_MESSAGE_MAP()


// CDiaPrintEdit 消息处理程序
<<<<<<< Updated upstream
=======


void CDiaPrintEdit::OnLbnSelchangeList10()
{
	// TODO: 在此添加控件通知处理程序代码
}
>>>>>>> Stashed changes
