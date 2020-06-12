#ifndef I_ABSTRACY_ITEM_BASE_H
#define I_ABSTRACY_ITEM_BASE_H
#include "ItemPropery.h"
#include <QObject>
#include <QHash>

typedef QString Props;
typedef QHash<ItemEnums::EItemProperty, Props> ItemPropertyMap;


class iAbstractItemBase: public QObject {
public:
    iAbstractItemBase(QObject *parent = nullptr);
    void setItemProperty( ItemEnums::EItemProperty propertyType, Props value);
    void setDefaultPropertyMap(const ItemPropertyMap &default_map);
    void changeItemProperty(ItemEnums::EItemProperty propertyType, Props value);
    const Props &getItemProperty(const ItemEnums::EItemProperty &propertyType);
    const FileData &getFileModel();
protected:

    ItemPropertyMap     item_data_;


private:



};

#endif // I_ABSTRACY_ITEM_BASE_H