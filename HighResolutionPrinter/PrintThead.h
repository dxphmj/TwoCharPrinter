#ifndef PRINTTHEAD_H
#define PRINTTHEAD_H

#include <QThread>
#include "ModuleMain.h"

class PrintThead : public QThread //鍠峰ⅷ鎵撳嵃绾跨▼
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
	bool m_bUsingPhotoESwitch;//用光电开关
	bool m_bTriggerByHigh;//高电平触发
	bool m_bPhotoESwitchState;//光电开关状态
	bool m_bPhotoESwitchStatePre;//光电开关前一个状态
	bool m_bTrigger; //是否触发打印了
	int m_SwitchHande;
	int m_SynchronizerHande;
	int m_bUsingSynchronizer;//是否使用同步器
	unsigned char* strTempCmd;

private://驱动相关句柄
	int fd2; 
	int read_result;
	int write_result;
	
};

#endif // PRINTTHEAD_H
