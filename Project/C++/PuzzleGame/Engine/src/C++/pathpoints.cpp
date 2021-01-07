#include <QGraphicsPathItem>
#include <functional>
#include <vector>
#include <QTime>
#include <qmath.h>
#include <QPen>
#include <QPainter>
#include <QDebug>

#include <random_points.h>
#include <pathpoints.h>
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

    if (path.type == SidePointsConteiner::eLineType::HorizontalZigZag) {
        for (auto &point : path.points)
            point.setY(-point.y());
    }
    if (path.type == SidePointsConteiner::eLineType::VerticalZigZag) {
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
    path.type = SidePointsConteiner::eLineType::VerticalZigZag;

    path.points = {
        //QPoint(0, 0),
        //QPoint(0, middle.y()-zigzagSize.y()),

        //QPoint(-width + zigzagSize2.x(), middle.y()-zigzagSize2.y()),
        //QPoint(-width + zigzagSize1.x(), middle.y()-zigzagSize1.y()),
        //QPoint(-width + zigzagSize.x(), middle.y()-zigzagSize.y()),
        //QPoint(-width, middle.y()),
        //QPoint(-width + zigzagSize.x(), middle.y()+zigzagSize.y()),
        //QPoint(-width + zigzagSize1.x(), middle.y()+zigzagSize1.y()),
        //QPoint(-width + zigzagSize2.x(), middle.y()+zigzagSize2.y()),

        //QPoint(0, middle.y()+zigzagSize.y()),

        //QPoint(0,height)
    };

    randomizePoints(path.points.begin() + 2, path.points.end() - 2, range);
    randCurvePath(path);

    return path;
}

SidePointsConteiner verticalPath_border(const SidePointsConteiner &source, int const indent) {
    SidePointsConteiner path;
    path.type = SidePointsConteiner::eLineType::VerticalZigZag;
    for (auto point : source.points){
        point.setY(point.y() - indent);
        path.points.push_back(point);

    }
    path.points[0].setY(0);
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
    path.type = SidePointsConteiner::eLineType::HorizontalZigZag;

    path.points = {
        //QPoint(0,0),
        //QPoint(middle.x()-zigzagSize.x(), 0),
        //QPoint(middle.x()-zigzagSize2.x(), zigzagSize2.y()-height),
        //QPoint(middle.x()-zigzagSize1.x(), zigzagSize1.y()-height),
        //QPoint(middle.x()-zigzagSize.x(), zigzagSize.y()-height),
        //QPoint(middle.x(), -height),

        //QPoint(middle.x()+zigzagSize.x(), zigzagSize.y()-height),
        //QPoint(middle.x()+zigzagSize1.x(), zigzagSize1.y()-height),
        //QPoint(middle.x()+zigzagSize2.x(), zigzagSize2.y()-height),
        //QPoint(middle.x()+zigzagSize.x(), 0),
        //QPoint(width, 0)
    };

    randomizePoints(path.points.begin() + 2, path.points.end() - 2, range);
    randCurvePath(path);

    return path;
}

SidePointsConteiner horizontalPath_border(const SidePointsConteiner &source, const int indent) {
    SidePointsConteiner path;

    for (auto point : source.points) {
        point.setX(point.x() - indent);
        path.type = source.type;
        path.points.push_back(point);
    }
    path.points[0].setX(0);
    //if (source.points.last().y() != 0)

    return path;
}


SidePointsConteiner horizLinePath(const int width) {
    SidePointsConteiner path;
    path.type = SidePointsConteiner::eLineType::HorizontalLine;

    path.points = {
        //QPoint(0,0),
        //QPoint(width, 0)
    };
    //qDebug()<<"horizLinePath - width = " + QString::number(width);

    return path;
}

SidePointsConteiner horizLinePath_borer(const SidePointsConteiner &source, const int indent) {
    SidePointsConteiner path;
    path.type = SidePointsConteiner::eLineType::HorizontalLine;
    QPoint point =  source.points[1];
    point.setX(point.x() - indent);
    path.points = {
        //QPoint(0,0),
        //point
    };
    return path;
}


SidePointsConteiner vertLinePath(const int height) {
    SidePointsConteiner path;
    path.type = SidePointsConteiner::eLineType::VerticalLine;

    path.points = {
        //QPoint(0,0),
        //QPoint(0, height)
    };
    // qDebug() << "vertLinePath - height = " +  QString::number(height);
    return path;
}

SidePointsConteiner vertLinePath_borer(const SidePointsConteiner &source, const int indent) {
    SidePointsConteiner path;
    path.type = SidePointsConteiner::eLineType::VerticalLine;
    QPoint point =  source.points[1];
    point.setY(point.y() - indent);
    path.points = {
        //QPoint(0,0),
        //point
    };
    return path;
}



QSize pathSize(const SidePointsConteiner &path) {
    auto sign = [](int value)->int { return value < 0 ? -1 : 1;};

    auto xCompare = [](QPoint a, QPoint b)->bool { return a.x() < b.x(); };
    auto yCompare = [](QPoint a, QPoint b)->bool { return a.y() < b.y(); };

    auto minMaxX = std::minmax_element(path.points.begin(), path.points.end(), xCompare);
    auto minMaxY = std::minmax_element(path.points.begin(), path.points.end(), yCompare);

    return QSize((minMaxX.second->x() - minMaxX.first->x()) * sign(minMaxX.first->x()),
                 (minMaxY.second->y() - minMaxY.first->y()) * sign(minMaxY.first->y()));
}

void createVerticalPoints (const QPixmap& source, SidePointsConteinerMatrix &vertical_points, const size_t rows, const size_t columns) {
    const int colVert_m = columns + 1;
    const int colVert_n = rows;
    int width = source.width()/columns;
    int height = source.height()/rows;
    vertical_points.resize(rows);
    for (int i = 0; i < colVert_n; i++) {
        vertical_points[i].resize(colVert_m);
        for (int j = 0; j < colVert_m; j++)
            if (j == 0 || (j == colVert_m - 1))
                vertical_points[i][j] = vertLinePath(height);
            else
                vertical_points[i][j] = verticalPath(width, height);
    }
}



void createVerticalBorderPoints(const SidePointsConteinerMatrix &original_points, SidePointsConteinerMatrix &out_points,const int indent) {
    int rows = original_points.size();
    int columns = original_points[0].size();
    out_points.resize(rows);
    for (int i = 0; i < rows; ++i) {
        out_points[i].resize(columns);
        for (int j = 0; j < columns; j++)
            if (j == 0 || j == columns)
                out_points[i][j] = vertLinePath_borer(original_points[i][j], indent);
            else
                out_points[i][j] = verticalPath_border(original_points[i][j], indent);
    }
}

void createHorizontalPoints(const QPixmap& source, SidePointsConteinerMatrix &horizontal_points,const  size_t rows, const size_t columns) {
    int colHoriz_n = rows + 1;
    int colHoriz_m = columns + 1;
    int width = source.width()/columns;
    int height = source.height()/rows;
    horizontal_points.resize(colHoriz_n);
    for (int i = 0; i < colHoriz_n; i++) {
        horizontal_points[i].resize(colHoriz_m);
        for (int j = 0; j < colHoriz_m; j++)
            if (i == 0 || i == colHoriz_n - 1)
                horizontal_points[i][j] = horizLinePath(width);
            else
                horizontal_points[i][j] = horizontalPath(width, height);
    }
}

void createHorizontalBorderPoints(const SidePointsConteinerMatrix &original_points, SidePointsConteinerMatrix &out_points,const int indent) {
    int rows = original_points.size();
    int columns = original_points[0].size();
    out_points.resize(rows);
    for (int i = 0; i < rows; ++i) {
        out_points[i].resize(columns);
        for (int j = 0; j < columns; ++j)
            if (i == 0 || i == rows)
            //out_points[i][j] = original_points[i][j];
                out_points[i][j] = horizLinePath_borer(original_points[i][j], indent);
            else
               // out_points[i][j] = original_points[i][j];
                out_points[i][j] = horizontalPath_border(original_points[i][j], indent);
    }
}

}
