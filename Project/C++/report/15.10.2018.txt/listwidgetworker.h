#ifndef LISTWIDGETWORKER_H
#define LISTWIDGETWORKER_H
#include <QWidget>
#include "worker.h"
class Creator;
class QListWidget;
class ListWidgetWorker: public Worker
{
    Q_OBJECT
public:

    explicit ListWidgetWorker(Creator *parent, QWidget* widget);
    void addData(const QMap <QString,QString>&);

private:
    QListWidget * workingwidget;
private slots:
    void setupDateList(const QMap<QString, QString> &);
    void setDate(const QDate&);
    void setWorkingDirectorySlot(const QString &);



};

#endif // LISTWIDGETWORKER_H
