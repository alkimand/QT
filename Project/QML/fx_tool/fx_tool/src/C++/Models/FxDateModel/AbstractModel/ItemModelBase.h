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

    ItemModelBase();

    void virtual  setPropertyMap();



    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    //RowItem IdemData(const QModelIndex &index, int role = Qt::DisplayRole) const;

    //QVector <QHash<DATA_ID, QVariant>> temp;
    //QVector <QHash<DATA_ID, QVariant>>  worksheet_data_(DATE_MAP_SIZE,);
    //    Q_INVOKABLE QVariantMap get(int row) const;
    //    Q_INVOKABLE void set(int row, int column, const QString &value);
    //    Q_INVOKABLE void remove(int row);



//private:
    QVector <Date_Map> worksheet_data_;
    virtual ~ItemModelBase();
protected:
    ItemEnums::EModelType date_type_;
    void SetupModel()
    ;    //ItemModelBase *childModel_ = nullptr;
    //ItemModelBase *parentModel_ = nullptr;

    //  QHash<int, QVariant> default_property_map_;

};

#endif // I_WidgetModelBase_H
