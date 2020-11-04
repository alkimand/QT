#ifndef ITEM_ENUMS_H
#define ITEM_ENUMS_H
#include <QObject>


   enum class EItemProperty {
        kNone = -1,
        kId ,
        kStatus,
        kFilePath,
        kFileName,
        kIcon,
        kDateLastSaved,
        kFormat
    };

 //  Q_ENUM(EItemProperty)

    enum eItemStatus {
        kStatusNone = -1,
        kDetected,
        kParsing,
        kParsed,
        kRemoving,
        kParseError,
        kSaveError
    };

    enum DATA_ID {
        FEATURE     = 0 ,
        FEATURE_NAME,
        IS_ACTIVE   ,
        NAME        ,
        ICON
        //    EDITE
    };

    enum MODEL_ROLES {
        DISPLAY     = 0 ,
        EDITE           ,
        IMAGE_SOURCE    ,
        BORDER_SOURCE   ,
        ID,
        ORIGIN_X,
        ORIGIN_Y,

    };


    enum eType {
        kBody,
        kBorder
    };

    //Q_ENUM(eItemStatus)
    

#endif // ITEM_ENUMS_H
