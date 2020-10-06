#include "Item.h"
#include <QDebug>
#include <QPixmap>
static const char className[] = "Item::";

Item::Item(QObject *parent): QObject(parent) {
    //str_property_ = new ItemPropertyWrapper<ItemEnums::EItemProperty, QString>();
    //model_ = new AbstractTableItemData(this);

   //QPixmap puzzleImage;
  // image_.load("test.jpg");
   if (!user_image_.load("test.jpg")) {
       LOOGGER("NO Default image");
       return;
   }
  // puzzleImage.load("test.jpg");

}

void Item::setFile(QString file_path) {

}

void Item::setFileName(QString file_name) {

}

void Item::setFilePath(const QString &file_name) {
     file_.setFileName(file_name);
     file_info_.setFile(file_name);
}

void Item::setWindowSize(const QSize && window_size) {
    window_size_ = std::move(window_size);
}

void Item::setMaxWindowRow(const int &&max_row) {
    max_row_ = std::move(max_row);
}

void Item::setMaxWindowColumn(const int &&max_column) {
    max_column_ = std::move(max_column);
}

void Item::setupTileTemplateMap() {

    QPixmap pixmap;

    pixmap.load("");
    tile_template_pix_map_.insert(Tile::eTileTemlate::kLeft, pixmap);
    tile_template_size_map_.insert(Tile::eTileTemlate::kLeft, pixmap.size());



}

int Item::getTileIdby() {
    return 0;
}

int Item::getId() {
    return id_;

}

//void Item::setId(int id){
//    id_ = id;
//}

void Item::setId(const int &&id){
    id_ = std::move(id);
}

Item::eItemStatus Item::getStatus() {
    return status_;
}

void Item::setStatus(const Item::eItemStatus &&new_status){
    status_= std::move(new_status);
}


//Item::ItemConteiner Item::getConteinerTupe(const ItemEnums::EItemProperty & property){
//    ItemConteiner cinteiner_tupe = ItemConteiner::string;
//    switch (property) {
//    case ItemEnums::EItemProperty::kNone:
//    case ItemEnums::EItemProperty::kId:
//    case ItemEnums::EItemProperty::kStatus:
//        cinteiner_tupe = ItemConteiner::integer;
//        break;
//    case ItemEnums::EItemProperty::kFilePath:
//    case ItemEnums::EItemProperty::kFileName:
//    case ItemEnums::EItemProperty::kIcon:
//    case ItemEnums::EItemProperty::kDateLastSaved:
//    case ItemEnums::EItemProperty::kFormat:
//        cinteiner_tupe = ItemConteiner::string;
//        break;
//    }
//    return cinteiner_tupe;
//}

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


//QString Item::getProperty(const ItemEnums::EItemProperty property) {
//    ItemConteiner cinteiner_tupe = getConteinerTupe(property);
//    if (cinteiner_tupe == ItemConteiner::string) {
//        if (str_property_.find(property) != str_property_.end())
//            return str_property_.find(property).value();
//    }

//    else if (cinteiner_tupe == ItemConteiner::integer) {
//        if (int_property_.find(property) != int_property_.end()){
//            return QString::number(int_property_.find(property).value());
//        }
//    }
//    return QString("");
//}


//void Item::setupDefault(const QHash<ItemEnums::EItemProperty,QString> &default_map) {
//    if (default_map.isEmpty()) {
//        LOOGGER("NO Default map");
//        return;
//    }
//    for(auto i = default_map.begin();i != default_map.end();++i) {




//    }
//}


void Item::parse() {
    LOOGGER("+");
   // window_size_.setWidth(800);
  //  window_size_.setHeight(800);


    QList <pTile> row;
    QImage template_("puzle.png");
    QPixmap template__("puzle.png");
    QPair<int,int> addres = {0,0};

    for(int i=0;i<10;++i){
        QPair<int,int> addres;
        addres.first = i;
        QPair<int,int> coordinate = {50*i, 50*i};

        Tile *tile = new Tile(coordinate, user_image_, template__);
        pTile ptile = pTile(tile, &QObject::deleteLater);
        row.append(ptile);
    }

    tiles_.append(row);
    tiles_.append(row);
    tiles_.append(row);
    tiles_.append(row);

    // QString status = QString(ItemEnums::eItemStatus::kParseError);
    //QString path = getItemProperty(ItemEnums::EItemProperty::kFilePath);
    //property_->parse();
    //FileData file_data;
    // file_data = property_->getFileModel();
    //    if (file_data.empty()) {
    //        property_->setItemProperty(ItemEnums::EItemProperty::kStatus, QString(ItemEnums::eItemStatus::kParseError));
    //        LOOGGER("::ParseError");
    //        return;
    //    }
    model_.setupModel(tiles_);
}

void Item::cleanModel() {
   // tiles_.clear();
}
AbstractTableItemData *Item::getModel() {
    return &model_;
}

//bool Item::isPropertyExist(const ItemEnums::EItemProperty property){
//    if (str_property_.find(property) != str_property_.end())
//        return true;
//    else if (int_property_.find(property) != int_property_.end())
//        return true;
//    return false;
//}

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


