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
    Item(QObject *parent = nullptr);
    void setFile(const QString &path);
    void setProperty(const ItemEnums::EItemProperty property,const QString value);
    const QString getProperty(const ItemEnums::EItemProperty property);
    void setPath(const QString &path);
    void setFileName(const QString &path);
    void setupDefault(const ItemPropertyMap &default_map_);
    void parse();
    void cleanModel();
    ItemModelBase *getModel();
    bool isPropertyExist(const ItemEnums::EItemProperty propertyType);
    void saveFile(const QString file_path);
    void deleteFile();
    ~Item();
private:

    VariedItem    *property_;
    ItemModelBase    *model_;
};

#endif // ITEM_H
