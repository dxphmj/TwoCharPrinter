#include "printsetting.h"

printSetting::printSetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.printSpeedRedBut,SIGNAL(clicked()),this,SLOT(printSpeedRedBut()));
	connect(ui.printSpeedAddBut,SIGNAL(clicked()),this,SLOT(printSpeedAddBut()));
	connect(ui.printDelayRedBut,SIGNAL(clicked()),this,SLOT(printDelayRedBut()));
	connect(ui.printDelayAddBut,SIGNAL(clicked()),this,SLOT(printDelayAddBut()));
	connect(ui.synFrequencyRedBut,SIGNAL(clicked()),this,SLOT(synFrequencyRedBut()));
	connect(ui.synFrequencyAddBut,SIGNAL(clicked()),this,SLOT(synFrequencyAddBut()));
	connect(ui.printGrayRedBut,SIGNAL(clicked()),this,SLOT(printGrayRedBut()));
	connect(ui.printGrayAddBut,SIGNAL(clicked()),this,SLOT(printGrayAddBut()));
	connect(ui.repeteNumRedBut,SIGNAL(clicked()),this,SLOT(repeteNumRedBut()));
	connect(ui.repeteNumAddBut,SIGNAL(clicked()),this,SLOT(repeteNumAddBut()));
	connect(ui.repeteDelayRedBut,SIGNAL(clicked()),this,SLOT(repeteDelayRedBut()));
	connect(ui.repeteDelayAddBut,SIGNAL(clicked()),this,SLOT(repeteDelayAddBut()));
	connect(ui.voltRedBut,SIGNAL(clicked()),this,SLOT(voltRedBut()));
	connect(ui.voltAddBut,SIGNAL(clicked()),this,SLOT(voltAddBut()));
	connect(ui.PWRedBut,SIGNAL(clicked()),this,SLOT(PWRedBut()));
	connect(ui.PWAddBut,SIGNAL(clicked()),this,SLOT(PWAddBut()));
	connect(ui.offsetRedBut,SIGNAL(clicked()),this,SLOT(offsetRedBut()));
	connect(ui.offsetAddBut,SIGNAL(clicked()),this,SLOT(offsetAddBut()));
	connect(ui.flashSprayInternalRedBut,SIGNAL(clicked()),this,SLOT(flashSprayInternalRedBut()));
	connect(ui.flashSprayInternalAddBut,SIGNAL(clicked()),this,SLOT(flashSprayInternalAddBut()));
	connect(ui.flashSprayTimesRedBut,SIGNAL(clicked()),this,SLOT(flashSprayTimesRedBut()));
	connect(ui.flashSprayTimesAddBut,SIGNAL(clicked()),this,SLOT(flashSprayTimesAddBut()));

	ui.printSetTabWid->setStyleSheet("QTabWidget:pane{ \
							  boder: -2px solid white;top: -2px;background-color:rgb(0, 0, 230);}\
							  QTabBar::tab{font:'楷体' 16pt;color: white;height:50px; width:252px; background-color:rgb(0, 0, 230); margin-right: 2px; margin-bottom:-2px;}\
							  QTabBar::tab:selected{border:1px solid white;border-bottom-color: none;}\
							  QTabBar::tab:!selected{border-bottom: 3px solid white;}\
							  ");
	ui.printSetTabWid->setCurrentIndex(0);
	ui.synWheelCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									  QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									  ");
	ui.voiceCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									   QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									   ");
	ui.repetePrintCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									");
	ui.isCombineCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
										  QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
										  ");

	ui.flashSprayCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									");
	ui.adaptParaCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
										 QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
										 ");
	ui.isUVCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
										 QCheckBox{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
										 ");

	ui.XDPI100RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									  QRadioButton{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									  ");
	ui.XDPI150RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									  QRadioButton{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
										 ");
	ui.XDPI200RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									 QRadioButton{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									 ");
	ui.XDPI300RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									 QRadioButton{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									 ");
	ui.XDPI600RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									 QRadioButton{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									 ");

	ui.YDPI300RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									  QRadioButton{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									  ");
	ui.YDPI600RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									  QRadioButton{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									  ");

	ui.nozzleSel1RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									 QRadioButton{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									 ");
	ui.nozzleSel2RadioBut->setStyleSheet("QRadioButton::indicator {width:20px;height:20px;}\
									 QRadioButton{color:rgb(255, 255, 255);background-color: rgb(67,51, 139);}\
									 ");

	ui.trigComBox->addItem(QStringLiteral("外置电眼"),0);
	ui.trigComBox->addItem(QStringLiteral("自动"),1);
	ui.trigComBox->addItem(QStringLiteral("光电"),2);
	ui.trigComBox->addItem(QStringLiteral("编码器"),3);
	ui.trigComBox->addItem(QStringLiteral("光电编码"),4);
	ui.trigComBox->addItem(QStringLiteral("光自动"),5);

	ui.inkjetComBox->addItem(QStringLiteral("左喷",0));
	ui.inkjetComBox->addItem(QStringLiteral("右喷"),1);

	ui.printDirComBox->addItem(QStringLiteral("正向"),0);
	ui.printDirComBox->addItem(QStringLiteral("逆向"),1);

#ifdef BIG_CHAR
	//[打印风格]界面：“打印灰度”改为“墨点大小”；隐藏“喷墨方式”
	ui.printGrayLab->setText(QStringLiteral("墨点大小"));
	ui.inkjetLab->setVisible(false);
	ui.inkjetComBox->setVisible(false);
	//[高级设置]界面：隐藏“DPI”
	ui.DPILab->setVisible(false);
	ui.DPI150RadioBut->setVisible(false);
	ui.DPI200RadioBut->setVisible(false);
	ui.DPI300RadioBut->setVisible(false);
	ui.DPI600RadioBut->setVisible(false);
	//[喷头设置]界面：隐藏“墨水类型”
	ui.inkTypeLab->setVisible(false);
	ui.adaptParaCheckBox->setVisible(false);
	ui.inkVoltLab->setVisible(false);
	ui.voltRedBut->setVisible(false);
	ui.voltShowLab->setVisible(false);
	ui.voltAddBut->setVisible(false);
	ui.PWLab->setVisible(false);
	ui.PWRedBut->setVisible(false);
	ui.PWShowLab->setVisible(false);
	ui.PWAddBut->setVisible(false);

#else
	DPIradioBG = new QButtonGroup;
	DPIradioBG->addButton(ui.DPI150RadioBut,1);
	DPIradioBG->addButton(ui.DPI200RadioBut,2);
	DPIradioBG->addButton(ui.DPI300RadioBut,3);
	DPIradioBG->addButton(ui.DPI600RadioBut,4);
	ui.DPI150RadioBut->setChecked(3);

#endif

	XDPIradioBG = new QButtonGroup;
	XDPIradioBG->addButton(ui.XDPI100RadioBut,1);
	XDPIradioBG->addButton(ui.XDPI150RadioBut,2);
	XDPIradioBG->addButton(ui.XDPI200RadioBut,3);
	XDPIradioBG->addButton(ui.XDPI300RadioBut,4);
	XDPIradioBG->addButton(ui.XDPI600RadioBut,5);
	ui.XDPI100RadioBut->setChecked(1);

	YDPIradioBG = new QButtonGroup;
	YDPIradioBG->addButton(ui.YDPI300RadioBut,1);
	YDPIradioBG->addButton(ui.YDPI600RadioBut,2);
	ui.YDPI300RadioBut->setChecked(1);

	NozzleradioBG = new QButtonGroup;
	NozzleradioBG->addButton(ui.nozzleSel1RadioBut,1);
	NozzleradioBG->addButton(ui.nozzleSel2RadioBut,2);
	ui.nozzleSel1RadioBut->setChecked(1);

}

printSetting::~printSetting()
{
}

QString printSetting::getNum(QString str)
{
	//获取数字
	QString str1 = str;
	QString res;
	QChar ch;
	int j = 0;

	for(int i=0;i<str1.size();i++)
	{
		ch = str1.at(i);
		if(ch.toLatin1() <'0'||ch > '9')
		{
			if(j == 0)
			{
				if(ch.toLatin1() == '.')
				{
					res.append(ch);
					j++;
					continue;
				}	
				else
					continue;
			}	
			else
				continue;
		}
			
		if(((ch.toLatin1()-'0')%2)!=0||((ch.toLatin1()-'0')%2)!=1)
			res.append(ch);

	}

	return res;
}

void printSetting::printSpeedRedBut()
{
	QString str = ui.printSpeedShowLab->text();

	QString str2 = getNum(str);
	int printSpeedFactor = str2.toInt();
	if (printSpeedFactor>0)
	{
		printSpeedFactor-=5;
	} 
	else
	{
		printSpeedFactor=0;
	}
	ui.printSpeedShowLab->setText(QString("%1").arg(printSpeedFactor));
}

void printSetting::printSpeedAddBut()
{
	QString str = ui.printSpeedShowLab->text();
	QString str2 = getNum(str);
	int printSpeedFactor = str2.toInt();
	if (printSpeedFactor>=0)
	{
		printSpeedFactor+=5;
	} 
	else
	{
		printSpeedFactor=0;
	}
	ui.printSpeedShowLab->setText(QString("%1").arg(printSpeedFactor));
}

void printSetting::printDelayRedBut()
{
	QString str = ui.printDelayShowLab->text();
	QString str2 = getNum(str);
	int printDelayFactor = str2.toInt();
	if (printDelayFactor>0)
	{
		printDelayFactor-=2;
	} 
	else
	{
		printDelayFactor=0;
	}
	ui.printDelayShowLab->setText(QString("%1").arg(printDelayFactor));
}

void printSetting::printDelayAddBut()
{
	QString str = ui.printDelayShowLab->text();
	QString str2 = getNum(str);
	int printDelayFactor = str2.toInt();
	if (printDelayFactor >= 0)
	{
		printDelayFactor+=2;
	} 
	else
	{
		printDelayFactor=0;
	}
	ui.printDelayShowLab->setText(QString("%1").arg(printDelayFactor));
}

void printSetting::synFrequencyRedBut()
{
	QString str = ui.synFrequencyShowLab->text();
	QString str2 = getNum(str);
	int synFrequencyFactor = str2.toInt();
	if (synFrequencyFactor>1)
	{
		synFrequencyFactor-=1;
	} 
	else
	{
		synFrequencyFactor=1;
	}
	ui.synFrequencyShowLab->setText(QString("%1").arg(synFrequencyFactor));

}

void printSetting::synFrequencyAddBut()
{
	QString str = ui.synFrequencyShowLab->text();
	QString str2 = getNum(str);
	int synFrequencyFactor = str2.toInt();
	if (synFrequencyFactor>=1)
	{
		synFrequencyFactor+=1;
	} 
	else
	{
		synFrequencyFactor=1;
	}
	ui.synFrequencyShowLab->setText(QString("%1").arg(synFrequencyFactor));

}

void printSetting::printGrayRedBut()
{
	QString str = ui.printGrayShowLab->text();
	QString str2 = getNum(str);
	int printGrayFactor = str2.toInt();
	if (printGrayFactor>1)
	{
		printGrayFactor-=1;
	} 
	else
	{
		printGrayFactor=1;
	}
	ui.printGrayShowLab->setText(QString("%1").arg(printGrayFactor));

}

void printSetting::printGrayAddBut()
{
	QString str = ui.printGrayShowLab->text();
	QString str2 = getNum(str);
	int printGrayFactor = str2.toInt();
	if (printGrayFactor>=1)
	{
		printGrayFactor+=1;
	} 
	else
	{
		printGrayFactor=1;
	}
	ui.printGrayShowLab->setText(QString("%1").arg(printGrayFactor));

}

void printSetting::repeteNumRedBut()
{
	QString str = ui.repeteNumShowLab->text();
	QString str2 = getNum(str);
	int repeteNumFactor = str2.toInt();
	if (repeteNumFactor>1)
	{
		repeteNumFactor-=1;
	} 
	else
	{
		repeteNumFactor=1;
	}
	ui.repeteNumShowLab->setText(QString("%1").arg(repeteNumFactor));

}

void printSetting::repeteNumAddBut()
{
	QString str = ui.repeteNumShowLab->text();
	QString str2 = getNum(str);
	int repeteNumFactor = str2.toInt();
	if (repeteNumFactor>=1)
	{
		repeteNumFactor+=1;
	} 
	else
	{
		repeteNumFactor=1;
	}
	ui.repeteNumShowLab->setText(QString("%1").arg(repeteNumFactor));

}

void printSetting::repeteDelayRedBut()
{
	QString str = ui.repeteDelayShowLab->text();
	QString str2 = getNum(str);
	int repeteDelayFactor = str2.toInt();
	if (repeteDelayFactor>50)
	{
		repeteDelayFactor-=50;
	} 
	else
	{
		repeteDelayFactor=50;
	}
	ui.repeteDelayShowLab->setText(QString("%1").arg(repeteDelayFactor));

}

void printSetting::repeteDelayAddBut()
{
	QString str = ui.repeteDelayShowLab->text();
	QString str2 = getNum(str);
	int repeteDelayFactor = str2.toInt();
	if (repeteDelayFactor>=0)
	{
		repeteDelayFactor+=50;
	} 
	else
	{
		repeteDelayFactor=0;
	}
	ui.repeteDelayShowLab->setText(QString("%1").arg(repeteDelayFactor));

}

void printSetting::voltRedBut()
{
	QString str = ui.voltShowLab->text();
	QString str2 = getNum(str);
	double voltFactor = str2.toDouble();
	
	if (voltFactor>0)
	{
		voltFactor-=0.1;
	} 
	else
	{
		voltFactor=0;
	}
	ui.voltShowLab->setText(QString("%1").arg(voltFactor));

}

void printSetting::voltAddBut()
{
	QString str = ui.voltShowLab->text();
	QString str2 = getNum(str);
	double voltFactor = str2.toDouble();

	if (voltFactor>=0)
	{
		voltFactor+=0.1;
	} 
	else
	{
		voltFactor=0;
	}
	ui.voltShowLab->setText(QString("%1").arg(voltFactor));

}

void printSetting::PWRedBut()
{
	QString str = ui.PWShowLab->text();
	QString str2 = getNum(str);
	double PWFactor = str2.toDouble();

	if (PWFactor>0)
	{
		PWFactor-=0.1;
	} 
	else
	{
		PWFactor=0;
	}
	ui.PWShowLab->setText(QString("%1").arg(PWFactor));

}

void printSetting::PWAddBut()
{
	QString str = ui.PWShowLab->text();
	QString str2 = getNum(str);
	double PWFactor = str2.toDouble();

	if (PWFactor>=0)
	{
		PWFactor+=0.1;
	} 
	else
	{
		PWFactor=0;
	}
	ui.PWShowLab->setText(QString("%1").arg(PWFactor));

}

void printSetting::offsetRedBut()
{
	QString str = ui.offsetShowLab->text();
	QString str2 = getNum(str);
	int offsetFactor = str2.toInt();
	if (offsetFactor>0)
	{
		offsetFactor-=1;
	} 
	else
	{
		offsetFactor=0;
	}
	ui.offsetShowLab->setText(QString("%1").arg(offsetFactor));

}

void printSetting::offsetAddBut()
{
	QString str = ui.offsetShowLab->text();
	QString str2 = getNum(str);
	int offsetFactor = str2.toInt();
	if (offsetFactor>=0)
	{
		offsetFactor+=1;
	} 
	else
	{
		offsetFactor=0;
	}
	ui.offsetShowLab->setText(QString("%1").arg(offsetFactor));

}

void printSetting::flashSprayInternalRedBut()
{
	QString str = ui.flashSprayInternalShowLab->text();
	QString str2 = getNum(str);
	int flashSprayInternalFactor = str2.toInt();
	if (flashSprayInternalFactor>0)
	{
		flashSprayInternalFactor-=1;
	} 
	else
	{
		flashSprayInternalFactor=0;
	}
	ui.flashSprayInternalShowLab->setText(QString("%1").arg(flashSprayInternalFactor));

}

void printSetting::flashSprayInternalAddBut()
{
	QString str = ui.flashSprayInternalShowLab->text();
	QString str2 = getNum(str);
	int flashSprayInternalFactor = str2.toInt();
	if (flashSprayInternalFactor>=0)
	{
		flashSprayInternalFactor+=1;
	} 
	else
	{
		flashSprayInternalFactor=0;
	}
	ui.flashSprayInternalShowLab->setText(QString("%1").arg(flashSprayInternalFactor));

}

void printSetting::flashSprayTimesRedBut()
{
	QString str = ui.flashSprayTimesShowLab->text();
	QString str2 = getNum(str);
	int flashSprayTimesFactor = str2.toInt();
	if (flashSprayTimesFactor>2)
	{
		flashSprayTimesFactor-=1;
	} 
	else
	{
		flashSprayTimesFactor=1;
	}
	ui.flashSprayTimesShowLab->setText(QString("%1").arg(flashSprayTimesFactor));

}

void printSetting::flashSprayTimesAddBut()
{
	QString str = ui.flashSprayTimesShowLab->text();
	QString str2 = getNum(str);
	int flashSprayTimesFactor = str2.toInt();
	if (flashSprayTimesFactor>=1)
	{
		flashSprayTimesFactor+=1;
	} 
	else
	{
		flashSprayTimesFactor=1;
	}
	ui.flashSprayTimesShowLab->setText(QString("%1").arg(flashSprayTimesFactor));

}
