import QtQuick 2.9
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
//import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
//import QtLocation 5.9
import QtGraphicalEffects 1.0
//https://coredump.su/questions/45117292/qml-tabview-and-tabbar-customization tabbar
//import "controls" as MyControls
//http://qaru.site/questions/8684025/extending-tabviewstyle-styledata
//http://qaru.site/questions/13091256/qml-qtquickcontrols-tabs-with-icons
import "../Style/Tab"

//https://doc.qt.io/QT-5/qml-qtquick-controls-styles-tabviewstyle.html
//right corner ToDo
TabViewStyle
{

    //https://colorscheme.ru/color-names.html
    //https://doc.qt.io/qt-5/qml-qtquick-controls-styles-tabviewstyle.html
    id:tabViewStyle
    //property int auxiliaryTabIndex: 0
    //property int tabMoveDirection: 0
    //property int movCoordinate: 0
    tabOverlap:0
    tabsMovable :true
    property string test:  "test TabViewStyle" //--
    tab:OneTabBaseStyle{id: oneTabBaseStyle}

    tabBar : Rectangle
    {
       // color:settingData.children[2].tabBarColorSetting
        gradient: Gradient.PerfectBlue
        border.width : 1
        border.color : "black"
        //https://doc.qt.io/qt-5/qgradient.html#Preset-enum
    }


}
