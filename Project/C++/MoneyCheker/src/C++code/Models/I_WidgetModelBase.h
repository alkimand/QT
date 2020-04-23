#ifndef I_WidgetModelBase_H
#define I_WidgetModelBase_H
#include <QObject>
#include <QVector>
#include <QAbstractTableModel>
#include "RowItem.h"
#include "props.h"
#include <QSharedPointer>


class I_WidgetModelBase : public QAbstractTableModel
{

    Q_OBJECT
public:
    //explicit
    explicit I_WidgetModelBase(ItemEnums::e_ModelType widgetType);
    void setupWidgetModel();



    int rowCount(const QModelIndex &parent = QModelIndex()) const {
        Q_UNUSED(parent); return rows.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const {
        Q_UNUSED(parent); return 1;
    }

    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    //RowItem IdemData(const QModelIndex &index, int role = Qt::DisplayRole) const;



    QVector <QSharedPointer<AbstractItem>>  rows;

    virtual ~I_WidgetModelBase();
protected:
    ItemEnums::e_ModelType widgetType_;





};

#endif // I_WidgetModelBase_H
