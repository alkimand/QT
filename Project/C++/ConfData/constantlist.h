//Лист констант - разделить на названия таблиц + enum + define

//https://habr.com/post/329228/ combobox + qibstracitemodel

//#include <constantlist.h>
#include <QMap>
#ifndef CONSTANTLIST_H
#define CONSTANTLIST_H

#define NULL_POSITION             "Не указано" //1

#define PRODUCT_TYPE_KTP          "КТП" //1
#define PRODUCT_TYPE_STP          "СТП" //2
#define PRODUCT_TYPE_PKU          "ПКУ" //3
#define PRODUCT_TYPE_NKU          "НКУ" //4

enum  Enum_Type{ TYPE_KTP = 1, TYPE_STP = 2, TYPE_PKU = 3, TYPE_NKU = 4 };

#define NAMES_TAB_FIRST          "Общее" //4
#define NAMES_TAB_KTP_2          "Параметры КТП"
#define NAMES_TAB_ACTIONS        "Действия"




#define TEMPLATEFILE          "G:/QT/234/ConfData/testtemplate.txt"

#endif // CONSTANTLIST_H
