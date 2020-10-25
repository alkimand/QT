#include <Tile/rotatableitem.h>

void RotatableItem::set_center_rotation(int angle) {
  if (false == is_rotatable_)
    return;
  rotate_angle_ += angle;

  QRectF rect = mapToScene(this->boundingRect()).boundingRect();
  QPointF center = rect.center();

  QTransform t;
  t.translate(center.x(), center.y());
  t.rotate(angle);
  t.translate(-center.x(), -center.y());
  setPos(t.map(pos()));

  setRotation(rotation() + angle);
  rotate_angle_ %= 360;

  emit changed();
}


void RotatableItem::set_randomRotate() {
  if (false == is_rotatable_)
    return;
  int angle = (rand() % 4)*90;

  if (angle) {
    set_center_rotation(angle);
  }
}


//RotatableItem::~RotatableItem(){

//}
