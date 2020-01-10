#include "printsetting.h"

printSetting::printSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.printSetTabWid->setStyleSheet("QTabWidget:pane{ \
							  boder: -2px solid white;top: -2px;background-color:rgb(0, 0, 230);}\
							  QTabBar::tab{font:'¿¬Ìå' 16pt;color: white;height:50px; width:252px; background-color:rgb(0, 0, 230); margin-right: 2px; margin-bottom:-2px;}\
							  QTabBar::tab:selected{border:1px solid white;border-bottom-color: none;}\
							  QTabBar::tab:!selected{border-bottom: 3px solid white;}\
							  ");
}

printSetting::~printSetting()
{

}
