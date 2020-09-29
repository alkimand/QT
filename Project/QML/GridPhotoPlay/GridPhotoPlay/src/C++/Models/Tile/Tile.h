#ifndef TILE
#define TILE
#include <QObject>

#include <AbstractPropertyConteiner.h>


class Tile : public AbstractPropertyConteiner{

    Q_OBJECT
public:
    //explicit
    Tile();

    virtual ~Tile();
};

#endif // I_WidgetModelBase_H

