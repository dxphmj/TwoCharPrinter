#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filemanageform.h"
#include "paramsettingform.h"

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

};

#endif // MAINWINDOW_H