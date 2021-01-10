#include <QMultiMap>
#include <QByteArray>
#include <QFile>

#include <working_thread.h>

void WorkingThread::setFiles(const QStringList file_list) {
    file_list_ = std::move(file_list);
}


void WorkingThread::run() {
    QMultiMap <QByteArray, QString> files;
    int counter{};
    int files_count = file_list_.size();
    foreach(const QString & file_path, file_list_) {
        QFile file(file_path);
        if (file.exists()) {
            files.insert(getCheckSum(file_path, QCryptographicHash::Md5), file_path);
            ++counter;
            QPair<int, int> pair(counter, files_count);
            emit parseProgress(QPair<int, int>(counter, files_count));
        }
    }

    QList <QList<QString>> result_files;
    for (auto& unique_hash : files.uniqueKeys()) {
        QList<QString> equal_hash_container = files.values(unique_hash);
        if (equal_hash_container.size() > 1) {
            result_files.push_back(equal_hash_container);
        }
    }
    emit  threadFinished(result_files);
};


QByteArray WorkingThread::getCheckSum(const QString& fileName, QCryptographicHash::Algorithm hashAlgorithm) {
    QFile file(fileName);
    if (file.open(QFile::ReadOnly)) {
        QCryptographicHash hash(hashAlgorithm);
        if (hash.addData(&file))
            return hash.result();
    }
    return QByteArray();
}

