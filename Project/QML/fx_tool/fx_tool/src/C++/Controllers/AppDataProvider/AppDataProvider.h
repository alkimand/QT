#ifndef APP_DATA_PROVIDER_H
#define APP_DATA_PROVIDER_H

#include "ItemModel.h"

#include <QSharedPointer>
#include <QObject>
#include <QVector>

#include <QDesktopServices>
#include <QDebug>

#include <QQmlEngine>
#include <QQmlContext>

typedef  QSharedPointer<ItemModel> Item;

class AppDataProvider: public QObject {
    Q_OBJECT

public:
    AppDataProvider();
    //   void setItemProperty( ItemEnums::EItemProperty propertyType, QVariant value);
    //   void setDefaultPropertyMap(ItemPropertyMap default_property_map);
    //   void changeItemProperty(ItemEnums::EItemProperty propertyType, QVariant value);
    //   QVariant getItemProperty(ItemEnums::EItemProperty propertyType);


    static AppDataProvider& instance(){
        qDebug()<< "instance";
        static AppDataProvider instance_;
        return instance_;
    }

    void loadDirectory(const QString &directory);
    static inline void openFile(const QString &fileName);

    void FindFilies(const QString path = "");
    //AppDataProvider(AppDataProvider const&) = delete;
    //  void operator=(AppDataProvider const&) = delete;

    void createItem(const QString path = "");
    void openInExplorer();

    //    ConfigAppDataProvider& Config() {
    //        return config_;
    //    }



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








    // ~AppDataProvider();
protected:

    //        ItemPropertyMap item_data_;

private:

    void PreapreItem(const QString path = "");
    //static AppDataProvider *s_instance_ ;
    //config_app_ config;

    QVector<Item>  app_data_;


    //public slots:

};



#endif // APP_DATA_PROVIDER_H
