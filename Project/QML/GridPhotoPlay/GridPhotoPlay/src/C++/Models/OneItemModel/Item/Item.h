#ifndef ITEM_H
#define ITEM_H

#include <ItemPropertyWrapper.h>
#include <AbstractTableItemData.h>

#include <QObject>
#include <QHash>
#include <QFileInfo>

#include <typeinfo>

class Item: public QObject {
    Q_OBJECT
    enum ItemConteiner {
        string = 0,
        integer = 1
    };

public:
    Item(QObject *parent = nullptr);

    //void setFile(const QString &path);

private:
    ItemConteiner getConteinerTupe(const ItemEnums::EItemProperty &);

public:   //
    void parse();
    //void cleanModel();
    // AbstractTableItemData *getModel();

public:
    //property
    bool isPropertyExist(const ItemEnums::EItemProperty property);
    template <typename Value>
    void setProperty(const ItemEnums::EItemProperty property, const Value value) {
        ItemConteiner conteiner_tupe = getConteinerTupe(property);
        if (typeid(value).name() == typeid(int()).name()) {
            if (conteiner_tupe==ItemConteiner::string)
                int_property_.insert(property, QVariant(value).toInt());
        }
        else if (typeid(value).name() == typeid(QString()).name()){
            if (conteiner_tupe==ItemConteiner::integer)
                str_property_.insert(property, value);
        }
    }


//void setProperty(const ItemEnums::EItemProperty property, const QString value);
// void setProperty(const ItemEnums::EItemProperty property, const int value);
QString getProperty(const ItemEnums::EItemProperty property);
void setupDefault(const QHash<ItemEnums::EItemProperty, QString> &default_map);

//void saveFile(const QString file_path);
//void deleteFile();

//~Item();

ItemPropertyWrapper <ItemEnums::EItemProperty, QString>                str_property_;
ItemPropertyWrapper <ItemEnums::EItemProperty, int>                    int_property_;
AbstractTableItemData                                                  model_; //views
};

#endif // ITEM_H
