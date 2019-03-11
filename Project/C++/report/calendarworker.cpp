#include "calendarworker.h"
#include "creator.h"
#include <QCalendarWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMap>
#include <QDebug>
#include <QTextCharFormat>

CalendarWorker::CalendarWorker(Creator *parent, QWidget *widget):Worker(parent)
{
    workingwidget = static_cast <QCalendarWidget*> (widget);
}

QDate CalendarWorker::getSelectedDate()
{
    return this->workingwidget->selectedDate();
}

void CalendarWorker::setDate(const QDate &date)
{
    QDate aldselectdate = workingwidget->selectedDate();
    if ( aldselectdate!=date)
        workingwidget->setSelectedDate(date);
    //qDebug()<<"workingwidget->setSelectedDate(date);" << date;
}

void CalendarWorker::setupDateList(const QMap<QString, QString> &filemap)
{
    clearCalendar();
    QString str;
    QDate date;
    //QDate date2 = QDate::currentDate();
    QTextCharFormat format;
    format.setForeground(Qt::blue);
    format.setFontWeight(QFont::Bold);
    QMapIterator<QString, QString> it(filemap);
    while (it.hasNext())
    {
        it.next();
        str = it.key();
        // date = Creator::getFileName(str);
        date =  QDate::fromString(Creator::getFileName(str),"dd.MM.yyyy");
        this->workingwidget->setDateTextFormat(date,format);
        // Creator::getFileName(str);
    }

    // this->workingwidget->setDateTextFormat(date2,format);
}

void CalendarWorker::clearCalendar()
{
    QMap<QDate, QTextCharFormat> map = this->workingwidget->dateTextFormat();
    QMapIterator <QDate, QTextCharFormat> it(map);
    QTextCharFormat format;
    QDate date;
    format.setForeground(Qt::black);
    format.setFontWeight(QFont::Normal);
    while (it.hasNext())
    {
        it.next();
        date = it.key();
        this->workingwidget->setDateTextFormat(date,format);
    }
}


