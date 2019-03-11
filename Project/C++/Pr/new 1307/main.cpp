//#include <QtGui>
#include <QtSql>
//#include <cstdlib>
#include <QtWidgets>
#include "mainform.h"
#include "mainform2.h"
//https://evileg.com/ru/post/67/
//https://evileg.com/ru/post/69/
//https://habr.com/post/51650/
//http://www.cyberforum.ru/qt/thread1707641.html
//https://andreyex.ru/bazy-dannyx/uchebnoe-posobie-po-sql/sql-foreign-key-vneshnij-klyuch/
//https://professorweb.ru/my/sql-server/2012/level2/2_6.php
//bool createConnection()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("Proizvodstvo.dat");
//    if (!db.open()) {
//        QMessageBox::warning(0, QObject::tr("Database Error"),
//                             db.lastError().text());
//        return false;
//    }
//    return true;
//}



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    bool existingData = QFile::exists("Proizvodstvo.dat");
//    if (!createConnection())
//        return 1;
//    if (!existingData)
//        createFakeData();

    MainForm form;
    form.resize(1800, 800);
    form.show();
    return app.exec();
}
