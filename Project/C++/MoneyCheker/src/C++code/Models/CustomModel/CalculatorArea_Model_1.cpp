//#include "IWidgetModelBase.h"

#include <QDebug>
#include "CalculatorArea_Model_1.h"


CalculatorWidgetModel::CalculatorWidgetModel(ItemEnums::EModelType m_widgetType):IWidgetModelBase(m_widgetType)
{
    childModel_ = this;

   setupDefaultPropertyMap();

    setupWidgetModel();


}


void CalculatorWidgetModel::setupWidgetModel()
{

    QSharedPointer<AbstractItem> p_home_prise = QSharedPointer <AbstractItem> (new AbstractItem);
    p_home_prise.data()->setDefaultProperty(default_property_map_);
    p_home_prise.data()->setItemProperty(ItemEnums::EItemProps::kTextValue_1,"Home prise");
    p_home_prise.data()->setItemProperty(ItemEnums::EItemProps::kTextValue_3,125);
    p_home_prise.data()->setItemProperty(ItemEnums::EItemProps::kTextType_3, 2);
    rows_.push_back(QSharedPointer<AbstractItem>(p_home_prise));


    QSharedPointer<AbstractItem> p_downpayment = QSharedPointer <AbstractItem> (new AbstractItem);
    p_downpayment.data()->setDefaultProperty(default_property_map_);
    p_downpayment.data()->setItemProperty(ItemEnums::EItemProps::kTextValue_1,"Downpayment");
    p_downpayment.data()->setItemProperty(ItemEnums::EItemProps::kTextValue_2,"1252");
    p_downpayment.data()->setItemProperty(ItemEnums::EItemProps::kTextValue_3,12);
    p_downpayment.data()->setItemProperty(ItemEnums::EItemProps::kTextType_3, 6);
    p_downpayment.data()->setItemProperty(ItemEnums::EItemProps::kTextType_3, 1);
    p_downpayment.data()->setItemProperty(ItemEnums::EItemProps::kTextValue_2,11.5);
    rows_.push_back(QSharedPointer<AbstractItem>(p_downpayment));

    QSharedPointer<AbstractItem> p_rate = QSharedPointer <AbstractItem> (new AbstractItem);
    p_rate.data()->setDefaultProperty(default_property_map_);
    p_rate.data()->setItemProperty(ItemEnums::EItemProps::kTextValue_1,"Rate");
    p_rate.data()->setItemProperty(ItemEnums::EItemProps::kTextValue_3,1.25);
    p_rate.data()->setItemProperty(ItemEnums::EItemProps::kTextType_3, 1);
    p_rate.data()->setItemProperty(ItemEnums::EItemProps::kTextType_1, 6);
    rows_.push_back(QSharedPointer<AbstractItem>(p_rate));




}

void CalculatorWidgetModel::setupDefaultPropertyMap()
{
    default_property_map_.insert(int (ItemEnums::EItemProps::kTextAlightment),0);
    default_property_map_.insert(int (ItemEnums::EItemProps::kButtonCount),0);
    default_property_map_.insert(int (ItemEnums::EItemProps::kButtonType),0);
    default_property_map_.insert(int (ItemEnums::EItemProps::kTextType_1),1);
    default_property_map_.insert(int (ItemEnums::EItemProps::kTextType_2),1);
    default_property_map_.insert(int (ItemEnums::EItemProps::kTextType_3),1);
    default_property_map_.insert(int (ItemEnums::EItemProps::kTextValue_1),"");
    default_property_map_.insert(int (ItemEnums::EItemProps::kTextValue_2),"");
    default_property_map_.insert(int (ItemEnums::EItemProps::kTextValue_3),"");
}




CalculatorWidgetModel::~CalculatorWidgetModel()
{

}


