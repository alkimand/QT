#ifndef PROPS_H
#define PROPS_H

#include <QObject>
#include "ItemConstant.h"

#include <QAbstractTableModel>

#define  LOOGGER(text)                     qDebug()<< className + QString::fromUtf8(__func__) + ":: " + text;

#define INT2QS(value)                      QString::number(value);

typedef QSharedPointer<QAbstractTableModel> p_model;
typedef std::map<std::string, std::string>  FileData;

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
        kNone = -1,
        kId ,
        kStatus,
        kFilePath,
        kFileName,
        kIcon,
        kDateLastSaved,
        kFormat,
    };

    Q_ENUM(EItemProperty)

  enum eItemStatus {
       kInit = -1,
       kDetected,
       kParsing,
       kParsed,
       kRemoving,
       kParseError
        };

    Q_ENUM(eItemStatus)

    enum EModelType {
        Calculator = 0,
        CALC_CENTER_WIDGET_
    };
    Q_ENUM(EModelType)

    enum EClientType {
        kNone_ = -1,
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
