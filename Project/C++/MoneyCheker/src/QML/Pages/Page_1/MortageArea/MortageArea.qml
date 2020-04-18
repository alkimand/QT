import QtQuick 2.12
import QtQuick.Controls 2.12

import "../../../Action"
import Settings 1.0
import "../../../CommonElements/OneRowItem/MoneyCheker"
import "../../../CommonElements/OneRowItem/RowLogic.js" as RowLogic
import "../../../CommonElements/SpecialRowWidget"

Item {
    id:root
    // property Actions actions : parent.actions
    //property int radius : parent.actions


   property int rowTextBlockWidth:Settings.elementsMortagePage.textBlockWidth;

    Component {
        id:rowBorder
        Rectangle {
            height:Settings.elementsMortagePage.distanceBetweenRow;
           // color: Settings.columnSettings.columnFreeSpaceColor;
            color:"red"
        }
    }


    SpecialRowWidget_O {
        id:home_prise_row
        anchors.top:parent.top
        anchors.left:parent.left
        anchors.right: parent.right
    }

//    Loader {
//        id:border_1
//        sourceComponent: itemBorder
//        anchors.top:home_prise_row.bottom
//        anchors.left:parent.left
//        anchors.right:parent.right
//    }

//    OneRowItem_S {
//        id: preincipal_row
//        anchors.top:border_1.bottom
//        anchors.left:parent.left
//        anchors.right: parent.right
//        value: 8255578
//        textBlockWidth : root.rowTextBlockWidth
//        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
//        type: Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY;
//        textFirstLine: "Principal & interest"
//    }

//    Loader {
//        id:border_2
//        sourceComponent: itemBorder
//        anchors.top:preincipal_row.bottom
//        anchors.left:parent.left
//        anchors.right:parent.right
//    }

//    OneRowItem_S {
//        id: tax_row
//        anchors.top:border_2.bottom
//        anchors.left:parent.left
//        anchors.right: parent.right
//        value: 58
//        textBlockWidth : root.rowTextBlockWidth
//        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
//        type: Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY;
//        textFirstLine: "Property tax"
//    }

//    Loader {
//        id:border_3
//        sourceComponent: itemBorder
//        anchors.top:tax_row.bottom
//        anchors.left:parent.left
//        anchors.right:parent.right
//    }

//    OneRowItem_S {
//        id: insurance_row
//        anchors.top:border_3.bottom
//        anchors.left:parent.left
//        anchors.right: parent.right
//        value: 10721
//        textBlockWidth : root.rowTextBlockWidth
//        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
//        type: Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY;
//        textFirstLine: "Property insuranse"
//    }

//    Loader {
//        id:border_4
//        sourceComponent: itemBorder
//        anchors.top:insurance_row.bottom
//        anchors.left:parent.left
//        anchors.right:parent.right
//    }

//    OneRowItem_S {
//        id: pmi_row
//        anchors.top:border_4.bottom
//        anchors.left:parent.left
//        anchors.right: parent.right
//        value: 5894
//        textBlockWidth : root.rowTextBlockWidth
//        textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
//        type: Settings.OneRowItemType.TWO_TEXT_LEFT_TEXT_AND_TEXT_RIGHT_ONLY;
//        textFirstLine: "PMI"
//    }

//    Loader {
//        id:border_5
//        sourceComponent: itemBorder
//        anchors.top:pmi_row.bottom
//        anchors.left:parent.left
//        anchors.right:parent.right
//    }


    StackView {
        id: mortage_Stack
        //initialItem: mortage_StackPage_1

        //  anchors.top:home_prise_row__.bottom

        anchors.left:parent.left
        anchors.right:parent.right
        anchors.top:parent.top
        anchors.bottom:parent.bottom
       // height: Settings.oneRowItemSettings.rowItemHeight*20;
        //popEnter : Transition{}
        //        popExit : Transition{}
        pushEnter : Transition{NumberAnimation { target: mortage_Stack; property: "opacity"; from: 0; to: 1; duration: 800 }}
        popEnter: Transition {
            NumberAnimation { target: mortage_Stack; property: "opacity"; from: 1; to: 0; duration: 600 }
        }

        popExit: Transition {}
        //        NumberAnimation { target: mortage_Stack; property: "opacity"; from: 0; to: 1; duration: 400 }
        //        }

        //            XAnimator {
        //                from: 0
        //                to: (mortage_Stack.mirrored ? -1 : 1) * control.width
        //                duration: 1000
        //                easing.type: Easing.OutCubic
        //                // console.log("XAnimator")

        //            }
        ////            onStart{
        ////                console.log("XAnimator")
        ////            }
        //        }

        pushExit : Transition{}
        replaceEnter : Transition{}
        replaceExit : Transition{}

        Component.onCompleted: {
            //  mortage_Stack.pop(calculator_StackPage_2, calculator_StackView.Immediate)

            //mortage_Stack.push(mortage_StackPage_1)
            //mortage_Stack.push(calculator_StackPage_2)
            //mortage_Stack.pop(calculator_StackView.Immediate)
        }

    }

    //Rows

    Component {
        id:mortage_StackPage_1
        Item{
            id:itemcalculator_StackPage_1
            //anchors.fill: parent
            SpecialRowWidget_O {
                id:home_prise_row
                anchors.top:parent.top
                anchors.left:parent.left
                anchors.right: parent.right
//                //anchors.fill: parent
//                value: 1210010
//                textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
//                textSecondLineType: RowLogic.DataType.PERSENT_DATA_TYPE;
//                type: Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
//                textFirstLine: "Home prise"
            }


//            Loader {
//                id:border_1
//                sourceComponent: itemBorder
//                anchors.top:home_prise_row.bottom
//                anchors.left:parent.left
//                anchors.right:parent.right
//            }


//            Connections {
//                target: start_date_row
//                onOpenRowView: {
//                    // console.log("start_date_row onOpenView")
//                    itemcalculator_StackPage_1.moveAllActiveElementsToBack()
//                    start_date_row.z = 1;
//                }
//            }

//            Connections {
//                target: amortization_row
//                onOpenRowView: {
//                    // console.log("start_date_row onOpenView")
//                    itemcalculator_StackPage_1.moveAllActiveElementsToBack()
//                    amortization_row.z = 1;
//                }
//            }

//            function moveAllActiveElementsToBack(){
//                start_date_row.z = 0;
//                amortization_row.z = 0;
//            }
        }
    }

    //    Component{
    //        id:calculator_StackPage_2
    //        Item {
    //            id:itemcalculator_StackPage_2
    //            //anchors.fill: parent
    //            OneRowItem_S {
    //                id:loan_row
    //                anchors.top:parent.top
    //                anchors.left:parent.left
    //                anchors.right: parent.right
    //                value: 1210010
    //                textType: RowLogic.DataType.CURRENCY_DATA_TYPE//Settings.DataType.CURRENCY_DATA_TYPE;
    //                type: Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
    //                textFirstLine: "Loan"
    //            }


    //            Loader {
    //                id:border_2_0
    //                sourceComponent: itemBorder
    //                anchors.top:loan_row.bottom
    //                anchors.left:parent.left
    //                anchors.right:parent.right
    //            }

    //            OneRowItem_S {
    //                id:rate_loan_row
    //                anchors.top:border_2_0.bottom
    //                anchors.left:parent.left
    //                value: 4.5
    //                type: Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
    //                textType:RowLogic.DataType.PERSENT_DATA_TYPE;
    //                textFirstLine: "Rate"
    //            }

    //            Loader {
    //                id:border_2_1
    //                sourceComponent: itemBorder
    //                anchors.top:rate_loan_row.bottom
    //                anchors.left:parent.left
    //                anchors.right:parent.right
    //            }

    //            OneRowItem_S {
    //                id:term_loan_row
    //                anchors.top:border_2_1.bottom
    //                anchors.left:parent.left
    //                value: 23
    //                type: Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_TWO_BUTTON_RIGHT;
    //                textType:RowLogic.DataType.YERS_DATA_TYPE;
    //                textFirstLine: "Term"
    //            }

    //            Loader {
    //                id:border_2_2
    //                sourceComponent: itemBorder
    //                anchors.top:term_loan_row.bottom
    //                anchors.left:parent.left
    //                anchors.right:parent.right
    //            }

    //            OneRowItem_S {
    //                id:start_date_loan_row
    //                //anchors.top:button_1.bottom
    //                anchors.top:border_2_2.bottom//border_7
    //                // anchors.top:button_1.bottom
    //                anchors.left:parent.left
    //                value : { return new Date()}
    //                type: Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_DATE_COMBOBOX_ONLY_LEFT_COMBOBOX_ALIGNEMENT;
    //                // textType:RowLogic.DataType.DATE_DATA_TYPE;
    //                //        valueArr: Settings.userTextModels.persentDownTextModel;
    //                textFirstLine: "Start date"
    //            }

    //            Loader {
    //                id:border_2_3
    //                sourceComponent: itemBorder
    //                anchors.top:start_date_loan_row.bottom
    //                anchors.left:parent.left
    //                anchors.right:parent.right
    //            }

    //            OneRowItem_S {
    //                id:amortization_loan_row
    //                anchors.top:border_2_3.bottom//border_7
    //                // anchors.top:button_1.bottom
    //                anchors.left:parent.left
    //                value: 0
    //                type: Settings.OneRowItemType.ONE_TEXT_LEFT_TEXT_AND_COMBOBOX_ONLY_LEFT_COMBOBOX_ALIGNEMENT;
    //                //textType: RowLogic.DataType.YERS_DATA_TYPE;
    //                textFirstLine: "Amortization"
    //                hasBorder: Settings.HasBorder.BOTTOM_BORDER
    //                valueArr: Settings.userTextModels.armortizationTextModel;
    //            }

    //            Connections {
    //                target: start_date_loan_row
    //                onOpenRowView: {
    //                   // console.log("start_date_row onOpenView")
    //                    itemcalculator_StackPage_2.moveAllActiveElementsToBack()
    //                    start_date_loan_row.z = 1;
    //                }
    //            }

    //            Connections {
    //                target: amortization_loan_row
    //                onOpenRowView: {
    //                   // console.log("start_date_row onOpenView")
    //                    itemcalculator_StackPage_2.moveAllActiveElementsToBack()
    //                    amortization_loan_row.z = 1;
    //                }
    //            }

    //            function moveAllActiveElementsToBack(){
    //                start_date_loan_row.z = 0;
    //                amortization_loan_row.z = 0;
    //            }


    //        }
    //    }



















    //Update TabButton
    //    function updateTabButton(){
    //        button_1.update();
    //        //console.log("button_1.update()");
    //        button_2.update();
    //        //console.log("button_2.update()");
    //    }



}



