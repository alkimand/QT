#ifndef MAINCOMBOBOX2_H
#define MAINCOMBOBOX2_H

//https://ru.stackoverflow.com/questions/311142/qdateedit-%D0%B2-qtableview
//ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
//:QItemDelegate(parent)[];
//QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const;
//void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const;
//void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
//void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const;

#include <QDialog>
#include <QList>
#include <QItemDelegate>

//class QDialogButtonBox;
//class QTableWidget;
class QDateEdit;
class QDataWidgetMapper;

//http://nullege.com/codes/search/PyQt4.QtGui.QDateEdit.setDisplayFormat
//https://www.youtube.com/watch?v=u6PeXMNI5iY
//комплетер

//http://rsdn.org/forum/cpp.qt/6187619.all

class VisitsDateDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    VisitsDateDelegate(QList <int> list, QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

private slots:
    void commitAndCloseEditor();

private:
    QList  <int> list;
};
#endif
