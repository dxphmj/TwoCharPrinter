#include "automessagebox.h"

CAutoMessageBox::CAutoMessageBox(QWidget *parent):QMessageBox(parent)
	,m_width(0)
	,m_high(0)
{

}

void CAutoMessageBox::AutoSetSize(int width, int high)
{
	m_width = width;
	m_high  = high;
}

void CAutoMessageBox::resizeEvent(QResizeEvent *event)
{
	setFixedSize(m_width,m_high);
}