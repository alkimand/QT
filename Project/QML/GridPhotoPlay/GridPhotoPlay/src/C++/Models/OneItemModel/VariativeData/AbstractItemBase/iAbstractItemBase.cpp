#include "iAbstractItemBase.h"
#include <QDebug>
//#include <QTextCodec>


static const char className[] = "iAbstractItemBase::";

iAbstractItemBase::iAbstractItemBase(QObject *parent): QObject(parent){
    //AbstractItem::AbstractItem() {
    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_1), "test");
    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_3), 1000);
}

void iAbstractItemBase::setItemProperty(ItemEnums::EItemProperty property_type, QString value) {
    if (item_data_.contains(property_type))
        item_data_[property_type] = value;
    else
        item_data_.insert(property_type, QString(value));
}

void iAbstractItemBase::setDefaultPropertyMap(const ItemPropertyMap &default_map) {
    if (default_map.isEmpty())
        return;
    //QHashIterator<ItemEnums::EItemProperty, QString> i(default_map);
//    for (auto &elem : default_map){
//        //elem
//        item_data_.insert(elem,default_map[elem]);
//    }
//    while (i.hasNext()) {
//        i.next();
//        item_data_.insert(i.key(),i.value());
//    }
    //qDebug()<< "iAbstractItemBase::setDefaultPropertyMap - ";
}


const QString &iAbstractItemBase::getItemProperty(const ItemEnums::EItemProperty &property_type) {
        return  (item_data_[property_type]);
}

bool iAbstractItemBase::isPropertyExist(const ItemEnums::EItemProperty propertyType){
    bool exist_property = false;
    ItemPropertyMap::const_iterator finder = item_data_.find(propertyType);
    if (finder != item_data_.end())
        exist_property = true;
    return exist_property;
}
