#include "AppDataProvider.h"
#include <QDebug>
#include <QWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QDirIterator>
#include <QStringList>
#include <QDir>
#include <QSysInfo>
#include <QSettings>
#include <QFuture>
#include <QtConcurrent>

#include "ItemPropery.h"

#include <QExplicitlySharedDataPointer>

#include <QSharedPointer>

static const char className[] = "AppDataProvider::";

AppDataProvider::AppDataProvider(QObject *parent):QObject(parent) {
    Init();
}

void AppDataProvider::appStart(){
    this->Init();

}

AppModel *AppDataProvider::getModel() {
    return model_;
}

QString AppDataProvider::getDefaultDir(){
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





void AppDataProvider::parseItem(QString id, int view_id){
    //LOOGGER("+ id= " + id + "+view_id= "+view_id);
//    pItem  item = model_->getItemByID(id);
//    if (item != nullptr) {
//        //qDebug() << QThread::currentThreadId();
//        auto future = QtConcurrent::run([=]() {
//            model_->parseItem(item);
////            if (item.get()->getProperty(ItemEnums::EItemProperty::kStatus) == QString(ItemEnums::eItemStatus::kParsed)) {
////                emit itemParsed(id,view_id);
////            };
//        });
//    }
//    else
//        LOOGGER("Error getItemByID id = " + id);
}


void AppDataProvider::openFile(const QString file_path) {
    //LOOGGER("+");
    QString real_file_path = file_path.mid(8);
    QFileInfo check_file(real_file_path);
    if (check_file.exists() && check_file.isFile()){
        int id = model_->getIDModelByProperty(ItemEnums::EItemProperty::kFilePath, real_file_path);
        if (id != -1) {
            parseItem(QString::number(id));
        }
        else {
            model_->createItem(QDir::toNativeSeparators(real_file_path));
            id = model_->getLastCreatedItemId();
            parseItem(QString::number(id));
        }
    }
    else {
        LOOGGER("wrong file name from qml" + file_path);
    }
}


void AppDataProvider::saveFile(const QString file_path, const QString id) {
    //LOOGGER("+ file_path=" + file_path);
//    if (id!="-1" && !id.isEmpty()) {
//        QString real_file_path = file_path;
//        if (file_path.contains("file:///")){
//            real_file_path = file_path.mid(8);
//        }
//        model_->saveFile(real_file_path , id);
//    }
}

void AppDataProvider::deleteModel(const QString id) {
    //LOOGGER("id= "+ id );
   // model_->deleteFile(id);
}


//AbstractTableItemData *AppDataProvider::getModelByID(const QString id) {
//    // LOOGGER("+");
//    //return model_->getItemByID(id)->getModel();
//}


//QString AppDataProvider::getFileTitleByID(const QString id) {
//   // return model_->getItemByID(id)->getProperty(ItemEnums::EItemProperty::kFileName);
//}


//QString AppDataProvider::getFilePathByID(const QString id) {
//    if (id!="-1" && !id.isEmpty())
//        return model_->getItemByID(id)->getProperty(ItemEnums::EItemProperty::kFilePath);
//    return QString();
//}


void AppDataProvider::Init() {
    model_ = new AppModel(this);
    QString default_dir = getDefaultDir();

    default_dir = "";//--

    if (default_dir.isEmpty())
        default_dir = QDir::currentPath();
    model_->parseFolder(std::move(default_dir));
}

AppDataProvider::~AppDataProvider() {
    delete model_;
}


