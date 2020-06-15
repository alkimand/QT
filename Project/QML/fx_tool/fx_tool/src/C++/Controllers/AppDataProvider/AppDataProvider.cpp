#include "AppDataProvider.h"
#include <QDebug>
#include <QWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QDirIterator>
#include <QStringList>
#include <QDir>
#include "ItemPropery.h"


#include <QExplicitlySharedDataPointer>

#include <QSharedPointer>

static const char className[] = "AppDataProvider::";

AppDataProvider::AppDataProvider(QObject *parent):QObject(parent){
    qDebug()<< "AppDataProvider";
    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_1), "test");
    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_3), 1000);

    // instance();

    // if (s_instance_) {
    //   qDebug()<< "create s_instance_";
    //s_instance_ = new AppDataProvider();
    // }

    // qDebug()<< "create AppDataProvider";
    //FindFilies();
    Init();
}


AppModel *AppDataProvider::getModel() {
    return model_;
}


void AppDataProvider::appStart(){
    LOOGGER("+");
    this->Init();
}

void AppDataProvider::toolBarButtonPush(QString id){
    LOOGGER("+");
    pItem  item = model_->getItemByID(id);
    if (item != nullptr) {
        model_->parseItem(item);
        if (item.get()->getProperty(ItemEnums::EItemProperty::kStatus) == Props(ItemEnums::eItemStatus::kParsed)) {
            emit itemParsed(id);
        }
    }
    else
       LOOGGER("Error getItemByID id = " + id);
}



void AppDataProvider::Init() {
    model_ = new AppModel(this);
    model_->parseFolder(QDir::currentPath());
    //    QString status =INT2QS(int(ItemEnums::eItemStatus::kInit));
    //    QString id =INT2QS(0);
    //    default_property_map_.insert(ItemEnums::EItemProperty::kId, id );
    //    default_property_map_.insert(ItemEnums::EItemProperty::kStatus, status);
    //    default_property_map_.insert(ItemEnums::EItemProperty::kFilePath,"");
    //    default_property_map_.insert(ItemEnums::EItemProperty::kFileName,"");
    //    default_property_map_.insert(ItemEnums::EItemProperty::kIcon,"");
    //    default_property_map_.insert(ItemEnums::EItemProperty::kDateLastSaved,"");
    //    default_property_map_.insert(ItemEnums::EItemProperty::kFormat,"fx");

    //    for (const QString &filePaths : FindFilies()) {
    //        createItem(QDir::toNativeSeparators(filePaths));
    //        LOOGGER(filePaths);
    //    }

}

//QStringList AppDataProvider::FindFilies(const QString file_path) {
//    QStringList files;
//    QString path = file_path;
//    if (file_path.isEmpty())
//        path = QDir::currentPath();
//    QStringList filters;
//    filters << FX_EXTENSION;
//    QDirIterator it(path, filters, QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::NoIteratorFlags);
//    while (it.hasNext())
//        files << it.next();
//    files.sort();

//    return files;


//    // QString directory;

//    //directory = QFileDialog::getExistingDirectory(0, tr("Find Files"), QDir::currentPath());
//    //   QDir::toNativeSeparators(QFileDialog::getExistingDirectory(parent, tr("Find Files"), QDir::currentPath()));

//    //    QString filters("Excel files (*.xlsx , *.xls);;Text files (*.txt);;All files (*.*)");
//    //    //QString defaultFilter("Fx files (*.fx)");
//    //    QString defaultFilter("All files (*.*)");
//    //    QString defaultPath = path_;
//    //    //QString fullFilePath = QFileDialog::getSaveFileName(0, "Save file", defaultPath, filters, &defaultFilter);
//    //    //directory = QFileDialog::getExistingDirectory(0, tr("Find Files"), QDir::currentPath());
//    //    if (directory.isEmpty())
//    //        directory = QDir::currentPath();

//    //    QStringList filter;
//    //filter<<"*.fx";
//    //QDirIterator it(directory, filter, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
//    //QStringList files;
//}

//void AppDataProvider::loadDirectory(const QString &directory){
//    Q_ASSERT(QDir(directory).exists());
//}

//void AppDataProvider::openFile() {
//    //std::wstring folder_path = digi::getAppSpecificFolder(fs::EAppSpecificFolder::eConfig);
//    //QString path = QFileDialog::getOpenFileName(0, tr("Open File"), WS2Q(folder_path), tr("*.fx"));
//    // QString path = QFileDialog::getOpenFileName(0, tr("Open File"), fileName, tr("*.fx"));
//    //QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
//    //QString fileName = fileComboBox->currentText();
//}

