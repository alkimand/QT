#ifndef VARIED_ITEM_H
#define VARIED_ITEM_H
#include "ItemPropery.h"
#include <QHash>
#include <QObject>
#include <QFileInfo>
#include <databuf.h>
#include "AbstractPropertyConteiner.h"
//typedef QString QString;


template <typename Key, typename Val>
class ItemPropertyWrapper: public AbstractPropertyConteiner <Key,Val > {
public:
    typedef QHash<Key, Val>                       ItemPropertyMap;
//    void setFile(const QString &path);
//    void parse();
//    void readFile(QString file_name, sys::IDataBuff& buff, int &error);
//    void writeFile(QString file_name, sys::IDataBuff& buff, int &error);
//    const FileData &getFileModel();
//    void setCMap(FileData map);
//    void save(const QString file_name, const FileData values);
//    void deleteFile();
    //  void setDataToStdMap();



private:
    QFile               file_;
    QFileInfo           file_info_;
    FileData            value_map_;


};

#endif // VARIED_ITEM_H
