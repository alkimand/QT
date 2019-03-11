#include "ContactsDelegate.h"
#include <QComboBox>
#include <QWidget>
#include <QtWidgets>
#include <QCheckBox>
#include <qcheckbox.h>
#include "ContactsCheckboxDelegate.h"
#include <QItemDelegate>
#include <QDebug>
#include <QStyleOptionViewItemV4>
#include <QStyledItemDelegate>
void BooleanWidget::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    //drawCheck(painter, option, option.rect, index.data().toBool() ? Qt::Checked : Qt::Unchecked);
    //drawFocus(painter, option, option.rect);
}



void CheckBoxDelegate::changed( bool value )
{
    BooleanWidget *checkbox = static_cast<BooleanWidget*>( sender() );
    emit commitData( checkbox );
    emit closeEditor( checkbox );
}

void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{if (list.contains(index.column())){
        QStyleOptionViewItemV4 viewItemOption(option);

        if (list.contains(index.column())) {
            const int textMargin = QApplication::style()->pixelMetric(QStyle::PM_FocusFrameHMargin) + 1;
            QRect newRect = QStyle::alignedRect(option.direction, Qt::AlignCenter,
                                                QSize(option.decorationSize.width() + 5,option.decorationSize.height()),
                                                QRect(option.rect.x() + textMargin, option.rect.y(),
                                                      option.rect.width() - (2 * textMargin), option.rect.height()));
            viewItemOption.rect = newRect;
          QStyledItemDelegate::paint(painter, viewItemOption, index);
        }

           drawCheck(painter, option, option.rect, index.data().toBool() ? Qt::Checked : Qt::Unchecked);
            drawFocus(painter, option, option.rect);

    }

}

void CheckBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
     editor->setGeometry(option.rect);
}


QWidget *CheckBoxDelegate::createEditor( QWidget *parent,const QStyleOptionViewItem & option ,const QModelIndex & index ) const
{
   if (list.contains(index.column())){
    BooleanWidget *editor = new BooleanWidget( parent );
  // QCheckBox *editor = new QCheckBox(parent);
   // editor->setTristate( true);
    editor->setStyleSheet("QCheckBox {margin-left: 43%; margin-right: 57%;}");
    //connect( editor, SIGNAL( toggled ( bool ) ), this, SLOT( changed( bool ) ) );

    return editor;
   }
   else {
           return QStyledItemDelegate::createEditor(parent, option, index);
}
}

CheckBoxDelegate::CheckBoxDelegate(QList <int> list,QObject *parent=0)
{
    this->list = list;
}

CheckBoxDelegate::~CheckBoxDelegate()
{

}

void CheckBoxDelegate::setEditorData( QWidget *editor,const QModelIndex &index ) const
{
   if (list.contains(index.column())){
    bool value = index.model()->data(index, Qt::EditRole).toBool();

    BooleanWidget *checkbox = static_cast<BooleanWidget*>(editor);

    if(value)
    {
        checkbox->setChecked(true);
    }
    else
    {
        checkbox->setChecked(false);
    }
}
   else {
           QStyledItemDelegate::setEditorData(editor, index);
       }

}

void CheckBoxDelegate::setModelData( QWidget *editor,QAbstractItemModel *model,const QModelIndex &index ) const
{
      if (list.contains(index.column())){
    BooleanWidget *checkBox = qobject_cast<BooleanWidget*>( editor );
    Qt::CheckState value;

    if(checkBox->isChecked())
        value = Qt::Checked;
    else
        value = Qt::Unchecked;

    model->setData( index, value, Qt::DisplayRole);
  }

      else {
              QStyledItemDelegate::setModelData(editor, model, index);
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
           const int textMargin = QApplication::style()->pixelMetric(QStyle::PM_FocusFrameHMargin) + 1;
           QRect checkRect = QStyle::alignedRect(option.direction, Qt::AlignCenter,
                                                 option.decorationSize,
                                                 QRect(option.rect.x() + (2 * textMargin), option.rect.y(),
                                                       option.rect.width() - (2 * textMargin),
                                                       option.rect.height()));

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


