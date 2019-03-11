#ifndef CALENDARWORKER_H
#define CALENDARWORKER_H
#include <QWidget>
#include "worker.h"

//выделение цветом
//http://doc.crossplatform.ru/qt/4.7.x/widgets-calendarwidget.html

class Creator;
class QCalendarWidget;
class CalendarWorker: public Worker
{
    Q_OBJECT
public:
    explicit CalendarWorker(Creator *parent, QWidget* widget);
    QDate getSelectedDate();

private:
    QCalendarWidget * workingwidget;
    void clearCalendar();
private slots:

    void setDate(const QDate&);
    void setupDateList(const QMap<QString, QString> & filemap);



};

#endif // CALENDARWORKER_H
