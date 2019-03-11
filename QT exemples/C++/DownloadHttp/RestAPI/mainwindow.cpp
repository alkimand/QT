#include "mainwindow.h"
#include "requester.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    Requester req(this);
    //nullptr
    req.initRequester("127.0.0.1",1500, nullptr);
     req.sendRequest()


}
