#include "dialworker.h"
#include "creator.h"
#include "worker.h"
#include <QDial>

DialWorker::DialWorker(Creator *parent, QWidget *widget):Worker(parent)
{
    workingwidget = static_cast <QDial*> (widget);
}
