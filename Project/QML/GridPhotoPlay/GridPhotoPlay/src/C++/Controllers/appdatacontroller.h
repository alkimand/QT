#ifndef APP_DATA_PROVIDER_H
#define APP_DATA_PROVIDER_H

#include <QAbstractTableModel>
#include <QSharedPointer>
#include <QObject>
#include <QVector>
#include <QDesktopServices>
#include <QDebug>
#include <QQmlEngine>
#include <QQmlContext>
#include <QScopedPointer>


#include <appdata.h>

class QStringList;
class QQmlApplicationEngine;

class AppDataController: public QObject {
    Q_OBJECT
    Q_PROPERTY(AppData * data READ getData  NOTIFY dataChanged)

public:
    AppDataController(QObject *parent = nullptr);
    void Init();
    ~AppDataController();

public:
    AppData* getData() ;
    void setApplicationEngine(QQmlApplicationEngine &engine);
    void registerQMLType(const int id);



signals:
    void itemParsed(QString item_id, int view_id = -1);
    void dataChanged();

private:
    //QScopedPointer<AppData>  app_data_;
    AppData  *app_data_;
    ImageControllerMap image_controller_map_;
    QQmlApplicationEngine *engine_;


private:
    bool dataIsEmpty();
public slots:
    void appStart();
    void openFile(const QString file_path);
    void saveFile(const QString file_path, const QString id);
    bool isPointInsideTile(int model_id, QString tile_index, int x, int y);
    void deleteModel(const QString id);
    ItemModelBase *getModelByID(const QString id);
    int getScreenWidth();
    int getScreenHeight();

//QML Layer
    //QString getFileTitleByID(const QString id);
    //QString getFilePathByID(const QString id);
    QString getDefaultDir();
};

#endif // APP_DATA_PROVIDER_H

