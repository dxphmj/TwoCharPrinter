#ifndef PRINTCREATTHREAD_H
#define PRINTCREATTHREAD_H

#include <QThread>

class PrintCreatThread : public QThread
{
	Q_OBJECT

public:
	PrintCreatThread(QObject *parent);
	~PrintCreatThread();

private:

protected:
    virtual void run(); 
	
};

#endif // PRINTCREATTHREAD_H
