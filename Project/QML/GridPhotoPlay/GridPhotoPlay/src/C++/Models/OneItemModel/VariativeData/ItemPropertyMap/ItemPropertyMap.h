#ifndef ITEM_PROPERTY_MAP
#define ITEM_PROPERTY_MAP

#include "VariedItemBase.h"

#include <ItemPropery.h>

#include <QObject>
#include <QHash>


typedef QHash<ItemEnums::EItemProperty, QString>    QStringPropertyMap;
typedef QHash<ItemEnums::EItemProperty, int>        IntPropertyMap;

class ItemPropertyMap: public QObject {
    Q_OBJECT

public:
    ItemPropertyMap(QObject *parent = nullptr);
    int	size() const;
    bool isEmpty() const;
    bool contains(QString property);
    bool contains(int property);
    void insert(ItemEnums::EItemProperty property_type, QString value);
    QString &operator[](const ItemEnums::EItemProperty &property_type);
    const QString operator[](const ItemEnums::EItemProperty &property_type) const;
    int &operator[](const ItemEnums::EItemProperty &property_type);
    void operator=(QString value);


          // item_data_[property_type] = value;

    ~ItemPropertyMap();
private:

    QStringPropertyMap    qStringPropertyMap_;
    IntPropertyMap             intPropertyMap;
};

#endif // ITEM_PROPERTY_MAP
