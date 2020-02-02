#ifndef PRINTSHOWTHREAD_H
#define PRINTSHOWTHREAD_H

#include <QThread>

class PrintShowThread : public QThread
{
	Q_OBJECT

public:
	PrintShowThread(QObject *parent);
	~PrintShowThread();

private:
	
protected:
    virtual void run(); 

};

#endif // PRINTSHOWTHREAD_H
