#ifndef CALCULATOR_AREA_MODEL_1_H
#define CALCULATOR_AREA_MODEL_1_H
#include "IWidgetModelBase.h"
#include <QObject>

class CalculatorWidgetModel: public IWidgetModelBase
{
    Q_OBJECT
public:
   explicit CalculatorWidgetModel(ItemEnums::EModelType widgetType);

    void setupWidgetModel();
    void setupDefaultPropertyMap();
   // void setupDefaultProperty();

   ~CalculatorWidgetModel();


};

#endif // CALCULATOR_AREA_MODEL_1_H
