#include "ItemPropertyMap.h"
#include <QDebug>

static const char className[] = "ItemPropertyMap::";

ItemPropertyMap::ItemPropertyMap(QObject *parent): QObject(parent) {

}

int ItemPropertyMap::size() const {

}

bool ItemPropertyMap::isEmpty() const {

}

bool ItemPropertyMap::contains(QString property) {

}

bool ItemPropertyMap::contains(int property) {

}

QString &ItemPropertyMap::operator[](const ItemEnums::EItemProperty &property_type)
{

}

const QString ItemPropertyMap::operator[](const ItemEnums::EItemProperty &property_type) const
{

}


void ItemPropertyMap::operator=(QString value){

}


ItemPropertyMap::~ItemPropertyMap() {
    //qDebug()<<"~ItemPropertyMap";
}

