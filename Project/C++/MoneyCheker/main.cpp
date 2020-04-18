#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "borderradiuswidget.h"
#include <QObject>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickWindow>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<BorderRadiusWidget>("BorderRadiusWidget.qml", 1, 0, "BorderRadiusWidget");
    qmlRegisterSingletonType( QUrl("qrc:/src/QML/Setting/Settings.qml"), "Settings", 1, 0, "Settings" );


    //app.setWindowIcon(QIcon(":/src/images/AppImages/programmer.png"));
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
