#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "borderradiuswidget.h"
#include "AppDataProvider.h"
#include "ItemModelBase.h"

//https://doc.qt.io/qt-5/qqmlengine.html#qmlRegisterSingletonType
int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QGuiApplication gui_app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterSingletonType( QUrl("qrc:/src/qml/Action/Actions.qml"), "Actions", 1, 0, "Actions" );
    qmlRegisterType<BorderRadiusWidget>("BorderRadiusWidget.qml", 1, 0, "BorderRadiusWidget");
    qmlRegisterType<ItemModelBase>("ItemModelBase", 1, 0, "ItemModelBase");
    qmlRegisterType<AppDataProvider>("AppDataProvider", 1, 0, "AppDataProvider");

    gui_app.setOrganizationName("test");
    gui_app.setOrganizationDomain("test");

    AppDataProvider app;
    engine.rootContext()->setContextProperty("app_data", &app);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &gui_app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return gui_app.exec();
}
