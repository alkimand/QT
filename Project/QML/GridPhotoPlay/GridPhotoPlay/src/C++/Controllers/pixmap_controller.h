#ifndef PIXMAP_CONTROLLER_H
#define PIXMAP_CONTROLLER_H

#include <QQuickImageProvider>
#include <QHash>
#include <QPixmap>

class PixmapController : public QQuickImageProvider
{
public:
    PixmapController():QQuickImageProvider(QQuickImageProvider::Pixmap){};
    void setPixmap(QHash<QString, QPixmap*> *map);
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
    QHash<QString, QPixmap*> *map_;
   //static void setPixmap(QHash<QString, QPixmap*> &map);

    virtual ~PixmapController();
};

#endif // APP_DATA_PROVIDER_H

