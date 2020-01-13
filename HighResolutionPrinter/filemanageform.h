#ifndef FILEMANAGEFORM_H
#define FILEMANAGEFORM_H

#include <QWidget>
#include <QStackedWidget>
#include "fileeditchild.h"
#include "filemanagechild.h"
#include "variblewidget.h"
#include "timecustom.h"

namespace Ui {
class FilemanageForm;
}

class FilemanageForm : public QWidget
{
    Q_OBJECT

public:
    FilemanageForm(QWidget *parent = 0);
    ~FilemanageForm();

private:
    Ui::FilemanageForm *ui;
	 
private:

	FileManageChild *FormFileManageChild;//创建窗口页面指针
	FileEditChild  *FormFileEditChild;
	varibleWidget  *fontVarWidget;
	timeCustom  *timeCustomWidget;

private slots:
	void exitBut_clicked();
	void editFileBut_clicked();
	void manageFileBut_clicked();

public:
	void timeCustomCall();
	void variableWidgetCall();
};

#endif // FILEMANAGEFORM_H
