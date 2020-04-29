#ifndef IModelControllerBase_
#define IModelControllerBase_
#include <QObject>
#include <QVector>
#include <QAbstractTableModel>
#include "RowItem.h"
#include "props.h"
#include <QSharedPointer>

//namespace controllers{

class IModelControllerBase: QObject
{

    Q_OBJECT
public:
    explicit IModelControllerBase(ItemEnums::EClientType type);

//    static IModelControllerBase &instance(){
//        static  IModelControllerBase instance;
//        return instance;
//    }



protected:
     ItemEnums::EClientType type_;

     IModelControllerBase *parent_;
     IModelControllerBase * child_;



private:
   // IModelControllerBase *model_;


};
//}
#endif // I_WidgetModelBase_H_
