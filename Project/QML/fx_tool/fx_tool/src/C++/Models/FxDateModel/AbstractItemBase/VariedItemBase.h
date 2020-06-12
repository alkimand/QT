#ifndef VARIED_ITEM_H
#define VARIED_ITEM_H
#include "ItemPropery.h"

#include <QObject>
#include <QFileInfo>
#include <databuf.h>
#include "iAbstractItemBase.h"
typedef QString Props;



class VariedItem: public iAbstractItemBase {


public:
    VariedItem(QObject *parent = nullptr);

    void setFile(const Props &path);
    void parse();
    void readFile(QString file_name, sys::IDataBuff& buff, int &error);
    const FileData &getFileModel();



private:
    QFile               file_;
    QFileInfo           file_info_;
    FileData            value_map_;


};

#endif // VARIED_ITEM_H
