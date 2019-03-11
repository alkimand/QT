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

//http://www.forum.crossplatform.ru/index.php?showtopic=6311&st=10 делеат

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(qrc);
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("sqldrivers");
    QCoreApplication::setLibraryPaths(paths);

    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);

    MainForm form;
    form.setWindowIcon(QPixmap(":/sourse/buttons/icon.png"));
    //form.resize(1800, 800);
    form.setAttribute(Qt::WA_DeleteOnClose);
    form.show();

   // app.setAttribute(Qt::WA_DeleteOnClose);
   // Qt::WA_DeleteOnClose;
    return app.exec();
}
