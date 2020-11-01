#include <appdata.h>
#include <pixmap_controller.h>
//#include <logger.h>

#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QDesktopServices>
#include <QTextStream>
#include <QStringList>
#include <QDir>
#include <QDirIterator>
#include <QRegExp>
//#include <QQmlApplicationEngine>



#include <QFuture>
#include <QtConcurrent>


static const char className[] = "AppData::";

AppData::AppData(QObject *parent):QObject(parent){
    //Q_UNUSED(parent);
    //    QString path = QDir::currentPath();
    //    QString fileName = "test.txt";
    //    QString fullFilePath = path  + "/" + fileName;
    Init();
}

void AppData::parseItem(pItem item){
    //LOOGGER("+");
    //qDebug() << QThread::currentThreadId();
    //int item_status;

    //item.get()->load()
    //eItemStatus status = item.get()->getStatus();
    //if (status ==  eItemStatus::kStatusNone) {
      //  item.get()->setStatus(eItemStatus::kParsing);
        //int id = item.get()->getId();
        //item.get()->setId(std::move(id));
      //  item.get()->parse();
       // if (item.get()->getStatus() != eItemStatus::kParseError) {

            //                item.get()->setProperty(ItemEnums::EItemProperty::kStatus,
            //                                        int(ItemEnums::eItemStatus::kParsed));
       // }
        //else {
       //     return;
      //  }
        //            else if (item_status == int (ItemEnums::eItemStatus::kParsed)){
        //                //item.get()->cleanModel();
        //            }
        //            else if (item_status != int (ItemEnums::eItemStatus::kStatusNone)){
        //                //emit itemParsed(id);
        //            }
    //}

}


pItem AppData::getItemByID(const int id){
    pItem item = nullptr;
    foreach (pItem it, app_data_){
        if (it.get()->getId() == id){
            item = it;
            break;
        }
    }
    if (!item.isNull())
        return item;
    else
        qDebug()<< ("NO item by id = " + QString::number(id));
}


void AppData::createItem(QString image_path, int rows, int columns, bool is_rotated) {
    // LOOGGER("+");
    Item *item = new Item(image_path, app_data_.size(), rows, columns, is_rotated, this);
    pItem ptem = pItem(item, &QObject::deleteLater);

    ptem.get()->createPaths();
    ptem.get()->createTiles();
   // ptem.get()->createPixmapController();

    //parseItem(ptem);
    app_data_.push_back(ptem);
}

int AppData::getLastCreatedItemId(){
    return  app_data_.size();
}

bool AppData::isEmpty(){
    return app_data_.isEmpty();
}


//void AppData::saveFile(const QString file_path, const QString id) {
//    QString item_status;
//    pItem item = getItemByID(id);
//    //item.get()->saveFile(file_path);
//}


//void AppData::deleteFile(const QString id){
//    if (id != "-1"){
//        pItem  item = getItemByID(id);
//        //item.get()->deleteFile();
//        int index = app_data_.indexOf(item);
//        //beginRemoveRows(QModelIndex(), index, index);
//        app_data_.removeAt(index);
//        //endRemoveRows();
//    }
//}



QQuickImageProvider *AppData::getPixmapController(const int id){
    return app_data_.at(id).get()->getPixmapController(eType::kBorder);
}

//QString AppData::getPropperIcon(const QString file_name) {
//    QString icon = DEFAULT_ICON;
//    if(file_name.contains(FREEYTVDOWNLOADER))
//        icon = FREEYTVDOWNLOADER_ICON;
//    else if(file_name.contains(FREETIKTOKDOWNLOADER))
//        icon = FREETIKTOKDOWNLOADER_ICON;
//    else if(file_name.contains(FREEYOUTUBETOMP3CONVERTER))
//        icon = FREEYOUTUBETOMP3CONVERTER_ICON;
//    else if(file_name.contains(SPECIAL))
//        icon = SPECIAL_ICON;
//    return icon;
//}


void AppData::Init(){
    //default_property_map_.insert(ItemEnums::EItemProperty::kId, QString::number(-1));
    //default_property_map_.insert(ItemEnums::EItemProperty::kStatus,  QString::number(int(ItemEnums::eItemStatus::kStatusNone)));
    //default_property_map_.insert(ItemEnums::EItemProperty::kFilePath,"");
    //default_property_map_.insert(ItemEnums::EItemProperty::kFileName,"");
    //default_property_map_.insert(ItemEnums::EItemProperty::kIcon, DEFAULT_ICON);
    // default_property_map_.insert(ItemEnums::EItemProperty::kDateLastSaved,"");
    //default_property_map_.insert(ItemEnums::EItemProperty::kFormat,"jpg");
    //parseFolder();
}

void AppData::parseFolder(QString path){
    //LOOGGER("parse one file - "+ file_path);
   // for (QString &path : getFiliesFromFolder(file_path))
       this->createItem(QDir::toNativeSeparators(path));
}

QStringList AppData::getFiliesFromFolder(const QString &file_path) {
    QStringList files;
    QString path = file_path;
    if (file_path.isEmpty())
        path = QDir::currentPath();
    QStringList filters;
    filters << JPG_EXTENSION;
    QDirIterator it(path, filters, QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::NoIteratorFlags);
    while (it.hasNext())
        files << it.next();
    files.sort();

    return files;
}





AppData::~AppData() {
    //LOOGGER("~AppData");
    //qDebug()<< "~ItemModel()";
}
