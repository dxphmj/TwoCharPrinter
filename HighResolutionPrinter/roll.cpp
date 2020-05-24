#include "roll.h"
#include <QPainter>
#include <QTimer>
#include "mainwindow.h"
#include "paramsettingform.h"
#include "syssetting.h"

//#include <QTextCodec>

roll::roll(QWidget *parent)
	: QLabel(parent)
{
	//this->installEventFilter(this);
	
	m_curIndex = 0;//当前角码
	m_charWidth = fontMetrics().width("a");//每个字符的宽度
	m_showText = QStringLiteral("温馨提示：请不要在打印过程中拔掉墨盒，防止喷嘴堵塞。");//显示的文字
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &roll::updateIndex);
	//connect(timer, SIGNAL(timeout()), this, SLOT(updateIndex()));
	timer->start(100);
	
}

roll::~roll()
{

}

void roll::paintEvent(QPaintEvent *event)
{
	//__super::paintEvent(event);
	QPainter painter(this);
	if (curlanguage == 0)
	{
		painter.drawText(m_curIndex*m_charWidth, 47, m_showText.left(m_charWidth*m_curIndex));
		painter.drawText(width(), 47, m_showText.left(width()- m_charWidth*m_curIndex));
	} 
	else
	{
		painter.drawText(0, 47, m_showText.mid(m_curIndex));
		painter.drawText(1.15*width() - m_charWidth*m_curIndex, 47, m_showText.left(m_curIndex));
	}
}

void roll::updateIndex()
{
	update();
	m_curIndex++;
	if (m_curIndex*m_charWidth > 1.15*width())
		m_curIndex = 0;
	chooseLan();
}

void roll::chooseLan()
{
	MainWindow *pMainWindow = qobject_cast<MainWindow*>(parent()->parent());
	if(pMainWindow == NULL) return;
	curlanguage = pMainWindow->m_paramsetting->m_sysSetting->returnIi();
	switch(curlanguage)
	{
	case 0://阿拉伯
		{
			m_showText = QStringLiteral("ملاحظة إيجابية: يرجى إزالة خراطيش الحبر أثناء عملية الطباعة لمنع الفتحات من الاختناق");
			break;
		}	  
	case 1://简体中文
		{
			m_showText = QStringLiteral("温馨提示:请不要在打印过程中拔掉墨盒，防止喷嘴堵塞。");
			break;
		}
	case 2:
		{
			m_showText = QStringLiteral("溫馨提示：請不要在列印過程中拔掉墨水匣，防止噴嘴堵塞。");
			break;
		}
	case 5://英语
		{
			m_showText = "Tip: Please do not remove the ink cartridge during printing to prevent the nozzle from blocking";
			break;
		}
	}

}
