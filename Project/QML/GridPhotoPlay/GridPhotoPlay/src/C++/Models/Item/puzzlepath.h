#ifndef PUZZLEPATH_H
#define PUZZLEPATH_H

#include <QPainterPath>
#include <Item/pathpoints.h>


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

QPainterPath getPainterPath(PathPoints path, bool need_reverse);

//! строит элемент пазла из четырех зигзагов
PuzzlePath* createPuzzlePathItem(PathPoints& up, PathPoints& right,
                       PathPoints& down, PathPoints& left);

typedef QVector<QVector <PuzzlePath*>> PathsMatrix;

//! создает пазлы для заданной картинки и количества фигур
PathsMatrix getPathsMatrix(QPixmap& source, size_t n_rows, size_t n_columns);

#endif // PUZZLEPATH_H
