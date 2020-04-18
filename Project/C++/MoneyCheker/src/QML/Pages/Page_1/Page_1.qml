import QtQuick 2.12
import QtQuick.Controls 2.12


import "../../ColumnWidget"
import Settings 1.0
import "../../Action"



    Item {
        id:root
//		anchors.fill: parent
		//anchors.left: stack.left

		ColumnWidget {

			id:space_calc
            anchors.left: parent.left
            columnWidgetType: Settings.ColumnWidgetType.CALCULATOR_SPACE
            width: Settings.appContentWidgetSettings.contentCalculatorPageWidth;
			actions: mainwindow.actions
		 }

		ColumnWidget {
			id: space_center
			anchors.left: space_calc.right
            columnWidgetType: Settings.ColumnWidgetType.EMPTY_SPACE
			width: 40;
			actions: mainwindow.actions
		}

        ColumnWidget {

            id:space_mortage
            anchors.left: space_center.right
            anchors.right: space_right.left
            columnWidgetType: Settings.ColumnWidgetType.MORTAGE_SPACE
            actions: mainwindow.actions

//            Rectangle{
//                id:rect
//                anchors.top:space_mortage.top
//                anchors.left:space_mortage.left
//                anchors.right: space_mortage.right
//                height:100
//                //width:100
//                color:"red"
//               // weidth:100

//            }

            //Component.onCompleted: {}
         }

        ColumnWidget {
            id: space_right
            anchors.right: parent.right
            columnWidgetType: Settings.ColumnWidgetType.EMPTY_SPACE
            width: 40;
           // rootReactClr:"red"
            actions: mainwindow.actions
        }
	}



