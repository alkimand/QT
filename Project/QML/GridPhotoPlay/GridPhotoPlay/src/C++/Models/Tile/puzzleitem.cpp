#include <Tile/puzzleitem.h>

#include <QPainter>
#include <QBitmap>
#include <QDebug>

PuzzleItem::~PuzzleItem() {
    //    if (pixmap_item_)
    //        delete pixmap_item_;
    //    if (pixmap_item_)
    //        delete path_;
    //    if (piece_pixmap_)
    //        delete piece_pixmap_;
}

PuzzleItem::PuzzleItem(PuzzlePath *path,const QPixmap& source,
                       const QRect &rect, QObject *parent)  :
    QObject(parent), QGraphicsItem(), path_(path), rect_(rect) {
    //user_pixmap_ = &source;
    QColor maskColor(122, 163, 39);
    user_pixmap_ = const_cast<QPixmap*>(&source);
    // смещаем элемент пазла т.к. его часть в отрицательных координатах,
    // при отрисовке на QPainter эта часть обрезается

    for (auto &it : path->path)
        full_path_.connectPath(it);
    full_path_.translate(-path_->upleft_dx, -path_->upleft_dy);

    //QPixmap *pixmap = new QPixmap(source.copy(rect));
    piece_pixmap_ = new QPixmap(user_pixmap_->copy(rect_));
    //piece_pixmap_->fill(Qt::GlobalColor::transparent);
    //QPixmap pieceImage(source.copy(rect));

    //QImage imgMask(pieceImage.size(), QImage::Format_ARGB32);
    QImage imgMask(piece_pixmap_->size(), QImage::Format_ARGB32);
    imgMask.fill(Qt::GlobalColor::transparent);

    QPainter painter;
    painter.begin(&imgMask);
    painter.setBrush(maskColor);
    painter.drawPath(full_path_);
    //painter.setPen(QPen(Qt::GlobalColor::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.end();

    QPixmap mask;
    mask.convertFromImage(imgMask);
    piece_pixmap_->setMask(mask.mask());

    background_piece_pixmap_ =  piece_pixmap_;//-
}

QRectF PuzzleItem::boundingRect() const {
   // if (pixmap_item_) {
       // auto rect = pixmap_item_->boundingRect();
       // return rect;
   // }
    return QRectF(0,0,0,0);
}

void PuzzleItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) {
   // if (pixmap_item_)
      //  pixmap_item_->paint(painter, option, widget);
}

void PuzzleItem::createBackgroundBorder(PuzzlePath *border_path, const int indent, const QColor &color) {

    background_border_pixmap_ = createBorderPixmap(border_path, indent, color);
}

void PuzzleItem::createSelectionBorder(PuzzlePath *border_path, const int indent, const QColor &color) {
    selection_border_pixmap_ = createBorderPixmap(border_path, indent, color);
}

//void PuzzleItem::createBorder(PuzzlePath *border_path, const int indent,const  QColor &color ) {
//    //qDebug()<< ("createBorder");

////    QPainterPath full_path_;
////    border_path_ = border_path;
////    for (auto &it : border_path_->path)
////        full_path_.connectPath(it);
////    full_path_.translate(-border_path_->upleft_dx + indent/2, -border_path_->upleft_dy + indent/2);
////    QImage imgMask(piece_pixmap_->size(), QImage::Format_ARGB32);
////    imgMask.fill(Qt::GlobalColor::transparent);
////    QPainter painter;
////    painter.begin(&imgMask);;
////    QPen pen(color, indent, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
////    painter.setPen(pen);
////    painter.drawPath(full_path_);
////    painter.end();

////    selection_border_pixmap_ = new QPixmap(piece_pixmap_->size());
////    selection_border_pixmap_->convertFromImage(imgMask);
//}

QPixmap* PuzzleItem::createBorderPixmap(PuzzlePath *border_path, const int indent, const QColor &color) {
    QPainterPath full_path_;
    for (auto &it : border_path->path)
        full_path_.connectPath(it);
    full_path_.translate(-border_path->upleft_dx + indent/2, -border_path->upleft_dy + indent/2);
    QImage imgMask(piece_pixmap_->size(), QImage::Format_ARGB32);
    imgMask.fill(Qt::GlobalColor::transparent);
    QPainter painter;
    painter.begin(&imgMask);;
    QPen pen(color, indent, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    painter.drawPath(full_path_);
    painter.end();

    QPixmap *border_pixmap = new QPixmap(piece_pixmap_->size());
    border_pixmap->convertFromImage(imgMask);
    return border_pixmap;
}

void PuzzleItem::createTouchesBorder(PuzzlePath *border_path, const int indent) {
    //createBorderPixmap(border_path, indent);
}

void PuzzleItem::setAddress(QPair<int, int> address) {
    address_= address;
}

QPair<int, int> PuzzleItem::getOriginCoordinates() {
    QPair<int, int> coordinates;
    coordinates.first = rect_.x();
    coordinates.second = rect_.y();
    return coordinates;
}

QString PuzzleItem::getSIndex() {
    QString result = QString::number(index_.first) + "_" +  QString::number(index_.second);
    return result;
}

void PuzzleItem::setIndex(QPair<int, int> index) {
    index_= index;
}

void PuzzleItem::createBackgroundPixmap() {

}
