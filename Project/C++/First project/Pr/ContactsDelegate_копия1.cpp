#include "ContactsDelegate.h"
#include <QComboBox>
#include <QWidget>
#include <QtWidgets>
#include <QCheckBox>


class BooleanWidget : public QWidget
{
    Q_OBJECT
    QCheckBox * checkBox;

    public:
    BooleanWidget(QWidget * parent = 0)
    {
        checkBox = new QCheckBox(this);
        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->addWidget(checkBox,0, Qt::AlignCenter);
    }

    bool isChecked(){return checkBox->isChecked();}
    void setChecked(bool value){checkBox->setChecked(value);}
};













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
        dateEdit->setDate(dateDate);
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
        dateEdit->setDate(date);
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




ContactsCheckboxDelegate:: ContactsCheckboxDelegate(QList <int> list, QObject *parent)
    : QItemDelegate(parent)
{
    this->list = list;
    this->popup=false;
}

void  ContactsCheckboxDelegate::paint(QPainter *painter,
                                      const QStyleOptionViewItem &option,
                                      const QModelIndex &index) const
{
    drawCheck(painter, option, option.rect, index.data().toBool() ? Qt::Checked : Qt::Unchecked);
    drawFocus(painter, option, option.rect);
}

//https://ru.vingrad.com/CheckBoxDelegate-id50b2a82c6ccc19606f0a58fb

QWidget * ContactsCheckboxDelegate::createEditor(QWidget *parent,
                                                 const QStyleOptionViewItem &/*option*/,

                                                 const QModelIndex &/*index*/) const
//http://qaru.site/questions/1426735/checkbox-and-itemdelegate-in-a-tableview
{
    BooleanWidget *editor = new BooleanWidget( parent );
    connect( editor, SIGNAL( toggled ( bool ) ), this, SLOT( changed( bool ) ) );
    return editor;

}


void  ContactsCheckboxDelegate::setEditorData(QWidget *editor,
                                              const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::DisplayRole).toInt();
        BooleanWidget *checkbox = static_cast<BooleanWidget*>(editor);
        if(value == 1)
        {
            checkbox->setChecked(true);
        }
        else
        {
            checkbox->setChecked(false);
        }
}

void  ContactsCheckboxDelegate::setModelData(QWidget *editor,
                                             QAbstractItemModel *model,
                                             const QModelIndex &index) const
{
    BooleanWidget *checkBox = qobject_cast<BooleanWidget*>( editor );
    Qt::CheckState value;

    if(checkBox->isChecked())
        value = Qt::Checked;
    else
        value = Qt::Unchecked;
    model->setData( index, value, Qt::DisplayRole);
}




//void BooleanEditor::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    drawCheck(painter, option, option.rect, index.data().toBool() ? Qt::Checked : Qt::Unchecked);
//    drawFocus(painter, option, option.rect);
//}
