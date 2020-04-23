#include "RowItem.h"
#include <QDebug>
//RowItem::RowItem(QObject *parent): QObject(parent)

AbstractItem::AbstractItem()//(QObject *parent): QObject(parent)
{
    itemData_.insert(int(ItemEnums::e_ItemProps::ITEM_TEXT_1_VALUE), "test");
    itemData_.insert(int(ItemEnums::e_ItemProps::ITEM_TEXT_3_VALUE), 1000);
}

void AbstractItem::setItemProperty(ItemEnums::e_ItemProps propertyType, QVariant toValue)
{
    if (itemData_.contains((int)propertyType))
        itemData_[(int)propertyType] = toValue;
}

void AbstractItem::changeItemProperty(ItemEnums::e_ItemProps propertyType, QVariant toValue)
{
    if (itemData_.contains((int)propertyType))
        itemData_[(int)propertyType] = toValue;
}


QVariant AbstractItem::getItemProperty(ItemEnums::e_ItemProps propertyType)
{
    if (itemData_.contains((int)propertyType))
        return itemData_[(int)propertyType];
}

//QString AbstractItem::textFirstRow() const
//{
//    return m_textFirstRow;
//}


//void AbstractItem::SetTextFirstRow(QString text)
//{
//    if (m_textFirstRow == text)
//        return;
//    m_textFirstRow = text;
//    emit TextFirstRowChanged(m_textFirstRow);
//    qDebug()<< "SetTextFirstRow="+text;
//}
