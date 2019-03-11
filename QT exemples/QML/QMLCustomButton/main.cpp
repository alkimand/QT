#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;                           // Создаём движок qml
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));     // И загружаем в него исходники
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
