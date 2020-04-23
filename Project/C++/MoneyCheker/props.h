#ifndef PROPS_H
#define PROPS_H

#include <QObject>
#include "ItemConstant.h"

class ItemEnums : public QObject
{
    Q_OBJECT
public:

    enum e_TableRoles
    {
        UI_WIDGET_TEXT_ALIGHTMENT_ROLE,
        UI_WIDGET_BUTTON_COUNT_ROLE,
        UI_WIDGET_BUTTON_TYPE_ROLE,

        TEXT_1_TYPE_ROLE,
        TEXT_2_TYPE_ROLE,
        TEXT_3_TYPE_ROLE,

        TEXT_1_VALUE_ROLE,
        TEXT_2_VALUE_ROLE,
        TEXT_3_VALUE_ROLE,


    };

    Q_ENUM(e_TableRoles)

    enum e_ItemProps {


        ITEM_TEXT_ALIGHTMENT,
        ITEM_BUTTON_COUNT,
        ITEM_BUTTON_TYPE,

        ITEM_TEXT_1_TYPE,
        ITEM_TEXT_2_TYPE,
        ITEM_TEXT_3_TYPE,

        ITEM_TEXT_1_VALUE,
        ITEM_TEXT_2_VALUE,
        ITEM_TEXT_3_VALUE
    };

    Q_ENUM(e_ItemProps)

    enum e_ModelType {
        CALC_CENTER_WIDGET = 0,
        CALC_CENTER_WIDGET_
    };
    Q_ENUM(e_ModelType)

};

#endif // PROPS_H
