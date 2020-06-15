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

    //Q_PROPERTY(int current_model_id_ READ getModelId  WRITE setModelId NOTIFY IdChanged)
   // Q_PROPERTY(bool isModelPresent_ READ isModelPresent  WRITE setModelPresent NOTIFY ModelPresentChanged)
   // Q_PROPERTY(QString current_model_title READ getTitle WRITE setTitle NOTIFY titleChange)
public:
    AppDataProvider(QObject *parent = nullptr);
    void Init();
    //void loadDirectory(const QString &directory);
   // static inline void openFile();
  //  QStringList FindFilies(const QString path = "");
   // void createItem(const QString &path = "");
   // void openInExplorer();

//for be a model




signals:
   // void itemParsed(int id);
    //QML
public:
    //get
    //int getModelId() const;
    AppModel *getModel() ;
    //bool isModelPresent() const;
    //QString getTitle();

    //set
    //void setModel(ItemModelBase *){};
    //void setModelId(int id);
   // void setModelPresent(bool modelPresent);
    //void setTitle(QString new_tittle);


    //qml
signals:
    void itemParsed(QString id);
    void modelChanged();
    //void IdChanged();
    //void ModelPresentChanged();
   // void titleChange();



    // ~AppDataProvider();
protected:

private:
    //pItem getTableModelByID(int id);


private:
    //qml
    //ItemModelBase *model;

    AppModel            *model_;

private:

public slots:
    void appStart();
    void toolBarButtonPush(QString id);



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
