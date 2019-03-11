#ifndef PATHLINEEDITWORKER_H
#define PATHLINEEDITWORKER_H
#include "worker.h"
#include <QObject>

class Creator;
class QLineEdit;

class PathLineEditWorker : public Worker
{
public:
    explicit PathLineEditWorker(Creator *parent, QWidget* widget);
    void setPath(QString&);
    QString getPath();
private:
    QLineEdit * workingwidget;
};

#endif // PATHLINEEDITWORKER_H
