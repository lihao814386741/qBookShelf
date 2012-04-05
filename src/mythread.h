#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread 
{
public:
    MyThread();
    virtual void run();

};

#endif // MYTHREAD_H
