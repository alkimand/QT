import QtQuick 2.12

ChoiceItemBase
{
    id:control
    property string test: "+"
    Component.onCompleted:
    {

       // control.rectangle.listView.listModel
        //control.rectangle.listView.listModel.append({idshnik: "Button 1"})
        //listModel.append({idshnik: "Button 2"})
        control.setButtonModel("Text logger")
        control.setButtonModel("UDP logger")
    }
}
