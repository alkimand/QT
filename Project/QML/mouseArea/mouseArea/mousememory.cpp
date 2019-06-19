#include "mousememory.h"

MouseMemory::MouseMemory(QObject *parent) : QObject(parent)
{

}

void MouseMemory::test()
{
    qDebug () << "Heloo from C++";
}

void MouseMemory::clear()
{
    qDebug() <<"Clear the data";
}

void MouseMemory::save()
{
     qDebug() <<"save the data";
}

void MouseMemory::add(double x, double y)
{
    QPoint p(x,y);
    qDebug() <<"Adding" <<p;
}

void MouseMemory::add(QPoint point)
{
    qDebug () << "Adding Float" << point;
}
