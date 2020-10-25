#include <Item/puzzlepath.h>
#include <QtDebug>

void reverse(PathPoints& path) {
  auto size = pathSize(path);
  for (auto &point : path.points) {
    if (path.type == PathPoints::Type::HorizontalZigZag ||
        path.type == PathPoints::Type::HorizontalLine)
      point.setX(point.x() - size.width());
    if (path.type == PathPoints::Type::VerticalZigZag ||
        path.type == PathPoints::Type::VerticalLine)
      point.setY(point.y() - size.height());
  }

  std::reverse(path.points.begin(), path.points.end());
}

QPainterPath getPainterPath(PathPoints path,  bool need_reverse) {
  if (need_reverse) {
    reverse(path);
  }
  QPainterPath painterPath;
  if (path.type == PathPoints::Type::HorizontalZigZag ||
      path.type == PathPoints::Type::VerticalZigZag) {
    painterPath.moveTo(path.points[0]);
    painterPath.lineTo(path.points[1]);
    for (size_t i = 1; i < path.points.size() - 2; i += 2) {
      painterPath.cubicTo(path.points[i], path.points[i+1], path.points[i+2]);
    }
    painterPath.lineTo(path.points[path.points.size()-1]);
  }
  else {
    painterPath.moveTo(path.points[0]);
    painterPath.lineTo(path.points[1]);
  }

  return painterPath;
}

PuzzlePath* createPuzzlePathItem(PathPoints& up, PathPoints& right,
                       PathPoints& down, PathPoints& left) {
  QPainterPath fullPath;

  int w = pathSize(up).width();
  int h = pathSize(right).height();

  QPainterPath upPath;
  QPainterPath rightPath;
  QPainterPath downPath;
  QPainterPath leftPath;

  int upleft_dx = 0;
  int upleft_dy = 0;

  int downright_dx = 0;
  int downright_dy = 0;

  if (pathSize(up).height() < 0) {
    upleft_dy = pathSize(up).height();
  }
  if (pathSize(down).height() > 0) {
    downright_dy = pathSize(down).height();
  }
  if (pathSize(left).width() < 0) {
    upleft_dx = pathSize(left).width();
  }
  if (pathSize(right).width() > 0) {
    downright_dx = pathSize(right).width();
  }

  upPath = getPainterPath(up, false);
  rightPath = getPainterPath(right, false);
  downPath = getPainterPath(down, true);
  leftPath = getPainterPath(left, true);

  upPath.translate(0, 0);
  rightPath.translate(w, 0);
  downPath.translate(w, h);
  leftPath.translate(0, h);

  fullPath.connectPath(upPath);
  fullPath.connectPath(rightPath);
  fullPath.connectPath(downPath);
  fullPath.connectPath(leftPath);

  return new PuzzlePath(fullPath, upleft_dx, upleft_dy, downright_dx, downright_dy);
}

PathsMatrix getPathsMatrix(QPixmap& source, size_t rows, size_t columns) {
  auto verPoints = getVerPoints(source, rows, columns);
  auto horPoints = getHorizPoints(source, rows, columns);
  PathsMatrix paths_matrix(rows);
  for (size_t i = 0; i < rows; i++) {
    paths_matrix[i].resize(columns);
    for (size_t j = 0; j < columns; j++){
       paths_matrix[i][j] = createPuzzlePathItem (
           horPoints[i][j], verPoints[i][j+1],
           horPoints[i+1][j], verPoints[i][j]
       );
    }
  }
  return paths_matrix;
}
