#include <item.h>
#include <QDebug>
#include <QDir>
static const char className[] = "Item::";


Item::Item(QString path, int id, int rows, int columns, bool is_rotated, QObject *parent): QObject(parent), id_(std::move(id)),max_row_(rows), max_column_(columns), is_rotated_(is_rotated)  {
    piece_count_ = max_row_ * max_column_;

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


void Item::setId( int id){
    id_ = id;
}

eItemStatus Item::getStatus() {
    return status_;
}


void Item::setStatus(eItemStatus new_status){
    status_= new_status;
}


void Item::createPoints() {
    SidePointsConteinerMatrix body_vertical_points;
    SidePointsConteinerMatrix body_horizontal_points;

    SidePointsConteinerMatrix border_vertical_points;
    SidePointsConteinerMatrix border_horizontal_points;

    point_utilities::createVerticalPoints(user_pixmap_,  body_vertical_points, max_row_, max_column_);
    point_utilities::createVerticalBorderPoints(body_vertical_points, border_vertical_points, indent_);
    point_utilities::createHorizontalPoints(user_pixmap_, body_horizontal_points, max_row_, max_column_);
    point_utilities::createHorizontalBorderPoints( body_horizontal_points, border_horizontal_points, indent_);

    vertical_points_.insert(eType::kBody, body_vertical_points);
    horizontal_points_.insert(eType::kBody, body_horizontal_points);
    vertical_points_.insert(eType::kBorder, border_vertical_points);
    horizontal_points_.insert(eType::kBorder, border_horizontal_points);
}


void Item::createPaths() {
    path_utilities::createPaths(paths_[eType::kBody], vertical_points_[eType::kBody], horizontal_points_[eType::kBody], max_row_, max_column_);
    path_utilities::createPaths(paths_[eType::kBorder], vertical_points_[eType::kBorder], horizontal_points_[eType::kBorder], max_row_, max_column_);
}

void Item::createTiles() {
    const QColor maskColor(122, 163, 39);

    const int item_height = user_pixmap_.size().height() / max_row_;
    const int item_width = user_pixmap_.size().width() / max_column_;

    auto paths = paths_[eType::kBody];
    tiles_matrix_.resize(max_row_);
    index_.resize(max_row_);
    for (int row = 0; row < max_row_; ++row) {
        tiles_matrix_[row].resize(max_column_);
        index_[row].resize(max_column_);
        for (int column = 0; column < max_column_; ++column) {
            auto& path = *paths[row][column];
            int x = item_width * column + path.upleft_dx;
            int y = item_height * row + path.upleft_dy;
            int specify_item_width = item_width - path.upleft_dx + path.downright_dx;
            int specify_item_height = item_height - path.upleft_dy + path.downright_dy;
            Tile *tile = new Tile(paths[row][column],
                                  user_pixmap_,QRect(x, y, specify_item_width, specify_item_height),
                                  QPointF(x, y));

            tile->setIndex(qMakePair(row, column));

            tile->createBorder(paths_[eType::kBorder][row][column], indent_);
            QString index = QString::number(row)+ "_" + QString::number(column);
            indexPixmap_[eType::kBody].insert(index, tile->getPixmap());
            indexPixmap_[eType::kBorder].insert(index, tile->getBorderPixmap());
            pTile ptile = pTile(tile, &QObject::deleteLater);
            tiles_matrix_[row][column] = ptile;
            index_[row][column] = index;
        }
    }
}

void Item::setupModel() {
    QPair<int, int> size {tiles_matrix_.size(),tiles_matrix_[0].size()};
    model_ = new ItemModelBase(&tiles_matrix_, this);
    //model_ = new ItemModelBase(size, this);

}


QQuickImageProvider *Item::getPixmapController(eType type) {
    PixmapController *pixmap_controller = new PixmapController();
    pixmap_controller->setPixmap(&indexPixmap_[type]);
    return static_cast<QQuickImageProvider*>(pixmap_controller);
}


void Item::parse() {
    getPimapsFromImage();
}


void Item::getPimapsFromImage() {
    // QList <pTile> row;
    QImage template_("puzle.png");
    QPixmap puzle_template("puzle.png");
    QPair<int,int> image_addres = {0,0};

}

void Item::cleanModel() {
    // tiles_.clear();
}

ItemModelBase *Item::getModel() {
    return model_;
}

Item::~Item() {
    qDebug()<<"~Item";
}
