#include "ContactsDelegate.h"
#include <QComboBox>
#include <QWidget>
#include <QtWidgets>
#include <QCheckBox>




ContactsDateDelegate::ContactsDateDelegate(QList <int> list, QObject *parent)
    : QItemDelegate(parent)
{
    this->list = list;
}

void ContactsDateDelegate::paint(QPainter *painter,
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

QWidget *ContactsDateDelegate::createEditor(QWidget *parent,
                                            const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    if (list.contains(index.column()) ) {//index.row=
        QDateEdit *dateEdit =  new  QDateEdit(parent);
        //dateEdit->setDisplayFormat("dd-MMM-yyyy"); //http://qt-doc.ru/klass-daty-qdate.html
        dateEdit->setAlignment(Qt::AlignCenter);
        dateEdit->setCalendarPopup(true);
        //index(mapper->currentIndex(),MAIN_stasus_Id), Qt::DisplayRole).toString();

        //date =
        // dateEdit->setDate(index.data());
        QDate dateDate =index.model()->data(index, Qt::DisplayRole).toDate();
        if (dateDate.isValid()){
            dateEdit->setDate(dateDate);}
        else dateEdit->setDate(QDate::currentDate());

        connect(dateEdit, SIGNAL(editingFinished()),
                this, SLOT(commitAndCloseEditor()));
        return dateEdit;
    } else {
        return QItemDelegate::createEditor(parent, option, index);
    }
}

void ContactsDateDelegate::setEditorData(QWidget *editor,
                                         const QModelIndex &index) const
{
    if (list.contains(index.column())) {
        QDateEdit *dateEdit = qobject_cast<QDateEdit *>(editor);
        QDate date = dateEdit->date();
        // editor->d
        // QDate date2 = dateEdit->date();
        //if (date.isValid()){
        dateEdit->setDate(date);//}
    } else {
        QItemDelegate::setEditorData(editor, index);
    }
}

void ContactsDateDelegate::setModelData(QWidget *editor,
                                        QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    if (list.contains(index.column())) {
        QDateEdit *dateEdit = qobject_cast<QDateEdit *>(editor);
        QDate date = dateEdit->date();
        model->setData(index, date);
    } else {
        QItemDelegate::setModelData(editor, model, index);
    }
}

void ContactsDateDelegate::commitAndCloseEditor()
{
    QDateEdit *editor = qobject_cast<QDateEdit *>(sender());
    emit commitData(editor);
    //  emit closeEditor(editor);//?
}
