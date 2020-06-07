#include "IEssenceModelBase.h"
#include "AbstractItem.h"
#include <QDebug>
#include <QVector>
#include "ItemPropery.h"
#include "ItemConstant.h"

IEssenceModelBase::IEssenceModelBase(ItemEnums::EModelType widgetType):widgetType_(widgetType)
{
    parentModel_ = this;
    // modelType_ = modelType
    //setupWidgetModel();

}

void IEssenceModelBase::setupWidgetModel()
{
//    switch (int (widgetType_)){
//    case (int(ItemEnums::EModelType::Calculator)) :

//        QSharedPointer<AbstractItem> obj =
//                QSharedPointer<AbstractItem>(new AbstractItem);
//        data_.push_back(obj);

//        QSharedPointer<AbstractItem> obj_ =
//                QSharedPointer<AbstractItem>(new AbstractItem);
//        data_.push_back(obj_);

       // break;

        //break;
    }
}

void IEssenceModelBase::setupDefaultPropertyMap()
{
    if (childModel_)
        childModel_->setupDefaultPropertyMap();
}


QHash<int, QByteArray> IEssenceModelBase::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kTextAlightment, ITEM_PROPERTY_WIDGET_TEXT_ALIGHTMENT);
    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kButtonCount, ITEM_PROPERTY_WIDGET_BUTTON_COUNT);
    roles.insert(Qt::UserRole + ItemEnums::EItemProps::kButtonType, ITEM_PROPERTY_WIDGET_BUTTON_TYPE);

    return roles;
}


QVariant IEssenceModelBase::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role)
    {
    case (int(Qt::UserRole + ItemEnums::EItemProps::kTextAlightment)):
        return this->data_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextAlightment);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kButtonCount)):
        return this->data_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kButtonCount);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kButtonType)):
        return this->data_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kButtonType);
        break;

    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextType_1)):
        return this->data_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextType_1);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextType_2)):
        return this->rows_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextType_2);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextType_3)):
        return this->data_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextType_3);
        break;

    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextValue_1)):
        data_.at(index.row()).at(index.column());
        //return this->data_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextValue_1);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextValue_2)):
        return this->data_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextValue_2);
        break;
    case (int(Qt::UserRole+ItemEnums::EItemProps::kTextValue_3)):
        return this->data_.at(index.row()).get()->getItemProperty(ItemEnums::EItemProps::kTextValue_3);
        break;


    }

    return QVariant();
}

IEssenceModelBase::~IEssenceModelBase()
{
    qDebug()<< "~IEssenceModelBase()";
}
