#include "MortageModelController.h"
MortageModelController::MortageModelController(ItemEnums::EClientType type):IModelControllerBase(type)
{
    child_ = this;

}
