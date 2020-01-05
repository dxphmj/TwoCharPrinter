#include "filemanageform.h"
#include "ui_filemanageform.h"

FileManageForm::FileManageForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileManageForm)
{
    ui->setupUi(this);
}

FileManageForm::~FileManageForm()
{
    delete ui;
}
