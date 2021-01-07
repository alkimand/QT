#ifndef PUZZLEPATH_H
#define PUZZLEPATH_H

#include <QPainterPath>
#include <pathpoints.h>
//#include <itemenums.h>

struct PuzzlePath;
typedef QVector<QVector <PuzzlePath*>> PathsMatrix;

struct  PuzzlePath {
  QVector <QPainterPath> path;
  int upleft_dx;
  int upleft_dy;
  int downright_dx;
  int downright_dy;

  PuzzlePath() {}

  PuzzlePath(QVector <QPainterPath> _path, int _upleft_dx, int _upleft_dy,
             int _downright_dx, int _downright_dy)
    :  upleft_dx(_upleft_dx), upleft_dy(_upleft_dy),
                    downright_dx(_downright_dx), downright_dy (_downright_dy) {
      for (auto &it: _path)
          path.push_back(std::move(it));
  }
};

namespace  path_utilities {


QPainterPath getPainterPath(SidePointsConteiner path, bool need_reverse);

PuzzlePath* createPuzzlePath(const SidePointsConteiner& up, const SidePointsConteiner& right,
                      const  SidePointsConteiner& down, const SidePointsConteiner& left);

void createPaths(PathsMatrix &out_paths,const SidePointsConteinerMatrix &vertical_points,
             const SidePointsConteinerMatrix &horizontal_points,const int rows, const int columns);
}

#endif // PUZZLEPATH_H
