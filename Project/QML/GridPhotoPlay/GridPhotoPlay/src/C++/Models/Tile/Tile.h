#ifndef TILE
#define TILE
#include <QObject>
//#include <QSharedPointer>

#include <QImage>
#include <QPair>
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QRgb>

class Tile : public QObject,  public QPixmap {
    Q_OBJECT

public:
    enum eTileTemlate {
        kLeft = 0,
        kTopLeft ,
        kTop,
        kTopRight,
        kRight,
        kBottomRight,
        kBottom,
        kBottomLeft,
        kCenter_type_1,
        kCenter_type_2,
        kCenter_type_3
    };



public:
   //explicit
    //Tile(QObject *parent = nullptr){};
    Tile(QPair<int, int> coordinate, QPixmap &original_pixmap, QPixmap &_template);
    //explicit
    //Tile();

    //virtual ~Tile();


private:
        QImage *original_image_;
        QImage *template_;
        int id_;
};


//typedef  QSharedPointer<Tile> pTile;

#endif // TILE

