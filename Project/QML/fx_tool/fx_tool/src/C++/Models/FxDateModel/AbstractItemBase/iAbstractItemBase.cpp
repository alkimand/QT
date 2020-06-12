#include "iAbstractItemBase.h"
#include <QDebug>
#include <QTextCodec>


static const char className[] = "iAbstractItemBase::";

iAbstractItemBase::iAbstractItemBase(QObject *parent): QObject(parent){
    //AbstractItem::AbstractItem() {
    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_1), "test");
    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_3), 1000);
}

void iAbstractItemBase::setItemProperty(ItemEnums::EItemProperty property_type, Props value) {
    if (item_data_.contains(property_type))
        item_data_[property_type] = Props(value);
    else
        item_data_.insert(property_type, Props(value));
}

void iAbstractItemBase::setDefaultPropertyMap(const ItemPropertyMap &default_map) {
    if (default_map.size()==0)
        return;
    QHashIterator<ItemEnums::EItemProperty, Props> i(default_map);
    while (i.hasNext()) {
        i.next();
        item_data_.insert(i.key(),i.value());
    }
    //qDebug()<< "iAbstractItemBase::setDefaultPropertyMap - ";
}

void iAbstractItemBase::changeItemProperty(ItemEnums::EItemProperty property_type, Props value) {
    if (item_data_.contains(property_type))
        item_data_[property_type] = Props(value);
}


const Props &iAbstractItemBase::getItemProperty(const ItemEnums::EItemProperty &property_type) {
    if (item_data_.contains(property_type))
        return  (item_data_[property_type]);
    return nullptr;
}
