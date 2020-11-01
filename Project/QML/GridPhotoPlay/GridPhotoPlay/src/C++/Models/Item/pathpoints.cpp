#include <QGraphicsPathItem>
#include <functional>
#include <vector>
#include <QTime>
#include <qmath.h>
#include <QPen>
#include <QPainter>
#include <Item/random_points.h>
#include <Item/pathpoints.h>
namespace  point_utilities {

void randomizePoints(QVector<QPoint>::iterator from,
                     QVector<QPoint>::iterator to,
                     const QPoint range) {
    for (auto it = from; it != to; ++it) {
        *it = getNear(*it, range);
    }
}

void randCurvePath(SidePointsConteiner& path) {
    if (rand()%2)
        return;

    if (path.type == SidePointsConteiner::Type::HorizontalZigZag) {
        for (auto &point : path.points)
            point.setY(-point.y());
    }
    if (path.type == SidePointsConteiner::Type::VerticalZigZag) {
        for (auto &point : path.points)
            point.setX(-point.x());
    }
}

SidePointsConteiner verticalPath(int width, int height) {
    width = height/5;
    QPoint middle(width/2, height/2);

    QPoint zigzagSize(width/10, height/10);
    QPoint zigzagSize1(width/6, height/6);
    QPoint zigzagSize2(width/4, height/3);

    const QPoint range(width/20, height/20);

    SidePointsConteiner path;
    path.type = SidePointsConteiner::Type::VerticalZigZag;

    path.points = {
        QPoint(0, 0),
        QPoint(0, middle.y()-zigzagSize.y()),

        QPoint(-width + zigzagSize2.x(), middle.y()-zigzagSize2.y()),
        QPoint(-width + zigzagSize1.x(), middle.y()-zigzagSize1.y()),
        QPoint(-width + zigzagSize.x(), middle.y()-zigzagSize.y()),
        QPoint(-width, middle.y()),
        QPoint(-width + zigzagSize.x(), middle.y()+zigzagSize.y()),
        QPoint(-width + zigzagSize1.x(), middle.y()+zigzagSize1.y()),
        QPoint(-width + zigzagSize2.x(), middle.y()+zigzagSize2.y()),

        QPoint(0, middle.y()+zigzagSize.y()),

        QPoint(0,height)
    };

    randomizePoints(path.points.begin() + 2, path.points.end() - 2, range);
    randCurvePath(path);

    return path;
}

SidePointsConteiner horizontalPath(int width, int height)  {
    height = height/5;

    QPoint middle(width/2, height/2);

    QPoint zigzagSize(width/10, height/10);
    QPoint zigzagSize1(width/6, height/6);
    QPoint zigzagSize2(width/4, height/4);

    const QPoint range(width/20, height/20);

    SidePointsConteiner path;
    path.type = SidePointsConteiner::Type::HorizontalZigZag;

    path.points = {
        QPoint(0,0),
        QPoint(middle.x()-zigzagSize.x(), 0),
        QPoint(middle.x()-zigzagSize2.x(), zigzagSize2.y()-height),
        QPoint(middle.x()-zigzagSize1.x(), zigzagSize1.y()-height),
        QPoint(middle.x()-zigzagSize.x(), zigzagSize.y()-height),
        QPoint(middle.x(), -height),

        QPoint(middle.x()+zigzagSize.x(), zigzagSize.y()-height),
        QPoint(middle.x()+zigzagSize1.x(), zigzagSize1.y()-height),
        QPoint(middle.x()+zigzagSize2.x(), zigzagSize2.y()-height),
        QPoint(middle.x()+zigzagSize.x(), 0),
        QPoint(width, 0)
    };

    randomizePoints(path.points.begin() + 2, path.points.end() - 2, range);
    randCurvePath(path);

    return path;
}

SidePointsConteiner horizLinePath(int width) {
    SidePointsConteiner path;
    path.type = SidePointsConteiner::Type::HorizontalLine;

    path.points = {
        QPoint(0,0),
        QPoint(width, 0)
    };

    return path;
}

SidePointsConteiner vertLinePath(int height) {
    SidePointsConteiner path;
    path.type = SidePointsConteiner::Type::VerticalLine;

    path.points = {
        QPoint(0,0),
        QPoint(0, height)
    };

    return path;
}

QSize pathSize(SidePointsConteiner &path) {
    auto sign = [](int value)->int { return value < 0 ? -1 : 1;};

    auto xCompare = [](QPoint a, QPoint b)->bool { return a.x() < b.x(); };
    auto yCompare = [](QPoint a, QPoint b)->bool { return a.y() < b.y(); };

    auto minMaxX = std::minmax_element(path.points.begin(), path.points.end(), xCompare);
    auto minMaxY = std::minmax_element(path.points.begin(), path.points.end(), yCompare);

    return QSize((minMaxX.second->x() - minMaxX.first->x()) * sign(minMaxX.first->x()),
                 (minMaxY.second->y() - minMaxY.first->y()) * sign(minMaxY.first->y()));
}

void createVerticalPoints (QPixmap& source, QHash <eType, SidePointsConteinerMatrix> &vertical_points, size_t rows, size_t column) {
    int indent = 50;
    const int colVert_m = column + 1;
    const int colVert_n = rows;
    int width = source.width()/column;
    int height = source.height()/rows;

    QHash<eType,SidePointsConteinerMatrix>::iterator it;
    for (it = vertical_points.begin(); it != vertical_points.end();++it) {
        if (it.key()== eType::kBody) {}
        else if (it.key()== eType::kBorder) {
            width = width - indent;
            height = height - indent;
        }
        else
            return;
        it.value().resize(rows);
        for (int i = 0; i < colVert_n; i++) {
            it.value()[i].resize(colVert_m);
            for (int j = 0; j < colVert_m; j++)
                if (j == 0 || (j == colVert_m - 1))
                    it.value()[i][j] = vertLinePath(height);
                else
                    it.value()[i][j] = verticalPath(width, height);
        }

    }
}

void createHorizontalPoints (QPixmap& source, QHash<eType, SidePointsConteinerMatrix> &horizontal_points, size_t row, size_t column) {
    int indent = 50;
    int colHoriz_n = row + 1;
    int colHoriz_m = column + 1;
    int width = source.width()/column;
    int height = source.height()/row;

    QHash<eType,SidePointsConteinerMatrix>::iterator it;
    for (it = horizontal_points.begin(); it != horizontal_points.end();++it) {
        if (it.key()== eType::kBody) {

        }
        else if (it.key()== eType::kBorder){
            width = width - indent;
            height = height - indent;
        }
        else
            return;
        it.value().resize(colHoriz_n);
        for (int i = 0; i < colHoriz_n; i++) {
            it.value()[i].resize(colHoriz_m);
            for (int j = 0; j < colHoriz_m; j++)
                if (i == 0 || i == colHoriz_n - 1)
                    it.value()[i][j] = horizLinePath(width);
                else
                    it.value()[i][j] = horizontalPath(width, height);
        }
    }
}
}
