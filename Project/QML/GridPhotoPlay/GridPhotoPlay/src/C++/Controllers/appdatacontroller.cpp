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

void AppDataController::registerQMLType(const int item_id) {
    pItem item = app_data_->getItemByID(item_id);
    if (!item.isNull() && !dataIsEmpty()) {
        pItem item = app_data_->getItemByID(item_id);
        if (engine_ && !item.isNull()) {
            ImageControllerMap::iterator it;
            for (it = image_controller_map_.begin(); it != image_controller_map_.end(); ++it) {
                engine_->addImageProvider(QLatin1String(it.value().toLatin1()), item.get()->getPixmapController(it.key()));
            }
        }
        else {
            qDebug()<< ("NO engine at item_id=" + QString::number(item_id));
        }
    }
    else {
        qDebug()<< ("NO item by id in registerQMLType at item_id= " + QString::number(item_id));
        return;
    }
}

int AppDataController::getScreenWidth() {
    return app_data_->getScreenWidth();

}

int AppDataController::getScreenHeight() {
   return app_data_->getScreenHeight();
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

bool AppDataController::isPointInsideTile(int model_id,  QString tile_index, int mouse_area_x, int mouse_area_y) {
   // getModelByID(QString::number(model_id)).;
    LOOGGER("tile_index=" + tile_index +" mouse_area_x="+ QString::number(mouse_area_x)+ " mouse_area_y="+ QString::number(mouse_area_y));
    return true;
}

void AppDataController::deleteModel(const QString id) {
    LOOGGER("id= "+ id );
    // model_->deleteFile(id);
}

ItemModelBase *AppDataController::getModelByID(const QString id) {

     //return app_data_->getItemByID(0)->getModel();

    return app_data_->getItemByID(id.toInt())->getModel();
}



void AppDataController::Init() {
    app_data_ = new AppData(this);
   // image_controller_map_.insert(kBody, QString(TILE_BODY_IMAGE_PROVIDER));
    image_controller_map_.insert(eType::kBody, QString(TILE_BODY_IMAGE_PROVIDER));
    image_controller_map_.insert(eType::Background, QString(TILE_BACKGOUND_BORDER_IMAGE_PROVIDER));
    image_controller_map_.insert(eType::kSelectionBorder, QString(TILE_BORDER_IMAGE_PROVIDER));
    image_controller_map_.insert(eType::kBackgroundBorder, QString(TILE_BACKGOUND_BORDER_IMAGE_PROVIDER));

//    QString default_dir = getDefaultDir();
//    default_dir = "";//--
//    if (default_dir.isEmpty())
//        default_dir = QDir::currentPath();
    // app_data_->parseFolder(default_dir);
    app_data_->createItem("test.jpg",20,20, false);
}

AppDataController::~AppDataController() {
    // app_data_->deleteLater();
    //delete app_data_;
}


