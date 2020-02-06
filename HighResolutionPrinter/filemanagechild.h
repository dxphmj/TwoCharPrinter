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
#include <QMessageBox>

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
	void informationMessage();

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
	void delSeleFileBut_clicked();
	
protected:
	bool eventFilter(QObject *watched, QEvent *event);
};

#endif // FILEMANAGECHILD_H
