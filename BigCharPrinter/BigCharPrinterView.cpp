
// BigCharPrinterView.cpp : CBigCharPrinterView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "BigCharPrinter.h"
#endif

#include "BigCharPrinterDoc.h"
#include "BigCharPrinterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBigCharPrinterView

IMPLEMENT_DYNCREATE(CBigCharPrinterView, CFormView)

BEGIN_MESSAGE_MAP(CBigCharPrinterView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CBigCharPrinterView 构造/析构

CBigCharPrinterView::CBigCharPrinterView()
	: CFormView(CBigCharPrinterView::IDD)
{
	// TODO: 在此处添加构造代码

}

CBigCharPrinterView::~CBigCharPrinterView()
{
}

void CBigCharPrinterView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CBigCharPrinterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CBigCharPrinterView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CRect rc;
	GetClientRect(rc);
	if (!m_tab.Create(CMFCTabCtrl::STYLE_3D_ONENOTE, rc, this, 3000, CMFCTabCtrl::LOCATION_TOP,0))
	{
		return ;     
	}

	m_dlgPrintEdit = new CDiaPrintEdit;
	m_dlgPrintControl = new CDiaPrintControl;
	m_dlgMouthClean = new CDiaMouthClean;
	m_dlgPrintParam = new CDiaPrintParam;
	m_dlgCustomIcon = new CDiaCustomIcon;
	m_dlgSystemSetting = new CDiaSystemSetting;

	m_dlgPrintEdit->Create(IDD_DIA_PRINT_EDIT,&m_tab);
	m_dlgPrintEdit->SetFont(&afxGlobalData.fontRegular);	 

	m_dlgPrintControl->Create(IDD_DIA_PRINT_CONTROL,&m_tab);
	m_dlgPrintControl->SetFont(&afxGlobalData.fontBold);
 
	m_dlgMouthClean->Create(IDD_DIA_MOUTH_CLEAN,&m_tab);
	m_dlgMouthClean->SetFont(&afxGlobalData.fontDefaultGUIBold);

	m_dlgPrintParam->Create(IDD_DIA_PRINT_PARAM,&m_tab);
	m_dlgPrintParam->SetFont(&afxGlobalData.fontRegular);

	m_dlgCustomIcon->Create(IDD_DIA_CUSTOM_ICON,&m_tab);
	m_dlgCustomIcon->SetFont(&afxGlobalData.fontBold);

	m_dlgSystemSetting->Create(IDD_DIA_SYSTEM_SETTING,&m_tab);
	m_dlgSystemSetting->SetFont(&afxGlobalData.fontDefaultGUIBold);

	m_tab.AddTab(m_dlgPrintEdit,L"打印编辑");
	m_tab.AddTab(m_dlgPrintControl,L"打印设置");
	m_tab.AddTab(m_dlgMouthClean,L"喷头清洗");
	m_tab.AddTab(m_dlgPrintParam,L"打印变量");
	m_tab.AddTab(m_dlgCustomIcon,L"图案编辑");
	m_tab.AddTab(m_dlgSystemSetting,L"系统设置");


	m_tab.EnableActiveTabCloseButton();//是否添加关闭选项卡按钮
	m_tab.SetActiveTab(0); //激活选项卡,以当前选项卡为第一页。
}

void CBigCharPrinterView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBigCharPrinterView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBigCharPrinterView 诊断

#ifdef _DEBUG
void CBigCharPrinterView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBigCharPrinterView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CBigCharPrinterDoc* CBigCharPrinterView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBigCharPrinterDoc)));
	return (CBigCharPrinterDoc*)m_pDocument;
}
#endif //_DEBUG


// CBigCharPrinterView 消息处理程序
