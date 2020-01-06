#ifndef FILEMANAGEFORM_H
#define FILEMANAGEFORM_H

#include <QWidget>

namespace Ui {
class FilemanageForm;
}

class FilemanageForm : public QWidget
{
    Q_OBJECT

public:
    explicit FilemanageForm(QWidget *parent = 0);
    ~FilemanageForm();

private:
    Ui::FilemanageForm *ui;
};

#endif // FILEMANAGEFORM_H
