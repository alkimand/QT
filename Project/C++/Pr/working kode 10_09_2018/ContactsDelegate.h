#ifndef MAINCOMBOBOX3_H
#define MAINCOMBOBOX3_H
#include <QDialog>
#include <QList>
#include <QItemDelegate>
#include <QHBoxLayout>
class QDateEdit;
class QDataWidgetMapper;
class QCheckBox;

class ContactsDateDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    ContactsDateDelegate(QList <int> list, QObject *parent = 0);

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
