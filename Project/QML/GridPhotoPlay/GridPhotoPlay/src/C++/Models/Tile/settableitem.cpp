#include <Tile/settableitem.h>

void SettableItem::onChanged() {
  if (angle())
    return;
  if (QLineF(this->scenePos(), correct_corner_possition_).length() < stable_distation_) {
    setPos(correct_corner_possition_);
    setted_ = true;
    emit setted();
    setZValue(0);
  }
}
