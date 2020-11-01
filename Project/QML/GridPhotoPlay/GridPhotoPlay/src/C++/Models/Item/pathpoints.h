#ifndef PATH_POINTS_H
#define PATH_POINTS_H

#include <vector>
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QList>
#include <Item/itemenums.h>

struct SidePointsConteiner {
  enum class eLineType {
    HorizontalLine,
    VerticalLine,
    HorizontalZigZag,
    VerticalZigZag,
  };

  QVector<QPoint> points;
  eLineType type;
};

typedef QVector<QVector<SidePointsConteiner> > SidePointsConteinerMatrix;

namespace  point_utilities {
SidePointsConteiner horizontalPath(int w, int h);

SidePointsConteiner verticalPath(int w, int h);

SidePointsConteiner horizLinePath(int w);

SidePointsConteiner vertLinePath(int h);

void randCurvePath(SidePointsConteiner& path);

QSize pathSize(SidePointsConteiner &path);

void createHorizontalPoints (QPixmap& source, QHash<eType,SidePointsConteinerMatrix> &vertical_points, size_t rows, size_t columns);

void createVerticalPoints (QPixmap& source, QHash<eType, SidePointsConteinerMatrix> &horizontal_points, size_t rows, size_t column);
}
#endif


