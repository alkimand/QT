#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "myui.h"

#include <QMainWindow>
class QCalendarWidget;
class Creator;
class MyUI;

namespace Ui {
class MainWindow;
//class MyUI;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Creator;
signals:
    void testSignal();
    void setDate (const QDate&);
    void pathChanges(const QString &);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;
    Creator*  MyCreator;

private:

private slots:
    void debugSlot();
    void changeSliderSlot(int);
    void listWidgetDatechange(const QString &);
    void debugStringSlot(const QString &);
    void getPathFolder();
};

#endif // MAINWINDOW_H
