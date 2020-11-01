#ifndef PUZZLEPATH_H
#define PUZZLEPATH_H

#include <QPainterPath>
#include <Item/pathpoints.h>
#include <Item/itemenums.h>

struct PuzzlePath;
typedef QVector<QVector <PuzzlePath*>> PathsMatrix;

struct  PuzzlePath {
  QPainterPath path;
  int upleft_dx;
  int upleft_dy;
  int downright_dx;
  int downright_dy;

  PuzzlePath() {}

  PuzzlePath(QPainterPath _path, int _upleft_dx, int _upleft_dy,
             int _downright_dx, int _downright_dy)
    : path (_path), upleft_dx(_upleft_dx), upleft_dy(_upleft_dy),
                    downright_dx(_downright_dx), downright_dy (_downright_dy) {
  }
};

namespace  path_utilities {


QPainterPath getPainterPath(SidePointsConteiner path, bool need_reverse);

PuzzlePath* createPuzzlePath(SidePointsConteiner& up, SidePointsConteiner& right,
                       SidePointsConteiner& down, SidePointsConteiner& left);

void createPaths(QPixmap& source, QHash<eType,PathsMatrix> &out_paths, QHash<eType,SidePointsConteinerMatrix> &input_vertical_points,
              QHash<eType,SidePointsConteinerMatrix> &input_horizontal_points, size_t rows, size_t columns);
}

#endif // PUZZLEPATH_H
