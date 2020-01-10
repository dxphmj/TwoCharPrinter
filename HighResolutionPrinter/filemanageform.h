#ifndef FILEMANAGEFORM_H
#define FILEMANAGEFORM_H

#include <QWidget>
#include <QStackedWidget>
#include "fileeditchild.h"
#include "filemanagechild.h"
#include "variblewidget.h"

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

	FileManageChild *FormFileManageChild;//��������ҳ��ָ��
	FileEditChild  *FormFileEditChild;
	varibleWidget  *fontVarWidget;
	int m_nTmp;

private slots:
	void exitBut_clicked();
	void editFileBut_clicked();
	void manageFileBut_clicked();

public slots:
	void variableWidgetCall();
};

#endif // FILEMANAGEFORM_H