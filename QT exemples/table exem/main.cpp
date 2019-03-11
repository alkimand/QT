#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <database.h>
#include <model.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Инициализируем базу данных
    DataBase database;
    // Объявляем и инициализируем модель представления данных
    Model *model = new Model();
    /* Поскольку Мы отнаследовались от QSqlQueryModel, то
     * для выборки данных нам необходимо выполнить SQL-запрос,
     * в котором мы выберем все необходимы поля из нужной нам таблицы
     * */
    model->setQuery("SELECT " TABLE_DATE ", " TABLE_TIME ", " TABLE_RANDOM ", " TABLE_MESSAGE
                   " FROM " TABLE);

    /* А это уже знакомо из уроков по сигналам и слотам в QML
     * Помещаем полученную модель в контекст QML, чтобы была возможность
     * обращаться к модели по имени "myModel"
     * */
    engine.rootContext()->setContextProperty("myModel", model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
