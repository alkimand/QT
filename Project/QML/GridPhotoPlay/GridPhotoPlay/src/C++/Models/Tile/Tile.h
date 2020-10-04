#ifndef TILE
#define TILE
#include <QObject>
#include <QImage>
#include <QPair>

class Tile : public QImage {

public:
    explicit Tile(QImage &original_image, QPair<int, int> coordinate, QImage i_template);
    //explicit
    //Tile();

   // virtual ~Tile();


private:
        QImage *original_image_;
        QImage template_;
};

#endif // TILE

