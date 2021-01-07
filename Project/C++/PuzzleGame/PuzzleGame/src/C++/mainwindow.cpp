
#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>

MainWindow::MainWindow()
{
    Init();

    engine_= QSharedPointer<EngineHelper>(new EngineHelper, &QObject::deleteLater);


    //connect(addNew, &QAction::triggered, this, &MainWindow::onAddNew);
    

 //   onAddNew();
}

//void MainWindow::onAddNew()
//{
//    if (!centralWidget())
//        setCentralWidget(new Window(this));
//    else
//        QMessageBox::information(0, tr("Cannot add new window"), tr("Already occupied. Undock first."));
//}


void MainWindow::Init() {
    QMenuBar *menuBar = new QMenuBar;
    QMenu *menuWindow = menuBar->addMenu(tr("&Window"));
    QAction *addNew = new QAction(menuWindow);
    addNew->setText(tr("Add new"));
    menuWindow->addAction(addNew);
    setMenuBar(menuBar);

    int item_id = 0;
    createScreen(item_id, "test.jpg", 10, 10, false);
}

void MainWindow::createScreen(int &picture_id, QString image_path, int rows, int columns, bool is_rotated) {
    picture_id = app_data_.size();
    Screen* screen = new Screen(image_path, picture_id, rows, columns, is_rotated, this);
    pScreen pscreen = pScreen(screen, &QObject::deleteLater);

    //user image
    screen->loadUserImage();
    screen->setScreenSize(screen_width_, screen_height_);

    //points
    screen->createPoints();
    screen->createPaths();
    screen->createTiles();
    //screen->setupModel();

    app_data_.push_back(pscreen);
}

MainWindow::~MainWindow() {
}

