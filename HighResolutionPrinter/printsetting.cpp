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
	ui.synWheelCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									  QCheckBox{color:rgb(255, 255, 255);}\
									  ");
	ui.voiceCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									   QCheckBox{color:rgb(255, 255, 255);}\
									   ");
	ui.repetePrintCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									QCheckBox{color:rgb(255, 255, 255);}\
									");
	ui.flashSprayCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									QCheckBox{color:rgb(255, 255, 255);}\
									");
	ui.adaptParaCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
										 QCheckBox{color:rgb(255, 255, 255);}\
										 ");
	ui.DPI150RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									  QRadioButton{color:rgb(255, 255, 255);}\
										 ");
	ui.DPI200RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									 QRadioButton{color:rgb(255, 255, 255);}\
									 ");
	ui.DPI300RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									 QRadioButton{color:rgb(255, 255, 255);}\
									 ");
	ui.DPI600RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									 QRadioButton{color:rgb(255, 255, 255);}\
									 ");
	ui.nozzleSel1RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									 QRadioButton{color:rgb(255, 255, 255);}\
									 ");
	ui.nozzleSel2RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									 QRadioButton{color:rgb(255, 255, 255);}\
									 ");
}

printSetting::~printSetting()
{

}
