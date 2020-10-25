#ifndef TILE
#define TILE
#include <QObject>

#include <Tile/settableitem.h>

class Tile : public SettableItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    void setID(int id);
    Tile(PuzzlePath *path, const QPixmap& source, const QRect &rect,
            QPointF correct_corner_possition, QObject *parent = nullptr);
    QPixmap *getPixmap();
    //virtual ~Tile();


private:
    int id_ = -1;

};


//typedef  QSharedPointer<Tile> pTile;

#endif // TILE

