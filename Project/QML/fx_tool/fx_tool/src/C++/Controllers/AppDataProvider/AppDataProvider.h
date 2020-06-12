#ifndef APP_DATA_PROVIDER_H
#define APP_DATA_PROVIDER_H

#include "Item.h"

#include <QSharedPointer>
#include <QObject>
#include <QVector>

#include <QDesktopServices>
#include <QDebug>

#include <QQmlEngine>
#include <QQmlContext>

//#define  LOOGGER(text)                     qDebug()<< className + QString::fromUtf8(__func__) + " " + text;
#define  FX_EXTENSION                      "*.fx"
#define  GetItemProp(props)                item.get()->getProperty(ItemEnums::EItemProperty::props)
#define  setItemProp_int(id , props)       item.get()->setProperty(ItemEnums::EItemProperty::id , QString::number( props ))
typedef  QSharedPointer<Item> pItem;


class QStringList;

class AppDataProvider: public QObject {
    Q_OBJECT
    Q_PROPERTY(ItemModelBase * model READ getModel  WRITE setModel NOTIFY modelChanged)
    Q_PROPERTY(int current_model_id_ READ getModelId  WRITE setModelId NOTIFY IdChanged)
    Q_PROPERTY(bool isModelPresent_ READ isModelPresent  WRITE setModelPresent NOTIFY ModelPresentChanged)
    Q_PROPERTY(QString current_model_title READ getTitle WRITE setTitle NOTIFY titleChange)
public:
    AppDataProvider();
    void Init();

    ItemEnums::eItemStatus parseItem(pItem item);
    void loadDirectory(const QString &directory);
    static inline void openFile();

    QStringList FindFilies(const QString path = "");
    //QString get
    //AppDataProvider(AppDataProvider const&) = delete;
    //  void operator=(AppDataProvider const&) = delete;

    void createItem(const QString &path = "");
    void openInExplorer();


signals:
    void itemParsed(int id);
    //QML
public:
    //get
    int getModelId() const;
    ItemModelBase *getModel() ;
    bool isModelPresent() const;
    QString getTitle();

    //set
    void setModel(ItemModelBase *){};
    void setModelId(int id);
    void setModelPresent(bool modelPresent);
    void setTitle(QString new_tittle);


    //qml
signals:

    void modelChanged();
    void IdChanged();
    void ModelPresentChanged();
    void titleChange();



    // ~AppDataProvider();
protected:

private:
    pItem getItemByID(int id);


private:
    //qml
    ItemModelBase *model;
    bool isModelPresent_ = false;
    QString            current_model_title ="";

private:
    int                   current_model_id_ = -1;
    ItemPropertyMap        default_property_map_;

    QVector<pItem>                     app_data_;
    //static AppDataProvider *s_instance_ ;
    //config_app_ config;
    //public slots:

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
