#ifndef SYSSETTING_H
#define SYSSETTING_H

#include <QWidget>
#include "ui_syssetting.h"
#include "printsetting.h"


class MainWindow;

class sysSetting : public QWidget
{
	Q_OBJECT

public:
	sysSetting(QWidget *parent = 0);
	~sysSetting();
	printSetting *m_printSetting;

public:
	Ui::sysSetting ui;

	MainWindow* m_pMainWindow;
	int m_SelLanguage;
	int returnIi()
	{
		return m_SelLanguage;
	}

private slots:
	void seleSysLanguage();
	void addYearBut();
	void reduceYearBut();
	void addMonthBut();
	void reduceMonthBut();
	void addDayBut();
	void reduceDayBut();
	void addHourBut();
	void reduceHourBut();
	void addMinBut();
	void reduceMinBut();
	void addSecondBut();
	void reduceSecondBut();

};

#endif // SYSSETTING_H
