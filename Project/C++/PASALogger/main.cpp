#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QAbstractTableModel>
#include <QtQml>
#include "Server.h"
//#include "tablemodel.h"
#include "clientbase.h"
#include "clientudp.h"

#include "modelserviseudp.h"
#include "modelservisebaseclass.h"
//https://habr.com/ru/post/140899/
#include <QObject>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickWindow>
#include "clientudp.h"
int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(qml);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


//    QStringList paths = QCoreApplication::libraryPaths();
//    paths.append(".");
//    paths.append("imageformats");
//    paths.append("platforms");
    //paths.append("sqldrivers");
    //app.setQuitOnLastWindowClosed(false);
    //app.setAttribute(Qt::WA_DeleteOnClose);
    //app.setWindowIcon(QPixmap(":/src/images/AppImages/programmer.png"));
//++/0
//if (1)
//{
    //qmlRegisterType<TableModel>("TableModel", 1, 0, "TableModel");
    app.setOrganizationName("PASA");
    app.setOrganizationDomain("PASA");
    app.setApplicationName("UDP Loger Application");
    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;
//}
   // Server server(&app);
    //ModelServiseBaseClass



    //engine.rootContext()->setContextProperty("someModel", &someModel);
    qmlRegisterType <ModelServiseUDP> ("ModuleName", 1, 0, "ModelServiseUDP");
    qmlRegisterType<ClientUDP>("com.ics.demo", 1, 0, "ClientUDP");


    //ClientUDP *base = new ClientUDP();
    QQmlEngine engine;
    QQmlComponent *component = new QQmlComponent(&engine);
    component->loadUrl(QUrl("main.qml"));
    //ModelServiseBaseClass *model = new ModelServiseUDP();
    //int d1 = 0;
    //QString name  = "testmodel";
    //name.append(QString("%1").arg(d1));
    //QString name = "testmodel"+"1";
    //engine.rootContext()->setContextProperty(name, model);

    //




    QObject::connect(&engine, SIGNAL(quit()), QCoreApplication::instance(), SLOT(quit()));



    if (!component->isReady() ) {
        qWarning("%s", qPrintable(component->errorString()));
        return -1;
    }

    QObject *topLevel = component->create();
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    QSurfaceFormat surfaceFormat = window->requestedFormat();
    window->setFormat(surfaceFormat);
    window->show();
    delete component;








    return app.exec();







   // return app.exec();
}
//#include "main.moc"
