#ifndef PRINTTHEAD_H
#define PRINTTHEAD_H

#include <QThread>
#include "ModuleMain.h"

class PrintThead : public QThread //喷墨打印线程
{
	Q_OBJECT

public:
	PrintThead(QObject *parent);
	~PrintThead();

	void closeThread();

protected:
    virtual void run(); 

private:
    volatile bool m_isStop; 
	bool m_bUsingPhotoESwitch;//用光电开�?
	bool m_bTriggerByHigh;//高电平触�?
	bool m_bPhotoESwitchState;//光电开关状�?
	bool m_bPhotoESwitchStatePre;//光电开关前一个状�?
	bool m_bTrigger; //是否触发打印�?
	int m_SwitchHande;
	int m_SynchronizerHande;
	int m_bUsingSynchronizer;//�Ƿ�ʹ��ͬ����
	unsigned char* strTempCmd;

private:
	
};

#endif // PRINTTHEAD_H
