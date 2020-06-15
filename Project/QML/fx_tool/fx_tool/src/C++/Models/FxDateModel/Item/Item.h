#ifndef ITEM_H
#define ITEM_H

#include "VariedItemBase.h"
#include "ItemModelBase.h"

#include <QObject>
#include <QHash>
#include <QFileInfo>
#define  iGetItemProp(props)               property_->getItemProperty(ItemEnums::EItemProperty::props)

class Item: public QObject {
    Q_OBJECT

public:
    //Item(QObject *parent = nullptr);
    //Item();
    Item(QObject *parent = nullptr);
//    AbstractItem(QObject *parent = nullptr);
 //   void setItemProperty( ItemEnums::EItemProperty propertyType, QVariant value);
 //   void setDefaultProperty(QHash<int, QVariant> default_property_map);
//    QVariant getItemProperty(ItemEnums::EItemProperty propertyType);

    void setFile(const QString &path);
    void setProperty(const ItemEnums::EItemProperty property,const Props value);
    const Props getProperty(const ItemEnums::EItemProperty property);
    //Props getProperty(const ItemEnums::EItemProperty property);
    void setPath(const Props &path);
    void setFileName(const Props &path);
    void setupDefault(const ItemPropertyMap &default_map_);
    void parse();
    void cleanModel();
    ItemModelBase *getModel();
    bool isPropertyExist(const ItemEnums::EItemProperty propertyType);
   // void createModel(FileData map);
    ~Item();
private:

    VariedItem    *property_;
    ItemModelBase    *model_;



    //ItemModelBase model_;
    //QHash<int, QVariant> item_data_;

//public slots:

    //QHash<int, QVariant> item_data_;
    //QVector <Date_Map> worksheet_data_;
};

#endif // ITEM_H
