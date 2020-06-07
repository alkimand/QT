#include "IWidgetModelBase.h"
#include "RowItem.h"
#include <QDebug>
#include <QVector>
#include "props.h"
#include "ItemConstant.h"

IWidgetModelBase::IWidgetModelBase(ItemEnums::EModelType widgetType):widgetType_(widgetType)
{
    parentModel_ = this;
    // modelType_ = modelType
    //setupWidgetModel();

}

void IWidgetModelBase::setupWidgetModel()
{
    switch (int (widgetType_)){
    case (int(ItemEnums::EModelType::Calculator)) :

        QSharedPointer<AbstractItem> obj =
                QSharedPointer<AbstractItem>(new AbstractItem);
        rows_.push_back(obj);

        QSharedPointer<AbstractItem> obj_ =
                QSharedPointer<AbstractItem>(new AbstractItem);
        rows_.push_back(obj_);

        break;

        //break;
    }
}

void IWidgetModelBase::setupDefaultPropertyMap()
{
    if (childModel_)
        childModel_->setupDefaultPropertyMap();
}


QHash<int, QByteArray> IWidgetModelBase::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kTextAlightment, ITEM_PROPERTY_WIDGET_TEXT_ALIGHTMENT);
    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kButtonCount, ITEM_PROPERTY_WIDGET_BUTTON_COUNT);
    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kButtonType, ITEM_PROPERTY_WIDGET_BUTTON_TYPE);

    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kTextType_1, ITEM_PROPERTY_TEXT_1_TYPE);
    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kTextType_2, ITEM_PROPERTY_TEXT_2_TYPE);
    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kTextType_3, ITEM_PROPERTY_TEXT_3_TYPE);

    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kTextValue_1, ITEM_PROPERTY_TEXT_1_VALUE);
    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kTextValue_2, ITEM_PROPERTY_TEXT_2_VALUE);
    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kTextValue_3, ITEM_PROPERTY_TEXT_3_VALUE);

    return roles;
}


QVariant IWidgetModelBase::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role)
    {
    case (int(Qt::UserRole + ItemEnums::EItemProps::kTextAlightment)):
        return this->rows_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextAlightment);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kButtonCount)):
        return this->rows_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kButtonCount);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kButtonType)):
        return this->rows_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kButtonType);
        break;

    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextType_1)):
        return this->rows_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextType_1);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextType_2)):
        return this->rows_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextType_2);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextType_3)):
        return this->rows_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextType_3);
        break;

    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextValue_1)):
        return this->rows_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextValue_1);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextValue_2)):
        return this->rows_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextValue_2);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextValue_3)):
        return this->rows_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextValue_3);
        break;


    }

    return QVariant();
}

IWidgetModelBase::~IWidgetModelBase()
{
    qDebug()<< "~IWidgetModelBase()";
}
