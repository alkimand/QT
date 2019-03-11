#include "ComboboxDelegate.h"
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

ComboboxDelegate::ComboboxDelegate ( QLineEdit *LineEdit,QString TableName, QString TableCulumnName, QSqlRelationalTableModel *Model, QObject *parent)
    : QItemDelegate(parent)
{
    this->Model = Model;
    for (int i = 0;i<this->Model->rowCount();i++){
        QString key = this->Model->data(this->Model->index(i,1),Qt::DisplayRole).toString();
        int value = this->Model->data(this->Model->index(i,0),Qt::DisplayRole).toInt();
        this->map.insert(key,value);
        this->map2 = &map;
        this->TableName = TableName;
        this->TableCulumnName = TableCulumnName;
        this->SityQLineEdit = LineEdit;
       // this->strlist = new QStringList(this);

        //qDebug()<< "key " << str << " value "<< value;
    }
}

void ComboboxDelegate::paint(QPainter *painter,
                             const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    //qDebug()<<"paint";
    QStyleOptionViewItemV4 myOption = option;
    QString text = index.model()->data(index,Qt::DisplayRole).toString();
    myOption.text = text;
    myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    // if (painter->isActive()) qDebug()<<"painter->fillRect(myOption.rect, Qt::red)";
    //else qDebug()<<"no painter->fillRect(myOption.rect, Qt::red)";
    // painter->fillRect(myOption.rect, Qt::white);
    //lightGray white

    // myOption.palette.setColor(QPalette::Highlight, Qt::white) ;
    //myOption.palette.setColor(QPalette::Text, Qt::red);//при не выделении
    //this->drawBackground(painter, myOption, index);
    drawDisplay(painter, myOption, myOption.rect, text);
    drawFocus(painter, myOption, myOption.rect);
    QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}

void ComboboxDelegate::drawBackground(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    //qDebug()<<"drawBackground";
    QString text=index.data().toString();
    if(text=="Red") painter->fillRect(option.rect, Qt::red);
    else if(text=="Black") painter->fillRect(option.rect, Qt::black);
}
//http://www.qtcentre.org/threads/14696-Editable-QComboBox-with-QItemDelegate
//void ComboboxDelegate::drawBackground(QPainter *painter, const QStyleOptionViewItem &option,
//                                      const QModelIndex &index) const {
//     QString text=index.data().toString();
//     if(text=="Red") painter->fillRect(option.rect, Qt::red);
//     else if(text=="Black") painter->fillRect(option.rect, Qt::black);
// }







QWidget *ComboboxDelegate::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    //qDebug()<<"createEditor";
    QComboBox *comboBox = new QComboBox(parent);
    comboBox->setEditable(true);
    comboBox->setInsertPolicy(QComboBox::InsertAtTop);//InsertAtBottom //http://doc.qt.io/qt-5/qcombobox.html#InsertPolicy-enum
    //for (int i=0;i<index.model()->rowCount();i++){ }
    QStringList strlist;
   // this->strlist
    //++--
    for (int i = 0;i<Model->rowCount();i++){
        QModelIndex index2=Model->index(i,1);
        QString str = Model->data(index2,Qt::DisplayRole).toString();
        this->strlist->append(str);
        strlist.append(str);

        //        for (int i = 0;i<=map.size();i++){
        //            QModelIndex index2=Model->index(i,1);
        //            QString str = Model->data(index2,Qt::DisplayRole).toString();
        //            strlist.append(str);

    }

    comboBox->addItems(strlist);
    //connect(comboBox, SIGNAL(activated(int)), this, SLOT(emitCommitData()));
    //connect(comboBox->lineEdit(), SIGNAL(editingFinished()), this, SLOT(emitCommitData()));
    QString currentText = index.model()->data(index, Qt::DisplayRole).toString();
    int selectedItem = comboBox->findText(currentText);
    if(selectedItem == -1){
       //
        //strlist.
        QString item(currentText);
        this->strlist->append(item);
        comboBox->addItem(item);
        comboBox->setCurrentText(item);
        comboBox->setEditText(index.model()->data(index, Qt::DisplayRole).toString());
        //emit AddNewList();
    }
    else
        comboBox->setCurrentIndex(selectedItem);
    //Палитра оставить?
    //    QPalette comboboxPalette = comboBox->palette();
    //    comboboxPalette.setColor(QPalette::Text, Qt::red);
    //  comboboxPalette.setColor(QPalette::Highlight, Qt::red) ;
    //    comboboxPalette.setColor(QPalette::WindowText, Qt::red);
    //      comboboxPalette.setColor(QPalette::Base, Qt::red) ;
    //    comboboxPalette.setColor(QPalette::Highlight, Qt::red) ;
    //QPainter painter;
    //painter.fillRect(option.rect, Qt::red);

    //    comboBox->setPalette(comboboxPalette);

    return comboBox;
}

void ComboboxDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    //qDebug()<<"setEditorData";
    //QString value = index.model()->data(index, Qt::EditRole).toString();
    //QComboBox *comboBox = static_cast<QComboBox*>(editor);

    //QPainter *painter=comboBox->pai
}

void ComboboxDelegate::setModelData(QWidget *editor,
                                    QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    //qDebug()<<"setModelData";
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString str1=comboBox->currentText();
    //qDebug() << "comboBox->currentText()"<< comboBox->currentText();
    QMap<QString, int>::const_iterator i = this->map.find(comboBox->currentText());
   // qDebug() << i.key();
    if (i.key()!="")
    {
        model->setData(index, i.value(), Qt ::EditRole);
        this->SityQLineEdit->setText(str1);
        emit this->SityQLineEdit->editingFinished();
    }
    else
    {
        int id;
        QSqlQueryModel model;
        QSqlQuery query;
        query.next();
        QString str = ("INSERT INTO " + this->TableName + "(" + this->TableCulumnName + ") VALUES ("
                                                                                        "'" + comboBox->currentText() + "')");
        //qDebug()<< str;
        query.prepare(str);
        query.exec();
        query.next();
        str = QString("SELECT id FROM " + this->TableName + " WHERE "  + this->TableCulumnName + " = '%1'  ") .arg(comboBox->currentText());
        //Server << str;
        if(query.value(0) != 0){
            //qDebug()<< "query.value(0) != 0 - TRUE";
            model.setQuery(str);
            str = comboBox->currentText();
            id = model.record(0).value("id").toInt();
            //qDebug()<< id ;
            this->map2->insert(str , id);
            // this->map.insert( "comboBox->currentText()).toStdString()" , 12 );
            this->SityQLineEdit->setText(str);
            //qDebug()<< "this->SityQLineEdit" << this->SityQLineEdit->text();
            //comboBox->addItem(comboBox->currentText());
            // emit comboBox->repaint();
            emit this->SityQLineEdit->editingFinished();
            // QString key = comboBox->currentText();
            //  int value = id;
            // map2->insert(key, value);
        }
        else {//qDebug()<<"query.value(0) != 0 - FALSE";}
}
        }
    }

    //void ComboboxDelegate::commitAndCloseEditor()
    //{
    //    QDateEdit *editor = qobject_cast<QDateEdit *>(sender());
    //    emit commitData(editor);
    //    //  emit closeEditor(editor);//?
    //}

    //void ComboboxDelegate::emitCommitData()
    //{
    //    emit commitData(qobject_cast<QWidget *>(sender()));
    //}

    void ComboboxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
    {
        editor->setGeometry(option.rect);
    }
