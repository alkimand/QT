#ifndef TILE
#define TILE
#include <QObject>
#include <QSharedPointer>
#include <QVector>

#include <Tile/puzzleitem.h>

class Tile : public PuzzleItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    void setID(int id);
    Tile(PuzzlePath *path, const QPixmap& source, const QRect &rect,
            QPointF correct_corner_possition, QObject *parent = nullptr);

    QPixmap *getPixmap();

    QPixmap *getBorderPixmap();
    //virtual ~Tile();


private:
    int id_ = -1;
};

typedef  QSharedPointer<Tile> pTile;
typedef  QVector<QVector <pTile> > TileMatrix;

//typedef  QSharedPointer<Tile> pTile;

#endif // TILE

