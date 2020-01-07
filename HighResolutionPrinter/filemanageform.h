#ifndef FILEMANAGEFORM_H
#define FILEMANAGEFORM_H

#include <QWidget>
#include <QStackedWidget>
#include "fileeditchild.h"
#include "filemanagechild.h"

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
	 
private:

	FileManageChild *FormFileManageChild;//创建窗口页面指针
	FileEditChild  *FormFileEditChild;

private slots:
	void exitBut_clicked();
	void editFileBut_clicked();
	void manageFileBut_clicked();
};

#endif // FILEMANAGEFORM_H
