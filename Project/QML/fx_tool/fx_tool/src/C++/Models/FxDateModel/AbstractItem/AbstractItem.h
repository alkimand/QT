#ifndef ROWITEM_H
#define ROWITEM_H
#include "ItemPropery.h"
#include <QObject>
#include <QHash>

class AbstractItem: public QObject
{
    Q_OBJECT

public:
    AbstractItem(QObject *parent = nullptr);
    void setItemProperty( ItemEnums::EItemProps propertyType, QVariant value);
    void setDefaultProperty(QHash<int, QVariant> default_property_map);
    void changeItemProperty(ItemEnums::EItemProps propertyType, QVariant value);
    QVariant getItemProperty(ItemEnums::EItemProps propertyType);

private:

    QHash<int, QVariant> item_data_;

public slots:

};

#endif // BORDERRADIUSWIDGET_H
