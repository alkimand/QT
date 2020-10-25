#ifndef GRAPHICSVIEW
#define GRAPHICSVIEW

#include <QGraphicsView>
#include <QPinchGesture>
#include <QGraphicsScene>
#include <QPinchGesture>
#include <QDebug>

class GraphicsView : public QGraphicsView {
  Q_OBJECT
public:
  GraphicsView(QGraphicsScene* scene);
signals:
  void gesture_started();
  void change_scalefactor();
protected:
  virtual bool event(QEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
private:
  bool gestureEvent(QGestureEvent *event);
  void pinchTriggered(QPinchGesture* pinch);
};

#endif // GRAPHICSVIEW
