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

class AppData : public QAbstractTableModel {
    Q_OBJECT
public:
    AppData(QObject*parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

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
    int getScreenWidth();
    int getScreenHeight();
    //void saveFile(const QString file_path, const QString id);
    //void deleteFile( const QString id);
    //QQuickImageProvider *getPixmapController(const int id);
    //private:


protected:

    //QHash<ItemEnums::EItemProperty, QString>       default_property_map_;
    //int                   model_counter_ = -1;

private:

    void Init();
    QStringList getFiliesFromFolder(const QString &path = "");

    int screen_width_= 0;
    int screen_height_= 0;
   // QString getPropperIcon(const QString file_name = "");

signals:
   // void itemParsed(int id);

private:
    QList <pItem>                       app_data_;

};

#endif // APP_MODEL_H
