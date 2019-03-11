#ifndef WORKER_H
#define WORKER_H
#include <QObject>
#include <QWidget>
class Creator;
class Worker:public QObject
{
    Q_OBJECT
public:
    explicit Worker(Creator* parent);

    // QWidget* parentwidget;
    Creator* creator;
private:

};

#endif // WORKER_H
