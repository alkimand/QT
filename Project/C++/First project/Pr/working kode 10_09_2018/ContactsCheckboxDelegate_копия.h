#ifndef CHECKBOXDELEGAT2_H
#define CHECKBOXDELEGAT2_H
#include <QDialog>
#include <QList>
#include <QItemDelegate>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QItemDelegate>
//http://www.cyberforum.ru/qt/thread1577711.html
#include <QStyleOptionViewItemV4>
#include <QStyledItemDelegate>


class BooleanWidget : public QWidget
{
    Q_OBJECT
    QCheckBox * checkBox;

    public:
    BooleanWidget(QWidget * parent = 0)
    {
        checkBox = new QCheckBox(this);
        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->addWidget(checkBox,0, Qt::AlignRight);//Qt::AlignCenter
        setMinimumSize(5,5);
    }
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index);
    bool isChecked(){return checkBox->isChecked();}
    void setChecked(bool value){checkBox->setChecked(value);}

};



class CheckBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
private:
    BooleanWidget *checkbox;
    QList  <int> list;

public:
    virtual bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option,
                                const QModelIndex &index);
    CheckBoxDelegate(QList <int> list,QObject *parent);
    ~CheckBoxDelegate();
    void setEditorData( QWidget *editor,const QModelIndex &index )const;
    void setModelData( QWidget *editor,QAbstractItemModel *model,const QModelIndex &index )const;
    QWidget *createEditor( QWidget *parent,const QStyleOptionViewItem & option ,const QModelIndex & index  )const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
public slots:
    void changed( bool );


};
#endif
