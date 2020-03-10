// Release_checker_app.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "fxtool.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <QStringList>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

void printUsage() {
    std::cout << "Usage:\n\
fx_tool.exe \"full file name\"" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        printUsage();
        return 
            0;
    }
   // QCoreApplication::addLibraryPath("./");
    //QApplication a(argc, argv);
    ////a.addLibraryPath("./");
    ////QCoreApplication::addLibraryPath("./");
    //FXTool w;
    //w.show(); 
    //return a.exec();
    //std::cout << "Hello World!\n"; 
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //const QUrl url(QStringLiteral("qrc:/main.qml"));
    //QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    //    &app, [url](QObject *obj, const QUrl &objUrl) {
    //    if (!obj && url == objUrl)
    //        QCoreApplication::exit(-1);
    //}, Qt::QueuedConnection);
    //engine.load(url);

    return app.exec();
    //QQmlContext *ctxt = view.rootContext();
    //ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    ////![0]

    //view.setSource(QUrl("qrc:view.qml"));
    //view.show();

    return app.exec();


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
