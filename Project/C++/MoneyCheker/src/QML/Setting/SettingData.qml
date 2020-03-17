import QtQuick 2.0

Item {
    //children[0]
    Item
    {
        id:appPropertyGlobal
        property string appNameSetting: "UDP Logger Exemple"
        property int widthSetting: 1000
        property int heightSetting: 800
        property int minimumWidthSetting: 100
        property int minimumHeightSetting: 100
    }

    //children[1] //global for tableview and header
    Item
    {
        id:appPropertyText
        property int fontSizeSetting: 15
        property string fontfamilySetting: "Arial Black"
        property int horizontalAlignmentSetting:  Text.AlignHCenter
    }

    //children[2]
    Item
    {
        id:appPropertyTab
        property color tabBorderColorSetting: "black" //border
        //
        property color tabRectangleColorIsSelictedSetting:"white" //"#F6F6F7" //rectangle color on tab
        property string tabRectangleColorIsNotSelictedSetting: "#C9CCD9"//"#de3636"//"#A9A9A9" //rectangle color on tab
        //
        property color tabBarColorSetting: "#9ACEEB" //rectangle there is no tab (plase right tab)TabViewStyle:tabBar
        property color tabBarTextColorSetting: "black" //rectangle TabViewStyle:tabBar

        property color tabBarRectColorIfSelectingStartSetting: "#B83669"//"#77a9ef"//"#2877D1"//"#9ACEEB"

        property string tabPanelColorSetting: "#A9A9A9" //white" //dont use yet
        property string tabBorderRectColorSetting: "black" //white"
        property string tabOneTabTextFontSetting: "Arial Narrow"
        property string tabSaveButtonIconSetting: "./../../../images/ToolBarIcon/filesave.png"
        property string tabCloseButtonIconSetting: "./../../../images/ToolBarIcon/close.png"
        property int tabBorderReactangleWidthSetting: 1 //use on border rectangle (4 reactangle in each corner)
        property int tabBorderWidthSetting: 0
        property int tabIndentSetting: 25 //Indent fore math implicitWidth of tab
        property int tabimplicitHeightSetting: 30
        property int tabOneTabHeightSetting: 35 //border
        property int tabOneTabTextHeightSetting: 8
        property int tabButtonImageHeightSetting: 18 //18x18


    }


    //https://evileg.com/en/post/314/ enym

    //children[3]
    Item
    {

        id:appPropertyToolBar
        //property bool toolBarIsIconSetting: true //-> to  get toolBarStateToolButtonSetting //toDo
        //property bool toolBarIstextSetting: true //-> to  get toolBarStateToolButtonSetting
        property int toolBarStateToolButtonSetting: SettingData.ToolBarToolButtonState.TOOLBAR_TOOLBUTTON_ICON_TEXT //appPropertyToolBar.toolBarStateToolButtonSetting.
        property int toolBarHeightToolButtonSetting: 50
        property int toolBarWidthToolButtonSetting: 50
        property int toolBarTextHeightToolButtonSetting: 8
        property int toolBarIconHeightSetting: 25
        property string toolBarSourceIconSetting: "../images/ToolBarIcon/"// ToDo
        property string toolBarTextFontToolButtonSetting:"Arial Narrow"
        property color toolBarButtonIsSelectedColorSetting: "#77a9ef"
        property color toolBarButtonIsNotSelectedColorSetting: "white"

    }

    //children[4]
    Item
    {
        //toolBarCobobox
        id:appPropertyCombobox
        property int comboBoxWidthSetting: 170
        property int comboBoxHeightSetting: 40
        property int comboBoxTextHeightSetting: 12
        property string comboBoxTextColor: "black"
        property string comboBoxBorderColor: "#0f4ba8"


    }

    //children[5]
    Item
    {
        //TableView - Header
        id:appPropertyTableViewHeaderDelegat
        property color tableViewhHederDelegatBackgroundColorSetting: "black"//"#75ccca"//"white"
        property int tableViewhHeighSetting: 80
        property int tableViewhWidthSetting: 150
        property int tableViewhHederDelegatBorderWidthSetting: 2
        property int tableViewhHederDelegatBorderMoveAreaWidthSetting: 2
        property color tableViewhHederDelegatBorderMoveAreaColorSetting: "red"
        property color tableViewhHederDelegatBorderColorSetting:"black"
        // property color tableViewhHederDelegatBorderColorSetting:"black"
        property color tableViewhHederDelegatTextColorSetting: "black"
        property color tableViewhHederDelegatBuckgroundColorSetting: "white"
        property string tableViewhHederTextFontSetting: "Arial Narrow"
        property int tableViewhHederTextPointSizeSetting: 12
        property bool tableViewhHederTextBoltSetting: true
        property int tableViewhHederTextHorizontalAlignmentSetting: Text.AlignHCenter
        property int tableViewhHederTextVerticalAlignmentSetting: Text.AlignVCenter
        property int tableViewhHederImageHeightSetting: 18 //18x18
        property string tableViewhHederImageFilterIconSetting: "./../../../images/TableViewIcon/filter.png"
        property string tableViewhHederImageFilterAddIconSetting: "./../../../images/TableViewIcon/filterAdd.png"
        property string tableViewhHederImageFilterDeleteIconSetting: "./../../../images/TableViewIcon/filterDelete.png"

        property string tableViewhHederImageSortAscendingIconSetting: "./../../../images/TableViewIcon/sort_ascending.png"
        property string tableViewhHederImageSortDescendingIconSetting: "./../../../images/TableViewIcon/sort_descending.png"


        //        property int comboBoxTextHeightSetting: 12
        //        property string comboBoxTextColor: "black"
        //        property string comboBoxBorderColor: "#0f4ba8"

        //children[6]




    }
    Item
    {
        property string t2ableViewhHederImageSortDescendingIconSetting: "./../../../images/TableViewIcon/sort_descending.png"
        //TableView - item
        property color tableViewhRowDelegatSelectColorSetting: "#00C919"

        //#00C919
        //ToDo

    }




    //children[7]
    Item
    {
        //Contex Menu
        property int contextMenuBaseImplicitWidthSetting: 200
        property int contextMenuBaseImplicitHeightSetting: 40
        property color contextMenuBaseBorderColorSetting : "#77a9ef"
        property color contextMenuBaseTextHighlightedColorSetting : "#ffffff"
        property color contextMenuBaseTextNoHighlightedColorSetting : "black"
        property color contextMenuBorderColorSetting : "#ffffff"
        property color contextMenuBaseItemColorSetting : "#deeef9"
        property string contextMenuBaseTextFontSetting: "Cambria Math"
        property int contextMenuBaseTextSizeSetting: 15
        property int contextMenuBaseIconSizeSetting: 25
    } 
	
    property var buttonSettings: Item {
		id:buttonSettings_
        property color buttonIsNotSelectedColorSetting: "#f1f1f1"
		property color buttonIsSelectedColorSetting: "#ffffff"
        property int buttonHeight: 80
		property int buttonWidth: 80 //not all place knows to take this value 
        property int buttonRadius: 10
        property int buttonMargin: 18 // Leaving space between image and borders (optional)
	
	}
    
        property var appContentWidgetSettings: Item {

        property int contentCalculatorPageWidth: 70 // Leaving space between image and borders (optional)
	
	}
	
	    property var columnSettings: Item {
		id:columnSettings_
        property color columnFreeSpaceColor: "#dfdfdf"
		//property color buttonIsSelectedColorSetting: "white"
        property int titleBlockHeight: 70 //height of title text block like "calculator"
		property int spaceBetweenButton: 20

	}
	
    enum ToolBarToolButtonState
    {
        TOOLBAR_TOOLBUTTON_ICON = 1,
        TOOLBAR_TOOLBUTTON_TEXT = 2,
        TOOLBAR_TOOLBUTTON_ICON_TEXT = 3
    }

    enum ColumnWidgetType {
        EMPTY_SPACE = 1,
        BUTTON_SPACE = 2,
        CALCULATOR_SPACE = 3,
        MORTAGE_SPACE = 4
    }



    function getAppPropertyGlobal()
    {
        return appName
    }

}

