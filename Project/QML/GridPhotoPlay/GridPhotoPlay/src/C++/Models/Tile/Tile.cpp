#include <Tile/tile.h>
//#include "ItemConstant.h"

void Tile::setID(int id) {
    id_=id;
}

Tile::Tile(PuzzlePath *path, const QPixmap &source, const QRect &rect, QPointF correct_corner_possition, QObject *parent):
    PuzzleItem(path, source, rect, parent) {

}

QPixmap *Tile::getPixmap() {
    return piece_pixmap_;
}

QPixmap *Tile::getSelectionBorderPixmap(){
    return selection_border_pixmap_;
}

QPixmap *Tile::getBackGroundBorderPixmap(){
    return background_border_pixmap_;
}

QPixmap *Tile::getBackGroundPixmap() {
    //return piece_pixmap_;
    return background_piece_pixmap_;
}

