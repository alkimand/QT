#ifndef I_WidgetModelBase_H
#define I_WidgetModelBase_H
#include <QObject>
#include <QVector>
#include <QAbstractTableModel>
#include "ItemPropery.h"
#include <QSharedPointer>

#define GET_ITEM_PROPERTY data_.at(index.row()).at(index.column())

class IEssenceModelBase : public QAbstractTableModel
{

    Q_OBJECT
public:
    //explicit
    explicit IEssenceModelBase(ItemEnums::EModelType widgetType);
    void setupWidgetModel();
    void virtual  setupDefaultPropertyMap();



    int rowCount(const QModelIndex &parent = QModelIndex()) const {
        Q_UNUSED(parent); return data_.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const {
        Q_UNUSED(parent); return 1;
    }

    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    //RowItem IdemData(const QModelIndex &index, int role = Qt::DisplayRole) const;



    QVector <QVector<QString>>  data_;

    virtual ~IEssenceModelBase();
protected:
    ItemEnums::EModelType widgetType_;
    IEssenceModelBase *childModel_ = nullptr;
    IEssenceModelBase *parentModel_ = nullptr;

    QHash<int, QVariant> default_property_map_;

};

#endif // I_WidgetModelBase_H
