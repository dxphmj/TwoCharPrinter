#ifndef PARAMSETTINGFORM_H
#define PARAMSETTINGFORM_H

#include <QWidget>

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
};

#endif // PARAMSETTINGFORM_H
