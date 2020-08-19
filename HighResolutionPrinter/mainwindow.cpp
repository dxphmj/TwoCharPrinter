#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTime>
#include <QProgressBar>
#include "filemanageform.h"
#include "paramsettingform.h"
#include "NozzleClean.h"
#include "ui_nozzleclean.h"
#include "ClassMessage.h"
#include "PrintThead.h"
#include "PrintCreatThread.h"
#include "PrintShowThread.h"
#include "OBJ_Type.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	m_bPrintNow = false;
	m_bDynamicPrint = false;

	ui->previewLab->installEventFilter(this);
 
	m_fileManage = new FilemanageForm(this);
	m_paramsetting = new ParamSettingForm(this);
	m_paramsetting->hide();
	m_fileManage->hide();

	m_MessagePrint = new ClassMessage();
	
	connect(ui->fileManageBut,SIGNAL(clicked()),this,SLOT(fileManageBut_clicked()));
	connect(ui->paraManageBut,SIGNAL(clicked()),this,SLOT(paraManageBut_clicked()));
	connect(ui->closeBut,SIGNAL(clicked()),this,SLOT(closeBut_clicked()));
	connect(ui->startPrintBut,SIGNAL(clicked()),this,SLOT(PrintBut_clicked()));

	ui->fileManageBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/fileManage.bmp);border-radius:15px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/fileManage.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 ");
		
	ui->paraManageBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/paraManage.bmp);border-radius:15px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/paraManage.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 "); 
	ui->startPrintBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/startPrint.bmp);border-radius:15px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/startPrint.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 "); 
	ui->closeBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/closeSys.bmp);border-radius:15px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/closeSys.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								");  
	ui->roolLab->setStyleSheet("background-color: rgb(67,51, 139);border-radius:10px;color: rgb(255, 255, 255);");  
 
	ui->previewLab->setStyleSheet("background-color: rgb(255,255,255);"); 

	ui->print1Prog->setStyleSheet("QProgressBar{""text-align:center;color: rgb(255, 255, 255);""}"
			                      "QProgressBar::chunk{""margin:2px;""}");
	ui->print2Prog->setStyleSheet("QProgressBar{""text-align:center;color: rgb(255, 255, 255);""}"
		                          "QProgressBar::chunk{""margin:2px;""}");

#ifdef BIG_CHAR
	//大字符环境下隐藏墨盒
	ui->print1Prog->setVisible(false);
	ui->print2Prog->setVisible(false);
	ui->No1Lab->setVisible(false);
	ui->No2Lab->setVisible(false);

	//新建一个“清理喷嘴”按钮
	QFont font;
	font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
	font.setPointSize(18);

	QPushButton* cleanNozzleBtn = new QPushButton(ui->progCtrlLab);
	cleanNozzleBtn->setGeometry(QRect(65,80,144,144));
	cleanNozzleBtn->setFont(font);
	cleanNozzleBtn->setText(QStringLiteral("清洗喷头"));
	cleanNozzleBtn->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/nozzleClean.bmp);border-radius:15px;color:rgb(255,255,255)}\
								  QPushButton:pressed{border-image: url(:/Images/nozzleClean.bmp);border: 1px solid rgb(12 , 138 , 235);\
								  padding-left:7px;padding-top:7px;}\
								  ");
	
	connect(cleanNozzleBtn,SIGNAL(clicked()),this,SLOT(showNozzleCleanWidget()));

#endif

	mythreadDynamicBoo = false;

	myTimer = new QTimer(this);
	myTimer->start(0);
	connect(myTimer,SIGNAL(timeout()),this,SLOT(GetDateTime()));
	ui->timeShowLab->setStyleSheet("qproperty-alignment: 'AlignVCenter | AlignRight';color:rgb(255,255,255);font-size:40px;");
	 
	m_pPrintThread = new PrintThead(this);//启动打印线程
	m_pPrintThread->start();

	serial.setPortName("COM4");   //串口名
	//if (serial.open(QIODevice::ReadWrite))
	//{
	//	bool b;
	//	qint32 baudrate = 115200;
	//	b = serial.setBaudRate(baudrate);//波特率
	//	b = serial.setDataBits(QSerialPort::Data8); //数据位
	//	b = serial.setParity(QSerialPort::NoParity); //校验位
	//	b = serial.setStopBits(QSerialPort::OneStop);//停止位
	//	b = serial.setFlowControl(QSerialPort::NoFlowControl);
	//	serial.setDataTerminalReady(true);
	//}
	//QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);
	//initPrinter();

	getCurParam();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showNozzleCleanWidget()
{
	m_NozzleClean = new NozzleClean(this);
	m_NozzleClean->setGeometry(10,80,1101,666);
	m_NozzleClean->setVisible(true);
	ui->fileManageBut->setEnabled(false);
	ui->paraManageBut->setEnabled(false);
	ui->startPrintBut->setEnabled(false);
}

void MainWindow::initPrinter()
{
    m_StructRowCol[1].m_nCOl = 1; m_StructRowCol[1].m_nRow = 1;
	m_StructRowCol[2].m_nCOl = 2; m_StructRowCol[2].m_nRow = 9;
	m_StructRowCol[3].m_nCOl = 1; m_StructRowCol[3].m_nRow = 16;
	m_StructRowCol[4].m_nCOl = 2; m_StructRowCol[4].m_nRow = 2;
	m_StructRowCol[5].m_nCOl = 1; m_StructRowCol[5].m_nRow = 9;
	m_StructRowCol[6].m_nCOl = 2; m_StructRowCol[6].m_nRow = 17;
	m_StructRowCol[7].m_nCOl = 1; m_StructRowCol[7].m_nRow = 2;
	m_StructRowCol[8].m_nCOl = 2; m_StructRowCol[8].m_nRow = 10;
	m_StructRowCol[9].m_nCOl = 1; m_StructRowCol[9].m_nRow = 17;
	m_StructRowCol[10].m_nCOl = 2; m_StructRowCol[10].m_nRow = 3;
	m_StructRowCol[11].m_nCOl = 1; m_StructRowCol[11].m_nRow = 10;
	m_StructRowCol[12].m_nCOl = 2; m_StructRowCol[12].m_nRow = 18;
	m_StructRowCol[13].m_nCOl = 1; m_StructRowCol[13].m_nRow = 3;
	m_StructRowCol[14].m_nCOl = 2; m_StructRowCol[14].m_nRow = 11;
	m_StructRowCol[15].m_nCOl = 1; m_StructRowCol[15].m_nRow = 18;
	m_StructRowCol[16].m_nCOl = 2; m_StructRowCol[16].m_nRow = 4;
	m_StructRowCol[17].m_nCOl = 1; m_StructRowCol[17].m_nRow = 11;
	m_StructRowCol[18].m_nCOl = 2; m_StructRowCol[18].m_nRow = 19;
	m_StructRowCol[19].m_nCOl = 1; m_StructRowCol[19].m_nRow = 4;
	m_StructRowCol[20].m_nCOl = 2; m_StructRowCol[20].m_nRow = 12;
	m_StructRowCol[21].m_nCOl = 1; m_StructRowCol[21].m_nRow = 19;
	m_StructRowCol[22].m_nCOl = 2; m_StructRowCol[22].m_nRow = 5;
	m_StructRowCol[23].m_nCOl = 1; m_StructRowCol[23].m_nRow = 12;
	m_StructRowCol[24].m_nCOl = 2; m_StructRowCol[24].m_nRow = 20;
	m_StructRowCol[25].m_nCOl = 1; m_StructRowCol[25].m_nRow = 5;
	m_StructRowCol[26].m_nCOl = 2; m_StructRowCol[26].m_nRow = 13;
	m_StructRowCol[27].m_nCOl = 1; m_StructRowCol[27].m_nRow = 20;
	m_StructRowCol[28].m_nCOl = 2; m_StructRowCol[28].m_nRow = 6;
	m_StructRowCol[29].m_nCOl = 1; m_StructRowCol[29].m_nRow = 13;
	m_StructRowCol[30].m_nCOl = 2; m_StructRowCol[30].m_nRow = 21;
	m_StructRowCol[31].m_nCOl = 1; m_StructRowCol[31].m_nRow = 6;
	m_StructRowCol[32].m_nCOl = 2; m_StructRowCol[32].m_nRow = 14;
	m_StructRowCol[33].m_nCOl = 1; m_StructRowCol[33].m_nRow = 21;
	m_StructRowCol[34].m_nCOl = 2; m_StructRowCol[34].m_nRow = 7;
	m_StructRowCol[35].m_nCOl = 1; m_StructRowCol[35].m_nRow = 14;
	m_StructRowCol[36].m_nCOl = 2; m_StructRowCol[36].m_nRow = 22;
	m_StructRowCol[37].m_nCOl = 1; m_StructRowCol[37].m_nRow = 7;
	m_StructRowCol[38].m_nCOl = 2; m_StructRowCol[38].m_nRow = 15;
	m_StructRowCol[39].m_nCOl = 1; m_StructRowCol[39].m_nRow = 22;
	m_StructRowCol[40].m_nCOl = 2; m_StructRowCol[40].m_nRow = 8;
	m_StructRowCol[41].m_nCOl = 3; m_StructRowCol[41].m_nRow = 15;
	m_StructRowCol[42].m_nCOl = 4; m_StructRowCol[42].m_nRow = 1;
	m_StructRowCol[43].m_nCOl = 3; m_StructRowCol[43].m_nRow = 8;
	m_StructRowCol[44].m_nCOl = 4; m_StructRowCol[44].m_nRow = 16;
	m_StructRowCol[45].m_nCOl = 3; m_StructRowCol[45].m_nRow = 1;
	m_StructRowCol[46].m_nCOl = 4; m_StructRowCol[46].m_nRow = 9;
	m_StructRowCol[47].m_nCOl = 3; m_StructRowCol[47].m_nRow = 16;
	m_StructRowCol[48].m_nCOl = 4; m_StructRowCol[48].m_nRow = 2;
	m_StructRowCol[49].m_nCOl = 3; m_StructRowCol[49].m_nRow = 9;
	m_StructRowCol[50].m_nCOl = 4; m_StructRowCol[50].m_nRow = 17;
	m_StructRowCol[51].m_nCOl = 3; m_StructRowCol[51].m_nRow = 2;
	m_StructRowCol[52].m_nCOl = 4; m_StructRowCol[52].m_nRow = 10;
	m_StructRowCol[53].m_nCOl = 3; m_StructRowCol[53].m_nRow = 17;
	m_StructRowCol[54].m_nCOl = 4; m_StructRowCol[54].m_nRow = 3;
	m_StructRowCol[55].m_nCOl = 3; m_StructRowCol[55].m_nRow = 10;
	m_StructRowCol[56].m_nCOl = 4; m_StructRowCol[56].m_nRow = 18;
	m_StructRowCol[57].m_nCOl = 3; m_StructRowCol[57].m_nRow = 3;
	m_StructRowCol[58].m_nCOl = 4; m_StructRowCol[58].m_nRow = 11;
	m_StructRowCol[59].m_nCOl = 3; m_StructRowCol[59].m_nRow = 18;
	m_StructRowCol[60].m_nCOl = 4; m_StructRowCol[60].m_nRow = 4;
	m_StructRowCol[61].m_nCOl = 3; m_StructRowCol[61].m_nRow = 11;
	m_StructRowCol[62].m_nCOl = 4; m_StructRowCol[62].m_nRow = 19;
	m_StructRowCol[63].m_nCOl = 3; m_StructRowCol[63].m_nRow = 4;
	m_StructRowCol[64].m_nCOl = 4; m_StructRowCol[64].m_nRow = 12;
	m_StructRowCol[65].m_nCOl = 3; m_StructRowCol[65].m_nRow = 19;
	m_StructRowCol[66].m_nCOl = 4; m_StructRowCol[66].m_nRow = 5;
	m_StructRowCol[67].m_nCOl = 3; m_StructRowCol[67].m_nRow = 12;
	m_StructRowCol[68].m_nCOl = 4; m_StructRowCol[68].m_nRow = 20;
	m_StructRowCol[69].m_nCOl = 3; m_StructRowCol[69].m_nRow = 5;
	m_StructRowCol[70].m_nCOl = 4; m_StructRowCol[70].m_nRow = 13;
	m_StructRowCol[71].m_nCOl = 3; m_StructRowCol[71].m_nRow = 20;
	m_StructRowCol[72].m_nCOl = 4; m_StructRowCol[72].m_nRow = 6;
	m_StructRowCol[73].m_nCOl = 3; m_StructRowCol[73].m_nRow = 13;
	m_StructRowCol[74].m_nCOl = 4; m_StructRowCol[74].m_nRow = 21;
	m_StructRowCol[75].m_nCOl = 3; m_StructRowCol[75].m_nRow = 6;
	m_StructRowCol[76].m_nCOl = 4; m_StructRowCol[76].m_nRow = 14;
	m_StructRowCol[77].m_nCOl = 3; m_StructRowCol[77].m_nRow = 21;
	m_StructRowCol[78].m_nCOl = 4; m_StructRowCol[78].m_nRow = 7;
	m_StructRowCol[79].m_nCOl = 3; m_StructRowCol[79].m_nRow = 14;
	m_StructRowCol[80].m_nCOl = 4; m_StructRowCol[80].m_nRow = 22;
	m_StructRowCol[81].m_nCOl = 3; m_StructRowCol[81].m_nRow = 7;
	m_StructRowCol[82].m_nCOl = 4; m_StructRowCol[82].m_nRow = 15;
	m_StructRowCol[83].m_nCOl = 3; m_StructRowCol[83].m_nRow = 22;
	m_StructRowCol[84].m_nCOl = 4; m_StructRowCol[84].m_nRow = 8;
	m_StructRowCol[85].m_nCOl = 5; m_StructRowCol[85].m_nRow = 15;
	m_StructRowCol[86].m_nCOl = 6; m_StructRowCol[86].m_nRow = 1;
	m_StructRowCol[87].m_nCOl = 5; m_StructRowCol[87].m_nRow = 8;
	m_StructRowCol[88].m_nCOl = 6; m_StructRowCol[88].m_nRow = 16;
	m_StructRowCol[89].m_nCOl = 5; m_StructRowCol[89].m_nRow = 1;
	m_StructRowCol[90].m_nCOl = 6; m_StructRowCol[90].m_nRow = 9;
	m_StructRowCol[91].m_nCOl = 5; m_StructRowCol[91].m_nRow = 16;
	m_StructRowCol[92].m_nCOl = 6; m_StructRowCol[92].m_nRow = 2;
	m_StructRowCol[93].m_nCOl = 5; m_StructRowCol[93].m_nRow = 9;
	m_StructRowCol[94].m_nCOl = 6; m_StructRowCol[94].m_nRow = 17;
	m_StructRowCol[95].m_nCOl = 5; m_StructRowCol[95].m_nRow = 2;
	m_StructRowCol[96].m_nCOl = 6; m_StructRowCol[96].m_nRow = 10;
	m_StructRowCol[97].m_nCOl = 5; m_StructRowCol[97].m_nRow = 17;
	m_StructRowCol[98].m_nCOl = 6; m_StructRowCol[98].m_nRow = 3;
	m_StructRowCol[99].m_nCOl = 5; m_StructRowCol[99].m_nRow = 10;
	m_StructRowCol[100].m_nCOl = 6; m_StructRowCol[100].m_nRow = 18;
	m_StructRowCol[101].m_nCOl = 5; m_StructRowCol[101].m_nRow = 3;
	m_StructRowCol[102].m_nCOl = 6; m_StructRowCol[102].m_nRow = 11;
	m_StructRowCol[103].m_nCOl = 5; m_StructRowCol[103].m_nRow = 18;
	m_StructRowCol[104].m_nCOl = 6; m_StructRowCol[104].m_nRow = 4;
	m_StructRowCol[105].m_nCOl = 5; m_StructRowCol[105].m_nRow = 11;
	m_StructRowCol[106].m_nCOl = 6; m_StructRowCol[106].m_nRow = 19;
	m_StructRowCol[107].m_nCOl = 5; m_StructRowCol[107].m_nRow = 4;
	m_StructRowCol[108].m_nCOl = 6; m_StructRowCol[108].m_nRow = 12;
	m_StructRowCol[109].m_nCOl = 5; m_StructRowCol[109].m_nRow = 19;
	m_StructRowCol[110].m_nCOl = 6; m_StructRowCol[110].m_nRow = 5;
	m_StructRowCol[111].m_nCOl = 5; m_StructRowCol[111].m_nRow = 12;
	m_StructRowCol[112].m_nCOl = 6; m_StructRowCol[112].m_nRow = 20;
	m_StructRowCol[113].m_nCOl = 5; m_StructRowCol[113].m_nRow = 5;
	m_StructRowCol[114].m_nCOl = 6; m_StructRowCol[114].m_nRow = 13;
	m_StructRowCol[115].m_nCOl = 5; m_StructRowCol[115].m_nRow = 20;
	m_StructRowCol[116].m_nCOl = 6; m_StructRowCol[116].m_nRow = 6;
	m_StructRowCol[117].m_nCOl = 5; m_StructRowCol[117].m_nRow = 13;
	m_StructRowCol[118].m_nCOl = 6; m_StructRowCol[118].m_nRow = 21;
	m_StructRowCol[119].m_nCOl = 5; m_StructRowCol[119].m_nRow = 6;
	m_StructRowCol[120].m_nCOl = 6; m_StructRowCol[120].m_nRow = 14;
	m_StructRowCol[121].m_nCOl = 5; m_StructRowCol[121].m_nRow = 21;
	m_StructRowCol[122].m_nCOl = 6; m_StructRowCol[122].m_nRow = 7;
	m_StructRowCol[123].m_nCOl = 5; m_StructRowCol[123].m_nRow = 14;
	m_StructRowCol[124].m_nCOl = 6; m_StructRowCol[124].m_nRow = 22;
	m_StructRowCol[125].m_nCOl = 5; m_StructRowCol[125].m_nRow = 7;
	m_StructRowCol[126].m_nCOl = 6; m_StructRowCol[126].m_nRow = 15;
	m_StructRowCol[127].m_nCOl = 5; m_StructRowCol[127].m_nRow = 22;
	m_StructRowCol[128].m_nCOl = 6; m_StructRowCol[128].m_nRow = 8;
	m_StructRowCol[129].m_nCOl = 7; m_StructRowCol[129].m_nRow = 15;
	m_StructRowCol[130].m_nCOl = 8; m_StructRowCol[130].m_nRow = 1;
	m_StructRowCol[131].m_nCOl = 7; m_StructRowCol[131].m_nRow = 8;
	m_StructRowCol[132].m_nCOl = 8; m_StructRowCol[132].m_nRow = 16;
	m_StructRowCol[133].m_nCOl = 7; m_StructRowCol[133].m_nRow = 1;
	m_StructRowCol[134].m_nCOl = 8; m_StructRowCol[134].m_nRow = 9;
	m_StructRowCol[135].m_nCOl = 7; m_StructRowCol[135].m_nRow = 16;
	m_StructRowCol[136].m_nCOl = 8; m_StructRowCol[136].m_nRow = 2;
	m_StructRowCol[137].m_nCOl = 7; m_StructRowCol[137].m_nRow = 9;
	m_StructRowCol[138].m_nCOl = 8; m_StructRowCol[138].m_nRow = 17;
	m_StructRowCol[139].m_nCOl = 7; m_StructRowCol[139].m_nRow = 2;
	m_StructRowCol[140].m_nCOl = 8; m_StructRowCol[140].m_nRow = 10;
	m_StructRowCol[141].m_nCOl = 7; m_StructRowCol[141].m_nRow = 17;
	m_StructRowCol[142].m_nCOl = 8; m_StructRowCol[142].m_nRow = 3;
	m_StructRowCol[143].m_nCOl = 7; m_StructRowCol[143].m_nRow = 10;
	m_StructRowCol[144].m_nCOl = 8; m_StructRowCol[144].m_nRow = 18;
	m_StructRowCol[145].m_nCOl = 7; m_StructRowCol[145].m_nRow = 3;
	m_StructRowCol[146].m_nCOl = 8; m_StructRowCol[146].m_nRow = 11;
	m_StructRowCol[147].m_nCOl = 7; m_StructRowCol[147].m_nRow = 18;
	m_StructRowCol[148].m_nCOl = 8; m_StructRowCol[148].m_nRow = 4;
	m_StructRowCol[149].m_nCOl = 7; m_StructRowCol[149].m_nRow = 11;
	m_StructRowCol[150].m_nCOl = 8; m_StructRowCol[150].m_nRow = 19;
	m_StructRowCol[151].m_nCOl = 7; m_StructRowCol[151].m_nRow = 4;
	m_StructRowCol[152].m_nCOl = 8; m_StructRowCol[152].m_nRow = 12;
	m_StructRowCol[153].m_nCOl = 7; m_StructRowCol[153].m_nRow = 19;
	m_StructRowCol[154].m_nCOl = 8; m_StructRowCol[154].m_nRow = 5;
	m_StructRowCol[155].m_nCOl = 7; m_StructRowCol[155].m_nRow = 12;
	m_StructRowCol[156].m_nCOl = 8; m_StructRowCol[156].m_nRow = 20;
	m_StructRowCol[157].m_nCOl = 7; m_StructRowCol[157].m_nRow = 5;
	m_StructRowCol[158].m_nCOl = 8; m_StructRowCol[158].m_nRow = 13;
	m_StructRowCol[159].m_nCOl = 7; m_StructRowCol[159].m_nRow = 20;
	m_StructRowCol[160].m_nCOl = 8; m_StructRowCol[160].m_nRow = 6;
	m_StructRowCol[161].m_nCOl = 7; m_StructRowCol[161].m_nRow = 13;
	m_StructRowCol[162].m_nCOl = 8; m_StructRowCol[162].m_nRow = 21;
	m_StructRowCol[163].m_nCOl = 7; m_StructRowCol[163].m_nRow = 6;
	m_StructRowCol[164].m_nCOl = 8; m_StructRowCol[164].m_nRow = 14;
	m_StructRowCol[165].m_nCOl = 7; m_StructRowCol[165].m_nRow = 21;
	m_StructRowCol[166].m_nCOl = 8; m_StructRowCol[166].m_nRow = 7;
	m_StructRowCol[167].m_nCOl = 7; m_StructRowCol[167].m_nRow = 14;
	m_StructRowCol[168].m_nCOl = 8; m_StructRowCol[168].m_nRow = 22;
	m_StructRowCol[169].m_nCOl = 7; m_StructRowCol[169].m_nRow = 7;
	m_StructRowCol[170].m_nCOl = 8; m_StructRowCol[170].m_nRow = 15;
	m_StructRowCol[171].m_nCOl = 7; m_StructRowCol[171].m_nRow = 22;
	m_StructRowCol[172].m_nCOl = 8; m_StructRowCol[172].m_nRow = 8;
	m_StructRowCol[173].m_nCOl = 9 ; m_StructRowCol[173].m_nRow = 15;
	m_StructRowCol[174].m_nCOl = 10; m_StructRowCol[174].m_nRow = 1;
	m_StructRowCol[175].m_nCOl = 9 ; m_StructRowCol[175].m_nRow = 8;
	m_StructRowCol[176].m_nCOl = 10; m_StructRowCol[176].m_nRow = 16;
	m_StructRowCol[177].m_nCOl = 9 ; m_StructRowCol[177].m_nRow = 9;
	m_StructRowCol[178].m_nCOl = 10; m_StructRowCol[178].m_nRow = 16;
	m_StructRowCol[179].m_nCOl = 9 ; m_StructRowCol[179].m_nRow = 2;
	m_StructRowCol[180].m_nCOl = 10; m_StructRowCol[180].m_nRow = 9;
	m_StructRowCol[181].m_nCOl = 9 ; m_StructRowCol[181].m_nRow = 9;
	m_StructRowCol[182].m_nCOl = 10; m_StructRowCol[182].m_nRow = 17;
	m_StructRowCol[183].m_nCOl = 9 ; m_StructRowCol[183].m_nRow = 2;
	m_StructRowCol[184].m_nCOl = 10; m_StructRowCol[184].m_nRow = 10;
	m_StructRowCol[185].m_nCOl = 9 ; m_StructRowCol[185].m_nRow = 17;
	m_StructRowCol[186].m_nCOl = 10; m_StructRowCol[186].m_nRow = 3;
	m_StructRowCol[187].m_nCOl = 9 ; m_StructRowCol[187].m_nRow = 10;
	m_StructRowCol[188].m_nCOl = 10; m_StructRowCol[188].m_nRow = 18;
	m_StructRowCol[189].m_nCOl = 9 ; m_StructRowCol[189].m_nRow = 3;
	m_StructRowCol[190].m_nCOl = 10; m_StructRowCol[190].m_nRow = 11;
	m_StructRowCol[191].m_nCOl = 9 ; m_StructRowCol[191].m_nRow = 18;
	m_StructRowCol[192].m_nCOl = 10; m_StructRowCol[192].m_nRow = 4;
	m_StructRowCol[193].m_nCOl = 9 ; m_StructRowCol[193].m_nRow = 11;
	m_StructRowCol[194].m_nCOl = 10; m_StructRowCol[194].m_nRow = 19;
	m_StructRowCol[195].m_nCOl = 9 ; m_StructRowCol[195].m_nRow = 4;
	m_StructRowCol[196].m_nCOl = 10; m_StructRowCol[196].m_nRow = 12;
	m_StructRowCol[197].m_nCOl = 9 ; m_StructRowCol[197].m_nRow = 19;
	m_StructRowCol[198].m_nCOl = 10; m_StructRowCol[198].m_nRow = 5;
	m_StructRowCol[199].m_nCOl = 9 ; m_StructRowCol[199].m_nRow = 12;
	m_StructRowCol[200].m_nCOl = 10; m_StructRowCol[200].m_nRow = 20;
	m_StructRowCol[201].m_nCOl = 9 ; m_StructRowCol[201].m_nRow = 5;
	m_StructRowCol[202].m_nCOl = 10; m_StructRowCol[202].m_nRow = 13;
	m_StructRowCol[203].m_nCOl = 9 ; m_StructRowCol[203].m_nRow = 20;
	m_StructRowCol[204].m_nCOl = 10; m_StructRowCol[204].m_nRow = 6;
	m_StructRowCol[205].m_nCOl = 9 ; m_StructRowCol[205].m_nRow = 13;
	m_StructRowCol[206].m_nCOl = 10; m_StructRowCol[206].m_nRow = 21;
	m_StructRowCol[207].m_nCOl = 9 ; m_StructRowCol[207].m_nRow = 6;
	m_StructRowCol[208].m_nCOl = 10; m_StructRowCol[208].m_nRow = 14;
	m_StructRowCol[209].m_nCOl = 9 ; m_StructRowCol[209].m_nRow = 21;
	m_StructRowCol[210].m_nCOl = 10; m_StructRowCol[210].m_nRow = 7;
	m_StructRowCol[211].m_nCOl = 9 ; m_StructRowCol[211].m_nRow = 14;
	m_StructRowCol[212].m_nCOl = 10; m_StructRowCol[212].m_nRow = 22;
	m_StructRowCol[213].m_nCOl = 9 ; m_StructRowCol[213].m_nRow = 7;
	m_StructRowCol[214].m_nCOl = 10; m_StructRowCol[214].m_nRow = 15;
	m_StructRowCol[215].m_nCOl = 9 ; m_StructRowCol[215].m_nRow = 22;
	m_StructRowCol[216].m_nCOl = 10; m_StructRowCol[216].m_nRow = 8;
	m_StructRowCol[217].m_nCOl = 11; m_StructRowCol[217].m_nRow = 15;
	m_StructRowCol[218].m_nCOl = 12; m_StructRowCol[218].m_nRow = 1;
	m_StructRowCol[219].m_nCOl = 11; m_StructRowCol[219].m_nRow = 8;
	m_StructRowCol[220].m_nCOl = 12; m_StructRowCol[220].m_nRow = 16;
	m_StructRowCol[221].m_nCOl = 11; m_StructRowCol[221].m_nRow = 1;
	m_StructRowCol[222].m_nCOl = 12; m_StructRowCol[222].m_nRow = 9;
	m_StructRowCol[223].m_nCOl = 11; m_StructRowCol[223].m_nRow = 16;
	m_StructRowCol[224].m_nCOl = 12; m_StructRowCol[224].m_nRow = 2;
	m_StructRowCol[225].m_nCOl = 11; m_StructRowCol[225].m_nRow = 9;
	m_StructRowCol[226].m_nCOl = 12; m_StructRowCol[226].m_nRow = 17;
	m_StructRowCol[227].m_nCOl = 11; m_StructRowCol[227].m_nRow = 2;
	m_StructRowCol[228].m_nCOl = 12; m_StructRowCol[228].m_nRow = 10;
	m_StructRowCol[229].m_nCOl = 11; m_StructRowCol[229].m_nRow = 17;
	m_StructRowCol[230].m_nCOl = 12; m_StructRowCol[230].m_nRow = 3;
	m_StructRowCol[231].m_nCOl = 11; m_StructRowCol[231].m_nRow = 10;
	m_StructRowCol[232].m_nCOl = 12; m_StructRowCol[232].m_nRow = 18;
	m_StructRowCol[233].m_nCOl = 11; m_StructRowCol[233].m_nRow = 3;
	m_StructRowCol[234].m_nCOl = 12; m_StructRowCol[234].m_nRow = 11;
	m_StructRowCol[235].m_nCOl = 11; m_StructRowCol[235].m_nRow = 18;
	m_StructRowCol[236].m_nCOl = 12; m_StructRowCol[236].m_nRow = 4;
	m_StructRowCol[237].m_nCOl = 11; m_StructRowCol[237].m_nRow = 11;
	m_StructRowCol[238].m_nCOl = 12; m_StructRowCol[238].m_nRow = 19;
	m_StructRowCol[239].m_nCOl = 11; m_StructRowCol[239].m_nRow = 4;
	m_StructRowCol[240].m_nCOl = 12; m_StructRowCol[240].m_nRow = 12;
	m_StructRowCol[241].m_nCOl = 11; m_StructRowCol[241].m_nRow = 19;
	m_StructRowCol[242].m_nCOl = 12; m_StructRowCol[242].m_nRow = 5;
	m_StructRowCol[243].m_nCOl = 11; m_StructRowCol[243].m_nRow = 12;
	m_StructRowCol[244].m_nCOl = 12; m_StructRowCol[244].m_nRow = 20;
	m_StructRowCol[245].m_nCOl = 11; m_StructRowCol[245].m_nRow = 5;
	m_StructRowCol[246].m_nCOl = 12; m_StructRowCol[246].m_nRow = 13;
	m_StructRowCol[247].m_nCOl = 11; m_StructRowCol[247].m_nRow = 20;
	m_StructRowCol[248].m_nCOl = 12; m_StructRowCol[248].m_nRow = 6;
	m_StructRowCol[249].m_nCOl = 11; m_StructRowCol[249].m_nRow = 13;
	m_StructRowCol[250].m_nCOl = 12; m_StructRowCol[250].m_nRow = 21;
	m_StructRowCol[251].m_nCOl = 11; m_StructRowCol[251].m_nRow = 6;
	m_StructRowCol[252].m_nCOl = 12; m_StructRowCol[252].m_nRow = 14;
	m_StructRowCol[253].m_nCOl = 11; m_StructRowCol[253].m_nRow = 21;
	m_StructRowCol[254].m_nCOl = 12; m_StructRowCol[254].m_nRow = 7;
	m_StructRowCol[255].m_nCOl = 11; m_StructRowCol[255].m_nRow = 14;
	m_StructRowCol[256].m_nCOl = 12; m_StructRowCol[256].m_nRow = 22;
	m_StructRowCol[257].m_nCOl = 11; m_StructRowCol[257].m_nRow = 7;
	m_StructRowCol[258].m_nCOl = 12; m_StructRowCol[258].m_nRow = 15;
	m_StructRowCol[259].m_nCOl = 11; m_StructRowCol[259].m_nRow = 22;
	m_StructRowCol[260].m_nCOl = 12; m_StructRowCol[260].m_nRow = 8;
	m_StructRowCol[261].m_nCOl = 13; m_StructRowCol[261].m_nRow = 15;
	m_StructRowCol[262].m_nCOl = 14; m_StructRowCol[262].m_nRow = 1;
	m_StructRowCol[263].m_nCOl = 13; m_StructRowCol[263].m_nRow = 8;
	m_StructRowCol[264].m_nCOl = 14; m_StructRowCol[264].m_nRow = 16;
	m_StructRowCol[265].m_nCOl = 13; m_StructRowCol[265].m_nRow = 1;
	m_StructRowCol[266].m_nCOl = 14; m_StructRowCol[266].m_nRow = 9;
	m_StructRowCol[267].m_nCOl = 13; m_StructRowCol[267].m_nRow = 16;
	m_StructRowCol[268].m_nCOl = 14; m_StructRowCol[268].m_nRow = 2;
	m_StructRowCol[269].m_nCOl = 13; m_StructRowCol[269].m_nRow = 9;
	m_StructRowCol[270].m_nCOl = 14; m_StructRowCol[270].m_nRow = 17;
	m_StructRowCol[271].m_nCOl = 13; m_StructRowCol[271].m_nRow = 2;
	m_StructRowCol[272].m_nCOl = 14; m_StructRowCol[272].m_nRow = 10;
	m_StructRowCol[273].m_nCOl = 13; m_StructRowCol[273].m_nRow = 17;
	m_StructRowCol[274].m_nCOl = 14; m_StructRowCol[274].m_nRow = 3;
	m_StructRowCol[275].m_nCOl = 13; m_StructRowCol[275].m_nRow = 10;
	m_StructRowCol[276].m_nCOl = 14; m_StructRowCol[276].m_nRow = 18;
	m_StructRowCol[277].m_nCOl = 13; m_StructRowCol[277].m_nRow = 3;
	m_StructRowCol[278].m_nCOl = 14; m_StructRowCol[278].m_nRow = 11;
	m_StructRowCol[279].m_nCOl = 13; m_StructRowCol[279].m_nRow = 18;
	m_StructRowCol[280].m_nCOl = 14; m_StructRowCol[280].m_nRow = 4;
	m_StructRowCol[281].m_nCOl = 13; m_StructRowCol[281].m_nRow = 11;
	m_StructRowCol[282].m_nCOl = 14; m_StructRowCol[282].m_nRow = 19;
	m_StructRowCol[283].m_nCOl = 13; m_StructRowCol[283].m_nRow = 4;
	m_StructRowCol[284].m_nCOl = 14; m_StructRowCol[284].m_nRow = 12;
	m_StructRowCol[285].m_nCOl = 13; m_StructRowCol[285].m_nRow = 19;
	m_StructRowCol[286].m_nCOl = 14; m_StructRowCol[286].m_nRow = 5;
	m_StructRowCol[287].m_nCOl = 13; m_StructRowCol[287].m_nRow = 12;
	m_StructRowCol[288].m_nCOl = 14; m_StructRowCol[288].m_nRow = 20;
	m_StructRowCol[289].m_nCOl = 13; m_StructRowCol[289].m_nRow = 5;
	m_StructRowCol[290].m_nCOl = 14; m_StructRowCol[290].m_nRow = 13;
	m_StructRowCol[291].m_nCOl = 13; m_StructRowCol[291].m_nRow = 20;
	m_StructRowCol[292].m_nCOl = 14; m_StructRowCol[292].m_nRow = 6;
	m_StructRowCol[293].m_nCOl = 13; m_StructRowCol[293].m_nRow = 13;
	m_StructRowCol[294].m_nCOl = 14; m_StructRowCol[294].m_nRow = 21;
	m_StructRowCol[295].m_nCOl = 13; m_StructRowCol[295].m_nRow = 6;
	m_StructRowCol[296].m_nCOl = 14; m_StructRowCol[296].m_nRow = 14;
	m_StructRowCol[297].m_nCOl = 13; m_StructRowCol[297].m_nRow = 21;
	m_StructRowCol[298].m_nCOl = 14; m_StructRowCol[298].m_nRow = 7;
	m_StructRowCol[299].m_nCOl = 13; m_StructRowCol[299].m_nRow = 14;
	m_StructRowCol[300].m_nCOl = 14; m_StructRowCol[300].m_nRow = 22;
}

void MainWindow::serialPort_readyRead()
{
    //从接收缓冲区中读取数据
    QByteArray buffer = serial.readAll();

	QString recv  = QString(buffer);

    //从界面中读取以前收到的数据
//    QString recv += QString(buffer);
    //清空以前的显示
 //   ui->recvTextEdit->clear();
    //重新显示
 //   ui->recvTextEdit->append(recv);
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui->previewLab && event->type() == QEvent::Paint)
	{
		boDrawMainPic = true;
	  	QPainter painter(ui->previewLab);
	 	m_MessagePrint->DrawAllDynamic(&painter);
	}
	return QWidget::eventFilter(watched,event);
}

void MainWindow::RefreshWindow()
{
	QWidget *pQWidget(this);
	pQWidget->update();
}

//void MainWindow::changedFont(const QFont& f)
//{
//	 label->setFont(f);
//}

void MainWindow::fileManageBut_clicked()
{
	m_paramsetting->hide();
	m_fileManage->show();
}

void MainWindow::paraManageBut_clicked()
{
	m_fileManage->hide();
	m_paramsetting->show();
}

void MainWindow::printerCode(char* writeArr)
{ 
    char readArr[46]={0x81,0x02, //控制指令
						  0x02,0x00, //row = 1 ， col = 1，16bit，分成两个字节传输，高字节在后，低字节在前
						  0x00,0x00,
						  0x02,0x00,
						  0x00,0x00,
						  0x02,0x00,
						  0x00,0x00,
						  0x02,0x00,
						  0x00,0x00, 
						  0x02,0x00,
						  0x00,0x00,
						  0x02,0x00,
						  0x00,0x00,
						  0x02,0x00,
						  0x00,0x00, 
						  0x02,0x00,
						  0x00,0x00,
						  0x02,0x00,
						  0x00,0x00,
						  0x02,0x00,
						  0x00,0x00,
						  0x02,0x00,
						  0x00,0x00 
		};
		 //1列150个喷嘴，150/8 = 19个字节，每个字节的位存储打印点阵中的1列黑白（0，1）信息
		//将19个字节中的bit数据转化成喷头的喷嘴行列驱动信息，然后传给FPGA
		//如果只用喷头的其中1列喷嘴打印，取奇数或偶数喷嘴序号
		BYTE  bytesData[19];
		for(int i = 0; i < 19; i++)
		{
			bytesData[i] = 0;
		}
		bytesData[0] = 0xFF;
		//bytesData[1] = 0xFF;
		bytesData[2] = 0xFF;
		//bytesData[3] = 0xFF;
		bytesData[4] = 0xFF;
		//bytesData[5] = 0xFF;
		bytesData[6] = 0xFF;
		//bytesData[7] = 0xFF;
		bytesData[8] = 0xFF;
	//	bytesData[9] = 0xFF;
		bytesData[10] = 0xFF;
	//	bytesData[11] = 0xFF;
		bytesData[12] = 0xFF;
	//	bytesData[13] = 0xFF;
		bytesData[14] = 0xFF;
	//	bytesData[15] = 0xFF; 
		bytesData[16] = 0xFF;
	//	bytesData[17] = 0xFF;
		bytesData[18] = 0xFF;	

		for(int i = 0; i < 19; i++)
		{
			BYTE oneBype = bytesData[i];
			for(int j = 0; j < 8; j++)
			{
				if(2*i*8+j*2+1 > 300) break;
				bool bit = ((oneBype >> j) & 1); //取某一位的值
				int row = m_StructRowCol[2*i*8+j*2+1].m_nRow;
				int col = m_StructRowCol[2*i*8+j*2+1].m_nCOl;
				if(col <= 6 && bit)
					readArr[row*2] = readArr[row*2] | (1 << (col+1)); //给某一位赋值
				else if(col > 6 && bit)
					readArr[row*2+1] = readArr[row*2+1] | (1 << (col-7)); //给某一位赋值
			}
		} 
		 
 	 	qint64 n = serial.write(readArr,46);//数据发送
	 
}

void MainWindow::closeBut_clicked()
{
	char* readArr;
	printerCode(readArr);
}

void MainWindow::PrintBut_clicked()
{
	m_bPrintNow = !m_bPrintNow;
}

void MainWindow::GetDateTime()
{
	 QTime timeNow=QTime::currentTime();
	 ui->timeShowLab->setText((QDate::currentDate().toString(tr("yyyy-MM-dd   ")))+tr("%1").arg(timeNow.toString())+tr("  "));
}

//下发打印数据
void MainWindow::DownloadPrintData()
{		
    //关闭动态打印线程（若有）
	if (mythreadDynamicBoo)
	{
		mythreadDynamicBoo = false;
		m_pPrintCreateThread->wait();//等待线程结束
		boDrawMainPic = false;
		m_pPrintShowThread->wait();//等待线程结束
		delete m_pPrintCreateThread;//删除线程
		delete m_pPrintShowThread;
	}
	
	//保存参数到目前的喷印配置xml文件和pcf文件里createPCF()	createPCFXML()
	//theApp.m_MessagePrint.createLABXML();
	//theApp.m_MessagePrint.SerialCountNew = true;

	CreatePrintData();

 	if (m_MessagePrint->boDynamic)//是否动态打印
	{
		mythreadDynamicBoo = true; 
		m_pPrintCreateThread = new PrintCreatThread(this);//启动打印内容生成线程
		m_pPrintCreateThread->start();
		m_pPrintShowThread = new PrintShowThread(this);//启动主界面打印显示线程
		m_pPrintShowThread->start();
	}
}

void MainWindow:: CreateCtrlCmd()
{
	BYTE ctrlType;
	int nType;
	vector<BYTE> tempCtrVec;

#ifdef BIG_CHAR // Control command (queCtr) : 39 Bytes
	nType = 39;
	ctrlType = (BYTE)(nType);
	//========= HEAD =========
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x0);
	tempCtrVec.push_back(ctrlType); ////大字符or高解析控制指令CONTENT长度
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);
	//======== CONTENT ========
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_PrintDelay.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_SynFrequency.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_PrintGray.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_EncoderRes.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_WheelDiameter.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_PulseWidth.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_TriggerMode.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_PrintingDirection.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_SynWheelCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_VoiceCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_HorizonalReverse));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_VerticalReverse));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_RepetePrintCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_RepeatTimes.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_RepeatDelay.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_SplicingCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.NozzleradioBGcheckedId));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_Offset.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_FlashSprayCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_FlashSprayInterval.toInt()));
	//tempCtrVec.push_back((BYTE)(m_ParamSetting.m_FlashSprayFrequency.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_UsingUVLightCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_TimeExpand.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_StartTime.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_YearShow.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_MonthShow.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_DayShow.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_HourShow.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_MinShow.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_SecondShow.toInt()));
	//========= END ==========
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);

#else  // Control command (queCtr) : 45 Bytes
	nType = 45;
	ctrlType = (BYTE)(nType);
//========= HEAD =========
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x3);
	tempCtrVec.push_back(0x0);
	tempCtrVec.push_back(ctrlType); //大字符or高解析控制指令CONTENT长度
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);
//======== CONTENT ========
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_PrintDelay.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_SynFrequency.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_PrintGray.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_EncoderRes.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_WheelDiameter.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_PulseWidth.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_TriggerMode.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_InkjetMode.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_PrintingDirection.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_SynWheelCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_VoiceCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.XDPIradioBGcheckedId));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.YDPIradioBGcheckedId));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_HorizonalReverse));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_VerticalReverse));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_RepetePrintCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_RepeatTimes.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_RepeatDelay.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_AdaptParaCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_InkVoltage.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_InkPulseWidth.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_SplicingCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.NozzleradioBGcheckedId));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_Offset.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_FlashSprayCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_FlashSprayInterval.toInt()));
//	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_FlashSprayFrequency.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_UsingUVLightCheck));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_TimeExpand.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_StartTime.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_YearShow.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_MonthShow.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_DayShow.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_HourShow.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_MinShow.toInt()));
	tempCtrVec.push_back((BYTE)(m_ParamSetting.m_SecondShow.toInt()));
//========= END ==========
	tempCtrVec.push_back(0xff);
	tempCtrVec.push_back(0xff);

#endif

	queCtr.push(tempCtrVec);
}

//生成下发打印数据
void MainWindow::CreatePrintData()
{	 	
	//theApp.mainPicPixel = theApp.m_MessagePrint->Pixel+1;
	//theApp.mainPicMatrx = theApp.m_MessagePrint->Matrix;

	BYTE dotDataLen_l,dotDataLen_h,matrix_name,pixelMes,pixelAll,printInterval;
	 
	ForPreQue = queue<vector<BYTE> >();
	 
	//信息重新发送，序列号按信息里面的开始值喷，如只改变喷印参数则按计数器的值继续喷
 	
	m_MessagePrint->boDynamic = false;
	getMessageDot();

	//CCodePrinterDlg *pParent = (CCodePrinterDlg *)GetParent();
	//pParent->m_PictureMain.Invalidate();

	if(m_MessagePrint->IntMes)
		delete[] m_MessagePrint->IntMes;
	m_MessagePrint->IntMes = new UINT32[m_MessagePrint->intRowMax];
	memset(m_MessagePrint->IntMes,0,sizeof(UINT32)*m_MessagePrint->intRowMax);

	for (int j = 0; j < 32; j++)//行
		for (int i = 0; i < m_MessagePrint->intRowMax; i++)//列
			m_MessagePrint->IntMes[i] += ((m_MessagePrint->boDotMes[j][i])?1:0)*pow(2.0,j);

	vector<BYTE> bytPrintData = m_MessagePrint->DotToByte(0,m_MessagePrint->intRowMax);
	dotDataLen_l = bytPrintData.size()%256; //dotDataLen_l与dotDataLen_h共同表达了打印数据的大小dotDataLen_h*256+dotDataLen_l
	dotDataLen_h = bytPrintData.size()/256;
	pixelMes = (BYTE)(m_MessagePrint->Pixel+1);
	matrix_name = pixelMes<<2;//低二位为模式 
	pixelAll = pixelMes|0x80; //表示该数据及时生效，开始打印，将前面的清除掉。

	/*计算两列之间的时间间隔
	若用户输入了打印速度V，则时间间隔t(微秒) = 两列间距离L(mm)÷打印速度V(m/min)÷1000×60×1000×1000
	其中，高解析两列之间的距离L(mm) = 1英寸25.4mm ÷ X方向DPI（默认300） = 0.085mm ; 大字符机L=3mm */
	double printSpeed = m_ParamSetting.m_PrintingSpeed.toDouble();
#ifdef BIG_CHAR
	printInterval = (BYTE)(3/printSpeed*60 + 0.5);//同步轮速度，一个字节只能表示0~255(大字符单位：毫秒)
#else
	printInterval = (BYTE)(0.085/printSpeed*60*1000 + 0.5);//同步轮速度，一个字节只能表示0~255(高解析单位：微秒)
#endif	
	//2020-07-15高解析测试：每秒2圈->速度113.1m/min->间隔225微秒，每秒10圈->速度22.6m/min->间隔45微秒
	//2020-07-16大字符测试：每秒4圈->速度45.24m/min->间隔4毫秒，每秒1/2圈->速度5.65m/min->间隔32毫秒(大字符机线速度一般在5~50m/min之间)

 	boPrintNowLock.lock();
		vector<BYTE>().swap(m_MessagePrint->bytPrintDataAll);//比clear()好，能够释放内存  
		vector<BYTE>().swap(m_MessagePrint->bytPrintDataAllOrder);  

		//预先给vector<BYTE>分配大小，然后再使用，效率也会高点，后面改正
		m_MessagePrint->bytPrintDataAll.push_back(0x1);
		m_MessagePrint->bytPrintDataAll.push_back(0x80);
		m_MessagePrint->bytPrintDataAll.push_back(0x6);
		m_MessagePrint->bytPrintDataAll.push_back(0x1);
		m_MessagePrint->bytPrintDataAll.push_back(0x11);
		m_MessagePrint->bytPrintDataAll.push_back(matrix_name);
		m_MessagePrint->bytPrintDataAll.push_back(pixelMes);
		m_MessagePrint->bytPrintDataAll.push_back(dotDataLen_l);
		m_MessagePrint->bytPrintDataAll.push_back(dotDataLen_h);
		m_MessagePrint->bytPrintDataAll.push_back(printInterval);
		m_MessagePrint->bytPrintDataAll.push_back(0xff);
		m_MessagePrint->bytPrintDataAll.push_back(0xff);

		//以下参见通信格式说明
		m_MessagePrint->bytPrintDataAllOrder.push_back(0x1);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0x80);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0x6);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0x1);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0x11);
		m_MessagePrint->bytPrintDataAllOrder.push_back(matrix_name);
		m_MessagePrint->bytPrintDataAllOrder.push_back(pixelMes);
		m_MessagePrint->bytPrintDataAllOrder.push_back(dotDataLen_l);
		m_MessagePrint->bytPrintDataAllOrder.push_back(dotDataLen_h);
		m_MessagePrint->bytPrintDataAllOrder.push_back(printSpeed);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0xff);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0xff);

		bytPrintData.push_back(0xff);
		bytPrintData.push_back(0xff);

		m_MessagePrint->bytPrintDataAll.insert(m_MessagePrint->bytPrintDataAll.end(),bytPrintData.begin(),bytPrintData.end());
		m_MessagePrint->bytPrintDataAllOrder.insert(m_MessagePrint->bytPrintDataAllOrder.end(),bytPrintData.begin(),bytPrintData.end());
		m_MessagePrint->intMesDis = m_MessagePrint->bytPrintDataAll;
		m_MessagePrint->boPrintNow = true;		
	boPrintNowLock.unlock();
/*
	if (m_MessagePrint->boDynamic)//是否动态打印
	{
  		ForPreQue.push(m_MessagePrint->bytPrintDataAll);  
  	}
*/
}

void MainWindow::getMessageDot()
{
	//CCodePrinterDlg *pParent = (CCodePrinterDlg *)GetParent();
	int nCurSel = 0;//pParent->m_Confi->m_reverse.GetCurSel();
	if (nCurSel == 0)
		m_MessagePrint->boReverse = false;
	else
		m_MessagePrint->boReverse = true;
	nCurSel = 0;//pParent->m_Confi->m_inverse.GetCurSel();
	if (nCurSel == 0)
		m_MessagePrint->boInverse = false;
	else
		m_MessagePrint->boInverse = true;

	m_MessagePrint->intRowMax = 0;

	for(int i=0;i<m_MessagePrint->OBJ_Vec.size();i++)
	{
		if (m_MessagePrint->intRowMax < (m_MessagePrint->OBJ_Vec[i]->intRowSize+m_MessagePrint->OBJ_Vec[i]->intRowStart))
		{
			m_MessagePrint->intRowMax = m_MessagePrint->OBJ_Vec[i]->intRowSize+m_MessagePrint->OBJ_Vec[i]->intRowStart;
			m_MessagePrint->scrMaxRow = m_MessagePrint->intRowMax;
		}
		if (m_MessagePrint->OBJ_Vec[i]->strType2 == "serial" || m_MessagePrint->OBJ_Vec[i]->strType2 == "time")
			m_MessagePrint->boDynamic = true;
	}

	if (m_MessagePrint->boDynamic)
	{
		for (int i = 0;i < m_MessagePrint->OBJ_Vec.size();i++)
		{
			//下段代码功能是什么？
			if (m_MessagePrint->OBJ_Vec.at(i)->strType2=="serial")
			{
				/*
				if (m_MessagePrint->SerialCountNew)
				{
					m_MessagePrint->OBJ_Vec[i]->CountNum = m_MessagePrint->OBJ_Vec[i]->intSerialStartValue;
					m_MessagePrint->OBJ_Vec[i]->CountNumRep = 1;
				}
				else if (!m_MessagePrint->SerialCountNew && !m_MessagePrint->SerialCountSet[0])
				{
					m_MessagePrint->OBJ_Vec[i]->intSerialStartValue = m_MessagePrint->OBJ_Vec[i]->CountNum;
					m_MessagePrint->OBJ_Vec[i]->CountNumRep = 1;
				}
				CCodePrinterDlg* tempDlg = (CCodePrinterDlg*)GetParent();
				switch(m_MessagePrint->OBJ_Vec.at(i)->intSerialCounter)
				{
				case 0:
					if (!m_MessagePrint->SerialCountNew && m_MessagePrint->SerialCountSet[0])
					{
						CString tempCstr;
						tempDlg->m_resetSerial->GetDlgItem(IDC_SET_VALUE1_EDIT)->GetWindowText(tempCstr);
						m_MessagePrint->OBJ_Vec[i]->CountNum=_ttoi(tempCstr);
						m_MessagePrint->OBJ_Vec[i]->intSerialStartValue = m_MessagePrint->OBJ_Vec[i]->CountNum;
						m_MessagePrint->OBJ_Vec[i]->CountNumRep = 1;
						m_MessagePrint->SerialCountSet[0] = false;
					}
					tempDlg->m_resetSerial->GetDlgItem(IDC_SERIAL1_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(m_MessagePrint->OBJ_Vec[i]->CountNum)));
					UpdateData(FALSE);
					break;
				case 1:
					if (!m_MessagePrint->SerialCountNew && m_MessagePrint->SerialCountSet[1])
					{
						CString tempCstr;
						tempDlg->m_resetSerial->GetDlgItem(IDC_SET_VALUE2_EDIT)->GetWindowText(tempCstr);
						m_MessagePrint->OBJ_Vec[i]->CountNum=_ttoi(tempCstr);
						m_MessagePrint->OBJ_Vec[i]->intSerialStartValue = m_MessagePrint->OBJ_Vec[i]->CountNum;
						m_MessagePrint->OBJ_Vec[i]->CountNumRep = 1;
						m_MessagePrint->SerialCountSet[1] = false;
					}
					tempDlg->m_resetSerial->GetDlgItem(IDC_SERIAL2_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(m_MessagePrint->OBJ_Vec[i]->CountNum)));
					UpdateData(FALSE);
					break;
				case 2:
					if (!m_MessagePrint->SerialCountNew && m_MessagePrint->SerialCountSet[2])
					{
						CString tempCstr;
						tempDlg->m_resetSerial->GetDlgItem(IDC_SET_VALUE3_EDIT)->GetWindowText(tempCstr);
						m_MessagePrint->OBJ_Vec[i]->CountNum=_ttoi(tempCstr);
						m_MessagePrint->OBJ_Vec[i]->intSerialStartValue = m_MessagePrint->OBJ_Vec[i]->CountNum;
						m_MessagePrint->OBJ_Vec[i]->CountNumRep = 1;
						m_MessagePrint->SerialCountSet[2] = false;
					}
					tempDlg->m_resetSerial->GetDlgItem(IDC_SERIAL3_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(m_MessagePrint->OBJ_Vec[i]->CountNum)));
					UpdateData(FALSE);
					break;
				case 3:
					if (!m_MessagePrint->SerialCountNew && m_MessagePrint->SerialCountSet[3])
					{
						CString tempCstr;
						tempDlg->m_resetSerial->GetDlgItem(IDC_SET_VALUE4_EDIT)->GetWindowText(tempCstr);
						m_MessagePrint->OBJ_Vec[i]->CountNum=_ttoi(tempCstr);
						m_MessagePrint->OBJ_Vec[i]->intSerialStartValue = m_MessagePrint->OBJ_Vec[i]->CountNum;
						m_MessagePrint->OBJ_Vec[i]->CountNumRep = 1;
						m_MessagePrint->SerialCountSet[3] = false;
					}
					tempDlg->m_resetSerial->GetDlgItem(IDC_SERIAL4_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(m_MessagePrint->OBJ_Vec[i]->CountNum)));
					UpdateData(FALSE);
					break;
				}
				*/
			}
		}
	}
	m_MessagePrint->getdot(); 
} 

//生成动态变化的打印数据到m_MessageEdit.bytPrintDataAll
void MainWindow::getSerialTimeDotBuf()
{
	boPrintNowLock.lock();
 		for(int i = 0; i < m_MessagePrint->OBJ_Vec.size(); i++)
		{
			 
			if (m_MessagePrint->OBJ_Vec[i]->strType2 == "serial")
			{					 
				CSerialOBJ* pSerialObj = (CSerialOBJ*)(m_MessagePrint->OBJ_Vec[i]);
				pSerialObj->CreateSerialDynamic(m_MessagePrint->bytPrintDataAll,m_MessagePrint->boReverse, m_MessagePrint->boInverse,
																m_MessagePrint->Matrix,m_MessagePrint->Pixel,m_MessagePrint->bytdigital5x5LineMap,
																m_MessagePrint->bytdigital7x5LineMap,m_MessagePrint->bytdigital12x12LineMap,
																m_MessagePrint->bytdigital16x12LineMap,m_MessagePrint->IntMes,m_MessagePrint->intRowMax);
			}
			else if (m_MessagePrint->OBJ_Vec[i]->strType2 == "time")
			{					 
				CTimeOBJ* pSerialObj = (CTimeOBJ*)(m_MessagePrint->OBJ_Vec[i]);

				pSerialObj->CreateTimeDynamic(m_MessagePrint->bytPrintDataAll,m_MessagePrint->boReverse,m_MessagePrint->boInverse,
																m_MessagePrint->Matrix,m_MessagePrint->Pixel,m_MessagePrint->bytdigital5x5LineMap,
																m_MessagePrint->bytdigital7x5LineMap,m_MessagePrint->bytdigital12x12LineMap,
																m_MessagePrint->bytdigital16x12LineMap,m_MessagePrint->IntMes,m_MessagePrint->intRowMax);
			}
		}	 
	boPrintNowLock.unlock();
	return;	 	
}

void MainWindow::getCurParam()
{
	ui->voltShowMWLab->setText(m_ParamSetting.m_InkVoltage);
	ui->voltShowMWLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
	ui->PWShowMWLab->setText(m_ParamSetting.m_InkPulseWidth);
	ui->PWShowMWLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
	ui->grayShowMWLab->setText(m_ParamSetting.m_PrintGray);
	ui->grayShowMWLab->setAlignment(Qt::AlignCenter);
	ui->speedShowMWLab->setText(m_ParamSetting.m_PrintingSpeed);
	ui->speedShowMWLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
	ui->timeDelayShowMWLab->setText(m_ParamSetting.m_PrintDelay);
	ui->timeDelayShowMWLab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
	ui->dirShowMWLab->setText(m_ParamSetting.m_PrintingDirection);
	ui->dirShowMWLab->setAlignment(Qt::AlignCenter);
}