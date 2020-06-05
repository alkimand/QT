#include "borderradiuswidget.h"
#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>
#include <QtMath>
#include <QDebug>

BorderRadiusWidget::BorderRadiusWidget(QQuickItem *parent) :
    QQuickItem(parent),
    m_activeButtonColor(Qt::red),
    m_needUpdate(true) {
    setFlag(QQuickItem::ItemHasContents);
    setAcceptedMouseButtons(Qt::AllButtons);
}

QSGNode *BorderRadiusWidget::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData) {

    Q_UNUSED(updatePaintNodeData)
    m_CircleNode = static_cast<QSGGeometryNode *>(oldNode);

    if(!m_CircleNode) {
        int stargAngle = 180;
        int finishAngle = 270;
        m_CircleNode = new QSGGeometryNode;
        QSGGeometry *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), (finishAngle - stargAngle + 2));
        geometry->setDrawingMode(GL_POLYGON  );
        drawPartOfCircle(stargAngle, finishAngle, *geometry);

        m_CircleNode->setFlag(QSGNode::OwnsGeometry);
        m_CircleNode->setFlag(QSGNode::OwnsMaterial);
        QSGFlatColorMaterial* borderNonActiveMaterial = new QSGFlatColorMaterial();
        borderNonActiveMaterial->setColor(m_activeButtonColor);
        m_CircleNode->setGeometry(geometry); 
        m_CircleNode->setMaterial(borderNonActiveMaterial);
    }
//    else {
//       // root->markDirty(QSGNode::DirtyGeometry);
//        //m_borderActiveNode->markDirty(QSGNode::DirtyGeometry);
//        m_CircleNode->markDirty(QSGNode::DirtyMaterial);
//        m_CircleNode->markDirty(QSGNode::DirtyGeometry);
//            qDebug() << "mousePressEvent";

//    }

    if(m_needUpdate) {
              QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
              material->setColor(m_activeButtonColor);
              m_CircleNode->setMaterial(material);
              m_needUpdate = false;
    }

    return m_CircleNode;
}

QColor BorderRadiusWidget::activeButtonColor() const {
    return m_activeButtonColor;
}

QColor BorderRadiusWidget::disactiveButtonColor() const {
        return m_disactiveButtonColor;
}

int BorderRadiusWidget::radius() const {
        return m_borderRadius;
}

void BorderRadiusWidget::setActiveButtonColor(const QColor &color) {
    if(m_activeButtonColor != color) {
        m_activeButtonColor = color;
        m_needUpdate = true;
        update();
        ActiveButtonColorChanged();
    }
}

void BorderRadiusWidget::setDisactiveButtonColor(const QColor &color) {
    if(m_disactiveButtonColor != color) {
        m_disactiveButtonColor = color;
        m_needUpdate = true;
        update();
        ActiveButtonColorChanged();
    }
}

void BorderRadiusWidget::setRadius(const int &radius){
        if(m_borderRadius != radius) 
            m_borderRadius = radius;
}


void BorderRadiusWidget::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED( event );
    qDebug() << "mousePressEvent";
}

void BorderRadiusWidget::drawPartOfCircle(const int &startAngle, const int &finishAngle, QSGGeometry &geometry){
    geometry.vertexDataAsPoint2D()[0].set(0, 0);
    for (int i = 0; i <= (finishAngle - startAngle); ++i)    {
        double rad = qDegreesToRadians(double(startAngle + i));
        geometry.vertexDataAsPoint2D()[i+1].set(std::cos(rad) * m_borderRadius + 0, std::sin(rad) * m_borderRadius + 0);
    }
}
