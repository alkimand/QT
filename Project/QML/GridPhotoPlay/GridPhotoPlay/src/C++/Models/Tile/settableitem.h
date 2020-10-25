#ifndef SETTABLEITEM_H
#define SETTABLEITEM_H

#include <Tile/movableitem.h>

//! установка Фрагмента в ячейки
class SettableItem : public MovableItem {
  Q_OBJECT
  Q_INTERFACES(QGraphicsItem)
public:
  SettableItem(PuzzlePath *path, const QPixmap& source, const QRect &rect,
               QPointF correct_corner_possition,
               QObject *parent = nullptr) :
    MovableItem(path, source, rect, parent),
    correct_corner_possition_(correct_corner_possition),
    stable_distation_(std::min(rect.height(), rect.width()) / 4.f),
    setted_(false) {
    connect(this, SIGNAL(changed()), this, SLOT(onChanged()));
  }

  void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
    if (setted_)
      return;
    MovableItem::mousePressEvent(event);
  }
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override {
    if (setted_)
      return;
    MovableItem::mouseMoveEvent(event);
  }
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override {
    if (setted_)
      return;
    MovableItem::mouseReleaseEvent(event);
  }

  bool is_setted() { return setted_; }

  void setRotatable(bool rotatable) {
    is_rotatable_ = rotatable;
  }
private slots:
  void onChanged();
signals:
  void setted();
protected: //private
  QPointF correct_corner_possition_;
  const float stable_distation_;
  bool setted_;
};

#endif // SETTABLEITEM_H
