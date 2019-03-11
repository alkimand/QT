#include "listwidgetworker.h"
#include "creator.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QMap>
#include <QDebug>

ListWidgetWorker::ListWidgetWorker(Creator *parent, QWidget *widget):Worker(parent)
{
    workingwidget = static_cast <QListWidget*> (widget);
    workingwidget->clear();
}

void ListWidgetWorker::addData(const QMap<QString, QString> & filemap)
{
    //    QString str;

    //    QMap <QString, QString>::const_iterator i = filemap.constBegin();
    //    while (i != filemap.constEnd())
    //    {
    //        QListWidgetItem *item = new QListWidgetItem("i.key", workingwidget);
    //        item->setCheckState(Qt::Checked);
    //    }

}

void ListWidgetWorker::setupDateList(const QMap<QString, QString> & filemap)
{

    disconnect (this->creator, SIGNAL(setupDateList(const QMap <QString,QString>&)), this, SLOT(setupDateList(const QMap <QString,QString>&)));
    disconnect (this->creator, SIGNAL (setDate(const QDate&)), this, SLOT (setDate(const QDate&)));
    disconnect (this->creator, SIGNAL (CpathChanges(const QString &)), this, SLOT (setWorkingDirectorySlot(const QString &)));
    workingwidget->clear();
    QString str;
    QMapIterator<QString, QString> it(filemap);
    while (it.hasNext())
    {
        it.next();
        str = it.key();
        QListWidgetItem *item = new QListWidgetItem(Creator::getFileName(str), workingwidget);
        item->setCheckState(Qt::Checked);
        workingwidget->setCurrentItem(item);
    }
    connect (this->creator, SIGNAL(setupDateList(const QMap <QString,QString>&)), this, SLOT(setupDateList(const QMap <QString,QString>&)));
    connect (this->creator, SIGNAL (setDate(const QDate&)), this, SLOT (setDate(const QDate&)));
    connect (this->creator, SIGNAL (CpathChanges(const QString &)), this, SLOT (setWorkingDirectorySlot(const QString &)));
}

void ListWidgetWorker::setDate(const QDate &date)
{
    QList<QListWidgetItem *> selected_items = this->workingwidget->selectedItems();
    if(selected_items.size() > 0)
    {
        QVariant selectdate = selected_items[0]->text();
        QString  Stringselectdate = selectdate.toString();
        QListWidgetItem *item;
        QString strdate=date.toString("dd.MM.yyyy");
        if (Stringselectdate!= strdate)
        {
            QList<QListWidgetItem *> found = this->workingwidget->findItems(strdate,Qt::MatchFlag::MatchFixedString);
            for (int i=0;i<found.count();i++)
            {
                item = found.at(i);
                this->workingwidget->setItemSelected(item,true);
            }
        }
    }
    //qDebug()<<"ListWidgetWorker::setDate(const QDate &date) "<< date;

}

void ListWidgetWorker::setWorkingDirectorySlot(const QString &)
{

}

//QDate aldselectdate = workingwidget->selectedDate();
//if ( aldselectdate!=date)
//workingwidget->setSelectedDate(date);
