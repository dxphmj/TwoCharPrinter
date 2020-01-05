#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(showFileMana()));

	ui->comboBox->addItem(QStringLiteral("Ó¢Óï"));
	ui->comboBox->addItem(QStringLiteral("ÊýÑ§"));
	ui->comboBox->addItem(QStringLiteral("ÓïÎÄ"));
	ui->comboBox->setCurrentIndex(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showFileMana()
{
	m_fileMana.show();
}
