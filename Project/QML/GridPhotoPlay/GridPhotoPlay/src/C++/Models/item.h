#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QSharedPointer>

#include <QHash>
#include <QList>

#include <QFile>
#include <QFileInfo>

//images
#include <QPixmap>
#include <QPainter>
#include <QRgb>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <Item/itemenums.h>
#include <Item/itemconstants.h>
#include <Item/itemproperties.h>
#include <Item/graphicsview.h>
#include <Item/puzzlepath.h>
#include <Item/pathpoints.h>
#include "Item/AbstractTableModel/ItemModelBase.h"
#include <Tile/tile.h>
#include <Item/random_points.h>

//utilities
#include <pixmap_controller.h>

//#include <ItemPropertyWrapper.h>
//#include <AbstractTableItemData.h>
#define  FX_EXTENSION                      "*.fx"
#define  JPG_EXTENSION                     "*.jpg"

//typedef  QSharedPointer<Tile> pTile;

typedef  QHash<QString, QPixmap*> IndexPixmap;
typedef  QHash<eType, QString> ImageControllerMap;


class Item: public QObject {
    Q_OBJECT

public:

public:
    explicit Item(QString path, int id = -1, int rows = 0, int columns = 0, bool is_rotated = false, QObject *parent = nullptr);

    void setWindowSize(QSize);
    void setMaxWindowRow(int);
    void setMaxWindowColumn(int);

    int getTileIdby();
    int getId();
    //void  setId(int id);
    void  setId( int id);
    eItemStatus getStatus();
    void setStatus (eItemStatus);


    //void setFile(const QString &path);

private:
    //ItemConteiner getConteinerTupe(const ItemEnums::EItemProperty &);

public:   //
    //void createVerticalPoints(size_t rows, size_t columns, bool rotated);
    void createPoints();
    void createPaths();
    void createTiles();
    void setupModel();
    //void createPixmapController();
    //PixmapController *getPixmapController();
    QQuickImageProvider *getPixmapController(eType );
    void parse();
   // IndexBodyPixmap *getPixmap();
    //TileMatrix getTileMatrix();//--
    void getPimapsFromImage();
    void cleanModel();
    ItemModelBase *getModel();

signals:
    void finished(bool win);
    void back();
    void exit();

public:

    //void setProperty(const ItemEnums::EItemProperty property, const QString value);
    // void setProperty(const ItemEnums::EItemProperty property, const int value);
    //QString getProperty(const ItemEnums::EItemProperty property);
    //void setupDefault(const QHash<ItemEnums::EItemProperty, QString> &default_map);
    //void saveFile(const QString file_path);
    //void deleteFile();
    PixmapController *pixmap_controller_;
    ~Item();
  //  AbstractTableItemData model_; //views

private:

    QFile  file_;
    QFileInfo file_info_;
    QPixmap  user_pixmap_;
    //QList<QList<pTile>> tiles_;

    QSize window_size_ = {0,0};
    int   max_row_ = 0;
    int   max_column_ = 0;
    int   indent_ = 2;
    bool is_rotated_ = false;
    QImage user_image_;

   // QHash<Tile::eTileKindTemlate, QPixmap>                                      tile_template_pix_map_;
    //QHash<Tile::eTileKindTemlate, QSize>                                        tile_template_size_map_;

    int id_ = -1;
    eItemStatus status_ = eItemStatus::kStatusNone;

    //QGraphicsScene *scene_ = nullptr;
    //GraphicsView   *view_= nullptr;

    //data
public:

    TileMatrix      tiles_matrix_;
    QVector<QVector<QString>> index_;
private:
    PathsMatrix     paths_matrix_;


    QHash<eType, SidePointsConteinerMatrix> points_;
    QHash<eType, PathsMatrix> paths_;
    QHash<eType, SidePointsConteinerMatrix> vertical_points_;
    QHash<eType, SidePointsConteinerMatrix> horizontal_points_;

    //QHash<int, QGraphicsPixmapItem> pixel_map_;

   // IndexPixmap body_map_;
   // IndexPixmap border_map_;
    QHash<eType,IndexPixmap>  indexPixmap_;

    ItemModelBase    *model_;

    //SoundController m_sound;
   // QLabel m_label;
//controls




  //  int m_selectionLayer;
    int piece_count_;
    bool m_image_orientation;

};

#endif // ITEM_H
