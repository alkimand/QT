#include <QDebug>
#include <QWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QDirIterator>
#include <QLatin1String>
#include <QStringList>
#include <QDir>
#include <QSysInfo>
#include <QSettings>
#include <QLatin1String>
#include <QFuture>
#include <QtConcurrent>
#include <QExplicitlySharedDataPointer>
#include <QSharedPointer>
#include <QQmlApplicationEngine>

#include <appdatacontroller.h>

static const char className[] = "AppDataController::";

//AppDataController::AppDataController(QQmlApplicationEngine &engine, QObject *parent):QObject(parent){ //, engine_(&engine) {
AppDataController::AppDataController(QObject *parent):QObject(parent){ //, engine_(&engine) {
    appStart();
}

void AppDataController::appStart() {
    Init();
}

AppData *AppDataController::getData() {
    return app_data_;
}

void AppDataController::setApplicationEngine(QQmlApplicationEngine &engine){
    engine_= &engine;
}

void AppDataController::registerQMLType(const int id) {
    pItem item = app_data_->getItemByID(id);
    if (!item.isNull() && !dataIsEmpty()) {
        pItem item = app_data_->getItemByID(id);
        if (engine_ && !item.isNull()) {
            ImageControllerMap::iterator it;
            for (it = image_controller_map_.begin(); it != image_controller_map_.end(); ++it) {
                QString image_root_path = it.value();
                engine_->addImageProvider(QLatin1String(image_root_path.toLatin1()), item.get()->getPixmapController(it.key()));
            }
        }
        else {
            qDebug()<< ("NO engine " + QString::number(id));
        }
    }
    else {
        qDebug()<< ("NO item by id in registerQMLType = " + QString::number(id));
        return;
    }
}

bool AppDataController::dataIsEmpty() {
    return app_data_->isEmpty();
}

QString AppDataController::getDefaultDir() {
    QString path;
    QSettings ini(QSettings::IniFormat, QSettings::UserScope,"DVDVideoSoft","");
    QString product_setting_path =   QFileInfo(ini.fileName()).absolutePath();
    if (!product_setting_path.isEmpty()){
        path += QFileInfo(ini.fileName()).absolutePath();
        path +="/DVDVideoSoft";
    }

    //  }
    //LOOGGER("= " + path);
    return path;
}

void AppDataController::openFile(const QString file_path){
    //LOOGGER("+");
    //    QString real_file_path = file_path.mid(8);
    //    QFileInfo check_file(real_file_path);
    //    if (check_file.exists() && check_file.isFile()){
    //        int id = model_->getIDModelByProperty(ItemEnums::EItemProperty::kFilePath, real_file_path);
    //        if (id != -1) {
    //            parseItem(QString::number(id));
    //        }
    //        else {
    //            model_->createItem(QDir::toNativeSeparators(real_file_path));
    //            id = model_->getLastCreatedItemId();
    //            parseItem(QString::number(id));
    //        }
    //    }
    //    else {
    //        LOOGGER("wrong file name from qml" + file_path);
    //    }
}


void AppDataController::saveFile(const QString file_path, const QString id) {
    //LOOGGER("+ file_path=" + file_path);
    //    if (id!="-1" && !id.isEmpty()) {
    //        QString real_file_path = file_path;
    //        if (file_path.contains("file:///")){
    //            real_file_path = file_path.mid(8);
    //        }
    //        model_->saveFile(real_file_path , id);
    //    }
}

void AppDataController::deleteModel(const QString id) {
    //LOOGGER("id= "+ id );
    // model_->deleteFile(id);
}



void AppDataController::Init() {
    app_data_ = new AppData(this);
    //image_controller_map_.insert(kTilePixmap, QString(TILE_BODY_IMAGE_PROVIDER));
    image_controller_map_.insert(kTilePixmap, "tile_body_id");
    image_controller_map_.insert(kTileBorder, QString(TILE_BORDER_IMAGE_PROVIDER));
    QString default_dir = getDefaultDir();
    default_dir = "";//--
    if (default_dir.isEmpty())
        default_dir = QDir::currentPath();
    // app_data_->parseFolder(default_dir);
    app_data_->createItem("test.jpg",5,5, false);
    // registerQMLType(0);
    // engine_->addImageProvider(QLatin1String("0"), app_data_->getPixmapController(0));

    // app_data_->registerQMLType(engine_);
}

AppDataController::~AppDataController() {
    // app_data_->deleteLater();
    //delete app_data_;
}


