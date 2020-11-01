#include <Item/puzzlepath.h>
#include <QDebug>
using namespace point_utilities;
namespace  path_utilities {

void reverse(SidePointsConteiner& path) {
    auto size = pathSize(path);
    for (auto &point : path.points) {
        if (path.type == SidePointsConteiner::eLineType::HorizontalZigZag ||
            path.type == SidePointsConteiner::eLineType::HorizontalLine)
            point.setX(point.x() - size.width());
        if (path.type == SidePointsConteiner::eLineType::VerticalZigZag ||
            path.type == SidePointsConteiner::eLineType::VerticalLine)
            point.setY(point.y() - size.height());
    }

    std::reverse(path.points.begin(), path.points.end());
}

QPainterPath createPainterPath(SidePointsConteiner path,  bool need_reverse) {
    if (need_reverse) {
        reverse(path);
    }
    QPainterPath painterPath;
    if (path.type == SidePointsConteiner::eLineType::HorizontalZigZag ||
        path.type == SidePointsConteiner::eLineType::VerticalZigZag) {
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

PuzzlePath* createPuzzlePath(SidePointsConteiner& up, SidePointsConteiner& right,
                                 SidePointsConteiner& down, SidePointsConteiner& left) {
    QPainterPath full_path;

    int width = pathSize(up).width();
    int height = pathSize(right).height();

    QPainterPath upPath;
    QPainterPath rightPath;
    QPainterPath downPath;
    QPainterPath leftPath;

    int upleft_dx {};
    int upleft_dy {};

    int downright_dx {};
    int downright_dy {};

    if (pathSize(up).height() < 0)
        upleft_dy = pathSize(up).height();

    if (pathSize(down).height() > 0)
        downright_dy = pathSize(down).height();

    if (pathSize(left).width() < 0)
        upleft_dx = pathSize(left).width();

    if (pathSize(right).width() > 0)
        downright_dx = pathSize(right).width();

    upPath = createPainterPath(up, false);
    rightPath = createPainterPath(right, false);
    downPath = createPainterPath(down, true);
    leftPath = createPainterPath(left, true);

    upPath.translate(0, 0);
    rightPath.translate(width, 0);
    downPath.translate(width, height);
    leftPath.translate(0, height);

    full_path.connectPath(upPath);
    full_path.connectPath(rightPath);
    full_path.connectPath(downPath);
    full_path.connectPath(leftPath);

    return new PuzzlePath(full_path, upleft_dx, upleft_dy, downright_dx, downright_dy);
}

void createPaths(QPixmap& source, QHash<eType,PathsMatrix> &out_paths, QHash<eType,SidePointsConteinerMatrix> &input_vertical_points, QHash<eType,SidePointsConteinerMatrix> &input_horizontal_points, size_t rows, size_t columns){
    QHash<eType,PathsMatrix>::iterator it;
    for (it = out_paths.begin(); it != out_paths.end();++it) {
        SidePointsConteinerMatrix vertical_points;
        SidePointsConteinerMatrix horizontal_points;
        if (it.key()== eType::kBody) {
            vertical_points = input_vertical_points[eType::kBody];
            horizontal_points = input_horizontal_points[eType::kBody];
        }
        else if (it.key()== eType::kBorder) {
            vertical_points = input_vertical_points[eType::kBorder];
            horizontal_points = input_horizontal_points[eType::kBorder];
        }
        else
            return;
        it.value().resize(rows);
        for (int row = 0; row < rows; row++) {
            it.value()[row].resize(columns);
            for (int column = 0; column < columns; column++) {
                it.value()[row][column] = path_utilities::createPuzzlePath (
                    horizontal_points[row][column], vertical_points[row][column+1],
                    horizontal_points[row+1][column], vertical_points[row][column]
                    );
            }
        }
        // }
    }
}
}
