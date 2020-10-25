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
    //Q_PROPERTY(AppModel * data READ getData  NOTIFY dataChanged)

public:
    //AppDataController(QQmlApplicationEngine &engine,QObject *parent = nullptr);
    AppDataController(QObject *parent = nullptr);
    void Init();
    ~AppDataController();

    //QML
public:
    //QScopedPointer<AppData> getData() ;
    AppData* getData() ;
    void setApplicationEngine(QQmlApplicationEngine &engine);
    void registerQMLType(const int id);
    QQmlApplicationEngine *engine_;

signals:
    void itemParsed(QString item_id, int view_id = -1);
    void dataChanged();


private:
    //QScopedPointer<AppData>  app_data_;
    AppData  *app_data_;


private:
public slots:
    void appStart();
    void openFile(const QString file_path);
    void saveFile(const QString file_path, const QString id);

    void deleteModel(const QString id);
    //AbstractTableItemData* getModelByID(const QString id);

//QML Layer
    //QString getFileTitleByID(const QString id);
    //QString getFilePathByID(const QString id);
    QString getDefaultDir();
};

#endif // APP_DATA_PROVIDER_H

