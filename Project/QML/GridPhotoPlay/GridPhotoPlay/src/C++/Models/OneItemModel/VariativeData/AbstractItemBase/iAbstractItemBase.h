#ifndef I_ABSTRACY_ITEM_BASE_H
#define I_ABSTRACY_ITEM_BASE_H

#include <QObject>
//#include <QHash>

#include <ItemPropery.h>
typedef QHash<ItemEnums::EItemProperty, QString>        ItemPropertyMap;


typedef QString QString;



class iAbstractItemBase: public QObject {
public:
    iAbstractItemBase(QObject *parent = nullptr);
    void setItemProperty( ItemEnums::EItemProperty propertyType, QString value);
    void setDefaultPropertyMap(const ItemPropertyMap &default_map);
    const QString &getItemProperty(const ItemEnums::EItemProperty &propertyType);
    //const FileData &getFileModel();
    bool isPropertyExist(const ItemEnums::EItemProperty propertyType);
protected:

    ItemPropertyMap     item_data_;


private:



};

#endif // I_ABSTRACY_ITEM_BASE_H
