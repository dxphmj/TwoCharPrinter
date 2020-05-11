#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTime>
#include <QProgressBar>
#include "filemanageform.h"
#include "paramsettingform.h"
#include "ClassMessage.h"
#include "PrintThead.h"
#include "PrintCreatThread.h"
#include "PrintShowThread.h"
#include "OBJ_Type.h"


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

	mythreadDynamicBoo = false;

	myTimer = new QTimer(this);
	myTimer->start(0);
	connect(myTimer,SIGNAL(timeout()),this,SLOT(GetDateTime()));
	ui->timeShowLab->setStyleSheet("qproperty-alignment: 'AlignVCenter | AlignRight';color:rgb(255,255,255);font-size:40px;");
	 
	m_pPrintThread = new PrintThead(this);//启动打印线程
	m_pPrintThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::closeBut_clicked()
{

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

//生成下发打印数据
void MainWindow::CreatePrintData()
{	 	
	//theApp.mainPicPixel = theApp.m_MessagePrint->Pixel+1;
	//theApp.mainPicMatrx = theApp.m_MessagePrint->Matrix;

	BYTE dotDataLen_l,dotDataLen_h,matrix_name,pixelMes,pixelAll;
	 
	ForPreQue = queue<vector<BYTE>>();
	 
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
		m_MessagePrint->bytPrintDataAll.push_back(0xff);
		m_MessagePrint->bytPrintDataAll.push_back(0xff);

		//以下参见通信格式说明
		m_MessagePrint->bytPrintDataAllOrder.push_back(0x1);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0x80);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0x6);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0x1);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0x11);
		m_MessagePrint->bytPrintDataAllOrder.push_back(matrix_name);
		m_MessagePrint->bytPrintDataAllOrder.push_back(pixelAll);
		m_MessagePrint->bytPrintDataAllOrder.push_back(dotDataLen_l);
		m_MessagePrint->bytPrintDataAllOrder.push_back(dotDataLen_h);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0xff);
		m_MessagePrint->bytPrintDataAllOrder.push_back(0xff);

		bytPrintData.push_back(0xff);
		bytPrintData.push_back(0xff);

		m_MessagePrint->bytPrintDataAll.insert(m_MessagePrint->bytPrintDataAll.end(),bytPrintData.begin(),bytPrintData.end());
		m_MessagePrint->bytPrintDataAllOrder.insert(m_MessagePrint->bytPrintDataAllOrder.end(),bytPrintData.begin(),bytPrintData.end());
		m_MessagePrint->intMesDis = m_MessagePrint->bytPrintDataAll;
		m_MessagePrint->boPrintNow = true;		
	boPrintNowLock.unlock();

	if (m_MessagePrint->boDynamic)//是否动态打印
	{
  		ForPreQue.push(m_MessagePrint->bytPrintDataAll);  
  	} 	 
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