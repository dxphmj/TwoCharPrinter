#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filemanageform.h"
#include "paramsettingform.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
	FilemanageForm m_fileManage;
	ParamSettingForm m_paramsetting;

private slots:
	void fileManageBut_clicked();
	void paraManageBut_clicked();
	void GetDateTime();
public:
	QTimer  *myTimer;
};

#endif // MAINWINDOW_H
