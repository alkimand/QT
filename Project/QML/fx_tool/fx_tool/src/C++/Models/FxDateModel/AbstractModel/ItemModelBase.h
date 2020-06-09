#ifndef I_WidgetModelBase_H
#define I_WidgetModelBase_H
#include <QObject>
#include <QVector>
#include <QAbstractTableModel>
#include "ItemPropery.h"
#include "ItemConstant.h"
#include <QSharedPointer>
#include <QHash>

//http://www.quizful.net/post/Qt.Iteratori.Kontejneri

typedef QHash<DATA_ID, QVariant> Date_Map;

class ItemModelBase : public QAbstractTableModel
{

    Q_OBJECT
public:
    //explicit
    //Q_ENUM(DATA_ID)

    //ItemModelBase(QObject *parent = nullptr);
ItemModelBase();
    void virtual  setPropertyMap();



    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

//private:
    
    virtual ~ItemModelBase();
protected:
    ItemEnums::EModelType date_type_;
    QVector <Date_Map> worksheet_data_;
    void SetupModel();
};

#endif // I_WidgetModelBase_H
