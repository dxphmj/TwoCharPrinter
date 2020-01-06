#include "filemanageform.h"
#include "ui_filemanageform.h"

FilemanageForm::FilemanageForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilemanageForm)
{
    ui->setupUi(this);
}

FilemanageForm::~FilemanageForm()
{
    delete ui;
}
