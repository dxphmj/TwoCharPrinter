#ifndef FILEMANAGECHILD_H
#define FILEMANAGECHILD_H

#include <QWidget>
#include <QDir>  
#include <QListWidgetItem>  
#include <QFileInfoList>  
#include <QListWidget>  
#include <QLineEdit>  
#include <QVBoxLayout>  
#include <QIcon>  
#include <QStringList>

class keyboard;
class ClassMessage;

namespace Ui {
	class FileManageChild;
}

class FileManageChild : public QWidget
{
	Q_OBJECT

public:
	FileManageChild(QWidget *parent = 0);
	~FileManageChild();
	Ui::FileManageChild *ui;  
	ClassMessage*  m_pPrinterMes;
	keyboard  *keyboardWidget;

	void showFileInfoList(QFileInfoList list);
	void paintDot();
	void PreviewSaveFile();
	QString rootStr;
	char* GetCurXmlFile();
	QFileInfoList list;
	bool boolFileSelected;
	bool boolSaveAsBtn_Clicked;

public slots:  
	void ShowLocalFilePath();
	void PreviewLocalFile();
	void SetButtonEnableOn();
	void SetButtonEnableOff();
	void slotShow(QDir dir); 
	void loadSeleFileBut_clicked();
	void editSeleFileBut_clicked();
	void fileNmaeLineEdit_click();
	void OKFileNameBut_clicked();
	//用于实现更改文件名的槽函数
	//void ChangeFileName();

protected:
	bool eventFilter(QObject *watched, QEvent *event);
};

#endif // FILEMANAGECHILD_H
