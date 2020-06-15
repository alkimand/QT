#include "VariedItemBase.h"
#include <QDebug>
#include <QTextCodec>
#include  <stdio.h>
#include <serialization.h>
#include <lite_gamma.h>
#include <databuf.h>
#include <qs_utils.h>
#include <QSharedPointer>
#include "iAbstractItemBase.h"

static const char className[] = "VariedItemBase::";

VariedItem::VariedItem(QObject *parent): iAbstractItemBase(parent){
    //AbstractItem::AbstractItem() {
    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_1), "test");
    // itemData_.insert(int(ItemEnums::EItemProperty::kTextValue_3), 1000);
}

void VariedItem::setFile(const Props &path) {
    if (!QFile(path).exists())
        return;
    //qDebug()<< "AbstractItemBase::setFile - " + path;
    file_.setFileName(path);
    file_info_.setFile(path);

    setItemProperty(ItemEnums::EItemProperty::kFilePath,Props(file_info_.absoluteFilePath()));
    setItemProperty(ItemEnums::EItemProperty::kFileName,Props(file_info_.fileName()));
    setItemProperty(ItemEnums::EItemProperty::kFormat, Props(file_info_.suffix()));



    //qDebug()<< "AbstractItemBase::setFile fileName- " + file_info_.fileName();
    // qDebug()<< "AbstractItemBase::setFile suffix- " + file_info_.suffix();
    //toDo icons
}

void VariedItem::parse() {
    //LOOGGER("+");
    Props status = Props(ItemEnums::eItemStatus::kParseError);
    Props path = getItemProperty(ItemEnums::EItemProperty::kFilePath);
    if (file_.open(QFile::ReadWrite )) {
        sys::DataBuff buff;
        //freadBin("file_info_.path()",buff);
        int error = 0;
        readFile(file_info_.absoluteFilePath(), buff, error );
        if (buff.size() > 0 && error ==0){
            lite_gamma::dc(buff.data(), buff.size(), DEFAULT_WP);
            std::string original_values = buff.getString();
            QString str = QString::fromUtf8(original_values.c_str());
            str.trimmed();
            str.simplified();
            original_values = str.toUtf8().constData();
            fs::deserialize(original_values, value_map_);
            status = Props(ItemEnums::eItemStatus::kParsing);
        }
        else {
            LOOGGER("file open Error");
        }
        file_.close();
    }
    setItemProperty(ItemEnums::EItemProperty::kStatus, Props(status));
    //LOOGGER("-");
}

void VariedItem::readFile(QString file_path, sys::IDataBuff &buff, int &error){
     //LOOGGER("+");
    //errno_t err;
    QByteArray ba = file_path.toLocal8Bit();
    const char *fname = ba.data();
    FILE *ptrFile;
    //err  = fopen_s(&ptrFile, "FreeTikTokDownloader.fx", "rb" );
    ptrFile =_fsopen(fname, "rb" , SH_DENYNO);
    fseek(ptrFile , 0 , SEEK_END);
    size_t nSize = (size_t)ftell(ptrFile);
    fseek(ptrFile, 0L, SEEK_SET);
    buff.resize(nSize);
    fread(buff.data(), nSize, 1, ptrFile);
    fclose(ptrFile);
}

const FileData &VariedItem::getFileModel() {
    return value_map_;
}

