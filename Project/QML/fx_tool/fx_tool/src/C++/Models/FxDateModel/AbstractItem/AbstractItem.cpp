#include "AbstractItem.h"
#include <QDebug>

//AbstractItem::AbstractItem(QObject *parent): QObject(parent) {
//AbstractItem::AbstractItem() {
//    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_1), "test");
//    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_3), 1000);
//}

void AbstractItem::setItemProperty(ItemEnums::EItemProperty property_type, QVariant value) {
    if (item_data_.contains(property_type))
        item_data_[property_type] = QVariant(value);
    else
        item_data_.insert(property_type, QVariant(value));
}

void AbstractItem::setDefaultPropertyMap(ItemPropertyMap default_property_map) {
    QHashIterator<ItemEnums::EItemProperty, QVariant> i(default_property_map);
    while (i.hasNext()) {
        i.next();
        item_data_.insert(i.key(),i.value());
    }
}

void AbstractItem::changeItemProperty(ItemEnums::EItemProperty property_type, QVariant value) {
    if (item_data_.contains(property_type))
        item_data_[property_type] = QVariant(value);
}


QVariant AbstractItem::getItemProperty(ItemEnums::EItemProperty property_type) {
    if (item_data_.contains(property_type))
        return item_data_[property_type];
    return QVariant();
}
