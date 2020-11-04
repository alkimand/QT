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



typedef QVector<QVector<SidePointsConteiner>> SidePointsConteinerMatrix;

namespace  point_utilities {
SidePointsConteiner horizontalPath(int w, int h);
SidePointsConteiner horizontalPath_border(const SidePointsConteiner &source, int const indent);

SidePointsConteiner verticalPath(int w, int h);
SidePointsConteiner verticalPath_border(const SidePointsConteiner &source, int const indent);

SidePointsConteiner horizLinePath(const int w);
SidePointsConteiner horizLinePath_borer(const SidePointsConteiner &source, int const indent);

SidePointsConteiner vertLinePath(const int h);
SidePointsConteiner vertLinePath_borer(const SidePointsConteiner &source, int const indent);

void randCurvePath(SidePointsConteiner& path);

QSize pathSize(const SidePointsConteiner &path);

//void createHorizontalPoints (QPixmap& source, QHash<eType,SidePointsConteinerMatrix> &vertical_points, size_t rows, size_t columns);
void createHorizontalPoints (const QPixmap& source, SidePointsConteinerMatrix &vertical_points, const size_t rows, const size_t columns);
void createHorizontalBorderPoints (const SidePointsConteinerMatrix &original_points, SidePointsConteinerMatrix &out_points,int indent);

//void createVerticalPoints (QPixmap& source, QHash<eType, SidePointsConteinerMatrix> &horizontal_points, size_t rows, size_t column);
void createVerticalPoints (const QPixmap& source,  SidePointsConteinerMatrix &horizontal_points, size_t rows, size_t column);
void createVerticalBorderPoints (const SidePointsConteinerMatrix &original_points, SidePointsConteinerMatrix &out_points,int indent);
}
#endif


