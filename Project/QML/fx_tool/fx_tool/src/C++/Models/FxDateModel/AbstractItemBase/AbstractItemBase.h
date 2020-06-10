#ifndef ROWITEM_H
#define ROWITEM_H
#include "ItemPropery.h"
//#include <QObject>
#include <QHash>
#include <QSharedPointer>
#include <databuf.h>
#include <QFileInfo>

typedef QString Props;
typedef QHash<ItemEnums::EItemProperty, Props> ItemPropertyMap;


class AbstractItemBase: public QObject{


public:
    AbstractItemBase(QObject *parent = nullptr);
    //AbstractItem();
    void setItemProperty( ItemEnums::EItemProperty propertyType, Props value);
    void setDefaultPropertyMap(const ItemPropertyMap &default_map);
    void changeItemProperty(ItemEnums::EItemProperty propertyType, Props value);
    const Props &getItemProperty(const ItemEnums::EItemProperty &propertyType);
    void setFile(const Props &path);
    void parse();
    void readFile(QString file_name, sys::IDataBuff& buff, int &error);
    const FileData &getFileModel();
protected:

    ItemPropertyMap item_data_;


private:
    QFile               file_;
    QFileInfo           file_info_;
    FileData            value_map_;


};

#endif // BORDERRADIUSWIDGET_H
