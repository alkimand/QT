#include "ContactsDelegate.h"
#include <QComboBox>
#include <QWidget>
#include <QtWidgets>
#include <QCheckBox>
#include <qcheckbox.h>
#include "ContactsCheckboxDelegate.h"
#include <QItemDelegate>
//#include <QDebug>
#include <QStyleOptionViewItemV4>
#include <QStyledItemDelegate>
void BooleanWidget::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    Q_UNUSED(index)
    //drawCheck(painter, option, option.rect, index.data().toBool() ? Qt::Checked : Qt::Unchecked);
    //drawFocus(painter, option, option.rect);
}


CheckBoxDelegate::CheckBoxDelegate(QList <int> list,QObject *parent)
{
    Q_UNUSED(parent)
    this->list = list;
}//QItemDelegate
// QStyledItemDelegate(parent)


void CheckBoxDelegate::changed( bool value )
{
    Q_UNUSED(value)
    BooleanWidget *checkbox = static_cast<BooleanWidget*>( sender() );
    //QCheckBox *checkbox = static_cast<QCheckBox*>( sender() );
    emit commitData( checkbox );
    emit closeEditor( checkbox );
}

void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // QStyleOptionViewItemV4 viewItemOption(option);
    if (list.contains(index.column()))
    {
        bool checkValue;
        //Q_UNUSED(value)
        QStyleOptionButton BtnStyle;
        BtnStyle.state = QStyle::State_Enabled;

        if(index.model()->data(index, Qt::DisplayRole).toBool() == true)
        {
            BtnStyle.state |= QStyle::State_On;
            checkValue = true;
        }else{
            BtnStyle.state |= QStyle::State_Off;
            checkValue = false;
        }


        BtnStyle.direction = QApplication::layoutDirection();
        BtnStyle.rect = option.rect;
        // QApplication::style()->drawControl(QStyle::CE_CheckBox,&BtnStyle,painter );
        // QApplication::style()->drawControl(QStyle::CE_CheckBox,&BtnStyle,painter );
        drawCheck(painter, option, option.rect, index.data().toBool() ? Qt::Checked : Qt::Unchecked);
        drawFocus(painter, option, option.rect);


        //             const int textMargin = QApplication::style()->pixelMetric(QStyle::PM_FocusFrameHMargin) + 1;
        //             QRect newRect = QStyle::alignedRect(option.direction, Qt::AlignCenter,
        //                                                 QSize(option.decorationSize.width() + 5,option.decorationSize.height()),
        //                                                 QRect(option.rect.x() + textMargin, option.rect.y(),
        //                                                       option.rect.width() - (2 * textMargin), option.rect.height()));
        //             viewItemOption.rect = newRect;
        //         }
        //QStyledItemDelegate::paint(painter, viewItemOption, index);







    }else{
        QItemDelegate::paint(painter, option, index);
        // QStyledItemDelegate::paint(painter, viewItemOption, index);
    }
}



void CheckBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // editor->setGeometry(option.rect);

    if(list.contains(index.column()))
    {
        editor->setGeometry(option.rect);
    }
    else{
    }
    QItemDelegate::updateEditorGeometry(editor,option,index);
    // QStyledItemDelegate::updateEditorGeometry(editor,option,index);
}






QWidget *CheckBoxDelegate::createEditor( QWidget *parent,const QStyleOptionViewItem & option ,const QModelIndex & index ) const
{
    if (list.contains(index.column()) ) {//index.row=
        BooleanWidget *editor = new BooleanWidget( parent );
        //editor->setStyleSheet("QCheckBox {margin-left: 43%; margin-right: 57%;}");
        editor->setStyleSheet("QCheckBox {margin-left: auto; margin-right: auto;}");
        // QCheckBox *CheckBox =new QCheckBox;
        //  index.model()->data(index, Qt::DisplayRole).toBool();
        // QDateEdit *dateEdit =  new  QDateEdit(parent);
        //dateEdit->setDisplayFormat("dd-MMM-yyyy"); //http://qt-doc.ru/klass-daty-qdate.html
        //CheckBox->setAlignment(Qt::AlignCenter);
        //dateEdit->setCalendarPopup(true);
        //index(mapper->currentIndex(),MAIN_stasus_Id), Qt::DisplayRole).toString();

        //date =
        // dateEdit->setDate(index.data());
        // QDate dateDate =index.model()->data(index, Qt::DisplayRole).toDate();
        // dateEdit->setDate(dateDate);
        //        connect(CheckBox, SIGNAL(editingFinished()),
        //                this, SLOT(commitAndCloseEditor()));

        // connect( editor, SIGNAL( toggled ( bool ) ), this, SLOT( changed( bool ) ) );

        return editor;
    } else {
        return QItemDelegate::createEditor(parent, option, index);
        //return QStyledItemDelegate::createEditor(parent, option, index);
    }
}


CheckBoxDelegate::~CheckBoxDelegate()
{

}

void CheckBoxDelegate::setEditorData( QWidget *editor,const QModelIndex &index ) const
{
    if (list.contains(index.column())) {
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
        // QCheckBox CheckBox =index.model()->data(index, Qt::DisplayRole).toBool();
        // QCheckBox *CheckBox = qobject_cast<QCheckBox *>(editor);
        // QDate date = dateEdit->date();
        // editor->d
        // QDate date2 = dateEdit->date();
        // dateEdit->setDate(date);
    } else {
        //  QStyledItemDelegate::setEditorData(editor, index);
        QItemDelegate::setEditorData(editor, index);
    }
}

void CheckBoxDelegate::setModelData( QWidget *editor,QAbstractItemModel *model,const QModelIndex &index ) const
{
    if (list.contains(index.column())) {
        BooleanWidget *checkBox = qobject_cast<BooleanWidget*>( editor );
        Qt::CheckState value;
        if(checkBox->isChecked())
            value = Qt::Checked;
        else
            value = Qt::Unchecked;
        model->setData( index, value, Qt::DisplayRole);
        //QCheckBox CheckBox =index.model()->data(index, Qt::DisplayRole).toBool();
        //QCheckBox *CheckBox = qobject_cast<QCheckBox *>(editor);
        // QDate date = dateEdit->date();
        // model->setData(index, date);
    } else {
        // QStyledItemDelegate::setModelData(editor, model, index);
        QItemDelegate::setModelData(editor, model, index);
    }
}


//void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    drawCheck(painter, option, option.rect, index.data().toBool() ? Qt::Checked : Qt::Unchecked);
//    drawFocus(painter, option, option.rect);
//}



//void BooleanEditor::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    drawCheck(painter, option, option.rect, index.data().toBool() ? Qt::Checked : Qt::Unchecked);
//    drawFocus(painter, option, option.rect);
//}

bool CheckBoxDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option,
                                   const QModelIndex &index)
{
    if (list.contains(index.column())){
        Q_ASSERT(event);
        Q_ASSERT(model);

        // make sure that the item is checkable
        Qt::ItemFlags flags = model->flags(index);
        if (!(flags & Qt::ItemIsUserCheckable) || !(flags & Qt::ItemIsEnabled))
            return false;
        // make sure that we have a check state
        QVariant value = index.data(Qt::CheckStateRole);
        if (!value.isValid())
            return false;
        // make sure that we have the right event type
        if (event->type() == QEvent::MouseButtonRelease) {
            const int textMargin = QApplication::style()->pixelMetric(QStyle::PM_FocusFrameHMargin) + 1;//?
            //           QRect checkRect = QStyle::alignedRect(option.direction, Qt::AlignCenter,
            //                                                 option.decorationSize,
            //                                                 QRect(option.rect.x() + (2 * textMargin), option.rect.y(),
            //                                                       option.rect.width() - (2 * textMargin),
            //                                                       option.rect.height()));

        } else {
            return false;
        }
        Qt::CheckState state = (static_cast<Qt::CheckState>(value.toInt()) == Qt::Checked
                                ? Qt::Unchecked : Qt::Checked);




        //emit(clickSignal(index.row()));
        qDebug()<<"emit(clickSignal(index.row()))";

        return model->setData(index, state, Qt::CheckStateRole);
    }
}


void CheckBoxDelegate::commitAndCloseEditor()
{
    QCheckBox *editor = qobject_cast<QCheckBox *>(sender());
    emit commitData(editor);
    //  emit closeEditor(editor);//?
}


