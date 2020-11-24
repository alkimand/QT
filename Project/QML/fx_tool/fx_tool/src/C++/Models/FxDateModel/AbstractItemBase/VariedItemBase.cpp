#include <QDebug>
#include <QTextCodec>
#include  <stdio.h>
#include <QSharedPointer>
#include <stdlib.h>
#include <cstdio>
#include <iostream>

#include "iAbstractItemBase.h"
#include "VariedItemBase.h"
#include <serialization.h>
#include <lite_gamma.h>
#include <databuf.h>
#include <qs_utils.h>

static const char className[] = "VariedItemBase::";

VariedItem::VariedItem(QObject *parent): iAbstractItemBase(parent){
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
}

void VariedItem::parse() {
    //LOOGGER("+");
    Props status = Props(ItemEnums::eItemStatus::kParseError);
    Props path = getItemProperty(ItemEnums::EItemProperty::kFilePath);
    if (file_.open(QFile::ReadWrite )) {
        file_.close();
        sys::DataBuff buff;
        int error = 0;
        readFile(file_info_.absoluteFilePath(), buff, error );
        if ( error == 0){
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
            LOOGGER("file open Error")
        }

    }
    setItemProperty(ItemEnums::EItemProperty::kStatus, Props(status));
    //LOOGGER("-");
}

void VariedItem::readFile(QString file_path, sys::IDataBuff &buff, int &error) {
    //LOOGGER("+");
    error = 1;
    QByteArray ba = file_path.toLocal8Bit();
    const char *fname = ba.data();
    FILE *ptrFile;
    ptrFile =_fsopen(fname, "rb", SH_DENYNO );//, _SH_DENYRW
    if (ptrFile == nullptr){
        LOOGGER("fsopen error")
        return ;
    }
    fseek(ptrFile , 0L , SEEK_END);
    size_t nSize = (size_t)ftell(ptrFile);
    fseek(ptrFile, 0L, SEEK_SET);
    buff.resize(nSize);
    fread(buff.data(), nSize, 1, ptrFile);
    fclose(ptrFile);
    error = 0;
}


void VariedItem::writeFile(QString file_path, sys::IDataBuff &buff, int &error){
    Q_UNUSED(error)
    QByteArray ba = file_path.toLocal8Bit();
    const char *fname = ba.data();
    QByteArray data;
    FILE *ptrFile;
    ptrFile =_fsopen(fname, "wb" , SH_DENYNO);
    if (ptrFile == nullptr){
        LOOGGER("fsopen error")
        return ;
    }
    std::fwrite(buff.data(), buff.size(),1 ,ptrFile);
    fclose(ptrFile);
}


const FileData &VariedItem::getFileModel() {
    return value_map_;
}


void VariedItem::setCMap(FileData map){
    value_map_ = map;
}


void VariedItem::save(QString file_name, const FileData value_map) {
    Props status = Props(ItemEnums::eItemStatus::kSaveError);
    if (!file_name.isEmpty()){
        QFileInfo check_file(file_name);
        if (check_file.exists() && check_file.isFile()) {
        }
        else {
            QFile file(file_name);
            file.open(QIODevice::ReadWrite | QIODevice::Text);
            file.close();
        }
        value_map_= value_map;
        std::string serialized = fs::serialize(value_map_);
        sys::DataBuff buff;
        buff.set(serialized);
        lite_gamma::ec(buff.data(), buff.size(), DEFAULT_WP);
        int error = 0;
        writeFile(file_name, buff, error);
        if (buff.size() > 0 && error == 0){
            status =  Props(ItemEnums::eItemStatus::kParsed);
        }

        setItemProperty(ItemEnums::EItemProperty::kFilePath, Props(file_name));

    }
    setItemProperty(ItemEnums::EItemProperty::kStatus, Props(status));
}


void VariedItem::deleteFile(){
    if (file_.open(QFile::ReadWrite )) {
        file_.remove();
    }
}

