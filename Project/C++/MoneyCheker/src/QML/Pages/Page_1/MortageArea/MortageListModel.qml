import QtQuick 2.12
import QtQuick.Controls 2.12

import Settings 1.0
import "../../../CommonElements/OneRowItem/RowLogic.js" as RowLogic


ListModel {
    id:root

    property var userTextAreaModels : Settings.userTextAreaModels.monthlyPayment;
    
    Component.onCompleted: {


        root.append({
                        "firstRowText_m":root.userTextAreaModels[0],
                        "value_m": 1255555555,
                        "type_m": Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY,
                        "textType_m": RowLogic.DataType.CURRENCY_DATA_TYPE,
                        "hasBorder_m": Settings.HasBorder.BOTTOM_BORDER,
                    });

        root.append({
                        "firstRowText_m":root.userTextAreaModels[1],
                        "value_m": 12252,
                        "type_m": Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY,
                        "textType_m": RowLogic.DataType.CURRENCY_DATA_TYPE,
                        "hasBorder_m": Settings.HasBorder.BOTTOM_BORDER,
                    });

        root.append({
                        "firstRowText_m":root.userTextAreaModels[2],
                        "value_m": 2525,
                        "type_m": Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY,
                        "textType_m": RowLogic.DataType.CURRENCY_DATA_TYPE,
                        "hasBorder_m": Settings.HasBorder.BOTTOM_BORDER,
                    });

        root.append({
                        "firstRowText_m":root.userTextAreaModels[3],
                        "value_m": 2525,
                        "type_m": Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY,
                        "textType_m": RowLogic.DataType.CURRENCY_DATA_TYPE,
                        "hasBorder_m": Settings.HasBorder.BOTTOM_BORDER,
                    });

        root.append({
                        "firstRowText_m":root.userTextAreaModels[4],
                        "value_m": 2525,
                        "type_m": Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY,
                        "textType_m": RowLogic.DataType.CURRENCY_DATA_TYPE,
                        "hasBorder_m": Settings.HasBorder.NO_BORDER,
                    });

       //console.log(root.get(0).value_m);
          //console.log("ListModel onCompleted");
    }

}



