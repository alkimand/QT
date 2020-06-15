#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "borderradiuswidget.h"
#include "AppDataProvider.h"
#include "ItemModelBase.h"

//https://doc.qt.io/qt-5/qqmlengine.html#qmlRegisterSingletonType
int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication gui_app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterSingletonType( QUrl("qrc:/src/qml/Action/Actions.qml"), "Actions", 1, 0, "Actions" );
    qmlRegisterType<BorderRadiusWidget>("BorderRadiusWidget.qml", 1, 0, "BorderRadiusWidget");
    //qmlRegisterType<ItemModelBase>("ItemModelBase", 1, 0, "ItemModelBase");

   // qmlRegisterType<AppModel>("AppModel", 1, 0, "AppModel");


    //qRegisterMetaType<AppModel*>("AppModel*");

   // qmlRegisterSingletonType<AppDataProvider>("AppDataProvider", 1, 0, "AppDataProvider", AppDataProvider::registerSingleton);
    //AppDataProvider::registerSingleton_(&engine);

  // AppDataProvider app_data_provider_;

    //qmlRegisterSingletonType<AppDataProvider>("AppDataProvider", 1,0,"AppDataProvider",  qmlAppDataInterface);

   qmlRegisterType<AppDataProvider>("AppDataProvider", 1, 0, "AppDataProvider");

    //QQuickView view;
    AppDataProvider app;
    //view.engine()->rootContext()->setContextProperty("app_data", &app_data_);
//    QSharedPointer<AbstractItem> obj =
//           QSharedPointer<AbstractItem>(new AbstractItem);
   // engine.rootContext()->setContextProperty("AppDataProvider", &app_data_provider_);
    //AppDataProvider temp();
   //AppDataProvider::registerSingleton_(&engine);
    engine.rootContext()->setContextProperty("app_data", &app);
//    QObject::connect(item, SIGNAL(qmlSignal(QString)),
//                     &myClass, SLOT(cppSlot(QString)));


//    QObject *item = engine.rootContext()-
    //QQuickView view(QUrl::fromLocalFile("qrc:/main.qml"));
   //QObject *item = view.rootObject();


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &gui_app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    QObject::connect(item, SIGNAL(appStart()),
//                     &app_data_, SLOT(appStart()));
    //view.show();



    return gui_app.exec();
}
