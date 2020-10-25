#include <Item/puzzlegame.h>
#include <Item/itemground.h>
#include <Item/random_points.h>
//#include <mainmenubutton.h>
#include <Item/puzzlematrix.h>
#include <Item/settableitem.h>
#include <QGridLayout>
#include <QPushButton>
#include <QSpacerItem>

PuzzleGame::PuzzleGame(QWidget* parent)
  : QWidget(parent),
    m_scene(), m_view(&m_scene),
    m_selectionLayer(1),
    m_sound({
      Animal(":/icons/pets/cat.png", "qrc:/sounds/pets/cat.ogg"),
      Animal(":/icons/pets/dog.png", "qrc:/sounds/pets/dog.ogg"),
      Animal(":/icons/pets/fish.png", ""),
      Animal(":/icons/pets/hen.png", "qrc:/sounds/pets/hen.ogg"),
      Animal(":/icons/pets/mouse.png", "qrc:/sounds/pets/mouse.ogg")
    }, this), m_label(this) {

  QGridLayout *grid = new QGridLayout(this);
  setLayout(grid);

  grid->addWidget(&m_view,1,0,1,2);

  grid->addWidget(&m_sound,2,0,1,2);

//  MainMenuButton *rotate = new MainMenuButton("rotate", this);
//  grid->addWidget(rotate,3,0);

//  MainMenuButton *back = new MainMenuButton("back", this);
//  back->setIcon(QIcon(":/icons/back.ico"));
//  grid->addWidget(back,3,1);


  grid->addWidget(&m_label,3,0);

//  connect(back, SIGNAL(clicked()), this, SIGNAL(back()));
  //connect(rotate, SIGNAL(clicked()), this, SLOT(rotate90()));
}

void PuzzleGame::load(QPixmap& source,
                      size_t n_rows,
                      size_t n_columns,
                      bool rotated) {
  m_scene.clear();
  m_view.viewport()->update();

  auto background = new QGraphicsPixmapItem(source);

  m_scene.addItem(background);
  background->setPos(0,0);
  background->setOpacity(0.2);

  m_unsetted = n_rows*n_columns;

  auto puzzlePathes = getPuzzlePathes(source, n_rows, n_columns);

  const size_t
      ImageH = source.height(),
      ImageW = source.width(),
      h = ImageH / n_rows,
      w = ImageW / n_columns;

  auto puzzleMatrix = createPuzzles(source, puzzlePathes);

  QPoint upperBound(-w, -h), lowerBound(ImageW + w, ImageH + h);

  for (size_t i = 0; i < puzzleMatrix.size(); ++i) {
    auto& row = puzzleMatrix[i];
    for (size_t j = 0; j < row.size(); ++j) {
      auto& puzzleItem = row[j];
      auto itemGround = new ItemGround(QRectF(j*w, i*h, w, h));

      puzzleItem->setRotatable(rotated);

      m_scene.addItem(puzzleItem);
      m_scene.addItem(itemGround);

      itemGround->setZValue(GroundLayer);
      puzzleItem->setZValue(m_selectionLayer);

      puzzleItem->setPos(getBetween(upperBound, lowerBound));
      puzzleItem->set_randomRotate();

      connect(puzzleItem, SIGNAL(clicked()), SLOT(onItemClicked()));
      connect(puzzleItem, SIGNAL(setted()), SLOT(onItemSetted()));
      connect(&m_view, SIGNAL(change_scalefactor()),
              puzzleItem, SLOT(clear_selection()));
    }
  }

  m_view.fitInView(QRectF(-w, -h, 2*w+ImageW, 2*h+ImageH), Qt::KeepAspectRatio);
  m_view.centerOn(0,0);
  m_view.show();
  m_view.update();
}

void PuzzleGame::rotate90() {
  m_view.rotate(90);
}

void PuzzleGame::onItemClicked() {
  ++m_selectionLayer;

  static_cast<SettableItem*>(sender())->setZValue(m_selectionLayer);
}

void PuzzleGame::onItemSetted() {
  m_sound.play();
  --m_unsetted;
  if (0 == m_unsetted) {
    emit finished(true);
  }
}
