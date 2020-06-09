#ifndef PROPS_H
#define PROPS_H

#include <QObject>
#include "ItemConstant.h"

#include <QAbstractTableModel>
typedef QSharedPointer<QAbstractTableModel> p_model;

class ItemEnums : public QObject
{
    Q_OBJECT
public:

//    enum ETableRoles
//    {
//        kTextAlightment_ = 0,
//        kButtonCount_,
//        UI_WIDGET_BUTTON_TYPE_ROLE,

//        TEXT_1_TYPE_ROLE,
//        TEXT_2_TYPE_ROLE,
//        TEXT_3_TYPE_ROLE,

//        TEXT_1_VALUE_ROLE,
//        TEXT_2_VALUE_ROLE,
//        TEXT_3_VALUE_ROLE,


//    };

//    Q_ENUM(ETableRoles)

    enum EItemProperty {
        kTextAlightment = 0,
        kButtonCount,
        kButtonType,

        kTextType_1,
        kTextType_2,
        kTextType_3,

        kTextValue_1,
        kTextValue_2,
        kTextValue_3

    };

    Q_ENUM(EItemProperty)

    enum EModelType {
        Calculator = 0,
        CALC_CENTER_WIDGET_
    };
    Q_ENUM(EModelType)

    enum EClientType {
        kNone = -1,
        kMortageLoanCalculator = 0
    };
    Q_ENUM(EClientType)


    enum ETextAlightment {
        kLeft = 0,
        kRight = 1
    };
    Q_ENUM(ETextAlightment)


    enum ETextType {
        kPersent = 1,
        kCurrensy = 2
    };
    Q_ENUM(ETextType)


};

#endif // PROPS_H
