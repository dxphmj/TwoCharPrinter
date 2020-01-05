#ifndef FILEMANAGEFORM_H
#define FILEMANAGEFORM_H

#include <QWidget>

namespace Ui {
class FileManageForm;
}

class FileManageForm : public QWidget
{
    Q_OBJECT

public:
    explicit FileManageForm(QWidget *parent = 0);
    ~FileManageForm();

private:
    Ui::FileManageForm *ui;
};

#endif // FILEMANAGEFORM_H
