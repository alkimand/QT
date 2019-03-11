#include "ui_mainwindow.h"
#ifndef MYUI_H
#define MYUI_H
//
#include "mainwindow.h"
#include <QMainWindow>
#include <QWidget>



class MyUI : public Ui::MainWindow
{
   // Q_OBJECT
public:
    MyUI();
public slots:
    void test();
   void debugSlot();


};

#endif // MYUI_H
