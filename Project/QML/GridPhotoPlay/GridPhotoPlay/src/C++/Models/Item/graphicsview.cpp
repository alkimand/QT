//#include <Iten/graphicsview.h>
//#include <puzzlematrix.h>
//#include <settableitem.h>
//#include <selectableitem.h>
//#include <puzzleitem.h>
//#include <rotatableitem.h>

#include <Item/graphicsview.h>

GraphicsView::GraphicsView(QGraphicsScene *scene)
  : QGraphicsView(scene) {
//  grabGesture(Qt::PinchGesture);
//  setAttribute(Qt::WA_AcceptTouchEvents);
// // setTransformationAnchor(AnchorViewCenter);

//  setViewportMargins(0, 0, 0, 0);
//  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

bool GraphicsView::event(QEvent *event) {
  if (event->type() == QEvent::Gesture)
    return gestureEvent(static_cast<QGestureEvent*>(event));
  return QGraphicsView::event(event);
}

bool GraphicsView::gestureEvent(QGestureEvent *event) {
  qDebug() << "gestureEvent";
  if (QGesture *pinch = event->gesture(Qt::PinchGesture))
    pinchTriggered(static_cast<QPinchGesture *>(pinch));
  return true;
}

void GraphicsView::pinchTriggered(QPinchGesture* pinch) {
//  if (pinch->state() == Qt::GestureUpdated) {
//    auto scaleValue = pinch->scaleFactor();
//    scale(scaleValue, scaleValue);
//    emit change_scalefactor();
//  }
}

void GraphicsView::mousePressEvent(QMouseEvent *event) {
//  auto item = dynamic_cast<SettableItem*>(itemAt(event->pos()));
//  if (item && false == item->is_setted()) {
//    setInteractive(true);
//    setDragMode(QGraphicsView::DragMode::NoDrag);
//  }
//  else {
//    setInteractive(false);
//    setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
//  }
//  QGraphicsView::mousePressEvent(event);
}
