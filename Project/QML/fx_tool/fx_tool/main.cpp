#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "borderradiuswidget.h"
#include "AppDataProvider.h"
#include "ItemModelBase.h"


//https://doc.qt.io/qt-5/qqmlengine.html#qmlRegisterSingletonType
int main(int argc, char *argv[]) {

    Q_INIT_RESOURCE(Icons);
    Q_INIT_RESOURCE(qml);

    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");

    QGuiApplication gui_app(argc, argv);

    gui_app.setAttribute(Qt::AA_UseSoftwareOpenGL);
    gui_app.setAttribute(Qt::AA_EnableHighDpiScaling);
    gui_app.setAttribute(Qt::AA_UseDesktopOpenGL);

    QGuiApplication::setLibraryPaths(paths);
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
