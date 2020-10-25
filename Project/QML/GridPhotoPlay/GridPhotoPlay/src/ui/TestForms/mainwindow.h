#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <Item/graphicsview.h>

QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
   // Ui::MainWindow *ui;
    QGraphicsScene m_scene;
    GraphicsView m_view;

};
#endif // MAINWINDOW_H
