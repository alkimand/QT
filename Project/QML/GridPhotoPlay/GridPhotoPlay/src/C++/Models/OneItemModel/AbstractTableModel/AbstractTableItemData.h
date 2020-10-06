#ifndef I_WidgetModelBase_H
#define I_WidgetModelBase_H
#include <QObject>
#include <QVector>
#include <QList>
#include <QAbstractTableModel>
#include <QSharedPointer>
#include "ItemPropery.h"
#include "ItemConstant.h"
#include <tile.h>
//#include "Item.h"
#include <QSharedPointer>
#include <QHash>

//typedef  QSharedPointer<Tile<ItemEnums::EItemProperty, QString>> pTile;
//typedef QList<QList<pTile>> Tiles;


class AbstractTableItemData : public QAbstractTableModel {
    Q_OBJECT
public:
    //explicit
    AbstractTableItemData(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void setupModel(QList<QList <QSharedPointer<Tile>>>  tiles);
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    virtual ~AbstractTableItemData();

public slots:


 public:
    void cleanModelData();
   // QVector<Date_Map> *getData();

protected:
   // ItemEnums::EModelType date_type_;

    //QVector <Date_Map> worksheet_data_;
    int column_count_=               3;
    //Tiles tiles;

    //void SetupModel();
    QList<QList<QSharedPointer<Tile>>>                                                   *tiles_;
   // QList<QList <pTile>>                                                   *tiles_;
};

#endif // I_WidgetModelBase_H
