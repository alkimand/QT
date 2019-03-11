#include "widget.h"
#include <QApplication>

//https://github.com/EXLMOTODEV/NetworkManagerDemo
//http://slproweb.com/products/Win32OpenSSL.html

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
