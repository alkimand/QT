#ifndef ROWITEM_H
#define ROWITEM_H
#include "ItemPropery.h"
#include <QObject>
#include <QHash>

typedef QHash<ItemEnums::EItemProperty, QVariant> ItemPropertyMap;

class AbstractItem: public QObject {
    Q_OBJECT

public:
    AbstractItem(QObject *parent = nullptr);
    void setItemProperty( ItemEnums::EItemProperty propertyType, QVariant value);
    void setDefaultPropertyMap(ItemPropertyMap default_property_map);
    void changeItemProperty(ItemEnums::EItemProperty propertyType, QVariant value);
    QVariant getItemProperty(ItemEnums::EItemProperty propertyType);


protected:

        ItemPropertyMap item_data_;

private:



public slots:

};

#endif // BORDERRADIUSWIDGET_H
