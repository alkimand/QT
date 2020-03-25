#include "borderradiuswidget.h"
#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>
#include <QtMath>
#include <QDebug>

//https://evileg.com/ru/post/197/
//https://evileg.com/ru/post/296/
//https://riptutorial.com/ru/qml/example/22330/%D1%81%D0%BE%D0%B7%D0%B4%D0%B0%D0%BD%D0%B8%D0%B5-%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D1%81%D0%BA%D0%B8%D1%85-%D1%8D%D0%BB%D0%B5%D0%BC%D0%B5%D0%BD%D1%82%D0%BE%D0%B2-%D0%B2-c-plusplus

BorderRadiusWidget::BorderRadiusWidget(QQuickItem *parent) :
    QQuickItem(parent),
    m_activeButtonColor(Qt::red),
    m_needUpdate(true)
{
    setFlag(QQuickItem::ItemHasContents);
    setAcceptedMouseButtons(Qt::AllButtons);
}

QSGNode *BorderRadiusWidget::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData)
{

    //QColor m_backgroundColor = Qt::red;
    //QColor m_backgroundColor = Qt::red;
    //QColor m_backgroundColor = Qt::red;  // выбираем цвет фона, ...
    Q_UNUSED(updatePaintNodeData)
    m_CircleNode = static_cast<QSGGeometryNode *>(oldNode);

    if(!m_CircleNode) {
        int stargAngle = 180;
        int finishAngle = 270;
        m_CircleNode = new QSGGeometryNode;
        QSGGeometry *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), (finishAngle - stargAngle + 2));
        geometry->setDrawingMode(GL_POLYGON  );
        drawPartOfCircle(stargAngle, finishAngle, *geometry);

        //geometry->vertexDataAsPoint2D()[0].set(width() / 2, 0);
        //geometry->vertexDataAsPoint2D()[1].set(width(), height());
        //geometry->vertexDataAsPoint2D()[2].set(0, height());


        m_CircleNode->setFlag(QSGNode::OwnsGeometry);
        m_CircleNode->setFlag(QSGNode::OwnsMaterial);
        QSGFlatColorMaterial* borderNonActiveMaterial = new QSGFlatColorMaterial();
        borderNonActiveMaterial->setColor(m_activeButtonColor);
        m_CircleNode->setGeometry(geometry); // Установка геометрии
        m_CircleNode->setMaterial(borderNonActiveMaterial);
        //root->setFlags(QSGNode::OwnsGeometry|QSGNode::OwnsMaterial);
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

QColor BorderRadiusWidget::activeButtonColor() const
{
    return m_activeButtonColor;
}

QColor BorderRadiusWidget::disactiveButtonColor() const
{
        return m_disactiveButtonColor;
}

int BorderRadiusWidget::radius() const
{
        return m_borderRadius;
}

void BorderRadiusWidget::setActiveButtonColor(const QColor &color)
{
    if(m_activeButtonColor != color) {
        m_activeButtonColor = color;
        m_needUpdate = true;
        update();
        ActiveButtonColorChanged();
    }
}

void BorderRadiusWidget::setDisactiveButtonColor(const QColor &color)
{
    if(m_disactiveButtonColor != color) {
        m_disactiveButtonColor = color;
        m_needUpdate = true;
        update();
        ActiveButtonColorChanged();
    }
}

void BorderRadiusWidget::setRadius(const int &radius)
{
        if(m_borderRadius != radius) {
            m_borderRadius = radius;
        }
}


void BorderRadiusWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent";
}

void BorderRadiusWidget::drawPartOfCircle(const int &startAngle, const int &finishAngle, QSGGeometry &geometry)
{
    //double rad = qDegreesToRadians(double(startAngle));
    geometry.vertexDataAsPoint2D()[0].set(0, 0);//start point
    for (int i = 0; i <= (finishAngle - startAngle); ++i)
    {
        double rad = qDegreesToRadians(double(startAngle + i));
        geometry.vertexDataAsPoint2D()[i+1].set(std::cos(rad) * m_borderRadius + 0, std::sin(rad) * m_borderRadius + 0);
    }
}
