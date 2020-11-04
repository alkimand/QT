#ifndef I_WidgetModelBase_H
#define I_WidgetModelBase_H
#include <QObject>
#include <QVector>
#include <QAbstractTableModel>
#include <QAbstractTableModel>
#include <Item/itemenums.h>
#include <Item/itemconstants.h>
#include <Item/itemproperties.h>
#include <Tile/tile.h>
#include <QSharedPointer>
#include <QHash>

//http://www.quizful.net/post/Qt.Iteratori.Kontejneri


class ItemModelBase : public QAbstractTableModel {
    Q_OBJECT
public:
    //explicit
    //Q_ENUM(DATA_ID)

    ItemModelBase(TileMatrix  *tiles_matrix = nullptr, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  //  void createModel(const FileData &map);

    bool setData(const QModelIndex &index, const QVariant &value, int role);

//private:
    
    virtual ~ItemModelBase();

public slots:
 // void removeRow(const int row);
  /// void addRow(const int row);
  // void copyRow(const int row);

 public:
    //void cleanModelData();
   // QVector<Date_Map> *getData();

protected:
   // ItemEnums::EModelType date_type_;
   // QVector <Date_Map> worksheet_data_;
   // int column_count_=               5;
    //int row_count_=               5;
    //void SetupModel();



private:
    TileMatrix      *tiles_matrix_;
    QPair<int, int > size_;
    QPair<int, int > origin_coordinates_;
};

#endif // I_WidgetModelBase_H