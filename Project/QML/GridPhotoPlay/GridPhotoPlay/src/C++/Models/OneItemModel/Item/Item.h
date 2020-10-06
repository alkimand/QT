#ifndef ITEM_H
#define ITEM_H

#include <ItemPropertyWrapper.h>
#include <AbstractTableItemData.h>

#include <QObject>
#include <QSharedPointer>

#include <QHash>
#include <QList>

#include <QFile>
#include <QFileInfo>

#include <tile.h>

//images
#include <QPixmap>
#include <QPainter>
#include <QRgb>
#include <QImage>



#define  FX_EXTENSION                      "*.fx"
#define  JPG_EXTENSION                     "*.jpg"

typedef  QSharedPointer<Tile> pTile;

class Item: public QObject {
    Q_OBJECT

public:
   enum EItemProperty {
        kNone = -1,
        kId ,
        kStatus,
        kFilePath,
        kFileName,
        kIcon,
        kDateLastSaved,
        kFormat
    };

   Q_ENUM(EItemProperty)
    enum eItemStatus {
        kInit = -1,
        kDetected,
        kParsing,
        kParsed,
        kRemoving,
        kParseError,
        kSaveError
    };
    Q_ENUM(eItemStatus)


//    enum ItemConteiner {
//        string = 0,
//        integer = 1
//    };

public:
    Item(QObject *parent = nullptr);

    //property
    void setFile(QString file_path);
    void setFileName(QString file_name);
    void setFilePath(const QString &file_name);
    void setWindowSize(const QSize &&);
    void setMaxWindowRow(const int &&);
    void setMaxWindowColumn(const int &&);
    void setupTileTemplateMap();
    int getTileIdby();
    int getId();
    //void  setId(int id);
    void  setId(const int &&id);
    eItemStatus getStatus();
    void setStatus (const eItemStatus &&);

    //void setFile(const QString &path);

private:


    //ItemConteiner getConteinerTupe(const ItemEnums::EItemProperty &);

public:   //
    void parse();
    void cleanModel();
     AbstractTableItemData *getModel();

public:
    //property
//    bool isPropertyExist(const ItemEnums::EItemProperty property);
//    template <typename Value>
//    void setProperty(const ItemEnums::EItemProperty property, const Value value) {
//        ItemConteiner conteiner_tupe = getConteinerTupe(property);
//        //if (typeid(value).name() == typeid(int()).name()) {
//        if (conteiner_tupe == ItemConteiner::string)
//            str_property_.insert(property, QString(value));
//        // }
//        //else if (typeid(value).name() == typeid(QString()).name()){
//        else if (conteiner_tupe == ItemConteiner::integer)
//            int_property_.insert(property, QVariant(value).toInt());
//        //  }
//    }


    //void setProperty(const ItemEnums::EItemProperty property, const QString value);
    // void setProperty(const ItemEnums::EItemProperty property, const int value);
    //QString getProperty(const ItemEnums::EItemProperty property);
    //void setupDefault(const QHash<ItemEnums::EItemProperty, QString> &default_map);

    //void saveFile(const QString file_path);
    //void deleteFile();

    //~Item();
    AbstractTableItemData                                                  model_; //views

private:

    QFile                                                                   file_;
    QFileInfo                                                               file_info_;
    QPixmap                                                                  user_image_;
    QList<QList<pTile>>                                                     tiles_;

    QSize                                                                   window_size_ = {0,0};
    int                                                                     max_row_ = 0;
    int                                                                     max_column_ = 0;

    //QFileInfo                                                              file_info_;
    //QImage                                                                 image_;

    QHash<Tile::eTileTemlate, QPixmap>                                      tile_template_pix_map_;
    QHash<Tile::eTileTemlate, QSize>                                        tile_template_size_map_;

    int id_ = -1;
    eItemStatus status_ = eItemStatus::kInit;

};

#endif // ITEM_H
