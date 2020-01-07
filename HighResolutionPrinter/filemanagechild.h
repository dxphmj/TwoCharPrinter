#ifndef FILEMANAGECHILD_H
#define FILEMANAGECHILD_H

#include <QWidget>
#include "ui_filemanagechild.h"

class FileManageChild : public QWidget
{
	Q_OBJECT

public:
	FileManageChild(QWidget *parent = 0);
	~FileManageChild();

private:
	Ui::FileManageChild ui;
};

#endif // FILEMANAGECHILD_H
