#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "filemanageform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	connect(ui->fileManageBut,SIGNAL(clicked()),this,SLOT(fileManageBut_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileManageBut_clicked()
{
	m_fileManage.show();
}
