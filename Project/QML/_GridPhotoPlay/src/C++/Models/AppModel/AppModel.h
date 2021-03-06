#ifndef APP_MODEL_H
#define APP_MODEL_H
#include <QObject>
#include <QVector>
#include <QAbstractTableModel>
#include "ItemPropery.h"
#include "ItemConstant.h"
#include "Item.h"
#include <QSharedPointer>
#include <QHash>

#define  FX_EXTENSION                      "*.fx"
#define  GetItemProp(props)                item.get()->getProperty(ItemEnums::EItemProperty::props)
#define  setItemProp_int(id , props)       item.get()->setProperty(ItemEnums::EItemProperty::id , QString::number( props ))
typedef  QSharedPointer<Item> pItem;

class AppModel : public QAbstractTableModel {
    Q_OBJECT
public:
    AppModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    virtual ~AppModel();

public:
   // void setDirectory(QString directory);
    void parseFolder(const QString file_path);
    void parseItem(pItem item);
    pItem  getItemByID(const QString id);
    int haveSameModelByProperty(const ItemEnums::EItemProperty propertyType, const Props property);
    void createItem(const QString &path = "");
    int getLastCreatedItemId();
    void saveFile(const QString file_path, const QString id);
    void deleteFile( const QString id);

    //private:

protected:
    //ItemEnums::EModelType date_type_;
   // QVector <Date_Map> worksheet_data_;
    QVector<pItem>                     app_data_;
    // void SetupModel();
    ItemPropertyMap       default_property_map_;
    int                   model_counter_ = -1;

private:
    void Init();

    QStringList FindFilies(const QString path = "");


     QString getPropperIcon(const QString file_name = "");

signals:
   // void itemParsed(int id);


};

#endif // APP_MODEL_H
