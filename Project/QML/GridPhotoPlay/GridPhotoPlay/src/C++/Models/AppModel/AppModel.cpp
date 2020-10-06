#include "AppModel.h"
#include "Item.h"
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

#include <QThread>

#include <QSharedPointer>

#include <QFuture>
#include <QtConcurrent>

static const char className[] = "AppModel::";

AppModel::AppModel(QObject *parent):QAbstractTableModel(parent){
    //Q_UNUSED(parent);
    //parentModel_ = this;
    // modelType_ = modelType
    //setupWidgetModel();
    //Tile *t = new Tile();
    //Tile h;
    QString path = QDir::currentPath();
    QString fileName = "test.txt";
    QString fullFilePath = path  + "/" + fileName;
    Init();
    //SetupModel();

}

//void AppModel::setDirectory(QString directory) {
//    directory_ = directory;
//}

void AppModel::parseItem(pItem item){
    //LOOGGER("+");
    //qDebug() << QThread::currentThreadId();
    //int item_status;
    Item::eItemStatus item_status = item.get()->getStatus();
    if (item_status ==  Item::eItemStatus::kInit){
        item.get()->setStatus(Item::eItemStatus::kParsing);
        int id = item.get()->getId();
        item.get()->setId(std::move(id));
        item.get()->parse();
        if (item.get()->getStatus() == Item::eItemStatus::kParseError) {

            //                item.get()->setProperty(ItemEnums::EItemProperty::kStatus,
            //                                        int(ItemEnums::eItemStatus::kParsed));
        }
        else {

        }
        //            else if (item_status == int (ItemEnums::eItemStatus::kParsed)){
        //                //item.get()->cleanModel();
        //            }
        //            else if (item_status != int (ItemEnums::eItemStatus::kInit)){
        //                //emit itemParsed(id);
        //            }
    }

}

pItem AppModel::getItemByID(const QString id){
    pItem item = nullptr;
    foreach (pItem it, app_data_){
        if (it.get()->getId() == id){
            item = it;
            break;
        }
    }
    return item;
}

//int AppModel::getIDModelByProperty(const ItemEnums::EItemProperty property_type,const QString property) {
//    int id = -1;
//    for (auto item: app_data_){
//        QString item_property =  item.get()->getProperty(property_type);
//        if (item_property == property) {
//            id = (item.get()->getProperty(ItemEnums::EItemProperty::kId)).toInt();
//            break;
//        }
//    }
//    return id;
//}


void AppModel::createItem(const QString &&path){
    // LOOGGER("+");
    Item *item = new Item(this);
    pItem ptem = pItem(item, &QObject::deleteLater);
    // ptem.get()->setupDefault(default_property_map_);
    ptem.get()->setId(app_data_.size());
    ptem.get()->setFilePath(path);
    parseItem(ptem);

    //int row = app_data_.size();
    //beginInsertRows(QModelIndex(), row, row);
    app_data_.push_back(ptem);
    //endInsertRows();
}

int AppModel::getLastCreatedItemId(){
    return  app_data_.size();
}


void AppModel::saveFile(const QString file_path, const QString id) {
    QString item_status;
    pItem item = getItemByID(id);
    //item.get()->saveFile(file_path);
}


void AppModel::deleteFile(const QString id){
    if (id != "-1"){
        pItem  item = getItemByID(id);
        //item.get()->deleteFile();
        int index = app_data_.indexOf(item);
        //beginRemoveRows(QModelIndex(), index, index);
        app_data_.removeAt(index);
        //endRemoveRows();
    }
}

//QString AppModel::getPropperIcon(const QString file_name) {
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

int AppModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return app_data_.size();
}

int AppModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return APP_MAIN_MODEL_COUNT;
}

QHash<int, QByteArray> AppModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles.insert(Qt::UserRole + MODEL_ROLES::TITLE, TITLE_S);
    roles.insert(Qt::UserRole + MODEL_ROLES::ID, ID_S);
    roles.insert(Qt::UserRole + MODEL_ROLES::ICON_PATH, ICON_S);
    roles.insert(Qt::EditRole, EDITE_S);
    // return { {Qt::DisplayRole, "display"} };
    //roles.insert(Qt::DisplayRole, "display");
    roles.insert(Qt::DisplayRole, DISPLAY_S);
    //roles.insert(Qt::UserRole + DATA_ID::DISPLAY, DISPLAY_S);
    return roles;
}

Qt::ItemFlags AppModel::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    if(index.isValid()){
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

QVariant AppModel::headerData(int section, Qt::Orientation orientation, int role) const {
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


QVariant AppModel::data(const QModelIndex &index, int role) const {
    Q_UNUSED(index);
    Q_UNUSED(role);
    if (!index.isValid())
        return QVariant();
    /*    QVariant result;
    switch (role) {
    case (int(Qt::DisplayRole)):
        result =  "";//app_data_.at(index.row()).value(DATA_ID(index.column()));
        //QString("%1, %2").arg(index.column()).arg(index.row());
        break;
    case (int(Qt::UserRole + MODEL_ROLES::TITLE)):
        if (app_data_.at(index.row()).get()->isPropertyExist(ItemEnums::EItemProperty::kFileName))
            result = app_data_.at(index.row()).get()->getProperty(ItemEnums::EItemProperty::kFileName);
        break;
    case (int(Qt::UserRole + MODEL_ROLES::ID)):
        if (app_data_.at(index.row()).get()->isPropertyExist(ItemEnums::EItemProperty::kId))
            result = app_data_.at(index.row()).get()->getProperty(ItemEnums::EItemProperty::kId);
        break;
    case (int(Qt::UserRole + MODEL_ROLES::ICON_PATH)):
        if (app_data_.at(index.row()).get()->isPropertyExist(ItemEnums::EItemProperty::kIcon))
            result = app_data_.at(index.row()).get()->getProperty(ItemEnums::EItemProperty::kIcon);
        break;
    }
    QString temp =  QString::number(index.row())+" " +  QString::number(index.column());*///index.row();
    //qDebug()<< "data " + temp + " = " + result.toString();

    //return result;
    return QVariant();
}

bool AppModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    Q_UNUSED(value);
    bool result = false;
    // qDebug()<< "setData"+value.toString();
    if (index.isValid() && (role==Qt::EditRole
                            || role==(Qt::UserRole + MODEL_ROLES::TITLE))) {
        //        switch (role){
        //        case (int(Qt::EditRole)):
        //            if (worksheet_data_.size() > index.row()) {
        //                if(worksheet_data_.at(index.row()).contains(DATA_ID(index.column()))) {
        //                    worksheet_data_[index.row()][DATA_ID(index.column())] = value.toString();
        //                }
        //                else {
        //                    Date_Map temp (worksheet_data_.at(index.row()));
        //                    temp[DATA_ID(index.column())] = value.toString();
        //                    worksheet_data_.replace(index.row(), temp);
        //                }
        //            }
        //            else {
        //                Date_Map temp;
        //                temp[DATA_ID(index.column())] = value.toString();
        //                worksheet_data_.insert(index.row(), temp);
        //            }
        //            //emit dataChanged(index, index);
        //            result = true;
        //            break;
        //        }
        //app_data_.at(index.row()).get()->setProperty(ItemEnums::EItemProperty::kFileName, value.toString());
        result = true;
        //QString temp =  QString::number(index.row())+" " +  QString::number(index.column());
        //qDebug()<< "setdata " + temp + " =" + value.toString();
    }
    return result;
}

void AppModel::Init(){
    //default_property_map_.insert(ItemEnums::EItemProperty::kId, QString::number(-1));
    //default_property_map_.insert(ItemEnums::EItemProperty::kStatus,  QString::number(int(ItemEnums::eItemStatus::kInit)));
    //default_property_map_.insert(ItemEnums::EItemProperty::kFilePath,"");
    //default_property_map_.insert(ItemEnums::EItemProperty::kFileName,"");
    //default_property_map_.insert(ItemEnums::EItemProperty::kIcon, DEFAULT_ICON);
    // default_property_map_.insert(ItemEnums::EItemProperty::kDateLastSaved,"");
    //default_property_map_.insert(ItemEnums::EItemProperty::kFormat,"jpg");
}

void AppModel::parseFolder(const QString &&file_path){
    LOOGGER("parse one file - "+ file_path);
    for (const QString &filePath : FindFilies(file_path))
        this->createItem(QDir::toNativeSeparators(filePath));
}

QStringList AppModel::FindFilies(const QString &file_path) {
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





AppModel::~AppModel() {
    LOOGGER("~AppModel");
    //qDebug()<< "~ItemModel()";
}
