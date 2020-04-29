#ifndef ROWITEM_H
#define ROWITEM_H
#include "props.h"
#include <QObject>
#include <QHash>

//Row controller
class AbstractItem: public QObject
{
    Q_OBJECT



public:
     //RowItem(QObject *parent = nullptr);
    AbstractItem();
//    QString SetTextFirstRow() const;
//    QString textFirstRow() const;
    void setItemProperty( ItemEnums::EItemProps propertyType, QVariant value);
    void setDefaultProperty(QHash<int, QVariant> default_property_map);
    void changeItemProperty(ItemEnums::EItemProps propertyType, QVariant value);
    QVariant getItemProperty(ItemEnums::EItemProps propertyType);

private:

    QHash<int, QVariant> itemData_;

public slots:



   // void TextFirstRowChanged(QString text);

  //  void dataChanged(QVariant value,ItemEnums::EItemProps propertyType);
};

#endif // BORDERRADIUSWIDGET_H
