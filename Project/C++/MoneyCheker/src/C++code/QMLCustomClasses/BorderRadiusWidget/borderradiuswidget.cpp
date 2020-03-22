#include "borderradiuswidget.h"
#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>
#include <QtMath>
#include <QDebug>

//https://evileg.com/ru/post/197/
//https://evileg.com/ru/post/296/

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
    QSGGeometryNode *root = static_cast<QSGGeometryNode *>(oldNode);

    if(!root) {
        int stargAngle = 180;
        int finishAngle = 270;
        root = new QSGGeometryNode;
        QSGGeometry *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), (finishAngle - stargAngle + 2));
        geometry->setDrawingMode(GL_POLYGON  );
        drawPartOfCircle(stargAngle, finishAngle, *geometry);

        //geometry->vertexDataAsPoint2D()[0].set(width() / 2, 0);
        //geometry->vertexDataAsPoint2D()[1].set(width(), height());
        //geometry->vertexDataAsPoint2D()[2].set(0, height());


        root->setFlag(QSGNode::OwnsGeometry);
        root->setFlag(QSGNode::OwnsMaterial);
        QSGFlatColorMaterial* borderNonActiveMaterial = new QSGFlatColorMaterial();
        borderNonActiveMaterial->setColor(m_activeButtonColor);
        root->setGeometry(geometry); // Установка геометрии
        root->setMaterial(borderNonActiveMaterial);
        //root->setFlags(QSGNode::OwnsGeometry|QSGNode::OwnsMaterial);
    }

    if(m_needUpdate) {
        //        QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
        //        material->setColor(m_color);
        //        root->setMaterial(material);
        //        m_needUpdate = false;
    }

    return root;
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
        // update();
        //   colorChanged();
    }
}

void BorderRadiusWidget::setDisactiveButtonColor(const QColor &color)
{
    if(m_disactiveButtonColor != color) {
        m_disactiveButtonColor = color;
        m_needUpdate = true;
        // update();
        //   colorChanged();
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
