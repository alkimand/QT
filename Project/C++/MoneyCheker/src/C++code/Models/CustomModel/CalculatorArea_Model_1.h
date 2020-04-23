#ifndef CALCULATOR_AREA_MODEL_1_H
#define CALCULATOR_AREA_MODEL_1_H
#include "I_WidgetModelBase.h"
#include <QObject>

class CalculatorWidgetModel: public I_WidgetModelBase
{
    Q_OBJECT
public:
   explicit CalculatorWidgetModel(ItemEnums::e_ModelType widgetType);

    void setupWidgetModel();

   ~CalculatorWidgetModel();


};

#endif // CALCULATOR_AREA_MODEL_1_H
