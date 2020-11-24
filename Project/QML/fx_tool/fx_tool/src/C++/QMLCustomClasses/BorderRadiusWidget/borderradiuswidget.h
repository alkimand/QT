#ifndef BORDERRADIUSWIDGET_H
#define BORDERRADIUSWIDGET_H

#include <QObject>
#include <QQuickItem>

#include <QSGGeometryNode>

class BorderRadiusWidget: public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QColor activeButtonColor READ activeButtonColor WRITE setActiveButtonColor NOTIFY ActiveButtonColorChanged)
    Q_PROPERTY(QColor disactiveButtonColor READ disactiveButtonColor WRITE setDisactiveButtonColor)// NOTIFY colorChanged)
    Q_PROPERTY(int radius READ radius WRITE setRadius)// NOTIFY colorChanged)
public:
    BorderRadiusWidget(QQuickItem *parent = Q_NULLPTR);
protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *updatePaintNodeData);

    QColor activeButtonColor() const;
    QColor disactiveButtonColor() const;
    int radius() const;
    void setActiveButtonColor(const QColor &color);
    void setDisactiveButtonColor(const QColor &color);
    void setRadius(const int &radius);
    void mousePressEvent(QMouseEvent *event);

private:
    QColor m_activeButtonColor;
    QColor m_disactiveButtonColor;
    QColor m_backgroundColor;
    int m_borderRadius;
    bool isActive;
    bool m_needUpdate;

private:
    QSGGeometryNode* m_CircleNode = nullptr;
    void drawPartOfCircle(const int  &startAngle, const int &finishAngle, QSGGeometry &geometry);

signals:
    void ActiveButtonColorChanged();
};

#endif // BORDERRADIUSWIDGET_H
