#include "VisitsDelegat.h"
#include <QComboBox>
#include <QWidget>
#include <QtWidgets>
//#include <QDebug>
VisitsDateDelegate::VisitsDateDelegate(QList <int> list, QObject *parent)
    : QItemDelegate(parent)
{
    this->list = list;
}

void VisitsDateDelegate::paint(QPainter *painter,
                                 const QStyleOptionViewItem &option,
                                 const QModelIndex &index) const
{
    {
        if (list.contains(index.column()))
        {
            QDate dateDate =index.model()->data(index, Qt::DisplayRole).toDate();
            QStyleOptionViewItem myOption = option;
            // myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
            myOption.displayAlignment = Qt::AlignCenter; //http://doc.qt.io/archives/qt-4.8/qt.html#AlignmentFlag-enum
            drawDisplay(painter, myOption, myOption.rect, dateDate.toString("dd-MMM-yyyy"));//http://qt-doc.ru/klass-daty-qdate.html
            drawFocus(painter, myOption, myOption.rect);
        } else{
            QItemDelegate::paint(painter, option, index);
        }
    }
}

QWidget *VisitsDateDelegate::createEditor(QWidget *parent,
                                            const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    if(index.row() == index.model()->rowCount()-1)
    {//index.model()->rowCount())
        //qDebug()<< index.row()<< "vs"<<index.model()->rowCount()-1;
        //bool as=if (index.row() == index.model()->rowCount()-1);
        //qDebug()<< if (index.row() == index.model()->rowCount()-1);
        //qDebug()<< index.row();
    if (list.contains(index.column()) ) {
        QDateEdit *dateEdit =  new  QDateEdit(parent);
        dateEdit->setAlignment(Qt::AlignCenter);
        dateEdit->setCalendarPopup(true);
        QDate dateDate =index.model()->data(index, Qt::DisplayRole).toDate();
        dateEdit->setDate(dateDate);
        connect(dateEdit, SIGNAL(editingFinished()),
                this, SLOT(commitAndCloseEditor()));
        return dateEdit;
    } else {
        return QItemDelegate::createEditor(parent, option, index);
    }
}
    else return 0;
}

void VisitsDateDelegate::setEditorData(QWidget *editor,
                                         const QModelIndex &index) const
{
    if (list.contains(index.column()) ) {
        QDateEdit *dateEdit = qobject_cast<QDateEdit *>(editor);
        QDate date = dateEdit->date();
        // editor->d
        // QDate date2 = dateEdit->date();
        dateEdit->setDate(date);
    } else {
        QItemDelegate::setEditorData(editor, index);
    }
}

void VisitsDateDelegate::setModelData(QWidget *editor,
                                        QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    if (list.contains(index.column()) ) {
        QDateEdit *dateEdit = qobject_cast<QDateEdit *>(editor);
        QDate date = dateEdit->date();
        model->setData(index, date);
    } else {
        QItemDelegate::setModelData(editor, model, index);
    }
}

void VisitsDateDelegate::commitAndCloseEditor()
{
//    QDateEdit *editor = qobject_cast<QDateEdit *>(sender());
   // emit commitData(editor);
  //  qDebug()<<"commitAndCloseEditor()";
   //   emit closeEditor(editor);//?
}

