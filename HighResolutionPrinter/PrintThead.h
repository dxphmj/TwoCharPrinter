#ifndef PRINTTHEAD_H
#define PRINTTHEAD_H

#include <QThread>
#include <QtSerialPort/qserialport.h>
#include <QtSerialPort/qserialportinfo.h>



struct structRowCol2
{
	int m_nRow, m_nCOl;
	structRowCol2()
	{
		m_nRow = 1;
		m_nCOl = 1;
	}
	structRowCol2(int nRow, int nCol)
	{
		m_nRow = nRow;
		m_nCOl = nCol;
	}
};

class PrintThead : public QThread //喷墨打印线程
{
	Q_OBJECT

public:
	PrintThead(QObject *parent);
	~PrintThead();

	void closeThread();
	void OpenCom();
	void initPrinter();
	structRowCol2 m_StructRowCol[301];

 private slots:
    void serialPort_readyRead();

protected:
    virtual void run(); 

private:
	QSerialPort* serial;
    volatile bool m_isStop; 
	bool m_bUsingPhotoESwitch;//用光电开关
	bool m_bTriggerByHigh;//高电平触发
	bool m_bPhotoESwitchState;//光电开关状态
	bool m_bPhotoESwitchStatePre;//光电开关前一个状态
	bool m_bTrigger; //是否触发打印了
	int m_SwitchHande;
	int m_SynchronizerHande;
	int m_bUsingSynchronizer;//是否使用同步器
 
private:
	
};

#endif // PRINTTHEAD_H
