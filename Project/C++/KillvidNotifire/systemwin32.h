#ifndef SYSTEMWIN32_H
#define SYSTEMWIN32_H

#include <windows.h>
//#include <w32api.h>
#include <tlhelp32.h>

#include <QMap>
#include <QMultiMap>
#include <QString>
#include <QDebug>



class systemWin32
{
public:
    systemWin32();
    bool processExist(const int &process_id);
    QString getProcessNamebyID(const int &process_id);
    QList <int> getProcessIDbyName(const QString &process_name);
    QStringList getAllProcessList();
    void terminate(const int &process_id);
private:
    QMultiMap <int, QString> win32sysMap;
    QString copyToQString(WCHAR array[MAX_PATH]);

};

#endif // SYSTEMWIN32_H
