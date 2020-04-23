#include "I_WidgetModelBase.h"
#include "RowItem.h"
#include <QDebug>
#include <QVector>
#include "props.h"
#include "ItemConstant.h"

I_WidgetModelBase::I_WidgetModelBase(ItemEnums::e_ModelType widgetType):widgetType_(widgetType)
{
    // modelType_ = modelType
    setupWidgetModel();

}

void I_WidgetModelBase::setupWidgetModel()
{
    switch (int (widgetType_)){
    case (int(ItemEnums::e_ModelType::CALC_CENTER_WIDGET)) :

        QSharedPointer<AbstractItem> obj =
                QSharedPointer<AbstractItem>(new AbstractItem);
        rows.push_back(obj);

        QSharedPointer<AbstractItem> obj_ =
                QSharedPointer<AbstractItem>(new AbstractItem);
        rows.push_back(obj_);

        break;

        //break;
    }
}


QHash<int, QByteArray> I_WidgetModelBase::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(Qt::UserRole + ItemEnums::e_TableRoles::UI_WIDGET_TEXT_ALIGHTMENT_ROLE, ITEM_PROPERTY_WIDGET_TEXT_ALIGHTMENT);
    roles.insert(Qt::UserRole + ItemEnums::e_TableRoles::UI_WIDGET_BUTTON_COUNT_ROLE, ITEM_PROPERTY_WIDGET_BUTTON_COUNT);
    roles.insert(Qt::UserRole + ItemEnums::e_TableRoles::UI_WIDGET_BUTTON_TYPE_ROLE, ITEM_PROPERTY_WIDGET_BUTTON_TYPE);

    roles.insert(Qt::UserRole + ItemEnums::e_TableRoles::TEXT_1_TYPE_ROLE, ITEM_PROPERTY_TEXT_1_TYPE_ROLE);
    roles.insert(Qt::UserRole + ItemEnums::e_TableRoles::TEXT_2_TYPE_ROLE, ITEM_PROPERTY_TEXT_2_TYPE_ROLE);
    roles.insert(Qt::UserRole + ItemEnums::e_TableRoles::TEXT_3_TYPE_ROLE, ITEM_PROPERTY_TEXT_3_TYPE_ROLE);

    roles.insert(Qt::UserRole + ItemEnums::e_TableRoles::TEXT_1_VALUE_ROLE, ITEM_PROPERTY_TEXT_1_VALUE_ROLE);
    roles.insert(Qt::UserRole + ItemEnums::e_TableRoles::TEXT_2_VALUE_ROLE, ITEM_PROPERTY_TEXT_2_VALUE_ROLE);
    roles.insert(Qt::UserRole + ItemEnums::e_TableRoles::TEXT_3_VALUE_ROLE, ITEM_PROPERTY_TEXT_3_VALUE_ROLE);

    return roles;
}


QVariant I_WidgetModelBase::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role)
    {
    case (int(Qt::UserRole + ItemEnums::e_TableRoles::UI_WIDGET_TEXT_ALIGHTMENT_ROLE)):
        return this->rows.at(index.row()).get()->getItemProperty(ItemEnums::e_ItemProps::ITEM_TEXT_ALIGHTMENT);
        break;
    case (int(Qt::UserRole+ItemEnums::e_TableRoles::UI_WIDGET_BUTTON_COUNT_ROLE)):
        return this->rows.at(index.row()).get()->getItemProperty(ItemEnums::e_ItemProps::ITEM_BUTTON_COUNT);
        break;
    case (int(Qt::UserRole+ItemEnums::e_TableRoles::UI_WIDGET_BUTTON_TYPE_ROLE)):
        return this->rows.at(index.row()).get()->getItemProperty(ItemEnums::e_ItemProps::ITEM_BUTTON_TYPE);
        break;

    case (int(Qt::UserRole+ItemEnums::e_TableRoles::TEXT_1_TYPE_ROLE)):
        return this->rows.at(index.row()).get()->getItemProperty(ItemEnums::e_ItemProps::ITEM_TEXT_1_TYPE);
        break;
    case (int(Qt::UserRole+ItemEnums::e_TableRoles::TEXT_2_TYPE_ROLE)):
        return this->rows.at(index.row()).get()->getItemProperty(ItemEnums::e_ItemProps::ITEM_TEXT_2_TYPE);
        break;
    case (int(Qt::UserRole+ItemEnums::e_TableRoles::TEXT_3_TYPE_ROLE)):
        return this->rows.at(index.row()).get()->getItemProperty(ItemEnums::e_ItemProps::ITEM_TEXT_3_TYPE);
        break;

    case (int(Qt::UserRole+ItemEnums::e_TableRoles::TEXT_1_VALUE_ROLE)):
        return this->rows.at(index.row()).get()->getItemProperty(ItemEnums::e_ItemProps::ITEM_TEXT_1_VALUE);
        break;
    case (int(Qt::UserRole+ItemEnums::e_TableRoles::TEXT_2_VALUE_ROLE)):
        return this->rows.at(index.row()).get()->getItemProperty(ItemEnums::e_ItemProps::ITEM_TEXT_3_VALUE);
        break;
    case (int(Qt::UserRole+ItemEnums::e_TableRoles::TEXT_3_VALUE_ROLE)):
        return this->rows.at(index.row()).get()->getItemProperty(ItemEnums::e_ItemProps::ITEM_TEXT_3_VALUE);
        break;


    }

    return QVariant();
}

I_WidgetModelBase::~I_WidgetModelBase()
{
    qDebug()<< "~I_WidgetModelBase()";
}
