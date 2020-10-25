#ifndef ROTATABLEITEM_H
#define ROTATABLEITEM_H

#include <Tile/selectableitem.h>


class RotatableItem : public SelectableItem {
  Q_OBJECT
  Q_INTERFACES(QGraphicsItem)
public:
  RotatableItem(PuzzlePath *path, const QPixmap& source, const QRect &rect,
              QObject *parent = nullptr) :
    SelectableItem(path, source, rect, parent),
    rotate_angle_(0), is_rotatable_(false)  {
  }

  void set_randomRotate();
  void set_center_rotation(int angle);
  int angle() { return rotate_angle_; }
signals:
  void changed();
protected:
  int rotate_angle_;
  bool is_rotatable_;
  private:
  //virtual ~RotatableItem();

};

#endif // ROTATABLEITEM_H
