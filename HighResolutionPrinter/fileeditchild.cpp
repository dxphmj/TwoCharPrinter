#include "fileeditchild.h"
#include "filemanageform.h"


FileEditChild::FileEditChild(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.editBut,SIGNAL(clicked()),this,SLOT(FileEditChild_clicked()));
	ui.editPreviewText->installEventFilter(this);

//	setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);hide();
//	this->setParent(parent);

	connect(ui.variableBut,SIGNAL(clicked()),this,SLOT(variableBut_clicked()));
}

FileEditChild::~FileEditChild()
{

}

bool FileEditChild::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui.editPreviewText && event->type() == QEvent::Paint)
	{
	paintDot();
	}
	return QWidget::eventFilter(watched,event);
}

void FileEditChild::paintDot()
{
	QPainter painter(ui.editPreviewText);//有个QWidget叫tab_2，在那里添加
	m_PrinterMes.DrawDot(&painter);
	/*
	painter.setRenderHint(QPainter::Antialiasing,true);
	painter.setPen(QPen(Qt::white,12,Qt::DashDotDotLine,Qt::RoundCap));
	painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
	painter.drawEllipse(80,80,400,240); */
}

void FileEditChild::variableBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->variableWidgetCall();
	
}