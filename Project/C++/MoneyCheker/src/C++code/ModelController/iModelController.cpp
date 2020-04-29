#include "iModelController.h"


IModelControllerBase::IModelControllerBase(ItemEnums::EClientType type):type_(type)
{
    parent_ = this;
}
