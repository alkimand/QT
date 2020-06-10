#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "borderradiuswidget.h"
#include "AppDataProvider.h"
#include "ItemModelBase.h"

//https://doc.qt.io/qt-5/qqmlengine.html#qmlRegisterSingletonType
int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterSingletonType( QUrl("qrc:/src/qml/Action/Actions.qml"), "Actions", 1, 0, "Actions" );
    qmlRegisterType<BorderRadiusWidget>("BorderRadiusWidget.qml", 1, 0, "BorderRadiusWidget");
    qmlRegisterType<ItemModelBase>("ItemModelBase", 1, 0, "ItemModelBase");

   // qmlRegisterSingletonType<AppDataProvider>("AppDataProvider", 1, 0, "AppDataProvider", AppDataProvider::registerSingleton);
    //AppDataProvider::registerSingleton_(&engine);

  // AppDataProvider app_data_provider_;

    //qmlRegisterSingletonType<AppDataProvider>("AppDataProvider", 1,0,"AppDataProvider",  qmlAppDataInterface);

   qmlRegisterType<AppDataProvider>("AppDataProvider", 1, 0, "AppDataProvider");

//    QSharedPointer<AbstractItem> obj =
//           QSharedPointer<AbstractItem>(new AbstractItem);
   // engine.rootContext()->setContextProperty("AppDataProvider", &app_data_provider_);
    //AppDataProvider temp();
   //AppDataProvider::registerSingleton_(&engine);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
