#include "pathlineeditworker.h"
#include <QLineEdit>
#include "creator.h"


PathLineEditWorker::PathLineEditWorker(Creator *parent, QWidget *widget):Worker(parent)
{
    workingwidget = static_cast <QLineEdit*> (widget);
}

void PathLineEditWorker::setPath(QString &path)
{
    workingwidget->setText(path);
}

QString PathLineEditWorker::getPath()
{
    return workingwidget->text();
}
