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

private:
	printSetting *m_printSetting;//创建窗口页面指针
	sysSetting  *m_sysSetting;
	countSetting  *m_countSetting;
	aboutMac  *m_aboutMac;

private slots:
	void quitBut_clicked();
	void printSettingBut_clicked();
	void sysSettingBut_clicked();
	void countSettingBut_clicked();
	void aboutMacBut_clicked();
};

#endif // PARAMSETTINGFORM_H
