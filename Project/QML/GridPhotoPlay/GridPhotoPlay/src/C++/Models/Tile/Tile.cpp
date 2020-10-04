#include "tile.h"
#include "ItemConstant.h"

#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QRgb>
#include <QImage>
#include <QDebug>


Tile::Tile(QImage &original_image, QPair<int, int> coordinate, QImage i_template) : QImage(i_template),
    template_(i_template) {
    original_image_= &original_image;

    //QPixmap puzzleImage;
}
