#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QSettings>

#include "systemwin32.h"

#define  LOOGGER(text)                     qDebug()<< className + QString::fromUtf8(__func__) + ":: " + text;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QString processName = QString("vidnotifier.exe");
    systemWin32 processesInWin;
    QList<int>  process_id_list  = processesInWin.getProcessIDbyName(processName);

    for (auto process_id : process_id_list){
        processesInWin.terminate(process_id);
    }

    QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
                       QSettings::NativeFormat);
    QStringList keyList = settings.allKeys();
    for(auto key : keyList){
        if (key =="vidnotifier.exe") {
            settings.remove(key);
            settings.sync();
        }
    }

    processName = QString("KillvidNotifire.exe");
    process_id_list  = processesInWin.getProcessIDbyName(processName);

//    for (auto process_id : process_id_list){
//        processesInWin.terminate(process_id);
//    }
   // a.quit();
    TerminateProcess(GetCurrentProcess(),0);
    return a.exec();
}
