#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>

#include <QQuickView>
#include <appdatacontroller.h>
#include "src/ui/TestForms/mainwindow.h"//--

//#include <item.h> //--

int main(int argc, char *argv[]) {

    Q_INIT_RESOURCE(Icons);
    Q_INIT_RESOURCE(qml);

    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");

    QGuiApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setLibraryPaths(paths);

    QGuiApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
    //QGuiApplication gui_app(argc, argv);

    //apps engine
    QApplication gui_app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterSingletonType( QUrl("qrc:/src/qml/Action/Actions.qml"), "Actions", 1, 0, "Actions" );
    //qmlRegisterType<BorderRadiusWidget>("BorderRadiusWidget.qml", 1, 0, "BorderRadiusWidget");
   // qmlRegisterType<AbstractTableItemData>("AbstractTableItemData", 1, 0, "AbstractTableItemData");
    qmlRegisterType<AppDataController>("AppDataController", 1, 0, "AppDataController");
    gui_app.setOrganizationName("MicrolabSystem");
    gui_app.setOrganizationDomain("MicrolabSystem");

   // AppDataController app(engine);
    AppDataController app;
    app.setApplicationEngine(engine);
    app.registerQMLType(0);
  //  MainWindow w;

    //Item *item = new Item("test.jpg",0);
   // item->load(5,5,false);

   // w.show();

    engine.rootContext()->setContextProperty("app_data", &app);
    //app.
   //engine.addImageProvider(QLatin1String("colors"), new PixmapController);
   // engine.addImageProvider(QLatin1String("tile"), new PixmapController);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &gui_app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return gui_app.exec();
}
