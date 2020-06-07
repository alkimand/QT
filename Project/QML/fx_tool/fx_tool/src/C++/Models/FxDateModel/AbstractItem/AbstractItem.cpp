#include "AbstractItem.h"
#include <QDebug>

AbstractItem::AbstractItem(QObject *parent): QObject(parent) {
    // itemData_.insert(int(ItemEnums::EItemProps::kTextValue_1), "test");
    // itemData_.insert(int(ItemEnums::EItemProps::kTextValue_3), 1000);
}

void AbstractItem::setItemProperty(ItemEnums::EItemProps property_type, QVariant value) {
    if (item_data_.contains((int)property_type))
        item_data_[(int)property_type] = QVariant(value);
    else
        item_data_.insert(int(property_type), QVariant(value));
}

void AbstractItem::setDefaultProperty(QHash<int, QVariant> default_property_map) {
    QHashIterator<int, QVariant> i(default_property_map);
    while (i.hasNext()) {
        i.next();
        item_data_.insert(i.key(),i.value());
    }
}


void AbstractItem::changeItemProperty(ItemEnums::EItemProps property_type, QVariant value) {
    if (item_data_.contains((int)property_type))
        item_data_[(int)property_type] = QVariant(value);
}


QVariant AbstractItem::getItemProperty(ItemEnums::EItemProps property_type) {
    if (item_data_.contains((int)property_type))
        return item_data_[(int)property_type];
    return QVariant();
}
