#include "QlineEditDelegate.h"
#include <QComboBox>
#include <QWidget>
#include <QtWidgets>
#include <QCheckBox>
#include <QComboBox>
#include <QSqlTableModel>
//#include <QMap>
#include <QtSql>
//http://programmingexamples.net/wiki/Qt/Delegates/ComboBoxDelegate
#include <QPalette>
#include <QLineEdit>
#include <QItemDelegate>
//#include <QDebug>
#include <QStyleOptionViewItemV4>
#include <QStyledItemDelegate>
#include <QSqlRelationalTableModel>

LineEditDelegate::LineEditDelegate ( QLineEdit *LineEdit,QString TableName, QString TableCulumnName, QSqlRelationalTableModel *Model, QObject *parent)
    : QItemDelegate(parent)
{
    this->Model=Model;
    for (int i = 0;i<this->Model->rowCount();i++){
        // QModelIndex index2=this->Model->index(i,1);
        //QString str = this->Model->data(index2,Qt::DisplayRole).toString();
        QString key = this->Model->data(this->Model->index(i,1),Qt::DisplayRole).toString();
        int value = this->Model->data(this->Model->index(i,0),Qt::DisplayRole).toInt();
        this->map.insert(key,value);
        this->TableName = TableName;
        this->TableCulumnName =TableCulumnName;
        this->LineEdit = LineEdit;
        this->map2 = &map;
        //this->map=&map2;
        //qDebug()<< "key " << str << " value "<< value;
    }
}

void LineEditDelegate::paint(QPainter *painter,
                             const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    QStyleOptionViewItemV4 myOption = option;
    QString text = index.model()->data(index,Qt::DisplayRole).toString();
    myOption.text = text;
    myOption.displayAlignment = Qt::AlignLeft | Qt::AlignVCenter;
    // if (painter->isActive()) qDebug()<<"painter->fillRect(myOption.rect, Qt::red)";
    //else qDebug()<<"no painter->fillRect(myOption.rect, Qt::red)";
    //painter->fillRect(myOption.rect, Qt::white);
    //lightGray white

    //myOption.palette.setColor(QPalette::Highlight, Qt::white) ;
    //myOption.palette.setColor(QPalette::Text, Qt::red);//при не выделении
    //this->drawBackground(painter, myOption, index);
    drawDisplay(painter, myOption, myOption.rect, text);
    drawFocus(painter, myOption, myOption.rect);
    QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}

QWidget *LineEditDelegate::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    //qDebug()<<"createEditor ";
    QLineEdit *DelegatLineEdit = new QLineEdit(parent);
    QString currentText = index.model()->data(index, Qt::DisplayRole).toString();
    // qDebug()<<currentText ;
    DelegatLineEdit->setText(currentText);
    return DelegatLineEdit;
}

void LineEditDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();
    QLineEdit *DelegatLineEdit = static_cast<QLineEdit*>(editor);
    //QPainter *painter=comboBox->pai
}

void LineEditDelegate::setModelData(QWidget *editor,
                                    QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    //qDebug()<<"setModelData= ";

    QLineEdit *DelegatLineEdit = static_cast<QLineEdit*>(editor);
    QMap<QString, int>::const_iterator i = map.find(DelegatLineEdit->text());
    //qDebug() << DelegatLineEdit->text();
    // qDebug() << i.key();
    if (i.key()!="")
    {
        model->setData(index, i.value(), Qt ::EditRole);
        this->LineEdit->setText(DelegatLineEdit->text());
        emit LineEdit->editingFinished();
    }
    else
    {
        QSqlQueryModel model;
        QSqlQuery query;
        //QString NameCulmn;
        query.exec("INSERT INTO " + TableName + "(" + TableCulumnName+ ") VALUES ("
                                                                       "'" + DelegatLineEdit->text() + "')");
        QString str = QString("SELECT id FROM " +TableName + " WHERE " + TableCulumnName + " = '%1'  ") .arg(DelegatLineEdit->text());
        model.setQuery(str);
        if(query.value(0) != 0){
            int  id = model.record(0).value("id").toInt();
           // qDebug()<<"id= "<<id;
            this->LineEdit->setText(DelegatLineEdit->text());
            emit LineEdit->editingFinished();
            //QString key = DelegatLineEdit->text();
            QString key = DelegatLineEdit->text();
            int value = id;
            map2->insert(key, value);
        }
    }
}

void LineEditDelegate::commitAndCloseEditor()
{
    QLineEdit *editor = qobject_cast<QLineEdit *>(sender());
    emit commitData(editor);
    //  emit closeEditor(editor);//?
}

void LineEditDelegate::emitCommitData()
{
    emit commitData(qobject_cast<QWidget *>(sender()));
}

void LineEditDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
