#ifndef FILEMANAGECHILD_H
#define FILEMANAGECHILD_H

#include <QWidget>
#include "ui_filemanagechild.h"
#include <QDir>  
#include <QListWidgetItem>  
#include <QFileInfoList>  
#include <QListWidget>  
#include <QLineEdit>  
#include <QVBoxLayout>  
#include <QIcon>  
#include <QStringList>
#include "ClassMessage.h"

using namespace MyNameSpace;

class FileManageChild : public QWidget
{
	Q_OBJECT

public:
	FileManageChild(QWidget *parent = 0);
	~FileManageChild();
	ClassMessage  m_PrinterMes2;
	void showFileInfoList(QFileInfoList list);
	void paintDot();
	QString rootStr;

public slots:  
	void ShowLocalFilePath();
	void PreviewLocalFile();
	void slotShow(QDir dir);  

private:
	Ui::FileManageChild ui;
	QLineEdit *fileLineEdit;  
	QListWidget *fileListWidget;  
	QFileInfoList list;

protected:
	bool eventFilter(QObject *watched, QEvent *event);
};

#endif // FILEMANAGECHILD_H
