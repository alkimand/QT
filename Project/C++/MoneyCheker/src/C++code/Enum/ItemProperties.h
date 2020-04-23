#ifndef STYLE_HPP
#define STYLE_HPP
#include <QObject>


//https://stackoverflow.com/questions/20089196/how-to-access-c-enum-from-qml


//#include <QtGlobal>
//#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
//    // Qt 4
//    #include <QDeclarativeEngine>
//#else
//    // Qt 5
//    #include <QQmlEngine>
//#endif

// Required derivation from QObject
//class ItemProperty : public QObject
//{
//    Q_OBJECT

//    public:
//        // Default constructor, required for classes you expose to QML.
//        ItemProperty() : QObject() {}

//        Q_NAMESPACE
//        enum e_ItemProperty
//        {
//            STYLE_RADIAL = 1,
//            STYLE_ENVELOPE,
//            STYLE_FILLED
//        };
//        Q_ENUM_NS(e_ItemProperty)

//        // Do not forget to declare your class to the QML system.
//        static void declareQML() {
//            qmlRegisterType<ItemProperty>("ItemProperty", 1, 0, "ItemProperty");
//        }


//namespace C_Enums
//{
//    Q_NAMESPACE         // required for meta object creation
//    enum e_ItemProperty {
//        STYLE_RADIAL,
//        STYLE_ENVELOPE,
//        STYLE_FILLED
//    };
//    Q_ENUM_NS(e_ItemProperty)  // register the enum in meta object data
//}

//namespace MyNamespace
//{
//Q_NAMESPACE         // required for meta object creation
//enum EnStyle
//{
//    STYLE_RADIAL,
//    STYLE_ENVELOPE,
//    STYLE_FILLED
//};
//Q_ENUMS(EnStyle) // register the enum in meta object data
//}

class Info : public QObject
{
    Q_OBJECT
public:
    enum State {
        Information,
        Debug,
        Warning,
        Error
    };
    Q_ENUM(State)
};


//};

#endif    // STYLE_HPP
