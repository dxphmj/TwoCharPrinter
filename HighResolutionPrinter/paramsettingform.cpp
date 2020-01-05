#include "paramsettingform.h"
#include "ui_paramsettingform.h"

ParamSettingForm::ParamSettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParamSettingForm)
{
    ui->setupUi(this);
}

ParamSettingForm::~ParamSettingForm()
{
    delete ui;
}
