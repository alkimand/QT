#ifndef I_WidgetModelBase_H
#define I_WidgetModelBase_H
#include <QObject>
#include <QVector>
#include <QList>
#include <QAbstractTableModel>
#include <QSharedPointer>
#include "ItemPropery.h"
#include "ItemConstant.h"
#include <Tile.h>
#include <QSharedPointer>
#include <QHash>

//http://www.quizful.net/post/Qt.Iteratori.Kontejneri

//typedef QHash<DATA_ID, QVariant> Date_Map;
typedef  QSharedPointer<Tile> pTile;
typedef QList<QList<pTile>> Tiles;


class AbstractTableItemData : public QAbstractTableModel {
    Q_OBJECT
public:
    //explicit
    //Q_ENUM(DATA_ID)

    AbstractTableItemData(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void createModel(const FileData &map);

    bool setData(const QModelIndex &index, const QVariant &value, int role);

//private:
    
    virtual ~AbstractTableItemData();

public slots:
   //void removeRow(const int row);
   //void addRow(const int row);
  // void copyRow(const int row);

 public:
    void cleanModelData();
   // QVector<Date_Map> *getData();

protected:
   // ItemEnums::EModelType date_type_;

    //QVector <Date_Map> worksheet_data_;
    int column_count_=               3;
    Tiles tiles;

    //void SetupModel();

};

#endif // I_WidgetModelBase_H
