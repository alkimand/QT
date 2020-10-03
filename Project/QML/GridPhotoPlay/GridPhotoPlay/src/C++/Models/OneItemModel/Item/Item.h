#ifndef ITEM_H
#define ITEM_H

#include <ItemPropertyWrapper.h>
#include <AbstractTableItemData.h>

#include <QObject>
#include <QHash>
#include <QFileInfo>


class Item: public QObject {
    Q_OBJECT

public:
    Item(QObject *parent = nullptr);
    //void setFile(const QString &path);
   // void setProperty(const ItemEnums::EItemProperty property,const QString value);
   // const QString getProperty(const ItemEnums::EItemProperty property);

    //void setupDefault(const QHash<ItemEnums::EItemProperty, QString> &default_map_);
    //void parse();
    //void cleanModel();
   // AbstractTableItemData *getModel();
   // bool isPropertyExist(const ItemEnums::EItemProperty propertyType);
    //void saveFile(const QString file_path);
    //void deleteFile();
    ~Item();
private:

    ItemPropertyWrapper <ItemEnums::EItemProperty, QString>               *property_;
  //  AbstractPropertyConteiner <int>               *property_;

    //QHash<QString, QString>   *property_;
    AbstractTableItemData                           *model_;
};

#endif // ITEM_H
