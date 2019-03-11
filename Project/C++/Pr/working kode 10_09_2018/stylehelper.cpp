#include "stylehelper.h"
//https://evileg.com/ru/post/156/
StyleHelper::StyleHelper()
{

}
QString StyleHelper::getWindowStyleSheet()//+" background-image: url(1.jpg) 3 10 3 10;"" background-image: url(:\sourse\stellaris\MainPanel.jpg) 3 10 3 10;"
{
    return "QWidget { "
           "background-color: white; "
           " background-repeat: no-repeat"
           " background-image: url(:/sourse/stellaris/MainPanel.jpg) 3 10 3 10;"

           "}";
}

QString StyleHelper::getMainPanelStyleSheet()//"background-image: url(:/sourse/stellaris/MainPanel.jpg) 0 0 0 0 stretch stretch;"
//" background-repeat: no-repeat"
{
    return "QWidget { "
           ""
           "background-color: white; "
           "background-image: url(:/sourse/stellaris/MainPanel.jpg) 0 0 0 0 stretch stretch;"
           " background-repeat: no-repeat;"
           "}";
}
//https://forum.qt.io/topic/40151/solved-scaled-background-image-using-stylesheet/12
//no resize :(
QString StyleHelper::getContactsPanelStyleSheet()
{
    return "QWidget { "
           "background-color: white; "
           " background-image: url(:/sourse/stellaris/ContactsPanel.jpg) 0 0 0 0 stretch stretch;"
           " background-repeat: no-repeat;"
           "}";
}

QString StyleHelper::getVisitsPanelStyleSheet()//   " width:  400px;"  "background-size: cover;"
{
    return "QWidget { "
           "background-color: white; "
           " background-image: url(:/sourse/stellaris/VisitsPanel.jpg) 0 0 0 0 stretch stretch;"
           " background-repeat: no-repeat;"

           "}";
}



//#454545"background-color:red ; ""color: white; "border: 5px solid black; "



//#8f8f8f "background: #f6f7fa; "






//"border-style: none;"
//" border-bottom: 1px solid #fffff8;"
//"border-right: 1px solid #fffff8;"






//http://doc.crossplatform.ru/qt/4.6.x/stylesheet-examples.html#customizing-qtableview "border: 5px solid #e2e2de;" "color: #00008B;" background-image: url(1.jpg) 3 10 3 10;"" background-image: url(1.jpg) 3 10 3 10;"
QString StyleHelper::getQTableViewSheet()//"background: #0063cd; ""gridline-color: black;
{
    return "QTableView { "
           "background-color: white; "

           "color: #D2691E; "
           "font-size: 15px;"
           "border-style:none;"

           "}"

           "QTableView::item:selected {"

           "}"

           " QTableView::item { "

           "border: 1px solid #e2e2de; "

           " } "

           "QTableView::item:focus"
           "{  "

           "background: #0063cd; "
           "}"

           "QHeaderView::section {"
           "background-color: #A9A9A9;"
           "font-size: 15px;"
           "border-style: none;"
           "color: #2F4F4F; "
           "border: 1px solid #e2e2de; "
           "padding: 6px; "
           "}"
            ;
}//#8f8f8f "background: #f6f7fa; ""border: 2px outset black;""border-style:hidden;"#008080 "border-top : 5px solid black;" "border-bottom : 5px solid black ;":horizintal
//"color: red; "  "color: red;"
//"color: red; "
//"gridline-color: red;"
//" background: red;"

QString StyleHelper::getQSplitterSheet(){
    return "QSplitter::handle { "
           "background: 10px solid #00465F;"
           "border-radius: 5px;"
           "}";
}

QString StyleHelper::getQLineEditSheet()//" border-color:rgb(71, 73, 73);"
{
    return "QLineEdit { "
           "border-style: solid;"
           "background-color: black;"
           "border: none; "
           "border-width: 2px;"
           " color:white;"
           "font-size: 15px;"
           "font-family: 'Ubuntu';"
           "font-style: normal;"
           "}";
}

QString StyleHelper::getQLineEditTableWiewSheet()
{
    return "QLineEdit { "
           "border-style: solid;"
           "background: white;"
           "border: none; "
           "border-width: 2px;"
           "color:black;"
           "font-size: 15px;"
           "font-family: 'Ubuntu';"
           "font-style: normal;"
           "}";
}

//https://developer.mozilla.org/en-US/docs/Web/CSS/background-origin
//http://doc.crossplatform.ru/qt/4.5.0/stylesheet-examples.html#customizing-qpushbutton

//"background: #FFA500;"
//"color: blue; "
//
//"font-size: 15px;"

QString StyleHelper::getQPushbuttonAddSheet()//" background-size: 50px 50px;"
{
    return "QPushButton { "
           " border-image: url(:/sourse/Add_cont.png) 3 10 3 10;"

           "}";
}
//not used now, becose  no QSpinButton
QString StyleHelper::getQSpinButtonSheet()//"background-color: rgb(71, 73, 73);" " border-color:rgb(71, 73, 73);"
{
    return "QComboBox { "
           "background-color: red;"
           "border-color:rgb(71, 73, 73);"
           "border-style: solid;"
           "border-width: 2px;"
           "color:black;"
           "font-family: 'Ubuntu';"
           "font-style: normal;"
           "vertical-align:text-top;"
           "font-weight: 400;"
           "}";
}
//http://www.cyberforum.ru/qt/thread1678289.html  3 10 3 10;"
//"image: url(:/sourse/buttons/combobox/combo-box_icon.png) ;"
QString StyleHelper::getQComboboxSheet()
{
    return "QComboBox { "
           "background-color: white;"
           "border-color:rgb(71, 73, 73);"
           "border-style: solid;"
           "border-width: 2px;"
           "font-size: 15px;"
           "color:black;"
           "font-family: 'Ubuntu';"
           "font-style: normal;"
           "vertical-align:text-top;"
           "font-weight: 400;"
           "}"

           "QComboBox QListView{"
           "background-color:#EC6D00;"
           "border:1px solid red;"
           "color:#EC6D00;"
           "}";
}

QString StyleHelper::getQDateEditSheet()//"background-color: #00305A;" "background-color: red;""border-color:#00305A;""border-style: solid;"
{
    return "QDateEdit { "
           "background-color: white;"
           "border: none; "
           "color:white;"
           "font-family: 'Ubuntu';"
           "background: black;"
           "font-size: 15px;"

           "}"



           " QDateEdit::drop-down {"
           "}"
            ;
}

QString StyleHelper::getQDateEditTableWiewSheet()
{
    return  "QDateEdit { "
            "border-color:#00305A;"
            "border-style: solid;"
            "color:black;"
            "font-size: 15px;"
            "background: white;"
            "font-family: 'Ubuntu';"
            "}"
            ;
}

QString StyleHelper::getLabelStyleSheet()//#0074A2
{
    return "QLabel { "
           "color: #0074A2; "
           "background-color: black;"

           "border: none; "
           "font-size: 15px;"
           "margin: 15px,0; "
           "font-weight: bold"
           "}";
}








//" border-width: 50"  "color: grey;"" background: transparent; border: none;"
//background: red;"background: red; "
//"background: red; "   "border: 5px solid red; ""border: 5px solid red; " "border-right: 5px solid red;""background: 5px solid blue;""border: 3px solid blue; "


//"image: url(Add_cont.png);"
//"subcontrol-origin: padding;"
//"subcontrol-position: bottom right;"
//"border-top: 3px transparent;"
//"border-bottom: 3px transparent;"
//" border-right: 10px transparent;"
//"border-left: 10px transparent;"







//QString StyleHelper::getCloseStyleSheet()
//{
//    return "QToolButton { "
//           "image: url(:/buttons/close-orange.png);"
//           "background-color: #292929; "
//           "icon-size: 12px;"
//           "padding-left: 10px;"
//           "padding-right: 10px;"
//           "padding-top: 5px;"
//           "padding-bottom: 5px;"
//           "border: 1px solid #292929; "
//           "}"
//           "QToolButton:hover {"
//           "image: url(:/buttons/close.png); "
//           "}"
//           "QToolButton:pressed { "
//           "image: url(:/buttons/close.png);"
//           "background-color: #de8e37; "
//           "}";
//}

//QString StyleHelper::getMaximizeStyleSheet()
//{
//    return "QToolButton { "
//           "image: url(:/buttons/window-maximize-gray.png);"
//           "background-color: #292929;"
//           "icon-size: 12px;"
//           "padding-left: 10px;"
//           "padding-right: 10px;"
//           "padding-top: 5px;"
//           "padding-bottom: 5px;"
//           "border: 1px solid #292929; "
//           "}"
//           "QToolButton:hover {"
//           "image: url(:/buttons/window-maximize.png); "
//           "}"
//           "QToolButton:pressed { "
//           "image: url(:/buttons/window-maximize.png);"
//           "background-color: #de8e37; "
//           "}";
//}

//QString StyleHelper::getRestoreStyleSheet()
//{
//    return "QToolButton { "
//           "image: url(:/buttons/window-restore-gray.png);"
//           "background-color: #292929;"
//           "icon-size: 12px;"
//           "padding-left: 10px;"
//           "padding-right: 10px;"
//           "padding-top: 5px;"
//           "padding-bottom: 5px;"
//           "border: 1px solid #292929; "
//           "}"
//           "QToolButton:hover {"
//           "image: url(:/buttons/window-restore.png); "
//           "}"
//           "QToolButton:pressed { "
//           "image: url(:/buttons/window-restore.png);"
//           "background-color: #de8e37; "
//           "}";
//}

//QString StyleHelper::getMinimizeStyleSheet()
//{
//    return "QToolButton { "
//           "image: url(:/buttons/window-minimize-gray.png);"
//           "background-color: #292929;"
//           "icon-size: 12px;"
//           "padding-left: 10px;"
//           "padding-right: 10px;"
//           "padding-top: 5px;"
//           "padding-bottom: 5px;"
//           "border: 1px solid #292929; "
//           "}"
//           "QToolButton:hover { "
//           "image: url(:/buttons/window-minimize.png); "
//           "}"
//           "QToolButton:pressed { "
//           "image: url(:/buttons/window-minimize.png);"
//           "background-color: #de8e37; "
//           "}";
//}

//QString StyleHelper::getNextStyleSheet()
//{
//    return "QToolButton { "
//           "image: url(:/buttons/skip-next.png);"
//           "icon-size: 24px;"
//           "padding: 6px;"
//           "margin: 6px;"
//           "border: none;"
//           "}"
//           "QToolButton:pressed { "
//           "image: url(:/buttons/skip-next-orange.png)"
//           "}";
//}

//QString StyleHelper::getPreviousStyleSheet()
//{
//    return "QToolButton { "
//           "image: url(:/buttons/skip-previous.png);"
//           "icon-size: 24px;"
//           "padding: 6px;"
//           "margin: 6px;"
//           "border: none;"
//           "}"
//           "QToolButton:pressed { "
//           "image: url(:/buttons/skip-previous-orange.png)"
//           "}";
//}

//QString StyleHelper::getStopStyleSheet()
//{
//    return "QToolButton { "
//           "image: url(:/buttons/stop.png);"
//           "icon-size: 24px;"
//           "padding: 6px;"
//           "margin: 6px;"
//           "border: none;"
//           "}"
//           "QToolButton:pressed { "
//           "image: url(:/buttons/stop-orange.png)"
//           "}";
//}

QString StyleHelper::getPlayStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/play.png);"
           "icon-size: 48px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/play-orange.png)"
           "}";
}

QString StyleHelper::getPauseStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/pause.png);"
           "icon-size: 24px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/pause-orange.png)"
           "}";
}

QString StyleHelper::getMenuStyleSheet()
{
    return "QToolButton { "
           "color: #8f8f8f;"
           "background-color: #292929;"
           "icon-size: 12px;"
           "padding-left: 10px;"
           "padding-right: 10px;"
           "padding-top: 5px;"
           "padding-bottom: 5px;"
           "border: 1px solid #292929; "
           "}"
           "QToolButton:hover {"
           "color: white;"
           "}"
           "QToolButton:pressed { "
           "color: white; "
           "background-color: #de8e37; "
           "}";
}
//white
QString StyleHelper::getTableViewStyleSheet()
{
    return "QTableView { "
           "background-color: red; "
           "color: black; "
           "border: 5px solid #e2e2de;"
           "}"
           "QTableView::item:selected {"
           "background-color: #de8e37;"
           "}"
           "QHeaderView::section:horizintal {"
           "background-color: white;"
           "border-style: none;"
           "color: black; "
           "border: 5px solid #e2e2de; "
           "padding: 6px; "
           "}";
}
