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

AppData::AppData(QObject *parent):QAbstractTableModel(parent){
    //Q_UNUSED(parent);
    //    QString path = QDir::currentPath();
    //    QString fileName = "test.txt";
    //    QString fullFilePath = path  + "/" + fileName;
    Init();
}

int AppData::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return app_data_.size();
}

int AppData::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return APP_MAIN_MODEL_COUNT;
}

QHash<int, QByteArray> AppData::roleNames() const {
    QHash<int, QByteArray> roles;
    // roles.insert(Qt::UserRole + MODEL_ROLES::TITLE, TITLE_S);
    roles.insert(Qt::UserRole + MODEL_ROLES::ID, ID_S);
    // roles.insert(Qt::UserRole + MODEL_ROLES::ICON_PATH, ICON_S);
    roles.insert(Qt::EditRole, EDITE_S);
    roles.insert(Qt::DisplayRole, DISPLAY_S);
    return roles;
}

Qt::ItemFlags AppData::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    if(index.isValid()){
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

QVariant AppData::headerData(int section, Qt::Orientation orientation, int role) const {
    Q_UNUSED(orientation);
    if(role != Qt::DisplayRole){
        return QVariant();
    }
    switch (section) {
    case int(DATA_ID::FEATURE):
        return tr(FEATURE_S);
        break;
    case int(DATA_ID::FEATURE_NAME):
        return tr(NAME_S);
        break;
    case int(DATA_ID::IS_ACTIVE):
        return tr(IS_ACTIVE_S);
        break;
    }
    return QVariant();
}

QVariant AppData::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();
    QVariant result;
    switch (role) {
    case (int(Qt::DisplayRole)):
        result =  "";//app_data_.at(index.row()).value(DATA_ID(index.column()));
        //QString("%1, %2").arg(index.column()).arg(index.row());
        break;
        //    case (int(Qt::UserRole + MODEL_ROLES::TITLE)):
        //           // result = app_data_.at(index.row()).get()->getProperty(ItemEnums::EItemProperty::kFileName);
        //        break;
    case (int(Qt::UserRole + MODEL_ROLES::ID)):
        result = QString("%1, %2").arg(index.column()).arg(index.row());
        break;
    }
    //QString temp =  QString::number(index.row())+" " +  QString::number(index.column());//index.row();
    //qDebug()<< "data " + temp + " = " + result.toString();
    return result;
}

bool AppData::setData(const QModelIndex &index, const QVariant &value, int role) {
    bool result = false;
    // qDebug()<< "setData"+value.toString();
    if (index.isValid() && (role==Qt::EditRole)) {
        //   || role==(Qt::UserRole + MODEL_ROLES::TITLE))) {
        // app_data_.at(index.row()).get()->setProperty(ItemEnums::EItemProperty::kFileName, value.toString());
        result = true;
    }
    return result;
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
    foreach (pItem it, app_data_) {
        if (it.get()->getId() == id){
            item = it;
            break;
        }
    }
    if (item.isNull())
        qDebug()<< ("NO item by id = " + QString::number(id));

    return item;
}


void AppData::createItem(int &item_id, QString image_path, int rows, int columns, bool is_rotated) {
    // LOOGGER("+");
    item_id = app_data_.size();
    Item *item = new Item(image_path, item_id, rows, columns, is_rotated, this);
    pItem ptem = pItem(item, &QObject::deleteLater);

    //user image
    ptem.get()->loadUserImage();
    ptem.get()->setScreenSize(screen_width_,screen_height_);

    //points
    ptem.get()->createPoints();
    ptem.get()->createPaths();
    ptem.get()->createTiles();
    ptem.get()->setupModel();

    app_data_.push_back(ptem);
}

int AppData::getLastCreatedItemId() {
    return  app_data_.size();
}

bool AppData::isEmpty(){
    return app_data_.isEmpty();
}


int AppData::getScreenWidth() {
    return screen_width_;
}

int AppData::getScreenHeight() {
    return screen_height_;
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



//QQuickImageProvider *AppData::getPixmapController(const int item_id){
//    return app_data_.at(item_id).get()->getPixmapController(eType::kSelectionBorder);
//}

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
    screen_width_= 500;
    screen_height_= 500;
}

void AppData::parseFolder(QString path){
    //LOOGGER("parse one file - "+ file_path);
    // for (QString &path : getFiliesFromFolder(file_path))
    //this->createItem(QDir::toNativeSeparators(path));
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
