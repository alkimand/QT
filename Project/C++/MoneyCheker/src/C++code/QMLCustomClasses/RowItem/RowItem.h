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
    void setItemProperty( ItemEnums::e_ItemProps propertyType, QVariant value);
    void changeItemProperty(ItemEnums::e_ItemProps propertyType, QVariant value);
    QVariant getItemProperty(ItemEnums::e_ItemProps propertyType);

private: //ITEM PROPS
    //QString m_textFirstRow= "test";
    ;
   // QList<QVariant> itemData_;
    QHash<int, QVariant> itemData_;
   //  ItemEnums::e_ModelType type;

public slots:



   // void TextFirstRowChanged(QString text);

  //  void dataChanged(QVariant value,ItemEnums::e_ItemProps propertyType);
};

#endif // BORDERRADIUSWIDGET_H
