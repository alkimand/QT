#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <item.h> //--

#include <QGridLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <Item/random_points.h>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), m_scene(), m_view(&m_scene) {

   QGridLayout *grid = new QGridLayout(this);
   setLayout(grid);

   grid->addWidget(&m_view,1,0,1,2);
   resize(740, 530);

//   Item *item = new Item("test.jpg",0);
//   item->load(5,5,false);

//   QPixmap source("test.jpg");

//   const size_t
//       ImageH = source.height(),
//       ImageW = source.width(),
//       h = ImageH / 5,
//       w = ImageW / 5;

//   TileMatrix puzzleMatrix = item->getTileMatrix();

//   QPoint upperBound(-w, -h);
//   QPoint lowerBound(ImageW + w, ImageH + h);

//   for (int i = 0; i < 5; ++i) {
//       int last_x =0;
//       int last_y=0;
//      // auto& row = puzzleMatrix[i];
//       QVector <Tile*> & row = puzzleMatrix[i];
//       //QVector <SettableItem*>
//       for (int j = 0; j < row.size(); ++j) {
//           Tile *puzzleItem = row[j];
//           //auto& puzzleItem = row[j];
//           //auto itemGround = new ItemGround(QRectF(j*w, i*h, w, h));

//           puzzleItem->setRotatable(false);

//           m_scene.addItem(puzzleItem);
//          // m_scene.addItem(itemGround);

//           //itemGround->setZValue(GroundLayer);
//           //puzzleItem->setZValue(m_selectionLayer);

//          //  puzzleItem->setPos(puzzleMatrix[i][j]->boundingRect().width(), i*h);
//          //  puzzleItem->setPos(puzzleMatrix[i][j]->boundingRect().width() * j, puzzleMatrix[i][j]->boundingRect().height()*i);
//          // puzzleItem->setPos(last_x, last_y);
//        puzzleItem->setPos(120*i, 120*j);
//           last_y+= puzzleMatrix[i][j]->boundingRect().height();
//         //   puzzleItem->setPos(puzzleMatrix[i][j]->boundingRect().width() * j, 150*i);
//           //puzzleItem->setPos(getBetween(upperBound, lowerBound));
//          // puzzleItem->set_randomRotate();

////           connect(puzzleItem, SIGNAL(clicked()), SLOT(onItemClicked()));
////           connect(puzzleItem, SIGNAL(setted()), SLOT(onItemSetted()));
////           connect(&m_view, SIGNAL(change_scalefactor()),
////                   puzzleItem, SLOT(clear_selection()));
//       }
//     //  last_x += puzzleMatrix[i][1]->boundingRect().width();
//   }//


    //QGraphicsScene scene;
    //scene.addText("Hello, world!");

   // QGraphicsView view(&scene);
   // view.show();



//   this->a
}

MainWindow::~MainWindow()
{
   // delete ui;
}

