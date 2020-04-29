#ifndef I_WidgetModelBase_H
#define I_WidgetModelBase_H
#include <QObject>
#include <QVector>
#include <QAbstractTableModel>
#include "RowItem.h"
#include "props.h"
#include <QSharedPointer>


class IWidgetModelBase : public QAbstractTableModel
{

    Q_OBJECT
public:
    //explicit
    explicit IWidgetModelBase(ItemEnums::EModelType widgetType);
    void setupWidgetModel();
    void virtual  setupDefaultPropertyMap();



    int rowCount(const QModelIndex &parent = QModelIndex()) const {
        Q_UNUSED(parent); return rows_.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const {
        Q_UNUSED(parent); return 1;
    }

    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    //RowItem IdemData(const QModelIndex &index, int role = Qt::DisplayRole) const;



    QVector <QSharedPointer<AbstractItem>>  rows_;

    virtual ~IWidgetModelBase();
protected:
    ItemEnums::EModelType widgetType_;
    IWidgetModelBase *childModel_ = nullptr;
    IWidgetModelBase *parentModel_ = nullptr;

    QHash<int, QVariant> default_property_map_;

};

#endif // I_WidgetModelBase_H
