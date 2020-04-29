#include "RowItem.h"
#include <QDebug>
//RowItem::RowItem(QObject *parent): QObject(parent)

AbstractItem::AbstractItem()//(QObject *parent): QObject(parent)
{
    // itemData_.insert(int(ItemEnums::EItemProps::kTextValue_1), "test");
    // itemData_.insert(int(ItemEnums::EItemProps::kTextValue_3), 1000);

}

void AbstractItem::setItemProperty(ItemEnums::EItemProps property_type, QVariant value)
{
    if (itemData_.contains((int)property_type))
        itemData_[(int)property_type] = QVariant(value);
    else
        itemData_.insert(int(property_type), QVariant(value));
}

void AbstractItem::setDefaultProperty(QHash<int, QVariant> default_property_map)
{
    QHashIterator<int, QVariant> i(default_property_map);
    while (i.hasNext()) {
        i.next();
        itemData_.insert(i.key(),i.value());
    }
}

void AbstractItem::changeItemProperty(ItemEnums::EItemProps property_type, QVariant value)
{
    if (itemData_.contains((int)property_type))
        itemData_[(int)property_type] = QVariant(value);
}


QVariant AbstractItem::getItemProperty(ItemEnums::EItemProps property_type)
{
    if (itemData_.contains((int)property_type))
        return itemData_[(int)property_type];
    return QVariant();
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
