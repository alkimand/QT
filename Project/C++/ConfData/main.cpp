#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(sourse);
    QApplication a(argc, argv);

    MainWindow w;
    //w.setWindowIcon(QPixmap(":/sourse/images_button/icon.png"));
    w.show();

    return a.exec();
}
