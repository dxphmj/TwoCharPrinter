#include "fileeditchild.h"
#include "filemanageform.h"
#include "ClassMessage.h"

FileEditChild::FileEditChild(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.editBut,SIGNAL(clicked()),this,SLOT(FileEditChild_clicked()));
	ui.editPreviewText->installEventFilter(this);

	connect(ui.variableBut,SIGNAL(clicked()),this,SLOT(variableBut_clicked()));

	m_PrinterMes.ReadObjectsFromXml("User\\Label\\logo.lab");
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
	QPainter painter(ui.editPreviewText);
	m_PrinterMes.DrawDot(&painter);	
}

void FileEditChild::paintEvent(QPaintEvent *)
{
//	QPainter painter(ui.editPreviewText);
//	m_PrinterMes.DrawDot(&painter);

}

void FileEditChild::variableBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->variableWidgetCall();
}