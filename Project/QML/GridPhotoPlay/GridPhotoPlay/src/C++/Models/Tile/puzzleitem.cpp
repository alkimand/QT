#include <Tile/puzzleitem.h>

#include <QPainter>
#include <QBitmap>

PuzzleItem::~PuzzleItem() {
    //    if (pixmap_item_)
    //        delete pixmap_item_;
    //    if (pixmap_item_)
    //        delete path_;
    //    if (pixmap_)
    //        delete pixmap_;
}

PuzzleItem::PuzzleItem(PuzzlePath *path,const QPixmap& source,
                       const QRect &rect, QObject *parent)  :
    QObject(parent), QGraphicsItem(), path_(path), rect_(rect) {
    //user_pixmap_ = &source;
    QColor maskColor(122, 163, 39);
    user_pixmap_ = const_cast<QPixmap*>(&source);
    // смещаем элемент пазла т.к. его часть в отрицательных координатах,
    // при отрисовке на QPainter эта часть обрезается
    path_->path.translate(-path_->upleft_dx, -path_->upleft_dy);

    //QPixmap *pixmap = new QPixmap(source.copy(rect));
    pixmap_ =new QPixmap(user_pixmap_->copy(rect_));
    //pixmap_->fill(Qt::GlobalColor::transparent);
    //QPixmap pieceImage(source.copy(rect));

    //QImage imgMask(pieceImage.size(), QImage::Format_ARGB32);
    QImage imgMask(pixmap_->size(), QImage::Format_ARGB32);
    imgMask.fill(Qt::GlobalColor::transparent);

    QPainter painter;
    painter.begin(&imgMask);
    painter.setBrush(maskColor);
    painter.drawPath(path_->path);
    //painter.setPen(QPen(Qt::GlobalColor::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.end();

    QPixmap mask;
    mask.convertFromImage(imgMask);
    //pieceImage.setMask(mask.mask());
    pixmap_->setMask(mask.mask());
    pixmap_item_ = new QGraphicsPixmapItem(*pixmap_);
}

QRectF PuzzleItem::boundingRect() const {
    if (pixmap_item_) {
        auto rect = pixmap_item_->boundingRect();
        return rect;
    }
    return QRectF(0,0,0,0);
}

void PuzzleItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) {
    if (pixmap_item_)
        pixmap_item_->paint(painter, option, widget);
}

void PuzzleItem::createBoreder(PuzzlePath *border_path, int indent) {
    border_path_ = border_path;
    border_path_->path.translate(-border_path_->upleft_dx + indent/2, -border_path_->upleft_dy + indent/2);
    QImage imgMask(pixmap_->size(), QImage::Format_ARGB32);
    imgMask.fill(Qt::red);
    QPainter painter;
    painter.begin(&imgMask);
    // painter2.setPen(QPen(Qt::GlobalColor::red, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    QPen pen(Qt::green, 6, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    //painter2.setPen({QColor(255, 117, 56), 1});
    //painter2.setBrush(Qt::cyan);
    painter.drawPath(border_path_->path);
    painter.end();

    border_pixmap_ = new QPixmap(pixmap_->size());
    border_pixmap_->convertFromImage(imgMask);

}
