#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "borderradiuswidget.h"
#include <QtQml> // Подключить QtQml для использования qmlRegisterType
#include <QObject>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickWindow>

#include "CalculatorArea_Model_1.h"

//#include "../../C++/MoneyCheker/src/C++code/Models/I_WidgetModelBase.h"
//#include "ItemProperties.h"

#include "props.h" // Подключить заголовочный файл класса Info
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QApplication app(argc, argv);






    qmlRegisterType<ItemEnums>("info", 1, 0, "Info");

    QQmlApplicationEngine engine;

    qmlRegisterType<BorderRadiusWidget>("BorderRadiusWidget.qml", 1, 0, "BorderRadiusWidget");
    qmlRegisterSingletonType( QUrl("qrc:/src/QML/Setting/Settings.qml"), "Settings", 1, 0, "Settings" );
   // ItemProperty::declareQML();

//    qmlRegisterUncreatableMetaObject(
//      e_ItemProperty::staticMetaObject, // static meta object
//      "e_ItemProperty",                // import statement (can be any string)
//      1, 0,                          // major and minor version of the import
//      "C_Enums",                 // name in QML (does not have to match C++ name)
//      "Error: only enums"            // error in case someone tries to create a MyNamespace object
//    );


//     qmlRegisterUncreatableMetaObject(
//      MyNamespace::staticMetaObject, // static meta object
//      "my.namespace",                // import statement (can be any string)
//      1, 0,                          // major and minor version of the import
//      "MyNamespace",                 // name in QML (does not have to match C++ name)
//      "Error: only enums"            // error in case someone tries to create a MyNamespace object
//    );


    CalculatorWidgetModel someModel(ItemEnums::e_ModelType::CALC_CENTER_WIDGET);
    engine.rootContext()->setContextProperty("someModel", &someModel);


    //app.setWindowIcon(QIcon(":/src/images/AppImages/programmer.png"));
   // app.setApplicationName("UDP Loger Application");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
