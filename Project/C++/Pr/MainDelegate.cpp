#include "MainDelegate.h"
#include <QComboBox>
#include <QWidget>
#include <QtWidgets>
#include <QTimer>
#include<thread>

DateDelegate::DateDelegate(QList <int> list, QObject *parent)
    : QItemDelegate(parent)
{
    this->list = list;
    //this->m_timer=new QTimer;
}

void DateDelegate::paint(QPainter *painter,
                         const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{

    {
        if (list.contains(index.column()) && (index.model()->data(index,Qt::DisplayRole).toDate().isValid()))
        {
            //QProcess::execute("CLS");
            // qDebug()<<index.model()->data(index,Qt::DisplayRole).toDate()<<" from paint";
            QDate dateDate =index.model()->data(index, Qt::DisplayRole).toDate();
            QStyleOptionViewItem myOption = option;
            // myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
            //
            //QPalette p(option.palette);
            //p.setColor(QPalette::Base, Qt::red);
            //            p.setColor(QPalette::HighlightedText, Qt::red);
            //            p.setColor(QPalette::Highlight, Qt::red);


            if (index.column()== list.last())
            {

                if  (dateDate==QDate::currentDate())
                {
                    painter->fillRect(option.rect, Qt::green);
                }
                else if   (dateDate < QDate::currentDate())
                {
                    //QPalette::ColorGroup cg = option.state & QStyle::State_Enabled
                    //   ? QPalette::Normal : QPalette::Disabled;
                    painter->fillRect(option.rect, Qt::lightGray);
                }
                else {
                    //  QPalette::ColorGroup cg = option.state & QStyle::State_Enabled
                    //      ? QPalette::Normal : QPalette::Disabled;
                    painter->fillRect(option.rect, Qt::yellow);
                }
            }
            myOption.displayAlignment = Qt::AlignCenter; //http://doc.qt.io/archives/qt-4.8/qt.html#AlignmentFlag-enum
            drawDisplay(painter, myOption, myOption.rect, dateDate.toString("dd-MMM-yyyy"));//http://qt-doc.ru/klass-daty-qdate.html
            drawFocus(painter, myOption, myOption.rect);
        } else{
            QItemDelegate::paint(painter, option, index);
        }
    }
}

QWidget *DateDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const
{
    if (list.contains(index.column()) && (index.model()->data(index,Qt::DisplayRole).toDate().isValid()))
    {
        //qDebug()<<index.model()->data(index,Qt::DisplayRole).toDate()<<" from createEditor";
        QDateEdit *dateEdit =  new  QDateEdit(parent);
        //dateEdit->setDisplayFormat("dd-MMM-yyyy"); //http://qt-doc.ru/klass-daty-qdate.html 2000-01-01
        dateEdit->setAlignment(Qt::AlignCenter);
        dateEdit->setCalendarPopup(true);
        //index(mapper->currentIndex(),MAIN_stasus_Id), Qt::DisplayRole).toString();



        QDate dateDate =index.model()->data(index, Qt::DisplayRole).toDate();
        dateEdit->setDate(dateDate);
        connect(dateEdit, SIGNAL(editingFinished()),
                this, SLOT(commitAndCloseEditor()));

        return dateEdit;
    } else {
        //qDebug()<<index.model()->data(index,Qt::DisplayRole)<<" from createEditor else";
        return QItemDelegate::createEditor(parent, option, index);
    }
}

void DateDelegate::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const
{
    if (list.contains(index.column()) && (index.model()->data(index,Qt::DisplayRole).toDate().isValid()))
    {
        // qDebug()<<index.model()->data(index,Qt::DisplayRole).toDate()<<" setEditorData";
        QDateEdit *dateEdit = qobject_cast<QDateEdit *>(editor);
        QDate date = dateEdit->date();
        // editor->d
        // QDate date2 = dateEdit->date();


        dateEdit->setDate(date);

    } else {
        QItemDelegate::setEditorData(editor, index);
    }
}

void DateDelegate::setModelData(QWidget *editor,
                                QAbstractItemModel *model,
                                const QModelIndex &index) const
{
    if(list.contains(index.column()) && (index.model()->data(index,Qt::DisplayRole).toDate().isValid()))
    {
        //qDebug()<<index.model()->data(index,Qt::DisplayRole).toDate()<<" setModelData";
        //qDebug()<<model->data(index,Qt::DisplayRole)<<" from setModelData";
        QDateEdit *dateEdit = qobject_cast<QDateEdit *>(editor);
        QDate date = dateEdit->date();
        model->setData(index, date);
    } else {
        QItemDelegate::setModelData(editor, model, index);
    }
}

void DateDelegate::setRandomBackgroundColor2(QPainter *painter, QStyleOptionViewItem &option, Qt::GlobalColor)
{
   // QTimer *timer = new QTimer(this);
    //QColor color = pen().color();
    //painte
    //if (painter-> painter->fillRect(option.rect, Qt::blue);
    painter->fillRect(option.rect, Qt::red);
}

void DateDelegate::commitAndCloseEditor()
{
    QDateEdit *editor = qobject_cast<QDateEdit *>(sender());
    emit commitData(editor);
    //  emit closeEditor(editor);//?
}

void DateDelegate::setRandomBackgroundColor(QPainter *painter, QStyleOptionViewItem &option, Qt::GlobalColor)
{
    painter->fillRect(option.rect, Qt::blue);
}

//void DateDelegate::BlackWindow()
//{
//    this->setPalette(QPalette(Qt::black));
//    this->show();
//    m_timer->stop();
//}
