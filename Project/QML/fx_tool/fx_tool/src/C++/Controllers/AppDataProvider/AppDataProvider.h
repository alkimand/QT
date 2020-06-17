#ifndef APP_DATA_PROVIDER_H
#define APP_DATA_PROVIDER_H

#include "Item.h"
#include <QAbstractTableModel>
#include <QSharedPointer>
#include <QObject>
#include <QVector>

#include <QDesktopServices>
#include <QDebug>

#include <QQmlEngine>
#include <QQmlContext>

#include "AppModel.h"

class QStringList;

class AppDataProvider: public QObject {
    Q_OBJECT
    Q_PROPERTY(AppModel * model READ getModel  NOTIFY modelChanged)

public:
    AppDataProvider(QObject *parent = nullptr);
    void Init();
    ~AppDataProvider();

    //QML
public:
    AppModel *getModel() ;
    //qml
signals:
    void itemParsed(QString item_id);
    void modelChanged();

private:
    AppModel            *model_;

private:


public slots:
    void appStart();
    void toolBarButtonPush(QString id);
    void openFile(const QString file_path);
    void saveFile(const QString file_path, const QString id);
    ItemModelBase* getModelByID(const QString id);
    QString getFileTitleByID(const QString id);
    QString getFilePathByID(const QString id);
    // QString getDefaultConfigFolder();
    QString getDefaultDir();
};

#endif // APP_DATA_PROVIDER_H


//ToDO
//void registerSingleton(QQmlEngine *qmlEngine);


//static QObject *registerSingleton(QQmlEngine *engine, QJSEngine *scriptEngine);


//     static void registerSingleton_(QQmlEngine *qmlEngine){

//        if (!s_instance_) {
//            s_instance_ = new AppDataProvider();
//        }

//        QQmlContext *rootContext = qmlEngine->rootContext();

//        //AppDataProvider *s_instance = new AppDataProvider();

//        rootContext->setContextProperty("AppDataProvider", s_instance_);
//    }

//     static AppDataProvider &instance() {
//         AppDataProvider  *tmp = new AppDataProvider();
//         return tmp;
//     };



//     QObject * qmlAppDataInterface( QQmlEngine *e, QJSEngine * scriptEngine)
//     {
//         Q_UNUSED(scriptEngine)

//         AppDataProvider *p = &AppDataProvider::instance();
//         e->setObjectOwnership(p, QQmlEngine::CppOwnership);
//         return p;
//     }


//    static AppDataProvider& instance(){
//        qDebug()<< "instance";
//        static AppDataProvider instance_;
//        return instance_;
//    }
