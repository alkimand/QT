#include "Item.h"
#include <QDebug>

static const char className[] = "Item::";

Item::Item(QObject *parent): QObject(parent) {
    //str_property_ = new ItemPropertyWrapper<ItemEnums::EItemProperty, QString>();
    //model_ = new AbstractTableItemData(this);
}

Item::ItemConteiner Item::getConteinerTupe(const ItemEnums::EItemProperty & property){
        ItemConteiner cinteiner_tupe = ItemConteiner::string;
        switch (property) {
        case ItemEnums::EItemProperty::kNone:
        case ItemEnums::EItemProperty::kId:
        case ItemEnums::EItemProperty::kStatus:
            cinteiner_tupe = ItemConteiner::integer;
            break;
        case ItemEnums::EItemProperty::kFilePath:
        case ItemEnums::EItemProperty::kFileName:
        case ItemEnums::EItemProperty::kIcon:
        case ItemEnums::EItemProperty::kDateLastSaved:
        case ItemEnums::EItemProperty::kFormat:
            cinteiner_tupe = ItemConteiner::string;
            break;
    }
    return cinteiner_tupe;
}

//void Item::setFile(const QString &path) {
//    property_->setFile(QString(path));
//}

//void Item::setProperty(const ItemEnums::EItemProperty property, const QString value) {
//    if (property!=ItemEnums::EItemProperty::kNone)
//        switch (property) {
//        case ItemEnums::EItemProperty::kFilePath:
//        case ItemEnums::EItemProperty::kFileName:
//        case ItemEnums::EItemProperty::kIcon:
//        case ItemEnums::EItemProperty::kDateLastSaved:
//        case ItemEnums::EItemProperty::kFormat:
//        str_property_.insert(property, value);
//            break;
//        }
//    // property_->insert(property, QString(value));
//}

//void Item::setProperty(const ItemEnums::EItemProperty property, const int value) {
//    if (property!=ItemEnums::EItemProperty::kNone)
//        switch (property) {
//        case ItemEnums::EItemProperty::kNone:
//        case ItemEnums::EItemProperty::kId:
//        case ItemEnums::EItemProperty::kStatus:
//            int_property_.insert(property, value);
//            break;
//        }
//}


QString Item::getProperty(const ItemEnums::EItemProperty property){
    //if (property != ItemEnums::EItemProperty::kNone)
    if (str_property_.find(property) != str_property_.end()){
        return str_property_.find(property).value();
    }
    else if (int_property_.find(property) != int_property_.end()){
        return QString::number(int_property_.find(property).value());
    }
    return QString("");
}





void Item::setupDefault(const QHash<ItemEnums::EItemProperty,QString> &default_map){
    if (default_map.isEmpty()){
        LOOGGER("NO Default map");
        return;
    }
    for(auto i = default_map.begin();i != default_map.end();++i){
        switch (i.key()) {
        case ItemEnums::EItemProperty::kNone:
        case ItemEnums::EItemProperty::kId:
        case ItemEnums::EItemProperty::kStatus:
            int_property_.insert(i.key(),(i.value().toInt()));
            break;
        case ItemEnums::EItemProperty::kFilePath:
        case ItemEnums::EItemProperty::kFileName:
        case ItemEnums::EItemProperty::kIcon:
        case ItemEnums::EItemProperty::kDateLastSaved:
        case ItemEnums::EItemProperty::kFormat:
            str_property_.insert(i.key(),i.value());
            break;
        }
    }
}
//    property_->setDefaultPropertyMap(default_map);
//}

void Item::parse() {
    //LOOGGER("+");
    //property_->parse();
    FileData file_data;
    //    file_data = property_->getFileModel();
    //    if (file_data.empty()) {
    //        property_->setItemProperty(ItemEnums::EItemProperty::kStatus, QString(ItemEnums::eItemStatus::kParseError));
    //        LOOGGER("::ParseError");
    //        return;
    //    }
    model_.createModel(file_data);
}

//void Item::cleanModel() {
//    model_->cleanModelData();

//AbstractTableItemData *Item::getModel() {
//    return model_;
//}

bool Item::isPropertyExist(const ItemEnums::EItemProperty property){
    if (str_property_.find(property) != str_property_.end())
        return true;
    else if (int_property_.find(property) != int_property_.end())
        return true;
    return false;
}

//void Item::saveFile(const QString file_path){
//    FileData c_map;
//    //QVector <Date_Map> * q_map = model_->getData();
//    property_->setItemProperty(ItemEnums::EItemProperty::kFilePath, file_path);

//    //Qstring file
//    QString line_1;
//    QString line_2;
//    for (auto iterator: *q_map ){
//        QHash<DATA_ID, QVariant> date_ = iterator;
//        if (iterator.size() > 2){
//            line_1 = (iterator.value(FEATURE)).toString();
//            if (!line_1.isEmpty() && line_1 != ""){
//                line_1 += ".";
//                line_1 = line_1 + (iterator.value(FEATURE_NAME)).toString();
//                line_2 = (iterator.value(IS_ACTIVE)).toString();
//            }
//            else
//                line_2 = "";
//        }
//        else {
//            line_1 = (iterator.value(FEATURE)).toString();
//            line_2 = (iterator.value(FEATURE_NAME)).toString();
//        }
//        // std::string sline_1 = line_1.toStdString();
//        if (!line_1.isEmpty() && !line_2.isEmpty())
//            c_map.insert_or_assign(line_1.toStdString(),line_2.toStdString());
//        // c_map.insert(sline_1, sline_1);
//    }
//    property_->save(file_path, c_map);
//}

//void Item::deleteFile(){
//    property_->deleteFile();
//}


//Item::~Item() {
//    //qDebug()<<"~Item";
//    //    if (int_property_)
//    //        delete int_property_;
//    //    if (model_)
//    //        delete model_;
//    // fs::FxConfig cfg_;
//}





//QVariant AbstractItem::getItemProperty(ItemEnums::EItemProperty property_type) {
//    if (item_data_.contains((int)property_type))
//        return item_data_[(int)property_type];
//    return QVariant();
//}


