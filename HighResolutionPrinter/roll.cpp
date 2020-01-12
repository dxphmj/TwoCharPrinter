#include "roll.h"
#include <QPainter>
#include <QTimer>
//#include <QTextCodec>

roll::roll(QWidget *parent)
	: QLabel(parent)
{
	m_curIndex = 0;//当前角码
	m_showText = QStringLiteral("温馨提示：请不要在打印过程中拔掉墨盒，防止喷嘴堵塞。");//显示的文字
	m_charWidth = fontMetrics().width("a");//每个字符的宽度

	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &roll::updateIndex);
	//connect(timer, SIGNAL(timeout()), this, SLOT(updateIndex()));
	timer->start(100);
}

roll::~roll()
{

}

void roll::paintEvent(QPaintEvent *event)
{
	__super::paintEvent(event);
	QPainter painter(this);
	painter.drawText(0, 47, m_showText.mid(m_curIndex));
	painter.drawText(width() - m_charWidth*m_curIndex, 47, m_showText.left(m_curIndex));
}

void roll::updateIndex()
{
	update();
	m_curIndex++;
	if (m_curIndex*m_charWidth > width())
		m_curIndex = 0;
}
