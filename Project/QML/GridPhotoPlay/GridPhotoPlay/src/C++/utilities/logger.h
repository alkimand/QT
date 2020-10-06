#ifndef LOGGER
#define LOGGER

#include <QDebug>

#define  LOOGGER(text)                     qDebug()<< className + QString::fromUtf8(__func__) + ":: " + text;

namespace utilities {

};
#endif //LOGGER
