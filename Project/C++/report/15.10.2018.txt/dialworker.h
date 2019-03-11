#ifndef DIALWORKER_H
#define DIALWORKER_H
#include "worker.h"
#include <QWidget>
class Creator;
class QDial;
class DialWorker: public Worker
{

public:
    explicit  DialWorker(Creator *parent, QWidget* widget);

private:
    QDial * workingwidget;

};

#endif // DIALWORKER_H
