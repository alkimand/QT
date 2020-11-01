#ifndef APP_MODEL_H
#define APP_MODEL_H
#include <QObject>
#include <QVector>
#include <QList>
#include <QAbstractTableModel>
#include <QSharedPointer>
#include <QHash>

#include <item.h>
#include <pixmap_controller.h>

//#include <Item/itemconstants.h>

typedef  QSharedPointer<Item> pItem;

class PixmapController;
//Class QQmlApplicationEngine;

class AppData : public QObject {
    Q_OBJECT
public:
    AppData(QObject*);

    virtual ~AppData();

public:
    //void setDirectory(QString directory);
    void parseFolder(QString file_path = "");
    void parseItem(pItem item);
    //void registerQMLType(QQmlApplicationEngine &engine);
    pItem  getItemByID(const int id);
    void createItem(QString image_path ="test.jpg" , int rows = 5, int columns = 5, bool is_rotated = false);
    int getLastCreatedItemId();
    bool isEmpty();
    //void saveFile(const QString file_path, const QString id);
    //void deleteFile( const QString id);
    QQuickImageProvider *getPixmapController(const int id);
    //private:

protected:

    //QHash<ItemEnums::EItemProperty, QString>       default_property_map_;
    //int                   model_counter_ = -1;

private:

    void Init();
    QStringList getFiliesFromFolder(const QString &path = "");

   // QString getPropperIcon(const QString file_name = "");

signals:
   // void itemParsed(int id);

private:
    QList <pItem>                       app_data_;
};

#endif // APP_MODEL_H
