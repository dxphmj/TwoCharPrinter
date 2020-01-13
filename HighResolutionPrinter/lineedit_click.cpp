#include "lineedit_click.h"

lineedit_click::lineedit_click(QWidget *parent)
	: QLineEdit(parent)
{

}

lineedit_click::~lineedit_click()
{

}

//重写mousePressEvent事件,检测事件类型是不是点击了鼠标左键
void lineedit_click::mousePressEvent(QMouseEvent *event) {
	//如果单击了就触发clicked信号
	if (event->button() == Qt::LeftButton) {
		//触发clicked信号
		emit clicked();
	}
	//将该事件传给父类处理
	QLineEdit::mousePressEvent(event);
}
