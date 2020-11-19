#include <QDebug>
#include <pixmap_controller.h>

//static const char className[] = "PixmapController::";

void PixmapController::setPixmap(QHash<QString, QPixmap*> *map) {
    map_= map;
}

QPixmap PixmapController::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) {
    int width = 100;
    int height = 50;
    if (size)
        *size = QSize(width, height);
    QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
                   requestedSize.height() > 0 ? requestedSize.height() : height);
    pixmap.fill(QColor(id).rgba());
    auto it = map_->find(id);
    //QPixmap test("test.jpg");
    //this->map_->insert("1", &test);
    if (it!=map_->end())
        return *it.value();
    else
        qDebug()<<"no valid pixmap on id - " + id;
    return pixmap;
}

PixmapController::~PixmapController() {

}
