#include <QDebug>
#include <QTextCodec>

#include "iAbstractItemBase.h"

static const char className[] = "iAbstractItemBase::";

iAbstractItemBase::iAbstractItemBase(QObject *parent): QObject(parent){
}

void
iAbstractItemBase::setItemProperty(ItemEnums::EItemProperty property_type, Props value) {
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
}


const Props &iAbstractItemBase::getItemProperty(const ItemEnums::EItemProperty &property_type) {
    return  (item_data_[property_type]);
}


bool iAbstractItemBase::isPropertyExist(const ItemEnums::EItemProperty propertyType){
    bool exist_property = false;
    ItemPropertyMap::const_iterator finder = item_data_.find(propertyType);
    if (finder != item_data_.end())
        exist_property = true;
    return exist_property;
}
