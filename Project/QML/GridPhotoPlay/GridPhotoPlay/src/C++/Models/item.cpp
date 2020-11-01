#include <item.h>
#include <QDebug>
#include <QDir>
static const char className[] = "Item::";


Item::Item(QString path, int id, int rows, int columns, bool is_rotated, QObject *parent): QObject(parent), id_(std::move(id)),max_row_(rows), max_column_(columns), is_rotated_(is_rotated)  {
    QFileInfo file(std::move(path));

    bool is_file_exist = false;
    if (file.exists() && file.isFile())
        is_file_exist = true;
     else
       is_file_exist = false;
     if (is_file_exist)
         user_pixmap_.load(path);
     else
         qDebug()<< ("NO Default image on path " +path);
}

//void Item::setFile(QString file_path) {

//}

//void Item::setFileName(QString file_name) {

//}

//void Item::setFilePath(QString &file_name) {
//    file_.setFileName(file_name);
//    file_info_.setFile(file_name);
//}

void Item::setWindowSize(QSize window_size) {
    window_size_ = window_size;
}

void Item::setMaxWindowRow( int max_row) {
    max_row_ = max_row;
}

void Item::setMaxWindowColumn( int max_column) {
    max_column_ = max_column;
}

int Item::getTileIdby() {
    return 0;
}

int Item::getId() {
    return id_;

}

//void Onegamecontroller::setId(int id){
//    id_ = id;
//}

void Item::setId( int id){
    id_ = id;
}

eItemStatus Item::getStatus() {
    return status_;
}

void Item::setStatus(eItemStatus new_status){
    status_= new_status;
}

void Item::createTiles() {
    const QColor maskColor(122, 163, 39);

    const int item_height = user_pixmap_.size().height() / max_row_;
    const int item_width = user_pixmap_.size().width() / max_column_;

    auto paths = paths_[eType::kBody];
    auto border_path = paths_[eType::kBorder];

    tiles_matrix_.resize(max_row_);
    for (int row = 0; row < max_row_; row++) {
        tiles_matrix_[row].resize(max_column_);
        for (int column = 0; column < max_column_; column++) {
            auto& path = *paths[row][column];
            int x = item_width * column + path.upleft_dx;
            int y = item_height * row + path.upleft_dy;
            int specify_item_width = item_width - path.upleft_dx + path.downright_dx;
            int specify_item_height = item_height - path.upleft_dy + path.downright_dy;
            Tile *tile = new Tile(paths[row][column],
                          user_pixmap_,QRect(x, y, specify_item_width, specify_item_height),
                          QPointF(x, y));
            tile->createBoreder(border_path[row][column]);

            body_map_.insert(QString::number(row)+ "_" + QString::number(column), tile->getPixmap());
            border_map_.insert(QString::number(row)+ "_" + QString::number(column), tile->getBorderPixmap());

            pTile ptile = pTile(tile, &QObject::deleteLater);
            tiles_matrix_[row][column] = ptile;
        }
    }
}

//void Item::createPixmapController(){
//    pixmap_controller_= new PixmapController();
//    pixmap_controller_->setPixmap(&map_);
//}

//PixmapController *Item::getPixmapController(){
//    PixmapController *pixmap_controller;
//    if (pixmap_controller_)
//         pixmap_controller = pixmap_controller_;
//    else {
//        pixmap_controller = new PixmapController();
//        pixmap_controller->setPixmap(&map_);
//        pixmap_controller_ = pixmap_controller;
//    }
//    return pixmap_controller;
//}

QQuickImageProvider *Item::getPixmapController(eType type) {
    PixmapController *pixmap_controller = new PixmapController();
    IndexPixmap *map;
    switch (type) {
    case eType::kBody:
        map = &body_map_;
        break;
    case eType::kBorder:
        map = &border_map_;
        break;
    }
    pixmap_controller->setPixmap(map);
    return static_cast<QQuickImageProvider*>(pixmap_controller);
}

void Item::createPaths() {
    piece_count_ = max_row_ * max_column_;

    PathsMatrix body;
    PathsMatrix border;
    SidePointsConteinerMatrix body_vertical_points;
    SidePointsConteinerMatrix body_horizontal_points;

    SidePointsConteinerMatrix border_vertical_points;
    SidePointsConteinerMatrix border_horizontal_points;

    paths_.insert(eType::kBody, body);
    paths_.insert(eType::kBorder, border);

    vertical_points_.insert(eType::kBody, body_vertical_points);
    horizontal_points_.insert(eType::kBody, body_horizontal_points);
    vertical_points_.insert(eType::kBorder, border_vertical_points);
    horizontal_points_.insert(eType::kBorder, border_horizontal_points);

    point_utilities::createVerticalPoints(user_pixmap_,  vertical_points_, max_row_, max_column_);
    point_utilities::createHorizontalPoints(user_pixmap_, horizontal_points_, max_row_, max_column_);

    path_utilities::createPaths(user_pixmap_, paths_, vertical_points_, horizontal_points_, max_row_, max_column_);
}

//void Item::
//    const size_t
//        ImageH = user_pixmap_.height(),
//        ImageW = user_pixmap_.width(),
//        h = ImageH / rows,
//        w = ImageW / columns;

//    QPoint upperBound(-w, -h);
//    QPoint lowerBound(ImageW + w, ImageH + h);

//    for (int i = 0; i < tiles_matrix_.size(); ++i) {
//        auto& row = tiles_matrix_[i];
//        for (int j = 0; j < row.size(); ++j) {
//            auto& puzzleItem = row[j];
//            ItemGround *itemGround = new ItemGround(QRectF(j*w, i*h, w, h));
//            puzzleItem->setRotatable(is_rotated);

            //  scene_.addItem(puzzleItem);
            //scene_.addItem(itemGround);

            // itemGround->setZValue(GroundLayer);
            //  puzzleItem->setZValue(m_selectionLayer);

           // puzzleItem->setPos(getBetween(upperBound, lowerBound));
            //puzzleItem->set_randomRotate();

            /*                connect(puzzleItem, SIGNAL(clicked()), SLOT(onItemClicked()));
                connect(puzzleItem, SIGNAL(setted()), SLOT(onItemSetted()));
                connect(&view_, SIGNAL(change_scalefactor()),
                        puzzleItem, SLOT(clear_selection()))*/;
            //  }
            //}
     //   }
  //  }
    // view_->fitInView(QRectF(-w, -h, 2*w+ImageW, 2*h+ImageH), Qt::KeepAspectRatio);
    // view_->centerOn(0,0);
    // view_->show();
    // view_->update();




//void Onegamecontroller::setFile(const QString &path) {
//    property_->setFile(QString(path));
//}

//void Onegamecontroller::setProperty(const ItemEnums::EItemProperty property, const QString value) {
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

//void Onegamecontroller::setProperty(const ItemEnums::EItemProperty property, const int value) {
//    if (property!=ItemEnums::EItemProperty::kNone)
//        switch (property) {
//        case ItemEnums::EItemProperty::kNone:
//        case ItemEnums::EItemProperty::kId:
//        case ItemEnums::EItemProperty::kStatus:
//            int_property_.insert(property, value);
//            break;
//        }
//}


//QString Onegamecontroller::getProperty(const ItemEnums::EItemProperty property) {
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


//void Onegamecontroller::setupDefault(const QHash<ItemEnums::EItemProperty,QString> &default_map) {
//    if (default_map.isEmpty()) {
//        LOOGGER("NO Default map");
//        return;
//    }
//    for(auto i = default_map.begin();i != default_map.end();++i) {




//    }
//}


void Item::parse() {
    // LOOGGER("+");
    // window_size_.setWidth(800);
    //  window_size_.setHeight(800);

    // to move in other function

    getPimapsFromImage();

    //        for(int i=0; i < max_row_; ++i){
    //            QPair<int,int> tile_addres;
    //            for(int j=0; j < max_column_; ++j){
    //                QPair<int,int> tile_addres = {i,j};
    //                // QPair<int,int> coordinate = {50*i, 50*i};
    //                Tile::eTileKindTemlate tile_template = getTileTemlatePixelMap(tile_addres, QPair<int,int> {max_row_,max_column_} );


    //                Tile *tile = new Tile(coordinate, user_image_, puzle_template);
    //                pTile ptile = pTile(tile, &QObject::deleteLater);
    //                row.append(ptile);

    //            }
    //            tiles_.append(row);
    //        }

    //tiles_.append(row);
    //tiles_.append(row);
    //tiles_.append(row);

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

    //  model_.setupModel(tiles_);
}

//IndexBodyPixmap *Item::getPixmap() {
//    return &map;
//}

//TileMatrix Item::getTileMatrix() {
//    return tiles_matrix_;

//}

void Item::getPimapsFromImage() {
    // QList <pTile> row;
    QImage template_("puzle.png");
    QPixmap puzle_template("puzle.png");
    QPair<int,int> image_addres = {0,0};

}

void Item::cleanModel() {
    // tiles_.clear();
}
//AbstractTableItemData *Item::getModel() {
//    return &model_;
//}

//bool Onegamecontroller::isPropertyExist(const ItemEnums::EItemProperty property){
//    if (str_property_.find(property) != str_property_.end())
//        return true;
//    else if (int_property_.find(property) != int_property_.end())
//        return true;
//    return false;
//}

//void Onegamecontroller::saveFile(const QString file_path){
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

//void Onegamecontroller::deleteFile(){
//    property_->deleteFile();
//}


Item::~Item() {
    qDebug()<<"~Item";
    //    if (scene_)
    //        delete scene_;
    //    if (view_)
    //        delete view_;
}





//QVariant AbstractItem::getItemProperty(ItemEnums::EItemProperty property_type) {
//    if (item_data_.contains((int)property_type))
//        return item_data_[(int)property_type];
//    return QVariant();
//}


