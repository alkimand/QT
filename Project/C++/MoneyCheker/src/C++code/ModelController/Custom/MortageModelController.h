#ifndef MORTAGEMODELCONTROLLER
#define MORTAGEMODELCONTROLLER

#include <QObject>
#include "iModelController.h"


//namespace controllers{

class MortageModelController: public IModelControllerBase
{

  // Q_OBJECT
public:
    explicit MortageModelController(ItemEnums::EClientType type);

//    static IModelControllerBase &instance(){
//        static  IModelControllerBase instance;
//        return instance;
//    }
protected:

private:
   // IModelControllerBase *model_;

};
//}
#endif // I_WidgetModelBase_H_
