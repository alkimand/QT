#include "ItemModel.h"
#include <QDebug>

//ItemModel::ItemModel(QObject *parent):AbstractItem(parent), ItemModelBase(parent)
ItemModel::ItemModel(): ItemModelBase(){

}

//AbstractItemModel::AbstractItemModel(QObject *parent): QObject(parent) {
//    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_1), "test");
//    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_3), 1000);
//}

//void AbstractItem::setItemProperty(ItemEnums::EItemProperty property_type, QVariant value) {
//    if (item_data_.contains((int)property_type))
//        item_data_[(int)property_type] = QVariant(value);
//    else
//        item_data_.insert(int(property_type), QVariant(value));
//}

//void AbstractItemModel::setDefaultProperty(QHash<ItemEnums::EItemProperty , QVariant> default_property_map) {
////    QHashIterator<int, QVariant> i(default_property_map);
////    while (i.hasNext()) {
////        i.next();
////        item_data_.insert(i.key(),i.value());
////    }
//}

void ItemModel::setupDefault() {

//   if (default_map_.size()>0){


//    }
//    QHashIterator<int, QVariant> i(default_property_map);
//    while (i.hasNext()) {
//        i.next();
//        item_data_.insert(i.key(),i.value());
//    }
}


//void AbstractItem::changeItemProperty(ItemEnums::EItemProperty property_type, QVariant value) {
//    if (item_data_.contains((int)property_type))
//        item_data_[(int)property_type] = QVariant(value);
//}


//QVariant AbstractItem::getItemProperty(ItemEnums::EItemProperty property_type) {
//    if (item_data_.contains((int)property_type))
//        return item_data_[(int)property_type];
//    return QVariant();
//}


