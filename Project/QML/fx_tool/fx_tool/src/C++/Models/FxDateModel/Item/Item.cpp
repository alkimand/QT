#include "Item.h"
#include <QDebug>

static const char className[] = "Item::";

Item::Item(QObject *parent): QObject(parent) {
    property_ = new VariedItem(this);
    model_ = new ItemModelBase(this);
}

void Item::setFile(const QString &path) {
    property_->setFile(Props(path));
}

void Item::setProperty(const ItemEnums::EItemProperty property,const Props value) {
        if (property!=ItemEnums::EItemProperty::kNone)
            property_->setItemProperty(property, Props(value));
}

const Props  Item::getProperty(const ItemEnums::EItemProperty property) {
        if (property!=ItemEnums::EItemProperty::kNone)
             return property_->getItemProperty(property);
        return Props("");
}

//Props Item::getProperty(const ItemEnums::EItemProperty property){
//    if (property!=ItemEnums::EItemProperty::kNone)
//        property_->getItemProperty(property, Props(property));
//}


void Item::setPath(const Props &path) {
    if (!path.isEmpty())
        property_->setItemProperty(ItemEnums::EItemProperty::kFilePath, Props(path));
    //qDebug()<< "Item::setPath - " + path;
}

void Item::setFileName(const Props &path) {
    if (!path.isEmpty())
        property_->setItemProperty(ItemEnums::EItemProperty::kFileName, Props(path));
    //qDebug()<< "setFileName - "+path;
}

void Item::setupDefault(const ItemPropertyMap &default_map){
    if (default_map.isEmpty()){
        LOOGGER("NO Default map");
        return;
    }
        property_->setDefaultPropertyMap(default_map);
}

void Item::parse() {
    LOOGGER("+");
   // Props path = getProperty(ItemEnums::EItemProperty::kFilePath);


    property_->parse();
    FileData file_data;
    file_data = property_->getFileModel();
    if (!file_data.size() > 0){
        property_->setItemProperty(ItemEnums::EItemProperty::kStatus, Props(ItemEnums::eItemStatus::kParseError));
        return;
    }
    model_->createModel(file_data);
}

void Item::cleanModel() {
    model_->cleanModelData();
}

ItemModelBase *Item::getModel() {
    return model_;
}

bool Item::isPropertyExist(const ItemEnums::EItemProperty propertyType){
    return property_->isPropertyExist(propertyType);
}

Item::~Item() {
    //qDebug()<<"~Item";
    delete property_;
    delete model_;
   // fs::FxConfig cfg_;
}



//QVariant AbstractItem::getItemProperty(ItemEnums::EItemProperty property_type) {
//    if (item_data_.contains((int)property_type))
//        return item_data_[(int)property_type];
//    return QVariant();
//}


