#pragma once
#include "afxwin.h"


// CDiaCustomIcon 对话框

class CDiaCustomIcon : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaCustomIcon)

public:
	CDiaCustomIcon(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaCustomIcon();

// 对话框数据
	enum { IDD = IDD_DIA_CUSTOM_ICON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	virtual BOOL OnInitDialog();
	 
	afx_msg void OnPaint();
	CStatic m_drawPic;
public:
	bool m_arrData[16][16];

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	
};
