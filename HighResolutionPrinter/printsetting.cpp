#include "printsetting.h"
#include "numkeyboard.h"

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
	connect(ui.synWheelCheckBox,SIGNAL(stateChanged(int)),this,SLOT(synWheelCheckBox_valueChanged(int)));
	connect(ui.trigComBox,SIGNAL(currentIndexChanged(int)),this,SLOT(trigComBox_ValueChanged(int)));
	connect(ui.encoderResLineEdit,SIGNAL(clicked()),this,SLOT(encoderResLineEdit_clicked()));
	connect(ui.wheelDiameterLineEdit,SIGNAL(clicked()),this,SLOT(wheelDiameterLineEdit_clicked()));
	connect(ui.pulseWidthLineEdit,SIGNAL(clicked()),this,SLOT(pulseWidthLineEdit_clicked()));

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

	ui.trigComBox->addItem(QStringLiteral("自动"),0);
	ui.trigComBox->addItem(QStringLiteral("光电"),1);
	ui.trigComBox->addItem(QStringLiteral("编码器"),2);
	ui.trigComBox->addItem(QStringLiteral("光电编码"),3);
	ui.trigComBox->addItem(QStringLiteral("光自动"),4);

	ui.inkjetComBox->addItem(QStringLiteral("左列"),0);
	ui.inkjetComBox->addItem(QStringLiteral("右列"),1);
	ui.inkjetComBox->addItem(QStringLiteral("左右交替"),2);
	ui.inkjetComBox->addItem(QStringLiteral("左+右列"),3);

	ui.printDirComBox->addItem(QStringLiteral("正向"),0);
	ui.printDirComBox->addItem(QStringLiteral("逆向"),1);

	ui.horizonalReverseComBox->addItem(QStringLiteral("off"),0);
	ui.horizonalReverseComBox->addItem(QStringLiteral("on"),1);
	ui.verticalReverseComBox->addItem(QStringLiteral("off"),0);
	ui.verticalReverseComBox->addItem(QStringLiteral("on"),1);

#ifdef BIG_CHAR
	//[打印风格]界面：“打印灰度”改为“墨点大小”；隐藏“喷墨方式”
	ui.printGrayLab->setText(QStringLiteral("墨点大小"));
	ui.inkjetLab->setVisible(false);
	ui.inkjetComBox->setVisible(false);
	//[高级设置]界面：隐藏“DPI”
	ui.XDPILab->setVisible(false);
	ui.YDPILab->setVisible(false);
	ui.XDPI100RadioBut->setVisible(false);
	ui.XDPI150RadioBut->setVisible(false);
	ui.XDPI200RadioBut->setVisible(false);
	ui.XDPI300RadioBut->setVisible(false);
	ui.XDPI600RadioBut->setVisible(false);
	ui.YDPI300RadioBut->setVisible(false);
	ui.YDPI600RadioBut->setVisible(false);
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

#endif

	NozzleradioBG = new QButtonGroup;
	NozzleradioBG->addButton(ui.nozzleSel1RadioBut,1);
	NozzleradioBG->addButton(ui.nozzleSel2RadioBut,2);
	ui.nozzleSel1RadioBut->setChecked(1);

	pNumKeyboard = new numkeyboard(ui.printSetTabWid);
	pNumKeyboard->setVisible(false);
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

void printSetting::synWheelCheckBox_valueChanged(int val)
{
	if (val)
	{
		//1.读取当前的同步轮速度，即每秒脉冲数m（测试阶段默认每秒脉冲数500）
		/*  open(驱动)
			int pulssPerSecond = read(int)(驱动里准备好了的变量)
			close(驱动)
		*/

		//测试用
		int pulssPerSecond = 1250;

		//2.计算当前产线速度（单位m/min），并显示在proLineSpeedShowLab中
		double tmpSpeed = calCurProSpeed(pulssPerSecond);
		ui.proLineSpeedShowLab->setText(QString::number(tmpSpeed,10,2));
		
		//3.设置界面
		ui.printSpeedRedBut->setEnabled(false);
		ui.printSpeedAddBut->setEnabled(false);
		ui.printSpeedRedBut->setStyleSheet("background-color: rgb(128,128,128,80);");
		ui.printSpeedAddBut->setStyleSheet("background-color: rgb(128,128,128,80);");
		ui.printSpeedShowLab->setStyleSheet("background-color: rgb(128,128,128,80); color: rgb(128,128,128);");

		ui.proLineSpeedLab->setStyleSheet("color: rgb(255,255,255);");
		ui.proLineSpeedShowLab->setStyleSheet("background-color: rgb(72,61, 139); color: rgb(255, 255, 255);");
		
	}
	else if (!val)
	{
		ui.printSpeedRedBut->setEnabled(true);
		ui.printSpeedAddBut->setEnabled(true);
		ui.printSpeedRedBut->setStyleSheet("color: rgb(255, 255, 255); background-color: rgb(0, 0, 230);");
		ui.printSpeedAddBut->setStyleSheet("color: rgb(255, 255, 255); background-color: rgb(0, 0, 230);");
		ui.printSpeedShowLab->setStyleSheet("background-color: rgb(72,61, 139); color: rgb(255, 255, 255);");
		//产线速度不可用
		ui.proLineSpeedLab->setStyleSheet("color: rgb(128,128,128);");
		ui.proLineSpeedShowLab->setStyleSheet("background-color: rgb(128,128,128,80); color: rgb(128,128,128);");
	}
}

double printSetting::calCurProSpeed(int pulsePerRound)
{
	//接收当前界面中的变量值
	int tmpEncoderRes = ui.encoderResLineEdit->text().toInt();
	int tmpWheelDiameter = ui.wheelDiameterLineEdit->text().toInt();

	if (tmpEncoderRes != 0)
	{
		//计算当前产线速度V = πmD/n×0.06（单位m/min）,其中m为每秒脉冲数，D为靠轮直径，n为分辨率
		double proSpeed = pulsePerRound * tmpWheelDiameter / tmpEncoderRes * 0.06 * PAI;
		return proSpeed;
	}
	
	return 0.0;
}

void printSetting::trigComBox_ValueChanged(int val)
{
	if ( val==0 || val==1 || val==4 )//若为自动/光电/光自动
	{
		//编码器分辨率不可用
		ui.encoderResLineEdit->setEnabled(false);
		ui.encoderResLineEdit->setStyleSheet("color: rgb(128,128,128); background-color: rgb(128,128,128,80); border-color: rgb(128,128,128,80);");
		//ui.encoderResLab->setStyleSheet("color: rgb(128,128,128);");
		//靠轮直径不可用
		ui.wheelDiameterLineEdit->setEnabled(false);
		ui.wheelDiameterLineEdit->setStyleSheet("color: rgb(128,128,128); background-color: rgb(128,128,128,80); border-color: rgb(128,128,128,80);");
		//ui.wheelDiameterLab->setStyleSheet("color: rgb(128,128,128);");
	}
	else
	{
		ui.encoderResLineEdit->setEnabled(true);
		ui.encoderResLineEdit->setStyleSheet("background-color: rgb(255,255,255); color: rgb(0,0,0);");
		//ui.encoderResLab->setStyleSheet("color: rgb(255,255,255);");
		ui.wheelDiameterLineEdit->setEnabled(true);
		ui.wheelDiameterLineEdit->setStyleSheet("background-color: rgb(255,255,255); color: rgb(0,0,0);");
		//ui.wheelDiameterLab->setStyleSheet("color: rgb(255,255,255);");
	}
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

void printSetting::encoderResLineEdit_clicked()
{
	pNumKeyboard->SetLineEdit(ui.encoderResLineEdit);
	QRect numKeyboardRect = pNumKeyboard->geometry();
	pNumKeyboard->setGeometry(520,300,numKeyboardRect.width(),numKeyboardRect.height());
}

void printSetting::wheelDiameterLineEdit_clicked()
{
	pNumKeyboard->SetLineEdit(ui.wheelDiameterLineEdit);
	QRect numKeyboardRect = pNumKeyboard->geometry();
	pNumKeyboard->setGeometry(520,300,numKeyboardRect.width(),numKeyboardRect.height());
}

void printSetting::pulseWidthLineEdit_clicked()
{
	pNumKeyboard->SetLineEdit(ui.pulseWidthLineEdit);
	QRect numKeyboardRect = pNumKeyboard->geometry();
	pNumKeyboard->setGeometry(520,300,numKeyboardRect.width(),numKeyboardRect.height());
}
