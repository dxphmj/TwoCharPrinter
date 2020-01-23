#ifndef TIMECUSTOM_H
#define TIMECUSTOM_H

#include <QWidget>
#include <QLineEdit>

namespace Ui {
	class timeCustom;
}

class timeCustom : public QWidget
{
	Q_OBJECT

public:
	timeCustom(QWidget *parent = 0);
	~timeCustom();

private:
	Ui::timeCustom *ui;

private slots:
	void OKDateBut_clicked();
	void cancelDateBut_clicked();
};

#endif // TIMECUSTOM_H
