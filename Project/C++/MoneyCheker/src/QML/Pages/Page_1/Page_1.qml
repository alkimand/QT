import QtQuick 2.12
import QtQuick.Controls 2.12


import "../../ColumnWidget"
import "../../Setting"
import "../../Action"



    Item {
        id:root
//		anchors.fill: parent
		//anchors.left: stack.left

		ColumnWidget {

			id:space_calc
            anchors.left: parent.left
			columnWidgetType: SettingData.ColumnWidgetType.CALCULATOR_SPACE
            width: settingData.appContentWidgetSettings.contentCalculatorPageWidth;
			actions: mainwindow.actions
		 }

		ColumnWidget {
			id: space_center
			anchors.left: space_calc.right
			columnWidgetType: SettingData.ColumnWidgetType.EMPTY_SPACE
			width: 40;
			actions: mainwindow.actions
		}

        ColumnWidget {

            id:space_mortage
            anchors.left: space_center.right
            anchors.right: space_right.left
            columnWidgetType: SettingData.ColumnWidgetType.MORTAGE_SPACE
            actions: mainwindow.actions
            //Component.onCompleted: {}
         }

        ColumnWidget {
            id: space_right
            anchors.right: parent.right
            columnWidgetType: SettingData.ColumnWidgetType.EMPTY_SPACE
            width: 40;
           // rootReactClr:"red"
            actions: mainwindow.actions
        }
	}



