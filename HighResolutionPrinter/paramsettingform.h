#ifndef PARAMSETTINGFORM_H
#define PARAMSETTINGFORM_H

#include <QWidget>
#include "printsetting.h"
#include "sysSetting.h"
#include "countSetting.h"
#include "aboutMac.h"

namespace Ui {
class ParamSettingForm;
}

class ParamSettingForm : public QWidget
{
    Q_OBJECT

public:
    explicit ParamSettingForm(QWidget *parent = 0);
    ~ParamSettingForm();

private:
    Ui::ParamSettingForm *ui;

public:
	printSetting *m_printSetting;//创建窗口页面指针
	sysSetting  *m_sysSetting;
	countSetting  *m_countSetting;
	aboutMac  *m_aboutMac;

public:
	QString getNum(QString str);

private slots:
	void paraExitBut_clicked();
	void printSettingBut_clicked();
	void sysSettingBut_clicked();
	void countSettingBut_clicked();
	void aboutMacBut_clicked();

	void holdConfigurationBut_clicked(); 

};

#endif // PARAMSETTINGFORM_H
