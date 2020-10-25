#ifndef PUZZLEITEM_H
#define PUZZLEITEM_H

#include <QGraphicsPixmapItem>
#include <QHash>
#include <QPixmap>
#include <Item/puzzlepath.h>

//! базовый класс пазла
class PuzzleItem : public QObject, public QGraphicsItem {
  Q_OBJECT
  Q_INTERFACES(QGraphicsItem)
public:
  PuzzleItem(PuzzlePath *path, const QPixmap& source, const QRect &rect,
             QObject *parent = nullptr);
  ~PuzzleItem() override;

  static QHash<int, QGraphicsPixmapItem> *pixel_map_;

  QRectF boundingRect() const override;
  void paint(QPainter *painter,
             const QStyleOptionGraphicsItem *option,
             QWidget *widget = nullptr) override;


private:
  QGraphicsPixmapItem* pixmap_item_;

protected:
  PuzzlePath* path_;
  QPixmap* user_pixmap_;
  QPixmap* pixmap_;
};

#endif // PUZZLEITEM_H
