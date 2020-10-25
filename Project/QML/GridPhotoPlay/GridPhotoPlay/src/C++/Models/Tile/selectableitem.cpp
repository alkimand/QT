#include <Tile/selectableitem.h>

SelectableItem::~SelectableItem() {
  delete border_;
}

void SelectableItem::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option,
           QWidget *widget) {
  PuzzleItem::paint(painter, option, widget);
  if (border_)
    border_->paint(painter, option, widget);
}

void SelectableItem::mousePressEvent(QGraphicsSceneMouseEvent *) {
  emit clicked();
  set_selected(true, true);
}

void SelectableItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *) {
  set_selected(false, true);
}

void SelectableItem::set_selected(bool selection, bool need_update = false) {
  selection_ = selection;
  if (selection) {
    border_->setPen(SelectionPen);
  }
  else {
    border_->setPen(DefaultPen);
  }

  if (need_update)
    update();
}
