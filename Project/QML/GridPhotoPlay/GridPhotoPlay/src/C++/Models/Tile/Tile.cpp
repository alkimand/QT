#include <Tile/tile.h>
//#include "ItemConstant.h"

void Tile::setID(int id) {
    id_=id;
}

Tile::Tile(PuzzlePath *path, const QPixmap &source, const QRect &rect, QPointF correct_corner_possition, QObject *parent):
    SettableItem(path, source, rect, correct_corner_possition, parent) {

}

QPixmap *Tile::getPixmap() {
    return pixmap_;
}
