#include <screen.h>

#include <QDebug>

Screen::Screen(const int id, const  QString image_path, const QPair <int, int> cells_size, 
    bool is_rotated, QWidget* parent) : QWidget(parent), id_(id), image_path_(image_path), 
    cells_size_(cells_size), is_rotated_(is_rotated) {

    //piece_count_ = max_row_ * max_column_;
    //file_info_.setFile(std::move(path));
    //bool is_file_exist = false;
    //if (file_info_.exists() && file_info_.isFile())
    //    is_file_exist = true;
    //if (!is_file_exist)
    //    qDebug() << ("NO Default image on path " + path);
}


void Screen::setWindowSize(const QPair <int, int> window_size) {
    window_pixel_size_ = window_size;
}


int Screen::getId() {
    return id_;
}

eItemStatus Screen::getStatus() {
    return status_;
}


void Screen::setStatus(eItemStatus new_status) {
    status_ = new_status;
}



//void Screen::createTiles() {
//    const QColor maskColor(122, 163, 39);
//
//    const int item_height = user_pixmap_.size().height() / max_row_;
//    const int item_width = user_pixmap_.size().width() / max_column_;
//
//    auto paths = paths_[eType::kBody];
//    tiles_matrix_.resize(max_row_);
//    index_.resize(max_row_);
//    for (int row = 0; row < max_row_; ++row) {
//        tiles_matrix_[row].resize(max_column_);
//        index_[row].resize(max_column_);
//        for (int column = 0; column < max_column_; ++column) {
//            auto& path = *paths[row][column];
//            int x = item_width * column + path.upleft_dx;
//            int y = item_height * row + path.upleft_dy;
//            int specify_item_width = item_width - path.upleft_dx + path.downright_dx;
//            int specify_item_height = item_height - path.upleft_dy + path.downright_dy;
//            Tile* tile = new Tile(paths[row][column],
//                user_pixmap_, QRect(x, y, specify_item_width, specify_item_height),
//                QPointF(x, y));
//
//            tile->setIndex(qMakePair(row, column));
//
//            //  tile->createSelectionBorder(paths_[eType::kSelectionBorder][row][column], indent_,  Qt::yellow);
//            tile->createBackgroundBorder(paths_[eType::kBackgroundBorder][row][column], black_grid_border_indent_, Qt::black);
//            // tile->createTouchesBorderder(paths_[eType::kTouchesBorder][row][column], backgrount_touches_indent_);
//
//            QString index = QString::number(row) + "_" + QString::number(column);
//            indexPixmap_[eType::kBody].insert(index, tile->getPixmap());
//            //indexPixmap_[eType::kSelectionBorder].insert(index, tile->getSelectionBorderPixmap());
//            indexPixmap_[eType::Background].insert(index, tile->getBackGroundPixmap());;
//            indexPixmap_[eType::kBackgroundBorder].insert(index, tile->getBackGroundBorderPixmap());
//            pTile ptile = pTile(tile, &QObject::deleteLater);
//            tiles_matrix_[row][column] = ptile;
//            index_[row][column] = index;
//        }
//    }
//}

void Screen::setScreenSize(const QSize new_window_size) {
  /*  QPixmap new_pixmap(user_pixmap_.scaled(to_screen_width, to_screen_height));
    user_pixmap_ = new_pixmap;*/
}


void Screen::loadUserImage() {
    user_pixmap_->load(file_info_->filePath());
}

Screen::~Screen() {
    qDebug() << "~Screen";

    if (file_)
        delete file_;
    if (file_info_)
        delete file_info_;
    if (user_pixmap_)
        delete user_pixmap_;
}