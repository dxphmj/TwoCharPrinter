#ifndef FILEMANAGEFORM_H
#define FILEMANAGEFORM_H

#include <QWidget>
#include <QStackedWidget>

class FileManageChild;
class FileEditChild;
class varibleWidget;
class variableBarCode;
class variableQR;
class variableDM;
class timeCustom;
class ClassMessage;

namespace Ui {
class FilemanageForm;
}

class FilemanageForm : public QWidget
{
    Q_OBJECT

public:
    FilemanageForm(QWidget *parent = 0);
    ~FilemanageForm();
    Ui::FilemanageForm *ui;
	ClassMessage *m_ClassMes;
	 
public:
	FileManageChild *FormFileManageChild;//创建窗口页面指针
	FileEditChild  *FormFileEditChild;
	varibleWidget  *fontVarWidget;
	variableBarCode  *BarCodeWidget;
	variableQR  *QRWidget;
	variableDM  *DMWidget;

	timeCustom  *timeCustomWidget;

private slots:
	void exitBut_clicked();
	void editFileBut_clicked();
	void manageFileBut_clicked();

public:
	void timeCustomCall();
	void variableWidgetCall();
	void variableBarCodeWidgetCall();
	void variableQRWidgetCall();
	void variableDMWidgetCall();
	void FileEditChildWidgetCall();
	void FileManageChildWidgetCall();
};

#endif // FILEMANAGEFORM_H
