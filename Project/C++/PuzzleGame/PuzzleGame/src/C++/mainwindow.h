#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>
#include <QScopedPointer>

#include <QList>

#include "engine_helper.h"
#include <screen.h>

typedef  QSharedPointer<Screen> pScreen;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();


private:
    void Init();
    void createScreen(int &picture_id, QString image_path, int rows, int columns, bool is_rotated);


private:
    QSharedPointer <EngineHelper>   engine_;
    QList <pScreen>                app_data_;
    int screen_width_ = 500;
    int screen_height_ = 500;
//private slots:



   // void onAddNew();
};

#endif
