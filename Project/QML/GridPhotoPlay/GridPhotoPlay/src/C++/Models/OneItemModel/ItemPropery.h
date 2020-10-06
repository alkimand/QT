#ifndef PROPS_H
#define PROPS_H

#include <QObject>
#include "ItemConstant.h"

#include <QAbstractTableModel>

#define  LOOGGER(text)                     qDebug()<< className + QString::fromUtf8(__func__) + ":: " + text;

#define INT2QS(value)                      QString::number(value);

typedef QSharedPointer<QAbstractTableModel> p_model;
typedef std::map<std::string, std::string>  FileData;

class ItemEnums : public QObject
{
    Q_OBJECT
public:

};

#endif // PROPS_H
