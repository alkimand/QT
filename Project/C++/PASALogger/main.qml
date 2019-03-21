import QtQuick 2.12
import QtQuick.Window 2.11
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import "src"
import "src/ToolBar"
import "src/MenuBar"
import "src/TableView"
import "src/Setting"
import "src/TabView"
import "./src/Action"

//IDI_ICON1 ICON DISCARDABLE "icon.ico"
//http://doc.crossplatform.ru/qt/en/4.7.x/appicon.html icon
//https://icon-icons.com/ru/%D0%9F%D0%BE%D0%B8%D1%81%D0%BA/%D0%B8%D0%BA%D0%BE%D0%BD%D0%BA%D0%B8/?filtro=clear+32x32
//https://evileg.com/en/forum/topic/466/ -таблица
//https://icon-icons.com/ru/download/106322/PNG/32/
ApplicationWindow
{
    id: window
    //object SettingData to chage/restore setting Application

    SettingData{id: settingData}
    visible: true
    width: settingData.children[0].widthSetting
    height: settingData.children[0].heightSetting
    minimumWidth: settingData.children[0].minimumWidthSetting
    minimumHeight: settingData.children[0].minimumHeightSetting
    title:  settingData.children[0].appNameSetting

    //Text property
    //property int fontSize: settingData.children[1].fontSizeSetting


    //console.log("tabView.getTab(index).children[0].rowHeight = " + tabView.getTab(index).children[0].rowHeight)


    // minimumHeight: window.item.children[0].size
    // tabView.getTab(index).children[0].selectTab(2)
    //SettingData.appHeight
    //

    //title: SettingData.appName
    // title: SettingData.getAppPropertyGlobal()

    //property string appName: "UDP Logger Exemple"
    /// Rectangle
    // {
    //  anchors.fill: parent

    MessageDialog
    {
        id: aboutBox
        title: "About Text"
        text: "Need more text there"
        icon: StandardIcon.Information
    }


    FileDialog
    {
        id: fileDialog
        nameFilters: ["Text files (*.txt)", "HTML files (*.html, *.htm)"]
        onAccepted: {
            if (fileDialog.selectExisting)
                document.fileUrl = fileUrl
            else
                document.saveAs(fileUrl, selectedNameFilter)
        }
    }

    ColorDialog
    {
        id: colorDialog
        title :"ColorDialog"
        color: "red"
        //        onColorChanged:
        //        {//console.log("ColorChanged" +colorDialog.color )}
        //            color: colorDialog.color
        //        }
    }

    Actions{id:actions}

    //https://www.iconfinder.com/iconsets/32x32-free-design-icons
    menuBar: MenuBar{id:mainMenuBar}
    header: ToolBar {id:mainToolBar}
    //footer: TabView {id:tabView}
    //toolBar:mainToolBar
    TabView
    {
        id:tabView

//        id:tabView
//        anchors.topMargin:  0
//        anchors.top:mainToolBar.Bottom
    }

   // footer:StatusBar{id:statusBar}
    function dounloadFunc()
    {

        console.log(settingData.size)
        //console.log(window.item.children[0].size)
        //console.log(window.children[0].item.size)
        //console.log(window.item.children[0].item.size)
        // console.log("tro lo lo")
    }

}
