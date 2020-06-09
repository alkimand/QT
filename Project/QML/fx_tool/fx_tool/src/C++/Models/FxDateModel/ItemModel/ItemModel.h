#ifndef ABSTRACT_ITEM_MODEL_H
#define ABSTRACT_ITEM_MODEL_H
#include "AbstractItem.h"
#include "ItemModelBase.h"
#include <QObject>
#include <QHash>

class ItemModel: public ItemModelBase {
    Q_OBJECT

public:
    //ItemModel(QObject *parent = nullptr);
    ItemModel();
//    AbstractItem(QObject *parent = nullptr);
 //   void setItemProperty( ItemEnums::EItemProperty propertyType, QVariant value);
 //   void setDefaultProperty(QHash<int, QVariant> default_property_map);
//    void changeItemProperty(ItemEnums::EItemProperty propertyType, QVariant value);
//    QVariant getItemProperty(ItemEnums::EItemProperty propertyType);

private:
    void setupDefault();
    //QHash<int, QVariant> item_data_;

//public slots:

    //QHash<int, QVariant> item_data_;
    //QVector <Date_Map> worksheet_data_;
};

#endif // ABSTRACT_ITEM_MODEL_H
