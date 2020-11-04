#ifndef PUZZLEITEM_H
#define PUZZLEITEM_H

#include <QGraphicsPixmapItem>
#include <QHash>
#include <QPixmap>
#include <Item/puzzlepath.h>

//! базовый класс пазла
class PuzzleItem : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    PuzzleItem(PuzzlePath *path, const QPixmap& source, const QRect &rect,
               QObject *parent = nullptr);
    ~PuzzleItem() override;

    //static QHash<int, QGraphicsPixmapItem> *pixel_map_;

    QRectF boundingRect() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

    void createBorder(PuzzlePath *border_path, const int indent = 0);
    void setAddress(QPair<int, int> address);
    QPair <int, int> getOriginCoordinates();
    QString getSIndex();
    void setIndex(QPair<int, int> index);

private:
    QGraphicsPixmapItem* pixmap_item_;

protected:
    QRect rect_;
    PuzzlePath* path_;
    PuzzlePath* border_path_;
    QPair<int, int> address_;
    QPair<int, int> index_;

    QPainterPath full_path_;

    QPixmap* user_pixmap_;
    QPixmap* piece_pixmap_;
    QPixmap* border_pixmap_;
};

#endif // PUZZLEITEM_H
