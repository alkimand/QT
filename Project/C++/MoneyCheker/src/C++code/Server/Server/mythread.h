#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QObject>
#include <QWidget>


class MyThread : public QThread
{
public:
    MyThread();
};

#endif // MYTHREAD_H
