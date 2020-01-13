#ifndef LINEEDIT_CLICK_H
#define LINEEDIT_CLICK_H

#include <QLineEdit>
#include <QMouseEvent>


class lineedit_click : public QLineEdit
{
	Q_OBJECT

public:
	lineedit_click(QWidget *parent);
	~lineedit_click();

protected:
	//重写mousePressEvent事件
	virtual void mousePressEvent(QMouseEvent *event);

signals:
	//自定义clicked()信号,在mousePressEvent事件发生时触发
	void clicked();

public slots:

private:
	
};

#endif // LINEEDIT_CLICK_H
