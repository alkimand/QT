#ifndef ABSTRACTPROPERTYCONTEINER
#define ABSTRACTPROPERTYCONTEINER

#include <QObject>
#include <QHash>

#include <ItemPropery.h>


template <typename Key, typename Val>
class AbstractPropertyConteiner: public QHash<Key, Val>  {
public:
//    typedef QHash<T, QString>           ItemPropertyMap;
//    AbstractPropertyConteiner();
//    void setItemProperty( const T &propertyType,const QString &value);
//    void setDefaultPropertyMap(ItemPropertyMap default_map);
//    const QString getItemProperty(const T &propertyType);;
//    bool isPropertyExist(const T &propertyType);
protected:

    //ItemPropertyMap     item_data_;


private:



};

#endif // ABSTRACTPROPERTYCONTEINER
