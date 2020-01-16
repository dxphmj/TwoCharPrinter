#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

class FilemanageForm;
class ParamSettingForm;
class ClassMessage;

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
 	ClassMessage* m_PrinterMes; //¥Ú”°º‡øÿ”√
	void RefreshWindow();

private:
    Ui::MainWindow *ui;
	FilemanageForm *m_fileManage;
	ParamSettingForm *m_paramsetting;

private slots:
	void fileManageBut_clicked();
	void paraManageBut_clicked();
	void closeBut_clicked();

	bool eventFilter(QObject *watched, QEvent *event);

	void GetDateTime();

public:
	QTimer  *myTimer;
};

#endif // MAINWINDOW_H
