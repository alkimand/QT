#include "systemwin32.h"

static const char className[] = "systemWin32::";

systemWin32::systemWin32()
{
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap == NULL) {
        //QMessageBox::critical(0, "Error!", "Error Load ToolHelp", QMessageBox::Close);
        return;
    }

    PROCESSENTRY32 proc = { sizeof(proc) };
    if (Process32First(hSnap, &proc)) {
        QString filename;
        filename = copyToQString(proc.szExeFile);
        // QMultiMap <int, QString> ::iterator it = win32sysMap.find(th32ProcessID)
        win32sysMap.insert(int(proc.th32ProcessID),filename);
        // win32sysMap[int(proc.th32ProcessID)] = filename;
        while (Process32Next(hSnap, &proc)) {
            filename = copyToQString(proc.szExeFile);
            win32sysMap.insert(int(proc.th32ProcessID),filename);
        }
    }
}


bool systemWin32::processExist(const int &process_id) {
    auto it = std::find(win32sysMap.begin(), win32sysMap.end(), process_id);
    if (it != win32sysMap.end()){
        return true;
    }
    return false;
}


QString systemWin32::getProcessNamebyID(const int &process_id) {
    QMultiMap <int, QString>::iterator it = win32sysMap.find(process_id);
    if (it != win32sysMap.end())
        return it.value();
    return QString("");
}


QList <int> systemWin32::getProcessIDbyName(const QString &process_name) {
    QList <int> process_id_list;
    QMultiMap<int, QString>::iterator i = win32sysMap.begin();
    while (i != win32sysMap.end()) {
        if (i.value() == process_name) {
            process_id_list.append(i.key());
        }
        ++i;
    }
    return process_id_list;
}


//  WinAPI present in WCHAR.
QString systemWin32::copyToQString(WCHAR array[MAX_PATH]){
    return QString::fromWCharArray(array, -1);
}


QStringList systemWin32::getAllProcessList(){
    return win32sysMap.values();
}

void systemWin32::terminate(const int &process_id){
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, process_id);
    if (hProcess == NULL){
        qDebug()<< ("couldn't open process\n");
        return;
    }
    TerminateProcess(hProcess, 1);
    CloseHandle(hProcess);
}


