#ifndef ITEMMODELBASE
#define ITEMMODELBASE
#include <QObject>
#include <QVector>
#include <QAbstractTableModel>
#include "ItemPropery.h"
#include "ItemConstant.h"
#include <QSharedPointer>
#include <QHash>


typedef QHash<DATA_ID, QVariant> Date_Map;

class ItemModelBase : public QAbstractTableModel {
    Q_OBJECT
public:

    ItemModelBase(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void createModel(const FileData &map);

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    //private:
    
    virtual ~ItemModelBase();

public slots:
    void removeRow(const int row);
    void addRow(const int row);
    void copyRow(const int row);

public:
    void cleanModelData();
    QVector<Date_Map> *getData();

protected:
    QVector <Date_Map> worksheet_data_;
    int column_count_=               3;
};

#endif //ITEMMODELBASE
